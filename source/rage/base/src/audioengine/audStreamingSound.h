#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audStreamingSound
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audStreamingSound;
} }

namespace reiv { namespace memory_map { namespace type_3b8504c94fec54dc {
inline constexpr char name[] = "rage::audStreamingSound";
inline constexpr char mangled[] = ".?AVaudStreamingSound@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audSound";
inline constexpr std::uint32_t type_descriptor_va = 0x00f433fcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b433fcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed18c0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ddc274u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_3b8504c94fec54dc {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ce1ec0u, 0x008e1ec0u, 0x00ddc274u, 0, "FUN_00ce1ec0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fa0u, 0x008e0fa0u, 0x00ddc274u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1000u, 0x008e1000u, 0x00ddc274u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fd0u, 0x008e0fd0u, 0x00ddc274u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1e60u, 0x008e1e60u, 0x00ddc274u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf03e0u, 0x008f03e0u, 0x00ddc274u, 5, "FUN_00cf03e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0bc0u, 0x008e0bc0u, 0x00ddc274u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf0410u, 0x008f0410u, 0x00ddc274u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cefcb0u, 0x008efcb0u, 0x00ddc274u, 8, "FUN_00cefcb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0092c4d0u, 0x0052c4d0u, 0x00ddc274u, 9, "FUN_0092c4d0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
