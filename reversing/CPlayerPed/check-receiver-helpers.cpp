#include <windows.h>
#include <array>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include "game/Peds/PlayerPedReceiverHelpers.h"
#include "receiver-helpers-fixture.h"
namespace H=reiv::game::player_receiver_helpers;
static std::array<unsigned char,4096> player,related,transform,info;
static std::vector<unsigned> trace;static unsigned scenario,index,flag,a1,a2,counts[6]{};
static unsigned U(const void*p){return unsigned(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned off,unsigned x){std::memcpy(static_cast<unsigned char*>(p)+off,&x,4);}
static unsigned __cdecl Record(unsigned f,void*p,unsigned*args,unsigned words){trace.insert(trace.end(),{f,f==0x924E80?0:U(p),words});for(unsigned i=0;i<words;++i)trace.push_back(args[i]);for(unsigned i=0;i<6;++i)if(HelperBindings[i].va==f)++counts[i];
 unsigned value=(scenario*0x81234567)^0xCA000000;
 switch(f){case 0x8A3390:return (value&0xFFFFFF00)|((scenario%4)==0?0:(scenario%4)==1?1:(scenario%4)==2?2:255);
 case 0x89DFB0:W(player.data(),0x58C,scenario);return(value&0xFFFFFF00)|((scenario>>2)&1);
 case 0x924E80:if(scenario&16)W(player.data(),0x2EC+index*12,(scenario&32)?a1:0);return U(info.data());
 case 0x921E00:case 0x922020:W(player.data(),0x228,(scenario&64)?0:U(related.data()));W(transform.data(),0x30,args[1]);return value;
 case 0x921320:return value;default:return 0;}}
__declspec(naked) static void S8A3390(){__asm{push 0
 lea eax,[esp+8]
 push eax
 push ecx
 push 08A3390h
 call Record
 add esp,16
 ret}}
__declspec(naked) static void S89DFB0(){__asm{push 0
 lea eax,[esp+8]
 push eax
 push ecx
 push 089DFB0h
 call Record
 add esp,16
 ret}}
__declspec(naked) static void S924E80(){__asm{mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 0924E80h
 call Record
 add esp,16
 ret}}
__declspec(naked) static void S921E00(){__asm{mov eax,esp
 add eax,4
 push 4
 push eax
 push ecx
 push 0921E00h
 call Record
 add esp,16
 ret 16}}
__declspec(naked) static void S922020(){__asm{mov eax,esp
 add eax,4
 push 4
 push eax
 push ecx
 push 0922020h
 call Record
 add esp,16
 ret 16}}
__declspec(naked) static void S921320(){__asm{push 0
 lea eax,[esp+8]
 push eax
 push ecx
 push 0921320h
 call Record
 add esp,16
 ret}}
static void* Stub(unsigned a){switch(a){case 0x8A3390:return reinterpret_cast<void*>(&S8A3390);case 0x89DFB0:return reinterpret_cast<void*>(&S89DFB0);case 0x924E80:return reinterpret_cast<void*>(&S924E80);case 0x921E00:return reinterpret_cast<void*>(&S921E00);case 0x922020:return reinterpret_cast<void*>(&S922020);case 0x921320:return reinterpret_cast<void*>(&S921320);default:return nullptr;}}
static void Init(){for(auto*p:{&player,&related,&transform,&info})for(unsigned i=0;i<4096;++i)(*p)[i]=static_cast<unsigned char>(i*37+scenario);trace.clear();
 const unsigned relatedValues[]={0,U(related.data()),0xFFFFFFA0,0xFFFFFF9F,0xFFFFFFFF};const unsigned transformValues[]={0,U(transform.data()),0xFFFFFFD0,0xFFFFFFCF};
 W(player.data(),0x228,relatedValues[scenario%5]);W(player.data(),0x20,transformValues[(scenario/5)%4]);W(info.data(),4,index);W(player.data(),0x2EC+index*12,(scenario&4)?a1:(scenario&8)?0:a1^0x12345678);
}
static std::vector<unsigned char> Snapshot(){std::vector<unsigned char>b;for(auto*p:{&player,&related,&transform,&info})b.insert(b.end(),p->begin(),p->end());return b;}
static unsigned Invoke(void*code,bool source,unsigned kind){if(source){switch(kind){case 0:return H::TestEitherPredicate(player.data(),nullptr);case 1:return H::SetPairFirstRaw(player.data(),nullptr,a1,a2);case 2:return H::SetPairSecondRaw(player.data(),nullptr,a1,a2);case 3:return H::GetRelatedRaw(player.data(),nullptr);case 4:return H::TestActionAllowed(player.data(),nullptr,a1,flag);}}if(kind==0||kind==3)return reinterpret_cast<unsigned(__thiscall*)(void*)>(code)(player.data());return reinterpret_cast<unsigned(__thiscall*)(void*,unsigned,unsigned)>(code)(player.data(),a1,kind==4?flag:a2);}
int main(){void*codes[5];for(auto b:HelperBindings)*b.target=Stub(b.va);for(unsigned k=0;k<5;++k){auto f=Helpers[k];auto c=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));std::memcpy(c,f.bytes,f.size);for(unsigned j=0;j<f.count;++j){auto p=f.patches[j];unsigned d=U(Stub(p.target))-U(c+p.offset+4);std::memcpy(c+p.offset,&d,4);}auto file=std::fopen(("build/player-receiver-"+std::to_string(k)+"-patched.bin").c_str(),"wb");std::fwrite(c,1,f.size,file);std::fclose(file);DWORD old;VirtualProtect(c,4096,PAGE_EXECUTE_READ,&old);FlushInstructionCache(GetCurrentProcess(),c,4096);codes[k]=c;}
 const unsigned indices[]={0,1,5,31,0xFFFFFFFF};const unsigned args[]={0,1,0xFFFFFFFF,0x80000000,0x7F800001,0xFF000000};unsigned count=0;
 for(unsigned k=0;k<5;++k)for(scenario=0;scenario<256;++scenario)for(unsigned idx:indices)for(unsigned x:args){index=idx;a1=x;a2=x^0x81234567;flag=(scenario&128)?0xFF000000:scenario%4;unsigned csr=0x1F80|((scenario%4)<<13)|((scenario&4)?0x8040:0);unsigned short cw=static_cast<unsigned short>(0x37F|((scenario%4)<<10));
  Init();_mm_setcsr(csr);__asm{fninit
 fldcw cw}unsigned expected=Invoke(codes[k],false,k)&Helpers[k].mask;auto state=Snapshot();auto log=trace;unsigned fp=_mm_getcsr();unsigned short sw;__asm{fnstsw sw}
  Init();_mm_setcsr(csr);__asm{fninit
 fldcw cw}unsigned actual=Invoke(codes[k],true,k)&Helpers[k].mask;unsigned short asw;__asm{fnstsw asw}
  if(expected!=actual||state!=Snapshot()||log!=trace||fp!=_mm_getcsr()||sw!=asw){std::printf("FAIL k=%u scenario=%u index=%X args=%X result=%X/%X mem=%d trace=%d\n",k,scenario,index,x,expected,actual,state!=Snapshot(),log!=trace);return 2;}++count;
 }
 _mm_setcsr(0x1F80);__asm{fninit}std::printf("PASS comparisons=%u per_method=7680 failures=0 full_buffers_trace_return_fp_matched=1\n",count);for(unsigned i=0;i<6;++i)std::printf("dependency %08X calls=%u\n",HelperBindings[i].va,counts[i]);return 0;}
