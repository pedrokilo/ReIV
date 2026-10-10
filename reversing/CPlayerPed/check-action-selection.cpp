#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include "game/Peds/PlayerPedActionSelection.h"
#include "selection-fixture.h"
namespace S=reiv::game::player_action_selection;
static std::array<unsigned char,4096> player,candidate,candidate2,transform,direction,tls;
static unsigned tlsVector[1];static unsigned scenario,flags,fpPattern,stackAnchor,callCounts[13]{};static ULONG_PTR stackLow,stackHigh;static std::vector<unsigned> trace;
static unsigned U(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned o,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+o,&x,4);}
static unsigned R(void*p,unsigned o){unsigned x;std::memcpy(&x,static_cast<unsigned char*>(p)+o,4);return x;}
static unsigned Norm(unsigned x){return x>=stackLow&&x<stackHigh?0xCCCC0000u+(x-stackAnchor):x;}
static const unsigned patterns[]={0,0x80000000,0x3F800000,0x40000000,0xBF800000,0x7F800000,0xFF800000,0x7FC00001,0x7F800001,1};
static unsigned __cdecl Record(unsigned f,void*p,unsigned*args,unsigned words){
 bool callerPops=f==0x441F20||f==0x462F90||f==0xD0C8E4;
 trace.insert(trace.end(),{f,callerPops?0:Norm(U(p)),words});for(unsigned i=0;i<words;++i)trace.push_back(Norm(args[i]));for(unsigned i=0;i<13;++i)if(SelectionCallBindings[i].original==f)++callCounts[i];
 switch(f){case 0x9E9090:W(p,0,0);return 0;
 case 0x9E9340:{unsigned i=R(p,0);W(p,0,i+1);return i==0?U(candidate.data()):i==1?U(candidate2.data()):0;}
 case 0x9C03E0:*reinterpret_cast<unsigned char*>(args[3])=static_cast<unsigned char>((scenario>>1)&1);return scenario&1;
 case 0x9C07A0:return patterns[fpPattern];
 case 0x9BF390:return patterns[(fpPattern+2)%10];
 case 0x9BF420:return patterns[(fpPattern+4)%10];
 case 0x9BF360:return (scenario>>2)&1;
 case 0x9C0660:return (scenario>>3)&1;
 case 0x462F90:return (scenario>>4)&1;
 case 0x441F20:return U(direction.data());default:return 0;}
}
#include "selection-stubs.h"
static float output;static unsigned outputInitial;
static void Init(){for(auto*p:{&player,&candidate,&candidate2,&transform,&direction,&tls})p->fill(0);trace.clear();stackAnchor=0;outputInitial=0xDEADBEEF;std::memcpy(&output,&outputInitial,4);
 W(player.data(),0xE7C,U(player.data()));W(player.data(),0x20,U(transform.data()));W(player.data(),0xD78,(scenario&32)?1:0);player[0x267]=(scenario&64)?1:0;
 for(auto*p:{&candidate,&candidate2}){W(p->data(),0x28,(scenario&128)?0xC0:0);(*p)[0xA70]=(scenario&256)?2:0;}
 for(unsigned o=0x10;o<=0x38;o+=4)W(transform.data(),o,patterns[(fpPattern+1)%10]);for(unsigned o:{0u,4u,8u})W(direction.data(),o,patterns[(fpPattern+3)%10]);
 for(auto b:SelectionGlobalBindings)*b.storage=0x3F800000;
 S::g00F2F869=(scenario>>9)&1;S::g00F2F86A=(scenario>>10)&1;S::g01618106=(scenario>>11)&1;S::g01618101=(scenario>>12)&1;
 S::g00DECD60=0;S::g011DC4C0=S::g011DC4C4=S::g011DC4C8=0;S::g011DC4E0=S::g011DC4E4=S::g011DC4E8=0;
 tlsVector[0]=U(tls.data());S::g0000002C=U(tlsVector);S::g017237B0=0;
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char>b;for(auto*p:{&player,&candidate,&candidate2,&transform,&direction,&tls})b.insert(b.end(),p->begin(),p->end());for(auto g:SelectionGlobalBindings){auto*p=reinterpret_cast<unsigned char*>(g.storage);b.insert(b.end(),p,p+4);}auto*p=reinterpret_cast<unsigned char*>(&output);b.insert(b.end(),p,p+4);return b;}
int main(){GetCurrentThreadStackLimits(&stackLow,&stackHigh);auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(code,SelectionBytes,sizeof SelectionBytes);
 for(auto b:SelectionCallBindings)if(b.original!=0x9C1300)*b.target=Stub(b.original);
 for(auto p:SelectionCallPatches){void*target=p.target==0x9C1300?code:Stub(p.target);if(!target)return 1;unsigned d=U(target)-U(code+p.offset+4);std::memcpy(code+p.offset,&d,4);}
 for(auto p:SelectionGlobalPatches){unsigned addr=0;for(auto b:SelectionGlobalBindings)if(b.original==p.original)addr=U(b.storage);if(!addr)return 1;std::memcpy(code+p.offset,&addr,4);if(p.original==0x2C){if(code[p.offset-2]!=0x64||code[p.offset-1]!=0xA1)return 3;code[p.offset-2]=0x90;}}
 auto file=std::fopen("build/player-action-selection-patched.bin","wb");std::fwrite(code,1,sizeof SelectionBytes,file);std::fclose(file);DWORD old;VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Fn=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,float*,unsigned);unsigned count=0;
 for(unsigned config=0;config<8;++config)for(scenario=0;scenario<65536;scenario+=997)for(unsigned low=0;low<32;++low)for(fpPattern=0;fpPattern<10;++fpPattern){flags=low|((scenario&1)?0x100:0)|((scenario&2)?0x200:0)|((scenario&4)?0x400:0);unsigned csr=0x1F80|((config%4)<<13)|((config/4)?0x8040:0);unsigned short cw=static_cast<unsigned short>(0x37F|((config%4)<<10));
  Init();_mm_setcsr(csr);__asm{fninit
 fldcw cw}unsigned expected=reinterpret_cast<Fn>(code)(player.data()+0xE7C,flags,0x3F800000,(scenario&8)?U(direction.data()):0,(scenario&16)?&output:nullptr,0);auto memory=Snapshot();auto log=trace;unsigned fp=_mm_getcsr();unsigned short sw;__asm{fnstsw sw}
  Init();_mm_setcsr(csr);__asm{fninit
 fldcw cw}unsigned actual=S::Select(player.data()+0xE7C,nullptr,flags,0x3F800000,(scenario&8)?U(direction.data()):0,(scenario&16)?&output:nullptr,0);unsigned short asw;__asm{fnstsw asw}
  if(expected!=actual||memory!=Snapshot()||log!=trace||fp!=_mm_getcsr()||sw!=asw){std::printf("FAIL config=%u scenario=%u flags=%X pattern=%u result=%X/%X mem=%d log=%d fp=%X/%X sw=%X/%X\n",config,scenario,flags,fpPattern,expected,actual,memory!=Snapshot(),log!=trace,fp,_mm_getcsr(),sw,asw);return 2;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}std::printf("PASS comparisons=%u failures=0 full_buffers_trace_fp_return_recursion_tls_environment_matched=1\n",count);for(unsigned i=0;i<13;++i)std::printf("dependency %08X calls=%u\n",SelectionCallBindings[i].original,callCounts[i]);return 0;}

