#include "DestructorModeProbe.h"

namespace destructormode {
int Check(unsigned i,unsigned sample) {
 __try{
  const auto& e=entries[i];unsigned char bytes[41];memcpy(bytes,e.bytes,41);
  unsigned adjusted=0;memcpy(&adjusted,bytes+10,4);
  const auto base=reinterpret_cast<unsigned>(GetModuleHandleW(nullptr));adjusted+=base-0x400000u;memcpy(bytes+10,&adjusted,4);
  reiv::original::FunctionAddress binding={"non-deleting destructor mode",e.rva,bytes,41,reiv::original::BindingState::StaticVerified};
  const auto address=reiv::original::ResolveAddress(binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  const unsigned vtable=base+e.vtable;memcpy(expected,&vtable,4);
  const unsigned flags=(sample*0x01020408u)&~1u;
  using F=void*(__thiscall*)(void*,unsigned);
  if(reinterpret_cast<F>(address)(object,flags)!=object)return 2;
  return memcmp(object,expected,sizeof(object))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}

void Report(const char* phase) {FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-destructor-mode.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"restricted_nonfreeing_mode_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);
}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.destructor-mode-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

void Tick() {if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int r=Check(i,n);++calls[i];if(r){++failures[i];++failed;if(r==4)++exceptions;break;}}REIV_INFO("Destructor restricted mode RVA0x%08X calls=%u failures=%u",entries[i].rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}

} // namespace destructormode
