#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CReplayOverlay
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CReplayOverlay;
} }

namespace reiv { namespace memory_map { namespace type_3530b2f0bd7e8f64 {
inline constexpr char name[] = "CReplayOverlay";
inline constexpr char mangled[] = ".?AVCReplayOverlay@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CReplayWidget";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3fa80u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3fa80u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ece9a4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbae1cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_3530b2f0bd7e8f64 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c32800u, 0x00832800u, 0x00dbae1cu, 0, "FUN_00c32800", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c32820u, 0x00832820u, 0x00dbae1cu, 1, "FUN_00c32820", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c325f0u, 0x008325f0u, 0x00dbae1cu, 2, "FUN_00c325f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
