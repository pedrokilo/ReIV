#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phJoint3Dof
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phJoint3Dof;
} }

namespace reiv { namespace memory_map { namespace type_419f9ceaa2c410df {
inline constexpr char name[] = "rage::phJoint3Dof";
inline constexpr char mangled[] = ".?AVphJoint3Dof@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phJoint";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1310u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1310u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe8d8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb7a14u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_419f9ceaa2c410df {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 32u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00534b90u, 0x00134b90u, 0x00eb7a14u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x0071c220u, 0x0031c220u, 0x00eb7a14u, 1, "FUN_0071c220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718210u, 0x00318210u, 0x00eb7a14u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00534c80u, 0x00134c80u, 0x00eb7a14u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00717a90u, 0x00317a90u, 0x00eb7a14u, 4, "FUN_00717a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00717ea0u, 0x00317ea0u, 0x00eb7a14u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718060u, 0x00318060u, 0x00eb7a14u, 6, "FUN_00718060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718140u, 0x00318140u, 0x00eb7a14u, 7, "FUN_00718140", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007182b0u, 0x003182b0u, 0x00eb7a14u, 8, "FUN_007182b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007183a0u, 0x003183a0u, 0x00eb7a14u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718600u, 0x00318600u, 0x00eb7a14u, 10, "FUN_00718600", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718730u, 0x00318730u, 0x00eb7a14u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00718860u, 0x00318860u, 0x00eb7a14u, 12, "FUN_00718860", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007190f0u, 0x003190f0u, 0x00eb7a14u, 13, "FUN_007190f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00715f80u, 0x00315f80u, 0x00eb7a14u, 14, "FUN_00715f80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00715fd0u, 0x00315fd0u, 0x00eb7a14u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00534ef0u, 0x00134ef0u, 0x00eb7a14u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 560; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006fe5e0u, 0x002fe5e0u, 0x00eb7a14u, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0071c500u, 0x0031c500u, 0x00eb7a14u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00719480u, 0x00319480u, 0x00eb7a14u, 19, "FUN_00719480", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071a040u, 0x0031a040u, 0x00eb7a14u, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00719d70u, 0x00319d70u, 0x00eb7a14u, 21, "FUN_00719d70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071a1e0u, 0x0031a1e0u, 0x00eb7a14u, 22, "FUN_0071a1e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071a9f0u, 0x0031a9f0u, 0x00eb7a14u, 23, "FUN_0071a9f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071b800u, 0x0031b800u, 0x00eb7a14u, 24, "FUN_0071b800", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071b500u, 0x0031b500u, 0x00eb7a14u, 25, "FUN_0071b500", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071bb00u, 0x0031bb00u, 0x00eb7a14u, 26, "FUN_0071bb00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071bb80u, 0x0031bb80u, 0x00eb7a14u, 27, "FUN_0071bb80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071be90u, 0x0031be90u, 0x00eb7a14u, 28, "FUN_0071be90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071bc00u, 0x0031bc00u, 0x00eb7a14u, 29, "FUN_0071bc00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071c120u, 0x0031c120u, 0x00eb7a14u, 30, "FUN_0071c120", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0071c1a0u, 0x0031c1a0u, 0x00eb7a14u, 31, "FUN_0071c1a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
