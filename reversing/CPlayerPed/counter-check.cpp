#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include "game/Peds/PlayerPedCounter.h"
using C = reiv::game::PlayerPedCounter;
static std::uint8_t related[0x2700], receiver[0x400], threshold;
static bool q1,q2,q3,resolveOk,stateOk;
static std::uint32_t stateValue, delta;
static void* current;
static std::vector<std::uint32_t> trace;
static std::uint8_t Query(void* p,std::uint32_t id,std::uint32_t arg) {
 trace.push_back(id); trace.push_back(reinterpret_cast<std::uintptr_t>(p)); trace.push_back(arg);
 return id==0x410?q1:id==0x41E?q2:q3;
}
static void* Resolve(void* p) { trace.push_back(0x9BE5D0); trace.push_back(p==current); return resolveOk?related:nullptr; }
static std::uint8_t State(void* p,std::uint32_t* v,std::uint8_t* f) {
 trace.push_back(0x9C2720); trace.push_back(reinterpret_cast<std::uintptr_t>(p));
 trace.push_back(*v); trace.push_back(*f); *v=stateValue; *f=0xD3; return stateOk;
}
static std::uint32_t Ticks() { trace.push_back(0x448330); return delta; }
static void Before(void* p) { trace.push_back(0x8A3990); trace.push_back(p==current); }
static std::uint8_t __fastcall QueryNative(void* p,void*,std::uint32_t a,std::uint32_t b) { return Query(p,a,b); }
static void* __fastcall ResolveNative(void* p,void*) { return Resolve(p); }
static std::uint8_t __fastcall StateNative(void* p,void*,std::uint32_t* a,std::uint8_t* b) { return State(p,a,b); }
static void __fastcall BeforeNative(void* p,void*) { Before(p); }
static void PatchCall(std::uint8_t* body,unsigned offset,void* target) {
 auto relative=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(target)-reinterpret_cast<std::uintptr_t>(body+offset+5));
 std::memcpy(body+offset+1,&relative,4);
}
int main() {
 const std::uint8_t original[] = {
#include "counter-body.inc"
 };
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
 if(!code) return 1;
 std::memcpy(code,original,sizeof(original));
 for(auto offset:{0x29u,0x3Bu,0xB5u}) PatchCall(code,offset,reinterpret_cast<void*>(QueryNative));
 PatchCall(code,0x4A,reinterpret_cast<void*>(ResolveNative)); PatchCall(code,0x7E,reinterpret_cast<void*>(StateNative));
 for(auto offset:{0xBEu,0xDEu}) PatchCall(code,offset,reinterpret_cast<void*>(Ticks));
 auto thresholdAddress=reinterpret_cast<std::uintptr_t>(&threshold); std::memcpy(code+0x11E,&thresholdAddress,4);
 // Exact slot73 wrapper: PUSH ESI/MOV ESI,ECX/CALL/MOV ECX,ESI/POP ESI/JMP.
 const std::uint8_t wrapper[]={0x56,0x8B,0xF1,0xE8,0,0,0,0,0x8B,0xCE,0x5E,0xE9,0,0,0,0};
 std::memcpy(code+512,wrapper,sizeof(wrapper)); PatchCall(code+512,3,reinterpret_cast<void*>(BeforeNative)); PatchCall(code+512,11,code);
 DWORD old; if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old)) return 2;
 FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Native=void(__thiscall*)(void*);
 reiv::game::PlayerPedCounterDependencies d{Query,Resolve,State,Ticks,Before,&threshold};
 const std::uint32_t counters[]={0,1,9999,10000,10001,0x7FFFFFFF,0x80000000,0xFFFFFFFF,0x80000001};
 const std::uint32_t deltas[]={0,1,300,10000,0x7FFFFFFF,0x80000000,0xFFFFFFFF};
 const std::uint32_t states[]={0,5,8,0xFFFFFFFF};
 unsigned count=0;
 for(unsigned flags=0;flags<128;++flags) for(auto counter:counters) for(auto dt:deltas) for(auto state:states) for(unsigned difference: {0u,100u,101u,149u,150u,200u,201u,255u}) {
  std::array<std::uint8_t,4096> a,b;
  for(unsigned i=0;i<a.size();++i)a[i]=static_cast<std::uint8_t>(i*37+flags*19);
  a[0x219]=(flags&1)?1:0; q1=flags&2;q2=flags&4;resolveOk=flags&8;stateOk=flags&16;q3=flags&32;
  delta=dt; stateValue=state; threshold=(flags&64)?201:100;
  related[0x26DC]=static_cast<std::uint8_t>(counter);related[0x26DE]=static_cast<std::uint8_t>(counter^difference);
  auto pointer=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(receiver));
  std::memcpy(a.data()+0x224,&pointer,4);std::memcpy(a.data()+0xEB0,&counter,4);b=a;
  trace.clear();current=a.data();reinterpret_cast<Native>(code+512)(a.data());auto nativeTrace=trace;
  trace.clear();current=b.data();C::UpdateSlot73(b.data(),d);
  if(a!=b || trace!=nativeTrace) {std::printf("failed flags=%u counter=%08x dt=%08x state=%u\n",flags,counter,dt,state);return 3;}
  ++count;
 }
 VirtualFree(code,0,MEM_RELEASE);std::printf("passed %u complete-body comparisons with callback traces\n",count);return 0;
}
