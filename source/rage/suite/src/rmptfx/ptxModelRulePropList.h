#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxModelRulePropList
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ptxModelRulePropList;
} }

namespace reiv { namespace memory_map { namespace type_9f340607b45a6f4a {
inline constexpr char name[] = "rage::ptxModelRulePropList";
inline constexpr char mangled[] = ".?AVptxModelRulePropList@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ptxRulePropList;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c2648u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc2648u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00740u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb8924u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_9f340607b45a6f4a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0056a8c0u, 0x0016a8c0u, 0x00eb8924u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0056a5c0u, 0x0016a5c0u, 0x00eb8924u, 1, "FUN_0056a5c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0056a8b0u, 0x0016a8b0u, 0x00eb8924u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
