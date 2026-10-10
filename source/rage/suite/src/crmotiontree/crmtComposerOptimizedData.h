#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtComposerOptimizedData
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtComposerOptimizedData;
} }

namespace reiv { namespace memory_map { namespace type_781a93fe69c34c61 {
inline constexpr char name[] = "rage::crmtComposerOptimizedData";
inline constexpr char mangled[] = ".?AVcrmtComposerOptimizedData@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtComposerData";
inline constexpr std::uint32_t type_descriptor_va = 0x010c03b4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc03b4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efccf8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6b88u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_781a93fe69c34c61 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00509af0u, 0x00109af0u, 0x00eb6b88u, 0, "FUN_00509af0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00509b90u, 0x00109b90u, 0x00eb6b88u, 1, "FUN_00509b90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00509bd0u, 0x00109bd0u, 0x00eb6b88u, 2, "FUN_00509bd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
