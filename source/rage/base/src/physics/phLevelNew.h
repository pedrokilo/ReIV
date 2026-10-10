#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phLevelNew
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phLevelNew;
} }

namespace reiv { namespace memory_map { namespace type_fcaebe0f32dc6584 {
inline constexpr char name[] = "rage::phLevelNew";
inline constexpr char mangled[] = ".?AVphLevelNew@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phLevelBase;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c563cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc563cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f053dcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebbe30u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_fcaebe0f32dc6584 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006d75a0u, 0x002d75a0u, 0x00ebbe30u, 0, "FUN_006d75a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
