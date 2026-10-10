#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::rmPtfxManager
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class rmPtfxManager;
} }

namespace reiv { namespace memory_map { namespace type_5835cd9fe5e7927c {
inline constexpr char name[] = "rage::rmPtfxManager";
inline constexpr char mangled[] = ".?AVrmPtfxManager@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c1020u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc1020u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe3e4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb74a8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_5835cd9fe5e7927c {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00525310u, 0x00125310u, 0x00eb74a8u, 0, "FUN_00525310", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00525db0u, 0x00125db0u, 0x00eb74a8u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00525e90u, 0x00125e90u, 0x00eb74a8u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00525f80u, 0x00125f80u, 0x00eb74a8u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005260b0u, 0x001260b0u, 0x00eb74a8u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005262d0u, 0x001262d0u, 0x00eb74a8u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00526380u, 0x00126380u, 0x00eb74a8u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00526430u, 0x00126430u, 0x00eb74a8u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
