#include "game/Peds/PlayerPedModelReset.h"
#include <cstdint>
#include <cstring>

namespace reiv { namespace game {
std::uint32_t PlayerPedModelReset::Read(const void*p,unsigned offset) {std::uint32_t v;std::memcpy(&v,static_cast<const unsigned char*>(p)+offset,4);return v;}

void PlayerPedModelReset::Write(void*p,unsigned offset,std::uint32_t v) {std::memcpy(static_cast<unsigned char*>(p)+offset,&v,4);}

void* PlayerPedModelReset::Member(std::uint32_t bits) {return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits+0x60u));}

    // VA 0x009BF660. One byte-valued stack argument; original RET 4.
    // MOVSS global transfer is a bit copy, with no numeric float conversion.
void PlayerPedModelReset::Reset(void* player,std::uint8_t argument,const PlayerPedModelResetDependencies& d) {
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
} }
