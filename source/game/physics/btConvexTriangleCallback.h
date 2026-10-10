#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: btConvexTriangleCallback
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class btConvexTriangleCallback;
} }

namespace reiv { namespace memory_map { namespace type_00f082871f9de7f6 {
inline constexpr char name[] = "btConvexTriangleCallback";
inline constexpr char mangled[] = ".?AVbtConvexTriangleCallback@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "TriangleCallback";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5d8cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5d8cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f0639cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebd26cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_00f082871f9de7f6 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0074c280u, 0x0034c280u, 0x00ebd26cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0074c560u, 0x0034c560u, 0x00ebd26cu, 1, "FUN_0074c560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
