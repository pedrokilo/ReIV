#include "game/Peds/PlayerPedReferenceClear.h"
#include <cstdint>
#include <cstring>

namespace reiv { namespace game {
    // VA 0x009BEED0. Zero is written after the external call, including if
    // the external call rewrites the pointer field. No complete layout claimed.
void PlayerPedReferenceClear::ClearFieldE74(void* object,const PlayerPedReferenceClearDependencies& d) {
        auto field=reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(object)+0xE74);
        std::uint32_t value;std::memcpy(&value,field,4);
        if(value){
            d.call9E6580(reinterpret_cast<void*>(static_cast<std::uintptr_t>(value)),field);
            const std::uint32_t zero=0;std::memcpy(field,&zero,4);
        }
    }
} }
