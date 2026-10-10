#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::netEventConnectionClosed::AutoIdDesc__
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_908077640e18f8f3 {
inline constexpr char name[] = "rage::netEventConnectionClosed::AutoIdDesc__";
inline constexpr char mangled[] = ".?AUAutoIdDesc__@netEventConnectionClosed@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::AutoIdDescriptor_T<rage::netEvent>;rage::AutoIdDescriptor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c6c84u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc6c84u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f07c74u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebda08u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_908077640e18f8f3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00779930u, 0x00379930u, 0x00ebda08u, 0, "FUN_00779930", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
