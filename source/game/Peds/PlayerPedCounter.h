#pragma once
#include <cstdint>

namespace reiv { namespace game {
// Candidate reconstruction of RVA 0x005BE610 and slot 73 RVA 0x005BE770.
// Dependency callbacks must implement the original contracts; no hooks installed.
// The complete CPlayerPed layout and the dependent methods remain unreconstructed.
struct PlayerPedCounterDependencies {
    std::uint8_t (*query426910)(void* receiver, std::uint32_t id, std::uint32_t argument);
    void* (*resolve9BE5D0)(void* player);
    std::uint8_t (*state9C2720)(void* receiver, std::uint32_t* value, std::uint8_t* flag);
    std::uint32_t (*ticks448330)();
    void (*before8A3990)(void* player);
    const volatile std::uint8_t* thresholdF2F067;
};

class PlayerPedCounter {
public:
    // RVA 0x005BE610. Unsigned arithmetic preserves x86 counter overflow.
    static void Update(void* player, const PlayerPedCounterDependencies& d);
    // RVA 0x005BE770, CPlayerPed virtual slot 73.
    static void UpdateSlot73(void* player, const PlayerPedCounterDependencies& d);
};
} }
