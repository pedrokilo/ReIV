#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetworkArrayMgr
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CNetworkArrayMgr;
} }

namespace reiv { namespace memory_map { namespace type_f0799e9bb59a39c8 {
inline constexpr char name[] = "CNetworkArrayMgr";
inline constexpr char mangled[] = ".?AVCNetworkArrayMgr@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f450u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f450u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed5bb0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ea08e4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f0799e9bb59a39c8 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00492a80u, 0x00092a80u, 0x00ea08e4u, 0, "FUN_00492a80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00492af0u, 0x00092af0u, 0x00ea08e4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00492c20u, 0x00092c20u, 0x00ea08e4u, 2, "FUN_00492c20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
