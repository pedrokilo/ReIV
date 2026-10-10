#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::PluginRegistrar<ART::Rockstar::NmRsPlugin>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_782b2fa68cc56f3f {
inline constexpr char name[] = "ART::PluginRegistrar<ART::Rockstar::NmRsPlugin>";
inline constexpr char mangled[] = ".?AV?$PluginRegistrar@VNmRsPlugin@Rockstar@ART@@@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3c4cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3c4cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f0311cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba5bcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_782b2fa68cc56f3f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005d66c0u, 0x001d66c0u, 0x00eba5bcu, 0, "FUN_005d66c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
