#include "game/Peds/PlayerPedExtraFields.h"
#include <cstdint>

namespace reiv { namespace game {
    // VA 0x009BF5D0. The original defines AL only. Unordered COMISS returns one.
std::uint8_t PlayerPedExtraFields::TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals) {
        const auto limit=globals.limitDECD60;
        std::uint8_t result;
        __asm {
            mov ecx, object
            mov eax, limit
            movss xmm0, dword ptr [ecx+0EE4h]
            comiss xmm0, dword ptr [eax]
            jbe field_ee4_one
            mov result, 0
            jmp field_ee4_done
        field_ee4_one:
            mov result, 1
        field_ee4_done:
        }
        return result;
    }

    // VA 0x009BF640. Ordered zero/negative resets; unordered comparison skips.
void PlayerPedExtraFields::ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals) {
        const auto reset=globals.resetD81958;
        __asm {
            mov ecx, object
            xorps xmm0, xmm0
            comiss xmm0, dword ptr [ecx+0EECh]
            jb field_eec_done
            mov eax, reset
            movss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EECh], xmm0
        field_eec_done:
        }
    }
} }
