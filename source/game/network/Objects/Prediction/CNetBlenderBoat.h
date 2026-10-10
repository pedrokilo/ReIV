#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetBlenderBoat
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CNetBlenderBoat;
} }

namespace reiv { namespace memory_map { namespace type_0e85b2c3f5f9adb3 {
inline constexpr char name[] = "CNetBlenderBoat";
inline constexpr char mangled[] = ".?AVCNetBlenderBoat@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CNetBlenderPhysical;CNetBlenderLinInterp;CNetworkBlender";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0394u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0394u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efcca4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6b34u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0e85b2c3f5f9adb3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 16u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005091e0u, 0x001091e0u, 0x00eb6b34u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3eb0u, 0x000a3eb0u, 0x00eb6b34u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00509760u, 0x00109760u, 0x00eb6b34u, 2, "FUN_00509760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507940u, 0x00107940u, 0x00eb6b34u, 3, "FUN_00507940", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507a30u, 0x00107a30u, 0x00eb6b34u, 4, "FUN_00507a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00eb6b34u, 5, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00eb6b34u, 6, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507e40u, 0x00107e40u, 0x00eb6b34u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a4ea0u, 0x000a4ea0u, 0x00eb6b34u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00508f40u, 0x00108f40u, 0x00eb6b34u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00509890u, 0x00109890u, 0x00eb6b34u, 10, "FUN_00509890", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507b70u, 0x00107b70u, 0x00eb6b34u, 11, "FUN_00507b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507cc0u, 0x00107cc0u, 0x00eb6b34u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00508e40u, 0x00108e40u, 0x00eb6b34u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00507ce0u, 0x00107ce0u, 0x00eb6b34u, 14, "FUN_00507ce0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00508f20u, 0x00108f20u, 0x00eb6b34u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
