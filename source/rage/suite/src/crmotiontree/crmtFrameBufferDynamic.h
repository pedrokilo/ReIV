#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtFrameBufferDynamic
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtFrameBufferDynamic;
} }

namespace reiv { namespace memory_map { namespace type_579994503d6e3600 {
inline constexpr char name[] = "rage::crmtFrameBufferDynamic";
inline constexpr char mangled[] = ".?AVcrmtFrameBufferDynamic@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtFrameBuffer";
inline constexpr std::uint32_t type_descriptor_va = 0x010c09fcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc09fcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd924u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6fa0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_579994503d6e3600 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00513ee0u, 0x00113ee0u, 0x00eb6fa0u, 0, "FUN_00513ee0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005140a0u, 0x001140a0u, 0x00eb6fa0u, 1, "FUN_005140a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00514130u, 0x00114130u, 0x00eb6fa0u, 2, "FUN_00514130", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
