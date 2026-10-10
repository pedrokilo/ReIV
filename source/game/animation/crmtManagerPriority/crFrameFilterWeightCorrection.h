#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: crmtManagerPriority::crFrameFilterWeightCorrection
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_5fa362b6eb649644 {
inline constexpr char name[] = "crmtManagerPriority::crFrameFilterWeightCorrection";
inline constexpr char mangled[] = ".?AVcrFrameFilterWeightCorrection@crmtManagerPriority@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crFrameFilterN;rage::atReferenceCounter;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f34720u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b34720u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec5bb4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d83f5cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_5fa362b6eb649644 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009eb260u, 0x005eb260u, 0x00d83f5cu, 0, "FUN_009eb260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6e0u, 0x0010b6e0u, 0x00d83f5cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; increment field +4 on isolated storage; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0050b6f0u, 0x0010b6f0u, 0x00d83f5cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; decrement field +4: nonzero branch only, no release; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004c88c0u, 0x000c88c0u, 0x00d83f5cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009eb120u, 0x005eb120u, 0x00d83f5cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d83f5cu, 5, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009eb110u, 0x005eb110u, 0x00d83f5cu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; read field +8 and output size 0x80 on isolated storage; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
