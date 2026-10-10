#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedTargetting
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedTargetting;
} }

namespace reiv { namespace memory_map { namespace type_b11d3f281f2423d2 {
inline constexpr char name[] = "CPedTargetting";
inline constexpr char mangled[] = ".?AVCPedTargetting@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CTargetting;CExpensiveProcess";
inline constexpr std::uint32_t type_descriptor_va = 0x00f4127cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b4127cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecfc70u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dc5820u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b11d3f281f2423d2 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 14u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c8a030u, 0x0088a030u, 0x00dc5820u, 0, "FUN_00c8a030", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c89f20u, 0x00889f20u, 0x00dc5820u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c888b0u, 0x008888b0u, 0x00dc5820u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c89070u, 0x00889070u, 0x00dc5820u, 3, "FUN_00c89070", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88090u, 0x00888090u, 0x00dc5820u, 4, "FUN_00c88090", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c89b50u, 0x00889b50u, 0x00dc5820u, 5, "FUN_00c89b50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88630u, 0x00888630u, 0x00dc5820u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88100u, 0x00888100u, 0x00dc5820u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88210u, 0x00888210u, 0x00dc5820u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88560u, 0x00888560u, 0x00dc5820u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c88580u, 0x00888580u, 0x00dc5820u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c885e0u, 0x008885e0u, 0x00dc5820u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c89ae0u, 0x00889ae0u, 0x00dc5820u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c87ef0u, 0x00887ef0u, 0x00dc5820u, 13, "FUN_00c87ef0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
