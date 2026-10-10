#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CTaskComplexStandGuard
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CTaskComplexStandGuard;
} }

namespace reiv { namespace memory_map { namespace type_fffd5e5dd80ab144 {
inline constexpr char name[] = "CTaskComplexStandGuard";
inline constexpr char mangled[] = ".?AVCTaskComplexStandGuard@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CTaskComplex;CTask";
inline constexpr std::uint32_t type_descriptor_va = 0x00f37528u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b37528u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec8c20u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d8e58cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_fffd5e5dd80ab144 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 22u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00a8fc80u, 0x0068fc80u, 0x00d8e58cu, 0, "FUN_00a8fc80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a89510u, 0x00689510u, 0x00d8e58cu, 1, "FUN_00a89510", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8e58cu, 2, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a76ad0u, 0x00676ad0u, 0x00d8e58cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d8e58cu, 4, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a7ba70u, 0x0067ba70u, 0x00d8e58cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004388c0u, 0x000388c0u, 0x00d8e58cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00438910u, 0x00038910u, 0x00d8e58cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004388d0u, 0x000388d0u, 0x00d8e58cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8e58cu, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8e58cu, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8e58cu, 11, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8e58cu, 12, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004388f0u, 0x000388f0u, 0x00d8e58cu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8e58cu, 14, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a28790u, 0x00628790u, 0x00d8e58cu, 15, "FUN_00a28790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a287d0u, 0x006287d0u, 0x00d8e58cu, 16, "FUN_00a287d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a28760u, 0x00628760u, 0x00d8e58cu, 17, "FUN_00a28760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a8fd50u, 0x0068fd50u, 0x00d8e58cu, 18, "FUN_00a8fd50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a8fcb0u, 0x0068fcb0u, 0x00d8e58cu, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a8ff70u, 0x0068ff70u, 0x00d8e58cu, 20, "FUN_00a8ff70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a76ae0u, 0x00676ae0u, 0x00d8e58cu, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
