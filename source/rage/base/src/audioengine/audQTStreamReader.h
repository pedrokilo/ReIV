#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::audQTStreamReader
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class audQTStreamReader;
} }

namespace reiv { namespace memory_map { namespace type_47bc1abd4ba3e525 {
inline constexpr char name[] = "rage::audQTStreamReader";
inline constexpr char mangled[] = ".?AVaudQTStreamReader@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::CBaseStreamReader";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43538u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43538u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed1a4cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ddcae4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_47bc1abd4ba3e525 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 10u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00cf5b20u, 0x008f5b20u, 0x00ddcae4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf65f0u, 0x008f65f0u, 0x00ddcae4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf5b40u, 0x008f5b40u, 0x00ddcae4u, 2, "FUN_00cf5b40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf6570u, 0x008f6570u, 0x00ddcae4u, 3, "FUN_00cf6570", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf5b90u, 0x008f5b90u, 0x00ddcae4u, 4, "FUN_00cf5b90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf5b80u, 0x008f5b80u, 0x00ddcae4u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 196; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cf5bc0u, 0x008f5bc0u, 0x00ddcae4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 192; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cf5bd0u, 0x008f5bd0u, 0x00ddcae4u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cf5f30u, 0x008f5f30u, 0x00ddcae4u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 208; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00cf5f40u, 0x008f5f40u, 0x00ddcae4u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 273; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
