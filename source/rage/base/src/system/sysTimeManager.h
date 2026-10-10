#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::sysTimeManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class sysTimeManager;
} }

namespace reiv { namespace memory_map { namespace type_41a7eadb168d9a1f {
inline constexpr char name[] = "rage::sysTimeManager";
inline constexpr char mangled[] = ".?AVsysTimeManager@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c38f8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc38f8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f029e4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba01cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_41a7eadb168d9a1f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005c13c0u, 0x001c13c0u, 0x00eba01cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c13f0u, 0x001c13f0u, 0x00eba01cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c1430u, 0x001c1430u, 0x00eba01cu, 2, "FUN_005c1430", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
