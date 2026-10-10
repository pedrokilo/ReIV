#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestAnimation
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestAnimation;
} }

namespace reiv { namespace memory_map { namespace type_8fdd2347e758e20c {
inline constexpr char name[] = "rage::crmtRequestAnimation";
inline constexpr char mangled[] = ".?AVcrmtRequestAnimation@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c079cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc079cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd47cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6d84u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_8fdd2347e758e20c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0050fff0u, 0x0010fff0u, 0x00eb6d84u, 0, "FUN_0050fff0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00510140u, 0x00110140u, 0x00eb6d84u, 1, "FUN_00510140", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005101b0u, 0x001101b0u, 0x00eb6d84u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
