#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::spdShaft
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class spdShaft;
} }

namespace reiv { namespace memory_map { namespace type_e5c0a5218cf5e918 {
inline constexpr char name[] = "rage::spdShaft";
inline constexpr char mangled[] = ".?AVspdShaft@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::spdApical";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0ec8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0ec8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe11cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb7450u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e5c0a5218cf5e918 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0051f250u, 0x0011f250u, 0x00eb7450u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051f1d0u, 0x0011f1d0u, 0x00eb7450u, 1, "FUN_0051f1d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054ea80u, 0x0014ea80u, 0x00eb7450u, 2, "FUN_0054ea80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054ebd0u, 0x0014ebd0u, 0x00eb7450u, 3, "FUN_0054ebd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054ed20u, 0x0014ed20u, 0x00eb7450u, 4, "FUN_0054ed20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0054ee80u, 0x0014ee80u, 0x00eb7450u, 5, "FUN_0054ee80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
