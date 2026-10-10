#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetBlenderLinInterp
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CNetBlenderLinInterp;
} }

namespace reiv { namespace memory_map { namespace type_81837716a6a0b5bf {
inline constexpr char name[] = "CNetBlenderLinInterp";
inline constexpr char mangled[] = ".?AVCNetBlenderLinInterp@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CNetworkBlender";
inline constexpr std::uint32_t type_descriptor_va = 0x01090a98u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c90a98u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed5e74u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ea0d8cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_81837716a6a0b5bf {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 16u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005091e0u, 0x001091e0u, 0x00ea0d8cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a3eb0u, 0x000a3eb0u, 0x00ea0d8cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a4050u, 0x000a4050u, 0x00ea0d8cu, 2, "FUN_004a4050", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a4910u, 0x000a4910u, 0x00ea0d8cu, 3, "FUN_004a4910", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a4990u, 0x000a4990u, 0x00ea0d8cu, 4, "FUN_004a4990", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00ea0d8cu, 5, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be61f0u, 0x007e61f0u, 0x00ea0d8cu, 6, "FUN_00be61f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 7, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x004a4ea0u, 0x000a4ea0u, 0x00ea0d8cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 9, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00ea0d8cu, 10, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004a49c0u, 0x000a49c0u, 0x00ea0d8cu, 11, "FUN_004a49c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 12, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 13, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 14, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ea0d8cu, 15, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
