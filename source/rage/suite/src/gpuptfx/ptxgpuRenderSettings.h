#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::ptxgpuRenderSettings
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
struct ptxgpuRenderSettings;
} }

namespace reiv { namespace memory_map { namespace type_3df20e3fe4fa4460 {
inline constexpr char name[] = "rage::ptxgpuRenderSettings";
inline constexpr char mangled[] = ".?AUptxgpuRenderSettings@rage@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::ParseClass<rage::ptxgpuRenderSettings>;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1ca0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1ca0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eff714u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dbe3c8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_3df20e3fe4fa4460 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005458b0u, 0x001458b0u, 0x00dbe3c8u, 0, "FUN_005458b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
