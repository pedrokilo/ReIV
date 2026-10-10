class CDynamicEntity;
class CMatrix;

namespace reiv { namespace game {
// Bridge to a real SDK/game instance. This is not a reconstructed object layout.
class CDynamicEntity {
public:
    CDynamicEntity() = delete;
    static bool OriginalAvailable();
    static ::CMatrix* GetBoneMatrix(::CDynamicEntity* entity, int boneID);
};
} }
