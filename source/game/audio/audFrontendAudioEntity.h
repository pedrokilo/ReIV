#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audFrontendAudioEntity
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audFrontendAudioEntity;
} }

namespace reiv { namespace memory_map { namespace type_ec7860ce5c130a16 {
inline constexpr char name[] = "audFrontendAudioEntity";
inline constexpr char mangled[] = ".?AVaudFrontendAudioEntity@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "audGtaAudioEntity;rage::audEntity";
inline constexpr std::uint32_t type_descriptor_va = 0x00f0fdb8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b0fdb8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ebf100u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d54d78u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ec7860ce5c130a16 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c877c0u, 0x008877c0u, 0x00d54d78u, 0, "FUN_00c877c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007b8d70u, 0x003b8d70u, 0x00d54d78u, 1, "FUN_007b8d70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007b8f60u, 0x003b8f60u, 0x00d54d78u, 2, "FUN_007b8f60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bb0e0u, 0x003bb0e0u, 0x00d54d78u, 3, "FUN_007bb0e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0092c4d0u, 0x0052c4d0u, 0x00d54d78u, 4, "FUN_0092c4d0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 8 body; two explicit synthetic stack arguments discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d54d78u, 5, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d54d78u, 6, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007ba330u, 0x003ba330u, 0x00000000u, -1, "audFrontendAudioEntity::StopLoadingTune", "audFrontendAudioEntity::StopLoadingTune", "contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV/audFrontendAudioEntity.cpp:20; plugin_iv_unique_pattern_not_validated", AddressOrigin::PluginIvPatternReference, false, false, false},
    {0x007b9a40u, 0x003b9a40u, 0x00000000u, -1, "audFrontendAudioEntity::TriggerMissionCompleteAudioEvent", "audFrontendAudioEntity::TriggerMissionCompleteAudioEvent", "contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV/audFrontendAudioEntity.cpp:24; plugin_iv_unique_pattern_not_validated", AddressOrigin::PluginIvPatternReference, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
