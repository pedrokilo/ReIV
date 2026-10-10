#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::fiAsciiTokenizer
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class fiAsciiTokenizer;
} }

namespace reiv { namespace memory_map { namespace type_df1903f3d38b1a56 {
inline constexpr char name[] = "rage::fiAsciiTokenizer";
inline constexpr char mangled[] = ".?AVfiAsciiTokenizer@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::fiBaseTokenizer";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0fc8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0fc8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efe2dcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d7049cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_df1903f3d38b1a56 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 41u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00520120u, 0x00120120u, 0x00d7049cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d7049cu, 1, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005c7120u, 0x001c7120u, 0x00d7049cu, 2, "FUN_005c7120", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cad30u, 0x001cad30u, 0x00d7049cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cad30u, 0x001cad30u, 0x00d7049cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7750u, 0x001c7750u, 0x00d7049cu, 5, "FUN_005c7750", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c77a0u, 0x001c77a0u, 0x00d7049cu, 6, "FUN_005c77a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7910u, 0x001c7910u, 0x00d7049cu, 7, "FUN_005c7910", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c78c0u, 0x001c78c0u, 0x00d7049cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7870u, 0x001c7870u, 0x00d7049cu, 9, "FUN_005c7870", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7830u, 0x001c7830u, 0x00d7049cu, 10, "FUN_005c7830", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7800u, 0x001c7800u, 0x00d7049cu, 11, "FUN_005c7800", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7990u, 0x001c7990u, 0x00d7049cu, 12, "FUN_005c7990", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c79b0u, 0x001c79b0u, 0x00d7049cu, 13, "FUN_005c79b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c79e0u, 0x001c79e0u, 0x00d7049cu, 14, "FUN_005c79e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7b10u, 0x001c7b10u, 0x00d7049cu, 15, "FUN_005c7b10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ad0u, 0x001c7ad0u, 0x00d7049cu, 16, "FUN_005c7ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a90u, 0x001c7a90u, 0x00d7049cu, 17, "FUN_005c7a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a50u, 0x001c7a50u, 0x00d7049cu, 18, "FUN_005c7a50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a10u, 0x001c7a10u, 0x00d7049cu, 19, "FUN_005c7a10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7b50u, 0x001c7b50u, 0x00d7049cu, 20, "FUN_005c7b50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ba0u, 0x001c7ba0u, 0x00d7049cu, 21, "FUN_005c7ba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7d30u, 0x001c7d30u, 0x00d7049cu, 22, "FUN_005c7d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ce0u, 0x001c7ce0u, 0x00d7049cu, 23, "FUN_005c7ce0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7c90u, 0x001c7c90u, 0x00d7049cu, 24, "FUN_005c7c90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7c40u, 0x001c7c40u, 0x00d7049cu, 25, "FUN_005c7c40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7bf0u, 0x001c7bf0u, 0x00d7049cu, 26, "FUN_005c7bf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7d80u, 0x001c7d80u, 0x00d7049cu, 27, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7e40u, 0x001c7e40u, 0x00d7049cu, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ef0u, 0x001c7ef0u, 0x00d7049cu, 29, "FUN_005c7ef0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7f10u, 0x001c7f10u, 0x00d7049cu, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00520110u, 0x00120110u, 0x00d7049cu, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x005c82c0u, 0x001c82c0u, 0x00d7049cu, 32, "FUN_005c82c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8240u, 0x001c8240u, 0x00d7049cu, 33, "FUN_005c8240", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c81d0u, 0x001c81d0u, 0x00d7049cu, 34, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8170u, 0x001c8170u, 0x00d7049cu, 35, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8120u, 0x001c8120u, 0x00d7049cu, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7fe0u, 0x001c7fe0u, 0x00d7049cu, 37, "FUN_005c7fe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8350u, 0x001c8350u, 0x00d7049cu, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8080u, 0x001c8080u, 0x00d7049cu, 39, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c80d0u, 0x001c80d0u, 0x00d7049cu, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
