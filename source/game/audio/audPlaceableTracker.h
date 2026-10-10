#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audPlaceableTracker
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audPlaceableTracker;
} }

namespace reiv { namespace memory_map { namespace type_7f3e0ce44800c407 {
inline constexpr char name[] = "audPlaceableTracker";
inline constexpr char mangled[] = ".?AVaudPlaceableTracker@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audTracker";
inline constexpr std::uint32_t type_descriptor_va = 0x00f21f50u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b21f50u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec1664u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d69690u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_7f3e0ce44800c407 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0089bbc0u, 0x0049bbc0u, 0x00d69690u, 0, "FUN_0089bbc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c57900u, 0x00857900u, 0x00d69690u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089bbb0u, 0x0049bbb0u, 0x00d69690u, 2, "FUN_0089bbb0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AudioValidation/evidence/runtime-summary.json; 64 calls; set_u32 at synthetic offset/value 8; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
