#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::grcSetup
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class grcSetup;
} }

namespace reiv { namespace memory_map { namespace type_59d71ef976968fac {
inline constexpr char name[] = "rage::grcSetup";
inline constexpr char mangled[] = ".?AVgrcSetup@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c4c64u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc4c64u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f042b8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb0d0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_59d71ef976968fac {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0057f820u, 0x0017f820u, 0x00ebb0d0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633150u, 0x00233150u, 0x00ebb0d0u, 1, "FUN_00633150", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006332d0u, 0x002332d0u, 0x00ebb0d0u, 2, "FUN_006332d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633370u, 0x00233370u, 0x00ebb0d0u, 3, "FUN_00633370", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633400u, 0x00233400u, 0x00ebb0d0u, 4, "FUN_00633400", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633460u, 0x00233460u, 0x00ebb0d0u, 5, "FUN_00633460", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006331d0u, 0x002331d0u, 0x00ebb0d0u, 6, "FUN_006331d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
