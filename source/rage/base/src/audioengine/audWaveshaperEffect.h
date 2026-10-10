#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audWaveshaperEffect
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audWaveshaperEffect;
} }

namespace reiv { namespace memory_map { namespace type_65ae890b3347581c {
inline constexpr char name[] = "rage::audWaveshaperEffect";
inline constexpr char mangled[] = ".?AVaudWaveshaperEffect@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audEffect";
inline constexpr std::uint32_t type_descriptor_va = 0x00f4378cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b4378cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed1b90u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dde5fcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_65ae890b3347581c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cfae10u, 0x008fae10u, 0x00dde5fcu, 0, "FUN_00cfae10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfacf0u, 0x008facf0u, 0x00dde5fcu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfad70u, 0x008fad70u, 0x00dde5fcu, 2, "FUN_00cfad70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c28820u, 0x00828820u, 0x00dde5fcu, 3, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cfada0u, 0x008fada0u, 0x00dde5fcu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfadb0u, 0x008fadb0u, 0x00dde5fcu, 5, "FUN_00cfadb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfb7c0u, 0x008fb7c0u, 0x00dde5fcu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 116; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
