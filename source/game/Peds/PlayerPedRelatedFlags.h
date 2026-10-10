#pragma once
#include <cstdint>
#include <cstring>
namespace reiv::game {
struct PlayerPedRelatedFlagDependencies {
    const void* (*getBlock4389D0)(void* player);
    void* (*enumerateA66B70)(std::uint32_t receiverBits, std::uint32_t index);
    void (*virtualSlot12)(void* player, std::uint32_t argument);
    std::uint32_t base1662178;
    const std::uint8_t* flags16180E0; // Seven original bytes; read after the virtual callback.
};
class PlayerPedRelatedFlags {    static std::uint32_t Read(const void* p, std::uint32_t off);    static void Write(void* p, std::uint32_t off, std::uint32_t x);public:

    // 0x009BF250: complete caller. Player receiver confirmed, original declaring class unknown.
    // Returns opaque EAX bits to preserve every original return path, without native type claims.
    // Dependencies are supplied explicitly; isolated sequential fixtures only.
    static std::uint32_t UpdateRaw(void* player,const PlayerPedRelatedFlagDependencies& deps);

};
}
