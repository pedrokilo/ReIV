#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include "game/Peds/CPlayerPed.h"
using R=reiv::game::PlayerPedReferenceClear;
static std::array<unsigned char,4096> object;static std::vector<unsigned> trace;static unsigned sample;
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void Release(void*p,std::uint32_t*field){trace.insert(trace.end(),{U(p),U(field),*field});*field=sample^0x12345678;std::memcpy(object.data()+0xE78,&sample,4);}
static void __fastcall NativeRelease(void*p,void*,std::uint32_t*f){Release(p,f);}
int main(){
 const unsigned char body[]={0x56,0x8D,0xB1,0x74,0x0E,0,0,0x8B,0x0E,0x85,0xC9,0x74,0x0C,0x56,0xE8,0x9D,0x76,2,0,0xC7,6,0,0,0,0,0x5E,0xC3};
 auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;std::memcpy(code,body,sizeof body);unsigned relative=U(reinterpret_cast<void*>(&NativeRelease))-U(code+19);std::memcpy(code+15,&relative,4);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 auto patched=std::fopen("build/player-reference-clear-patched.bin","wb");std::fwrite(code,1,sizeof body,patched);std::fclose(patched);
 reiv::game::PlayerPedReferenceClearDependencies d{Release};using Fn=void(__thiscall*)(void*);
 for(sample=0;sample<512;++sample){
  auto Init=[](){for(unsigned i=0;i<4096;++i)object[i]=static_cast<unsigned char>(i*37+sample);unsigned value=(sample&1)?sample*0x1234567:0;std::memcpy(object.data()+0xE74,&value,4);trace.clear();};
  Init();reinterpret_cast<Fn>(code)(object.data());auto expected=object;auto log=trace;
  Init();R::ClearFieldE74(object.data(),d);if(object!=expected||trace!=log){std::printf("FAIL sample=%u\n",sample);return 2;}
 }
 VirtualFree(code,0,MEM_RELEASE);std::printf("PASS comparisons=512 failures=0 full_buffer_and_ordered_callback_matched=1\n");return 0;
}
