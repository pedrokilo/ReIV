#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <xmmintrin.h>
#include "game/Peds/PlayerPedRelatedFlags.h"
#include "related-flags-fixture.h"
using D=reiv::game::PlayerPedRelatedFlagDependencies;using R=reiv::game::PlayerPedRelatedFlags;
static std::array<unsigned char,4096> player,block;static std::array<std::array<unsigned char,4096>,7> candidates;
static unsigned table1[13],table2[13],scenario,step,base,seed,lookupCalls;static unsigned char flags[7];static std::vector<unsigned> trace;
static unsigned U(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned Read(void*p,unsigned off){unsigned x;std::memcpy(&x,static_cast<unsigned char*>(p)+off,4);return x;}
static const unsigned indices[]={0,1,0xFFFFFFFF,0x80000000,0x10000000,0x2C8590B2};
static const void* Block(void*p){step=lookupCalls++;trace.insert(trace.end(),{0x4389D0,U(p),step});W(block.data(),0x3D4,indices[(scenario+step)%6]);return block.data();}
static void* Enumerate(unsigned receiver,unsigned index){trace.insert(trace.end(),{0xA66B70,receiver,index});return ((scenario>>index)&1)?nullptr:candidates[index].data();}
static void Virtual(unsigned variant,void*p,unsigned arg){trace.insert(trace.end(),{12,variant,U(p),arg,step});auto c=candidates[step].data();if(scenario&8)W(c,0x260,Read(c,0x260)^0x1000);if(scenario&16)c[0x26C]^=4;if(scenario&32)flags[step]^=255;if(scenario&64)W(c,0x24,Read(c,0x24)^0x12345678);if(scenario&128){W(p,0,U(table2));flags[(step+1)%7]^=1;}}
static const void* __fastcall NativeBlock(void*p,void*){return Block(p);}
static void* __fastcall NativeEnumerate(void*p,void*,unsigned i){return Enumerate(U(p),i);}
static void __fastcall NativeVirtual1(void*p,void*,unsigned arg){Virtual(1,p,arg);}
static void __fastcall NativeVirtual2(void*p,void*,unsigned arg){Virtual(2,p,arg);}
static void DispatchVirtual(void*p,unsigned arg){auto t=Read(p,0);Virtual(t==U(table1)?1:2,p,arg);}
static void Init(){for(unsigned i=0;i<4096;++i){player[i]=static_cast<unsigned char>(i*13+scenario);block[i]=static_cast<unsigned char>(i*17+scenario);for(unsigned j=0;j<7;++j)candidates[j][i]=static_cast<unsigned char>(i*23+j*31+scenario);}lookupCalls=0;step=0;trace.clear();W(player.data(),0,U(table1));
 for(unsigned j=0;j<7;++j){candidates[j][0xA70]=((scenario+j)%3)==0?2:1;candidates[j][0x26C]=((scenario+j)&1)?4:0;flags[j]=static_cast<unsigned char>((scenario+j*seed)&255);W(candidates[j].data(),0x260,(scenario*0x81234567)^(j*0x12345678));}
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char>b;for(auto*p:{&player,&block})b.insert(b.end(),p->begin(),p->end());for(auto&c:candidates)b.insert(b.end(),c.begin(),c.end());b.insert(b.end(),flags,flags+7);return b;}
int main(){table1[12]=U(reinterpret_cast<void*>(&NativeVirtual1));table2[12]=U(reinterpret_cast<void*>(&NativeVirtual2));auto code=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(code,RelatedFlagBytes,sizeof RelatedFlagBytes);
 for(auto c:RelatedFlagCalls){void*target=c.address==0x4389D0?reinterpret_cast<void*>(&NativeBlock):reinterpret_cast<void*>(&NativeEnumerate);unsigned d=U(target)-U(code+c.offset+4);std::memcpy(code+c.offset,&d,4);}
 for(auto g:RelatedFlagGlobals)if(g.address==0x16180E0){unsigned a=U(flags);std::memcpy(code+g.offset,&a,4);}
 unsigned baseOffset=RelatedFlagGlobals[0].address==0x1662178?RelatedFlagGlobals[0].offset:RelatedFlagGlobals[1].offset;
 using Fn=unsigned(__thiscall*)(void*);unsigned count=0;
 for(unsigned b:{0u,0x1662178u,0xFFFFFFF0u,0x80000000u})for(unsigned s:{0u,1u,2u,255u}){base=b;seed=s;
  DWORD old;VirtualProtect(code,4096,PAGE_READWRITE,&old);std::memcpy(code+baseOffset,&base,4);VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),code,4096);D deps{Block,Enumerate,DispatchVirtual,base,flags};
  for(scenario=0;scenario<256;++scenario){unsigned csr=0x1F80|((scenario%4)<<13)|((scenario&4)?0x8040:0);unsigned short cw=static_cast<unsigned short>(0x37F|((scenario%4)<<10));unsigned char expectedValue[10],actualValue[10];
   Init();_mm_setcsr(csr);__asm{fninit
   fldcw cw
   fld1}unsigned expected=reinterpret_cast<Fn>(code)(player.data());auto state=Snapshot();auto log=trace;unsigned calls=lookupCalls;unsigned fp=_mm_getcsr();unsigned short sw;__asm{fnstsw sw
   fstp tbyte ptr expectedValue}
   Init();_mm_setcsr(csr);__asm{fninit
   fldcw cw
   fld1}unsigned actual=R::UpdateRaw(player.data(),deps);unsigned short asw;__asm{fnstsw asw
   fstp tbyte ptr actualValue}
   if(expected!=actual||state!=Snapshot()||log!=trace||calls!=7||lookupCalls!=7||fp!=_mm_getcsr()||sw!=asw||std::memcmp(expectedValue,actualValue,10)){std::printf("FAIL base=%X seed=%u scenario=%u result=%X/%X mem=%d log=%d\n",base,seed,scenario,expected,actual,state!=Snapshot(),log!=trace);return 2;}++count;}
 }
 _mm_setcsr(0x1F80);__asm{fninit}auto file=std::fopen("build/player-related-flags-patched.bin","wb");std::fwrite(code,1,sizeof RelatedFlagBytes,file);std::fclose(file);std::printf("PASS comparisons=%u failures=0 raw_eax_full_buffers_trace_wrap_reloads_virtual_dispatch_fp_matched=1\n",count);return 0;}

