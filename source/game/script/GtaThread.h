#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: GtaThread
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class GtaThread;
} }

namespace reiv { namespace memory_map { namespace type_177915526f9e4630 {
inline constexpr char name[] = "GtaThread";
inline constexpr char mangled[] = ".?AVGtaThread@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::scrThread";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3e29cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3e29cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecda8cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dae9c4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_177915526f9e4630 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00bbcdd0u, 0x007bcdd0u, 0x00dae9c4u, 0, "FUN_00bbcdd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005a6570u, 0x001a6570u, 0x00dae9c4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005a4cd0u, 0x001a4cd0u, 0x00dae9c4u, 2, "FUN_005a4cd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bbcdf0u, 0x007bcdf0u, 0x00dae9c4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bbce70u, 0x007bce70u, 0x00dae9c4u, 4, "FUN_00bbce70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
