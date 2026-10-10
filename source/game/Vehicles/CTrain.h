#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CTrain
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CTrain;
} }

namespace reiv { namespace memory_map { namespace type_b6da8e6926264365 {
inline constexpr char name[] = "CTrain";
inline constexpr char mangled[] = ".?AVCTrain@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CVehicle;CPhysical;CDynamicEntity;CEntity;CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a61cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a61cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec3374u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d78d4cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b6da8e6926264365 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 111u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0094ce40u, 0x0054ce40u, 0x00d78d4cu, 0, "FUN_0094ce40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48eb0u, 0x00648eb0u, 0x00d78d4cu, 1, "FUN_00a48eb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48e40u, 0x00648e40u, 0x00d78d4cu, 2, "FUN_00a48e40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a47a40u, 0x00647a40u, 0x00d78d4cu, 3, "FUN_00a47a40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1960u, 0x005e1960u, 0x00d78d4cu, 4, "FUN_009e1960", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e9e10u, 0x005e9e10u, 0x00d78d4cu, 5, "FUN_009e9e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1ed0u, 0x005e1ed0u, 0x00d78d4cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0410u, 0x005e0410u, 0x00d78d4cu, 7, "FUN_009e0410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0440u, 0x005e0440u, 0x00d78d4cu, 8, "FUN_009e0440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d78d4cu, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d78d4cu, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d78d4cu, 11, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089bbf0u, 0x0049bbf0u, 0x00d78d4cu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; set or clear flag 0x20 on isolated storage; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008b86d0u, 0x004b86d0u, 0x00d78d4cu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00949000u, 0x00549000u, 0x00d78d4cu, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e69e0u, 0x005e69e0u, 0x00d78d4cu, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e7cf0u, 0x005e7cf0u, 0x00d78d4cu, 16, "FUN_009e7cf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e22a0u, 0x005e22a0u, 0x00d78d4cu, 17, "FUN_009e22a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e18a0u, 0x005e18a0u, 0x00d78d4cu, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e6a40u, 0x005e6a40u, 0x00d78d4cu, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e05c0u, 0x005e05c0u, 0x00d78d4cu, 20, "FUN_009e05c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e04d0u, 0x005e04d0u, 0x00d78d4cu, 21, "FUN_009e04d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0490u, 0x005e0490u, 0x00d78d4cu, 22, "FUN_009e0490", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0610u, 0x005e0610u, 0x00d78d4cu, 23, "FUN_009e0610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0660u, 0x005e0660u, 0x00d78d4cu, 24, "FUN_009e0660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0690u, 0x005e0690u, 0x00d78d4cu, 25, "FUN_009e0690", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e06c0u, 0x005e06c0u, 0x00d78d4cu, 26, "FUN_009e06c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0bd0u, 0x005e0bd0u, 0x00d78d4cu, 27, "FUN_009e0bd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d78d4cu, 28, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0094ce70u, 0x0054ce70u, 0x00d78d4cu, 29, "FUN_0094ce70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447970u, 0x00047970u, 0x00d78d4cu, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete XOR AL,AL/RET 12 body; three synthetic arguments discarded; low-byte zero checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009d6170u, 0x005d6170u, 0x00d78d4cu, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c28820u, 0x00828820u, 0x00d78d4cu, 32, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0094a020u, 0x0054a020u, 0x00d78d4cu, 33, "FUN_0094a020", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1b70u, 0x005e1b70u, 0x00d78d4cu, 34, "FUN_009e1b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c83a0u, 0x005c83a0u, 0x00d78d4cu, 35, "FUN_009c83a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d78d4cu, 36, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d78d4cu, 37, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c91a0u, 0x005c91a0u, 0x00d78d4cu, 38, "FUN_009c91a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008b8fe0u, 0x004b8fe0u, 0x00d78d4cu, 39, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; read vector through both synthetic parent branches; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008b86c0u, 0x004b86c0u, 0x00d78d4cu, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d78d4cu, 41, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00949400u, 0x00549400u, 0x00d78d4cu, 42, "FUN_00949400", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48630u, 0x00648630u, 0x00d78d4cu, 43, "FUN_00a48630", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a486e0u, 0x006486e0u, 0x00d78d4cu, 44, "FUN_00a486e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48770u, 0x00648770u, 0x00d78d4cu, 45, "FUN_00a48770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c93b0u, 0x005c93b0u, 0x00d78d4cu, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0094bb60u, 0x0054bb60u, 0x00d78d4cu, 47, "FUN_0094bb60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004c78c0u, 0x000c78c0u, 0x00d78d4cu, 48, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d78d4cu, 49, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d78d4cu, 50, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0094a1e0u, 0x0054a1e0u, 0x00d78d4cu, 51, "FUN_0094a1e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d78d4cu, 52, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d78d4cu, 53, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009dfe70u, 0x005dfe70u, 0x00d78d4cu, 54, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a476b0u, 0x006476b0u, 0x00d78d4cu, 55, "FUN_00a476b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008b86f0u, 0x004b86f0u, 0x00d78d4cu, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48a40u, 0x00648a40u, 0x00d78d4cu, 57, "FUN_00a48a40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 58, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00949420u, 0x00549420u, 0x00d78d4cu, 59, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a47930u, 0x00647930u, 0x00d78d4cu, 60, "FUN_00a47930", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a47950u, 0x00647950u, 0x00d78d4cu, 61, "FUN_00a47950", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a47970u, 0x00647970u, 0x00d78d4cu, 62, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b30u, 0x00047b30u, 0x00d78d4cu, 63, "unknown_entry", "CPhysical::GetHealth", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CPhysical.h:63", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a49650u, 0x00649650u, 0x00d78d4cu, 64, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00948fd0u, 0x00548fd0u, 0x00d78d4cu, 65, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b40u, 0x00047b40u, 0x00d78d4cu, 66, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b50u, 0x00047b50u, 0x00d78d4cu, 67, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48550u, 0x00648550u, 0x00d78d4cu, 68, "FUN_00a48550", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a4a320u, 0x0064a320u, 0x00d78d4cu, 69, "FUN_00a4a320", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a4a890u, 0x0064a890u, 0x00d78d4cu, 70, "FUN_00a4a890", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a4af20u, 0x0064af20u, 0x00d78d4cu, 71, "FUN_00a4af20", "CPhysical::_ProcessWater;CPhysical::ProcessWater", "docs/MemoryMap/virtual_slots.csv; sdk_exact_function_address contrib/IV SDK/IV-SDK-main/include/CPhysical.h:52;sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CPhysical.h:58", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c8a70u, 0x005c8a70u, 0x00d78d4cu, 72, "FUN_009c8a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c52c0u, 0x005c52c0u, 0x00d78d4cu, 73, "FUN_009c52c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c5360u, 0x005c5360u, 0x00d78d4cu, 74, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c8d80u, 0x005c8d80u, 0x00d78d4cu, 75, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c5370u, 0x005c5370u, 0x00d78d4cu, 76, "FUN_009c5370", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c8dc0u, 0x005c8dc0u, 0x00d78d4cu, 77, "FUN_009c8dc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c53c0u, 0x005c53c0u, 0x00d78d4cu, 78, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c8f30u, 0x005c8f30u, 0x00d78d4cu, 79, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009d4a50u, 0x005d4a50u, 0x00d78d4cu, 80, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c5430u, 0x005c5430u, 0x00d78d4cu, 81, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c9020u, 0x005c9020u, 0x00d78d4cu, 82, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c9210u, 0x005c9210u, 0x00d78d4cu, 83, "FUN_009c9210", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c9450u, 0x005c9450u, 0x00d78d4cu, 84, "FUN_009c9450", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00949b70u, 0x00549b70u, 0x00d78d4cu, 85, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 86, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c28820u, 0x00828820u, 0x00d78d4cu, 87, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 88, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d78d4cu, 89, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00949450u, 0x00549450u, 0x00d78d4cu, 90, "FUN_00949450", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009d25d0u, 0x005d25d0u, 0x00d78d4cu, 91, "FUN_009d25d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d78d4cu, 92, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d78d4cu, 93, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d78d4cu, 94, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 95, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c4c720u, 0x0084c720u, 0x00d78d4cu, 96, "FUN_00c4c720", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c71460u, 0x00871460u, 0x00d78d4cu, 97, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009cc990u, 0x005cc990u, 0x00d78d4cu, 98, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d78d4cu, 99, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c28820u, 0x00828820u, 0x00d78d4cu, 100, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009d5fc0u, 0x005d5fc0u, 0x00d78d4cu, 101, "FUN_009d5fc0", "CVehicle::Fix", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CVehicle.h:570", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c28820u, 0x00828820u, 0x00d78d4cu, 102, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 103, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c28820u, 0x00828820u, 0x00d78d4cu, 104, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00948fe0u, 0x00548fe0u, 0x00d78d4cu, 105, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d78d4cu, 106, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c7380u, 0x005c7380u, 0x00d78d4cu, 107, "FUN_009c7380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009ca710u, 0x005ca710u, 0x00d78d4cu, 108, "FUN_009ca710", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009ca8e0u, 0x005ca8e0u, 0x00d78d4cu, 109, "FUN_009ca8e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d78d4cu, 110, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
