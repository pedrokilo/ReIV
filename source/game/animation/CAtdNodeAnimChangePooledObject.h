#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CAtdNodeAnimChangePooledObject
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CAtdNodeAnimChangePooledObject;
} }

namespace reiv { namespace memory_map { namespace type_17081169cc1e3be4 {
inline constexpr char name[] = "CAtdNodeAnimChangePooledObject";
inline constexpr char mangled[] = ".?AVCAtdNodeAnimChangePooledObject@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::atDNode<CAnimChange,CAtdVirtualBase>;CAtdVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f348d8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b348d8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec5e88u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d84010u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_17081169cc1e3be4 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009ee750u, 0x005ee750u, 0x00d84010u, 0, "FUN_009ee750", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
