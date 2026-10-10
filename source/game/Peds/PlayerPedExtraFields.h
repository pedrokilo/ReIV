#pragma once
#include <cstdint>

namespace reiv { namespace game {
struct PlayerPedExtraFieldsGlobals {
    const std::uint32_t* limitDECD60;
    const std::uint32_t* resetD81958;
};
// Player-flag guarded callers pass their preserved player receiver in ECX.
// These names refer to offsets; original defining C++ class names are inferred.
class PlayerPedExtraFields {public:

    // VA 0x009BF5D0. The original defines AL only. Unordered COMISS returns one.
    static std::uint8_t TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals);
    // VA 0x009BF640. Ordered zero/negative resets; unordered comparison skips.
    static void ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals);

};
} }
