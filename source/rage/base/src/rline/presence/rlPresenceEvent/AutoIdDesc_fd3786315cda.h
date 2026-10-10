#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlPresenceEvent::AutoIdDesc__
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_84c400b7fb650e88 {
inline constexpr char name[] = "rage::rlPresenceEvent::AutoIdDesc__";
inline constexpr char mangled[] = ".?AUAutoIdDesc__@rlPresenceEvent@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::AutoIdDescriptor_T<rage::rlPresenceEvent>;rage::AutoIdDescriptor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c6118u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc6118u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f068c0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd574u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_84c400b7fb650e88 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0075d720u, 0x0035d720u, 0x00ebd574u, 0, "FUN_0075d720", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
