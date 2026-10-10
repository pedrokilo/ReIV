#pragma once
#include <cstdint>
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player state helpers require MSVC x86.
#endif
namespace reiv::game::player_detail {
using StateQueryCallback = float(__cdecl*)(std::uint32_t selector);
struct StateHelperDependencies {
    const volatile std::uint32_t* sourceD50398;
    volatile std::uint32_t* destinationF1D9D8;
    StateQueryCallback query962B20;
};
// Bodies have proved player receivers at original callsites; the original
// defining C++ class is not inferred from proximity. No live hooks are installed.
// Null player-info paths retain original low-memory fault behavior.
// VA 0x009BF070. MOVSS copies the global as bits before the state write.
inline void ClearState3D8(void* player, const StateHelperDependencies& d) {
    std::uint32_t info;
    std::memcpy(&info, static_cast<unsigned char*>(player) + 0x228, 4);
    const std::uint32_t member = info ? info + 0x60u : 0u;
    const auto p = reinterpret_cast<unsigned char*>(static_cast<std::uintptr_t>(member));
    if ((p[0x3D0] & 2) == 0) return;
    std::uint32_t state;
    std::memcpy(&state, p + 0x3D8, 4);
    if (!state) return;
    const auto bits = *d.sourceD50398;
    const std::uint32_t zero = 0;
    std::memcpy(p + 0x3D8, &zero, 4);
    *d.destinationF1D9D8 = bits;
}

// VA 0x009BF2D0. Preserve callback output in ST0 and the destination captured
// before the callback. A C++ float temporary can add an unwanted rounding store.
__declspec(naked) inline void __fastcall StoreQuery7(void* player, const StateHelperDependencies* dependencies) {
    __asm {
        push esi
        push edi
        mov edi, edx
        mov eax, dword ptr [ecx + 228h]
        test eax, eax
        jz query7null
        lea esi, [eax + 60h]
        jmp query7ready
    query7null:
        xor esi, esi
    query7ready:
        push 7
        call dword ptr [edi + 8]
        fstp dword ptr [esi + 3B4h]
        add esp, 4
        pop edi
        pop esi
        ret
    }
}
// VA 0x009BF310. The FSTP destination is latched; the flag destination is
// reloaded from player+228 after the callback, allowing dependency mutations.
__declspec(naked) inline void __fastcall StoreQuery8AndClearFlag(void* player, const StateHelperDependencies* dependencies) {
    __asm {
        push ebx
        push esi
        push edi
        mov ebx, edx
        mov edi, ecx
        mov eax, dword ptr [edi + 228h]
        test eax, eax
        jz query8null
        lea esi, [eax + 60h]
        jmp query8ready
    query8null:
        xor esi, esi
    query8ready:
        push 8
        call dword ptr [ebx + 8]
        fstp dword ptr [esi + 3E0h]
        mov eax, dword ptr [edi + 228h]
        add esp, 4
        test eax, eax
        pop edi
        pop esi
        pop ebx
        jz query8clearzero
        and dword ptr [eax + 430h], 0FFFFFF7Fh
        ret
    query8clearzero:
        xor eax, eax
        and dword ptr [eax + 3D0h], 0FFFFFF7Fh
        ret
    }
}
}
