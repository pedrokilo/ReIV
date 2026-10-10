#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::snEventAddedGamer::AutoIdDesc__
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_d3c4a3cf9a4b07c0 {
inline constexpr char name[] = "rage::snEventAddedGamer::AutoIdDesc__";
inline constexpr char mangled[] = ".?AUAutoIdDesc__@snEventAddedGamer@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::AutoIdDescriptor_T<rage::snEvent>;rage::AutoIdDescriptor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1974u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1974u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff24cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb7dc0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d3c4a3cf9a4b07c0 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0053d0a0u, 0x0013d0a0u, 0x00eb7dc0u, 0, "FUN_0053d0a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
