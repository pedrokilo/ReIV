#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRsCBUDynamicBalancer
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_47dccf1af559b3fd {
inline constexpr char name[] = "ART::Rockstar::NmRsCBUDynamicBalancer";
inline constexpr char mangled[] = ".?AVNmRsCBUDynamicBalancer@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::Rockstar::CBUTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c40acu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc40acu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f039e4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba92cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_47dccf1af559b3fd {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005f7770u, 0x001f7770u, 0x00eba92cu, 0, "FUN_005f7770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc30u, 0x001efc30u, 0x00eba92cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005f7910u, 0x001f7910u, 0x00eba92cu, 2, "FUN_005f7910", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005f7a30u, 0x001f7a30u, 0x00eba92cu, 3, "FUN_005f7a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc70u, 0x001efc70u, 0x00eba92cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; zero_pair at synthetic field offset/value 12; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005f7ab0u, 0x001f7ab0u, 0x00eba92cu, 5, "FUN_005f7ab0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005f76a0u, 0x001f76a0u, 0x00eba92cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; bit_u8 at synthetic field offset/value 3068; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005f7830u, 0x001f7830u, 0x00eba92cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
