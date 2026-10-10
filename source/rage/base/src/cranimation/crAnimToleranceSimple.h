#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crAnimToleranceSimple
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crAnimToleranceSimple;
} }

namespace reiv { namespace memory_map { namespace type_ee7e0fbd282dc38b {
inline constexpr char name[] = "rage::crAnimToleranceSimple";
inline constexpr char mangled[] = ".?AVcrAnimToleranceSimple@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crAnimTolerance";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3438u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3438u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f020d0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb96f0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ee7e0fbd282dc38b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0059f0c0u, 0x0019f0c0u, 0x00eb96f0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059f110u, 0x0019f110u, 0x00eb96f0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059f170u, 0x0019f170u, 0x00eb96f0u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059f180u, 0x0019f180u, 0x00eb96f0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
