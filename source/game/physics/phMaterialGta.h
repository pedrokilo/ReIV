#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: phMaterialGta
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class phMaterialGta;
} }

namespace reiv { namespace memory_map { namespace type_f2ffeec5312d4221 {
inline constexpr char name[] = "phMaterialGta";
inline constexpr char mangled[] = ".?AVphMaterialGta@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phMaterial;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f422e8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b422e8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed0514u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dc9100u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f2ffeec5312d4221 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00796670u, 0x00396670u, 0x00dc9100u, 0, "FUN_00796670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00703600u, 0x00303600u, 0x00dc9100u, 1, "FUN_00703600", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00703660u, 0x00303660u, 0x00dc9100u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
