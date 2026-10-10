#include "game/Peds/PlayerPedAccumulation.h"
#include <cstdint>

namespace reiv { namespace game {
    // VA 0x009BF5F0. SSE instructions preserve NaNs, MXCSR, and store order.
    // COMISS runs before the EE0 store; an unmasked comparison exception must
    // therefore occur before that store. Unordered and <= skip the reset.
void PlayerPedAccumulation::AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals) {
        const auto value=globals.value11DDE7C;
        const auto multiplier=globals.multiplierDCC5EC;
        const auto limit=globals.limitD81948;
        const auto reset=globals.resetD81950;
        __asm {
            mov ecx, object
            mov eax, value
            movss xmm0, dword ptr [eax]
            mov eax, multiplier
            mulss xmm0, dword ptr [eax]
            addss xmm0, dword ptr [ecx+0EE0h]
            mov eax, limit
            comiss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EE0h], xmm0
            jbe accumulation_done
            mov eax, reset
            movss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EE4h], xmm0
            xorps xmm0, xmm0
            movss dword ptr [ecx+0EE0h], xmm0
        accumulation_done:
        }
    }
} }
