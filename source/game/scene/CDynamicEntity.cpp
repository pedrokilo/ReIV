#include "CDynamicEntity.h"
#include "../../core/OriginalCall.h"

namespace {
// Canonical EXE SHA-256: ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c.
// SDK: CDynamicEntity.h:11. RVA 0x005C7710, preferred-base VA 0x009C7710.
constexpr unsigned char getBoneMatrixBytes[] = {
    0x56,0x8b,0xf1,0x8b,0x06,0x8b,0x90,0xa0,0x00,0x00,0x00,0x57,0xff,0xd2,0x85,0xc0
};
constexpr reiv::original::FunctionAddress getBoneMatrix = {
    "CDynamicEntity::GetBoneMatrix", 0x005c7710u,
    getBoneMatrixBytes, sizeof(getBoneMatrixBytes),
    reiv::original::BindingState::StaticVerified
};
using GetBoneMatrixFunction = reiv::original::Thiscall<::CMatrix*, ::CDynamicEntity, int>;
}

bool reiv::game::CDynamicEntity::OriginalAvailable() {
    return original::Resolve<GetBoneMatrixFunction>(getBoneMatrix) != nullptr;
}

// 1.0.7.0: VA 0x009C7710 / RVA 0x005C7710. Original implementation; not reversed.
::CMatrix* reiv::game::CDynamicEntity::GetBoneMatrix(::CDynamicEntity* entity, int boneID) {
    if (!entity) return nullptr;
    const auto function = original::Resolve<GetBoneMatrixFunction>(getBoneMatrix);
    return function ? function(entity, boneID) : nullptr;
}
