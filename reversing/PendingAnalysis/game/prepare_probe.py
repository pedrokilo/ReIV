import pathlib,json
ROOT=pathlib.Path(__file__).resolve().parents[3];P=pathlib.Path(__file__).resolve().parent
items=json.loads((P/'fixture-scope.json').read_text())
lines=['#pragma once','#include <cstring>','namespace gamepending {','enum class Operation { address_offset,compare_u32,get_float,get_pair,get_u32,get_u8,identity_this,outputs_minus_one,set_pair,set_u32,set_u8 };','struct Entry { reiv::original::FunctionAddress binding; Operation operation; unsigned offset; };']
for i,x in enumerate(items):lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join('0x'+b for b in x['entry_bytes'].split())+'};')
lines.append('inline const Entry entries[]={')
for i,x in enumerate(items):lines.append('{{"Game pending '+x['va']+'",'+x['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},Operation::'+x['operation']+','+str(x['value'])+'},')
lines.append('};')
tail=(ROOT/'source/hooks/AudioFixtureProbe.h').read_text();tail=tail[tail.index('inline constexpr unsigned count='):]
tail=tail.replace('ReIV-audio-fixtures.json','ReIV-game-pending.json').replace('ReIV.audio-fixtures-test','ReIV.game-pending-test').replace('Audio fixture','Game pending')
tail=tail.replace('inline int Check(unsigned i)','inline int Check(unsigned i,unsigned sample)')
tail=tail.replace('memset(object,0xa5,sizeof(object))','memset(object,(sample*17+0xa5)&255,sizeof(object))')
tail=tail.replace('unsigned a=0x12345678,b=0x87654321; float value=3.25f;','unsigned a=0x12345678^(sample*0x01020408),b=0x87654321^(sample*0x04030201); float value=3.25f+sample;')
tail=tail.replace('object[e.offset]=0x71','object[e.offset]=static_cast<unsigned char>(0x71+sample)').replace('!=0x71','!=static_cast<unsigned char>(0x71+sample)')
tail=tail.replace('case Operation::set_u32:', 'case Operation::set_u8: {using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,b);memcpy(expected+e.offset,&b,1);break;}\n   case Operation::set_u32:')
tail=tail.replace('int result=Check(i);','int result=Check(i,n);')
(ROOT/'source/hooks/GamePendingProbe.h').write_text('\n'.join(lines)+'\n'+tail,encoding='utf-8')
print(len(items))
