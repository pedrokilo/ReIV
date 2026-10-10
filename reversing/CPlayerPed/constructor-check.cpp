#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include "game/Peds/CPlayerPed.h"
using C=reiv::game::PlayerPedConstruction;
struct Patch { unsigned offset,va; }; struct Call { unsigned offset,target; };
#include "constructor-patches.inc"
static std::array<std::uint32_t,sizeof(globalVAs)/4> globals;
static std::array<std::uint8_t,4096> player,first,second,target,auxiliary;
static std::vector<std::uint32_t> trace;
static unsigned scenario,randomSample;
static std::uint32_t U(const void* p) { return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p)); }
static unsigned Index(unsigned va) { for(unsigned i=0;i<globals.size();++i)if(globalVAs[i]==va)return i;std::abort(); }
static std::uint32_t R(unsigned va) { return globals[Index(va)]; }
static void W(unsigned va,unsigned value) { globals[Index(va)]=value; }
static void B(unsigned va,std::uint8_t value) { std::memcpy(&globals[Index(va)],&value,1); }
static std::uint32_t Address(unsigned va) {
 for(unsigned i=0;i<globals.size();++i)if(globalVAs[i]==va)return U(&globals[i]);
 return 0xB0000000u|(va&0x0FFFFFFFu);
}
static void Store(void* p,unsigned off,unsigned value) {std::memcpy(static_cast<std::uint8_t*>(p)+off,&value,4);}
static void Event(unsigned id,std::initializer_list<unsigned> args={}) {trace.push_back(id);for(auto a:args)trace.push_back(a);}
static void Base(void* p,unsigned a,unsigned b) {Event(0x8ABF10,{U(p),a,b});Store(p,0x21C,U(first.data()));Store(p,0x224,U(target.data()));static_cast<std::uint8_t*>(p)[0x218]=(scenario&4)?1:0;static_cast<std::uint8_t*>(p)[0x219]=(scenario&8)?1:0;}
static void Embedded(void* p) {Event(0xC68B50,{U(p)});Store(p,0,0xABCD1234);}
static void ValueCtor(void* p) {Event(0x4475C0,{U(p)});Store(p,0,0x98765432);}
static void Block1(void* p,unsigned a) {Event(0xB2A8F0,{U(p),a});}
static void Block2(void* p) {Event(0xB29E50,{U(p)});}
static void* Resolve(unsigned a) {Event(0x817F20,{a});return first.data();}
static void Link(void* p,void* q) {Event(0x920CD0,{U(p),U(q)});if(scenario&16)Store(q,0x228,U(second.data()));}
static void LinkDone(void* p) {Event(0x921050,{U(p)});}
static void Init(void* p) {Event(0x9BE4C0,{U(p)});}
static unsigned Random() {Event(0xD0D21A);return randomSample;}
static unsigned Hash(unsigned p) {Event(0x8631E0,{p});return 0xDC123456;}
static void Value(void* p,unsigned bits) {Event(0x447610,{U(p),bits});Store(p,4,bits);}
static void Flags(void* p,unsigned bits) {Event(0x89E5A0,{U(p),bits});Store(p,0x214,bits);}
static void Reset(void* p) {Event(0x9720E0,{U(p)});Store(p,0,0xF123ABCD);}
static unsigned IndexValue() {Event(0x797D70);return (scenario&32)?0x65432110:0x65432111;}
static void Message(unsigned a,unsigned b,unsigned c,unsigned d) {Event(0xD4D4B8,{a,b,c,d});}
static void* Allocate(unsigned a) {Event(0x4011D0,{a});return (scenario&64)?nullptr:auxiliary.data();}
static void* Create(void* p) {Event(0x8DA9A0,{U(p)});return p;}
static std::uint8_t Flag(void* p) {Event(0x878A00,{U(p)});return (scenario&128)?1:0;}
static void __fastcall NBase(void* p,void*,unsigned a,unsigned b) {Base(p,a,b);}
static void __fastcall NEmbedded(void* p,void*) {Embedded(p);}
static void __fastcall NValueCtor(void* p,void*) {ValueCtor(p);}
static void __fastcall NBlock1(void* p,void*,unsigned a) {Block1(p,a);}
static void __fastcall NLink(void* p,void*,void* q) {Link(p,q);}
static void __fastcall NLinkDone(void* p,void*) {LinkDone(p);}
static void __fastcall NInit(void* p,void*) {Init(p);}
static void __fastcall NValue(void* p,void*,unsigned a) {Value(p,a);}
static void __fastcall NFlags(void* p,void*,unsigned a) {Flags(p,a);}
static void __fastcall NReset(void* p,void*) {Reset(p);}
static void* __fastcall NCreate(void* p,void*) {return Create(p);}
static std::uint8_t __fastcall NFlag(void* p,void*) {return Flag(p);}
static void __stdcall NMessage(unsigned a,unsigned b,unsigned c,unsigned d) {Message(a,b,c,d);}
static void* Function(unsigned va) {
 switch(va) {
 case 0x8ABF10:return reinterpret_cast<void*>(NBase); case 0xC68B50:return reinterpret_cast<void*>(NEmbedded);
 case 0x4475C0:return reinterpret_cast<void*>(NValueCtor); case 0xB2A8F0:return reinterpret_cast<void*>(NBlock1);
 case 0xB29E50:return reinterpret_cast<void*>(Block2); case 0x817F20:return reinterpret_cast<void*>(Resolve);
 case 0x920CD0:return reinterpret_cast<void*>(NLink); case 0x921050:return reinterpret_cast<void*>(NLinkDone);
 case 0x9BE4C0:return reinterpret_cast<void*>(NInit); case 0xD0D21A:return reinterpret_cast<void*>(Random);
 case 0x8631E0:return reinterpret_cast<void*>(Hash); case 0x447610:return reinterpret_cast<void*>(NValue);
 case 0x89E5A0:return reinterpret_cast<void*>(NFlags); case 0x9720E0:return reinterpret_cast<void*>(NReset);
 case 0x797D70:return reinterpret_cast<void*>(IndexValue); case 0x4011D0:return reinterpret_cast<void*>(Allocate);
 case 0x8DA9A0:return reinterpret_cast<void*>(NCreate); case 0x878A00:return reinterpret_cast<void*>(NFlag);
 default:std::abort();
 }
}
static void Seed() {
 for(unsigned i=0;i<4096;++i) {player[i]=static_cast<std::uint8_t>(i*37+scenario);first[i]=static_cast<std::uint8_t>(i*19+scenario);second[i]=static_cast<std::uint8_t>(i*29+scenario);target[i]=static_cast<std::uint8_t>(i*31+scenario);auxiliary[i]=0xD1;}
 for(unsigned i=0;i<globals.size();++i)globals[i]=globalVAs[i]^0xA123D123;
 W(0xD4D4B8,U(reinterpret_cast<void*>(NMessage)));
 W(0x10D0170,(scenario&1)?1:0);W(0x10E1984,(scenario&2)?0xFFFFFFFF:123);W(0xE3447C,0xFFFFFFFF);
 W(0xF0E4A0,(scenario&256)?0x12:0x11);W(0x10D00A0,0x65432110);
 W(0xEBE1D8,0x38000000);W(0xD819BC,0xC808B800);
 W(0xD8D70C,(scenario&512)?0x7F800001:0x43480000);
 W(0xD50978,0x41F00000);W(0xD81958,0x40000000);
 trace.clear();
}
struct Snapshot {std::array<std::uint8_t,4096> p,a,b,c,e;decltype(globals) g;};
static Snapshot Capture() {return {player,first,second,target,auxiliary,globals};}
static bool Equal(const Snapshot& x,const Snapshot& y) {return x.p==y.p&&x.a==y.a&&x.b==y.b&&x.c==y.c&&x.e==y.e&&x.g==y.g;}
static void SetFPU(std::uint16_t control) {__asm {
 fninit
 fldcw word ptr control
 }}
static std::uint16_t Status() {std::uint16_t result;__asm {fnstsw word ptr result}return result;}
static std::uint16_t Control() {std::uint16_t result;__asm {fnstcw word ptr result}return result;}
int main() {
 const std::uint8_t bytes[]={
#include "constructor-body.inc"
 };
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;
 std::memcpy(code,bytes,sizeof(bytes));
 for(auto p:patches) {auto value=Address(p.va);std::memcpy(code+p.offset,&value,4);}
 for(auto c:calls) {auto relative=U(Function(c.target))-U(code+c.offset+5);std::memcpy(code+c.offset+1,&relative,4);}
 DWORD old;if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),code,4096);
 reiv::game::PlayerPedConstructionDependencies d{R,W,B,Address,Base,Embedded,ValueCtor,Block1,Block2,Resolve,Link,LinkDone,Init,Random,Hash,Value,Flags,Reset,IndexValue,Message,Allocate,Create,Flag};
 using Native=void*(__thiscall*)(void*,unsigned,unsigned,unsigned);
 unsigned count=0;
 for(unsigned control:{0x007Fu,0x027Fu,0x037Fu,0x047Fu,0x067Fu,0x077Fu,0x087Fu,0x0A7Fu,0x0B7Fu,0x0C7Fu,0x0E7Fu,0x0F7Fu}) for(unsigned sample:{0u,1u,16384u,32767u}) for(scenario=0;scenario<1024;++scenario) {
  randomSample=sample;
  Seed();SetFPU(static_cast<std::uint16_t>(control));auto result=reinterpret_cast<Native>(code)(player.data(),0x1234ABCD,0x98765432,0x76543210);
  const auto sw=Status(),cw=Control();auto reference=Capture();auto referenceTrace=trace;
  Seed();SetFPU(static_cast<std::uint16_t>(control));auto rebuilt=C::Construct(player.data(),0x1234ABCD,0x98765432,0x76543210,d);
  const auto sw2=Status(),cw2=Control();
  if(result!=rebuilt||!Equal(reference,Capture())||trace!=referenceTrace||sw!=sw2||cw!=cw2) {
   std::printf("failed scenario=%u control=%x sw=%x/%x cw=%x/%x trace=%zu/%zu\n",scenario,control,sw,sw2,cw,cw2,referenceTrace.size(),trace.size());return 3;
  }
  ++count;
 }
 VirtualFree(code,0,MEM_RELEASE);SetFPU(0x037F);std::printf("passed %u constructor comparisons including buffers globals callbacks FPU\n",count);return 0;
}
