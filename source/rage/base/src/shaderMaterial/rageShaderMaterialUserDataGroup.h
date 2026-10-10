#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rageShaderMaterialUserDataGroup
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rageShaderMaterialUserDataGroup;
} }

namespace reiv { namespace memory_map { namespace type_bfb9b36b90501537 {
inline constexpr char name[] = "rage::rageShaderMaterialUserDataGroup";
inline constexpr char mangled[] = ".?AVrageShaderMaterialUserDataGroup@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c53c8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc53c8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f04eccu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb974u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_bfb9b36b90501537 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006705c0u, 0x002705c0u, 0x00ebb974u, 0, "FUN_006705c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006704a0u, 0x002704a0u, 0x00ebb974u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
