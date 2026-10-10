#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: PointCollector
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class PointCollector;
} }

namespace reiv { namespace memory_map { namespace type_cebfafeb0e1fc3b8 {
inline constexpr char name[] = "PointCollector";
inline constexpr char mangled[] = ".?AVPointCollector@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "DiscreteCollisionDetectorInterface::Result";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5b8cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5b8cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05fc0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebcf7cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_cebfafeb0e1fc3b8 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006e1cc0u, 0x002e1cc0u, 0x00ebcf7cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00732780u, 0x00332780u, 0x00ebcf7cu, 1, "FUN_00732780", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
