#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlMatch_detail::ReportStatsTask
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_a3f81dc5ee69309d {
inline constexpr char name[] = "rage::rlMatch_detail::ReportStatsTask";
inline constexpr char mangled[] = ".?AVReportStatsTask@rlMatch_detail@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlMatch_detail::Task;rage::rlTask<rage::rlMatch>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c699cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc699cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f077c0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd828u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_a3f81dc5ee69309d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00774d00u, 0x00374d00u, 0x00ebd828u, 0, "FUN_00774d00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055c570u, 0x0015c570u, 0x00ebd828u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00774de0u, 0x00374de0u, 0x00ebd828u, 2, "FUN_00774de0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00774f30u, 0x00374f30u, 0x00ebd828u, 3, "FUN_00774f30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00ebd828u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00774ec0u, 0x00374ec0u, 0x00ebd828u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
