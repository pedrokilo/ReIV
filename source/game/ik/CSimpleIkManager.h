#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CSimpleIkManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CSimpleIkManager;
} }

namespace reiv { namespace memory_map { namespace type_6efe3749cc5b2d80 {
inline constexpr char name[] = "CSimpleIkManager";
inline constexpr char mangled[] = ".?AVCSimpleIkManager@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a7f4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a7f4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec33d0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d79218u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_6efe3749cc5b2d80 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0094f010u, 0x0054f010u, 0x00d79218u, 0, "FUN_0094f010", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00956d50u, 0x00556d50u, 0x00d79218u, 1, "FUN_00956d50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00956d90u, 0x00556d90u, 0x00d79218u, 2, "FUN_00956d90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
