#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include "game/Peds/CPlayerPed.h"
#include "game/Peds/CPlayerPed.h"
#include "range-fixture.h"
#include "request-fixture.h"
namespace A=reiv::game::player_action_range;namespace B=reiv::game::player_action_request;
static std::array<unsigned char,4096> player,related,target,transform,info,action,transform2;
static unsigned scenario,stackAnchor,flag,argument,fpConfig;static ULONG_PTR stackLow,stackHigh;
static std::vector<unsigned> trace;
static unsigned U(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned o,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+o,&x,4);}
static unsigned Norm(unsigned x){return x>=stackLow&&x<stackHigh?0xCCCC0000u+(x-stackAnchor):x;}
static unsigned __cdecl Record(unsigned f,void*p,unsigned*args,unsigned words){
 bool callerPops=f==0x924E80||f==0x462F90||f==0xC28820;
 trace.insert(trace.end(),{f,callerPops?0:Norm(U(p)),words});for(unsigned i=0;i<words;++i)trace.push_back(Norm(args[i]));
 switch(f){case 0x924E80:return U(info.data());case 0x462F90:return (scenario>>3)&1;
 case 0x9A9CF0:return (scenario&1)?U(action.data()):0;
 case 0x9C1300:if(scenario&0x1000)W(player.data(),0x228,0);else if(scenario&0x2000)W(player.data(),0x228,U(target.data()));return (scenario&2)?U(action.data()):0;
 case 0x9A9EF0:W(player.data(),0x2B0,args[0]);return 0;
 case 0xC28820:if(scenario&0x4000)W(player.data(),0x3A8,U(action.data()));return 0;default:return 0;}
}
#include "action-stubs.h"
static const unsigned patterns[]={0,0x80000000,0x3F800000,0x40000000,0xBF800000,0x7F800000,0xFF800000,0x7FC00001,0x7F800001,1};
static void Init(){for(auto*p:{&player,&related,&target,&transform,&info,&action,&transform2})p->fill(0);trace.clear();stackAnchor=0;
 W(player.data(),0x228,U(related.data()));W(player.data(),0xE7C,U(related.data()));W(player.data(),0x20,U(transform.data()));W(player.data(),0x3A8,(scenario&4)?U(target.data()):0);W(player.data(),0x2C8,0);W(action.data(),0x18,17);
 W(info.data(),0x14,patterns[fpConfig%10]);W(info.data(),0xC,(scenario>>4)&1);W(related.data(),0x5A8,patterns[(fpConfig+3)%10]);W(related.data(),0x264,(scenario&32)?0x800000:0);
 W(target.data(),0x28,(scenario&64)?0xC0:0);W(target.data(),0x270,(scenario&128)?16:0);W(target.data(),0x20,(scenario&256)?U(transform2.data()):0);
 for(unsigned o:{0x10u,0x14u})W(target.data(),o,patterns[(fpConfig+2)%10]);for(unsigned o:{0x30u,0x34u}){W(transform.data(),o,patterns[(fpConfig+4)%10]);W(transform2.data(),o,patterns[(fpConfig+6)%10]);}
 A::g010F8044=B::g010F8044=(scenario&512)?2:0;A::g010C7A08=(scenario&1024)?1:0;A::g00FC7EFF=(scenario&2048)?1:0;
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char>b;for(auto*p:{&player,&related,&target,&transform,&info,&action,&transform2})b.insert(b.end(),p->begin(),p->end());return b;}
static DWORD faultCode;static ULONG_PTR faultAddress;
static int Filter(EXCEPTION_POINTERS*p){faultCode=p->ExceptionRecord->ExceptionCode;faultAddress=p->ExceptionRecord->NumberParameters>1?p->ExceptionRecord->ExceptionInformation[1]:0;return EXCEPTION_EXECUTE_HANDLER;}
static unsigned Invoke(void*code,bool source,bool range){unsigned value=0;faultCode=0;faultAddress=0;
 __try {if(range){if(source)value=A::Act(player.data(),nullptr,flag);else value=reinterpret_cast<unsigned char(__thiscall*)(void*,unsigned)>(code)(player.data(),flag);}else{if(source)value=B::Act(player.data(),nullptr,flag,argument);else value=reinterpret_cast<unsigned char(__thiscall*)(void*,unsigned,unsigned)>(code)(player.data(),flag,argument);}}
 __except(Filter(GetExceptionInformation())) {}return value;}
template<class C,class G,class CB,class GB>static void* Patch(const unsigned char*bytes,unsigned n,const C*c,unsigned nc,const G*g,unsigned ng,const CB*cb,unsigned ncb,const GB*gb,unsigned ngb){
 auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(code,bytes,n);
 for(unsigned i=0;i<ncb;++i)*cb[i].target=Stub(cb[i].original);
 for(unsigned i=0;i<nc;++i){unsigned d=U(Stub(c[i].target))-U(code+c[i].offset+4);std::memcpy(code+c[i].offset,&d,4);}
 for(unsigned i=0;i<ng;++i){unsigned addr=0;for(unsigned j=0;j<ngb;++j)if(gb[j].original==g[i].original)addr=U(gb[j].storage);if(!addr)return nullptr;std::memcpy(code+g[i].offset,&addr,4);}
 auto file=std::fopen(n==483?"build/player-action-range-patched.bin":"build/player-action-request-patched.bin","wb");std::fwrite(code,1,n,file);std::fclose(file);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);return code;}
#define N(a) unsigned(sizeof(a)/sizeof((a)[0]))
int main(){GetCurrentThreadStackLimits(&stackLow,&stackHigh);
 auto range=Patch(RangeBytes,sizeof RangeBytes,RangeCallPatches,N(RangeCallPatches),RangeGlobalPatches,N(RangeGlobalPatches),RangeCallBindings,N(RangeCallBindings),RangeGlobalBindings,N(RangeGlobalBindings));
 auto request=Patch(RequestBytes,sizeof RequestBytes,RequestCallPatches,N(RequestCallPatches),RequestGlobalPatches,N(RequestGlobalPatches),RequestCallBindings,N(RequestCallBindings),RequestGlobalBindings,N(RequestGlobalBindings));if(!range||!request)return 1;
 unsigned count=0,faults=0;
 for(unsigned mode=0;mode<2;++mode)for(scenario=0;scenario<32768;scenario+=31)for(fpConfig=0;fpConfig<10;++fpConfig)for(flag=0;flag<2;++flag){argument=0x12345678;
  Init();_mm_setcsr(0x1F80);__asm{fninit}unsigned expected=Invoke(mode?request:range,false,!mode);auto state=Snapshot();auto log=trace;DWORD fc=faultCode;auto fa=faultAddress;unsigned fp=_mm_getcsr();unsigned short sw;__asm{fnstsw sw}
  Init();_mm_setcsr(0x1F80);__asm{fninit}unsigned actual=Invoke(mode?request:range,true,!mode);unsigned short asw;__asm{fnstsw asw}
  if(expected!=actual||state!=Snapshot()||log!=trace||fc!=faultCode||fa!=faultAddress||(!fc&&(fp!=_mm_getcsr()||sw!=asw))){std::printf("FAIL mode=%u scenario=%u fp=%u flag=%u trace=%d memory=%d faults=%08X/%08X address=%X/%X\n",mode,scenario,fpConfig,flag,log!=trace,state!=Snapshot(),fc,faultCode,unsigned(fa),unsigned(faultAddress));return 2;}if(fc){if(fc!=EXCEPTION_ACCESS_VIOLATION||fa!=0x415)return 3;++faults;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}std::printf("PASS comparisons=%u failures=0 explicit_matching_null_415_faults=%u\n",count,faults);return 0;}

