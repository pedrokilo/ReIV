#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <xmmintrin.h>
#include "../../source/game/Peds/PlayerPedStateHelpers.h"
#include "../../build/player-state-fixture.h"
namespace pd=reiv::game::player_detail;
static unsigned char player[4096],a[4096],b[4096];
static unsigned source,destination,mutation,events[8],eventCount,valueBits;
static unsigned U(const void* p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void* p,unsigned off,unsigned value){memcpy(static_cast<unsigned char*>(p)+off,&value,4);}
static unsigned R(const void* p,unsigned off){unsigned v;memcpy(&v,static_cast<const unsigned char*>(p)+off,4);return v;}
static unsigned __cdecl Record(unsigned selector){
    events[eventCount++]=selector;events[eventCount++]=R(player,0x228);
    if(mutation&1)W(player,0x228,U(b));
    if(mutation&2){W(a,0x430,0xff00ff7f);W(b,0x430,0xabcdef80);}
    return valueBits;
}
__declspec(naked) static float __cdecl Query(unsigned selector){__asm{
    mov eax,dword ptr [esp+4]
    push eax
    call Record
    add esp,4
    push eax
    fld dword ptr [esp]
    add esp,4
    ret
}}
struct State{unsigned short status;unsigned mxcsr;};
static void Reset(unsigned short control,unsigned mxcsr){__asm{fninit}__asm{fldcw control}_mm_setcsr(mxcsr);}
static State Finish(){State s{};unsigned short status;__asm{fnstsw status}s.status=status;s.mxcsr=_mm_getcsr();return s;}
static void Seed(unsigned sample,unsigned pattern,unsigned branch){
    for(unsigned i=0;i<4096;++i){player[i]=static_cast<unsigned char>(i*37+sample*19);a[i]=static_cast<unsigned char>(i*17+sample*31);b[i]=static_cast<unsigned char>(i*23+sample*29);}
    W(player,0x228,U(a));W(a,0x430,(sample<<8)|(branch&1?2:0));W(a,0x438,branch&2?0x12345678:0);
    source=pattern;destination=0xabcdef01;eventCount=0;memset(events,0,sizeof events);
}
static void Rel(unsigned char* p,unsigned instruction,const void* target){unsigned d=U(target)-U(p+instruction+5);memcpy(p+instruction+1,&d,4);}
int main(){
    auto page=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!page)return 2;
    memcpy(page,FixtureClear,sizeof FixtureClear);memcpy(page+128,FixtureQuery7,sizeof FixtureQuery7);memcpy(page+256,FixtureQuery8,sizeof FixtureQuery8);
    unsigned src=U(&source),dst=U(&destination);memcpy(page+61,&src,4);memcpy(page+79,&dst,4);
    Rel(page+128,16,Query);Rel(page+128,36,Query);Rel(page+256,23,Query);
    DWORD old;if(!VirtualProtect(page,4096,PAGE_EXECUTE_READ,&old))return 3;FlushInstructionCache(GetCurrentProcess(),page,4096);
    using Native=void(__thiscall*)(void*);Native funcs[]={reinterpret_cast<Native>(page),reinterpret_cast<Native>(page+128),reinterpret_cast<Native>(page+256)};
    pd::StateHelperDependencies deps{&source,&destination,Query};
    const unsigned patterns[]={0,0x80000000,0x3f800000,0xbf800000,0x7f800000,0xff800000,0x7fc00001,0xffc12345,0x7f800001,0xff800001,1,0x80000001,0x007fffff,0x00800000,0x7f7fffff,0x3eaaaaab};
    const unsigned precisions[]={0,0x200,0x300};unsigned count=0,failures=0;
    for(unsigned method=0;method<3;++method)for(unsigned rounding=0;rounding<4;++rounding)for(unsigned precision:precisions)for(unsigned denorm=0;denorm<4;++denorm)
    for(unsigned pattern:patterns)for(mutation=0;mutation<4;++mutation)for(unsigned sample=0;sample<8;++sample){
        valueBits=pattern;const auto control=static_cast<unsigned short>(0x7f|precision|(rounding<<10));const auto mxcsr=0x1f80|(rounding<<13)|((denorm&1)?0x40:0)|((denorm&2)?0x8000:0);
        unsigned char expectedPlayer[4096],expectedA[4096],expectedB[4096];unsigned expectedEvents[8];
        Seed(sample,pattern,mutation);Reset(control,mxcsr);funcs[method](player);const auto original=Finish();
        memcpy(expectedPlayer,player,4096);memcpy(expectedA,a,4096);memcpy(expectedB,b,4096);memcpy(expectedEvents,events,sizeof events);
        const auto expectedSource=source,expectedDestination=destination,expectedCount=eventCount;
        Seed(sample,pattern,mutation);Reset(control,mxcsr);
        if(method==0)pd::ClearState3D8(player,deps);else if(method==1)pd::StoreQuery7(player,&deps);else pd::StoreQuery8AndClearFlag(player,&deps);
        const auto rebuilt=Finish();++count;
        if(memcmp(expectedPlayer,player,4096)||memcmp(expectedA,a,4096)||memcmp(expectedB,b,4096)||memcmp(expectedEvents,events,sizeof events)||expectedCount!=eventCount||expectedSource!=source||expectedDestination!=destination||original.status!=rebuilt.status||original.mxcsr!=rebuilt.mxcsr){
            ++failures;if(failures<5)printf("Mismatch method=%u rounding=%u precision=%u denorm=%u pattern=%08x mutation=%u sample=%u status=%04x/%04x\n",method,rounding,precision,denorm,pattern,mutation,sample,original.status,rebuilt.status);
        }
    }
    Reset(0x37f,0x1f80);VirtualFree(page,0,MEM_RELEASE);
    printf("{\"passed\":%s,\"comparisons\":%u,\"failures\":%u,\"scope\":\"three canonical complete caller bodies; controlled query callback, latched destination and receiver mutation, raw global bits, float edge patterns, PC/RC/DAZ/FTZ, full three buffers and FP state; no in-game calls\"}\n",failures?"false":"true",count,failures);
    return failures?1:0;
}
