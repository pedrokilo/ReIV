#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phBoundBase
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phBoundBase;
} }

namespace reiv { namespace memory_map { namespace type_81039e92dc608e7b {
inline constexpr char name[] = "rage::phBoundBase";
inline constexpr char mangled[] = ".?AVphBoundBase@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_type";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c547cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc547cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0u};
inline constexpr std::uint32_t locators_count = 0u;
inline constexpr std::uint32_t vtables[] = {0u};
inline constexpr std::uint32_t vtables_count = 0u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_81039e92dc608e7b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 0u;
// No function destinations associated by exact owner name in the available CSVs.
inline constexpr const PendingHook* pending_hooks = nullptr;
} } }
// END GENERATED PENDING HOOK ADDRESSES
