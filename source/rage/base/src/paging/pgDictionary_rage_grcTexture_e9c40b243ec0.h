#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::pgDictionary<rage::grcTexture>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_c503f5d52005fab3 {
inline constexpr char name[] = "rage::pgDictionary<rage::grcTexture>";
inline constexpr char mangled[] = ".?AV?$pgDictionary@VgrcTexture@rage@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::pgBase;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f144u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f144u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed3148u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d5b430u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c503f5d52005fab3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0043b6c0u, 0x0003b6c0u, 0x00d5b430u, 0, "FUN_0043b6c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00553fe0u, 0x00153fe0u, 0x00d5b430u, 1, "FUN_00553fe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0043faa0u, 0x0003faa0u, 0x00d5b430u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
