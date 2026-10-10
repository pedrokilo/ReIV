#pragma once
#include <cstdint>

namespace reiv { namespace game {
struct PlayerPedAccumulationGlobals {
    const std::uint32_t* value11DDE7C;
    const std::uint32_t* multiplierDCC5EC;
    const std::uint32_t* limitD81948;
    const std::uint32_t* resetD81950;
};
// Player receiver supported by the caller's virtual-slot74 type query.
// Original source class declaration and gameplay names remain unknown.
class PlayerPedAccumulation {public:

    // VA 0x009BF5F0. SSE instructions preserve NaNs, MXCSR, and store order.
    // COMISS runs before the EE0 store; an unmasked comparison exception must
    // therefore occur before that store. Unordered and <= skip the reset.
    static void AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals);

};
} }
