#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CMovementEventHandler
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CMovementEventHandler;
} }

namespace reiv { namespace memory_map { namespace type_08d093ef388731ec {
inline constexpr char name[] = "CMovementEventHandler";
inline constexpr char mangled[] = ".?AVCMovementEventHandler@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f38248u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b38248u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eca1a8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d928f4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_08d093ef388731ec {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ab7ad0u, 0x006b7ad0u, 0x00d928f4u, 0, "FUN_00ab7ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ab7af0u, 0x006b7af0u, 0x00d928f4u, 1, "FUN_00ab7af0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ab7c60u, 0x006b7c60u, 0x00d928f4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ab7d10u, 0x006b7d10u, 0x00d928f4u, 3, "FUN_00ab7d10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
