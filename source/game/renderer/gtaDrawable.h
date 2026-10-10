#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: gtaDrawable
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class gtaDrawable;
} }

namespace reiv { namespace memory_map { namespace type_254dcaeef9384fda {
inline constexpr char name[] = "gtaDrawable";
inline constexpr char mangled[] = ".?AVgtaDrawable@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rmcDrawable;rage::rmcDrawableBase;rage::pgBase;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f36698u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b36698u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec7cc0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d8aae4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_254dcaeef9384fda {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 22u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00a4c120u, 0x0064c120u, 0x00d8aae4u, 0, "FUN_00a4c120", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006353a0u, 0x002353a0u, 0x00d8aae4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006353d0u, 0x002353d0u, 0x00d8aae4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635390u, 0x00235390u, 0x00d8aae4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006355e0u, 0x002355e0u, 0x00d8aae4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635500u, 0x00235500u, 0x00d8aae4u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635660u, 0x00235660u, 0x00d8aae4u, 6, "FUN_00635660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635d70u, 0x00235d70u, 0x00d8aae4u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635dd0u, 0x00235dd0u, 0x00d8aae4u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635da0u, 0x00235da0u, 0x00d8aae4u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635e00u, 0x00235e00u, 0x00d8aae4u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635e30u, 0x00235e30u, 0x00d8aae4u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635ee0u, 0x00235ee0u, 0x00d8aae4u, 12, "FUN_00635ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635d30u, 0x00235d30u, 0x00d8aae4u, 13, "FUN_00635d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635a30u, 0x00235a30u, 0x00d8aae4u, 14, "FUN_00635a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635a30u, 0x00235a30u, 0x00d8aae4u, 15, "FUN_00635a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005520d0u, 0x001520d0u, 0x00d8aae4u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635870u, 0x00235870u, 0x00d8aae4u, 17, "FUN_00635870", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006358d0u, 0x002358d0u, 0x00d8aae4u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635950u, 0x00235950u, 0x00d8aae4u, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635820u, 0x00235820u, 0x00d8aae4u, 20, "FUN_00635820", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006359d0u, 0x002359d0u, 0x00d8aae4u, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
