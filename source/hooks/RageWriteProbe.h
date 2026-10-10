#pragma once
#include <cstring>
namespace ragewrites {
struct Entry { reiv::original::FunctionAddress binding; unsigned offset,width; };
inline constexpr unsigned char bytes0[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes1[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x84,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x70,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes5[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes6[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x07,0xc2,0x04,0x00};
inline const Entry entries[]={
{{"Rage write 0x00554660",0x00154660,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},32,1},
{{"Rage write 0x00554710",0x00154710,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},32,4},
{{"Rage write 0x0055de60",0x0015de60,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},388,4},
{{"Rage write 0x0056a9e0",0x0016a9e0,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},368,4},
{{"Rage write 0x0059b9c0",0x0019b9c0,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},8,4},
{{"Rage write 0x005aa230",0x001aa230,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},4,4},
{{"Rage write 0x006848f0",0x002848f0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},7,1},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

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

