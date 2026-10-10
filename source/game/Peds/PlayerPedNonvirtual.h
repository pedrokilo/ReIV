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
class PlayerPedNonvirtual {
    static std::uint32_t R(const void* p, unsigned off) {
        std::uint32_t v; std::memcpy(&v,static_cast<const std::uint8_t*>(p)+off,4); return v;
    }
    static void W(void* p, unsigned off, std::uint32_t value) {
        std::memcpy(static_cast<std::uint8_t*>(p)+off,&value,4);
    }
    static void* Pointer(std::uint32_t bits) {return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits));}
    static void* LinkReceiver(void* player) {
        const auto bits=R(player,0x228);return Pointer(bits?bits+0x60u:0u);
    }
    static bool Enabled(const void* player) {
        auto bytes=static_cast<const std::uint8_t*>(player);
        return bytes[0x218]==0 && bytes[0x219]!=0;
    }
public:
    // VA 0x009BE4C0. Captured write destination survives create callback.
    // Null dependent pointers remain invalid, as in the original low-address accesses.
    static void InitializeRelations(void* player, const PlayerPedInitializationDependencies& d) {
        const auto oldHandle=R(LinkReceiver(player),0x3D4);
        if(!(oldHandle&0x80000000u)) {
            auto receiver=Pointer(d.table1662170+oldHandle*0x5Cu);
            d.resetA677D0(receiver,1,1);
        }
        auto destination=LinkReceiver(player);
        const auto created=d.createA66F20(player);
        W(destination,0x3D4,created);
        auto handle=R(LinkReceiver(player),0x3D4);
        d.linkA67AA0(Pointer(d.table1662170+8u+handle*0x5Cu),player);
        handle=R(LinkReceiver(player),0x3D4);
        d.startA67D70(Pointer(d.table1662170+handle*0x5Cu));
        auto link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFEFFu);
        link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFDFFu);
        link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFBFFu);
    }
    // VA 0x009BE5D0; original tail-calls global helper 0x007C3900.
    static void* ResolveIfPlayerFlags(const void* player, const PlayerPedNonvirtualDependencies& d) {
        return Enabled(player)?d.resolve7C3900():nullptr;
    }
    // VA 0x009BEE70; original passes receiver+0x2B0 and one zero argument.
    static void CallBlockIfPlayerFlags(void* player, const PlayerPedNonvirtualDependencies& d) {
        if(Enabled(player)) {
            const auto receiverBits=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(player))+0x2B0u;
            d.call9A9EF0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(receiverBits)),0);
        }
    }
};
} }
