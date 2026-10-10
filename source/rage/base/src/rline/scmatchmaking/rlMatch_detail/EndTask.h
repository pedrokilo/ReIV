#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rlMatch_detail::EndTask
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_880cb3a59c98f5a9 {
inline constexpr char name[] = "rage::rlMatch_detail::EndTask";
inline constexpr char mangled[] = ".?AVEndTask@rlMatch_detail@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rlMatch_detail::Task;rage::rlTask<rage::rlMatch>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c693cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc693cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f07718u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd860u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_880cb3a59c98f5a9 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00775a70u, 0x00375a70u, 0x00ebd860u, 0, "FUN_00775a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055c570u, 0x0015c570u, 0x00ebd860u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00775b20u, 0x00375b20u, 0x00ebd860u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/rage/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; complete forward CFG reviewed; defined EAX mask only; expected_nodes_mask describes model paths, not instrumented native coverage", AddressOrigin::VirtualSlot, true, false, false},
    {0x00775ba0u, 0x00375ba0u, 0x00ebd860u, 3, "FUN_00775ba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00ebd860u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00775b40u, 0x00375b40u, 0x00ebd860u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
