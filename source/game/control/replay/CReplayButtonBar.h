#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CReplayButtonBar
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CReplayButtonBar;
} }

namespace reiv { namespace memory_map { namespace type_99bf8614dc2eb21e {
inline constexpr char name[] = "CReplayButtonBar";
inline constexpr char mangled[] = ".?AVCReplayButtonBar@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CReplayWidget";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3fce4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3fce4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eceb24u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbbdfcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_99bf8614dc2eb21e {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c3aab0u, 0x0083aab0u, 0x00dbbdfcu, 0, "FUN_00c3aab0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c3ba50u, 0x0083ba50u, 0x00dbbdfcu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c3a9d0u, 0x0083a9d0u, 0x00dbbdfcu, 2, "FUN_00c3a9d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
