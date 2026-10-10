import hashlib,json,struct
from pathlib import Path
import capstone
ROOT=Path(__file__).resolve().parents[2]
b=Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes();digest=hashlib.sha256(b).hexdigest()
assert digest=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',b,60)[0];o=p+24+struct.unpack_from('<H',b,p+20)[0]
sections=[struct.unpack_from('<III',b,o+i*40+12) for i in range(struct.unpack_from('<H',b,p+6)[0])]
def raw(va,n):
 s=next(s for s in sections if s[0]<=va-0x400000<s[0]+s[1]);q=s[2]+va-0x400000-s[0];return b[q:q+n]
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32)
lines=['#pragma once','struct ControlPatch { unsigned offset,target; };'];items=[]
for name,va,n in [('model',0x9C0AA0,87),('create',0x9C1E10,74)]:
 code=raw(va,n);ins=list(cs.disasm(code,va));assert sum(i.size for i in ins)==n
 lines.append('inline constexpr unsigned char '+name+'Bytes[]={'+','.join(hex(x) for x in code)+'};')
 patches=[(i.address-va+1,int(i.op_str,16)) for i in ins if i.mnemonic=='call']
 lines.append('inline constexpr ControlPatch '+name+'Patches[]={'+','.join('{'+f'{off},0x{target:X}'+'}' for off,target in patches)+'};')
 items.append(dict(va=f'0x{va:08X}',bytes=code.hex(' '),instructions=[dict(va=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins],patches=[dict(offset=x,target=hex(y)) for x,y in patches]))
(ROOT/'reversing/CPlayerPed/control-fixture.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(ROOT/'reversing/CPlayerPed/evidence/control-static.json').write_text(json.dumps(dict(exe_sha256=digest,functions=items,dependencies_reconstructed=False),indent=2)+'\n',encoding='utf-8')
