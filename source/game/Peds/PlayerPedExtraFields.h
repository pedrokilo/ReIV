#pragma once
#include <cstdint>

namespace reiv { namespace game {
struct PlayerPedExtraFieldsGlobals {
    const std::uint32_t* limitDECD60;
    const std::uint32_t* resetD81958;
};
// Player-flag guarded callers pass their preserved player receiver in ECX.
// These names refer to offsets; original defining C++ class names are inferred.
class PlayerPedExtraFields {
public:
    // VA 0x009BF5D0. The original defines AL only. Unordered COMISS returns one.
    static std::uint8_t TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals) {
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
    static void ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals) {
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
};
} }
