#include "game/Peds/PlayerPedFloatCopy.h"


namespace reiv::game::player_detail {
void CopyBlockEC0(void* object, const void* input) {
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

void CopyBlockED0(void* object, const void* input) {
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
