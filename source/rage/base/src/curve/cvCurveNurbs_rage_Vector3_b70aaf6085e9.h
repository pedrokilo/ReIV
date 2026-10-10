#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::cvCurveNurbs<rage::Vector3>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_329d7bfd032bbbc5 {
inline constexpr char name[] = "rage::cvCurveNurbs<rage::Vector3>";
inline constexpr char mangled[] = ".?AV?$cvCurveNurbs@VVector3@rage@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::cvCurve<rage::Vector3>";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5ae0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5ae0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05e88u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebcf48u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_329d7bfd032bbbc5 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x007307b0u, 0x003307b0u, 0x00ebcf48u, 0, "FUN_007307b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0072f3f0u, 0x0032f3f0u, 0x00ebcf48u, 1, "FUN_0072f3f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0072f5b0u, 0x0032f5b0u, 0x00ebcf48u, 2, "FUN_0072f5b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0072fc50u, 0x0032fc50u, 0x00ebcf48u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007301e0u, 0x003301e0u, 0x00ebcf48u, 4, "FUN_007301e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00730740u, 0x00330740u, 0x00ebcf48u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00ebcf48u, 6, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007307a0u, 0x003307a0u, 0x00ebcf48u, 7, "FUN_007307a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
