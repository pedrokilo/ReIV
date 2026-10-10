#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::fragDrawable
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class fragDrawable;
} }

namespace reiv { namespace memory_map { namespace type_9a9e4ce822200af8 {
inline constexpr char name[] = "rage::fragDrawable";
inline constexpr char mangled[] = ".?AVfragDrawable@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::rmcDrawable;rage::rmcDrawableBase;rage::pgBase;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c20ecu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc20ecu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00effce4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb813cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_9a9e4ce822200af8 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 23u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00552200u, 0x00152200u, 0x00eb813cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006353a0u, 0x002353a0u, 0x00eb813cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006353d0u, 0x002353d0u, 0x00eb813cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635390u, 0x00235390u, 0x00eb813cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447970u, 0x00047970u, 0x00eb813cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00552e80u, 0x00152e80u, 0x00eb813cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635660u, 0x00235660u, 0x00eb813cu, 6, "FUN_00635660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635d70u, 0x00235d70u, 0x00eb813cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635dd0u, 0x00235dd0u, 0x00eb813cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635da0u, 0x00235da0u, 0x00eb813cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635e00u, 0x00235e00u, 0x00eb813cu, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635e30u, 0x00235e30u, 0x00eb813cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635ee0u, 0x00235ee0u, 0x00eb813cu, 12, "FUN_00635ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635d30u, 0x00235d30u, 0x00eb813cu, 13, "FUN_00635d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635a30u, 0x00235a30u, 0x00eb813cu, 14, "FUN_00635a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635a30u, 0x00235a30u, 0x00eb813cu, 15, "FUN_00635a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005520d0u, 0x001520d0u, 0x00eb813cu, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635870u, 0x00235870u, 0x00eb813cu, 17, "FUN_00635870", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006358d0u, 0x002358d0u, 0x00eb813cu, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635950u, 0x00235950u, 0x00eb813cu, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00635820u, 0x00235820u, 0x00eb813cu, 20, "FUN_00635820", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006359d0u, 0x002359d0u, 0x00eb813cu, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005524e0u, 0x001524e0u, 0x00eb813cu, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
