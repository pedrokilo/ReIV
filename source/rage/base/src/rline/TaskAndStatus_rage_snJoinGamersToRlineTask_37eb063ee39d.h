#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::TaskAndStatus<rage::snJoinGamersToRlineTask>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_d27553fa5ce39e85 {
inline constexpr char name[] = "rage::TaskAndStatus<rage::snJoinGamersToRlineTask>";
inline constexpr char mangled[] = ".?AV?$TaskAndStatus@VsnJoinGamersToRlineTask@rage@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::snJoinGamersToRlineTask;rage::snTask;rage::rlTask<rage::snSession>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1538u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1538u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efec18u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb7e8cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d27553fa5ce39e85 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005432e0u, 0x001432e0u, 0x00eb7e8cu, 0, "FUN_005432e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0053cb00u, 0x0013cb00u, 0x00eb7e8cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00579280u, 0x00179280u, 0x00eb7e8cu, 2, "FUN_00579280", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005793b0u, 0x001793b0u, 0x00eb7e8cu, 3, "FUN_005793b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00eb7e8cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00579330u, 0x00179330u, 0x00eb7e8cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
