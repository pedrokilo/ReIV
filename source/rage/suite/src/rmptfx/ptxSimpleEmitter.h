#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxSimpleEmitter
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
struct ptxSimpleEmitter;
} }

namespace reiv { namespace memory_map { namespace type_e00a652928c98e6d {
inline constexpr char name[] = "rage::ptxSimpleEmitter";
inline constexpr char mangled[] = ".?AUptxSimpleEmitter@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ParseClass<rage::ptxSimpleEmitter>;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1c3cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1c3cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff68cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbe3d0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e00a652928c98e6d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0057f820u, 0x0017f820u, 0x00dbe3d0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005458f0u, 0x001458f0u, 0x00dbe3d0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
