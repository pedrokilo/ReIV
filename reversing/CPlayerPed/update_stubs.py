import json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
data=json.loads((ROOT/'reversing/CPlayerPed/evidence/rea-update-callee-instructions.json').read_text())
cdecl={0x401950:2,0x462F90:0,0x924E80:1,0x987730:6,0xAA83F0:3,0xAB3B60:3}
pop_overrides={0x91A0A0:0,0x9E6630:0}
lines=['#pragma once'];contracts=[]
for entry in data:
 va=int(entry['address'],16);ins=entry['data']['result']['instructions'];rets=[]
 for i in ins:
  m=re.search(r': RET(?: (0x[0-9a-f]+))?$',i)
  if m:rets.append(int(m[1],16) if m[1] else 0)
 assert len(set(rets))<=1
 pop=rets[0] if rets else pop_overrides[va];words=cdecl.get(va,pop//4)
 contracts.append(dict(va=hex(va),callee_pop_bytes=pop,stack_words=words,thiscall=va not in cdecl,evidence='reversing/CPlayerPed/evidence/rea-tail-and-buffer-instructions.json; terminal targets 9164B0/9E6490 RET with zero pop' if not rets else 'Canonical callee RET and original caller pushes'))
 lines += [f'__declspec(naked) static void Stub{va:08X}() {{',' __asm {','  mov frameBase, ebp','  mov eax, esp','  add eax, 4',f'  push {words}','  push eax','  push ecx',f'  push 0{va:X}h','  call Record','  add esp, 16',f'  ret {pop}' if pop else '  ret',' }','}']
lines+=['static void* StubAddress(unsigned original){switch(original){']+[f'case 0x{int(x["va"],16):X}:return reinterpret_cast<void*>(&Stub{int(x["va"],16):08X});' for x in contracts]+['default:return nullptr;}}']
(ROOT/'reversing/CPlayerPed/update-stubs.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(ROOT/'reversing/CPlayerPed/evidence/update-callback-contracts.json').write_text(json.dumps(contracts,indent=2)+'\n',encoding='utf-8')
