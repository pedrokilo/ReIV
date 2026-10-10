#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::netBandwidthRecorder
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class netBandwidthRecorder;
} }

namespace reiv { namespace memory_map { namespace type_d44bc93476a81e69 {
inline constexpr char name[] = "rage::netBandwidthRecorder";
inline constexpr char mangled[] = ".?AVnetBandwidthRecorder@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::netPacketRecorder";
inline constexpr std::uint32_t type_descriptor_va = 0x010c65d8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc65d8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f070dcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd6e8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d44bc93476a81e69 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0076c1f0u, 0x0036c1f0u, 0x00ebd6e8u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0076c220u, 0x0036c220u, 0x00ebd6e8u, 1, "FUN_0076c220", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0076c370u, 0x0036c370u, 0x00ebd6e8u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0076c3f0u, 0x0036c3f0u, 0x00ebd6e8u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0076c460u, 0x0036c460u, 0x00ebd6e8u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
