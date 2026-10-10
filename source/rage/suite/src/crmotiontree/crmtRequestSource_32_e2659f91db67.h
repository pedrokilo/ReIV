#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestSource<32>
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_6d00db2e0098fa8d {
inline constexpr char name[] = "rage::crmtRequestSource<32>";
inline constexpr char mangled[] = ".?AV?$crmtRequestSource@$0CA@@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c06d4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc06d4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd2bcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6d34u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_6d00db2e0098fa8d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0050fb60u, 0x0010fb60u, 0x00eb6d34u, 0, "FUN_0050fb60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050fa40u, 0x0010fa40u, 0x00eb6d34u, 1, "FUN_0050fa40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00eb6d34u, 2, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called; reversing/NMutils/evidence/00401210.txt; complete fatal handler excluded; no runtime call attempted", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
