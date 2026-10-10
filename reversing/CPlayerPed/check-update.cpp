#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <xmmintrin.h>
#include "game/Peds/CPlayerPed.h"
#include "update-fixture.h"
namespace P=reiv::game::player_update;
static std::array<unsigned char,16384> player,member,transform,related,action,actionInfo,query,task,vehicle,taskNested;
static std::array<unsigned char,8192> complexEntity;
static unsigned vtable[82],taskVtable[4],scenario,pattern,activeRandom,actions;
static ULONG_PTR stackLow,stackHigh;
static unsigned frameBase;
static unsigned visitedCalls[29]{};
static std::vector<unsigned> trace;
static const unsigned floatPatterns[]={0,0x80000000,0x3F800000,0xBF800000,0x3DCCCCCD,0x7FC00001,0x7F800001,1,0x7F800000,0xFF800000,0x40000000};
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned R(void*p,unsigned off){unsigned x;std::memcpy(&x,static_cast<unsigned char*>(p)+off,4);return x;}
static unsigned Normalize(unsigned value){
 struct Buffer{const unsigned char*p;unsigned size,tag;};
 const Buffer buffers[]={{player.data(),4096,0x10000000},{member.data(),4096,0x20000000},{transform.data(),4096,0x30000000},{related.data(),4096,0x40000000},{action.data(),4096,0x50000000},{actionInfo.data(),4096,0x60000000},{query.data(),4096,0x70000000},{task.data(),4096,0x80000000},{vehicle.data(),4096,0x90000000},{complexEntity.data(),8192,0xA0000000},{taskNested.data(),4096,0xB0000000}};
 for(auto b:buffers)if(value>=U(b.p)&&value<U(b.p)+b.size)return b.tag+value-U(b.p);
 if(value>=stackLow&&value<stackHigh)return 0xCCCC0000u+(value-frameBase); // exact signed offset from caller EBP; keeps local buffer identities distinct
 return value;
}
static unsigned __cdecl Record(unsigned f,void*receiver,unsigned*args,unsigned words){
 trace.push_back(f);
 bool callerPops=f==0x401950||f==0x462F90||f==0x924E80||f==0x987730||f==0xAA83F0||f==0xAB3B60;
 trace.push_back(callerPops?0:Normalize(U(receiver)));trace.push_back(words);for(unsigned i=0;i<words;++i)trace.push_back(Normalize(args[i]));
 for(unsigned i=0;i<27;++i)if(UpdateCallBindings[i].original==f)++visitedCalls[i];
 switch(f){
 case 0xF0000002:++visitedCalls[28];return 0;
 case 0x401950:return args[0]==45?60:activeRandom;
 case 0x4389D0:return U(member.data()+0x60);
 case 0x462F90:return scenario&1;
 case 0x88F5D0:return 0x1234;
 case 0x4269B0:return 1;
 case 0x89EA80:return(scenario&4)?U(task.data()):0;
 case 0x8AADC0:P::g011DDE74+=17;return 0xABCD1234;
 case 0x9BE5D0:return(scenario&2)?0:U(related.data());
 case 0x9A9CF0:return(scenario&8)?0:U(action.data());
 case 0x924E80:return U(actionInfo.data());
 case 0x91A050:std::memset(receiver,0x5A,24);return U(receiver);
 case 0xAA83F0:return U(query.data());
 case 0xAA80D0:return 0;
 case 0x976E90:std::memset(reinterpret_cast<void*>(args[2]),0x3C,16);std::memset(reinterpret_cast<void*>(args[3]),0x4D,16);return 0;
 case 0x987730:++actions;return 0;
 case 0xAFE160:return 0x4567;
 default:return 0;
 }
}
#include "update-stubs.h"
static unsigned __cdecl RecordVelocity(unsigned,void*,unsigned*,unsigned);
__declspec(naked) static void Velocity(){__asm{
 mov frameBase,ebp
 mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 0F0000001h
 call RecordVelocity
 add esp,16
 ret 4
}}
static unsigned __cdecl RecordVelocity(unsigned f,void*receiver,unsigned*args,unsigned words){
 ++visitedCalls[27];trace.insert(trace.end(),{f,Normalize(U(receiver)),words,Normalize(args[0])});auto p=reinterpret_cast<void*>(args[0]);W(p,0,floatPatterns[pattern]);W(p,4,floatPatterns[(pattern+3)%11]);W(p,8,0);W(p,12,0);return U(p);
}
__declspec(naked) static void TaskType(){__asm{
 mov frameBase,ebp
 push 0
 push 0
 push ecx
 push 0F0000002h
 call Record
 add esp,16
 mov eax,841h
 ret
}}
static void Initialize(){
 for(auto*p:{&player,&member,&transform,&related,&action,&actionInfo,&query,&task,&vehicle,&taskNested})p->fill(0);complexEntity.fill(0);trace.clear();actions=0;
 for(auto g:UpdateGlobalBindings)*g.storage=0;
 P::g010E1984=P::g00E3447C=0xFFFFFFFF;P::g011DDE74=1000;P::g011DDE7C=0x3DCCCCCD;
 P::g00F317B8=0x3F800000;P::g00D819B8=0x3F800000;P::g00D81944=0x3F800000;P::g00D582A0=0x3F000000;P::g00DC9290=0x3DCCCCCD;
 P::g00EBDED4=0x3F800000;P::g00DCB2AC=0x3F000000;P::g00D796E4=0x3F000000;P::g00D50398=0x3F800000;P::g00D8F340=0x42C80000;P::g00D81958=0x40000000;
 P::g016180EC=(scenario&16)?2000:0;P::g016180F0=scenario&32;P::g016180F4=500;P::g01618110=scenario&64;P::g0161810C=60000;
 P::g01724286=scenario&1;P::g016180E8=(scenario&128)?1:0;P::g011DDF38=(scenario&256)?1:0;
 vtable[59]=U(reinterpret_cast<void*>(&Velocity));taskVtable[3]=U(reinterpret_cast<void*>(&TaskType));
 W(player.data(),0,U(vtable));W(player.data(),0x228,U(member.data()));W(player.data(),0x20,U(transform.data()));W(player.data(),0x224,U(query.data()));
 player[0x218]=(scenario&512)?1:0;player[0x219]=(scenario&1024)?1:0;member[0x60+0x3BC]=static_cast<unsigned char>(scenario%3);member[0x60+0x3DD]=1;member[0x60+0x3DC]=static_cast<unsigned char>(scenario%3);member[0x60+0x416]=1;
 W(member.data(),0x60+0x3C0,(scenario&4)?700:0);W(member.data(),0x60+0x3D0,1);
 W(transform.data(),0x30,floatPatterns[pattern]);W(transform.data(),0x34,floatPatterns[(pattern+1)%11]);W(transform.data(),0x38,floatPatterns[(pattern+2)%11]);
 W(player.data(),0x118,1);for(unsigned off:{0xEE0u,0xEE4u,0xEE8u,0xEECu})W(player.data(),off,floatPatterns[pattern]);
 W(player.data(),0xB90,scenario%5);W(player.data(),0xA84,(scenario&2048)?1:0);W(player.data(),0xEF4,(scenario&4096)?0xFFFFFFFF:3);
 W(player.data(),0x26C,4);W(player.data(),0xB40,U(vehicle.data()));
 W(player.data(),0xAC0,U(complexEntity.data()));W(complexEntity.data(),0x28,(scenario&4)?0x100:0x80);W(complexEntity.data(),0xFA0,U(taskNested.data()));complexEntity[0xF6F]=0x40;W(taskNested.data(),0x21C,U(query.data()));W(query.data(),0x12C,2);
 W(player.data(),0x3A8,U(vehicle.data()));W(action.data(),0x18,1234);W(action.data(),0x1C,1);W(actionInfo.data(),0xC,(scenario&1)?1:0);
 W(player.data(),0x38,U(task.data()));W(player.data(),0x7C4,U(task.data()));W(player.data(),0x2DC,U(complexEntity.data()));W(complexEntity.data(),0x25C,U(query.data()));W(complexEntity.data(),0x20,U(transform.data()));W(task.data(),0,U(taskVtable));related[0x26DE]=200;
 W(player.data(),0xB0,1);W(player.data(),0xB8,1);activeRandom=(scenario&64)?96:91;
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char> b;for(auto g:UpdateGlobalBindings){auto p=reinterpret_cast<unsigned char*>(g.storage);b.insert(b.end(),p,p+4);}for(auto*p:{&player,&member,&transform,&related,&action,&actionInfo,&query,&task,&vehicle,&taskNested})b.insert(b.end(),p->begin(),p->end());b.insert(b.end(),complexEntity.begin(),complexEntity.end());return b;}
int main(){
 GetCurrentThreadStackLimits(&stackLow,&stackHigh);
 for(auto b:UpdateCallBindings)*b.target=StubAddress(b.original);
 auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(code,UpdateBytes,sizeof UpdateBytes);
 for(auto p:UpdateCallPatches){unsigned delta=U(StubAddress(p.target))-U(code+p.offset+4);std::memcpy(code+p.offset,&delta,4);}
 for(auto p:UpdateGlobalPatches){unsigned address=0;if(p.original==0x168F910)address=U(P::object0168F910);else for(auto g:UpdateGlobalBindings)if(g.original==p.original)address=U(g.storage);if(!address)return 2;std::memcpy(code+p.offset,&address,4);}
 auto patched=std::fopen("build/player-update-patched.bin","wb");if(!patched)return 4;std::fwrite(code,1,sizeof UpdateBytes,patched);std::fclose(patched);
 DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Native=unsigned char(__thiscall*)(void*);unsigned comparisons=0;
 for(unsigned rounding=0;rounding<4;++rounding)for(unsigned denorm=0;denorm<4;++denorm)for(unsigned precision:{0u,0x200u,0x300u}){
 const unsigned fpControl=0x1F80|(rounding<<13)|((denorm&1)?0x40:0)|((denorm&2)?0x8000:0);
 const unsigned short x87Control=static_cast<unsigned short>(0x7F|precision|(rounding<<10));
 for(scenario=0;scenario<8192;scenario+=31)for(pattern=0;pattern<11;++pattern){
  Initialize();_mm_setcsr(fpControl);__asm{fninit}__asm{fldcw x87Control}auto value=reinterpret_cast<Native>(code)(player.data());auto expected=Snapshot();auto log=trace;unsigned mxcsr=_mm_getcsr();unsigned short status;__asm{fnstsw status}
  Initialize();_mm_setcsr(fpControl);__asm{fninit}__asm{fldcw x87Control}auto rebuilt=P::Update(player.data(),nullptr);auto actual=Snapshot();unsigned short actualStatus;__asm{fnstsw actualStatus}
  if(value!=rebuilt||expected!=actual||log!=trace||mxcsr!=_mm_getcsr()||status!=actualStatus){std::printf("FAIL scenario=%u pattern=%u return=%u/%u memory=%d log=%d fp=%04X/%04X\n",scenario,pattern,value,rebuilt,expected!=actual,log!=trace,status,actualStatus);return 3;}++comparisons;
 }
 std::printf("group rounding=%u denorm=%u precision=%u passed\n",rounding,denorm,precision);std::fflush(stdout);
 }
 std::printf("PASS comparisons=%u failures=0 masked_fp_state_matched=1\n",comparisons);
 for(unsigned i=0;i<27;++i)std::printf("dependency %08X calls=%u\n",UpdateCallBindings[i].original,visitedCalls[i]);
 std::printf("virtual 59 calls=%u\nvirtual 3 calls=%u\n",visitedCalls[27],visitedCalls[28]);
 _mm_setcsr(0x1F80);__asm{fninit}VirtualFree(code,0,MEM_RELEASE);return 0;
}
