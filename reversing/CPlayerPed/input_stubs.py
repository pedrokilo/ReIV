import json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
old=json.loads((ROOT/'reversing/CPlayerPed/evidence/rea-update-callee-instructions.json').read_text());new=json.loads((ROOT/'reversing/CPlayerPed/evidence/rea-input-callee-instructions.json').read_text())
by={int(x['address'],16):x['data']['result'] for x in old};by.update({int(x['address'],16):x['result']['result'] for x in new['callees'] if x['result']})
method=next(x for x in json.loads((ROOT/'reversing/CPlayerPed/evidence/remaining-update-methods.json').read_text())['methods'] if x['va']=='0x9be7d0')
cdecl={0x8FF470:0,0x924E80:1,0x4255A0:1,0x9B3B00:1,0x9ADB90:0,0x462F90:0,0x987730:6,0x99C5E0:1};contracts=[];lines=['#pragma once']
for va in (int(x,16) for x in method['direct_dependencies']):
 # Counter's existing canonical query contract: 426957 C2 08 00.
 ins=by[va]['instructions'] if va in by else ['0x426957: RET 0x8'] if va==0x426910 else None
 assert ins is not None,hex(va)
 pops=[]
 for i in ins:
  m=re.search(r': RET(?: (0x[0-9a-f]+))?$',i)
  if m:pops.append(int(m[1],16) if m[1] else 0)
 assert len(set(pops))<=1
 pop=pops[0] if pops else 0;assert pops or va==0x4255A0
 words=cdecl.get(va,pop//4);contracts.append(dict(va=hex(va),pop=pop,stack_words=words,thiscall=va not in cdecl,evidence='Canonical callee RET;4255A0 tail98CA30 has RET0'))
 lines += [f'__declspec(naked) static void InputStub{va:08X}(){{',' __asm{','  mov eax,esp','  add eax,4']
 if va==0x9BE5D0:lines += ['  mov stackAnchor,eax']
 lines += [f'  push {words}','  push eax','  push ecx',f'  push 0{va:X}h','  call Record','  add esp,16',f'  ret {pop}' if pop else '  ret',' }','}']
lines+=['static void* Stub(unsigned target){switch(target){']+[f'case 0x{int(c["va"],16):X}:return reinterpret_cast<void*>(&InputStub{int(c["va"],16):08X});' for c in contracts]+['default:return nullptr;}}']
(ROOT/'reversing/CPlayerPed/input-stubs.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(ROOT/'reversing/CPlayerPed/evidence/input-selection-contracts.json').write_text(json.dumps(contracts,indent=2)+'\n',encoding='utf-8')
