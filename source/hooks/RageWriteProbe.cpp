#include "RageWriteProbe.h"

namespace ragewrites {
int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i];auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  unsigned value=0x87654321u^(sample*0x01020408u);memcpy(expected+e.offset,&value,e.width);
  using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,value);
  return memcmp(object,expected,sizeof(object))?2:0;
 } __except(EXCEPTION_EXECUTE_HANDLER){return 3;}
}

void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-rage-writes.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}

void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==3)++exceptions;break;}}REIV_INFO("Rage write RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.rage-writes-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

} // namespace ragewrites
