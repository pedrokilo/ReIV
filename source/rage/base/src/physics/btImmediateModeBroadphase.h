#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::btImmediateModeBroadphase
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class btImmediateModeBroadphase;
} }

namespace reiv { namespace memory_map { namespace type_e1b50eba7ea980ca {
inline constexpr char name[] = "rage::btImmediateModeBroadphase";
inline constexpr char mangled[] = ".?AVbtImmediateModeBroadphase@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phBroadPhase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c55ecu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc55ecu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05390u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebbe3cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e1b50eba7ea980ca {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 18u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006a2010u, 0x002a2010u, 0x00ebbe3cu, 0, "FUN_006a2010", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1d60u, 0x002a1d60u, 0x00ebbe3cu, 1, "FUN_006a1d60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1cc0u, 0x002a1cc0u, 0x00ebbe3cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a2370u, 0x002a2370u, 0x00ebbe3cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cad10u, 0x001cad10u, 0x00ebbe3cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00784520u, 0x00384520u, 0x00ebbe3cu, 5, "FUN_00784520", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1de0u, 0x002a1de0u, 0x00ebbe3cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1e90u, 0x002a1e90u, 0x00ebbe3cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0073e470u, 0x0033e470u, 0x00ebbe3cu, 8, "FUN_0073e470", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1ed0u, 0x002a1ed0u, 0x00ebbe3cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1c70u, 0x002a1c70u, 0x00ebbe3cu, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1a30u, 0x002a1a30u, 0x00ebbe3cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1f40u, 0x002a1f40u, 0x00ebbe3cu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00ebbe3cu, 13, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006a1f30u, 0x002a1f30u, 0x00ebbe3cu, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1a30u, 0x002a1a30u, 0x00ebbe3cu, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00401210u, 0x00001210u, 0x00ebbe3cu, 16, "fatal_assertion_handler_do_not_call", "", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCam.h:70; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called; reversing/NMutils/evidence/00401210.txt; complete fatal handler excluded; no runtime call attempted", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1a60u, 0x002a1a60u, 0x00ebbe3cu, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
