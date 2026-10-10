"""Read-only x86 RTTI rescan: never attribute derived vtables to a base type."""
import csv,hashlib,json,struct
from collections import Counter,defaultdict
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];OUT=Path(__file__).resolve().parent/'evidence';OUT.mkdir(parents=True,exist_ok=True)
def rows(path):
 with (ROOT/path).open(encoding='utf-8-sig',newline='') as f:return list(csv.DictReader(f))
classes=rows('docs/MemoryMap/classes.csv');pending=rows('docs/MemoryMap/pending_hooks.csv');manifest={r['name']:r['file'] for r in rows('source/class-files.csv')}
# Stable original RTTI-only cohort, even after EH metadata supplies some methods.
unknown=[r for r in classes if not r['locators'] and not r['vtables']];assert len(unknown)==585
data=Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes();sha=hashlib.sha256(data).hexdigest();assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',data,60)[0];opt=pe+24;assert struct.unpack_from('<H',data,pe+4)[0]==0x14c and struct.unpack_from('<H',data,opt)[0]==0x10b
base=struct.unpack_from('<I',data,opt+28)[0];sections=[]
for i in range(struct.unpack_from('<H',data,pe+6)[0]):
 p=opt+struct.unpack_from('<H',data,pe+20)[0]+40*i;vs,va,size,ptr=struct.unpack_from('<IIII',data,p+8);flags=struct.unpack_from('<I',data,p+36)[0];sections.append((base+va,size,ptr,flags))
def offset(va,length=4):
 for start,size,ptr,flags in sections:
  if start<=va and va+length<=start+size:return ptr+va-start
 return None
def u32(va):
 p=offset(va);return struct.unpack_from('<I',data,p)[0] if p is not None else None
names={int(r['type_descriptor_va'],16):r['name'] for r in classes};wanted={int(r['type_descriptor_va'],16) for r in unknown}
# Every aligned, file-backed non-code dword referencing a known type descriptor.
type_refs=defaultdict(list)
for start,size,ptr,flags in sections:
 if flags&0x20000000:continue
 for pos in range(0,size-3,4):
  value=struct.unpack_from('<I',data,ptr+pos)[0]
  if value in names:type_refs[value].append(start+pos)
def hierarchy(chd):
 p=offset(chd,16)
 if p is None:return None
 sig,attributes,count,array=struct.unpack_from('<IIII',data,p)
 if sig!=0 or not 1<=count<=4096 or offset(array,count*4) is None:return None
 result=[]
 for i in range(count):
  bcd=u32(array+i*4);q=offset(bcd,24) if bcd is not None else None
  if q is None:return None
  td,contained,mdisp,pdisp,vdisp,attrs=struct.unpack_from('<IIiiiI',data,q)
  if td not in names:return None
  result.append(dict(name=names[td],type_descriptor_va=f'0x{td:08x}',descriptor_va=f'0x{bcd:08x}',contained_bases=contained,mdisp=mdisp,pdisp=pdisp,vdisp=vdisp,attributes=attrs))
 return result
own_locs=defaultdict(list);base_relations=defaultdict(list);all_locs={}
for td,addresses in type_refs.items():
 for address in addresses:
  loc=address-12;p=offset(loc,20)
  if p is None:continue
  signature,thisoff,cdoff,checktd,chd=struct.unpack_from('<IIIII',data,p)
  if signature!=0 or checktd!=td or thisoff>0x1000000 or cdoff>0x1000000:continue
  h=hierarchy(chd)
  if not h or h[0]['name']!=names[td]:continue
  all_locs[loc]=(names[td],h)
  if td in wanted:own_locs[td].append(loc)
  for relation in h[1:]:
   if int(relation['type_descriptor_va'],16) in wanted:
    base_relations[relation['name']].append(dict(derived_owner=names[td],locator_va=f'0x{loc:08x}',**relation))
# Find actual COL-pointer+code-pointer pairs, rather than treating any COL as methods.
locator_refs=defaultdict(list)
for start,size,ptr,flags in sections:
 if flags&0x20000000:continue
 for pos in range(0,size-7,4):
  value=struct.unpack_from('<I',data,ptr+pos)[0]
  if value in all_locs:locator_refs[value].append(start+pos)
recovered=[];result=[]
for c in unknown:
 td=int(c['type_descriptor_va'],16);locators=own_locs[td];vts=[]
 for loc in locators:
  for ref in locator_refs[loc]:
   vt=ref+4;targets=[]
   for slot in range(256):
    target=u32(vt+slot*4)
    if target is None or not any(start<=target<start+size and flags&0x20000000 for start,size,ptr,flags in sections):break
    targets.append(target)
   if targets:
    vts.append(vt)
    for slot,target in enumerate(targets):recovered.append(dict(owner=c['name'],file=manifest[c['name']],vtable_va=f'0x{vt:08x}',slot=slot,function_va=f'0x{target:08x}',function_rva=f'0x{target-base:08x}',status='static_rtti_own_vtable_not_runtime_tested',enabled=False,reconstructed=False))
 relations=base_relations[c['name']];derived=sorted(set(r['derived_owner'] for r in relations))
 reason='own_vtable_recovered' if vts else 'own_locator_without_executable_vtable' if locators else 'base_type_only_no_own_locator_or_vtable' if derived else 'type_descriptor_only_no_own_locator_or_vtable'
 result.append(dict(name=c['name'],file=manifest[c['name']],type_descriptor_va=c['type_descriptor_va'],reason=reason,own_locators=';'.join(f'0x{x:08x}' for x in locators),own_vtables=';'.join(f'0x{x:08x}' for x in vts),descriptor_pointer_refs=len(type_refs[td]),derived_owner_count=len(derived),derived_owners=';'.join(derived),method_addresses_recovered=sum(r['owner']==c['name'] for r in recovered),runtime_reference_tested=False,enabled=False,reconstructed=False))
def write_csv(name,items,fields):
 with (OUT/name).open('w',encoding='utf-8',newline='') as f:
  w=csv.DictWriter(f,fieldnames=fields);w.writeheader();w.writerows(items)
write_csv('unknown-types.csv',result,list(result[0]));write_csv('recovered-own-methods.csv',recovered,['owner','file','vtable_va','slot','function_va','function_rva','status','enabled','reconstructed'])
(OUT/'base-relations.json').write_text(json.dumps(base_relations,indent=2)+'\n',encoding='utf-8')
counts=Counter(r['reason'] for r in result);summary=dict(exe_sha256=sha,unknown_types=len(result),reason_counts=dict(counts),recovered_own_method_references=len(recovered),scanner_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),validated_complete_object_locators=len(all_locs),scope='Aligned file-backed non-executable sections; exact x86 COL owner + bounded hierarchy + executable vtable entries; no inherited method attribution or runtime calls')
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n',encoding='utf-8')
md='# Análisis de los 585 tipos sin métodos conocidos\n\n'+f'EXE canónico SHA-256: `{sha}`. Escáner reproducible: `python reversing/UnknownTypesAnalysis/analyze.py`.\n\n| Resultado | Tipos |\n| --- | --- |\n'+''.join(f'| {k} | {v} |\n' for k,v in counts.items())+'\nSe revisaron referencias alineadas a los descriptores RTTI, localizadores completos x86, jerarquías y punteros a tablas propias. Los descriptores de tipos base presentes en jerarquías de clases derivadas no establecen direcciones de métodos propios de esas bases. No se atribuyen métodos de las clases derivadas a sus bases.\n\nEl resultado distingue presencia de RTTI y relación de herencia de existencia de un objeto completo con tabla virtual propia. La ausencia de tabla propia en este inventario no prueba que una clase carezca de métodos no virtuales: para identificarlos hacen falta referencias de código y análisis de implementaciones. Ninguna llamada se ejecuta ni se habilita con este análisis.\n\nTodos los 585 tipos están enumerados en [unknown-types.csv](evidence/unknown-types.csv); las relaciones documentadas en [base-relations.json](evidence/base-relations.json). Las referencias de métodos propios recuperadas, si existen, quedan en [recovered-own-methods.csv](evidence/recovered-own-methods.csv), pendientes de validación.\n'
(Path(__file__).resolve().parent/'README.md').write_text(md,encoding='utf-8');print(json.dumps(summary))
