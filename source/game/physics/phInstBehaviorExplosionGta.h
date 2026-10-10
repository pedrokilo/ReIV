#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: phInstBehaviorExplosionGta
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class phInstBehaviorExplosionGta;
} }

namespace reiv { namespace memory_map { namespace type_0267dcc491b60b70 {
inline constexpr char name[] = "phInstBehaviorExplosionGta";
inline constexpr char mangled[] = ".?AVphInstBehaviorExplosionGta@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phInstBehavior";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a8f0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a8f0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec3544u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d796fcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0267dcc491b60b70 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 14u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0095c440u, 0x0055c440u, 0x00d796fcu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0095fe40u, 0x0055fe40u, 0x00d796fcu, 1, "FUN_0095fe40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0095fe10u, 0x0055fe10u, 0x00d796fcu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d796fcu, 3, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d796fcu, 4, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009600c0u, 0x005600c0u, 0x00d796fcu, 5, "FUN_009600c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0095e9e0u, 0x0055e9e0u, 0x00d796fcu, 6, "FUN_0095e9e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d796fcu, 7, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0059bc80u, 0x0019bc80u, 0x00d796fcu, 8, "FUN_0059bc80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d796fcu, 9, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0095ee50u, 0x0055ee50u, 0x00d796fcu, 10, "FUN_0095ee50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00961b50u, 0x00561b50u, 0x00d796fcu, 11, "FUN_00961b50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0095ed50u, 0x0055ed50u, 0x00d796fcu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0095ed70u, 0x0055ed70u, 0x00d796fcu, 13, "FUN_0095ed70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
