#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetworkObjectMgr::CAtdNodeNetworkObject
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_43b6b8f84ced0e81 {
inline constexpr char name[] = "CNetworkObjectMgr::CAtdNodeNetworkObject";
inline constexpr char mangled[] = ".?AVCAtdNodeNetworkObject@CNetworkObjectMgr@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::atDNode<CNetworkObject*,rage::datBase>;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010902b0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c902b0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed4fe0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9fa88u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_43b6b8f84ced0e81 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00475a60u, 0x00075a60u, 0x00e9fa88u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
