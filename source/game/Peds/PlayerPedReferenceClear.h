#pragma once
#include <cstdint>
#include <cstring>
namespace reiv { namespace game {
struct PlayerPedReferenceClearDependencies {
    void (*call9E6580)(void* receiver,std::uint32_t* field); // thiscall receiver, RET 4
};
class PlayerPedReferenceClear {public:

    // VA 0x009BEED0. Zero is written after the external call, including if
    // the external call rewrites the pointer field. No complete layout claimed.
    static void ClearFieldE74(void* object,const PlayerPedReferenceClearDependencies& d);

};
} }
