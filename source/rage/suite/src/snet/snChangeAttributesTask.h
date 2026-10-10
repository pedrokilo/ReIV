#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::snChangeAttributesTask
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class snChangeAttributesTask;
} }

namespace reiv { namespace memory_map { namespace type_2f6d2d98db0f3b7d {
inline constexpr char name[] = "rage::snChangeAttributesTask";
inline constexpr char mangled[] = ".?AVsnChangeAttributesTask@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::snTask;rage::rlTask<rage::snSession>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c143cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc143cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00fc0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb8fd8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_2f6d2d98db0f3b7d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0057a530u, 0x0017a530u, 0x00eb8fd8u, 0, "FUN_0057a530", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0053cb80u, 0x0013cb80u, 0x00eb8fd8u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0057d810u, 0x0017d810u, 0x00eb8fd8u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0057d990u, 0x0017d990u, 0x00eb8fd8u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00eb8fd8u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0057d8a0u, 0x0017d8a0u, 0x00eb8fd8u, 5, "FUN_0057d8a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
