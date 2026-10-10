#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRsCBUFlinch
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_f9498589b51edfa3 {
inline constexpr char name[] = "ART::Rockstar::NmRsCBUFlinch";
inline constexpr char mangled[] = ".?AVNmRsCBUFlinch@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::Rockstar::CBUTaskBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c412cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc412cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03ae0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebaa1cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f9498589b51edfa3 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0060c220u, 0x0020c220u, 0x00ebaa1cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc30u, 0x001efc30u, 0x00ebaa1cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00600320u, 0x00200320u, 0x00ebaa1cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006004b0u, 0x002004b0u, 0x00ebaa1cu, 3, "FUN_006004b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005efc70u, 0x001efc70u, 0x00ebaa1cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; zero_pair at synthetic field offset/value 12; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00600560u, 0x00200560u, 0x00ebaa1cu, 5, "FUN_00600560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00600200u, 0x00200200u, 0x00ebaa1cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; bit_u8 at synthetic field offset/value 168; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00600260u, 0x00200260u, 0x00ebaa1cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
