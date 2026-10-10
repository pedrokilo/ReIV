#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRsEngine
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_d2dde0ba7ea6629b {
inline constexpr char name[] = "ART::Rockstar::NmRsEngine";
inline constexpr char mangled[] = ".?AVNmRsEngine@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::SubAgentBuilder;ART::SegmentLoader;ART::Engine;ART::TransformSource;ART::IncomingTransformProcessor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3e0cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3e0cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03440u, 0x00f03454u, 0x00f03468u, 0x00f0347cu, 0x00f03490u};
inline constexpr std::uint32_t locators_count = 5u;
inline constexpr std::uint32_t vtables[] = {0x00eba65cu, 0x00eba66cu, 0x00eba67cu, 0x00eba6a0u, 0x00eba6b4u};
inline constexpr std::uint32_t vtables_count = 5u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d2dde0ba7ea6629b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 22u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005e0c90u, 0x001e0c90u, 0x00eba65cu, 0, "FUN_005e0c90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e0ea0u, 0x001e0ea0u, 0x00eba65cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e0fa0u, 0x001e0fa0u, 0x00eba65cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1530u, 0x001e1530u, 0x00eba66cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e0db0u, 0x001e0db0u, 0x00eba66cu, 1, "FUN_005e0db0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e0e30u, 0x001e0e30u, 0x00eba66cu, 2, "FUN_005e0e30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1540u, 0x001e1540u, 0x00eba67cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00eba67cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005e1050u, 0x001e1050u, 0x00eba67cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e10f0u, 0x001e10f0u, 0x00eba67cu, 3, "FUN_005e10f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1220u, 0x001e1220u, 0x00eba67cu, 4, "FUN_005e1220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e10a0u, 0x001e10a0u, 0x00eba67cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00eba67cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005e1470u, 0x001e1470u, 0x00eba67cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1510u, 0x001e1510u, 0x00eba6a0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e13c0u, 0x001e13c0u, 0x00eba6a0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1280u, 0x001e1280u, 0x00eba6a0u, 2, "FUN_005e1280", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eba6a0u, 3, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005e1520u, 0x001e1520u, 0x00eba6b4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e13f0u, 0x001e13f0u, 0x00eba6b4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1410u, 0x001e1410u, 0x00eba6b4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e1430u, 0x001e1430u, 0x00eba6b4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
