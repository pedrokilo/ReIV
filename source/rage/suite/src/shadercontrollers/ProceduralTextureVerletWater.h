#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ProceduralTextureVerletWater
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ProceduralTextureVerletWater;
} }

namespace reiv { namespace memory_map { namespace type_c2b6bfa2c66a2286 {
inline constexpr char name[] = "rage::ProceduralTextureVerletWater";
inline constexpr char mangled[] = ".?AVProceduralTextureVerletWater@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ProceduralTexture;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1e3cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1e3cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff968u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb807cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c2b6bfa2c66a2286 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005497e0u, 0x001497e0u, 0x00eb807cu, 0, "FUN_005497e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549860u, 0x00149860u, 0x00eb807cu, 1, "FUN_00549860", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549a80u, 0x00149a80u, 0x00eb807cu, 2, "FUN_00549a80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549af0u, 0x00149af0u, 0x00eb807cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549b50u, 0x00149b50u, 0x00eb807cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00548b40u, 0x00148b40u, 0x00eb807cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
