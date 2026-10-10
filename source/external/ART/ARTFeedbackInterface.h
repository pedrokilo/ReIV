#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::ARTFeedbackInterface
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace ART {
class ARTFeedbackInterface;
} }

namespace reiv { namespace memory_map { namespace type_b2d34e116419543f {
inline constexpr char name[] = "ART::ARTFeedbackInterface";
inline constexpr char mangled[] = ".?AVARTFeedbackInterface@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f40e80u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b40e80u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecf554u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dc2334u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b2d34e116419543f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c70e40u, 0x00870e40u, 0x00dc2334u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc2334u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; return_minus_one at synthetic field offset/value 0; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
