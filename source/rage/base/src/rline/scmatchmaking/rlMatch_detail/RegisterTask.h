#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlMatch_detail::RegisterTask
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_48f55e924ca2c48a {
inline constexpr char name[] = "rage::rlMatch_detail::RegisterTask";
inline constexpr char mangled[] = ".?AVRegisterTask@rlMatch_detail@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlMatch_detail::Task;rage::rlTask<rage::rlMatch>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c69fcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc69fcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f07868u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd7f0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_48f55e924ca2c48a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00774650u, 0x00374650u, 0x00ebd7f0u, 0, "FUN_00774650", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055c570u, 0x0015c570u, 0x00ebd7f0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00774770u, 0x00374770u, 0x00ebd7f0u, 2, "FUN_00774770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00774ad0u, 0x00374ad0u, 0x00ebd7f0u, 3, "FUN_00774ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00ebd7f0u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007748d0u, 0x003748d0u, 0x00ebd7f0u, 5, "FUN_007748d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
