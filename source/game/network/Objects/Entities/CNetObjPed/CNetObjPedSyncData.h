#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetObjPed::CNetObjPedSyncData
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_7dda865a9ff8f33d {
inline constexpr char name[] = "CNetObjPed::CNetObjPedSyncData";
inline constexpr char mangled[] = ".?AVCNetObjPedSyncData@CNetObjPed@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CNetworkObject::CNetObjSyncData";
inline constexpr std::uint32_t type_descriptor_va = 0x010909c0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c909c0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed5ca8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ea0cb4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_7dda865a9ff8f33d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00496a10u, 0x00096a10u, 0x00ea0cb4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496d70u, 0x00096d70u, 0x00ea0cb4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496d80u, 0x00096d80u, 0x00ea0cb4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496db0u, 0x00096db0u, 0x00ea0cb4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496dd0u, 0x00096dd0u, 0x00ea0cb4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496e20u, 0x00096e20u, 0x00ea0cb4u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496e30u, 0x00096e30u, 0x00ea0cb4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496e70u, 0x00096e70u, 0x00ea0cb4u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496e80u, 0x00096e80u, 0x00ea0cb4u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00496ea0u, 0x00096ea0u, 0x00ea0cb4u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
