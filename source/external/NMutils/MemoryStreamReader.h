#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: NMutils::MemoryStreamReader
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace NMutils {
class MemoryStreamReader;
} }

namespace reiv { namespace memory_map { namespace type_b06882f8db2202be {
inline constexpr char name[] = "NMutils::MemoryStreamReader";
inline constexpr char mangled[] = ".?AVMemoryStreamReader@NMutils@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3ed0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3ed0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f036b0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba6c8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b06882f8db2202be {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005e1820u, 0x001e1820u, 0x00eba6c8u, 0, "FUN_005e1820", "", "docs/MemoryMap/virtual_slots.csv; ; docs/MemoryMap/NMutilsValidation.md; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
