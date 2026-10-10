#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtComposerOptimized
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtComposerOptimized;
} }

namespace reiv { namespace memory_map { namespace type_38ce8177b369d59b {
inline constexpr char name[] = "rage::crmtComposerOptimized";
inline constexpr char mangled[] = ".?AVcrmtComposerOptimized@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtComposer;rage::crmtIterator";
inline constexpr std::uint32_t type_descriptor_va = 0x010c09d0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc09d0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd854u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6ee4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_38ce8177b369d59b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 34u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00511d40u, 0x00111d40u, 0x00eb6ee4u, 0, "FUN_00511d40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511da0u, 0x00111da0u, 0x00eb6ee4u, 1, "FUN_00511da0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511de0u, 0x00111de0u, 0x00eb6ee4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00515380u, 0x00115380u, 0x00eb6ee4u, 3, "FUN_00515380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005143d0u, 0x001143d0u, 0x00eb6ee4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511d90u, 0x00111d90u, 0x00eb6ee4u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511e10u, 0x00111e10u, 0x00eb6ee4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511e60u, 0x00111e60u, 0x00eb6ee4u, 7, "FUN_00511e60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511ee0u, 0x00111ee0u, 0x00eb6ee4u, 8, "FUN_00511ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511f80u, 0x00111f80u, 0x00eb6ee4u, 9, "FUN_00511f80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512020u, 0x00112020u, 0x00eb6ee4u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005120c0u, 0x001120c0u, 0x00eb6ee4u, 11, "FUN_005120c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512130u, 0x00112130u, 0x00eb6ee4u, 12, "FUN_00512130", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512200u, 0x00112200u, 0x00eb6ee4u, 13, "FUN_00512200", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512270u, 0x00112270u, 0x00eb6ee4u, 14, "FUN_00512270", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512340u, 0x00112340u, 0x00eb6ee4u, 15, "FUN_00512340", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005123b0u, 0x001123b0u, 0x00eb6ee4u, 16, "FUN_005123b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512450u, 0x00112450u, 0x00eb6ee4u, 17, "FUN_00512450", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005124b0u, 0x001124b0u, 0x00eb6ee4u, 18, "FUN_005124b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512510u, 0x00112510u, 0x00eb6ee4u, 19, "FUN_00512510", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512540u, 0x00112540u, 0x00eb6ee4u, 20, "FUN_00512540", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512560u, 0x00112560u, 0x00eb6ee4u, 21, "FUN_00512560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512590u, 0x00112590u, 0x00eb6ee4u, 22, "FUN_00512590", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005125e0u, 0x001125e0u, 0x00eb6ee4u, 23, "FUN_005125e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512620u, 0x00112620u, 0x00eb6ee4u, 24, "FUN_00512620", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512650u, 0x00112650u, 0x00eb6ee4u, 25, "FUN_00512650", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512670u, 0x00112670u, 0x00eb6ee4u, 26, "FUN_00512670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005126f0u, 0x001126f0u, 0x00eb6ee4u, 27, "FUN_005126f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511d10u, 0x00111d10u, 0x00eb6ee4u, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00512af0u, 0x00112af0u, 0x00eb6ee4u, 29, "FUN_00512af0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00513060u, 0x00113060u, 0x00eb6ee4u, 30, "FUN_00513060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005130c0u, 0x001130c0u, 0x00eb6ee4u, 31, "FUN_005130c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00513160u, 0x00113160u, 0x00eb6ee4u, 32, "FUN_00513160", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005132e0u, 0x001132e0u, 0x00eb6ee4u, 33, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
