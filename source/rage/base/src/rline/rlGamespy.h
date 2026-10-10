#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlGamespy
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rlGamespy;
} }

namespace reiv { namespace memory_map { namespace type_1107a056fbe3537b {
inline constexpr char name[] = "rage::rlGamespy";
inline constexpr char mangled[] = ".?AVrlGamespy@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::netVSocket";
inline constexpr std::uint32_t type_descriptor_va = 0x010c7498u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc7498u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f086c8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebde30u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_1107a056fbe3537b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0077de10u, 0x0037de10u, 0x00ebde30u, 0, "FUN_0077de10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0077e1b0u, 0x0037e1b0u, 0x00ebde30u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00779d90u, 0x00379d90u, 0x00ebde30u, 2, "FUN_00779d90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
