#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::AgentComponentsManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace ART {
class AgentComponentsManager;
} }

namespace reiv { namespace memory_map { namespace type_2b4835eddf975561 {
inline constexpr char name[] = "ART::AgentComponentsManager";
inline constexpr char mangled[] = ".?AVAgentComponentsManager@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::SegmentLoader";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3d58u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3d58u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03318u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba5fcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_2b4835eddf975561 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005d7090u, 0x001d7090u, 0x00eba5fcu, 0, "FUN_005d7090", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d70f0u, 0x001d70f0u, 0x00eba5fcu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d7160u, 0x001d7160u, 0x00eba5fcu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
