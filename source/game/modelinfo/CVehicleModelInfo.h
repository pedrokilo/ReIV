#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CVehicleModelInfo
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CVehicleModelInfo;
} }

namespace reiv { namespace memory_map { namespace type_408e8102912c0cdf {
inline constexpr char name[] = "CVehicleModelInfo";
inline constexpr char mangled[] = ".?AVCVehicleModelInfo@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CBaseModelInfo;CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f2a634u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b2a634u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ec3bc8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d7d384u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_408e8102912c0cdf {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 19u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009888d0u, 0x005888d0u, 0x00d7d384u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be6480u, 0x007e6480u, 0x00d7d384u, 1, "FUN_00be6480", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009745b0u, 0x005745b0u, 0x00d7d384u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009890b0u, 0x005890b0u, 0x00d7d384u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bea930u, 0x007ea930u, 0x00d7d384u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d7d384u, 5, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00beac40u, 0x007eac40u, 0x00d7d384u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d7d384u, 7, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bea8d0u, 0x007ea8d0u, 0x00d7d384u, 8, "FUN_00bea8d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00beac60u, 0x007eac60u, 0x00d7d384u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0098ea00u, 0x0058ea00u, 0x00d7d384u, 10, "FUN_0098ea00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bea900u, 0x007ea900u, 0x00d7d384u, 11, "FUN_00bea900", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7d384u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00d7d384u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004c4c00u, 0x000c4c00u, 0x00d7d384u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00be7d70u, 0x007e7d70u, 0x00000000u, -1, "CVehicleModelInfo::SetHandlingParams", "CVehicleModelInfo::SetHandlingParams", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:142; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
    {0x00be6a60u, 0x007e6a60u, 0x00000000u, -1, "CVehicleModelInfo::GetNumberOfSeats", "CVehicleModelInfo::GetNumberOfSeats", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:147; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
    {0x00be6930u, 0x007e6930u, 0x00000000u, -1, "CVehicleModelInfo::ChooseVehicleColour", "CVehicleModelInfo::ChooseVehicleColour", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:152; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
    {0x00beac80u, 0x007eac80u, 0x00000000u, -1, "CVehicleModelInfo::SetSecondaryAnimGroup", "CVehicleModelInfo::SetSecondaryAnimGroup", "contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:157; sdk_reference_not_validated", AddressOrigin::SdkFunctionReference, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
