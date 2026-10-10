#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <xmmintrin.h>
#include "game/Peds/CPlayerPed.h"
#include "value-fixture.h"
namespace V=reiv::game::player_adjustment;
static std::array<unsigned char,4096> player,a,b;static unsigned scenario,pattern,lookups;
static std::vector<unsigned> trace;
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned R(void*p,unsigned off){unsigned x;std::memcpy(&x,static_cast<unsigned char*>(p)+off,4);return x;}
static unsigned __cdecl Predicate(){trace.push_back(0x462F90);return scenario&1;}
static void* __fastcall Lookup(void*p,void*){trace.insert(trace.end(),{0x4389D0,U(p),lookups});auto current=R(player.data(),0x228);if(scenario&16)W(player.data(),0x228,(++lookups&1)?U(b.data()):U(a.data()));return reinterpret_cast<void*>(current+0x60);}
static float __cdecl Cap(unsigned id){trace.insert(trace.end(),{0x962B20,id});if(scenario&32)W(player.data(),0x228,U(b.data()));float value;unsigned bits=0x42C80000;std::memcpy(&value,&bits,4);return value;}
static void Initialize(unsigned bits){for(unsigned i=0;i<4096;++i){player[i]=static_cast<unsigned char>(i*31+scenario);a[i]=static_cast<unsigned char>(i*17+scenario);b[i]=static_cast<unsigned char>(i*19+scenario);}W(player.data(),0x228,U(a.data()));a[0x546]=static_cast<unsigned char>(scenario&2);W(a.data(),0x430,(scenario&4)?2:0);W(a.data(),0x414,bits);W(b.data(),0x414,bits^0x80000000);lookups=0;trace.clear();
 V::g011DDE7C=(scenario&64)?0x7FC00001:0x3DCCCCCD;V::g00DCEA38=0x42480000;V::g00DECD60=0x3F800000;V::g01618104=(scenario&8)?1:0;V::g00D819B4=0x3EAAAAAB;V::g00D5A154=0x3F000000;
}

#include "templates.h"
static unsigned CloneResolve(reiv::player_clone::Kind kind,unsigned va){
 if(kind==reiv::player_clone::Kind::Call){for(auto b:ValueCallBindings)if(b.original==va)return U(*b.target);}
 for(auto g:ValueGlobalBindings)if(g.original==va)return U(g.storage);return 0;
}
int main(){
 V::call00462F90=reinterpret_cast<void*>(&Predicate);V::call004389D0=reinterpret_cast<void*>(&Lookup);V::call00962B20=reinterpret_cast<void*>(&Cap);
 reiv::player_clone::CoffClone clones[2];
 for(auto& clone:clones)clone.Create(reiv::player_clone::AdjustBody,CloneResolve);
 const auto binding0=clones[0].BindingSnapshot(),binding1=clones[1].BindingSnapshot();
 if(clones[0].Entry()==clones[1].Entry()||!clones[0].Immutable()||!clones[1].Immutable())return 90;
 auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;std::memcpy(code,ValueBytes,sizeof ValueBytes);
 for(auto x:ValueCallPatches){void*target=nullptr;for(auto b:ValueCallBindings)if(b.original==x.target)target=*b.target;unsigned d=U(target)-U(code+x.offset+4);std::memcpy(code+x.offset,&d,4);}
 for(auto x:ValueGlobalPatches){unsigned g=0;for(auto b:ValueGlobalBindings)if(b.original==x.original)g=U(b.storage);std::memcpy(code+x.offset,&g,4);}
 auto f=std::fopen("build/privateNativeBinding/clone-adjust-value-adjust-patched.bin","wb");std::fwrite(code,1,sizeof ValueBytes,f);std::fclose(f);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Original=unsigned char(__thiscall*)(void*,unsigned,float);const unsigned bits[]={0,0x80000000,0x3F800000,0xBF800000,0x42C80000,0x7FC00001,0x7F800001,1,0x7F800000,0xFF800000};unsigned count=0;
 for(unsigned round=0;round<4;++round)for(unsigned denorm=0;denorm<4;++denorm)for(unsigned precision:{0u,0x200u,0x300u})for(scenario=0;scenario<128;++scenario)for(unsigned flag:{0u,1u,0x12340000u,0xFFFFFFFFu})for(unsigned field:bits)for(unsigned input:bits){
  unsigned fp=0x1F80|(round<<13)|((denorm&1)?0x40:0)|((denorm&2)?0x8000:0);unsigned short cw=static_cast<unsigned short>(0x7F|precision|(round<<10));float value;std::memcpy(&value,&input,4);
  Initialize(field);_mm_setcsr(fp);__asm{fninit}__asm{fldcw cw}auto expected=reinterpret_cast<Original>(code)(player.data(),flag,value);auto pp=player,aa=a,bb=b;auto log=trace;unsigned mxcsr=_mm_getcsr();unsigned short sw;__asm{fnstsw sw}
  Initialize(field);_mm_setcsr(fp);__asm{fninit}__asm{fldcw cw}auto result=V::Adjust(player.data(),nullptr,flag,value);unsigned short actual;__asm{fnstsw actual}
  if(pp!=player||aa!=a||bb!=b||log!=trace||expected!=result||sw!=actual||mxcsr!=_mm_getcsr()){std::printf("FAIL scenario=%u flag=%08X field=%08X input=%08X result=%u/%u\n",scenario,flag,field,input,expected,result);return 2;}for(auto& clone:clones){Initialize(field);_mm_setcsr(fp);__asm{fninit}__asm{fldcw cw}auto cloneResult=reinterpret_cast<Original>(clone.Entry())(player.data(),flag,value);unsigned short cloneStatus;__asm{fnstsw cloneStatus}if(pp!=player||aa!=a||bb!=b||log!=trace||expected!=cloneResult||sw!=cloneStatus||mxcsr!=_mm_getcsr())return 91;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}VirtualFree(code,0,MEM_RELEASE);if(!clones[0].Immutable()||!clones[1].Immutable()||clones[0].BindingSnapshot()!=binding0||clones[1].BindingSnapshot()!=binding1)return 92;std::printf("CLONE PASS two_allocations original_source_and_clones_match immutable_bindings=1\n");std::printf("PASS comparisons=%u failures=0 return_AL_buffers_trace_x87_MXCSR_matched=1\n",count);return 0;
}
