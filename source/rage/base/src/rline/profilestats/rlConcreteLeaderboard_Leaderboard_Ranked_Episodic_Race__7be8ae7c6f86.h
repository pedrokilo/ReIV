#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlConcreteLeaderboard<Leaderboard_Ranked_Episodic_Race_35>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_f361008cf430f30e {
inline constexpr char name[] = "rage::rlConcreteLeaderboard<Leaderboard_Ranked_Episodic_Race_35>";
inline constexpr char mangled[] = ".?AV?$rlConcreteLeaderboard@VLeaderboard_Ranked_Episodic_Race_35@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlLeaderboard";
inline constexpr std::uint32_t type_descriptor_va = 0x010aa250u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00caa250u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ee9e98u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ead350u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f361008cf430f30e {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x004d8c60u, 0x000d8c60u, 0x00ead350u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004c5970u, 0x000c5970u, 0x00ead350u, 1, "FUN_004c5970", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 16; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ca6e0u, 0x000ca6e0u, 0x00ead350u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ca6e0u, 0x000ca6e0u, 0x00ead350u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
