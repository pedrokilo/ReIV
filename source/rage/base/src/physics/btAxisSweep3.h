#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::btAxisSweep3
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class btAxisSweep3;
} }

namespace reiv { namespace memory_map { namespace type_4d926ad61d29dc2c {
inline constexpr char name[] = "rage::btAxisSweep3";
inline constexpr char mangled[] = ".?AVbtAxisSweep3@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phBroadPhase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5d3cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5d3cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f062f0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd004u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_4d926ad61d29dc2c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 18u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0073d410u, 0x0033d410u, 0x00ebd004u, 0, "FUN_0073d410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1d60u, 0x002a1d60u, 0x00ebd004u, 1, "FUN_006a1d60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073d640u, 0x0033d640u, 0x00ebd004u, 2, "FUN_0073d640", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073d760u, 0x0033d760u, 0x00ebd004u, 3, "FUN_0073d760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073de60u, 0x0033de60u, 0x00ebd004u, 4, "FUN_0073de60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e0d0u, 0x0033e0d0u, 0x00ebd004u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e0f0u, 0x0033e0f0u, 0x00ebd004u, 6, "FUN_0073e0f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e1f0u, 0x0033e1f0u, 0x00ebd004u, 7, "FUN_0073e1f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e470u, 0x0033e470u, 0x00ebd004u, 8, "FUN_0073e470", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e4f0u, 0x0033e4f0u, 0x00ebd004u, 9, "FUN_0073e4f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1a00u, 0x002a1a00u, 0x00ebd004u, 10, "FUN_006a1a00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1a30u, 0x002a1a30u, 0x00ebd004u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073dac0u, 0x0033dac0u, 0x00ebd004u, 12, "FUN_0073dac0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073daa0u, 0x0033daa0u, 0x00ebd004u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073de50u, 0x0033de50u, 0x00ebd004u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073ee40u, 0x0033ee40u, 0x00ebd004u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073ee80u, 0x0033ee80u, 0x00ebd004u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073d1e0u, 0x0033d1e0u, 0x00ebd004u, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
