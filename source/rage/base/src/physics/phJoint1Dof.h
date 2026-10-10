#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phJoint1Dof
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phJoint1Dof;
} }

namespace reiv { namespace memory_map { namespace type_600e0589085d6490 {
inline constexpr char name[] = "rage::phJoint1Dof";
inline constexpr char mangled[] = ".?AVphJoint1Dof@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phJoint";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1330u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1330u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe924u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb798cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_600e0589085d6490 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 32u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00534b90u, 0x00134b90u, 0x00eb798cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x006fbc60u, 0x002fbc60u, 0x00eb798cu, 1, "FUN_006fbc60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb530u, 0x002fb530u, 0x00eb798cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00534c80u, 0x00134c80u, 0x00eb798cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb2d0u, 0x002fb2d0u, 0x00eb798cu, 4, "FUN_006fb2d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb370u, 0x002fb370u, 0x00eb798cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb3f0u, 0x002fb3f0u, 0x00eb798cu, 6, "FUN_006fb3f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb480u, 0x002fb480u, 0x00eb798cu, 7, "FUN_006fb480", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb650u, 0x002fb650u, 0x00eb798cu, 8, "FUN_006fb650", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb720u, 0x002fb720u, 0x00eb798cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb550u, 0x002fb550u, 0x00eb798cu, 10, "FUN_006fb550", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb5d0u, 0x002fb5d0u, 0x00eb798cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb7d0u, 0x002fb7d0u, 0x00eb798cu, 12, "FUN_006fb7d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb9b0u, 0x002fb9b0u, 0x00eb798cu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006facf0u, 0x002facf0u, 0x00eb798cu, 14, "FUN_006facf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fb250u, 0x002fb250u, 0x00eb798cu, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00534ef0u, 0x00134ef0u, 0x00eb798cu, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 560; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006fe5e0u, 0x002fe5e0u, 0x00eb798cu, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x007159e0u, 0x003159e0u, 0x00eb798cu, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fba10u, 0x002fba10u, 0x00eb798cu, 19, "FUN_006fba10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fc6a0u, 0x002fc6a0u, 0x00eb798cu, 20, "FUN_006fc6a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fc2f0u, 0x002fc2f0u, 0x00eb798cu, 21, "FUN_006fc2f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fc7e0u, 0x002fc7e0u, 0x00eb798cu, 22, "FUN_006fc7e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00714e20u, 0x00314e20u, 0x00eb798cu, 23, "FUN_00714e20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fcd40u, 0x002fcd40u, 0x00eb798cu, 24, "FUN_006fcd40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fca20u, 0x002fca20u, 0x00eb798cu, 25, "FUN_006fca20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fcb90u, 0x002fcb90u, 0x00eb798cu, 26, "FUN_006fcb90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fceb0u, 0x002fceb0u, 0x00eb798cu, 27, "FUN_006fceb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fd380u, 0x002fd380u, 0x00eb798cu, 28, "FUN_006fd380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fd060u, 0x002fd060u, 0x00eb798cu, 29, "FUN_006fd060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fd1d0u, 0x002fd1d0u, 0x00eb798cu, 30, "FUN_006fd1d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006fd4f0u, 0x002fd4f0u, 0x00eb798cu, 31, "FUN_006fd4f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
