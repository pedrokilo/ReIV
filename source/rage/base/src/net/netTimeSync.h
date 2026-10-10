#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::netTimeSync
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class netTimeSync;
} }

namespace reiv { namespace memory_map { namespace type_607cc5ec18aa301b {
inline constexpr char name[] = "rage::netTimeSync";
inline constexpr char mangled[] = ".?AVnetTimeSync@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c6518u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc6518u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f06fa4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd66cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_607cc5ec18aa301b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00767860u, 0x00367860u, 0x00ebd66cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00767a00u, 0x00367a00u, 0x00ebd66cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
