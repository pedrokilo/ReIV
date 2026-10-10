"""Bounded entry disassembly plus complete finite scalar fixtures; never ABI inference."""
import csv, hashlib, json, struct
from pathlib import Path
import capstone
from capstone.x86 import *

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
EV=HERE/'evidence';EV.mkdir(parents=True,exist_ok=True)
data=Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes()
SHA='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
assert hashlib.sha256(data).hexdigest()==SHA
pe=struct.unpack_from('<I',data,60)[0];o=pe+24
sections=[]
for i in range(struct.unpack_from('<H',data,pe+6)[0]):
 p=o+struct.unpack_from('<H',data,pe+20)[0]+40*i
 va,size,ptr=struct.unpack_from('<III',data,p+12)
 sections.append((va,size,ptr,struct.unpack_from('<I',data,p+36)[0]))
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig',newline='')) if r['file'].startswith(('source/rage/','source/external/ART/'))]
group={}
for row in refs:group.setdefault(int(row['rva'],16),[]).append(row)
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);cs.detail=True

def recognize(ins):
 if not ins or ins[-1].mnemonic!='ret' or len(ins)>12:return None
 pop=ins[-1].operands[0].imm if ins[-1].operands else 0
 if pop not in (0,4,8,12,16,20,24):return None
 if len(ins)==2 and ins[0].mnemonic=='fldz':return dict(kind='float_zero',pop=pop,trace=[],mask=0xffffffff,expected_float=0)
 trace=[];known={'eax':0,'edx':0,'ecx':0xffffffff,'xmm0':0};writes=[]
 def operand(op,write=False):
  if op.type==X86_OP_IMM:return f'0x{op.imm&0xffffffff:08x}u'
  if op.type==X86_OP_REG:
   name=cs.reg_name(op.reg)
   if name not in ('eax','ax','al','edx','dx','dl','ecx'):raise ValueError('unsupported register')
   base={'ax':'eax','al':'eax','dx':'edx','dl':'edx'}.get(name,name)
   mask=(1<<(op.size*8))-1
   if not write and known[base]&mask!=mask:raise ValueError('uninitialized register read')
   return base if mask==0xffffffff else f'({base}&0x{mask:x}u)'
  if op.type==X86_OP_MEM:
   m=op.mem
   if m.segment or m.index or m.base not in (X86_REG_ECX,X86_REG_ESP):raise ValueError('global/indirect memory')
   if m.base==X86_REG_ESP:
    if write or op.size!=4 or m.disp<4 or m.disp>pop or m.disp%4:raise ValueError('stack argument outside pop')
    return f'args[{m.disp//4-1}]'
   if not 0<=m.disp<=4096-op.size or op.size not in (1,2,4):raise ValueError('field out of fixture')
   if write:writes.append((m.disp,op.size))
   return f'Load(expected+{m.disp},{op.size})'
  raise ValueError('unknown operand')
 def assign(dest,value):
  if dest.type==X86_OP_MEM:
   operand(dest,True);return f'Store(expected+{dest.mem.disp},{dest.size},{value});'
  operand(dest,True);name=cs.reg_name(dest.reg)
  if name=='ecx':raise ValueError('ECX mutation changes fixture base')
  base={'ax':'eax','al':'eax','dx':'edx','dl':'edx'}.get(name,name);mask=(1<<(dest.size*8))-1
  known[base]|=mask
  return f'{base}=({value});' if mask==0xffffffff else f'{base}=({base}&0x{(~mask)&0xffffffff:08x}u)|(({value})&0x{mask:x}u);'
 try:
  for i in ins[:-1]:
   ops=i.operands;m=i.mnemonic
   if m in ('mov','movzx') and len(ops)==2:trace.append(assign(ops[0],operand(ops[1])))
   elif m=='xor' and len(ops)==2 and ops[0].type==ops[1].type==X86_OP_REG and ops[0].reg==ops[1].reg:trace.append(assign(ops[0],'0'))
   elif m=='or' and len(ops)==2 and ops[0].type==X86_OP_REG and ops[1].type==X86_OP_IMM and ops[1].imm & ((1<<(ops[0].size*8))-1)==(1<<(ops[0].size*8))-1:
    trace.append(assign(ops[0],operand(ops[1])))
   elif m in ('and','or','add','sub','xor','shl','shr') and len(ops)==2:
    a,b=operand(ops[0]),operand(ops[1]);symbol={'and':'&','or':'|','add':'+','sub':'-','xor':'^','shl':'<<','shr':'>>'}[m]
    if m in ('shl','shr') and (ops[1].type!=X86_OP_IMM or not 0<=ops[1].imm<32):raise ValueError('unsafe shift')
    trace.append(assign(ops[0],f'({a}){symbol}({b})'))
   elif m=='lea' and len(ops)==2 and ops[1].type==X86_OP_MEM and ops[1].mem.base==X86_REG_ECX and not ops[1].mem.index and 0<=ops[1].mem.disp<=0x30000:
    trace.append(assign(ops[0],f'ecx+{ops[1].mem.disp}u'))
   elif m=='movss' and len(ops)==2:
    if ops[0].type==X86_OP_REG and ops[0].reg==X86_REG_XMM0 and ops[1].type==X86_OP_MEM and ops[1].size==4:
     trace.append('xmm0='+operand(ops[1])+';');known['xmm0']=0xffffffff
    elif ops[0].type==X86_OP_MEM and ops[0].size==4 and ops[1].type==X86_OP_REG and ops[1].reg==X86_REG_XMM0 and known['xmm0']==0xffffffff:
     trace.append(assign(ops[0],'xmm0'))
    else:raise ValueError('SSE candidate requires separate proof')
   elif m=='xorps' and len(ops)==2 and ops[0].type==ops[1].type==X86_OP_REG and ops[0].reg==ops[1].reg==X86_REG_XMM0:
    trace.append('xmm0=0;');known['xmm0']=0xffffffff
   else:raise ValueError('instruction unsupported')
  return dict(kind='scalar_fixture',pop=pop,trace=trace,mask=known['eax'],writes=writes)
 except ValueError:return None

inventory=[];candidates=[]
for rva,rows in sorted(group.items()):
 pending=[r for r in rows if r['runtime_reference_tested']!='1']
 if not pending:continue
 sec=next((s for s in sections if s[0]<=rva<s[0]+s[1] and s[3]&0x20000000),None)
 instructions=[];calls=[];branches=[];globals_=[];ret=False
 if sec:
  pos=sec[2]+rva-sec[0]
  for ins in cs.disasm(data[pos:pos+512],rva+0x400000):
   instructions.append(ins)
   if ins.mnemonic=='call':calls.append(ins.op_str)
   if ins.mnemonic.startswith('j'):branches.append(ins.op_str)
   for op in ins.operands:
    if op.type==X86_OP_MEM and not op.mem.base:globals_.append(ins.op_str)
   if ins.mnemonic=='ret':ret=True;break
   if ins.mnemonic in ('jmp','int3','ud2') or len(instructions)>=128:break
 fixture=recognize(instructions) if sec and rva!=0x1210 else None
 complete=ret and not calls and not branches
 reason='fatal handler excluded' if rva==0x1210 else 'safe scalar candidate not runtime checked' if fixture else 'direct call dependencies; ABI and game state unresolved' if calls else 'control flow unresolved; bounded entry slice' if branches else 'global/TLS memory or unsupported instruction; ABI unresolved' if complete else 'body boundary unresolved within bounded slice'
 item=dict(rva=f'0x{rva:08X}',va=f'0x{rva+0x400000:08X}',owners=sorted({r['owner'] for r in pending}),reference_count=len(pending),exe_sha256=SHA,classification=reason,complete_linear_body=complete,instructions=[f'{i.address:08X}: {i.mnemonic} {i.op_str}' for i in instructions],direct_calls=calls,branches=branches,global_operands=globals_,runtime_tested=False,enabled=False)
 if instructions:item['entry_bytes']=b''.join(i.bytes for i in instructions).hex(' ')
 inventory.append(item)
 if fixture:
  fixture.update(item);fixture['body_size']=sum(i.size for i in instructions);candidates.append(fixture)
(EV/'inventory.json').write_text(json.dumps(inventory,indent=2)+'\n',encoding='utf-8')
(EV/'fixture-scope.json').write_text(json.dumps(candidates,indent=2)+'\n',encoding='utf-8')
with (EV/'inventory.csv').open('w',encoding='utf-8',newline='') as f:
 fields=['rva','va','reference_count','classification','complete_linear_body','direct_calls','branches','global_operands','runtime_tested','enabled']
 w=csv.DictWriter(f,fieldnames=fields);w.writeheader()
 for x in inventory:w.writerow({k:json.dumps(x[k]) if isinstance(x[k],list) else x[k] for k in fields})
lines=['#pragma once','#include <cstring>','namespace pendingscalar {','struct Entry { reiv::original::FunctionAddress binding; unsigned pop; bool floating; unsigned mask; };']
for i,c in enumerate(candidates):lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join(f'0x{x:02x}' for x in bytes.fromhex(c['entry_bytes']))+'};')
lines.append('inline const Entry entries[]={')
for i,c in enumerate(candidates):lines.append('{{"Pending scalar '+c['va']+'",'+c['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},'+str(c['pop'])+','+str(c['kind']=='float_zero').lower()+',0x'+f'{c["mask"]:08x}'+'u},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline unsigned Load(const unsigned char* p,unsigned n){unsigned v=0;memcpy(&v,p,n);return v;}','inline void Store(unsigned char* p,unsigned n,unsigned v){memcpy(p,&v,n);}','inline unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args){unsigned eax=0,edx=0,xmm0=0;switch(i){']
for i,c in enumerate(candidates):lines.append(f'case {i}: '+' '.join(c['trace'])+' break;')
lines+=['}return eax;}']
template=(ROOT/'reversing/PendingAnalysis/rage-art/probe-template.txt').read_text(encoding='utf-8')
(ROOT/'source/hooks/PendingScalarProbe.h').write_text('\n'.join(lines)+'\n'+template,encoding='utf-8')
print(json.dumps(dict(pending_targets=len(inventory),candidates=len(candidates),candidate_references=sum(c['reference_count'] for c in candidates))))
