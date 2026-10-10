#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestFilter
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestFilter;
} }

namespace reiv { namespace memory_map { namespace type_79a58e6f62bd66d6 {
inline constexpr char name[] = "rage::crmtRequestFilter";
inline constexpr char mangled[] = ".?AVcrmtRequestFilter@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequestSource<1>;rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c07f0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc07f0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd518u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6da4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_79a58e6f62bd66d6 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005104f0u, 0x001104f0u, 0x00eb6da4u, 0, "FUN_005104f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00510350u, 0x00110350u, 0x00eb6da4u, 1, "FUN_00510350", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00510620u, 0x00110620u, 0x00eb6da4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
