#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::CWMStreamReader
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class CWMStreamReader;
} }

namespace reiv { namespace memory_map { namespace type_37b371f84fa27267 {
inline constexpr char name[] = "rage::CWMStreamReader";
inline constexpr char mangled[] = ".?AVCWMStreamReader@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::CBaseStreamReader";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43630u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43630u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed1ab4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ddd428u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_37b371f84fa27267 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cf5b20u, 0x008f5b20u, 0x00ddd428u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6d00u, 0x008f6d00u, 0x00ddd428u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6620u, 0x008f6620u, 0x00ddd428u, 2, "FUN_00cf6620", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6670u, 0x008f6670u, 0x00ddd428u, 3, "FUN_00cf6670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6990u, 0x008f6990u, 0x00ddd428u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf68f0u, 0x008f68f0u, 0x00ddd428u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6910u, 0x008f6910u, 0x00ddd428u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6930u, 0x008f6930u, 0x00ddd428u, 7, "FUN_00cf6930", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6a10u, 0x008f6a10u, 0x00ddd428u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6a20u, 0x008f6a20u, 0x00ddd428u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
