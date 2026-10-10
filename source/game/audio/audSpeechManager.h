#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audSpeechManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audSpeechManager;
} }

namespace reiv { namespace memory_map { namespace type_ef779d5cff3c7c54 {
inline constexpr char name[] = "audSpeechManager";
inline constexpr char mangled[] = ".?AVaudSpeechManager@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audEntity";
inline constexpr std::uint32_t type_descriptor_va = 0x00f38ae8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b38ae8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecabf0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d964d4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ef779d5cff3c7c54 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ad2660u, 0x006d2660u, 0x00d964d4u, 0, "FUN_00ad2660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ad3fa0u, 0x006d3fa0u, 0x00d964d4u, 1, "FUN_00ad3fa0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce8280u, 0x008e8280u, 0x00d964d4u, 2, "FUN_00ce8280", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d964d4u, 3, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0092c4d0u, 0x0052c4d0u, 0x00d964d4u, 4, "FUN_0092c4d0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 8 body; two explicit synthetic stack arguments discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d964d4u, 5, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
