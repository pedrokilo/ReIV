#pragma once
#include <cstdint>
#include <cstring>
namespace reiv { namespace game {
struct PlayerPedModelResetDependencies {
    const volatile std::uint32_t* sourceD50398;
    volatile std::uint32_t* globalF1D9D8;
    void (*call8A92C0)(void*,std::uint32_t);
    void (*call8A07E0)(void*,std::uint32_t);
    void (*call8A70C0)(void*,std::uint32_t,std::uint32_t);
    void (*call89C8B0)(void*,std::uint32_t);
    void (*virtualSlot68)(void*);
    void (*call9BF0D0)(void*,std::uint32_t,std::uint32_t,std::uint32_t);
    void (*call8793F0)(void*);
};
class PlayerPedModelReset {    static std::uint32_t Read(const void*p,unsigned offset);    static void Write(void*p,unsigned offset,std::uint32_t v);    static void* Member(std::uint32_t bits);public:

    // VA 0x009BF660. One byte-valued stack argument; original RET 4.
    // MOVSS global transfer is a bit copy, with no numeric float conversion.
    static void Reset(void* player,std::uint8_t argument,const PlayerPedModelResetDependencies& d);

};
} }
