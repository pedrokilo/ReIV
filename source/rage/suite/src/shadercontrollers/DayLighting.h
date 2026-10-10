#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::DayLighting
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class DayLighting;
} }

namespace reiv { namespace memory_map { namespace type_4fbbfca0150fa52a {
inline constexpr char name[] = "rage::DayLighting";
inline constexpr char mangled[] = ".?AVDayLighting@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ShaderFragment;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c2704u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc2704u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00878u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb8c2cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_4fbbfca0150fa52a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00573350u, 0x00173350u, 0x00eb8c2cu, 0, "FUN_00573350", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00574cc0u, 0x00174cc0u, 0x00eb8c2cu, 1, "FUN_00574cc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb8c2cu, 2, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005732f0u, 0x001732f0u, 0x00eb8c2cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0052bb30u, 0x0012bb30u, 0x00eb8c2cu, 4, "FUN_0052bb30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00573310u, 0x00173310u, 0x00eb8c2cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00573340u, 0x00173340u, 0x00eb8c2cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
