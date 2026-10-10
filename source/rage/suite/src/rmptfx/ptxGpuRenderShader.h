#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxGpuRenderShader
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class ptxGpuRenderShader;
} }

namespace reiv { namespace memory_map { namespace type_ac7470c9c346f81a {
inline constexpr char name[] = "rage::ptxGpuRenderShader";
inline constexpr char mangled[] = ".?AVptxGpuRenderShader@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ptxGpuShader;rage::atReferenceCounter;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3ffc8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3ffc8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eceed4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbe364u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ac7470c9c346f81a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c483e0u, 0x008483e0u, 0x00dbe364u, 0, "FUN_00c483e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6e0u, 0x0010b6e0u, 0x00dbe364u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6f0u, 0x0010b6f0u, 0x00dbe364u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005469e0u, 0x001469e0u, 0x00dbe364u, 3, "FUN_005469e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00dbe364u, 4, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
