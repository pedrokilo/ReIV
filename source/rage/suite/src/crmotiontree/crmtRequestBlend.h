#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestBlend
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestBlend;
} }

namespace reiv { namespace memory_map { namespace type_b95a1b28d1d1d8df {
inline constexpr char name[] = "rage::crmtRequestBlend";
inline constexpr char mangled[] = ".?AVcrmtRequestBlend@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequestSource<2>;rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0888u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0888u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd634u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6ea4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b95a1b28d1d1d8df {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005115c0u, 0x001115c0u, 0x00eb6ea4u, 0, "FUN_005115c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511700u, 0x00111700u, 0x00eb6ea4u, 1, "FUN_00511700", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005117a0u, 0x001117a0u, 0x00eb6ea4u, 2, "FUN_005117a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
