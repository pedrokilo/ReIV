import csv,json,pathlib,hashlib,struct
ROOT=pathlib.Path(__file__).resolve().parents[2]
EV=pathlib.Path(__file__).resolve().parent/'evidence';EV.mkdir(parents=True,exist_ok=True)
spec=[(0x554660,'set_u8',32,'8a442404884120c20400'),(0x554710,'set_u32',32,'8b442404894120c20400'),(0x55de60,'set_u32',388,'8b442404898184010000c20400'),(0x56a9e0,'set_u32',368,'8b442404898170010000c20400'),(0x59b9c0,'set_u32',8,'8b442404894108c20400'),(0x5aa230,'set_u32',4,'8b442404894104c20400'),(0x6848f0,'set_u8',7,'8a442404884107c20400')]
d=pathlib.Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe').read_bytes();sha=hashlib.sha256(d).hexdigest();assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',d,60)[0];opt=pe+24;s=[]
for i in range(struct.unpack_from('<H',d,pe+6)[0]):
 q=opt+struct.unpack_from('<H',d,pe+20)[0]+i*40;va,size,ptr=struct.unpack_from('<III',d,q+12);s.append((va,size,ptr,struct.unpack_from('<I',d,q+36)[0]))
refs=list(csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(newline='',encoding='utf-8-sig')))
items=[];lines=['#pragma once','#include <cstring>','namespace ragewrites {','struct Entry { reiv::original::FunctionAddress binding; unsigned offset,width; };']
for i,(va,op,off,hexbytes) in enumerate(spec):
 rva=va-0x400000;raw=bytes.fromhex(hexbytes);sec=next(x for x in s if x[0]<=rva<x[0]+x[1] and x[3]&0x20000000);pos=sec[2]+rva-sec[0];assert d[pos:pos+len(raw)]==raw
 rows=[r for r in refs if r['file'].startswith('source/rage/') and int(r['rva'],16)==rva];assert rows
 items.append(dict(va=f'0x{va:08x}',rva=f'0x{rva:08x}',operation=op,value=off,entry_bytes=raw.hex(' '),body_size=len(raw),abi='x86_thiscall_fixture',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=sha))
 lines.append(f'inline constexpr unsigned char bytes{i}[]={{'+','.join(f'0x{x:02x}' for x in raw)+'};')
lines.append('inline const Entry entries[]={')
for i,x in enumerate(items):lines.append('{{"Rage write '+x['va']+'",'+x['rva']+',bytes'+str(i)+',sizeof(bytes'+str(i)+'),reiv::original::BindingState::StaticVerified},'+str(x['value'])+','+str(1 if x['operation']=='set_u8' else 4)+'},')
lines+=['};','inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);','inline bool enabled=false,done=false;','inline unsigned calls[count]{},failures[count]{},exceptions=0;']
lines.append(r'''
inline int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i];auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  unsigned value=0x87654321u^(sample*0x01020408u);memcpy(expected+e.offset,&value,e.width);
  using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,value);
  return memcmp(object,expected,sizeof(object))?2:0;
 } __except(EXCEPTION_EXECUTE_HANDLER){return 3;}
}
inline void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-rage-writes.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}
inline void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==3)++exceptions;break;}}REIV_INFO("Rage write RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.rage-writes-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}
''')
(ROOT/'source/hooks/RageWriteProbe.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
(EV/'fixture-scope.json').write_text(json.dumps(items,indent=2)+'\n',encoding='utf-8')
print(len(items))
