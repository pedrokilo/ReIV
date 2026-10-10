#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::parStreamOutRbf
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class parStreamOutRbf;
} }

namespace reiv { namespace memory_map { namespace type_3077d7059fbdf8dd {
inline constexpr char name[] = "rage::parStreamOutRbf";
inline constexpr char mangled[] = ".?AVparStreamOutRbf@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::parStreamOut;rage::parStream";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3b08u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3b08u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f02e00u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba3d8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_3077d7059fbdf8dd {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005cf1a0u, 0x001cf1a0u, 0x00eba3d8u, 0, "FUN_005cf1a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf1e0u, 0x001cf1e0u, 0x00eba3d8u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf200u, 0x001cf200u, 0x00eba3d8u, 2, "FUN_005cf200", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf5b0u, 0x001cf5b0u, 0x00eba3d8u, 3, "FUN_005cf5b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf7b0u, 0x001cf7b0u, 0x00eba3d8u, 4, "FUN_005cf7b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf3a0u, 0x001cf3a0u, 0x00eba3d8u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cf780u, 0x001cf780u, 0x00eba3d8u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
