"""Generate ORIGINAL executable validation bytes, never a reconstructed body."""
from pathlib import Path
import hashlib,json,struct
ROOT=Path(__file__).resolve().parents[2]
exe=Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe')
data=exe.read_bytes()
assert hashlib.sha256(data).hexdigest()=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',data,60)[0]
count=struct.unpack_from('<H',data,pe+6)[0]
optional=struct.unpack_from('<H',data,pe+20)[0]
image_size=struct.unpack_from('<I',data,pe+24+56)[0]
def read(va,length):
    rva=va-0x400000
    for i in range(count):
        _,section,size,raw=struct.unpack_from('<IIII',data,pe+24+optional+i*40+8)
        if section<=rva and rva+length<=section+size:
            return data[raw+rva-section:raw+rva-section+length]
    raise ValueError(hex(va))
reloc_rva,reloc_size=struct.unpack_from('<II',data,pe+24+96+5*8)
reloc_data=read(0x400000+reloc_rva,reloc_size)
relocs=set();position=0
while position<len(reloc_data):
    block,size=struct.unpack_from('<II',reloc_data,position)
    assert size>=8 and size%2==0
    for offset in range(position+8,position+size,2):
        entry=struct.unpack_from('<H',reloc_data,offset)[0]
        if entry>>12==3:relocs.add(0x400000+block+(entry&0xFFF))
        else:assert entry>>12==0
    position+=size
manifest=json.loads((ROOT/'reversing/CPlayerPed/evidence/native-binding-design.json').read_text())
callbacks=sorted({r['original_va'] for b in manifest['bodies'] for r in b['relocations'] if r['category']=='call'})
specs=[('Update',0x9C0B00,2046),('Adjust',0x9BFD80,332),('Select',0x9BE7D0,1652)]
specs += [(f'Callee{va:08X}',va,16) for va in callbacks]
lines=['#pragma once','#include "../NativeValidatedResolver.h"','namespace reiv::player_native {','// ORIGINAL bytes below validate identity only; never exposed as executable templates.']
records=[]
for name,va,length in specs:
    touching=[r for r in relocs if va<=r<va+length]
    if touching:length=max(length,max(r+4-va for r in touching))
    assert not any(r<va<r+4 for r in relocs)
    body=read(va,length)
    operands=[]
    for relocation in sorted(r for r in relocs if va<=r<va+length):
        offset=relocation-va;value=struct.unpack_from('<I',body,offset)[0]
        assert 0x400000<=value<0x400000+image_size
        operands.append((offset,value))
    lines.append(f'inline constexpr unsigned char Validation{name}Bytes[]={{'+','.join(hex(b) for b in body)+'};')
    # A dummy array keeps standard C++ valid when no image relocation exists.
    lines.append(f'inline constexpr Operand Validation{name}Operands[]={{'+(','.join('{'+str(o)+','+str(v)+'}' for o,v in operands) or '{0,0}')+'};')
    record=f'{{{va},Validation{name}Bytes,sizeof Validation{name}Bytes,Validation{name}Operands,{len(operands)}}}'
    records.append(record)
lines.append('inline constexpr ExpectedBody ValidationBodies[]={'+','.join(records[:3])+'};')
lines.append('inline constexpr ExpectedEntry ValidationEntries[]={'+','.join(records[3:])+'};')
references={}
for b in manifest['bodies']:
    for r in b['relocations']:
        if r['category'] not in ('g','object'):continue
        instruction=r['instruction']
        width=16 if 'xmmword ptr' in instruction else 4 if 'dword ptr' in instruction else 2 if 'word ptr' in instruction else 1
        key=(r['category'],r['original_va'])
        references[key]=max(references.get(key,0),width)
lines.append('inline constexpr AllowedReference ValidationReferences[]={'+','.join('{player_clone::Kind::'+('Global' if kind=='g' else 'Object')+f',{va},{width}'+'}' for (kind,va),width in sorted(references.items()))+'};')
lines.append('inline bool ValidateCurrentGame(ValidatedResolver& resolver,std::string& error){return resolver.Open(ValidationBodies,sizeof ValidationBodies/sizeof(ExpectedBody),ValidationEntries,sizeof ValidationEntries/sizeof(ExpectedEntry),ValidationReferences,sizeof ValidationReferences/sizeof(AllowedReference),error);}')
lines.append('}')
out=ROOT/'reversing/CPlayerPed/native-clone/native-validation.h'
out.write_text('\n'.join(lines)+'\n')
summary=dict(exe_sha256=hashlib.sha256(data).hexdigest(),generated_header_sha256=hashlib.sha256(out.read_bytes()).hexdigest(),original_validation_only=True,reconstructed_code=False,callee_count=len(callbacks),body_count=3,relocation_source='PE IMAGE_REL_BASED_HIGHLOW',game_runtime_validated=False)
(ROOT/'reversing/CPlayerPed/evidence/native-validation-manifest.json').write_text(json.dumps(summary,indent=2)+'\n')
print('PASS original validation manifest',len(callbacks),'callee entries,3 complete caller bodies,ASLR operands from PE relocation table')
