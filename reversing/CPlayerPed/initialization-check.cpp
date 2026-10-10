#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include "game/Peds/PlayerPedNonvirtual.h"
using C=reiv::game::PlayerPedNonvirtual;
static std::array<std::uint8_t,4096> player,first,second,third;
static std::vector<std::uint32_t> trace;
static unsigned mode,created;
static unsigned U(const void* p) {return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void Store(void* p,unsigned off,unsigned value) {std::memcpy(static_cast<std::uint8_t*>(p)+off,&value,4);}
static void Reset(void* p,unsigned a,unsigned b) {
 trace.insert(trace.end(),{0xA677D0,U(p),a,b});if(mode&1)Store(player.data(),0x228,U(second.data()));
}
static unsigned Create(void* p) {
 trace.insert(trace.end(),{0xA66F20,U(p)});if(mode&2)Store(p,0x228,U(third.data()));return created;
}
static void Link(void* p,void* q) {
 trace.insert(trace.end(),{0xA67AA0,U(p),U(q)});if(mode&4)Store(q,0x228,U(first.data()));
}
static void Start(void* p) {
 trace.insert(trace.end(),{0xA67D70,U(p)});if(mode&8)Store(player.data(),0x228,U(second.data()));
}
static void __fastcall NReset(void* p,void*,unsigned a,unsigned b) {Reset(p,a,b);}
static void __fastcall NLink(void* p,void*,void* q) {Link(p,q);}
static void __fastcall NStart(void* p,void*) {Start(p);}
static void Patch(std::uint8_t* base,unsigned off,void* target) {
 const auto relative=U(target)-U(base+off+5);std::memcpy(base+off+1,&relative,4);
}
static void Seed(unsigned handle,unsigned sample) {
 for(unsigned i=0;i<4096;++i) {player[i]=static_cast<std::uint8_t>(i*37+sample*19);first[i]=static_cast<std::uint8_t>(i*19+sample*17);second[i]=static_cast<std::uint8_t>(i*23+sample*31);third[i]=static_cast<std::uint8_t>(i*41+sample*29);}
 Store(player.data(),0x228,U(first.data()));Store(first.data(),0x434,handle);Store(second.data(),0x434,3);Store(third.data(),0x434,7);trace.clear();
}
int main() {
 const std::uint8_t body[]={
#include "initialization-body.inc"
 };
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;
 std::memcpy(code,body,sizeof(body));Patch(code,59,reinterpret_cast<void*>(NReset));Patch(code,83,reinterpret_cast<void*>(Create));Patch(code,131,reinterpret_cast<void*>(NLink));Patch(code,168,reinterpret_cast<void*>(NStart));
 unsigned table=0x60000000;for(unsigned off:{55u,164u})std::memcpy(code+off,&table,4);table+=8;std::memcpy(code+127,&table,4);
 DWORD old;if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Native=void(__thiscall*)(void*);reiv::game::PlayerPedInitializationDependencies d{0x60000000,Reset,Create,Link,Start};unsigned count=0;
 const unsigned values[]={0,1,3,7,0x7FFFFFFF,0x80000000,0xFFFFFFFF,0x12345678,0x89ABCDEF};
 for(mode=0;mode<16;++mode)for(unsigned handle:values)for(unsigned newValue:values)for(unsigned sample=0;sample<32;++sample) {
  created=newValue;Seed(handle,sample);reinterpret_cast<Native>(code)(player.data());auto p=player,a=first,b=second,c=third;auto calls=trace;
  Seed(handle,sample);C::InitializeRelations(player.data(),d);
  if(p!=player||a!=first||b!=second||c!=third||trace!=calls) {std::printf("failed mode=%u handle=%x new=%x sample=%u\n",mode,handle,newValue,sample);return 3;}
  ++count;
 }
 VirtualFree(code,0,MEM_RELEASE);std::printf("passed %u initialization original-body comparisons\n",count);return 0;
}
