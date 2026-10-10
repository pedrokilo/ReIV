"""Entire bounded ART bodies and both branches on isolated storage only."""
import csv,hashlib,json,struct
from pathlib import Path
import capstone
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;EV=HERE/'evidence';EV.mkdir(parents=True,exist_ok=True)
D=Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes();SHA=hashlib.sha256(D).hexdigest();assert SHA=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',D,60)[0];o=p+24;sections=[]
for i in range(struct.unpack_from('<H',D,p+6)[0]):
 q=o+struct.unpack_from('<H',D,p+20)[0]+i*40;va,size,ptr=struct.unpack_from('<III',D,q+12);sections.append((va,size,ptr,struct.unpack_from('<I',D,q+36)[0]))
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig',newline='')) if r['file'].startswith('source/external/ART/')]
spec=[(va,'guarded_float_store',off) for va,off in [(0x5e35c0,380),(0x5e35f0,388),(0x5e3620,392),(0x5e3650,396),(0x5ee8c0,296),(0x5ee8f0,300),(0x5ee920,304),(0x5ee950,308)]]+[(0x5e41c0,'guarded_copy3',0),(0x5e4460,'guarded_zero3',0),(0x5eee40,'reset_and_guarded_copy',0),(0x5ef060,'guarded_zero1',0),(0x5fdcf0,'select_this',0),(0x5fdd60,'nested_read',0),(0x686cd0,'zero_output9',0)]
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);items=[];lines=['#pragma once','#include <cstring>','namespace artcomplex {','enum Operation { '+','.join(sorted(set(x[1] for x in spec)))+' };','struct Entry { reiv::original::FunctionAddress binding; Operation op; unsigned offset; };']
for i,(va,op,off) in enumerate(spec):
 rva=va-0x400000;sec=next(x for x in sections if x[0]<=rva<x[0]+x[1] and x[3]&0x20000000);pos=sec[2]+rva-sec[0];ins=[]
 for x in cs.disasm(D[pos:pos+128],va):
  ins.append(x)
  if x.mnemonic=='ret':break
 assert ins[-1].mnemonic=='ret';raw=b''.join(x.bytes for x in ins);bound={x.address for x in ins}
 for x in ins:
  assert x.mnemonic!='call'
  if x.mnemonic.startswith('j'):assert int(x.op_str,16) in bound
 rows=[r for r in refs if int(r['rva'],16)==rva];assert rows
 items.append(dict(va=f'0x{va:08x}',rva=f'0x{rva:08x}',operation=op,value=off,entry_bytes=raw.hex(' '),body_size=len(raw),instructions=[f'{x.address:08x}: {x.mnemonic} {x.op_str}' for x in ins],abi='synthetic_x86_thiscall',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),exe_sha256=SHA,runtime_tested=False,enabled=False,reconstructed=False,scope='entire body; both branch outcomes where present; full 4096-byte object and nested buffer plus 96-byte output guards; no original class ABI assertion'))
 lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join(f'0x{x:02x}' for x in raw)+'};')
lines.append('inline const Entry entries[]={')
for i,x in enumerate(items):lines.append('{{"ART complex '+x['va']+'",'+x['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},'+x['operation']+','+str(x['value'])+'},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline unsigned calls[count]{},failures[count]{},exceptions=0;','inline bool enabled=false,done=false;']
lines.append(r'''
inline int Check(unsigned i,unsigned sample){
 __try {
  const auto& e=entries[i];const auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096],nested[4096],nestedExpected[4096],output[96],outputExpected[96];
  memset(object,(sample*17+0xa5)&255,sizeof(object));memset(nested,0x5a,sizeof(nested));memset(output,0xa5,sizeof(output));
  object[232]=static_cast<unsigned char>(((sample*17)&~4u)|((sample&1)?4:0));object[10]=static_cast<unsigned char>(((sample*13)&~8u)|((sample&1)?8:0));
  unsigned ptr=reinterpret_cast<unsigned>(nested);memcpy(object+80,&ptr,4);unsigned value=0x12345678u^(sample*0x01020408u);memcpy(nested+844,&value,4);
  for(unsigned n=0;n<3;++n){float f=3.25f+sample+n;memcpy(object+332+n*4,&f,4);}float f=2.5f+sample;memcpy(object+280,&f,4);
  memcpy(expected,object,sizeof(object));memcpy(nestedExpected,nested,sizeof(nested));memcpy(outputExpected,output,sizeof(output));
  using Void=void(__thiscall*)(void*);using One=void(__thiscall*)(void*,unsigned);using Select=void*(__thiscall*)(void*,unsigned);using Read=unsigned(__thiscall*)(void*);using Out=void(__thiscall*)(void*,void*,unsigned,unsigned,unsigned,unsigned,unsigned);
  switch(e.op){
   case guarded_float_store:{float v=4.75f+sample;unsigned bits=0;memcpy(&bits,&v,4);if(!(object[232]&4))memcpy(expected+e.offset,&bits,4);reinterpret_cast<One>(address)(object,bits);break;}
   case guarded_copy3:if(!(object[232]&4))memcpy(expected+356,object+332,12);reinterpret_cast<Void>(address)(object);break;
   case guarded_zero3:if(!(object[232]&4))memset(expected+356,0,12);reinterpret_cast<Void>(address)(object);break;
   case reset_and_guarded_copy:memset(expected+308,0,4);if(!(object[232]&4))memcpy(expected+288,object+280,4);reinterpret_cast<Void>(address)(object);break;
   case guarded_zero1:if(!(object[232]&4))memset(expected+288,0,4);reinterpret_cast<Void>(address)(object);break;
   case select_this:if(reinterpret_cast<Select>(address)(object,0)!=(object[10]&8?nullptr:object))return 2;break;
   case nested_read:if(reinterpret_cast<Read>(address)(object)!=value)return 2;break;
   case zero_output9:for(unsigned n=0;n<3;++n)memset(outputExpected+16+n*16,0,12);reinterpret_cast<Out>(address)(object,output+16,0,0,0,0,0);break;
  }
  return memcmp(object,expected,sizeof(object))||memcmp(nested,nestedExpected,sizeof(nested))||memcmp(output,outputExpected,sizeof(output))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}
inline void Report(const char* phase){FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-art-complex.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"both_branch_outcomes\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.art-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
inline void Tick(){if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("ART complex RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}
}
''')
(ROOT/'source/hooks/ARTComplexProbe.h').write_text('\n'.join(lines)+'\n',encoding='utf-8');(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n',encoding='utf-8')
print(json.dumps(dict(candidates=len(items),refs=sum(x['reference_count'] for x in items))))
