#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CComplexNewUseCoverInfo
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CComplexNewUseCoverInfo;
} }

namespace reiv { namespace memory_map { namespace type_7d9609f28439455a {
inline constexpr char name[] = "CComplexNewUseCoverInfo";
inline constexpr char mangled[] = ".?AVCComplexNewUseCoverInfo@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CTaskInfoWithCloneTask;CTaskInfo";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2ccf8u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2ccf8u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec4d30u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d7fe44u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_7d9609f28439455a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 17u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009a9b60u, 0x005a9b60u, 0x00d7fe44u, 0, "FUN_009a9b60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c8b340u, 0x0088b340u, 0x00d7fe44u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a1e350u, 0x0061e350u, 0x00d7fe44u, 2, "FUN_00a1e350", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a66b0u, 0x005a66b0u, 0x00d7fe44u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a6720u, 0x005a6720u, 0x00d7fe44u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a3890u, 0x005a3890u, 0x00d7fe44u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a38e0u, 0x005a38e0u, 0x00d7fe44u, 6, "FUN_009a38e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a3970u, 0x005a3970u, 0x00d7fe44u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a3a20u, 0x005a3a20u, 0x00d7fe44u, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a7a10u, 0x005a7a10u, 0x00d7fe44u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a7a10u, 0x005a7a10u, 0x00d7fe44u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d7fe44u, 11, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004a10f0u, 0x000a10f0u, 0x00d7fe44u, 12, "FUN_004a10f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009a03e0u, 0x005a03e0u, 0x00d7fe44u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004d7030u, 0x000d7030u, 0x00d7fe44u, 14, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7fe44u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7fe44u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
