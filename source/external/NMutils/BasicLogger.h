#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: NMutils::BasicLogger
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace NMutils {
class BasicLogger;
} }

namespace reiv { namespace memory_map { namespace type_d80d8f058a63b4f2 {
inline constexpr char name[] = "NMutils::BasicLogger";
inline constexpr char mangled[] = ".?AVBasicLogger@NMutils@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3bc8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3bc8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03040u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba548u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d80d8f058a63b4f2 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005d4f40u, 0x001d4f40u, 0x00eba548u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; docs/MemoryMap/NMutilsValidation.md; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)", AddressOrigin::VirtualSlot, true, false, false},
    {0x005d67f0u, 0x001d67f0u, 0x00eba548u, 1, "FUN_005d67f0", "", "docs/MemoryMap/virtual_slots.csv; ; docs/MemoryMap/NMutilsValidation.md; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)", AddressOrigin::VirtualSlot, true, false, false},
    {0x00401210u, 0x00001210u, 0x00eba548u, 2, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; docs/MemoryMap/NMutilsValidation.md; binary body and helper provoke process termination; excluded from runtime test; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x005d67a0u, 0x001d67a0u, 0x00eba548u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; docs/MemoryMap/NMutilsValidation.md; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
