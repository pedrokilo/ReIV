#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audWaveshaperEffectPc
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audWaveshaperEffectPc;
} }

namespace reiv { namespace memory_map { namespace type_db47da2030ea991b {
inline constexpr char name[] = "rage::audWaveshaperEffectPc";
inline constexpr char mangled[] = ".?AVaudWaveshaperEffectPc@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audDspEffect";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43d78u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43d78u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed24acu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00de0d4cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_db47da2030ea991b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00d091e0u, 0x009091e0u, 0x00de0d4cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c28820u, 0x00828820u, 0x00de0d4cu, 1, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00d09240u, 0x00909240u, 0x00de0d4cu, 2, "FUN_00d09240", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
