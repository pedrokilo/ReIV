#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phBoundGeometry
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phBoundGeometry;
} }

namespace reiv { namespace memory_map { namespace type_2fe24b115406d1eb {
inline constexpr char name[] = "rage::phBoundGeometry";
inline constexpr char mangled[] = ".?AVphBoundGeometry@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phBoundPolyhedron;rage::phBound;rage::phBoundBase;CollisionShape";
inline constexpr std::uint32_t type_descriptor_va = 0x010c56d0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc56d0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f054f8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebc09cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_2fe24b115406d1eb {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 60u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006b8cd0u, 0x002b8cd0u, 0x00ebc09cu, 0, "FUN_006b8cd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686250u, 0x00286250u, 0x00ebc09cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00728a70u, 0x00328a70u, 0x00ebc09cu, 2, "FUN_00728a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00728bf0u, 0x00328bf0u, 0x00ebc09cu, 3, "FUN_00728bf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686780u, 0x00286780u, 0x00ebc09cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00ebc09cu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686240u, 0x00286240u, 0x00ebc09cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebc09cu, 7, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686790u, 0x00286790u, 0x00ebc09cu, 8, "FUN_00686790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006867e0u, 0x002867e0u, 0x00ebc09cu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006867f0u, 0x002867f0u, 0x00ebc09cu, 10, "FUN_006867f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00684ab0u, 0x00284ab0u, 0x00ebc09cu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006848f0u, 0x002848f0u, 0x00ebc09cu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageWriteValidation/evidence/runtime-summary.json; 64 calls; set_u8 at synthetic field offset/value 7; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00684900u, 0x00284900u, 0x00ebc09cu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u8 at synthetic field offset/value 7; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006c2280u, 0x002c2280u, 0x00ebc09cu, 14, "FUN_006c2280", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453ad0u, 0x00053ad0u, 0x00ebc09cu, 15, "FUN_00453ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00ebc09cu, 16, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006ba390u, 0x002ba390u, 0x00ebc09cu, 17, "FUN_006ba390", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006ba400u, 0x002ba400u, 0x00ebc09cu, 18, "FUN_006ba400", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d1810u, 0x002d1810u, 0x00ebc09cu, 19, "FUN_006d1810", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d1920u, 0x002d1920u, 0x00ebc09cu, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8c50u, 0x002b8c50u, 0x00ebc09cu, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8f30u, 0x002b8f30u, 0x00ebc09cu, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8c60u, 0x002b8c60u, 0x00ebc09cu, 23, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b9fa0u, 0x002b9fa0u, 0x00ebc09cu, 24, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b9ef0u, 0x002b9ef0u, 0x00ebc09cu, 25, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b9f60u, 0x002b9f60u, 0x00ebc09cu, 26, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00784520u, 0x00384520u, 0x00ebc09cu, 27, "FUN_00784520", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2280u, 0x002d2280u, 0x00ebc09cu, 28, "FUN_006d2280", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2560u, 0x002d2560u, 0x00ebc09cu, 29, "FUN_006d2560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2630u, 0x002d2630u, 0x00ebc09cu, 30, "FUN_006d2630", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2820u, 0x002d2820u, 0x00ebc09cu, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2840u, 0x002d2840u, 0x00ebc09cu, 32, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00685100u, 0x00285100u, 0x00ebc09cu, 33, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447970u, 0x00047970u, 0x00ebc09cu, 34, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00685110u, 0x00285110u, 0x00ebc09cu, 35, "FUN_00685110", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00ebc09cu, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00685580u, 0x00285580u, 0x00ebc09cu, 37, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006c2e60u, 0x002c2e60u, 0x00ebc09cu, 38, "FUN_006c2e60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006c3c80u, 0x002c3c80u, 0x00ebc09cu, 39, "FUN_006c3c80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00724b20u, 0x00324b20u, 0x00ebc09cu, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006c6ef0u, 0x002c6ef0u, 0x00ebc09cu, 41, "FUN_006c6ef0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006619b0u, 0x002619b0u, 0x00ebc09cu, 42, "FUN_006619b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006c2d40u, 0x002c2d40u, 0x00ebc09cu, 43, "FUN_006c2d40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00ebc09cu, 44, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebc09cu, 45, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006bd030u, 0x002bd030u, 0x00ebc09cu, 46, "FUN_006bd030", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00685740u, 0x00285740u, 0x00ebc09cu, 47, "FUN_00685740", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686260u, 0x00286260u, 0x00ebc09cu, 48, "FUN_00686260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059ba00u, 0x0019ba00u, 0x00ebc09cu, 49, "FUN_0059ba00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006b92a0u, 0x002b92a0u, 0x00ebc09cu, 50, "FUN_006b92a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006bcaf0u, 0x002bcaf0u, 0x00ebc09cu, 51, "FUN_006bcaf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d1ab0u, 0x002d1ab0u, 0x00ebc09cu, 52, "FUN_006d1ab0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8f90u, 0x002b8f90u, 0x00ebc09cu, 53, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b9f40u, 0x002b9f40u, 0x00ebc09cu, 54, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d2de0u, 0x002d2de0u, 0x00ebc09cu, 55, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8f20u, 0x002b8f20u, 0x00ebc09cu, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006b8f60u, 0x002b8f60u, 0x00ebc09cu, 57, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006ba010u, 0x002ba010u, 0x00ebc09cu, 58, "FUN_006ba010", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00ebc09cu, 59, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
