#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::pgBasicScheduler
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class pgBasicScheduler;
} }

namespace reiv { namespace memory_map { namespace type_e33c51b767336ce0 {
inline constexpr char name[] = "rage::pgBasicScheduler";
inline constexpr char mangled[] = ".?AVpgBasicScheduler@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3960u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3960u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f02ac8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba17cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e33c51b767336ce0 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 9u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005c95c0u, 0x001c95c0u, 0x00eba17cu, 0, "FUN_005c95c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c9600u, 0x001c9600u, 0x00eba17cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c96a0u, 0x001c96a0u, 0x00eba17cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c9680u, 0x001c9680u, 0x00eba17cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c97c0u, 0x001c97c0u, 0x00eba17cu, 4, "FUN_005c97c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c9720u, 0x001c9720u, 0x00eba17cu, 5, "FUN_005c9720", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c96d0u, 0x001c96d0u, 0x00eba17cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c9700u, 0x001c9700u, 0x00eba17cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c9830u, 0x001c9830u, 0x00eba17cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
