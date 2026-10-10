#pragma once
#include <cstdint>
#include <cstring>

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
    static std::uint32_t Read32(const void* p, std::uint32_t offset) {
        std::uint32_t v; std::memcpy(&v, static_cast<const std::uint8_t*>(p) + offset, 4); return v;
    }
    static void Write32(void* p, std::uint32_t offset, std::uint32_t v) {
        std::memcpy(static_cast<std::uint8_t*>(p) + offset, &v, 4);
    }
    static std::uint8_t Read8(const void* p, std::uint32_t offset) {
        return static_cast<const std::uint8_t*>(p)[offset];
    }
    static void* Pointer(std::uint32_t bits) {
        return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits));
    }
    static void* QueryReceiver(void* player) {
        // x86 addition wraps; the original has no null-pointer fallback.
        return Pointer(Read32(player, 0x224) + 0x2E0u);
    }
public:
    // RVA 0x005BE610. Unsigned arithmetic preserves x86 counter overflow.
    static void Update(void* player, const PlayerPedCounterDependencies& d) {
        if (Read8(player, 0x219) == 0) return;
        void* receiver = QueryReceiver(player);
        if (d.query426910(receiver, 0x410, 0) == 0 &&
            d.query426910(receiver, 0x41E, 0) == 0) return;
        void* related = d.resolve9BE5D0(player);
        if (related == nullptr) return; // explicit original branch
        std::uint32_t value = 0;
        std::uint8_t flag = 0;
        bool eligible = true;
        bool stateEight = false;
        if (d.state9C2720(Pointer(Read32(player, 0x224)), &value, &flag) != 0) {
            eligible = value == 5 || value == 8;
            stateEight = value == 8;
        }
        if (d.query426910(QueryReceiver(player), 0x413, 0) != 0) {
            const auto delta = d.ticks448330();
            const auto bits = Read32(player, 0xEB0) - delta;
            Write32(player, 0xEB0, (bits & 0x80000000u) ? 0u : bits); // JNS
        } else if (!stateEight) {
            const auto delta = d.ticks448330();
            const auto bits = Read32(player, 0xEB0) + delta;
            // CMP bits,10000/JLE uses a signed comparison, even after overflow.
            Write32(player, 0xEB0, !(bits & 0x80000000u) && bits > 10000u ? 10000u : bits);
        }
        const auto difference = static_cast<std::uint8_t>(Read8(related, 0x26DE) ^ Read8(related, 0x26DC));
        const bool retain = eligible && (stateEight ||
            (difference > 100u && difference < *d.thresholdF2F067));
        Write32(player, 0xEB4, Read32(player, 0xEB0));
        if (!retain) Write32(player, 0xEB0, 0);
    }
    // RVA 0x005BE770, CPlayerPed virtual slot 73.
    static void UpdateSlot73(void* player, const PlayerPedCounterDependencies& d) {
        d.before8A3990(player);
        Update(player, d);
    }
};
} }
