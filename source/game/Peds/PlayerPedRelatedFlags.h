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
class PlayerPedRelatedFlags {
    static std::uint32_t Read(const void* p, std::uint32_t off) { std::uint32_t x; std::memcpy(&x,static_cast<const unsigned char*>(p)+off,4);return x; }
    static void Write(void* p, std::uint32_t off, std::uint32_t x) { std::memcpy(static_cast<unsigned char*>(p)+off,&x,4); }
public:
    // 0x009BF250: complete caller. Player receiver confirmed, original declaring class unknown.
    // Returns opaque EAX bits to preserve every original return path, without native type claims.
    // Dependencies are supplied explicitly; isolated sequential fixtures only.
    static std::uint32_t UpdateRaw(void* player,const PlayerPedRelatedFlagDependencies& deps) {
        static_assert(sizeof(void*)==4,"Related flags preserve x86 pointer/return bits.");
        std::uint32_t result=0;
        for(std::uint32_t index=0;index<7;++index) {
            const auto block=deps.getBlock4389D0(player);
            const auto receiver=Read(block,0x3D4)*std::uint32_t{0x5C}+deps.base1662178;
            auto candidate=deps.enumerateA66B70(receiver,index);
            result=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(candidate));
            if(!candidate||*(static_cast<unsigned char*>(candidate)+0xA70)==2)continue;
            deps.virtualSlot12(player,1);
            if((*(static_cast<unsigned char*>(candidate)+0x26C)&4)==0)Write(candidate,0x24,Read(candidate,0x24)|1);
            result=((std::uint32_t{deps.flags16180E0[index]}<<12)^Read(candidate,0x260))&0x1000;
            Write(candidate,0x260,Read(candidate,0x260)^result);
        }
        return result;
    }
};
}
