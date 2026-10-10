#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlConcreteLeaderboard<SkillLeaderboard_CompCarStealRanked>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_2b5f9d88dd0c7186 {
inline constexpr char name[] = "rage::rlConcreteLeaderboard<SkillLeaderboard_CompCarStealRanked>";
inline constexpr char mangled[] = ".?AV?$rlConcreteLeaderboard@VSkillLeaderboard_CompCarStealRanked@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlLeaderboard";
inline constexpr std::uint32_t type_descriptor_va = 0x010bf168u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cbf168u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efadfcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ea5d48u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_2b5f9d88dd0c7186 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x004d8c60u, 0x000d8c60u, 0x00ea5d48u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004c5970u, 0x000c5970u, 0x00ea5d48u, 1, "FUN_004c5970", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 16; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ca6e0u, 0x000ca6e0u, 0x00ea5d48u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ca6e0u, 0x000ca6e0u, 0x00ea5d48u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
