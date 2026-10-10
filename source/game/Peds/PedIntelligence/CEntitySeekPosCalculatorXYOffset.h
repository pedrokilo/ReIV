#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CEntitySeekPosCalculatorXYOffset
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CEntitySeekPosCalculatorXYOffset;
} }

namespace reiv { namespace memory_map { namespace type_5fde358b961c8dd6 {
inline constexpr char name[] = "CEntitySeekPosCalculatorXYOffset";
inline constexpr char mangled[] = ".?AVCEntitySeekPosCalculatorXYOffset@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CEntitySeekPosCalculator";
inline constexpr std::uint32_t type_descriptor_va = 0x00f36c34u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b36c34u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec845cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d8c9a8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_5fde358b961c8dd6 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00a63970u, 0x00663970u, 0x00d8c9a8u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a63e10u, 0x00663e10u, 0x00d8c9a8u, 1, "FUN_00a63e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
