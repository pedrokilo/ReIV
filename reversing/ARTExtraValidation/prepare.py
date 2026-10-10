"""Complete ART bit accessors/local writes; synthetic buffers, no class ABI claim."""
import csv, hashlib, json, pathlib, struct
ROOT=pathlib.Path(__file__).resolve().parents[2]
EV=pathlib.Path(__file__).resolve().parent/'evidence'; EV.mkdir(parents=True,exist_ok=True)
d=pathlib.Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes()
sha=hashlib.sha256(d).hexdigest(); assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',d,60)[0];o=pe+24;s=[]
for i in range(struct.unpack_from('<H',d,pe+6)[0]):
 q=o+struct.unpack_from('<H',d,pe+20)[0]+40*i; va,size,ptr=struct.unpack_from('<III',d,q+12);s.append((va,size,ptr,struct.unpack_from('<I',d,q+36)[0]))
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig',newline='')) if r['file'].startswith('source/external/ART/')]
spec=[(0x4ee420,'return_minus_one',0,0,'83c8ffc3'),(0x784520,'return_one_pop4',0,0,'b001c20400'),(0x5fdd00,'echo_u8_pop4',0,0,'8a442404c20400'),(0x5e39e0,'zero_u32',228,0,'c781e400000000000000c3'),(0x5e6340,'and_u8',232,231,'80a1e8000000e7c3'),(0x5efc70,'zero_pair',12,0,'33c089410c894110c3'),(0x686be0,'zero_output3',0,0,'8b4424040f57c0f30f114008f30f114004f30f1100c20400'),(0x5e35a0,'bit_u8',232,1,'8a81e8000000d0e82401c3')]
for va,off in [(0x5f1e70,636),(0x5f3ce0,324),(0x5f76a0,3068),(0x600200,168),(0x602440,152),(0x605870,180),(0x605fe0,144),(0x608760,140)]:
 spec.append((va,'bit_u8',off,0,'8a81'+off.to_bytes(4,'little').hex()+'2401c3'))
items=[];lines=['#pragma once','#include <cstring>','namespace artextras {','enum Operation { '+','.join(sorted(set(x[1] for x in spec)))+' };','struct Entry { reiv::original::FunctionAddress binding; Operation op; unsigned offset,arg; };']
for i,(va,op,offset,arg,body) in enumerate(spec):
 rva=va-0x400000;raw=bytes.fromhex(body);sec=next(x for x in s if x[0]<=rva<x[0]+x[1] and x[3]&0x20000000);pos=sec[2]+rva-sec[0];assert d[pos:pos+len(raw)]==raw
 rows=[r for r in refs if int(r['rva'],16)==rva];assert rows
 items.append(dict(va=f'0x{va:08x}',rva=f'0x{rva:08x}',operation=op,value=offset,argument=arg,entry_bytes=raw.hex(' '),body_size=len(raw),abi='x86_synthetic_fixture',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=sha))
 lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join(f'0x{x:02x}' for x in raw)+'};')
lines.append('inline const Entry entries[]={')
for i,x in enumerate(items):lines.append('{{"ART extra '+x['va']+'",'+x['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},'+x['operation']+','+str(x['value'])+','+str(x['argument'])+'},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline bool enabled=false,done=false;','inline unsigned calls[count]{},failures[count]{},exceptions=0;']
lines.append(r'''
inline int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i];auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096],output[32],outputExpected[32];
  memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  memset(output,0xa5,sizeof(output));memcpy(outputExpected,output,sizeof(output));
  unsigned value=0x87654321u^(sample*0x01020408u),result=0;
  using Noarg=unsigned(__cdecl*)();using Onearg=unsigned(__stdcall*)(unsigned);
  using Read=unsigned(__thiscall*)(void*);using Write=void(__thiscall*)(void*);using Out=void(__thiscall*)(void*,void*);
  switch(e.op) {
  case return_minus_one:result=reinterpret_cast<Noarg>(address)();if(result!=0xffffffffu)return 2;break;
  case return_one_pop4:result=reinterpret_cast<Onearg>(address)(value);if((result&255)!=1)return 2;break;
  case echo_u8_pop4:result=reinterpret_cast<Onearg>(address)(value);if((result&255)!=(value&255))return 2;break;
  case bit_u8:result=reinterpret_cast<Read>(address)(object);if((result&255)!=((object[e.offset]>>e.arg)&1))return 2;break;
  case zero_u32:memset(expected+e.offset,0,4);reinterpret_cast<Write>(address)(object);break;
  case and_u8:expected[e.offset]&=e.arg;reinterpret_cast<Write>(address)(object);break;
  case zero_pair:memset(expected+e.offset,0,8);reinterpret_cast<Write>(address)(object);break;
  case zero_output3:memset(outputExpected+8,0,12);reinterpret_cast<Out>(address)(object,output+8);break;
  }
  return memcmp(object,expected,sizeof(object))||memcmp(output,outputExpected,sizeof(output))?3:0;
 } __except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}
inline void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-art-extras.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}
inline void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("ART extra RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.art-extras-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}
''')
(ROOT/'source/hooks/ARTExtraProbe.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n',encoding='utf-8')
print(json.dumps(dict(candidates=len(items),references=sum(x['reference_count'] for x in items))))
