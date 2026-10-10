#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: NMutils::MemoryStream
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace NMutils {
class MemoryStream;
} }

namespace reiv { namespace memory_map { namespace type_d45cd9ecc2824807 {
inline constexpr char name[] = "NMutils::MemoryStream";
inline constexpr char mangled[] = ".?AVMemoryStream@NMutils@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3eacu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3eacu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03668u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba6d0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d45cd9ecc2824807 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005e1600u, 0x001e1600u, 0x00eba6d0u, 0, "FUN_005e1600", "", "docs/MemoryMap/virtual_slots.csv; ; docs/MemoryMap/NMutilsValidation.md; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
