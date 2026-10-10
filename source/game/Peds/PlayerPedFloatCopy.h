#pragma once

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error CPlayerPed float-copy operations require MSVC x86 inline assembly.
#endif

namespace reiv::game::player_detail {
// VA 0x009C1D90 / slot 79 and VA 0x009C1DD0 / slot 80.
// The original uses x87 loads/stores for components 0 and 3, MOVSS for 1/2.
// Keep that distinction and the late load of component 3: memcpy, or loading
// all four components first, changes signalling NaNs and overlapping inputs.
// Assembly-specific reconstruction; the complete object layout is not inferred.
inline void CopyBlockEC0(void* object, const void* input) {
    __asm {
        mov ecx, object
        mov eax, input
        fld dword ptr [eax]
        movss xmm0, dword ptr [eax + 4]
        movss xmm1, dword ptr [eax + 8]
        fstp dword ptr [ecx + 0EC0h]
        movss dword ptr [ecx + 0EC4h], xmm0
        movss dword ptr [ecx + 0EC8h], xmm1
        fld dword ptr [eax + 12]
        fstp dword ptr [ecx + 0ECCh]
    }
}

inline void CopyBlockED0(void* object, const void* input) {
    __asm {
        mov ecx, object
        mov eax, input
        fld dword ptr [eax]
        movss xmm0, dword ptr [eax + 4]
        movss xmm1, dword ptr [eax + 8]
        fstp dword ptr [ecx + 0ED0h]
        movss dword ptr [ecx + 0ED4h], xmm0
        movss dword ptr [ecx + 0ED8h], xmm1
        fld dword ptr [eax + 12]
        fstp dword ptr [ecx + 0EDCh]
    }
}
}
