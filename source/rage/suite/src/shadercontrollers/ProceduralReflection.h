#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ProceduralReflection
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ProceduralReflection;
} }

namespace reiv { namespace memory_map { namespace type_887771703ffc8108 {
inline constexpr char name[] = "rage::ProceduralReflection";
inline constexpr char mangled[] = ".?AVProceduralReflection@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1e14u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1e14u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff91cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb8098u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_887771703ffc8108 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00548c20u, 0x00148c20u, 0x00eb8098u, 0, "FUN_00548c20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00548c10u, 0x00148c10u, 0x00eb8098u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
