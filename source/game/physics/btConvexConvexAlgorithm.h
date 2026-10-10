#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: btConvexConvexAlgorithm
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class btConvexConvexAlgorithm;
} }

namespace reiv { namespace memory_map { namespace type_fcd5304a71078c02 {
inline constexpr char name[] = "btConvexConvexAlgorithm";
inline constexpr char mangled[] = ".?AVbtConvexConvexAlgorithm@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "btCollisionAlgorithm";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5e6cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5e6cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f06564u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd29cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_fcd5304a71078c02 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00758890u, 0x00358890u, 0x00ebd29cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007585f0u, 0x003585f0u, 0x00ebd29cu, 1, "FUN_007585f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
