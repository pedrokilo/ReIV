"""Transcribe complete canonical caller into MSVC x86 inline assembly."""
import json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
s=json.loads((ROOT/'reversing/CPlayerPed/evidence/update-static.json').read_text())
globals_=sorted((int(x,16) for x in s['global_uses']))
lines=['#pragma once','#include <cstdint>','#if !defined(_MSC_VER) || !defined(_M_IX86)','#error Player update transcription requires MSVC x86.','#endif','namespace reiv::game::player_update {','// Complete caller transcription, with external functions and globals explicit.','// ISOLATED FIXTURES ONLY: shared mutable storage is not thread-safe or a game binding.','// No live-game replacement is installed. Raw callback pointers retain original ABI.']
for va in globals_:lines.append(f'inline std::uint32_t g{va:08X}=0; // original storage VA 0x{va:08X}, exact operand widths below')
lines+=['inline unsigned char object0168F910[16]{}; // opaque context identity, dependency owns layout']
for va in s['direct_dependencies']:lines.append(f'inline void* call{int(va,16):08X}=nullptr;')
lines+=['// All dependencies must be bound before use; original caller uses AL return.','__declspec(naked) inline std::uint8_t __fastcall Update(void* object, void*) {','    __asm {']
targets={int(i['operands'],16) for i in s['instructions'] if i['mnemonic'].startswith('j') and i['operands'].startswith('0x')}
for i in s['instructions']:
 va=int(i['va'],16)
 if va in targets:lines.append(f'    L{va:08X}:')
 op=i['operands'];m=i['mnemonic']
 if m=='call' and op.startswith('0x'):op='dword ptr [call'+f'{int(op,16):08X}'+']'
 elif m.startswith('j') and op.startswith('0x'):op='L'+f'{int(op,16):08X}'
 else:
  for g in globals_:op=op.replace('[0x'+f'{g:x}'+']','[g'+f'{g:08X}'+']')
  if m=='mov' and op=='ecx, 0x168f910':op='ecx, offset object0168F910'
  # MSVC inline assembler uses h-suffixed hexadecimal immediates.
  op=re.sub(r'0x([0-9a-f]+)',lambda m:'0'+m[1].upper()+'h',op)
 lines.append('        '+m+' '+op)
lines+=['    }','}','}']
(ROOT/'source/game/Peds/CPlayerPed.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
fixture=['#pragma once','inline constexpr unsigned char UpdateBytes[]={'+','.join('0x'+x for x in s['body_bytes'].split())+'};','struct UpdateCallPatch{unsigned offset,target;};','inline constexpr UpdateCallPatch UpdateCallPatches[]={']
fixture += ['{'+str(int(i['va'],16)-0x9C0B00+1)+','+i['operands']+'},' for i in s['instructions'] if i['mnemonic']=='call' and i['operands'].startswith('0x')]
fixture+=['};','struct UpdateGlobalPatch{unsigned offset,original;};','inline constexpr UpdateGlobalPatch UpdateGlobalPatches[]={']
body=bytes.fromhex(s['body_bytes'])
for g,uses in s['global_uses'].items():
 for use in uses:
  i=next(i for i in s['instructions'] if i['va']==use['va']);raw=bytes.fromhex(i['bytes']);off=raw.find(int(g,16).to_bytes(4,'little'));assert off>=0
  fixture.append('{'+str(int(i['va'],16)-0x9C0B00+off)+','+g+'},')
fixture+=['{'+str(0x9C0C8A-0x9C0B00)+',0x168F910},','{'+str(0x9C0C95-0x9C0B00)+',0x168F910},','};']
fixture+=['struct UpdateGlobalBinding {unsigned original;std::uint32_t* storage;};','inline UpdateGlobalBinding UpdateGlobalBindings[]={']
fixture += ['{'+hex(g)+',&reiv::game::player_update::g'+f'{g:08X}'+'},' for g in globals_]
fixture+=['};','struct UpdateCallBinding{unsigned original;void** target;};','inline UpdateCallBinding UpdateCallBindings[]={']
fixture += ['{'+g+',&reiv::game::player_update::call'+f'{int(g,16):08X}'+'},' for g in s['direct_dependencies']]
fixture+=['};']
(ROOT/'reversing/CPlayerPed/update-fixture.h').write_text('\n'.join(fixture)+'\n',encoding='utf-8')
print('Transcribed567instructions; direct callees explicit, global operands mapped.')
