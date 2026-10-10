#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <xmmintrin.h>
#include "game/Peds/CPlayerPed.h"
#include "model-reset-fixture.h"
using M=reiv::game::PlayerPedModelReset;using D=reiv::game::PlayerPedModelResetDependencies;
static std::array<unsigned char,4096> player,a,b;
static unsigned sourceGlobal,destinationGlobal,scenario,vtable[69];
static std::vector<unsigned> trace;
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static unsigned R(const void*p,unsigned off){unsigned x;std::memcpy(&x,static_cast<const unsigned char*>(p)+off,4);return x;}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned Member(unsigned mode){return mode==0?0:mode==1?U(a.data()):mode==2?U(b.data()):0xFFFFFFA0u;}
static void Log(unsigned f,void*p,unsigned x=0,unsigned y=0,unsigned z=0){trace.insert(trace.end(),{f,U(p),x,y,z,R(player.data(),0x24),R(player.data(),0xA80),R(player.data(),0x228),sourceGlobal,destinationGlobal});}
static void First(void*p,unsigned x){Log(0x8A92C0,p,x);sourceGlobal^=0xFFFFFFFF;W(p,0x24,0x12340000);}
static void Second(void*p,unsigned x){Log(0x8A07E0,p,x);W(p,0x26C,0x87654321);}
static void Third(void*p,unsigned x,unsigned y){Log(0x8A70C0,p,x,y);}
static void Fourth(void*p,unsigned x){Log(0x89C8B0,p,x);W(p,0x228,Member((scenario>>2)&3));}
static void Virtual(void*p){Log(68,p);W(p,0x24,0x43210000);W(p,0x228,Member((scenario>>4)&3));}
static void Extra(void*p,unsigned x,unsigned y,unsigned z){Log(0x9BF0D0,p,x,y,z);W(p,0x228,Member((scenario>>6)&3));}
static void Final(void*p){Log(0x8793F0,p);W(p,0x18,0xFEDCBA98);}
static void __fastcall NFirst(void*p,void*,unsigned x){First(p,x);}static void __fastcall NSecond(void*p,void*,unsigned x){Second(p,x);}
static void __fastcall NThird(void*p,void*,unsigned x,unsigned y){Third(p,x,y);}static void __fastcall NFourth(void*p,void*,unsigned x){Fourth(p,x);}
static void __fastcall NVirtual(void*p,void*){Virtual(p);}static void __fastcall NExtra(void*p,void*,unsigned x,unsigned y,unsigned z){Extra(p,x,y,z);}static void __fastcall NFinal(void*p,void*){Final(p);}
static void* Target(unsigned f){switch(f){case 0x8A92C0:return reinterpret_cast<void*>(&NFirst);case 0x8A07E0:return reinterpret_cast<void*>(&NSecond);case 0x8A70C0:return reinterpret_cast<void*>(&NThird);case 0x89C8B0:return reinterpret_cast<void*>(&NFourth);case 0x9BF0D0:return reinterpret_cast<void*>(&NExtra);case 0x8793F0:return reinterpret_cast<void*>(&NFinal);default:return nullptr;}}
static void Initialize(unsigned bits){for(unsigned i=0;i<4096;++i){player[i]=static_cast<unsigned char>(i*31+scenario);a[i]=static_cast<unsigned char>(i*17+scenario);b[i]=static_cast<unsigned char>(i*19+scenario);}W(player.data(),0,U(vtable));W(player.data(),0x228,Member(scenario&3));sourceGlobal=bits;destinationGlobal=0xDEADBEEF;trace.clear();}
int main(){
 vtable[68]=U(reinterpret_cast<void*>(&NVirtual));auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;std::memcpy(code,ModelResetBytes,sizeof ModelResetBytes);
 for(auto p:ModelResetPatches){unsigned delta=U(Target(p.target))-U(code+p.offset+4);std::memcpy(code+p.offset,&delta,4);}unsigned src=U(&sourceGlobal),dst=U(&destinationGlobal);std::memcpy(code+4,&src,4);std::memcpy(code+15,&dst,4);
 auto file=std::fopen("build/player-model-reset-patched.bin","wb");std::fwrite(code,1,sizeof ModelResetBytes,file);std::fclose(file);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 D deps{&sourceGlobal,&destinationGlobal,First,Second,Third,Fourth,Virtual,Extra,Final};using Native=void(__thiscall*)(void*,unsigned);
 const unsigned patterns[]={0,0x80000000,0x3F800000,0x7FC00001,0x7F800001,1,0xFFFFFFFF};unsigned count=0;
 for(scenario=0;scenario<256;++scenario)for(unsigned argument:{0u,1u,255u,0x12340000u,0xFFFFFF00u,0xFFFFFF01u})for(unsigned bits:patterns){
  Initialize(bits);_mm_setcsr(0x1F80);__asm{fninit}reinterpret_cast<Native>(code)(player.data(),argument);auto obj=player,aa=a,bb=b;auto log=trace;unsigned expectedSource=sourceGlobal,expectedDestination=destinationGlobal,mxcsr=_mm_getcsr();unsigned short status;__asm{fnstsw status}
  Initialize(bits);_mm_setcsr(0x1F80);__asm{fninit}M::Reset(player.data(),static_cast<std::uint8_t>(argument),deps);unsigned short actualStatus;__asm{fnstsw actualStatus}
  if(obj!=player||aa!=a||bb!=b||log!=trace||expectedSource!=sourceGlobal||expectedDestination!=destinationGlobal||mxcsr!=_mm_getcsr()||status!=actualStatus){std::printf("FAIL scenario=%u argument=%08X bits=%08X\n",scenario,argument,bits);return 2;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}VirtualFree(code,0,MEM_RELEASE);std::printf("PASS comparisons=%u failures=0 globals_trace_buffers_fp_state_matched=1\n",count);return 0;
}
