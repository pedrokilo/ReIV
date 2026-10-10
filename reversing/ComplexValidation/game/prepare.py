"""Recognize complete linear comparison and bit-accessor bodies; reject all calls/branches."""
import csv,hashlib,json,pathlib,struct,capstone
ROOT=pathlib.Path(__file__).resolve().parents[3];P=pathlib.Path(__file__).resolve().parent;EV=P/'evidence';EV.mkdir(parents=True,exist_ok=True)
d=pathlib.Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes();sha=hashlib.sha256(d).hexdigest();assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',d,60)[0];opt=pe+24;sections=[]
for i in range(struct.unpack_from('<H',d,pe+6)[0]):
 p=opt+struct.unpack_from('<H',d,pe+20)[0]+40*i;va,size,ptr=struct.unpack_from('<III',d,p+12);sections.append((va,size,ptr,struct.unpack_from('<I',d,p+36)[0]))
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig')) if r['file'].startswith('source/game/')]
known={int(r['rva'],16) for r in csv.DictReader((ROOT/'docs/hooks.csv').open(encoding='utf-8-sig')) if r['runtime_checked']=='1' and r['source_matches_evidence']=='1'}
groups={}
for r in refs:groups.setdefault(int(r['rva'],16),[]).append(r)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True;X=capstone.x86;items=[]
def member(o):return o.type==X.X86_OP_MEM and o.mem.base==X.X86_REG_ECX and o.mem.index==0 and o.mem.segment==0 and 0<=o.mem.disp<=4092 and o.size in(1,4)
for rva,rows in sorted(groups.items()):
 if rva in known:continue
 s=next((s for s in sections if s[0]<=rva<s[0]+s[1] and s[3]&0x20000000),None)
 if not s:continue
 pos=s[2]+rva-s[0];ins=[]
 for i in md.disasm(d[pos:pos+64],rva+0x400000):
  if i.group(capstone.CS_GRP_CALL) or i.group(capstone.CS_GRP_JUMP):break
  ins.append(i)
  if i.group(capstone.CS_GRP_RET):break
 if not ins or ins[-1].mnemonic!='ret':continue
 cleanup=ins[-1].operands[0].imm if ins[-1].operands else 0
 if cleanup not in (0,4,8,12,16,20):continue
 body=ins[:-1];operation=None;off=0;width=0;value=0;ops=[]
 # EAX clearing is optional for a byte boolean return.
 if body and body[0].mnemonic=='xor' and body[0].op_str=='eax, eax':body=body[1:]
 if len(body)==2 and body[0].mnemonic=='cmp' and body[1].mnemonic in ('sete','setne','setg','setge','setl','setle','seta','setae','setb','setbe') and body[1].op_str=='al':
  a,b=body[0].operands
  if member(a) and (b.type==X.X86_OP_IMM or (b.type==X.X86_OP_REG and b.reg in (X.X86_REG_EAX,X.X86_REG_AL) and ins[0].mnemonic=='xor')):
   operation=body[1].mnemonic;off=a.mem.disp;width=a.size;value=b.imm if b.type==X.X86_OP_IMM else 0
 # Single object read followed by bounded unsigned arithmetic; no memory writes.
 if len(body)>=2 and body[0].mnemonic in ('mov','movzx'):
  a,b=body[0].operands
  if a.type==X.X86_OP_REG and a.reg in (X.X86_REG_EAX,X.X86_REG_AL) and member(b) and (a.reg!=X.X86_REG_AL or b.size==1):
   good=True
   for i in body[1:]:
    a=i.operands[0] if i.operands else None
    if i.mnemonic not in ('shr','and','or','xor','not') or not a or a.type!=X.X86_OP_REG or a.reg!=body[0].operands[0].reg:good=False;break
    if i.mnemonic!='not' and (len(i.operands)!=2 or i.operands[1].type!=X.X86_OP_IMM):good=False;break
    ops.append((i.mnemonic,0 if i.mnemonic=='not' else i.operands[1].imm))
   if good and len(ops)<=8:operation='bits';off=b.mem.disp;width=b.size;value=1 if body[0].operands[0].reg==X.X86_REG_AL else 4
 if not operation:continue
 length=sum(i.size for i in ins);raw=d[pos:pos+length]
 items.append(dict(va=f'0x{rva+0x400000:08x}',rva=f'0x{rva:08x}',operation=operation,value=value,offset=off,width=width,cleanup=cleanup,arithmetic=ops,entry_bytes=raw.hex(' '),body_size=length,abi='x86_thiscall_isolated_member_fixture',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=sha,proof='complete linear instruction stream through RET; no branch/call/global/indirection',disassembly=[i.mnemonic+' '+i.op_str for i in ins]))
(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n',encoding='utf-8')
lines=['#pragma once','#include <cstring>','#include "GameComplexScalarProbe.h"','namespace gamecomplex {','enum class Op { sete,setne,setg,setge,setl,setle,seta,setae,setb,setbe,bits };','enum class Arithmetic { none,shr,and_,or_,xor_,not_ };','struct Step { Arithmetic op; unsigned value; };','struct Entry { reiv::original::FunctionAddress binding;Op operation;unsigned offset,width,cleanup,value,stepCount;Step steps[8]; };']
for i,x in enumerate(items):lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join('0x'+b for b in x['entry_bytes'].split())+'};')
lines.append('inline const Entry entries[]={')
for i,x in enumerate(items):
 steps=','.join('{Arithmetic::'+(op+'_' if op in ('and','or','xor','not') else op)+',0x'+format(value&0xffffffff,'08x')+'u}' for op,value in x['arithmetic'])
 lines.append('{{"Game complex '+x['va']+'",'+x['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},Op::'+x['operation']+','+','.join(str(x[k])+'u' if k!='value' else '0x'+format(x[k]&0xffffffff,'08x')+'u' for k in ('offset','width','cleanup','value'))+','+str(len(x['arithmetic']))+',{'+steps+'}},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline bool enabled=false,done=false;','inline unsigned calls[count]{},failures[count]{},exceptions=0;']
lines.append(r'''
template<class R> inline R Invoke(uintptr_t address,void* object,unsigned cleanup) {
 switch(cleanup){
 case 0:return reinterpret_cast<R(__thiscall*)(void*)>(address)(object);
 case 4:return reinterpret_cast<R(__thiscall*)(void*,unsigned)>(address)(object,0);
 case 8:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned)>(address)(object,0,0);
 case 12:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned)>(address)(object,0,0,0);
 case 16:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned)>(address)(object,0,0,0,0);
 default:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned)>(address)(object,0,0,0,0,0);
 }
}
inline int Check(unsigned index,unsigned sample) {
 __try {
  const auto& e=entries[index];auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));
  const unsigned patterns[]={0,1,0xffffffffu,0x80000000u,0x7fffffffu,e.value,e.value-1,e.value+1};
  unsigned input=sample<8?patterns[sample]:sample*0x10204081u;memcpy(object+e.offset,&input,e.width);memcpy(expected,object,sizeof(object));
  unsigned mask=e.width==1?255u:0xffffffffu;input&=mask;unsigned rhs=e.value&mask;bool truth=false;
  int signedInput=e.width==1?static_cast<signed char>(input):static_cast<int>(input);int signedRhs=e.width==1?static_cast<signed char>(rhs):static_cast<int>(rhs);
  switch(e.operation){
   case Op::sete:truth=input==rhs;break;case Op::setne:truth=input!=rhs;break;case Op::setg:truth=signedInput>signedRhs;break;case Op::setge:truth=signedInput>=signedRhs;break;
   case Op::setl:truth=signedInput<signedRhs;break;case Op::setle:truth=signedInput<=signedRhs;break;case Op::seta:truth=input>rhs;break;case Op::setae:truth=input>=rhs;break;case Op::setb:truth=input<rhs;break;case Op::setbe:truth=input<=rhs;break;
   case Op::bits:break;
  }
  if(e.operation==Op::bits){unsigned want=input;unsigned registerMask=e.value==1?255u:0xffffffffu;for(unsigned j=0;j<e.stepCount;++j){const auto& s=e.steps[j];switch(s.op){case Arithmetic::shr:want>>=(s.value&31);break;case Arithmetic::and_:want&=s.value;break;case Arithmetic::or_:want|=s.value;break;case Arithmetic::xor_:want^=s.value;break;case Arithmetic::not_:want=~want;break;default:break;}want&=registerMask;}
   unsigned got=e.value==1?Invoke<unsigned char>(address,object,e.cleanup):Invoke<unsigned>(address,object,e.cleanup);if(got!=want)return 2;
  }else if(Invoke<unsigned char>(address,object,e.cleanup)!=(truth?1:0))return 2;
  return memcmp(object,expected,sizeof(object))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}
inline void Report(const char* phase){FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-game-complex.json").c_str(),"wb")||!f)return;fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}
inline void Tick(){gamecomplexscalar::Tick();if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Game complex RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}
inline void Initialize(){gamecomplexscalar::Initialize();enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}
''')
(ROOT/'source/hooks/GameComplexProbe.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
print(json.dumps(dict(candidates=len(items),references=sum(i['reference_count'] for i in items))))
