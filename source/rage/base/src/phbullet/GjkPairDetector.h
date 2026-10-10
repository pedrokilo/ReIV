#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::GjkPairDetector
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class GjkPairDetector;
} }

namespace reiv { namespace memory_map { namespace type_a04d83577564a0a3 {
inline constexpr char name[] = "rage::GjkPairDetector";
inline constexpr char mangled[] = ".?AVGjkPairDetector@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "DiscreteCollisionDetectorInterface";
inline constexpr std::uint32_t type_descriptor_va = 0x010c580cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc580cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05844u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebc674u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_a04d83577564a0a3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006e1cb0u, 0x002e1cb0u, 0x00ebc674u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0074f9e0u, 0x0034f9e0u, 0x00ebc674u, 1, "FUN_0074f9e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
