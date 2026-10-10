#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtFrameBufferFixed<50>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_cc0e6e9ed7789baa {
inline constexpr char name[] = "rage::crmtFrameBufferFixed<50>";
inline constexpr char mangled[] = ".?AV?$crmtFrameBufferFixed@$0DC@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtFrameBuffer";
inline constexpr std::uint32_t type_descriptor_va = 0x00f34908u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b34908u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec5ed8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d84018u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_cc0e6e9ed7789baa {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009ee3f0u, 0x005ee3f0u, 0x00d84018u, 0, "FUN_009ee3f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009ee300u, 0x005ee300u, 0x00d84018u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009ee380u, 0x005ee380u, 0x00d84018u, 2, "FUN_009ee380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
