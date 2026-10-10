#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedStopAttractor
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedStopAttractor;
} }

namespace reiv { namespace memory_map { namespace type_c4e5e65be9ae90de {
inline constexpr char name[] = "CPedStopAttractor";
inline constexpr char mangled[] = ".?AVCPedStopAttractor@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPedAttractor";
inline constexpr std::uint32_t type_descriptor_va = 0x00f42a80u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b42a80u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed0de0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dccbf0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c4e5e65be9ae90de {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00918420u, 0x00518420u, 0x00dccbf0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cc2ee0u, 0x008c2ee0u, 0x00dccbf0u, 1, "FUN_00cc2ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc2040u, 0x008c2040u, 0x00dccbf0u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc18c0u, 0x008c18c0u, 0x00dccbf0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc1980u, 0x008c1980u, 0x00dccbf0u, 4, "FUN_00cc1980", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cc34b0u, 0x008c34b0u, 0x00dccbf0u, 5, "FUN_00cc34b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
