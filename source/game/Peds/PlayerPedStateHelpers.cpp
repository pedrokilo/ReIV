#include "game/Peds/PlayerPedStateHelpers.h"
#include <cstdint>
#include <cstring>

namespace reiv::game::player_detail {
void ClearState3D8(void* player, const StateHelperDependencies& d) {
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

__declspec(naked) void __fastcall StoreQuery7(void* player, const StateHelperDependencies* dependencies) {
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

__declspec(naked) void __fastcall StoreQuery8AndClearFlag(void* player, const StateHelperDependencies* dependencies) {
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
