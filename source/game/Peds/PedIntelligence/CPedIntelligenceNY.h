#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedIntelligenceNY
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedIntelligenceNY;
} }

namespace reiv { namespace memory_map { namespace type_dacb5ad68c2f6ee1 {
inline constexpr char name[] = "CPedIntelligenceNY";
inline constexpr char mangled[] = ".?AVCPedIntelligenceNY@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPedIntelligence";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f958u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f958u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed3fd4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9f3dcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_dacb5ad68c2f6ee1 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00451a70u, 0x00051a70u, 0x00e9f3dcu, 0, "FUN_00451a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451a10u, 0x00051a10u, 0x00e9f3dcu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451a10u, 0x00051a10u, 0x00e9f3dcu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451ae0u, 0x00051ae0u, 0x00e9f3dcu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451b50u, 0x00051b50u, 0x00e9f3dcu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451bd0u, 0x00051bd0u, 0x00e9f3dcu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451c00u, 0x00051c00u, 0x00e9f3dcu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451a00u, 0x00051a00u, 0x00e9f3dcu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00451a00u, 0x00051a00u, 0x00e9f3dcu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
