#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CHtmlParser
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CHtmlParser;
} }

namespace reiv { namespace memory_map { namespace type_b1b05ae2e007a489 {
inline constexpr char name[] = "CHtmlParser";
inline constexpr char mangled[] = ".?AVCHtmlParser@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::parStreamInXml;rage::parStreamIn;rage::parStream";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f0ccu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f0ccu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed2e80u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9eca0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b1b05ae2e007a489 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005b5630u, 0x001b5630u, 0x00e9eca0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b57b0u, 0x001b57b0u, 0x00e9eca0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00450680u, 0x00050680u, 0x00e9eca0u, 2, "FUN_00450680", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b6ef0u, 0x001b6ef0u, 0x00e9eca0u, 3, "FUN_005b6ef0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b6f30u, 0x001b6f30u, 0x00e9eca0u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b7000u, 0x001b7000u, 0x00e9eca0u, 5, "FUN_005b7000", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b6fe0u, 0x001b6fe0u, 0x00e9eca0u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b7070u, 0x001b7070u, 0x00e9eca0u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b57a0u, 0x001b57a0u, 0x00e9eca0u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005b6f90u, 0x001b6f90u, 0x00e9eca0u, 9, "FUN_005b6f90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
