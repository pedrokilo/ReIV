#include <cstring>
#include "game/Peds/PlayerPedFloatCopy.h"
#include "game/Peds/PlayerPedDestruction.h"
#include "game/Peds/PlayerPedControl.h"
#include "game/Peds/PlayerPedCounter.h"
#include "game/Peds/PlayerPedProtectedValue.h"
#include "game/Peds/PlayerPedConstruction.h"
#include "game/Peds/PlayerPedNonvirtual.h"
#include "game/Peds/PlayerPedAccumulation.h"
#include "game/Peds/PlayerPedExtraFields.h"
#include "game/Peds/PlayerPedLayout.h"
#include "game/Peds/PlayerPedUpdate.h"
#include "game/Peds/PlayerPedModelReset.h"
#include "game/Peds/PlayerPedReferenceClear.h"
#include "game/Peds/PlayerPedValueAdjustment.h"
#include "game/Peds/PlayerPedInputSelection.h"
#include "game/Peds/PlayerPedStateHelpers.h"
#include "game/Peds/PlayerPedActionRange.h"
#include "game/Peds/PlayerPedActionRequest.h"
#include "game/Peds/PlayerPedActionSelection.h" // Embedded E7C receiver; not a CPlayerPed method.
#include "game/Peds/PlayerPedReceiverHelpers.h"
#include "game/Peds/PlayerPedRelatedFlags.h"

namespace reiv { namespace game {
// Reconstructed operations on an existing object. No complete layout or ownership.
// Offsets and names describe machine-code behavior, not gameplay semantics.
class CPlayerPed {
    static std::uint32_t Read(const void* object, std::uint32_t offset) {
        std::uint32_t value; std::memcpy(&value, static_cast<const unsigned char*>(object) + offset, 4); return value;
    }
    static void Write(void* object, std::uint32_t offset, std::uint32_t value) {
        std::memcpy(static_cast<unsigned char*>(object) + offset, &value, 4);
    }
public:
    CPlayerPed() = delete;
    // Additional confirmed own callers. ASM bindings are isolated single-thread fixtures.
    static void ClearReferenceE74(void* object, const PlayerPedReferenceClearDependencies& deps) { PlayerPedReferenceClear::ClearFieldE74(object, deps); }
    static std::uint8_t AdjustValueIsolated(void* object, std::uint32_t flag, float value) { return player_adjustment::Adjust(object, nullptr, flag, value); }
    static void SelectInputIsolated(void* object) { player_input::Select(object, nullptr); }
    static std::uint8_t ActInRangeIsolated(void* object, std::uint32_t flag) { return player_action_range::Act(object, nullptr, flag); }
    static std::uint8_t RequestActionIsolated(void* object, std::uint32_t flag, std::uint32_t argument) { return player_action_request::Act(object, nullptr, flag, argument); }
    // Receiver proven as player; convenience APIs do not recover original C++ declarations.
    // Raw returns preserve EAX bits without inventing native semantic return types.
    static std::uint8_t TestEitherPredicate(void* object) { return player_receiver_helpers::TestEitherPredicate(object, nullptr); }
    static std::uint32_t DispatchPairFirstRaw(void* object, std::uint32_t a1, std::uint32_t a2) { return player_receiver_helpers::SetPairFirstRaw(object, nullptr, a1, a2); }
    static std::uint32_t DispatchPairSecondRaw(void* object, std::uint32_t a1, std::uint32_t a2) { return player_receiver_helpers::SetPairSecondRaw(object, nullptr, a1, a2); }
    static std::uint32_t DispatchRelatedRaw(void* object) { return player_receiver_helpers::GetRelatedRaw(object, nullptr); }
    static std::uint8_t TestActionAllowed(void* object, std::uint32_t action, std::uint32_t flag) { return player_receiver_helpers::TestActionAllowed(object, nullptr, action, flag); }
    static std::uint32_t UpdateRelatedFlagsRaw(void* object, const PlayerPedRelatedFlagDependencies& deps) { return PlayerPedRelatedFlags::UpdateRaw(object, deps); }
    // Player-receiver routines; original declaring C++ class is not recovered.
    static void ClearState3D8(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::ClearState3D8(object, deps); }
    static void StoreQuery7(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::StoreQuery7(object, &deps); }
    static void StoreQuery8AndClearFlag(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::StoreQuery8AndClearFlag(object, &deps); }
    // VA 0x009BF660. Complete own caller; external reset methods remain callbacks.
    static void ResetModelState(void* object, std::uint8_t argument, const PlayerPedModelResetDependencies& deps) { PlayerPedModelReset::Reset(object, argument, deps); }
    // VA 0x009C0B00, slot 29. Complete ASM caller, isolated bindings only.
    // Shared player_update globals/callbacks require exclusive fixture ownership.
    static std::uint8_t UpdateIsolated(void* object) { return player_update::Update(object, nullptr); }
    // VA 0x009C1910; constructor body with explicit dependency contracts.
    static void* Construct(void* object, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3, const PlayerPedConstructionDependencies& deps) { return PlayerPedConstruction::Construct(object, a1, a2, a3, deps); }
    static void* ResolveIfPlayerFlags(const void* object, const PlayerPedNonvirtualDependencies& deps) { return PlayerPedNonvirtual::ResolveIfPlayerFlags(object, deps); }
    static void CallBlockIfPlayerFlags(void* object, const PlayerPedNonvirtualDependencies& deps) { PlayerPedNonvirtual::CallBlockIfPlayerFlags(object, deps); }
    static void InitializeRelations(void* object, const PlayerPedInitializationDependencies& deps) { PlayerPedNonvirtual::InitializeRelations(object, deps); }
    static void AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals) { PlayerPedAccumulation::AdvanceFieldEE0(object, globals); }
    static std::uint8_t TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals) { return PlayerPedExtraFields::TestFieldEE4(object, globals); }
    static void ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals) { PlayerPedExtraFields::ResetFieldEEC(object, globals); }
    // These reconstructed bodies require explicitly supplied external dependencies.
    // They do not resolve or install native game hooks automatically.
    static void Destroy(void* object, const PlayerPedDestructionDependencies& deps) { PlayerPedDestruction::Destroy(object, deps); }
    static void* DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& deps) { return PlayerPedDestruction::DestroyDeleting(object, flags, deps); }
    static std::uint32_t ApplyModel(void* object, std::uint32_t model, const PlayerPedControlDependencies& deps) { return PlayerPedControl::ApplyModel(object, model, deps); }
    static void* CreateControl(void* object, std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t e, std::uint32_t count, const PlayerPedControlDependencies& deps) { return PlayerPedControl::CreateControl(object, a, b, c, e, count, deps); }
    static void UpdateCounter(void* object, const PlayerPedCounterDependencies& deps) { PlayerPedCounter::Update(object, deps); }
    static void UpdateSlot73(void* object, const PlayerPedCounterDependencies& deps) { PlayerPedCounter::UpdateSlot73(object, deps); }
    static void SetProtectedAndFlags(void* object, float value, const player_detail::ProtectedCallbacks& deps) { player_detail::SetProtectedAndFlags(object, &deps, value); }
    static void SetProtectedAndFlagsWithUnused(void* object, float value, std::uint32_t unused, const player_detail::ProtectedCallbacks& deps) { player_detail::SetProtectedAndFlagsWithUnused(object, &deps, value, unused); }
    static void AddProtectedAndFlags(void* object, float value, const player_detail::ProtectedCallbacks& deps) { player_detail::AddProtectedAndFlags(object, &deps, value); }
    static float GetPlayerProtected(void* object, const player_detail::ProtectedCallbacks& deps) { return player_detail::GetPlayerProtected(object, &deps); }
    // VA 0x007BDC00 / slot 48; return-register bits, semantic type unknown.
    static std::uint32_t ReturnZeroSlot48() { return 0; }
    // VA 0x00CFAEE0 / slot 74; original defines AL only.
    static std::uint8_t ReturnOneSlot74() { return 1; }
    // VA 0x009C1C90, virtual slot 75.
    static std::uint32_t GetFieldEBC(const void* object) { return Read(object, 0xEBC); }
    // VA 0x009C1CA0, virtual slot 76.
    static void* GetBlockEC0(void* object) { return static_cast<unsigned char*>(object) + 0xEC0; }
    // VA 0x009C1CB0, virtual slot 77.
    static void* GetBlockED0(void* object) { return static_cast<unsigned char*>(object) + 0xED0; }
    // VA 0x009C1CC0, virtual slot 78.
    static void SetFieldEBC(void* object, std::uint32_t value) { Write(object, 0xEBC, value); }
    // VA 0x009C1D90 / slot 79; x87/SSE-specific implementation.
    static void CopyBlockEC0(void* object, const void* input) { player_detail::CopyBlockEC0(object, input); }
    // VA 0x009C1DD0 / slot 80; x87/SSE-specific implementation.
    static void CopyBlockED0(void* object, const void* input) { player_detail::CopyBlockED0(object, input); }
    // VA 0x009C1CD0, virtual slot 81.
    static void SetFieldEF0(void* object, std::uint32_t value) { Write(object, 0xEF0, value); }
};
} }
