#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlPresenceEventInviteAccepted
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rlPresenceEventInviteAccepted;
} }

namespace reiv { namespace memory_map { namespace type_1ded6fe94b4597ab {
inline constexpr char name[] = "rage::rlPresenceEventInviteAccepted";
inline constexpr char mangled[] = ".?AVrlPresenceEventInviteAccepted@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlPresenceEvent";
inline constexpr std::uint32_t type_descriptor_va = 0x010c617cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc617cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f069a8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd550u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_1ded6fe94b4597ab {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0075d820u, 0x0035d820u, 0x00ebd550u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0075d760u, 0x0035d760u, 0x00ebd550u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
