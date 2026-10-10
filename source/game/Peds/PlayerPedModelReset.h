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
class PlayerPedModelReset {
    static std::uint32_t Read(const void*p,unsigned offset){std::uint32_t v;std::memcpy(&v,static_cast<const unsigned char*>(p)+offset,4);return v;}
    static void Write(void*p,unsigned offset,std::uint32_t v){std::memcpy(static_cast<unsigned char*>(p)+offset,&v,4);}
    static void* Member(std::uint32_t bits){return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits+0x60u));}
public:
    // VA 0x009BF660. One byte-valued stack argument; original RET 4.
    // MOVSS global transfer is a bit copy, with no numeric float conversion.
    static void Reset(void* player,std::uint8_t argument,const PlayerPedModelResetDependencies& d){
        *d.globalF1D9D8=*d.sourceD50398;
        Write(player,0x24,Read(player,0x24)|1u);
        Write(player,0xA80,0);
        d.call8A92C0(player,0);
        d.call8A07E0(player,1);
        d.call8A70C0(player,0,0xFFFFFFFFu);
        d.call89C8B0(player,0xFFFFFFFFu);
        auto member=Read(player,0x228);
        Write(player,0x26C,Read(player,0x26C)|0x20000u);
        if(member&&member+0x60u)Write(Member(member),0x3D0,Read(Member(member),0x3D0)&~2u);
        d.virtualSlot68(player);
        Write(player,0x24,Read(player,0x24)|1u);
        if(!argument)d.call9BF0D0(player,1,0,1);
        member=Read(player,0x228);
        if(member&&member+0x60u)d.call8793F0(Member(member));
    }
};
} }
