#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audSimpleSound
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audSimpleSound;
} }

namespace reiv { namespace memory_map { namespace type_18fae9f46a36c419 {
inline constexpr char name[] = "rage::audSimpleSound";
inline constexpr char mangled[] = ".?AVaudSimpleSound@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audSound";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43ae4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43ae4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed2050u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ddf80cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_18fae9f46a36c419 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ce1ec0u, 0x008e1ec0u, 0x00ddf80cu, 0, "FUN_00ce1ec0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fa0u, 0x008e0fa0u, 0x00ddf80cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1000u, 0x008e1000u, 0x00ddf80cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fd0u, 0x008e0fd0u, 0x00ddf80cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1e60u, 0x008e1e60u, 0x00ddf80cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cff660u, 0x008ff660u, 0x00ddf80cu, 5, "FUN_00cff660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0bc0u, 0x008e0bc0u, 0x00ddf80cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cff0f0u, 0x008ff0f0u, 0x00ddf80cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1220u, 0x008e1220u, 0x00ddf80cu, 8, "FUN_00ce1220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cff440u, 0x008ff440u, 0x00ddf80cu, 9, "FUN_00cff440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
