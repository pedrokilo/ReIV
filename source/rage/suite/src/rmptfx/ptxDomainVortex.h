#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxDomainVortex
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ptxDomainVortex;
} }

namespace reiv { namespace memory_map { namespace type_51158aa26a7c1a12 {
inline constexpr char name[] = "rage::ptxDomainVortex";
inline constexpr char mangled[] = ".?AVptxDomainVortex@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ptxDomain;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c2468u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc2468u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00388u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb85c0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_51158aa26a7c1a12 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00557500u, 0x00157500u, 0x00eb85c0u, 0, "FUN_00557500", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557f80u, 0x00157f80u, 0x00eb85c0u, 1, "FUN_00557f80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557450u, 0x00157450u, 0x00eb85c0u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557480u, 0x00157480u, 0x00eb85c0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005591d0u, 0x001591d0u, 0x00eb85c0u, 4, "FUN_005591d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00558d90u, 0x00158d90u, 0x00eb85c0u, 5, "FUN_00558d90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005574e0u, 0x001574e0u, 0x00eb85c0u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
