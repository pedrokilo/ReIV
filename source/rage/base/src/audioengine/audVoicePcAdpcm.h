#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audVoicePcAdpcm
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audVoicePcAdpcm;
} }

namespace reiv { namespace memory_map { namespace type_0a021a86e1040d3d {
inline constexpr char name[] = "rage::audVoicePcAdpcm";
inline constexpr char mangled[] = ".?AVaudVoicePcAdpcm@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audVoicePhysical";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43ce4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43ce4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed23e0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00de0a20u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0a021a86e1040d3d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 12u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00d086d0u, 0x009086d0u, 0x00de0a20u, 0, "FUN_00d086d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d079a0u, 0x009079a0u, 0x00de0a20u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d07be0u, 0x00907be0u, 0x00de0a20u, 2, "FUN_00d07be0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d08730u, 0x00908730u, 0x00de0a20u, 3, "FUN_00d08730", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d084b0u, 0x009084b0u, 0x00de0a20u, 4, "FUN_00d084b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d07c20u, 0x00907c20u, 0x00de0a20u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d07c40u, 0x00907c40u, 0x00de0a20u, 6, "FUN_00d07c40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d07430u, 0x00907430u, 0x00de0a20u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d082d0u, 0x009082d0u, 0x00de0a20u, 8, "FUN_00d082d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00de0a20u, 9, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 8; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00d087a0u, 0x009087a0u, 0x00de0a20u, 10, "FUN_00d087a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00d08840u, 0x00908840u, 0x00de0a20u, 11, "FUN_00d08840", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
