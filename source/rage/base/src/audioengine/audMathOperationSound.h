#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audMathOperationSound
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audMathOperationSound;
} }

namespace reiv { namespace memory_map { namespace type_eded192c92d5b9aa {
inline constexpr char name[] = "rage::audMathOperationSound";
inline constexpr char mangled[] = ".?AVaudMathOperationSound@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audSound";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43928u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43928u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed1d58u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dde95cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_eded192c92d5b9aa {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ce1ec0u, 0x008e1ec0u, 0x00dde95cu, 0, "FUN_00ce1ec0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fa0u, 0x008e0fa0u, 0x00dde95cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1000u, 0x008e1000u, 0x00dde95cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0fd0u, 0x008e0fd0u, 0x00dde95cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1e60u, 0x008e1e60u, 0x00dde95cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfc410u, 0x008fc410u, 0x00dde95cu, 5, "FUN_00cfc410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce0bc0u, 0x008e0bc0u, 0x00dde95cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfbbc0u, 0x008fbbc0u, 0x00dde95cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ce1220u, 0x008e1220u, 0x00dde95cu, 8, "FUN_00ce1220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0092c4d0u, 0x0052c4d0u, 0x00dde95cu, 9, "FUN_0092c4d0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
