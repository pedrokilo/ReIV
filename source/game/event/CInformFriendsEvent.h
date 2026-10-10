#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CInformFriendsEvent
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CInformFriendsEvent;
} }

namespace reiv { namespace memory_map { namespace type_0de4d6435a4cc5a1 {
inline constexpr char name[] = "CInformFriendsEvent";
inline constexpr char mangled[] = ".?AVCInformFriendsEvent@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f273d8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b273d8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec251cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d70e74u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0de4d6435a4cc5a1 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0091c1f0u, 0x0051c1f0u, 0x00d70e74u, 0, "FUN_0091c1f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
