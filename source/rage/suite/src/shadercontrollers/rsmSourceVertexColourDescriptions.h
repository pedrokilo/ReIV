#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rsmSourceVertexColourDescriptions
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rsmSourceVertexColourDescriptions;
} }

namespace reiv { namespace memory_map { namespace type_f2c0621b121c6325 {
inline constexpr char name[] = "rage::rsmSourceVertexColourDescriptions";
inline constexpr char mangled[] = ".?AVrsmSourceVertexColourDescriptions@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5328u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5328u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f04df4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb950u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f2c0621b121c6325 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0066f9b0u, 0x0026f9b0u, 0x00ebb950u, 0, "FUN_0066f9b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0066f890u, 0x0026f890u, 0x00ebb950u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
