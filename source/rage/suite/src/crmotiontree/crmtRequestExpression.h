#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestExpression
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestExpression;
} }

namespace reiv { namespace memory_map { namespace type_40c4181d59146ead {
inline constexpr char name[] = "rage::crmtRequestExpression";
inline constexpr char mangled[] = ".?AVcrmtRequestExpression@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequestSource<1>;rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c07c4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc07c4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd4c8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6d94u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_40c4181d59146ead {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00510260u, 0x00110260u, 0x00eb6d94u, 0, "FUN_00510260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00510350u, 0x00110350u, 0x00eb6d94u, 1, "FUN_00510350", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005103a0u, 0x001103a0u, 0x00eb6d94u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
