#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audDelayEffectPc
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audDelayEffectPc;
} }

namespace reiv { namespace memory_map { namespace type_68e5ceff8a4160ea {
inline constexpr char name[] = "rage::audDelayEffectPc";
inline constexpr char mangled[] = ".?AVaudDelayEffectPc@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audDspEffect";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43da8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43da8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed24f8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00de0eb4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_68e5ceff8a4160ea {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00d09490u, 0x00909490u, 0x00de0eb4u, 0, "FUN_00d09490", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d099b0u, 0x009099b0u, 0x00de0eb4u, 1, "FUN_00d099b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d09670u, 0x00909670u, 0x00de0eb4u, 2, "FUN_00d09670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
