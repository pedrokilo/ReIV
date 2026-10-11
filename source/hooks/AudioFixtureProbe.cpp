#include "AudioFixtureProbe.h"

namespace audiofixtures {
int Check(unsigned i) {
 __try {
  const auto& e=entries[i]; auto address=reiv::original::ResolveAddress(e.binding); if(!address)return 1;
  alignas(16) unsigned char object[4096], expected[4096]; memset(object,0xa5,sizeof(object));
  unsigned a=0x12345678,b=0x87654321; float value=3.25f;
  memcpy(object+e.offset,&a,4); if(e.operation==Operation::get_float)memcpy(object+e.offset,&value,4);
  if(e.operation==Operation::get_u8)object[e.offset]=0x71;
  memcpy(expected,object,sizeof(object));
  switch(e.operation) {
   case Operation::address_offset: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object+e.offset)return 2;break;}
   case Operation::identity_this: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object)return 2;break;}
   case Operation::get_u32: {using F=unsigned(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=a)return 2;break;}
   case Operation::get_u8: {using F=unsigned char(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=0x71)return 2;break;}
   case Operation::get_float: {using F=float(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=value)return 2;break;}
   case Operation::compare_u32: {using F=bool(__thiscall*)(void*,unsigned);auto fn=reinterpret_cast<F>(address);if(!fn(object,a)||fn(object,b))return 2;break;}
   case Operation::set_u32: {using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,b);memcpy(expected+e.offset,&b,4);break;}
   case Operation::set_pair: {using F=void(__thiscall*)(void*,unsigned,unsigned);reinterpret_cast<F>(address)(object,a,b);memcpy(expected+e.offset,&a,4);memcpy(expected+e.offset+4,&b,4);break;}
   case Operation::get_pair: {unsigned out[4]={0x11111111,0,0,0x22222222};memcpy(object+e.offset+4,&b,4);memcpy(expected,object,sizeof(object));using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=a||out[2]!=b||out[3]!=0x22222222)return 2;break;}
   case Operation::outputs_minus_one: {unsigned out[4]={0x11111111,0,0,0x22222222};using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=0xffffffff||out[2]!=0xffffffff||out[3]!=0x22222222)return 2;break;}
  }
  return memcmp(object,expected,sizeof(object))?3:0;
 } __except(EXCEPTION_EXECUTE_HANDLER) { return 4; }
}

void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-audio-fixtures.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}

void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i);calls[i]+=entries[i].operation==Operation::compare_u32?2:1;if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Audio fixture RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.audio-fixtures-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

} // namespace audiofixtures
