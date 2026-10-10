#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::snMsgChangeSessionAttributesCmd::AutoIdDesc__
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_d69530e1ba7c550d {
inline constexpr char name[] = "rage::snMsgChangeSessionAttributesCmd::AutoIdDesc__";
inline constexpr char mangled[] = ".?AUAutoIdDesc__@snMsgChangeSessionAttributesCmd@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::AutoIdDescriptor_T<rage::netMessage>;rage::AutoIdDescriptor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c2d78u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc2d78u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f0149cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb92a0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d69530e1ba7c550d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x007768c0u, 0x003768c0u, 0x00eb92a0u, 0, "FUN_007768c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
