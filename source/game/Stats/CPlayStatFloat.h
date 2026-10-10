#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPlayStatFloat
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPlayStatFloat;
} }

namespace reiv { namespace memory_map { namespace type_4255dbcc6c86aafd {
inline constexpr char name[] = "CPlayStatFloat";
inline constexpr char mangled[] = ".?AVCPlayStatFloat@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPlayStatBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f1ccdcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b1ccdcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec0aacu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d5b21cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_4255dbcc6c86aafd {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0081e790u, 0x0041e790u, 0x00d5b21cu, 0, "FUN_0081e790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009180f0u, 0x005180f0u, 0x00d5b21cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bcb2b0u, 0x007cb2b0u, 0x00d5b21cu, 2, "FUN_00bcb2b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008200f0u, 0x004200f0u, 0x00d5b21cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00820130u, 0x00420130u, 0x00d5b21cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
