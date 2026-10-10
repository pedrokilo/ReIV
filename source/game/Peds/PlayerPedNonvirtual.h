#pragma once
#include <cstdint>
#include <cstring>

namespace reiv { namespace game {
// Nonvirtual routines called with the player receiver by virtual slot 29.
// Names describe machine behavior. Defining original C++ class is not recovered.
// External callbacks are explicit contracts; no native hooks are installed.
struct PlayerPedNonvirtualDependencies {
    void* (*resolve7C3900)();
    void (*call9A9EF0)(void* receiver, std::uint32_t argument);
};
struct PlayerPedInitializationDependencies {
    std::uint32_t table1662170;
    void (*resetA677D0)(void* receiver, std::uint32_t, std::uint32_t);
    std::uint32_t (*createA66F20)(void* player);
    void (*linkA67AA0)(void* receiver, void* player);
    void (*startA67D70)(void* receiver);
};
class PlayerPedNonvirtual {    static std::uint32_t R(const void* p, unsigned off);    static void W(void* p, unsigned off, std::uint32_t value);    static void* Pointer(std::uint32_t bits);    static void* LinkReceiver(void* player);    static bool Enabled(const void* player);public:

    // VA 0x009BE4C0. Captured write destination survives create callback.
    // Null dependent pointers remain invalid, as in the original low-address accesses.
    static void InitializeRelations(void* player, const PlayerPedInitializationDependencies& d);
    // VA 0x009BE5D0; original tail-calls global helper 0x007C3900.
    static void* ResolveIfPlayerFlags(const void* player, const PlayerPedNonvirtualDependencies& d);
    // VA 0x009BEE70; original passes receiver+0x2B0 and one zero argument.
    static void CallBlockIfPlayerFlags(void* player, const PlayerPedNonvirtualDependencies& d);

};
} }
