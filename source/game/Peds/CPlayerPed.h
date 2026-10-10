#pragma once
#include <cstdint>
#include <cstring>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPlayerPed
// Own caller bodies have scoped reconstruction evidence; complete native layout/inheritance remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

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

namespace reiv { namespace memory_map { namespace type_05a24c6871b3ba9f {
inline constexpr char name[] = "CPlayerPed";
inline constexpr char mangled[] = ".?AVCPlayerPed@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPed;CPhysical;CDynamicEntity;CEntity;CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f317bcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b317bcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec58acu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d819c4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_05a24c6871b3ba9f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 82u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009c2260u, 0x005c2260u, 0x00d819c4u, 0, "FUN_009c2260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48eb0u, 0x00648eb0u, 0x00d819c4u, 1, "FUN_00a48eb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48e40u, 0x00648e40u, 0x00d819c4u, 2, "FUN_00a48e40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089ed00u, 0x0049ed00u, 0x00d819c4u, 3, "FUN_0089ed00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1960u, 0x005e1960u, 0x00d819c4u, 4, "FUN_009e1960", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e9e10u, 0x005e9e10u, 0x00d819c4u, 5, "FUN_009e9e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1ed0u, 0x005e1ed0u, 0x00d819c4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0410u, 0x005e0410u, 0x00d819c4u, 7, "FUN_009e0410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0440u, 0x005e0440u, 0x00d819c4u, 8, "FUN_009e0440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 11, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089e4b0u, 0x0049e4b0u, 0x00d819c4u, 12, "FUN_0089e4b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447ba0u, 0x00047ba0u, 0x00d819c4u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c0aa0u, 0x005c0aa0u, 0x00d819c4u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e69e0u, 0x005e69e0u, 0x00d819c4u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c520u, 0x0049c520u, 0x00d819c4u, 16, "FUN_0089c520", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c5a0u, 0x0049c5a0u, 0x00d819c4u, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e18a0u, 0x005e18a0u, 0x00d819c4u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c560u, 0x0049c560u, 0x00d819c4u, 19, "FUN_0089c560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e05c0u, 0x005e05c0u, 0x00d819c4u, 20, "FUN_009e05c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e04d0u, 0x005e04d0u, 0x00d819c4u, 21, "FUN_009e04d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0490u, 0x005e0490u, 0x00d819c4u, 22, "FUN_009e0490", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0610u, 0x005e0610u, 0x00d819c4u, 23, "FUN_009e0610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0660u, 0x005e0660u, 0x00d819c4u, 24, "FUN_009e0660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0690u, 0x005e0690u, 0x00d819c4u, 25, "FUN_009e0690", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e06c0u, 0x005e06c0u, 0x00d819c4u, 26, "FUN_009e06c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0bd0u, 0x005e0bd0u, 0x00d819c4u, 27, "FUN_009e0bd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00d819c4u, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c0b00u, 0x005c0b00u, 0x00d819c4u, 29, "FUN_009c0b00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447970u, 0x00047970u, 0x00d819c4u, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete XOR AL,AL/RET 12 body; three synthetic arguments discarded; low-byte zero checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a8cc0u, 0x004a8cc0u, 0x00d819c4u, 31, "FUN_008a8cc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089d360u, 0x0049d360u, 0x00d819c4u, 32, "FUN_0089d360", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a3850u, 0x004a3850u, 0x00d819c4u, 33, "FUN_008a3850", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1b70u, 0x005e1b70u, 0x00d819c4u, 34, "FUN_009e1b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a3b30u, 0x004a3b30u, 0x00d819c4u, 35, "FUN_008a3b30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 36, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d819c4u, 37, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a3ec0u, 0x004a3ec0u, 0x00d819c4u, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a5060u, 0x004a5060u, 0x00d819c4u, 39, "FUN_008a5060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447c10u, 0x00047c10u, 0x00d819c4u, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447c00u, 0x00047c00u, 0x00d819c4u, 41, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a6780u, 0x004a6780u, 0x00d819c4u, 42, "FUN_008a6780", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c100u, 0x0049c100u, 0x00d819c4u, 43, "FUN_0089c100", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008aac30u, 0x004aac30u, 0x00d819c4u, 44, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089f050u, 0x0049f050u, 0x00d819c4u, 45, "FUN_0089f050", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c200u, 0x0049c200u, 0x00d819c4u, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1e10u, 0x005c1e10u, 0x00d819c4u, 47, "FUN_009c1e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d819c4u, 48, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d819c4u, 49, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d819c4u, 50, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a8340u, 0x004a8340u, 0x00d819c4u, 51, "FUN_008a8340", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b90u, 0x00047b90u, 0x00d819c4u, 52, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447b90u, 0x00047b90u, 0x00d819c4u, 53, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a3250u, 0x004a3250u, 0x00d819c4u, 54, "FUN_008a3250", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008ac520u, 0x004ac520u, 0x00d819c4u, 55, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b20u, 0x00047b20u, 0x00d819c4u, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/game/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; comparison/bit/scalar bodies only; EDX/high return not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089efe0u, 0x0049efe0u, 0x00d819c4u, 57, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a15e0u, 0x004a15e0u, 0x00d819c4u, 58, "FUN_008a15e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a477f0u, 0x006477f0u, 0x00d819c4u, 59, "unknown_entry", "CPhysical::GetVelocity", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CPhysical.h:46", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1cf0u, 0x005c1cf0u, 0x00d819c4u, 60, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1d20u, 0x005c1d20u, 0x00d819c4u, 61, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1d50u, 0x005c1d50u, 0x00d819c4u, 62, "FUN_009c1d50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1ce0u, 0x005c1ce0u, 0x00d819c4u, 63, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a49650u, 0x00649650u, 0x00d819c4u, 64, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a7d70u, 0x004a7d70u, 0x00d819c4u, 65, "FUN_008a7d70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b40u, 0x00047b40u, 0x00d819c4u, 66, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/game/evidence/scalar-runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; comparison/bit/scalar bodies only; EDX/high return not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447b50u, 0x00047b50u, 0x00d819c4u, 67, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48550u, 0x00648550u, 0x00d819c4u, 68, "FUN_00a48550", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a9070u, 0x004a9070u, 0x00d819c4u, 69, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008ac540u, 0x004ac540u, 0x00d819c4u, 70, "FUN_008ac540", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089dce0u, 0x0049dce0u, 0x00d819c4u, 71, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009be780u, 0x005be780u, 0x00d819c4u, 72, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009be770u, 0x005be770u, 0x00d819c4u, 73, "FUN_009be770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d819c4u, 74, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1c90u, 0x005c1c90u, 0x00d819c4u, 75, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1ca0u, 0x005c1ca0u, 0x00d819c4u, 76, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; address_offset; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1cb0u, 0x005c1cb0u, 0x00d819c4u, 77, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; address_offset; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1cc0u, 0x005c1cc0u, 0x00d819c4u, 78, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; set_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1d90u, 0x005c1d90u, 0x00d819c4u, 79, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1dd0u, 0x005c1dd0u, 0x00d819c4u, 80, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1cd0u, 0x005c1cd0u, 0x00d819c4u, 81, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; set_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
