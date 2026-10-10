#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phBoundTaperedCapsule
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phBoundTaperedCapsule;
} }

namespace reiv { namespace memory_map { namespace type_84b542a86ff44bcc {
inline constexpr char name[] = "rage::phBoundTaperedCapsule";
inline constexpr char mangled[] = ".?AVphBoundTaperedCapsule@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phBound;rage::phBoundBase;CollisionShape";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5980u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5980u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05b3cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebc8bcu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_84b542a86ff44bcc {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 52u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00728920u, 0x00328920u, 0x00ebc8bcu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686250u, 0x00286250u, 0x00ebc8bcu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00728a70u, 0x00328a70u, 0x00ebc8bcu, 2, "FUN_00728a70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00728bf0u, 0x00328bf0u, 0x00ebc8bcu, 3, "FUN_00728bf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686780u, 0x00286780u, 0x00ebc8bcu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00ebc8bcu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686240u, 0x00286240u, 0x00ebc8bcu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebc8bcu, 7, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00686790u, 0x00286790u, 0x00ebc8bcu, 8, "FUN_00686790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006867e0u, 0x002867e0u, 0x00ebc8bcu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006867f0u, 0x002867f0u, 0x00ebc8bcu, 10, "FUN_006867f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00684ab0u, 0x00284ab0u, 0x00ebc8bcu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006848f0u, 0x002848f0u, 0x00ebc8bcu, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageWriteValidation/evidence/runtime-summary.json; 64 calls; set_u8 at synthetic field offset/value 7; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00684900u, 0x00284900u, 0x00ebc8bcu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u8 at synthetic field offset/value 7; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00704cc0u, 0x00304cc0u, 0x00ebc8bcu, 14, "FUN_00704cc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00453ad0u, 0x00053ad0u, 0x00ebc8bcu, 15, "FUN_00453ad0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00ebc8bcu, 16, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00704c00u, 0x00304c00u, 0x00ebc8bcu, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00704c70u, 0x00304c70u, 0x00ebc8bcu, 18, "FUN_00704c70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00705070u, 0x00305070u, 0x00ebc8bcu, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007050d0u, 0x003050d0u, 0x00ebc8bcu, 20, "FUN_007050d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0074beb0u, 0x0034beb0u, 0x00ebc8bcu, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00704720u, 0x00304720u, 0x00ebc8bcu, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00704740u, 0x00304740u, 0x00ebc8bcu, 23, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00704750u, 0x00304750u, 0x00ebc8bcu, 24, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00704760u, 0x00304760u, 0x00ebc8bcu, 25, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006d7660u, 0x002d7660u, 0x00ebc8bcu, 26, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006619b0u, 0x002619b0u, 0x00ebc8bcu, 27, "FUN_006619b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00705640u, 0x00305640u, 0x00ebc8bcu, 28, "FUN_00705640", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00705820u, 0x00305820u, 0x00ebc8bcu, 29, "FUN_00705820", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00705290u, 0x00305290u, 0x00ebc8bcu, 30, "FUN_00705290", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00705f50u, 0x00305f50u, 0x00ebc8bcu, 31, "FUN_00705f50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00706b70u, 0x00306b70u, 0x00ebc8bcu, 32, "FUN_00706b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007065b0u, 0x003065b0u, 0x00ebc8bcu, 33, "FUN_007065b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00706230u, 0x00306230u, 0x00ebc8bcu, 34, "FUN_00706230", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00685110u, 0x00285110u, 0x00ebc8bcu, 35, "FUN_00685110", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00ebc8bcu, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00685580u, 0x00285580u, 0x00ebc8bcu, 37, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707930u, 0x00307930u, 0x00ebc8bcu, 38, "FUN_00707930", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00708090u, 0x00308090u, 0x00ebc8bcu, 39, "FUN_00708090", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006619b0u, 0x002619b0u, 0x00ebc8bcu, 40, "FUN_006619b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006619b0u, 0x002619b0u, 0x00ebc8bcu, 41, "FUN_006619b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006619b0u, 0x002619b0u, 0x00ebc8bcu, 42, "FUN_006619b0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_zero_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00705200u, 0x00305200u, 0x00ebc8bcu, 43, "FUN_00705200", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00549100u, 0x00149100u, 0x00ebc8bcu, 44, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebc8bcu, 45, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00685610u, 0x00285610u, 0x00ebc8bcu, 46, "FUN_00685610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00685740u, 0x00285740u, 0x00ebc8bcu, 47, "FUN_00685740", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00686260u, 0x00286260u, 0x00ebc8bcu, 48, "FUN_00686260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0059ba00u, 0x0019ba00u, 0x00ebc8bcu, 49, "FUN_0059ba00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0070b380u, 0x0030b380u, 0x00ebc8bcu, 50, "FUN_0070b380", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00704a90u, 0x00304a90u, 0x00ebc8bcu, 51, "FUN_00704a90", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
