#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CDrawPedPropsDC
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CDrawPedPropsDC;
} }

namespace reiv { namespace memory_map { namespace type_2f64e0d2aad4d90c {
inline constexpr char name[] = "CDrawPedPropsDC";
inline constexpr char mangled[] = ".?AVCDrawPedPropsDC@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CBaseDC";
inline constexpr std::uint32_t type_descriptor_va = 0x00f10954u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b10954u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec0074u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d55b80u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_2f64e0d2aad4d90c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x007c2e50u, 0x003c2e50u, 0x00d55b80u, 0, "FUN_007c2e50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007be2c0u, 0x003be2c0u, 0x00d55b80u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004d01d0u, 0x000d01d0u, 0x00d55b80u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d55b80u, 3, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d55b80u, 4, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00826400u, 0x00426400u, 0x00d55b80u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
