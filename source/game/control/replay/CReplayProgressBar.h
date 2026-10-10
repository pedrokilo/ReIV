#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CReplayProgressBar
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CReplayProgressBar;
} }

namespace reiv { namespace memory_map { namespace type_9686f59ab2495321 {
inline constexpr char name[] = "CReplayProgressBar";
inline constexpr char mangled[] = ".?AVCReplayProgressBar@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CReplayWidget";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3fc74u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3fc74u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecea8cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbb984u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_9686f59ab2495321 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c37e00u, 0x00837e00u, 0x00dbb984u, 0, "FUN_00c37e00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c3a3e0u, 0x0083a3e0u, 0x00dbb984u, 1, "FUN_00c3a3e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c36d30u, 0x00836d30u, 0x00dbb984u, 2, "FUN_00c36d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
