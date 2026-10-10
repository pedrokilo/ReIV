#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <xmmintrin.h>
#include "game/Peds/CPlayerPed.h"
#include "input-fixture.h"
namespace I=reiv::game::player_input;
static std::array<unsigned char,4096> player,query,action,actionInfo,transform;
static std::array<unsigned char,16384> related,vehicle;
static unsigned scenario,selected,state,stackAnchor;static ULONG_PTR stackLow,stackHigh;
static std::vector<unsigned> trace;static unsigned callCounts[19]{};
static unsigned jumpModes[24]{};
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned R(void*p,unsigned off){unsigned x;std::memcpy(&x,static_cast<unsigned char*>(p)+off,4);return x;}
static unsigned Normalize(unsigned value){if(value>=stackLow&&value<stackHigh)return 0xCCCC0000u+(value-stackAnchor);return value;}
static const unsigned queryOffsets[]={0x2D98,0x2DA8,0x2938,0x2CF8,0x2D18,0x2D58,0x2D08,0x27E8,0x2718,0x2728,0x2CD8,0x2CE8,0x2D28,0x2D38,0x2D48,0x2D68};
static unsigned __cdecl Record(unsigned f,void*p,unsigned*args,unsigned words){
 bool callerPops=f==0x8FF470||f==0x924E80||f==0x4255A0||f==0x9B3B00||f==0x9ADB90||f==0x462F90||f==0x987730||f==0x99C5E0;
 trace.insert(trace.end(),{f,callerPops?0:Normalize(U(p)),words});for(unsigned i=0;i<words;++i)trace.push_back(Normalize(args[i]));for(unsigned i=0;i<19;++i)if(InputCallBindings[i].original==f)++callCounts[i];
 switch(f){
 case 0x9BE5D0:return U(related.data());
 case 0x8FF470:return selected>=22?0:(scenario>>5)&1;
 case 0x426780:return U(p)==U(related.data())+(selected==22?0x2DA8:selected==23?0x2D98:selected==20||selected==21?0x27E8:queryOffsets[selected%16]);
 case 0x9BE4A0:return(scenario>>6)&1;
 case 0x9C5D60:return!((scenario>>8)&1);
 case 0x785EB0:return selected&1;
 case 0x89E300:return state;
 case 0x924E80:return U(actionInfo.data());
 case 0x9252D0:return 1;
 case 0x9B3B00:return(scenario>>10)&1;
 case 0x9ADB90:return(scenario>>11)&1;
 case 0x9AA330:if(words==4&&args[1]==4&&args[2]==0&&args[3]==U(player.data())&&args[0]<24)++jumpModes[args[0]];W(player.data(),0x2C8,args[1]);return 0;
 case 0x462F90:return(scenario>>14)&1;
 case 0x9A9CF0:return(scenario>>13)&1?0:U(action.data());
 case 0x426910:return(scenario>>15)&1;
 case 0x9AC110:W(player.data(),0x2B0+0x18,0);return 1;
 default:return 0;
 }
}
#include "input-stubs.h"
static void Initialize(){
 player.fill(0);query.fill(0);action.fill(0);actionInfo.fill(0);transform.fill(0);related.fill(0);vehicle.fill(0);trace.clear();
 I::g011DDF38=1234;I::g010F8044=(scenario&4096)?2:0;
 W(player.data(),0x228,U(query.data()));W(player.data(),0x224,U(query.data()));W(player.data(),0x20,U(transform.data()));
 if(scenario&4){W(player.data(),0xB40,U(vehicle.data()));W(player.data(),0x26C,4);}else W(player.data(),0xB40,0);
 player[0x2A0]=(scenario&8)?0x10:0;W(player.data(),0x264,(scenario&16)?0x80000000:0);
 related[0x328C]=(scenario&1)?1:0;related[0x328D]=(scenario&2)?1:0;
 W(vehicle.data(),0x1354,(scenario&128)?2:0);W(vehicle.data(),0x1350,1);vehicle[0xF71]=(scenario&512)?1:0;
 for(unsigned off:{0x271Eu,0x272Eu,0x27EEu,0x27FEu,0x280Eu,0x321Eu})related[off]=static_cast<unsigned char>(selected==16?127:selected==17?128:selected==18?255:(off>>4==((selected%16)+0x270))?200:0);
 related[0x27FF]=(selected&1)?128:0;related[0x321F]=(selected&2)?128:0;
 for(unsigned off=0x2F8;off<=0x358;off+=12)W(player.data(),off,selected&1?1:0xFFFFFFFF);
 W(player.data(),0x310,(state&1)?0x16:0x1A);W(query.data(),0x424,(selected&1)?1234:0);W(player.data(),0x2C8,(state&1)?1:0);
 if(selected==20||selected==21){related[0x328C]=1;related[0x328D]=0;related[0x280E]=128;related[0x271E]=related[0x272E]=0;related[0x27EE]=128;W(player.data(),0x328,selected==20?1:0);W(player.data(),0x31C,1);}
 if(selected>=22){player[0x2A0]=0;W(player.data(),0x264,0);W(player.data(),0xB40,U(vehicle.data()));W(player.data(),0x26C,4);related[0x328C]=0;related[0x328D]=1;W(query.data(),0x424,0);}
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char>b;for(auto*p:{&player,&query,&action,&actionInfo,&transform})b.insert(b.end(),p->begin(),p->end());b.insert(b.end(),related.begin(),related.end());b.insert(b.end(),vehicle.begin(),vehicle.end());for(auto g:InputGlobalBindings){auto ptr=reinterpret_cast<unsigned char*>(g.storage);b.insert(b.end(),ptr,ptr+4);}return b;}
int main(){
 GetCurrentThreadStackLimits(&stackLow,&stackHigh);for(auto b:InputCallBindings)*b.target=Stub(b.original);
 auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(code,InputBytes,sizeof InputBytes);unsigned tables[2][4];for(unsigned i=0;i<2;++i)for(unsigned j=0;j<4;++j)tables[i][j]=U(code+InputJumpTargets[i][j]);
 for(auto p:InputCallPatches){unsigned d=U(Stub(p.target))-U(code+p.offset+4);std::memcpy(code+p.offset,&d,4);}
 for(auto p:InputGlobalPatches){unsigned addr=p.original==0x9BEE44?U(tables[0]):p.original==0x9BEE54?U(tables[1]):0;for(auto b:InputGlobalBindings)if(b.original==p.original)addr=U(b.storage);if(!addr)return 1;std::memcpy(code+p.offset,&addr,4);}
 auto file=std::fopen("build/player-input-select-patched.bin","wb");std::fwrite(code,1,sizeof InputBytes,file);std::fclose(file);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Original=void(__thiscall*)(void*);unsigned count=0;
 for(scenario=0;scenario<65536;scenario+=127)for(selected=0;selected<24;++selected)for(state=10;state<16;++state){
  Initialize();_mm_setcsr(0x1F80);__asm{fninit}reinterpret_cast<Original>(code)(player.data());auto expected=Snapshot();auto log=trace;unsigned fp=_mm_getcsr();unsigned short sw;__asm{fnstsw sw}
  Initialize();_mm_setcsr(0x1F80);__asm{fninit}I::Select(player.data(),nullptr);unsigned short actual;__asm{fnstsw actual}if(expected!=Snapshot()||log!=trace||fp!=_mm_getcsr()||sw!=actual){std::printf("FAIL scenario=%u selected=%u state=%u mem=%d log=%d\n",scenario,selected,state,expected!=Snapshot(),log!=trace);return 2;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}std::printf("PASS comparisons=%u failures=0 mapped_tables_full_buffers_ordered_trace_fp_state_matched=1\n",count);for(unsigned i=0;i<19;++i)std::printf("dependency %08X calls=%u\n",InputCallBindings[i].original,callCounts[i]);for(unsigned mode:{2u,3u,4u,5u,20u,21u,22u,23u})std::printf("jump_mode %u calls=%u\n",mode,jumpModes[mode]);VirtualFree(code,0,MEM_RELEASE);return 0;
}
