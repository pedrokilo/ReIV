#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::PluginRegistry
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace ART {
class PluginRegistry;
} }

namespace reiv { namespace memory_map { namespace type_ebcfe8a1bec44bcd {
inline constexpr char name[] = "ART::PluginRegistry";
inline constexpr char mangled[] = ".?AVPluginRegistry@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3cf4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3cf4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03240u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba5dcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ebcfe8a1bec44bcd {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005d6cd0u, 0x001d6cd0u, 0x00eba5dcu, 0, "FUN_005d6cd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
