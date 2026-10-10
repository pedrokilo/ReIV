#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audSpeechSound
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audSpeechSound;
} }

namespace reiv { namespace memory_map { namespace type_36806a21955c8b21 {
inline constexpr char name[] = "rage::audSpeechSound";
inline constexpr char mangled[] = ".?AVaudSpeechSound@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audSound";
inline constexpr std::uint32_t type_descriptor_va = 0x00f0e800u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b0e800u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed1874u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ddb4d4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_36806a21955c8b21 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ce1ec0u, 0x008e1ec0u, 0x00ddb4d4u, 0, "FUN_00ce1ec0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fa0u, 0x008e0fa0u, 0x00ddb4d4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1000u, 0x008e1000u, 0x00ddb4d4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fd0u, 0x008e0fd0u, 0x00ddb4d4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1e60u, 0x008e1e60u, 0x00ddb4d4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ceca00u, 0x008eca00u, 0x00ddb4d4u, 5, "FUN_00ceca00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0bc0u, 0x008e0bc0u, 0x00ddb4d4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cec580u, 0x008ec580u, 0x00ddb4d4u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1220u, 0x008e1220u, 0x00ddb4d4u, 8, "FUN_00ce1220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cec7d0u, 0x008ec7d0u, 0x00ddb4d4u, 9, "FUN_00cec7d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
