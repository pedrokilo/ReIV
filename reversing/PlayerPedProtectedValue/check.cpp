#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include "../../source/game/Peds/PlayerPedProtectedValue.h"
#include "../../build/player-protected-fixture.h"
namespace pd = reiv::game::player_detail;
static unsigned protectedBits, mode, callbackFailures, eventCount, events[8];
static unsigned __stdcall WriteMock(unsigned handle,unsigned offset,unsigned bits) {
    if(handle!=0x11223344||offset)++callbackFailures;
    events[eventCount++]=0x5021;events[eventCount++]=bits;
    protectedBits=bits;
    return 0xabcdef01;
}
static unsigned __stdcall ReadMock(unsigned handle,unsigned offset,unsigned* bits) {
    if(handle!=0x11223344||offset||*bits!=0)++callbackFailures;
    events[eventCount++]=0x5020;
    if(!mode)*bits=protectedBits;
    return 0xabcdef02;
}
static void Reset(unsigned short control,unsigned mxcsr) {
    __asm { fninit }
    __asm { fldcw control }
    _mm_setcsr(mxcsr);
}
struct State {
    unsigned short status;
    unsigned mxcsr, stored, count, failures, log[8];
};
static State Finish() {
    State s{};unsigned short status;
    __asm { fnstsw status }
    s.status=status;s.mxcsr=_mm_getcsr();s.stored=protectedBits;
    s.count=eventCount;s.failures=callbackFailures;memcpy(s.log,events,sizeof events);
    return s;
}
static void Begin(unsigned bits,unsigned short control,unsigned mxcsr) {
    protectedBits=bits;callbackFailures=0;eventCount=0;memset(events,0,sizeof events);
    Reset(control,mxcsr);
}
static void Rel(unsigned char* code,unsigned instruction,const void* target) {
    const auto displacement=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(target)-reinterpret_cast<std::uintptr_t>(code+instruction+5));
    memcpy(code+instruction+1,&displacement,4);
}
static void Absolute(unsigned char* code,unsigned offset,const void* target) {
    const auto address=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(target));
    memcpy(code+offset,&address,4);
}
int main() {
    auto page=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));
    if(!page)return 2;
    unsigned char* funcs[7];for(unsigned i=0;i<7;++i)funcs[i]=page+i*256;
    memcpy(funcs[0],FixtureWrite,sizeof FixtureWrite);memcpy(funcs[1],FixtureRead,sizeof FixtureRead);
    memcpy(funcs[2],FixtureFlags,sizeof FixtureFlags);memcpy(funcs[3],FixtureSet60,sizeof FixtureSet60);
    memcpy(funcs[4],FixtureSet61,sizeof FixtureSet61);memcpy(funcs[5],FixtureAdd62,sizeof FixtureAdd62);
    memcpy(funcs[6],FixtureGet63,sizeof FixtureGet63);
    Rel(funcs[0],25,WriteMock);Rel(funcs[1],15,ReadMock);
    Absolute(funcs[2],4,&pd::FlagThreshold50);Absolute(funcs[2],32,&pd::FlagThreshold100);
    Rel(funcs[3],17,funcs[0]);Rel(funcs[3],32,funcs[2]);
    Rel(funcs[4],17,funcs[0]);Rel(funcs[4],32,funcs[2]);
    Rel(funcs[5],12,funcs[1]);Rel(funcs[5],31,funcs[0]);Rel(funcs[5],46,funcs[2]);
    Rel(funcs[6],6,funcs[1]);
    DWORD protection;if(!VirtualProtect(page,4096,PAGE_EXECUTE_READ,&protection))return 3;
    FlushInstructionCache(GetCurrentProcess(),page,4096);
    using Set = void(__thiscall*)(void*,float);
    using SetTwo = void(__thiscall*)(void*,float,unsigned);
    using Get = float(__thiscall*)(void*);
    using Write = void*(__thiscall*)(void*,float);
    const unsigned patterns[]={0,0x80000000,0x3f800000,0xbf800000,0x42480000,0x42c80000,0x4247ffff,0x42480001,0x42c7ffff,0x42c80001,0x7f800000,0xff800000,0x7fc00001,0xffc12345,0x7f800001,0xff800001,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0x3eaaaaab};
    const unsigned precisions[]={0,0x200,0x300};
    pd::ProtectedCallbacks deps{WriteMock,ReadMock};
    unsigned comparisons=0,failures=0,counts[7]{};
    for(unsigned method=0;method<7;++method)
    for(unsigned rounding=0;rounding<4;++rounding)
    for(unsigned precision=0;precision<3;++precision)
    for(unsigned denorm=0;denorm<4;++denorm)
    for(mode=0;mode<2;++mode)
    for(unsigned p=0;p<sizeof(patterns)/sizeof(*patterns);++p)
    for(unsigned initial=0;initial<sizeof(patterns)/sizeof(*patterns);++initial) {
        unsigned char a[4096],b[4096];for(unsigned i=0;i<sizeof a;++i)a[i]=static_cast<unsigned char>(i*37+p*19);
        unsigned handle=0x11223344;memcpy(a+0xeac,&handle,4);memcpy(b,a,sizeof a);
        float value;memcpy(&value,&patterns[p],4);
        const auto control=static_cast<unsigned short>(0x7f|precisions[precision]|rounding<<10);
        const auto mxcsr=0x1f80|rounding<<13|((denorm&1)?0x40:0)|((denorm&2)?0x8000:0);
        float originalResult=0,rebuiltResult=0;void* originalPointer=nullptr;void* rebuiltPointer=nullptr;
        Begin(patterns[initial],control,mxcsr);
        switch(method) {
        case 0: reinterpret_cast<Set>(funcs[3])(a,value);break;
        case 1: reinterpret_cast<SetTwo>(funcs[4])(a,value,patterns[(p+7)%22]);break;
        case 2: reinterpret_cast<Set>(funcs[5])(a,value);break;
        case 3: originalResult=reinterpret_cast<Get>(funcs[6])(a);break;
        case 4: reinterpret_cast<Set>(funcs[2])(a,value);break;
        case 5: originalPointer=reinterpret_cast<Write>(funcs[0])(a+0xeac,value);break;
        case 6: originalResult=reinterpret_cast<Get>(funcs[1])(a+0xeac);break;
        }
        const auto original=Finish();
        Begin(patterns[initial],control,mxcsr);
        switch(method) {
        case 0: pd::SetProtectedAndFlags(b,&deps,value);break;
        case 1: pd::SetProtectedAndFlagsWithUnused(b,&deps,value,patterns[(p+7)%22]);break;
        case 2: pd::AddProtectedAndFlags(b,&deps,value);break;
        case 3: rebuiltResult=pd::GetPlayerProtected(b,&deps);break;
        case 4: pd::UpdateValueFlags(b,nullptr,value);break;
        case 5: rebuiltPointer=pd::WriteProtected(b+0xeac,&deps,value);break;
        case 6: rebuiltResult=pd::ReadProtected(b+0xeac,&deps);break;
        }
        const auto rebuilt=Finish();++comparisons;++counts[method];
        if(original.failures||rebuilt.failures||memcmp(a,b,sizeof a)||memcmp(&original,&rebuilt,sizeof original)||memcmp(&originalResult,&rebuiltResult,4)||
            (method==5&&(originalPointer!=a+0xeac||rebuiltPointer!=b+0xeac))) {
            ++failures;if(failures<5)printf("Mismatch method=%u rounding=%u precision=%u denorm=%u mode=%u p=%u initial=%u status=%04x/%04x memory=%d state=%d\n",method,rounding,precision,denorm,mode,p,initial,original.status,rebuilt.status,memcmp(a,b,sizeof a),memcmp(&original,&rebuilt,sizeof original));
        }
    }
    Reset(0x37f,0x1f80);VirtualFree(page,0,MEM_RELEASE);
    printf("{\"passed\":%s,\"comparisons\":%u,\"failures\":%u,\"comparisons_per_body\":%u,\"scope\":\"seven canonical bodies with patched explicit dependencies; mocked xlive callbacks; complete object and callback log, x87/MXCSR, float edge cases and rounding; no in-game calls\"}\n",failures?"false":"true",comparisons,failures,counts[0]);
    return failures?1:0;
}
