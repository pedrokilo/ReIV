#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlFriendsReader::Worker
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_95e0479e58c0db42 {
inline constexpr char name[] = "rage::rlFriendsReader::Worker";
inline constexpr char mangled[] = ".?AUWorker@rlFriendsReader@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlWorker";
inline constexpr std::uint32_t type_descriptor_va = 0x010c6650u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc6650u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f071bcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd714u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_95e0479e58c0db42 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0076d600u, 0x0036d600u, 0x00ebd714u, 0, "FUN_0076d600", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00776e30u, 0x00376e30u, 0x00ebd714u, 1, "FUN_00776e30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00776ed0u, 0x00376ed0u, 0x00ebd714u, 2, "FUN_00776ed0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0076d6f0u, 0x0036d6f0u, 0x00ebd714u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
