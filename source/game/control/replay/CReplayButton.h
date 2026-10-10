#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CReplayButton
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CReplayButton;
} }

namespace reiv { namespace memory_map { namespace type_11d6756fb3438acf {
inline constexpr char name[] = "CReplayButton";
inline constexpr char mangled[] = ".?AVCReplayButton@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CReplayWidget";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3fcc8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3fcc8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecead8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbbdecu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_11d6756fb3438acf {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c3aa10u, 0x0083aa10u, 0x00dbbdecu, 0, "FUN_00c3aa10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c3a5e0u, 0x0083a5e0u, 0x00dbbdecu, 1, "FUN_00c3a5e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c3a850u, 0x0083a850u, 0x00dbbdecu, 2, "FUN_00c3a850", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
