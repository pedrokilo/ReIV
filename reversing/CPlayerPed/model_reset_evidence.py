import json,struct,hashlib
from pathlib import Path
import capstone
ROOT=Path(__file__).resolve().parents[2];b=Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes();digest=hashlib.sha256(b).hexdigest();assert digest=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',b,60)[0];o=p+24+struct.unpack_from('<H',b,p+20)[0];ss=[struct.unpack_from('<III',b,o+i*40+12) for i in range(struct.unpack_from('<H',b,p+6)[0])]
def raw(va,n):
 s=next(s for s in ss if s[0]<=va-0x400000<s[0]+s[1]);q=s[2]+va-0x400000-s[0];return b[q:q+n]
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);va=0x9BF660;code=raw(va,163);ins=list(cs.disasm(code,va));assert sum(i.size for i in ins)==163
calls=[dict(offset=i.address-va+1,target=hex(int(i.op_str,16))) for i in ins if i.mnemonic=='call' and i.op_str.startswith('0x')]
deps=[]
for c in calls:
 entry=int(c['target'],16);ret=next(i for i in cs.disasm(raw(entry,2048),entry) if i.mnemonic=='ret');deps.append(dict(va=hex(entry),first_ret_va=hex(ret.address),first_ret_bytes=ret.bytes.hex(' '),callee_pop=ret.op_str or '0',note='Canonical first reachable linear RET; caller supplies corresponding stack words.'))
result=dict(exe_sha256=digest,va=hex(va),bytes=code.hex(' '),size=163,instructions=[dict(va=hex(i.address),mnemonic=i.mnemonic,operands=i.op_str) for i in ins],calls=calls,dependencies=deps,globals={'source':'0x00D50398','destination':'0x00F1D9D8'},virtual_slot=68)
(ROOT/'reversing/CPlayerPed/evidence/model-reset-static.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
lines=['#pragma once','inline constexpr unsigned char ModelResetBytes[]={'+','.join(hex(x) for x in code)+'};','struct ModelResetPatch{unsigned offset,target;};','inline constexpr ModelResetPatch ModelResetPatches[]={']+['{'+str(c['offset'])+','+c['target']+'},' for c in calls]+['};']
(ROOT/'reversing/CPlayerPed/model-reset-fixture.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
