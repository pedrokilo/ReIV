#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxDomainCylinder
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ptxDomainCylinder;
} }

namespace reiv { namespace memory_map { namespace type_a117ce515e780274 {
inline constexpr char name[] = "rage::ptxDomainCylinder";
inline constexpr char mangled[] = ".?AVptxDomainCylinder@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ptxDomain;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c23fcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc23fcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f00298u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb8620u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_a117ce515e780274 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00557500u, 0x00157500u, 0x00eb8620u, 0, "FUN_00557500", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557f80u, 0x00157f80u, 0x00eb8620u, 1, "FUN_00557f80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557450u, 0x00157450u, 0x00eb8620u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557480u, 0x00157480u, 0x00eb8620u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a0e0u, 0x0015a0e0u, 0x00eb8620u, 4, "FUN_0055a0e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00559a30u, 0x00159a30u, 0x00eb8620u, 5, "FUN_00559a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00557570u, 0x00157570u, 0x00eb8620u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
