import json,re
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];items=json.loads((ROOT/'reversing/CPlayerPed/evidence/actions-static.json').read_text())['methods']
for va,file,ns,name,args,ret in [(0x9C1300,'CPlayerPed.h','player_action_selection','Select','void* embeddedReceiver, void*, std::uint32_t flags, std::uint32_t rangeBits, std::uint32_t argument, float* output, std::uint32_t last','std::uint32_t')]:
 s=next(s for s in items if int(s['va'],16)==va);globals_=sorted(int(g,16) for g in s['global_uses']);calls=s['direct_dependencies'];tables=s['jump_tables']
 lines=['#pragma once','#include <cstdint>','#if !defined(_MSC_VER) || !defined(_M_IX86)','#error Player operations require MSVC x86 inline assembly.','#endif',f'namespace reiv::game::{ns} {{','// Complete own caller transcription. Dependencies and storage are explicit.','// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.']
 for g in globals_:lines.append(f'inline std::uint32_t g{g:08X}=0;')
 for c in calls:lines.append(f'inline void* call{int(c,16):08X}=nullptr; // exact original stack contract must be supplied')
 for t in tables:lines.append(f'inline std::uint32_t table{int(t["va"],16):08X}[4]{{}};')
 lines += [f'__declspec(naked) inline {ret} __fastcall {name}({args}) {{',' __asm {']
 if tables:
  lines.append(' // Resolve local code labels; LEA/MOV preserve flags. EAX is caller-saved, overwritten by the first original call.')
  for t in tables:
   for index,target in enumerate(t['targets']):lines+=[f'  lea eax, L{int(target,16):08X}',f'  mov dword ptr [table{int(t["va"],16):08X}+{index*4}], eax']
 targets={int(i['operands'],16) for i in s['instructions'] if i['mnemonic'].startswith('j') and i['operands'].startswith('0x')}
 targets.update(int(target,16) for t in tables for target in t['targets'])
 for i in s['instructions']:
  addr=int(i['va'],16);op=i['operands'];m=i['mnemonic']
  if m=='fcompi':m='fcomip';op='st, '+op
  if addr in targets:lines.append(f' L{addr:08X}:')
  if m=='call' and op=='0x9c1300':op='Select'
  elif m=='call' and op.startswith('0x'):op=f'dword ptr [call{int(op,16):08X}]'
  elif m.startswith('j') and op.startswith('0x'):op=f'L{int(op,16):08X}'
  else:
   for g in globals_:op=op.replace('[0x'+f'{g:x}'+']',f'[g{g:08X}]')
   for t in tables:op=op.replace('0x'+f'{int(t["va"],16):x}',f'table{int(t["va"],16):08X}')
   op=re.sub(r'0x([0-9a-f]+)',lambda m:'0'+m[1].upper()+'h',op)
  if 'fs:[g0000002C]' in op:op=op.replace('fs:[g0000002C]','[g0000002C]')
  lines.append('  '+m+' '+op)
 lines+=[' }','}','}']
 (ROOT/'source/game/Peds'/file).write_text('\n'.join(lines)+'\n',encoding='utf-8')
 prefix='Selection';fixture=['#pragma once',f'inline constexpr unsigned char {prefix}Bytes[]={{'+','.join('0x'+x for x in s['body_bytes'].split())+'};',f'struct {prefix}CallPatch{{unsigned offset,target;}};',f'inline constexpr {prefix}CallPatch {prefix}CallPatches[]={{']
 fixture += ['{'+str(int(i['va'],16)-va+1)+','+i['operands']+'},' for i in s['instructions'] if i['mnemonic']=='call' and i['operands'].startswith('0x')]
 fixture+=['};',f'struct {prefix}GlobalPatch{{unsigned offset,original;}};',f'inline constexpr {prefix}GlobalPatch {prefix}GlobalPatches[]={{']
 for g,uses in s['global_uses'].items():
  for u in uses:
   inst=next(i for i in s['instructions'] if i['va']==u['va']);r=bytes.fromhex(inst['bytes']);off=r.find(int(g,16).to_bytes(4,'little'));assert off>=0;fixture.append('{'+str(int(inst['va'],16)-va+off)+','+g+'},')
 for t in tables:
  for i in s['instructions']:
   if t['va'] in i['operands']:
    off=bytes.fromhex(i['bytes']).find(int(t['va'],16).to_bytes(4,'little'));fixture.append('{'+str(int(i['va'],16)-va+off)+','+t['va']+'},')
 fixture+=['};',f'struct {prefix}GlobalBinding{{unsigned original;std::uint32_t* storage;}};',f'inline {prefix}GlobalBinding {prefix}GlobalBindings[]={{']
 fixture += ['{'+hex(g)+',&reiv::game::'+ns+f'::g{g:08X}'+'},' for g in globals_];fixture+=['};']
 fixture += [f'struct {prefix}CallBinding{{unsigned original;void** target;}};',f'inline {prefix}CallBinding {prefix}CallBindings[]={{']+['{'+c+',&reiv::game::'+ns+f'::call{int(c,16):08X}'+'},' for c in calls]+['};']
 if tables:
  fixture += [f'inline constexpr unsigned {prefix}JumpTargets[][4]={{']+['{'+','.join(str(int(target,16)-va) for target in t['targets'])+'},' for t in tables]+['};']
 (ROOT/f'reversing/CPlayerPed/{prefix.lower()}-fixture.h').write_text('\n'.join(fixture)+'\n',encoding='utf-8')
 print(file,s['size'],s['instruction_count'])
