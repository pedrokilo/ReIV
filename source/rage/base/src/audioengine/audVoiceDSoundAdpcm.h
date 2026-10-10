#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audVoiceDSoundAdpcm
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audVoiceDSoundAdpcm;
} }

namespace reiv { namespace memory_map { namespace type_d9577208f54f97b6 {
inline constexpr char name[] = "rage::audVoiceDSoundAdpcm";
inline constexpr char mangled[] = ".?AVaudVoiceDSoundAdpcm@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audVoicePhysical";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43c94u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43c94u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed2348u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00de071cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d9577208f54f97b6 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 13u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00d06750u, 0x00906750u, 0x00de071cu, 0, "FUN_00d06750", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d05b00u, 0x00905b00u, 0x00de071cu, 1, "FUN_00d05b00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d04f10u, 0x00904f10u, 0x00de071cu, 2, "FUN_00d04f10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d067b0u, 0x009067b0u, 0x00de071cu, 3, "FUN_00d067b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d064b0u, 0x009064b0u, 0x00de071cu, 4, "FUN_00d064b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d04f50u, 0x00904f50u, 0x00de071cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d05ed0u, 0x00905ed0u, 0x00de071cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d05f00u, 0x00905f00u, 0x00de071cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d05f20u, 0x00905f20u, 0x00de071cu, 8, "FUN_00d05f20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00de071cu, 9, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 8; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00d06850u, 0x00906850u, 0x00de071cu, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d068b0u, 0x009068b0u, 0x00de071cu, 11, "FUN_00d068b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00de071cu, 12, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
