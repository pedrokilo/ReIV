#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::netEventConnectionError
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class netEventConnectionError;
} }

namespace reiv { namespace memory_map { namespace type_000f84f92e784d9e {
inline constexpr char name[] = "rage::netEventConnectionError";
inline constexpr char mangled[] = ".?AVnetEventConnectionError@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::netEvent";
inline constexpr std::uint32_t type_descriptor_va = 0x010c6398u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc6398u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f06d04u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd5dcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_000f84f92e784d9e {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0075f1d0u, 0x0035f1d0u, 0x00ebd5dcu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00777010u, 0x00377010u, 0x00ebd5dcu, 1, "FUN_00777010", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
