#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestBlendN
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestBlendN;
} }

namespace reiv { namespace memory_map { namespace type_d30d41c3b1c09598 {
inline constexpr char name[] = "rage::crmtRequestBlendN";
inline constexpr char mangled[] = ".?AVcrmtRequestBlendN@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequestN;rage::crmtRequestSource<32>;rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c068cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc068cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd268u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6d44u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d30d41c3b1c09598 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0050f790u, 0x0010f790u, 0x00eb6d44u, 0, "FUN_0050f790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050fc70u, 0x0010fc70u, 0x00eb6d44u, 1, "FUN_0050fc70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050f810u, 0x0010f810u, 0x00eb6d44u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
