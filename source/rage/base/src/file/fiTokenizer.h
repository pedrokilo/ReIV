#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::fiTokenizer
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class fiTokenizer;
} }

namespace reiv { namespace memory_map { namespace type_e1ccae49d48ca576 {
inline constexpr char name[] = "rage::fiTokenizer";
inline constexpr char mangled[] = ".?AVfiTokenizer@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::fiAsciiTokenizer;rage::fiBaseTokenizer";
inline constexpr std::uint32_t type_descriptor_va = 0x010c391cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc391cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f02a2cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba0d4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e1ccae49d48ca576 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 41u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00520120u, 0x00120120u, 0x00eba0d4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00eba0d4u, 1, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005c7120u, 0x001c7120u, 0x00eba0d4u, 2, "FUN_005c7120", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cad30u, 0x001cad30u, 0x00eba0d4u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005cad30u, 0x001cad30u, 0x00eba0d4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7750u, 0x001c7750u, 0x00eba0d4u, 5, "FUN_005c7750", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c77a0u, 0x001c77a0u, 0x00eba0d4u, 6, "FUN_005c77a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7910u, 0x001c7910u, 0x00eba0d4u, 7, "FUN_005c7910", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c78c0u, 0x001c78c0u, 0x00eba0d4u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7870u, 0x001c7870u, 0x00eba0d4u, 9, "FUN_005c7870", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7830u, 0x001c7830u, 0x00eba0d4u, 10, "FUN_005c7830", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7800u, 0x001c7800u, 0x00eba0d4u, 11, "FUN_005c7800", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7990u, 0x001c7990u, 0x00eba0d4u, 12, "FUN_005c7990", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c79b0u, 0x001c79b0u, 0x00eba0d4u, 13, "FUN_005c79b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c79e0u, 0x001c79e0u, 0x00eba0d4u, 14, "FUN_005c79e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7b10u, 0x001c7b10u, 0x00eba0d4u, 15, "FUN_005c7b10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ad0u, 0x001c7ad0u, 0x00eba0d4u, 16, "FUN_005c7ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a90u, 0x001c7a90u, 0x00eba0d4u, 17, "FUN_005c7a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a50u, 0x001c7a50u, 0x00eba0d4u, 18, "FUN_005c7a50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7a10u, 0x001c7a10u, 0x00eba0d4u, 19, "FUN_005c7a10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7b50u, 0x001c7b50u, 0x00eba0d4u, 20, "FUN_005c7b50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ba0u, 0x001c7ba0u, 0x00eba0d4u, 21, "FUN_005c7ba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7d30u, 0x001c7d30u, 0x00eba0d4u, 22, "FUN_005c7d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ce0u, 0x001c7ce0u, 0x00eba0d4u, 23, "FUN_005c7ce0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7c90u, 0x001c7c90u, 0x00eba0d4u, 24, "FUN_005c7c90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7c40u, 0x001c7c40u, 0x00eba0d4u, 25, "FUN_005c7c40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7bf0u, 0x001c7bf0u, 0x00eba0d4u, 26, "FUN_005c7bf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7d80u, 0x001c7d80u, 0x00eba0d4u, 27, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7e40u, 0x001c7e40u, 0x00eba0d4u, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7ef0u, 0x001c7ef0u, 0x00eba0d4u, 29, "FUN_005c7ef0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7f10u, 0x001c7f10u, 0x00eba0d4u, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00520110u, 0x00120110u, 0x00eba0d4u, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c82c0u, 0x001c82c0u, 0x00eba0d4u, 32, "FUN_005c82c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8240u, 0x001c8240u, 0x00eba0d4u, 33, "FUN_005c8240", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c81d0u, 0x001c81d0u, 0x00eba0d4u, 34, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8170u, 0x001c8170u, 0x00eba0d4u, 35, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8120u, 0x001c8120u, 0x00eba0d4u, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c7fe0u, 0x001c7fe0u, 0x00eba0d4u, 37, "FUN_005c7fe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8350u, 0x001c8350u, 0x00eba0d4u, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c8080u, 0x001c8080u, 0x00eba0d4u, 39, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005c80d0u, 0x001c80d0u, 0x00eba0d4u, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
