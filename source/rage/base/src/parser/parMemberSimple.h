#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::parMemberSimple
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class parMemberSimple;
} }

namespace reiv { namespace memory_map { namespace type_354cd6e28aa5fbf1 {
inline constexpr char name[] = "rage::parMemberSimple";
inline constexpr char mangled[] = ".?AVparMemberSimple@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::parMember";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3a58u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3a58u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f02cd4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba1d0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_354cd6e28aa5fbf1 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 12u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005c99c0u, 0x001c99c0u, 0x00eba1d0u, 0, "FUN_005c99c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1dc0u, 0x001d1dc0u, 0x00eba1d0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d20b0u, 0x001d20b0u, 0x00eba1d0u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1c30u, 0x001d1c30u, 0x00eba1d0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1de0u, 0x001d1de0u, 0x00eba1d0u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1df0u, 0x001d1df0u, 0x00eba1d0u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1980u, 0x001d1980u, 0x00eba1d0u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d20c0u, 0x001d20c0u, 0x00eba1d0u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1f40u, 0x001d1f40u, 0x00eba1d0u, 8, "FUN_005d1f40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00576590u, 0x00176590u, 0x00eba1d0u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005d1dd0u, 0x001d1dd0u, 0x00eba1d0u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d1970u, 0x001d1970u, 0x00eba1d0u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
