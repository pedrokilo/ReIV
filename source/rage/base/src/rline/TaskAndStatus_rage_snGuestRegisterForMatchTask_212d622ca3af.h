#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::TaskAndStatus<rage::snGuestRegisterForMatchTask>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_6b83a834cbb1f5ca {
inline constexpr char name[] = "rage::TaskAndStatus<rage::snGuestRegisterForMatchTask>";
inline constexpr char mangled[] = ".?AV?$TaskAndStatus@VsnGuestRegisterForMatchTask@rage@@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::snGuestRegisterForMatchTask;rage::snTask;rage::rlTask<rage::snSession>;rage::rlTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1618u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1618u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efed48u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb7e54u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_6b83a834cbb1f5ca {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0057a530u, 0x0017a530u, 0x00eb7e54u, 0, "FUN_0057a530", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0053cb50u, 0x0013cb50u, 0x00eb7e54u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0057b3a0u, 0x0017b3a0u, 0x00eb7e54u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0057dc00u, 0x0017dc00u, 0x00eb7e54u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00542290u, 0x00142290u, 0x00eb7e54u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0057b450u, 0x0017b450u, 0x00eb7e54u, 5, "FUN_0057b450", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
