#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CTaskComplexSeekCoverShooting
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CTaskComplexSeekCoverShooting;
} }

namespace reiv { namespace memory_map { namespace type_15c6118af5e8aac5 {
inline constexpr char name[] = "CTaskComplexSeekCoverShooting";
inline constexpr char mangled[] = ".?AVCTaskComplexSeekCoverShooting@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CTaskComplexSeekCover;CTaskComplex;CTask";
inline constexpr std::uint32_t type_descriptor_va = 0x00f37278u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b37278u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec8758u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d8dfacu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_15c6118af5e8aac5 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 23u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cb86e0u, 0x008b86e0u, 0x00d8dfacu, 0, "FUN_00cb86e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb8380u, 0x008b8380u, 0x00d8dfacu, 1, "FUN_00cb8380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8dfacu, 2, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a74c20u, 0x00674c20u, 0x00d8dfacu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d8dfacu, 4, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cb5b00u, 0x008b5b00u, 0x00d8dfacu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004388c0u, 0x000388c0u, 0x00d8dfacu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00438910u, 0x00038910u, 0x00d8dfacu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004388d0u, 0x000388d0u, 0x00d8dfacu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8dfacu, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d8dfacu, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8dfacu, 11, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8dfacu, 12, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004388f0u, 0x000388f0u, 0x00d8dfacu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d8dfacu, 14, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a28790u, 0x00628790u, 0x00d8dfacu, 15, "FUN_00a28790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a287d0u, 0x006287d0u, 0x00d8dfacu, 16, "FUN_00a287d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a28760u, 0x00628760u, 0x00d8dfacu, 17, "FUN_00a28760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb78f0u, 0x008b78f0u, 0x00d8dfacu, 18, "FUN_00cb78f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb7850u, 0x008b7850u, 0x00d8dfacu, 19, "FUN_00cb7850", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb7b80u, 0x008b7b80u, 0x00d8dfacu, 20, "FUN_00cb7b80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb8330u, 0x008b8330u, 0x00d8dfacu, 21, "FUN_00cb8330", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cb56a0u, 0x008b56a0u, 0x00d8dfacu, 22, "FUN_00cb56a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
