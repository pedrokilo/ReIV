#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ProceduralTextureSkyhat
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ProceduralTextureSkyhat;
} }

namespace reiv { namespace memory_map { namespace type_74001e2956f320f0 {
inline constexpr char name[] = "rage::ProceduralTextureSkyhat";
inline constexpr char mangled[] = ".?AVProceduralTextureSkyhat@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ProceduralTexture;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1de8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1de8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff8ccu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb80a4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_74001e2956f320f0 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0054a2b0u, 0x0014a2b0u, 0x00eb80a4u, 0, "FUN_0054a2b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054a390u, 0x0014a390u, 0x00eb80a4u, 1, "FUN_0054a390", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00eb80a4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0054ab90u, 0x0014ab90u, 0x00eb80a4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054ae00u, 0x0014ae00u, 0x00eb80a4u, 4, "FUN_0054ae00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00548c50u, 0x00148c50u, 0x00eb80a4u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
