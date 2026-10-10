#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CDispatchOrderArrayHandler
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CDispatchOrderArrayHandler;
} }

namespace reiv { namespace memory_map { namespace type_9e1538482143c509 {
inline constexpr char name[] = "CDispatchOrderArrayHandler";
inline constexpr char mangled[] = ".?AVCDispatchOrderArrayHandler@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CNetworkArrayHandler";
inline constexpr std::uint32_t type_descriptor_va = 0x0108fa18u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8fa18u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed4154u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9f414u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_9e1538482143c509 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 28u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00453b00u, 0x00053b00u, 0x00e9f414u, 0, "FUN_00453b00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a2680u, 0x000a2680u, 0x00e9f414u, 1, "FUN_004a2680", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a28d0u, 0x000a28d0u, 0x00e9f414u, 2, "FUN_004a28d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00e9f414u, 3, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004a2a30u, 0x000a2a30u, 0x00e9f414u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004540a0u, 0x000540a0u, 0x00e9f414u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a2910u, 0x000a2910u, 0x00e9f414u, 6, "FUN_004a2910", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453ae0u, 0x00053ae0u, 0x00e9f414u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00453af0u, 0x00053af0u, 0x00e9f414u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00453b30u, 0x00053b30u, 0x00e9f414u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453b70u, 0x00053b70u, 0x00e9f414u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a37c0u, 0x000a37c0u, 0x00e9f414u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a39e0u, 0x000a39e0u, 0x00e9f414u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3520u, 0x000a3520u, 0x00e9f414u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3ac0u, 0x000a3ac0u, 0x00e9f414u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3af0u, 0x000a3af0u, 0x00e9f414u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453b90u, 0x00053b90u, 0x00e9f414u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453ad0u, 0x00053ad0u, 0x00e9f414u, 17, "FUN_00453ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453bc0u, 0x00053bc0u, 0x00e9f414u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453be0u, 0x00053be0u, 0x00e9f414u, 19, "FUN_00453be0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453cd0u, 0x00053cd0u, 0x00e9f414u, 20, "FUN_00453cd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453e10u, 0x00053e10u, 0x00e9f414u, 21, "FUN_00453e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453ec0u, 0x00053ec0u, 0x00e9f414u, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453f00u, 0x00053f00u, 0x00e9f414u, 23, "FUN_00453f00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00454080u, 0x00054080u, 0x00e9f414u, 24, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3b50u, 0x000a3b50u, 0x00e9f414u, 25, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00454090u, 0x00054090u, 0x00e9f414u, 26, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00454100u, 0x00054100u, 0x00e9f414u, 27, "FUN_00454100", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
