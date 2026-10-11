#include "ARTExtraProbe.h"

namespace artextras {
int Check(unsigned i,unsigned sample) {
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

void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-art-extras.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}

void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("ART extra RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.art-extras-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

} // namespace artextras
