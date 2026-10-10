#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phRopeContact
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phRopeContact;
} }

namespace reiv { namespace memory_map { namespace type_20e2a73c448b497d {
inline constexpr char name[] = "rage::phRopeContact";
inline constexpr char mangled[] = ".?AVphRopeContact@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phContact";
inline constexpr std::uint32_t type_descriptor_va = 0x010c59f0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc59f0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05bf0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebca64u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_20e2a73c448b497d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 15u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0070bb60u, 0x0030bb60u, 0x00ebca64u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070d5a0u, 0x0030d5a0u, 0x00ebca64u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070d5c0u, 0x0030d5c0u, 0x00ebca64u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070d5f0u, 0x0030d5f0u, 0x00ebca64u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/rage/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; complete forward CFG reviewed; defined EAX mask only; expected_nodes_mask describes model paths, not instrumented native coverage", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070d620u, 0x0030d620u, 0x00ebca64u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/rage/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; complete forward CFG reviewed; defined EAX mask only; expected_nodes_mask describes model paths, not instrumented native coverage", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070d650u, 0x0030d650u, 0x00ebca64u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070d6f0u, 0x0030d6f0u, 0x00ebca64u, 6, "FUN_0070d6f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070d8a0u, 0x0030d8a0u, 0x00ebca64u, 7, "FUN_0070d8a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070db60u, 0x0030db60u, 0x00ebca64u, 8, "FUN_0070db60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070dc20u, 0x0030dc20u, 0x00ebca64u, 9, "FUN_0070dc20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00ebca64u, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070dd40u, 0x0030dd40u, 0x00ebca64u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070dd50u, 0x0030dd50u, 0x00ebca64u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070dd80u, 0x0030dd80u, 0x00ebca64u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070ddf0u, 0x0030ddf0u, 0x00ebca64u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
