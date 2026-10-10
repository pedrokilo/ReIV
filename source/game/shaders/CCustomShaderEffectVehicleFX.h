#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CCustomShaderEffectVehicleFX
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CCustomShaderEffectVehicleFX;
} }

namespace reiv { namespace memory_map { namespace type_c2483b75da523160 {
inline constexpr char name[] = "CCustomShaderEffectVehicleFX";
inline constexpr char mangled[] = ".?AVCCustomShaderEffectVehicleFX@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CCustomShaderEffectBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f42894u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b42894u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ed0aa4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dcbd3cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c2483b75da523160 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cba240u, 0x008ba240u, 0x00dcbd3cu, 0, "FUN_00cba240", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cba260u, 0x008ba260u, 0x00dcbd3cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c28820u, 0x00828820u, 0x00dcbd3cu, 2, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cbab30u, 0x008bab30u, 0x00dcbd3cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb9e90u, 0x008b9e90u, 0x00dcbd3cu, 4, "FUN_00cb9e90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cbb050u, 0x008bb050u, 0x00dcbd3cu, 5, "FUN_00cbb050", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb9e60u, 0x008b9e60u, 0x00dcbd3cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cba430u, 0x008ba430u, 0x00dcbd3cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cba460u, 0x008ba460u, 0x00dcbd3cu, 8, "FUN_00cba460", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
