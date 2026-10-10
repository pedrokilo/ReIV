#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRsCBUShot
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_87800ea19a41c668 {
inline constexpr char name[] = "ART::Rockstar::NmRsCBUShot";
inline constexpr char mangled[] = ".?AVNmRsCBUShot@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::Rockstar::CBUTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c4050u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc4050u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f0394cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba8e4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_87800ea19a41c668 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0060c220u, 0x0020c220u, 0x00eba8e4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc30u, 0x001efc30u, 0x00eba8e4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eba8e4u, 2, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005f2660u, 0x001f2660u, 0x00eba8e4u, 3, "FUN_005f2660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc70u, 0x001efc70u, 0x00eba8e4u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; zero_pair at synthetic field offset/value 12; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005f2790u, 0x001f2790u, 0x00eba8e4u, 5, "FUN_005f2790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005f1e70u, 0x001f1e70u, 0x00eba8e4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; bit_u8 at synthetic field offset/value 636; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005f1f10u, 0x001f1f10u, 0x00eba8e4u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
