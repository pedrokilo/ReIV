#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CParseVehicle
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CParseVehicle;
} }

namespace reiv { namespace memory_map { namespace type_0dadb7153ee465b3 {
inline constexpr char name[] = "CParseVehicle";
inline constexpr char mangled[] = ".?AVCParseVehicle@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CParsePhysical;CParseDynamicEntity;CParseEntity;CParseNetworkObject";
inline constexpr std::uint32_t type_descriptor_va = 0x010c01c8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc01c8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efc904u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb68ecu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0dadb7153ee465b3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 11u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005050b0u, 0x001050b0u, 0x00eb68ecu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00505350u, 0x00105350u, 0x00eb68ecu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005053f0u, 0x001053f0u, 0x00eb68ecu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005054a0u, 0x001054a0u, 0x00eb68ecu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00505990u, 0x00105990u, 0x00eb68ecu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00504190u, 0x00104190u, 0x00eb68ecu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00505ad0u, 0x00105ad0u, 0x00eb68ecu, 6, "FUN_00505ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00504490u, 0x00104490u, 0x00eb68ecu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005044e0u, 0x001044e0u, 0x00eb68ecu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00504530u, 0x00104530u, 0x00eb68ecu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00505db0u, 0x00105db0u, 0x00eb68ecu, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
