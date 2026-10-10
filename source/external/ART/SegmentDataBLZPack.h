#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::SegmentDataBLZPack
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace ART {
class SegmentDataBLZPack;
} }

namespace reiv { namespace memory_map { namespace type_69bf9d5c2ea9d3a0 {
inline constexpr char name[] = "ART::SegmentDataBLZPack";
inline constexpr char mangled[] = ".?AVSegmentDataBLZPack@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::SegmentDataProcessor";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3efcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3efcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f036f8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba6f0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_69bf9d5c2ea9d3a0 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005e2b20u, 0x001e2b20u, 0x00eba6f0u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004489d0u, 0x000489d0u, 0x00eba6f0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004489d0u, 0x000489d0u, 0x00eba6f0u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005e2b50u, 0x001e2b50u, 0x00eba6f0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e2ca0u, 0x001e2ca0u, 0x00eba6f0u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
