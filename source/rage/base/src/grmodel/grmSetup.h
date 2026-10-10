#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::grmSetup
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class grmSetup;
} }

namespace reiv { namespace memory_map { namespace type_73f867c83c011c7b {
inline constexpr char name[] = "rage::grmSetup";
inline constexpr char mangled[] = ".?AVgrmSetup@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::grcSetup;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f0c218u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b0c218u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ebee68u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d50d80u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_73f867c83c011c7b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00796670u, 0x00396670u, 0x00d50d80u, 0, "FUN_00796670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633520u, 0x00233520u, 0x00d50d80u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006335d0u, 0x002335d0u, 0x00d50d80u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633370u, 0x00233370u, 0x00d50d80u, 3, "FUN_00633370", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633400u, 0x00233400u, 0x00d50d80u, 4, "FUN_00633400", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633460u, 0x00233460u, 0x00d50d80u, 5, "FUN_00633460", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00633590u, 0x00233590u, 0x00d50d80u, 6, "FUN_00633590", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
