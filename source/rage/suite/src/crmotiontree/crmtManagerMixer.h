#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtManagerMixer
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtManagerMixer;
} }

namespace reiv { namespace memory_map { namespace type_83a655d1fce43fe3 {
inline constexpr char name[] = "rage::crmtManagerMixer";
inline constexpr char mangled[] = ".?AVcrmtManagerMixer@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtManager";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0544u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0544u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efcfb8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6bfcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_83a655d1fce43fe3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0050c020u, 0x0010c020u, 0x00eb6bfcu, 0, "FUN_0050c020", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c080u, 0x0010c080u, 0x00eb6bfcu, 1, "FUN_0050c080", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c0b0u, 0x0010c0b0u, 0x00eb6bfcu, 2, "FUN_0050c0b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050f4d0u, 0x0010f4d0u, 0x00eb6bfcu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a850u, 0x0015a850u, 0x00eb6bfcu, 4, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0050c2f0u, 0x0010c2f0u, 0x00eb6bfcu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c3d0u, 0x0010c3d0u, 0x00eb6bfcu, 6, "FUN_0050c3d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050c410u, 0x0010c410u, 0x00eb6bfcu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
