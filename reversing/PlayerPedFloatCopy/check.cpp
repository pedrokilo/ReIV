#include <Windows.h>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <xmmintrin.h>
#include "../../source/game/Peds/PlayerPedFloatCopy.h"

using Original = void(__thiscall*)(void*, const void*);
using Rebuilt = void(*)(void*, const void*);
struct State { unsigned short status; unsigned mxcsr; };
static void Reset(unsigned short control, unsigned mxcsr) {
    __asm { fninit }
    __asm { fldcw control }
    _mm_setcsr(mxcsr);
}
static State Finish() {
    State state{};
    unsigned short status;
    __asm { fnstsw status }
    state.status = status;
    state.mxcsr = _mm_getcsr();
    return state;
}
int main() {
    const unsigned char originalBytes[] = {
        0x8b,0x44,0x24,0x04,0xd9,0x00,0xf3,0x0f,0x10,0x40,0x04,
        0xf3,0x0f,0x10,0x48,0x08,0xd9,0x99,0xc0,0x0e,0x00,0x00,
        0xf3,0x0f,0x11,0x81,0xc4,0x0e,0x00,0x00,
        0xf3,0x0f,0x11,0x89,0xc8,0x0e,0x00,0x00,
        0xd9,0x40,0x0c,0xd9,0x99,0xcc,0x0e,0x00,0x00,0xc2,0x04,0x00
    };
    auto code = static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));
    if (!code) return 2;
    memcpy(code, originalBytes, sizeof originalBytes);
    memcpy(code+128, originalBytes, sizeof originalBytes);
    // The second original has exactly the same instructions with +0xED0 destinations.
    for (unsigned offset : {18u,26u,34u,43u}) code[128+offset] += 0x10;
    DWORD oldProtection;
    if (!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&oldProtection)) return 3;
    FlushInstructionCache(GetCurrentProcess(),code,4096);
    Original originals[] = {reinterpret_cast<Original>(code),reinterpret_cast<Original>(code+128)};
    Rebuilt rebuilt[] = {reiv::game::player_detail::CopyBlockEC0,reiv::game::player_detail::CopyBlockED0};
    const std::uint32_t patterns[] = {
        0,0x80000000,0x3f800000,0xbf800000,0x7f800000,0xff800000,
        0x7fc00001,0xffc12345,0x7f800001,0xff800001,1,0x80000001,
        0x007fffff,0x00800000,0x7f7fffff,0x3eaaaaab
    };
    unsigned comparisons=0,failures=0;
    for(unsigned method=0;method<2;++method)
    for(unsigned rounding=0;rounding<4;++rounding)
    for(unsigned precision=0;precision<3;++precision)
    for(unsigned denorm=0;denorm<4;++denorm)
    for(unsigned pattern=0;pattern<16;++pattern)
    for(int delta=-20;delta<=20;++delta) {
        unsigned char a[4096],b[4096];
        for(unsigned i=0;i<4096;++i)a[i]=static_cast<unsigned char>(i*37+pattern*19);
        const unsigned destination=method?0xed0:0xec0;
        const unsigned input=destination+delta;
        for(unsigned i=0;i<4;++i)memcpy(a+input+i*4,&patterns[(pattern+i*3)%16],4);
        memcpy(b,a,sizeof a);
        const unsigned precisions[]={0,0x200,0x300};
        const auto control=static_cast<unsigned short>(0x7f|precisions[precision]|(rounding<<10));
        const unsigned mxcsr=0x1f80|(rounding<<13)|((denorm&1)?0x40:0)|((denorm&2)?0x8000:0);
        Reset(control,mxcsr);originals[method](a,a+input);const auto originalState=Finish();
        Reset(control,mxcsr);rebuilt[method](b,b+input);const auto rebuiltState=Finish();
        ++comparisons;
        if(memcmp(a,b,sizeof a)||originalState.status!=rebuiltState.status||originalState.mxcsr!=rebuiltState.mxcsr) {
            ++failures;
            if(failures<5)printf("Mismatch method=%u rounding=%u precision=%u denorm=%u pattern=%u delta=%d status=%04x/%04x\n",method,rounding,precision,denorm,pattern,delta,originalState.status,rebuiltState.status);
        }
    }
    Reset(0x37f,0x1f80);
    VirtualFree(code,0,MEM_RELEASE);
    printf("{\"comparisons\":%u,\"failures\":%u,\"passed\":%s,\"scope\":\"copied original bytes, masked x87 exceptions, all four rounding modes, three precision modes, DAZ/FTZ, float edge cases, alias offsets -20 through +20; not in-game\"}\n",comparisons,failures,failures?"false":"true");
    return failures?1:0;
}
