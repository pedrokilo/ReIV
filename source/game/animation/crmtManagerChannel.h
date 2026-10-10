#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: crmtManagerChannel
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class crmtManagerChannel;
} }

namespace reiv { namespace memory_map { namespace type_62647ed864e964ef {
inline constexpr char name[] = "crmtManagerChannel";
inline constexpr char mangled[] = ".?AVcrmtManagerChannel@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtManagerMixer;rage::crmtManager";
inline constexpr std::uint32_t type_descriptor_va = 0x00f34860u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b34860u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec5d94u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d83fb8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_62647ed864e964ef {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009ed8d0u, 0x005ed8d0u, 0x00d83fb8u, 0, "FUN_009ed8d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c080u, 0x0010c080u, 0x00d83fb8u, 1, "FUN_0050c080", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c0b0u, 0x0010c0b0u, 0x00d83fb8u, 2, "FUN_0050c0b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050f4d0u, 0x0010f4d0u, 0x00d83fb8u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a850u, 0x0015a850u, 0x00d83fb8u, 4, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009ed810u, 0x005ed810u, 0x00d83fb8u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009eea90u, 0x005eea90u, 0x00d83fb8u, 6, "FUN_009eea90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009eebd0u, 0x005eebd0u, 0x00d83fb8u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009ee5a0u, 0x005ee5a0u, 0x00d83fb8u, 8, "FUN_009ee5a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
