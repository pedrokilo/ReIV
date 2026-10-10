#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedDamageResponse
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedDamageResponse;
} }

namespace reiv { namespace memory_map { namespace type_9d4dbe3986987bf9 {
inline constexpr char name[] = "CPedDamageResponse";
inline constexpr char mangled[] = ".?AVCPedDamageResponse@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f38354u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b38354u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00eca330u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d92e88u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_9d4dbe3986987bf9 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ab9450u, 0x006b9450u, 0x00d92e88u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
