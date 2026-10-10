#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rsmRunTimeVertexColourDescriptions
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rsmRunTimeVertexColourDescriptions;
} }

namespace reiv { namespace memory_map { namespace type_cabc311bfaa30cb9 {
inline constexpr char name[] = "rage::rsmRunTimeVertexColourDescriptions";
inline constexpr char mangled[] = ".?AVrsmRunTimeVertexColourDescriptions@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5428u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5428u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f04f5cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb98cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_cabc311bfaa30cb9 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00670be0u, 0x00270be0u, 0x00ebb98cu, 0, "FUN_00670be0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00670ac0u, 0x00270ac0u, 0x00ebb98cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
