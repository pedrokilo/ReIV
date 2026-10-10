#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CNetCloneTaskComplexNewExitVehicle
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CNetCloneTaskComplexNewExitVehicle;
} }

namespace reiv { namespace memory_map { namespace type_e0ff9d9bbfe53516 {
inline constexpr char name[] = "CNetCloneTaskComplexNewExitVehicle";
inline constexpr char mangled[] = ".?AVCNetCloneTaskComplexNewExitVehicle@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CNetCloneTaskVehicleBase;CNetCloneTask";
inline constexpr std::uint32_t type_descriptor_va = 0x010bfa98u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cbfa98u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efbbf0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb5d1cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_e0ff9d9bbfe53516 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 11u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x004f0c10u, 0x000f0c10u, 0x00eb5d1cu, 0, "FUN_004f0c10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004f2270u, 0x000f2270u, 0x00eb5d1cu, 1, "FUN_004f2270", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00eb5d1cu, 2, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00eb5d1cu, 3, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00a2c9d0u, 0x0062c9d0u, 0x00eb5d1cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00919b60u, 0x00519b60u, 0x00eb5d1cu, 5, "FUN_00919b60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008b8740u, 0x004b8740u, 0x00eb5d1cu, 6, "FUN_008b8740", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008b8740u, 0x004b8740u, 0x00eb5d1cu, 7, "FUN_008b8740", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004f2220u, 0x000f2220u, 0x00eb5d1cu, 8, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004df780u, 0x000df780u, 0x00eb5d1cu, 9, "FUN_004df780", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004f28b0u, 0x000f28b0u, 0x00eb5d1cu, 10, "FUN_004f28b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
