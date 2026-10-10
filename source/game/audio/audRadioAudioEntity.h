#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audRadioAudioEntity
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audRadioAudioEntity;
} }

namespace reiv { namespace memory_map { namespace type_35966349a345dd3c {
inline constexpr char name[] = "audRadioAudioEntity";
inline constexpr char mangled[] = ".?AVaudRadioAudioEntity@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "audGtaAudioEntity;rage::audEntity";
inline constexpr std::uint32_t type_descriptor_va = 0x00f1cc38u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b1cc38u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ec09dcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d5ad6cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_35966349a345dd3c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00816210u, 0x00416210u, 0x00d5ad6cu, 0, "FUN_00816210", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00815650u, 0x00415650u, 0x00d5ad6cu, 1, "FUN_00815650", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00815760u, 0x00415760u, 0x00d5ad6cu, 2, "FUN_00815760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00816ee0u, 0x00416ee0u, 0x00d5ad6cu, 3, "FUN_00816ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0092c4d0u, 0x0052c4d0u, 0x00d5ad6cu, 4, "FUN_0092c4d0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 8 body; two explicit synthetic stack arguments discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d5ad6cu, 5, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d5ad6cu, 6, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00824eb0u, 0x00424eb0u, 0x00000000u, -1, "audRadioAudioEntity::RetuneRadioUpDown", "audRadioAudioEntity::RetuneRadioUpDown", "contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV/audRadioAudioEntity.cpp:38; plugin_iv_unique_pattern_not_validated", AddressOrigin::PluginIvPatternReference, false, false, false},
    {0x00824100u, 0x00424100u, 0x00000000u, -1, "audRadioAudioEntity::CanRetune", "audRadioAudioEntity::CanRetune", "contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV/audRadioAudioEntity.cpp:50; plugin_iv_unique_pattern_not_validated", AddressOrigin::PluginIvPatternReference, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
