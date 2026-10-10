#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include "game/Peds/PlayerPedNonvirtual.h"
#include "nonvirtual-body.inc"
using C=reiv::game::PlayerPedNonvirtual;
static std::vector<std::uint32_t> trace;
static std::uint32_t resultBits;
static void* Resolve() {trace.push_back(0x7C3900);return reinterpret_cast<void*>(static_cast<std::uintptr_t>(resultBits));}
static void Call(void* p,std::uint32_t argument) {
 trace.push_back(0x9A9EF0);trace.push_back(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p)));trace.push_back(argument);
 std::memcpy(static_cast<std::uint8_t*>(p)+0x20,&resultBits,4);
}
static void __fastcall NCall(void* p,void*,std::uint32_t a) {Call(p,a);}
static void Patch(std::uint8_t* base,unsigned offset,void* destination) {
 const auto relative=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(destination)-reinterpret_cast<std::uintptr_t>(base+offset+5));
 std::memcpy(base+offset+1,&relative,4);
}
int main() {
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!code)return 1;
 std::memcpy(code,resolveCode,sizeof(resolveCode));std::memcpy(code+128,callCode,sizeof(callCode));
 Patch(code,18,reinterpret_cast<void*>(Resolve));Patch(code+128,26,reinterpret_cast<void*>(NCall));
 DWORD old;if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),code,4096);
 using NR=void*(__thiscall*)(void*);using NC=void(__thiscall*)(void*);
 reiv::game::PlayerPedNonvirtualDependencies d{Resolve,Call};std::array<std::uint8_t,4096> object;
 unsigned count=0;
 for(unsigned first:{0u,1u,128u,255u})for(unsigned second:{0u,1u,128u,255u})for(unsigned result:{0u,0x81234567u})for(unsigned sample=0;sample<256;++sample) {
  for(unsigned i=0;i<object.size();++i)object[i]=static_cast<std::uint8_t>(i*37+sample*19);
  object[0x218]=static_cast<std::uint8_t>(first);object[0x219]=static_cast<std::uint8_t>(second);const auto seeded=object;resultBits=result;
  trace.clear();auto native=reinterpret_cast<NR>(code)(object.data());const auto t=trace;
  trace.clear();auto rebuilt=C::ResolveIfPlayerFlags(object.data(),d);
  if(native!=rebuilt||trace!=t||object!=seeded)return 3;
  ++count;
  trace.clear();reinterpret_cast<NC>(code+128)(object.data());const auto nativeObject=object;const auto nt=trace;
  object=seeded;trace.clear();C::CallBlockIfPlayerFlags(object.data(),d);
  if(object!=nativeObject||trace!=nt)return 4;
  ++count;
 }
 VirtualFree(code,0,MEM_RELEASE);std::printf("passed %u nonvirtual original-body comparisons\n",count);return 0;
}
