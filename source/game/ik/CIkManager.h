#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CIkManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CIkManager;
} }

namespace reiv { namespace memory_map { namespace type_79eb2a46fdeaeafd {
inline constexpr char name[] = "CIkManager";
inline constexpr char mangled[] = ".?AVCIkManager@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CSimpleIkManager";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a814u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a814u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec3418u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d79228u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_79eb2a46fdeaeafd {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009501c0u, 0x005501c0u, 0x00d79228u, 0, "FUN_009501c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00956f20u, 0x00556f20u, 0x00d79228u, 1, "FUN_00956f20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00959a90u, 0x00559a90u, 0x00d79228u, 2, "FUN_00959a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
