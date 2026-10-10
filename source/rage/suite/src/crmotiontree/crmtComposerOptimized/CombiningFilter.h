#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtComposerOptimized::CombiningFilter
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_cf10036d61265065 {
inline constexpr char name[] = "rage::crmtComposerOptimized::CombiningFilter";
inline constexpr char mangled[] = ".?AVCombiningFilter@crmtComposerOptimized@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crFrameFilters<8,0>;rage::crFrameFilter;rage::atReferenceCounter;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0928u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0928u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd7a8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6f88u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_cf10036d61265065 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005129d0u, 0x001129d0u, 0x00eb6f88u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6e0u, 0x0010b6e0u, 0x00eb6f88u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6f0u, 0x0010b6f0u, 0x00eb6f88u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512a00u, 0x00112a00u, 0x00eb6f88u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512a90u, 0x00112a90u, 0x00eb6f88u, 4, "FUN_00512a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
