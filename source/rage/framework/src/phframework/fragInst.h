#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::fragInst
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class fragInst;
} }

namespace reiv { namespace memory_map { namespace type_565e22e8f1750bde {
inline constexpr char name[] = "rage::fragInst";
inline constexpr char mangled[] = ".?AVfragInst@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phInstBreakable;rage::phInst;rage::datBase;rage::pgStreamableRef<rage::fragType>;rage::pgStreamableRefBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0d58u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0d58u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efdefcu, 0x00efdf10u};
inline constexpr std::uint32_t locators_count = 2u;
inline constexpr std::uint32_t vtables[] = {0x00eb728cu, 0x00eb7394u};
inline constexpr std::uint32_t vtables_count = 2u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_565e22e8f1750bde {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 68u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00531fb0u, 0x00131fb0u, 0x00eb728cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0044c570u, 0x0004c570u, 0x00eb728cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00517920u, 0x00117920u, 0x00eb728cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005879b0u, 0x001879b0u, 0x00eb728cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic field offset/value 16; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00eb728cu, 4, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686be0u, 0x00286be0u, 0x00eb728cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686be0u, 0x00286be0u, 0x00eb728cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686c00u, 0x00286c00u, 0x00eb728cu, 7, "FUN_00686c00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00eb728cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051a090u, 0x0011a090u, 0x00eb728cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a0e0u, 0x0011a0e0u, 0x00eb728cu, 10, "FUN_0051a0e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686b20u, 0x00286b20u, 0x00eb728cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686af0u, 0x00286af0u, 0x00eb728cu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051dad0u, 0x0011dad0u, 0x00eb728cu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00eb728cu, 14, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00eb728cu, 15, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686b70u, 0x00286b70u, 0x00eb728cu, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00518a70u, 0x00118a70u, 0x00eb728cu, 17, "FUN_00518a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00518c10u, 0x00118c10u, 0x00eb728cu, 18, "FUN_00518c10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 19, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00510b90u, 0x00110b90u, 0x00eb728cu, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00784520u, 0x00384520u, 0x00eb728cu, 21, "FUN_00784520", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00707920u, 0x00307920u, 0x00eb728cu, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00707920u, 0x00307920u, 0x00eb728cu, 23, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00518a50u, 0x00118a50u, 0x00eb728cu, 24, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 25, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00518c80u, 0x00118c80u, 0x00eb728cu, 26, "FUN_00518c80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059ba00u, 0x0019ba00u, 0x00eb728cu, 27, "FUN_0059ba00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051a700u, 0x0011a700u, 0x00eb728cu, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051c750u, 0x0011c750u, 0x00eb728cu, 29, "FUN_0051c750", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00784520u, 0x00384520u, 0x00eb728cu, 30, "FUN_00784520", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686cd0u, 0x00286cd0u, 0x00eb728cu, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00567170u, 0x00167170u, 0x00eb728cu, 32, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00567170u, 0x00167170u, 0x00eb728cu, 33, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00518270u, 0x00118270u, 0x00eb728cu, 34, "FUN_00518270", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051ccc0u, 0x0011ccc0u, 0x00eb728cu, 35, "FUN_0051ccc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051c850u, 0x0011c850u, 0x00eb728cu, 36, "FUN_0051c850", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070b950u, 0x0030b950u, 0x00eb728cu, 37, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070b990u, 0x0030b990u, 0x00eb728cu, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005765b0u, 0x001765b0u, 0x00eb728cu, 39, "FUN_005765b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00517550u, 0x00117550u, 0x00eb728cu, 40, "FUN_00517550", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a180u, 0x0011a180u, 0x00eb728cu, 41, "FUN_0051a180", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a390u, 0x0011a390u, 0x00eb728cu, 42, "FUN_0051a390", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a400u, 0x0011a400u, 0x00eb728cu, 43, "FUN_0051a400", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051dd40u, 0x0011dd40u, 0x00eb728cu, 44, "FUN_0051dd40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00510b90u, 0x00110b90u, 0x00eb728cu, 45, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051e050u, 0x0011e050u, 0x00eb728cu, 46, "FUN_0051e050", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051bd00u, 0x0011bd00u, 0x00eb728cu, 47, "FUN_0051bd00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a960u, 0x0011a960u, 0x00eb728cu, 48, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051a9f0u, 0x0011a9f0u, 0x00eb728cu, 49, "FUN_0051a9f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 50, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051db20u, 0x0011db20u, 0x00eb728cu, 51, "FUN_0051db20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051dcb0u, 0x0011dcb0u, 0x00eb728cu, 52, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 53, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 54, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0051df40u, 0x0011df40u, 0x00eb728cu, 55, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051dfd0u, 0x0011dfd0u, 0x00eb728cu, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051e010u, 0x0011e010u, 0x00eb728cu, 57, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00eb728cu, 58, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0059ba00u, 0x0019ba00u, 0x00eb728cu, 59, "FUN_0059ba00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00519060u, 0x00119060u, 0x00eb728cu, 60, "FUN_00519060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051b520u, 0x0011b520u, 0x00eb728cu, 61, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051dab0u, 0x0011dab0u, 0x00eb728cu, 62, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0055a850u, 0x0015a850u, 0x00eb728cu, 63, "FUN_0055a850", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00eb728cu, 64, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005171f0u, 0x001171f0u, 0x00eb7394u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00517200u, 0x00117200u, 0x00eb7394u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0051ebd0u, 0x0011ebd0u, 0x00eb7394u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
