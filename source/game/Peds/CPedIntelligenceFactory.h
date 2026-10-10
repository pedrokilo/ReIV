#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPedIntelligenceFactory
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPedIntelligenceFactory;
} }

namespace reiv { namespace memory_map { namespace type_baf5de4f03301012 {
inline constexpr char name[] = "CPedIntelligenceFactory";
inline constexpr char mangled[] = ".?AVCPedIntelligenceFactory@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f33cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f33cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec326cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d72834u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_baf5de4f03301012 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00924dc0u, 0x00524dc0u, 0x00d72834u, 0, "FUN_00924dc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00d72834u, 1, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
