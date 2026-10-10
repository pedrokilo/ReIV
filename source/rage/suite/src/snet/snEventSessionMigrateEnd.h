#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::snEventSessionMigrateEnd
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class snEventSessionMigrateEnd;
} }

namespace reiv { namespace memory_map { namespace type_fba325b76ee64665 {
inline constexpr char name[] = "rage::snEventSessionMigrateEnd";
inline constexpr char mangled[] = ".?AVsnEventSessionMigrateEnd@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::snEvent";
inline constexpr std::uint32_t type_descriptor_va = 0x010c2a20u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc2a20u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00d90u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb9068u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_fba325b76ee64665 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005777b0u, 0x001777b0u, 0x00eb9068u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0053cce0u, 0x0013cce0u, 0x00eb9068u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
