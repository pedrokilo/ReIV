#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crCreatureComponentBlendShapes
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crCreatureComponentBlendShapes;
} }

namespace reiv { namespace memory_map { namespace type_b54ba1df180287b0 {
inline constexpr char name[] = "rage::crCreatureComponentBlendShapes";
inline constexpr char mangled[] = ".?AVcrCreatureComponentBlendShapes@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crCreatureComponent";
inline constexpr std::uint32_t type_descriptor_va = 0x010c32e0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc32e0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f01e58u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb951cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_b54ba1df180287b0 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 12u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0059abc0u, 0x0019abc0u, 0x00eb951cu, 0, "FUN_0059abc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b9c0u, 0x0019b9c0u, 0x00eb951cu, 1, "FUN_0059b9c0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageWriteValidation/evidence/runtime-summary.json; 64 calls; set_u32 at synthetic field offset/value 8; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0059b030u, 0x0019b030u, 0x00eb951cu, 2, "FUN_0059b030", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b080u, 0x0019b080u, 0x00eb951cu, 3, "FUN_0059b080", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b3a0u, 0x0019b3a0u, 0x00eb951cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b3f0u, 0x0019b3f0u, 0x00eb951cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b440u, 0x0019b440u, 0x00eb951cu, 6, "FUN_0059b440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b4d0u, 0x0019b4d0u, 0x00eb951cu, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059b520u, 0x0019b520u, 0x00eb951cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059ba10u, 0x0019ba10u, 0x00eb951cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0059aec0u, 0x0019aec0u, 0x00eb951cu, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0059adf0u, 0x0019adf0u, 0x00eb951cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
