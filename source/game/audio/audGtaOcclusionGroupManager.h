#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audGtaOcclusionGroupManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audGtaOcclusionGroupManager;
} }

namespace reiv { namespace memory_map { namespace type_56f2b7fb456f8e48 {
inline constexpr char name[] = "audGtaOcclusionGroupManager";
inline constexpr char mangled[] = ".?AVaudGtaOcclusionGroupManager@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audOcclusionGroupManager";
inline constexpr std::uint32_t type_descriptor_va = 0x00f0c1b0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b0c1b0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ebee1cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d50954u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_56f2b7fb456f8e48 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00793af0u, 0x00393af0u, 0x00d50954u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00ac8e60u, 0x006c8e60u, 0x00d50954u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
