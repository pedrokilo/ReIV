#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CVehInterp
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CVehInterp;
} }

namespace reiv { namespace memory_map { namespace type_063e745b087db4a9 {
inline constexpr char name[] = "CVehInterp";
inline constexpr char mangled[] = ".?AVCVehInterp@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CInterpolator";
inline constexpr std::uint32_t type_descriptor_va = 0x00f0e724u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b0e724u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ebef80u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d52984u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_063e745b087db4a9 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00b04790u, 0x00704790u, 0x00d52984u, 0, "FUN_00b04790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
