#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CBaseModelInfo
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CBaseModelInfo;
} }

namespace reiv { namespace memory_map { namespace type_eccf26e5c3d76a33 {
inline constexpr char name[] = "CBaseModelInfo";
inline constexpr char mangled[] = ".?AVCBaseModelInfo@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f28050u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b28050u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ec379cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d7cd04u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_eccf26e5c3d76a33 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 17u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00988810u, 0x00588810u, 0x00d7cd04u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098e610u, 0x0058e610u, 0x00d7cd04u, 1, "FUN_0098e610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098e360u, 0x0058e360u, 0x00d7cd04u, 2, "FUN_0098e360", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d7cd04u, 3, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_exact_owner_slot contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0098eed0u, 0x0058eed0u, 0x00d7cd04u, 4, "FUN_0098eed0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d7cd04u, 5, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0098ec90u, 0x0058ec90u, 0x00d7cd04u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d7cd04u, 7, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0098e6b0u, 0x0058e6b0u, 0x00d7cd04u, 8, "FUN_0098e6b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098f170u, 0x0058f170u, 0x00d7cd04u, 9, "FUN_0098f170", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098ea00u, 0x0058ea00u, 0x00d7cd04u, 10, "FUN_0098ea00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098e480u, 0x0058e480u, 0x00d7cd04u, 11, "FUN_0098e480", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7cd04u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7cd04u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004c4c00u, 0x000c4c00u, 0x00d7cd04u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098f3f0u, 0x0058f3f0u, 0x00000000u, -1, "CBaseModelInfo::SetAnimGroup", "CBaseModelInfo::SetAnimGroup", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:44; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
    {0x0098ee30u, 0x0058ee30u, 0x00000000u, -1, "CBaseModelInfo::SetTexDictionary", "CBaseModelInfo::SetTexDictionary", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:49; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
