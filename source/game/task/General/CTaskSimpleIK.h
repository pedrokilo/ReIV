#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CTaskSimpleIK
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CTaskSimpleIK;
} }

namespace reiv { namespace memory_map { namespace type_ffb07a64bc08d575 {
inline constexpr char name[] = "CTaskSimpleIK";
inline constexpr char mangled[] = ".?AVCTaskSimpleIK@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a830u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a830u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec3464u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d79238u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ffb07a64bc08d575 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009543f0u, 0x005543f0u, 0x00d79238u, 0, "FUN_009543f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00957250u, 0x00557250u, 0x00d79238u, 1, "FUN_00957250", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00957230u, 0x00557230u, 0x00d79238u, 2, "FUN_00957230", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0094ea70u, 0x0054ea70u, 0x00d79238u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
