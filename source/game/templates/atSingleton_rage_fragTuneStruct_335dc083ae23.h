#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: atSingleton<rage::fragTuneStruct>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_335dc083ae2372c2 {
inline constexpr char name[] = "atSingleton<rage::fragTuneStruct>";
inline constexpr char mangled[] = ".?AV?$atSingleton@VfragTuneStruct@rage@@@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::fragTuneStruct;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f36e08u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b36e08u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec864cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d8d700u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_335dc083ae2372c2 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00a722a0u, 0x006722a0u, 0x00d8d700u, 0, "FUN_00a722a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00534410u, 0x00134410u, 0x00d8d700u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
