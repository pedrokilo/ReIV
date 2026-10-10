#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::fragManagerTemplate<rage::fragTypeStub>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_6800714a220fd312 {
inline constexpr char name[] = "rage::fragManagerTemplate<rage::fragTypeStub>";
inline constexpr char mangled[] = ".?AV?$fragManagerTemplate@VfragTypeStub@rage@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::fragManagerBase;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0f28u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0f28u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe0f4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb747cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_6800714a220fd312 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0051fe30u, 0x0011fe30u, 0x00eb747cu, 0, "FUN_0051fe30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051fdc0u, 0x0011fdc0u, 0x00eb747cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051fd10u, 0x0011fd10u, 0x00eb747cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
