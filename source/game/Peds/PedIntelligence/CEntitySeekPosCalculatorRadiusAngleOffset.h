#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CEntitySeekPosCalculatorRadiusAngleOffset
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CEntitySeekPosCalculatorRadiusAngleOffset;
} }

namespace reiv { namespace memory_map { namespace type_fcd8275b61cd5d5d {
inline constexpr char name[] = "CEntitySeekPosCalculatorRadiusAngleOffset";
inline constexpr char mangled[] = ".?AVCEntitySeekPosCalculatorRadiusAngleOffset@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CEntitySeekPosCalculator";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3e17cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3e17cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecd9d4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dad9b8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_fcd8275b61cd5d5d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00a63970u, 0x00663970u, 0x00dad9b8u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a63e90u, 0x00663e90u, 0x00dad9b8u, 1, "FUN_00a63e90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
