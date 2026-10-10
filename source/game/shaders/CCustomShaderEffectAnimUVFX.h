#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CCustomShaderEffectAnimUVFX
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CCustomShaderEffectAnimUVFX;
} }

namespace reiv { namespace memory_map { namespace type_0f2ff3f90d3b55b9 {
inline constexpr char name[] = "CCustomShaderEffectAnimUVFX";
inline constexpr char mangled[] = ".?AVCCustomShaderEffectAnimUVFX@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CCustomShaderEffectBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43050u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43050u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed17ccu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dd91fcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0f2ff3f90d3b55b9 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 14u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cd7eb0u, 0x008d7eb0u, 0x00dd91fcu, 0, "FUN_00cd7eb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00919b60u, 0x00519b60u, 0x00dd91fcu, 1, "FUN_00919b60", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/game/evidence/scalar-runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; comparison/bit/scalar bodies only; EDX/high return not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cd8560u, 0x008d8560u, 0x00dd91fcu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cd7f50u, 0x008d7f50u, 0x00dd91fcu, 3, "FUN_00cd7f50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cd7dd0u, 0x008d7dd0u, 0x00dd91fcu, 4, "FUN_00cd7dd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cd7e40u, 0x008d7e40u, 0x00dd91fcu, 5, "FUN_00cd7e40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00b3fd20u, 0x0073fd20u, 0x00dd91fcu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cba430u, 0x008ba430u, 0x00dd91fcu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cd8250u, 0x008d8250u, 0x00dd91fcu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00430041u, 0x00030041u, 0x00dd91fcu, 9, "excluded_runtime_vtable_mismatch", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary", AddressOrigin::VirtualSlot, false, false, false},
    {0x00490054u, 0x00090054u, 0x00dd91fcu, 10, "excluded_runtime_vtable_mismatch", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary", AddressOrigin::VirtualSlot, false, false, false},
    {0x004e004fu, 0x000e004fu, 0x00dd91fcu, 11, "excluded_runtime_vtable_mismatch", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary", AddressOrigin::VirtualSlot, false, false, false},
    {0x0049004cu, 0x0009004cu, 0x00dd91fcu, 12, "excluded_runtime_vtable_mismatch", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary", AddressOrigin::VirtualSlot, false, false, false},
    {0x00540053u, 0x00140053u, 0x00dd91fcu, 13, "excluded_runtime_vtable_mismatch", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
