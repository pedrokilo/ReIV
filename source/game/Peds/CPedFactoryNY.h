#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedFactoryNY
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedFactoryNY;
} }

namespace reiv { namespace memory_map { namespace type_c991abee8d941e5d {
inline constexpr char name[] = "CPedFactoryNY";
inline constexpr char mangled[] = ".?AVCPedFactoryNY@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPedFactory";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f008u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f008u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ed2d6cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9ec04u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c991abee8d941e5d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00439f20u, 0x00039f20u, 0x00e9ec04u, 0, "FUN_00439f20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00439ff0u, 0x00039ff0u, 0x00e9ec04u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00439f50u, 0x00039f50u, 0x00e9ec04u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0096d440u, 0x0056d440u, 0x00e9ec04u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0043a170u, 0x0003a170u, 0x00e9ec04u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0043a000u, 0x0003a000u, 0x00e9ec04u, 5, "unknown_entry", "CPedFactoryNY::CreatePed", "docs/MemoryMap/virtual_slots.csv; sdk_exact_owner_slot contrib/IV SDK/IV-SDK-main/include/CPedFactoryNY.h:19", AddressOrigin::VirtualSlot, false, false, false},
    {0x0096d480u, 0x0056d480u, 0x00e9ec04u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0043a340u, 0x0003a340u, 0x00e9ec04u, 7, "FUN_0043a340", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0096d5a0u, 0x0056d5a0u, 0x00e9ec04u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0043a720u, 0x0003a720u, 0x00e9ec04u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
