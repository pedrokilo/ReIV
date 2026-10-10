"""Complete acyclic CFG scalar fixtures only. Every reachable instruction is reviewed."""
import csv,hashlib,json,struct
from pathlib import Path
import capstone
from capstone.x86 import *
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;EV=HERE/'evidence';EV.mkdir(parents=True,exist_ok=True)
d=Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes();SHA=hashlib.sha256(d).hexdigest();assert SHA=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',d,60)[0];o=pe+24;sections=[]
for n in range(struct.unpack_from('<H',d,pe+6)[0]):
 p=o+struct.unpack_from('<H',d,pe+20)[0]+40*n;va,size,ptr=struct.unpack_from('<III',d,p+12);sections.append((va,size,ptr,struct.unpack_from('<I',d,p+36)[0]))
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);cs.detail=True
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig',newline='')) if r['file'].startswith('source/rage/') and r['runtime_reference_tested']!='1']
group={}
for r in refs:group.setdefault(int(r['rva'],16),[]).append(r)
conditions={'je':'z','jz':'z','jne':'!z','jnz':'!z','ja':'!c&&!z','jae':'!c','jb':'c','jbe':'c||z','jg':'!z&&(s==v)','jge':'s==v','jl':'s!=v','jle':'z||(s!=v)'}
setconditions={k.replace('j','set',1):v for k,v in conditions.items()}
def build(rva):
 sec=next((s for s in sections if s[0]<=rva<s[0]+s[1] and s[3]&0x20000000),None)
 if not sec:raise ValueError('not executable')
 start=rva+0x400000;pos=sec[2]+rva-sec[0];nodes={};successors={};pops=set()
 def visit(a):
  if a in nodes:return
  if not start<=a<start+256:raise ValueError('branch beyond finite body limit')
  i=next(cs.disasm(d[pos+a-start:pos+a-start+16],a,count=1),None)
  if not i:raise ValueError('decode failure')
  nodes[a]=i
  if len(nodes)>64:raise ValueError('CFG node limit')
  if i.mnemonic=='ret':
   pop=i.operands[0].imm if i.operands else 0
   if pop not in (0,4,8,12,16,20,24):raise ValueError('unsupported stack cleanup')
   pops.add(pop);successors[a]=[];return
  if i.mnemonic.startswith('j'):
   if i.operands[0].type!=X86_OP_IMM:raise ValueError('indirect branch')
   target=i.operands[0].imm
   if target<=a:raise ValueError('cycle/backward branch excluded')
   if i.mnemonic=='jmp':succ=[target]
   elif i.mnemonic in conditions:succ=[a+i.size,target]
   else:raise ValueError('unknown branch condition')
  else:succ=[a+i.size]
  successors[a]=succ
  for nxt in succ:visit(nxt)
 visit(start)
 if len(pops)!=1:raise ValueError('inconsistent cleanup')
 pop=next(iter(pops));state={start:({'eax':0,'edx':0,'ecx':0xffffffff},False)};lines={};retmasks=[];fields=[]
 def operand(op,known,write=False):
  if op.type==X86_OP_IMM:return f'0x{op.imm&0xffffffff:08x}u'
  if op.type==X86_OP_REG:
   name=cs.reg_name(op.reg);base={'ax':'eax','al':'eax','dx':'edx','dl':'edx'}.get(name,name)
   if base not in known:raise ValueError('unsupported register')
   mask=(1<<(op.size*8))-1
   if not write and known[base]&mask!=mask:raise ValueError('unknown register bits')
   return base if mask==0xffffffff else f'({base}&0x{mask:x}u)'
  if op.type==X86_OP_MEM:
   m=op.mem
   if m.segment or m.index or m.base not in (X86_REG_ECX,X86_REG_ESP):raise ValueError('global/TLS/index/pointer chase excluded')
   if m.base==X86_REG_ESP:
    if write or op.size not in (1,2,4) or m.disp<4 or m.disp>pop or m.disp%4:raise ValueError('unsupported stack access')
    return f'(args[{m.disp//4-1}]&0x{(1<<(op.size*8))-1:x}u)'
   if op.size not in (1,2,4) or not 0<=m.disp<=4096-op.size:raise ValueError('field out of range')
   fields.append((m.disp,op.size));return f'Load(expected+{m.disp},{op.size})'
  raise ValueError('unknown operand')
 def assign(op,value,known):
  operand(op,known,True)
  if op.type==X86_OP_MEM:return f'Store(expected+{op.mem.disp},{op.size},{value});'
  name=cs.reg_name(op.reg);base={'ax':'eax','al':'eax','dx':'edx','dl':'edx'}.get(name,name)
  if base=='ecx':raise ValueError('fixture base mutation excluded')
  mask=(1<<(op.size*8))-1;known[base]|=mask
  return f'{base}=({value});' if mask==0xffffffff else f'{base}=({base}&0x{(~mask)&0xffffffff:08x}u)|(({value})&0x{mask:x}u);'
 for a in sorted(nodes):
  known,flagknown=state[a];known=known.copy();i=nodes[a];m=i.mnemonic;ops=i.operands;code=''
  if m=='ret':retmasks.append(known['eax']);code='return eax;'
  elif m=='jmp':code=f'goto L{ops[0].imm-start};'
  elif m in conditions:
   if not flagknown:raise ValueError('branch consumes unknown flags')
   code=f'if({conditions[m]})goto L{ops[0].imm-start};'
  elif m in ('cmp','test'):
   a0,b=operand(ops[0],known),operand(ops[1],known);code=f'Flags({a0},{b},{ops[0].size},{str(m=="test").lower()},z,s,v,c);';flagknown=True
  elif m in setconditions:
   if not flagknown:raise ValueError('setcc consumes unknown flags')
   code=assign(ops[0],f'({setconditions[m]}?1u:0u)',known)
  elif m in ('mov','movzx'):code=assign(ops[0],operand(ops[1],known),known)
  elif m=='xor' and ops[0].type==ops[1].type==X86_OP_REG and ops[0].reg==ops[1].reg:
   code=assign(ops[0],'0',known)+'z=true;s=v=c=false;';flagknown=True
  elif m in ('and','or','xor','add','sub','shl','shr'):
   left,right=operand(ops[0],known),operand(ops[1],known);symbol={'and':'&','or':'|','xor':'^','add':'+','sub':'-','shl':'<<','shr':'>>'}[m]
   if m in ('shl','shr') and (ops[1].type!=X86_OP_IMM or not 0<ops[1].imm<32):raise ValueError('unsupported shift')
   if m=='sub':code=f'Flags({left},{right},{ops[0].size},false,z,s,v,c);';flagknown=True
   elif m in ('and','or','xor'):code=f'LogicFlags(({left}){symbol}({right}),{ops[0].size},z,s,v,c);';flagknown=True
   else:flagknown=False
   code+=assign(ops[0],f'({left}){symbol}({right})',known)
  elif m=='lea' and ops[1].type==X86_OP_MEM:
   mem=ops[1].mem
   if mem.segment:raise ValueError('segmented LEA')
   val=str(mem.disp)+'u'
   for reg,scale in [(mem.base,1),(mem.index,mem.scale)]:
    if reg:
     name=cs.reg_name(reg)
     if name not in known or known[name]!=0xffffffff:raise ValueError('unknown LEA register')
     val+=f'+{name}*{scale}u'
   code=assign(ops[0],val,known)
  elif m=='imul' and len(ops)==3:
   code=assign(ops[0],f'({operand(ops[1],known)})*({operand(ops[2],known)})',known);flagknown=False
  else:raise ValueError('unsupported instruction '+m)
  if m!='ret' and m!='jmp':code+=f'goto L{a+i.size-start};'
  lines[a]=code
  for nxt in successors[a]:
   if nxt in state:
    old,oldflags=state[nxt];state[nxt]=({r:old[r]&known[r] for r in old},oldflags and flagknown)
   else:state[nxt]=(known.copy(),flagknown)
 mask=0xffffffff
 for x in retmasks:mask&=x
 # Record the complete byte envelope and all independently decoded CFG nodes.
 end=max(a+i.size for a,i in nodes.items());raw=d[pos:pos+end-start]
 return dict(pop=pop,mask=mask,fields=sorted(set(fields)),entry_bytes=raw.hex(' '),body_size=len(raw),nodes=[dict(address=f'0x{a:08X}',instruction=f'{i.mnemonic} {i.op_str}',successors=[f'0x{x:08X}' for x in successors[a]]) for a,i in sorted(nodes.items())],expected_code='\n'.join(f'L{a-start}: visited[index]|=1ull<<{n}; {lines[a]}' for n,a in enumerate(sorted(nodes))),branches=sum(i.mnemonic.startswith('j') for i in nodes.values()))
candidates=[];rejected=[]
for rva,rows in sorted(group.items()):
 if rva==0x1210:continue
 try:
  item=build(rva)
  if not item['branches']:continue # prior linear scanner scope; this batch focuses complete CFGs
  item.update(rva=f'0x{rva:08X}',va=f'0x{rva+0x400000:08X}',owners=sorted({r['owner'] for r in rows}),reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=SHA)
  candidates.append(item)
 except ValueError as e:rejected.append(dict(rva=f'0x{rva:08X}',reason=str(e)))
(EV/'fixture-scope.json').write_text(json.dumps(candidates,indent=2)+'\n',encoding='utf-8');(EV/'rejected.json').write_text(json.dumps(rejected,indent=2)+'\n',encoding='utf-8')
lines=['#pragma once','#include <cstring>','namespace ragecomplex {','struct Entry { reiv::original::FunctionAddress binding; unsigned pop; bool floating; unsigned mask; };']
for n,c in enumerate(candidates):lines.append(f'inline constexpr unsigned char bytes{n}[]={{'+','.join(f'0x{x:02x}' for x in bytes.fromhex(c['entry_bytes']))+'};')
lines.append('inline const Entry entries[]={')
for n,c in enumerate(candidates):lines.append('{{"Rage complete CFG '+c['va']+'",'+c['rva']+',bytes'+str(n)+',sizeof(bytes'+str(n)+'),reiv::original::BindingState::StaticVerified},'+str(c['pop'])+',false,0x'+f'{c["mask"]:08x}'+'u},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline unsigned long long visited[count]{};','inline unsigned Load(const unsigned char* p,unsigned n){unsigned v=0;memcpy(&v,p,n);return v;}','inline void Store(unsigned char* p,unsigned n,unsigned v){memcpy(p,&v,n);}',
'inline void LogicFlags(unsigned a,unsigned n,bool& z,bool& s,bool& v,bool& c){unsigned mask=n==4?0xffffffffu:(1u<<(n*8))-1;unsigned sign=1u<<(n*8-1);a&=mask;z=!a;s=(a&sign)!=0;v=c=false;}',
'inline void Flags(unsigned a,unsigned b,unsigned n,bool test,bool& z,bool& s,bool& v,bool& c){if(test){LogicFlags(a&b,n,z,s,v,c);return;}unsigned mask=n==4?0xffffffffu:(1u<<(n*8))-1;unsigned sign=1u<<(n*8-1);a&=mask;b&=mask;unsigned r=(a-b)&mask;z=!r;s=(r&sign)!=0;c=a<b;v=((a^b)&(a^r)&sign)!=0;}']
for n,c in enumerate(candidates):lines.append(f'inline unsigned Expected{n}(unsigned char* expected,unsigned ecx,const unsigned* args){{constexpr unsigned index={n};unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;\n'+c['expected_code']+'\n}')
lines.append('inline unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args){switch(i){')
for n,c in enumerate(candidates):lines.append(f'case {n}:return Expected{n}(expected,ecx,args);')
lines.append('}return 0;}')
lines.append('inline void Setup(unsigned i,unsigned sample,unsigned char* object,const unsigned* args){switch(i){')
for n,c in enumerate(candidates):
 lines.append(f'case {n}: '+' '.join(f'Store(object+{off},{width},sample<32?((sample>>{j%5})&1?args[0]:0):args[0]^{j*0x10203}u);' for j,(off,width) in enumerate(c['fields']))+'break;')
lines.append('}}')
template=(ROOT/'reversing/PendingAnalysis/rage-art/probe-template.txt').read_text(encoding='utf-8').replace('ReIV-pending-scalar','ReIV-rage-complex').replace('ReIV.pending-scalar','ReIV.rage-complex').replace('Pending scalar','Rage complete CFG')
# Small/signed/boundary values exercise argument-switch paths, and varied field bytes exercise branches.
template=template.replace('0x87654321u^(sample*0x01020408u)^(n*0x02030405u)','sample<32?sample+n:(sample==32?0xffffffffu:0x80000000u+(sample-33)*0x1020304u+n)')
template=template.replace('const unsigned wanted=Expected', 'Setup(i,sample,object,args);memcpy(expected,object,sizeof(object));\n  const unsigned wanted=Expected')
template=template.replace(r'\"disabled\":%s}',r'\"disabled\":%s,\"expected_nodes_mask\":\"0x%016llX\"}')
template=template.replace('failures[i]?"true":"false");fprintf', 'failures[i]?"true":"false",visited[i]);fprintf')
(ROOT/'source/hooks/RageComplexProbe.h').write_text('\n'.join(lines)+'\n'+template,encoding='utf-8')
print(json.dumps(dict(candidates=len(candidates),references=sum(c['reference_count'] for c in candidates),rejected=len(rejected))))
