"""Exact 41-byte deleting-destructor body; tests ONLY flags bit0 clear."""
import csv,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).parent;EV=HERE/'evidence';EV.mkdir(exist_ok=True)
b=Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes();sha=hashlib.sha256(b).hexdigest();assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',b,60)[0];opt=p+24;o=opt+struct.unpack_from('<H',b,p+20)[0];secs=[struct.unpack_from('<III',b,o+i*40+12) for i in range(struct.unpack_from('<H',b,p+6)[0])]
def offset(rva):
 s=next(s for s in secs if s[0]<=rva<s[0]+s[1]);return s[2]+rva-s[0]
reloc_rva,reloc_size=struct.unpack_from('<II',b,opt+96+5*8);rp=offset(reloc_rva);end=rp+reloc_size;relocs=set()
while rp+8<=end:
 page,size=struct.unpack_from('<II',b,rp)
 if size<8:break
 for q in range(rp+8,rp+size,2):
  x=struct.unpack_from('<H',b,q)[0]
  if x>>12==3:relocs.add(page+(x&4095))
 rp+=size
refs=list(csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig')));groups={}
for r in refs:
 if r['runtime_reference_tested']=='0':groups.setdefault(int(r['rva'],16),[]).append(r)
pattern=bytes.fromhex('f644240401568bf1c70600000000741364a12c0000008b088b49088b118b420c56ffd08bc65ec20400');items=[]
for r,rows in sorted(groups.items()):
 try:q=offset(r)
 except StopIteration:continue
 raw=b[q:q+41]
 if raw[:10]!=pattern[:10] or raw[14:]!=pattern[14:]:continue
 assert r+10 in relocs
 target=struct.unpack_from('<I',raw,10)[0];offset(target-0x400000)
 items.append(dict(rva=f'0x{r:08X}',va=f'0x{r+0x400000:08X}',owners=sorted({x['owner'] for x in rows}),reference_count=len(rows),vtable_rva=f'0x{target-0x400000:08X}',entry_bytes=raw.hex(' '),relocated_offset=10,flags_restriction='bit0 clear only; freeing/TLS branch never entered',excluded_branch='offset16..34 including TLS allocator call',exe_sha256=sha))
(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n',encoding='utf-8')
lines=['#pragma once','#include <cstring>','namespace destructormode {','struct Entry{unsigned rva,vtable;const unsigned char* bytes;};']
for i,c in enumerate(items):lines.append(f"inline constexpr unsigned char b{i}[]={{"+','.join('0x'+x for x in c['entry_bytes'].split())+'};')
lines+=['inline const Entry entries[]={']+[f"{{{c['rva']},{c['vtable_rva']},b{i}}}," for i,c in enumerate(items)]+['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);']
lines+=(HERE/'probe-template.txt').read_text().splitlines()
(ROOT/'source/hooks/DestructorModeProbe.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
print(len(items),sum(x['reference_count'] for x in items))
