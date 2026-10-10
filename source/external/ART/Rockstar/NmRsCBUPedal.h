#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRsCBUPedal
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_427dbcd56d451861 {
inline constexpr char name[] = "ART::Rockstar::NmRsCBUPedal";
inline constexpr char mangled[] = ".?AVNmRsCBUPedal@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::Rockstar::CBUTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c42d8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc42d8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03d8cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebab60u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_427dbcd56d451861 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0060c220u, 0x0020c220u, 0x00ebab60u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc30u, 0x001efc30u, 0x00ebab60u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0060b0f0u, 0x0020b0f0u, 0x00ebab60u, 2, "FUN_0060b0f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0060b3e0u, 0x0020b3e0u, 0x00ebab60u, 3, "FUN_0060b3e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc70u, 0x001efc70u, 0x00ebab60u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; zero_pair at synthetic field offset/value 12; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0060ba80u, 0x0020ba80u, 0x00ebab60u, 5, "FUN_0060ba80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0060b000u, 0x0020b000u, 0x00ebab60u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u8 at synthetic field offset/value 213; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0060b010u, 0x0020b010u, 0x00ebab60u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
