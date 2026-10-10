"""Recover exact-owner callbacks from MSVC x86 CatchableType/ThrowInfo metadata."""
import analyze as a
import csv,hashlib,json,struct
from collections import defaultdict
def code(va):return any(start<=va<start+size and flags&0x20000000 for start,size,ptr,flags in a.sections)
def catchable(va):
 p=a.offset(va,28)
 if p is None:return None
 properties,td,mdisp,pdisp,vdisp,size,copy=struct.unpack_from('<IIiiiII',a.data,p)
 if td not in a.names or properties&~31 or not 0<size<0x1000000 or not code(copy):return None
 return dict(owner=a.names[td],metadata_va=va,copy_function_va=copy,size=size,mdisp=mdisp,pdisp=pdisp,vdisp=vdisp,properties=properties)
cts={}
for td,refs in a.type_refs.items():
 for ref in refs:
  ct=catchable(ref-4)
  if ct:cts[ref-4]=ct
arrays={};throws=[]
for start,size,ptr,flags in a.sections:
 if flags&0x20000000:continue
 for pos in range(0,size-7,4):
  count,first=struct.unpack_from('<II',a.data,ptr+pos)
  if not 1<=count<=64 or first not in cts or pos+4+count*4>size:continue
  entries=list(struct.unpack_from('<'+'I'*count,a.data,ptr+pos+4))
  if all(ct in cts for ct in entries):arrays[start+pos]=entries
for start,size,ptr,flags in a.sections:
 if flags&0x20000000:continue
 for pos in range(0,size-15,4):
  attrs,unwind,forward,array=struct.unpack_from('<IIII',a.data,ptr+pos)
  if array in arrays and attrs&~31==0 and code(unwind) and (forward==0 or code(forward)):
   throws.append(dict(throw_info_va=start+pos,unwind_va=unwind,array_va=array))
validated_arrays={t['array_va'] for t in throws};refs=[];seen=set()
for arr in sorted(validated_arrays):
 for ctva in arrays[arr]:
  ct=cts[ctva];owner=ct['owner']
  if owner not in {r['name'] for r in a.unknown}:continue
  target=ct['copy_function_va'];key=(owner,target)
  if key in seen:continue
  seen.add(key);refs.append(dict(owner=owner,file=a.manifest[owner],function_va=f'0x{target:08x}',function_rva=f'0x{target-a.base:08x}',method_kind='msvc_eh_copy_constructor_callback',metadata_va=f'0x{ctva:08x}',catchable_type_array_va=f'0x{arr:08x}',status='static_metadata_owner_verified_not_runtime_called',entry_bytes=a.data[a.offset(target):a.offset(target)+16].hex(' '),enabled=False,reconstructed=False,runtime_reference_tested=False))
for t in throws:
 ct=cts[arrays[t['array_va']][0]];owner=ct['owner'];target=t['unwind_va'];key=(owner,target)
 if owner not in {r['name'] for r in a.unknown} or key in seen:continue
 seen.add(key);refs.append(dict(owner=owner,file=a.manifest[owner],function_va=f'0x{target:08x}',function_rva=f'0x{target-a.base:08x}',method_kind='msvc_eh_unwind_destructor_callback',metadata_va=f'0x{t["throw_info_va"]:08x}',catchable_type_array_va=f'0x{t["array_va"]:08x}',status='static_metadata_owner_verified_not_runtime_called',entry_bytes=a.data[a.offset(target):a.offset(target)+16].hex(' '),enabled=False,reconstructed=False,runtime_reference_tested=False))
with (a.OUT/'recovered-eh-methods.csv').open('w',encoding='utf-8',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(refs[0]));w.writeheader();w.writerows(refs)
overlay=[]
for r in refs:
 overlay.append(dict(owner=r['owner'],file=r['file'],va=r['function_va'],rva=r['function_rva'],vtable_va='',slot='',label=r['method_kind'],name_candidates='',evidence='reversing/UnknownTypesAnalysis/evidence/eh-summary.json; metadata '+r['metadata_va']+'; CatchableTypeArray '+r['catchable_type_array_va'],origin='ExceptionCopyConstructor' if 'copy_constructor' in r['method_kind'] else 'ExceptionUnwindDestructor',runtime_reference_tested='0',enabled='0',reconstructed='0'))
with (a.OUT/'pending-overlay.csv').open('w',encoding='utf-8',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(overlay[0]));w.writeheader();w.writerows(overlay)
proof=dict(exe_sha256=a.sha,source_sha256=hashlib.sha256(__import__('pathlib').Path(__file__).read_bytes()).hexdigest(),validated_throw_info=throws,validated_arrays={f'0x{x:08x}':[cts[v] for v in arrays[x]] for x in validated_arrays},recovered_references=len(refs),owners=sorted(set(x['owner'] for x in refs)),runtime_calls=0)
(a.OUT/'eh-summary.json').write_text(json.dumps(proof,indent=2)+'\n',encoding='utf-8')
md=__import__('pathlib').Path(__file__).resolve().parent/'README.md'
with md.open('a',encoding='utf-8') as f:
 f.write('\n## Referencias adicionales mediante excepciones MSVC\n\n`python reversing/UnknownTypesAnalysis/analyze_eh.py` valida cadenas ThrowInfo → CatchableTypeArray → CatchableType y exporta [recovered-eh-methods.csv](evidence/recovered-eh-methods.csv). Son seis callbacks propios de cuatro tipos, cuatro de copia y dos de destrucción durante unwind. Los nombres describen su función en los metadatos; el ABI y su ejecución permanecen pendientes. No son métodos heredados ni entradas virtuales. La evidencia completa está en [eh-summary.json](evidence/eh-summary.json).\n\n| Propietario | Tipo de callback | VA |\n| --- | --- | --- |\n')
 for r in refs:f.write(f'| {r["owner"]} | {r["method_kind"]} | `{r["function_va"]}` |\n')
print(json.dumps(dict(references=len(refs),owners=len(set(x['owner'] for x in refs)))))
