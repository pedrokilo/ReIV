#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxKeyframe4
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ptxKeyframe4;
} }

namespace reiv { namespace memory_map { namespace type_16df54a9dd9c18e6 {
inline constexpr char name[] = "rage::ptxKeyframe4";
inline constexpr char mangled[] = ".?AVptxKeyframe4@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ptxNetObject;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c30f0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc30f0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f01998u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb92d8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_16df54a9dd9c18e6 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0057fa60u, 0x0017fa60u, 0x00eb92d8u, 0, "FUN_0057fa60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
