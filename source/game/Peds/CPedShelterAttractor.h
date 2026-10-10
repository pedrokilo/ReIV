#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedShelterAttractor
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedShelterAttractor;
} }

namespace reiv { namespace memory_map { namespace type_d091aed68479b82e {
inline constexpr char name[] = "CPedShelterAttractor";
inline constexpr char mangled[] = ".?AVCPedShelterAttractor@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPedAttractor";
inline constexpr std::uint32_t type_descriptor_va = 0x00f42ac4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b42ac4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed0e78u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dccc2cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d091aed68479b82e {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x004c7a20u, 0x000c7a20u, 0x00dccc2cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cc2ee0u, 0x008c2ee0u, 0x00dccc2cu, 1, "FUN_00cc2ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00919b60u, 0x00519b60u, 0x00dccc2cu, 2, "FUN_00919b60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc20c0u, 0x008c20c0u, 0x00dccc2cu, 3, "FUN_00cc20c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc1820u, 0x008c1820u, 0x00dccc2cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc3620u, 0x008c3620u, 0x00dccc2cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
