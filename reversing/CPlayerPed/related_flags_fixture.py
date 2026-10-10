import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=json.loads((ROOT/'reversing/CPlayerPed/evidence/related-flags-static.json').read_text())['methods'][0]
lines=['#pragma once','inline constexpr unsigned char RelatedFlagBytes[]={'+','.join('0x'+x for x in s['body_bytes'].split())+'};','struct RelatedFlagPatch{unsigned offset,address;};','inline constexpr RelatedFlagPatch RelatedFlagCalls[]={']
lines+=['{'+str(int(i['va'],16)-0x9BF250+1)+','+i['operands']+'},' for i in s['instructions'] if i['mnemonic']=='call' and i['operands'].startswith('0x')];lines+=['};','inline constexpr RelatedFlagPatch RelatedFlagGlobals[]={']
for address in [0x1662178,0x16180E0]:
 found=False
 for i in s['instructions']:
  b=bytes.fromhex(i['bytes']);off=b.find(address.to_bytes(4,'little'))
  if off>=0:lines.append('{'+str(int(i['va'],16)-0x9BF250+off)+','+hex(address)+'},');found=True
 assert found
lines+=['};'];(ROOT/'reversing/CPlayerPed/related-flags-fixture.h').write_text('\n'.join(lines)+'\n')
