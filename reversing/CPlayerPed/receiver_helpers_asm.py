import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
items=json.loads((ROOT/'reversing/CPlayerPed/evidence/receiver-helpers-static.json').read_text())['methods']
signatures={0x9BE5F0:('TestEitherPredicate','void* player, void*','std::uint8_t'),0x9BEEF0:('SetPairFirstRaw','void* player, void*, std::uint32_t a1, std::uint32_t a2','std::uint32_t'),0x9BEF20:('SetPairSecondRaw','void* player, void*, std::uint32_t a1, std::uint32_t a2','std::uint32_t'),0x9BEF70:('GetRelatedRaw','void* player, void*','std::uint32_t'),0x9BE790:('TestActionAllowed','void* player, void*, std::uint32_t action, std::uint32_t flag','std::uint8_t')}
deps=set()
for item in items:
 lo=int(item['va'],16);hi=lo+item['size']
 for i in item['instructions']:
  if i['mnemonic'] in ('call','jmp') and i['operands'].startswith('0x'):
   addr=int(i['operands'],16)
   if not lo<=addr<hi:deps.add(addr)
lines=['#pragma once','#include <cstdint>','#if !defined(_MSC_VER) || !defined(_M_IX86)','#error Receiver helpers require MSVC x86 inline assembly.','#endif','namespace reiv::game::player_receiver_helpers {','// Player receiver proven; original declaring C++ class remains unknown.','// Complete caller ASM; raw EAX APIs describe bits, not the native semantic return type.','// Shared callback bindings are restricted to sequential isolated fixtures.']
lines += [f'inline void* call{d:08X}=nullptr;' for d in sorted(deps)]
fixture=['#pragma once','struct HelperPatch {unsigned offset,target;};','struct HelperFixture {unsigned va,size,mask;const unsigned char*bytes;const HelperPatch*patches;unsigned count;};']
for item in items:
 va=int(item['va'],16);name,args,ret=signatures[va];lo=va;hi=lo+item['size'];targets={int(i['operands'],16) for i in item['instructions'] if i['mnemonic'].startswith('j') and i['operands'].startswith('0x') and lo<=int(i['operands'],16)<hi};patches=[]
 lines += [f'__declspec(naked) inline {ret} __fastcall {name}({args}) {{',' __asm {']
 for i in item['instructions']:
  a=int(i['va'],16);m=i['mnemonic'];op=i['operands']
  if a in targets:lines.append(f' L{a:08X}:')
  if (m=='call' or m.startswith('j')) and op.startswith('0x'):
   target=int(op,16)
   if lo<=target<hi:op=f'L{target:08X}'
   else:op=f'dword ptr [call{target:08X}]';patches.append((a-lo+1,target))
  else:
   import re
   op=re.sub(r'0x([0-9a-f]+)',lambda x:'0'+x[1].upper()+'h',op)
  lines.append('  '+m+' '+op)
 lines += [' }','}']
 fixture += [f'inline constexpr unsigned char Bytes{va:X}[]={{'+','.join('0x'+x for x in item['body_bytes'].split())+'};',f'inline constexpr HelperPatch Patches{va:X}[]={{'+','.join('{'+str(off)+','+hex(t)+'}' for off,t in patches)+'};']
 item['external_tail_dependencies']=[hex(p[1]) for p in patches if p[1] not in [int(d,16) for d in item['direct_dependencies']]]
lines+=['}'];fixture+=['inline constexpr HelperFixture Helpers[]={']+[f'{{0x{int(i["va"],16):X},{i["size"]},'+('0xFF' if signatures[int(i['va'],16)][2]=='std::uint8_t' else '0xFFFFFFFF')+f',Bytes{int(i["va"],16):X},Patches{int(i["va"],16):X},sizeof(Patches{int(i["va"],16):X})/sizeof(HelperPatch)}},' for i in items]+['};','struct HelperBinding{unsigned va;void**target;};','inline HelperBinding HelperBindings[]={']+[f'{{0x{d:X},&reiv::game::player_receiver_helpers::call{d:08X}}},' for d in sorted(deps)]+['};']
(ROOT/'source/game/Peds/CPlayerPed.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(ROOT/'reversing/CPlayerPed/receiver-helpers-fixture.h').write_text('\n'.join(fixture)+'\n',encoding='utf-8')
(ROOT/'reversing/CPlayerPed/evidence/receiver-helpers-static.json').write_text(json.dumps(dict(exe_sha256='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c',methods=items),indent=2)+'\n',encoding='utf-8')
