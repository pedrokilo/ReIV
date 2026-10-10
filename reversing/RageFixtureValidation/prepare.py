"""Exact complete member-access bodies only; no constructors, calls or globals."""
import csv, hashlib, json, pathlib, struct
ROOT=pathlib.Path(__file__).resolve().parents[2]
EV=pathlib.Path(__file__).resolve().parent/'evidence'
EV.mkdir(parents=True,exist_ok=True)
data=pathlib.Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes()
sha=hashlib.sha256(data).hexdigest()
assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',data,0x3c)[0]; opt=pe+24
base=struct.unpack_from('<I',data,opt+28)[0]
sections=[]
for i in range(struct.unpack_from('<H',data,pe+6)[0]):
 p=opt+struct.unpack_from('<H',data,pe+20)[0]+i*40
 va,size,ptr=struct.unpack_from('<III',data,p+12)
 sections.append((va,size,ptr,struct.unpack_from('<I',data,p+36)[0]))
refs=list(csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(newline='',encoding='utf-8-sig')))
refs=[r for r in refs if r['file'].startswith('source/rage/')]
group={}
for r in refs:group.setdefault(int(r['rva'],16),[]).append(r)
items=[]
for rva,rows in sorted(group.items()):
 s=next((s for s in sections if s[0]<=rva<s[0]+s[1] and s[3]&0x20000000),None)
 if not s:continue
 b=data[s[2]+rva-s[0]:s[2]+rva-s[0]+32]
 operation=None;offset=0;size=0
 # All instruction sequences end in RET with no stack arguments.
 for prefix,op in [(b'\x8b\x41','get_u32'),(b'\x8a\x41','get_u8'),(b'\xd9\x41','get_float'),(b'\x8d\x41','address_offset')]:
  if b.startswith(prefix) and b[3]==0xc3 and b[2]<0x80:operation,offset,size=op,b[2],4
 for prefix,op in [(b'\x8b\x81','get_u32'),(b'\x8a\x81','get_u8'),(b'\xd9\x81','get_float'),(b'\x8d\x81','address_offset')]:
  if b.startswith(prefix) and b[6]==0xc3:
   off=int.from_bytes(b[2:6],'little',signed=True)
   if 0<=off<=4092:operation,offset,size=op,off,7
 if not operation:continue
 items.append(dict(va=f'0x{base+rva:08x}',rva=f'0x{rva:08x}',operation=operation,value=offset,entry_bytes=b[:size].hex(' '),body_size=size,abi='x86_thiscall_fixture',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=sha))
(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n')
# Reuse the already exercised object/sentinel fixture implementation, restricting
# generated entries to these independently recognized whole-body accessors.
source=(ROOT/'reversing/AudioValidation/generate_probe.py').read_text()
source=source.replace("items=json.loads((p/'evidence/candidates.json').read_text())","items=json.loads((p/'evidence/fixture-scope.json').read_text())")
source=source.replace('audiofixtures','ragefixtures').replace('Audio fixture','Rage fixture').replace('AudioFixtureProbe.h','RageFixtureProbe.h').replace('ReIV-audio-fixtures','ReIV-rage-fixtures').replace('ReIV.audio-fixtures-test','ReIV.rage-fixtures-test')
# enum and cases reference the existing exhaustive operations; retaining this
# harmless superset keeps the reused checker compiling with a narrower selection.
source=source.replace("ops=sorted(set(x['operation'] for x in items))","ops=['address_offset','compare_u32','get_float','get_pair','get_u32','get_u8','identity_this','outputs_minus_one','set_pair','set_u32']")
exec(compile(source,str(pathlib.Path(__file__)),'exec'),{'__file__':__file__})
print(json.dumps(dict(candidates=len(items),references=sum(i['reference_count'] for i in items))))
