#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlConcreteLeaderboardInfoBase<Leaderboard_Ranked_Episodic_Race_135>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_1bff548b03a2f2bf {
inline constexpr char name[] = "rage::rlConcreteLeaderboardInfoBase<Leaderboard_Ranked_Episodic_Race_135>";
inline constexpr char mangled[] = ".?AV?$rlConcreteLeaderboardInfoBase@VLeaderboard_Ranked_Episodic_Race_135@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_type";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010a16c0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00ca16c0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0u};
inline constexpr std::uint32_t locators_count = 0u;
inline constexpr std::uint32_t vtables[] = {0u};
inline constexpr std::uint32_t vtables_count = 0u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_1bff548b03a2f2bf {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 0u;
// No function destinations associated by exact owner name in the available CSVs.
inline constexpr const PendingHook* pending_hooks = nullptr;
} } }
// END GENERATED PENDING HOOK ADDRESSES
