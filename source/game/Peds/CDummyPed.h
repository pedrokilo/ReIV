#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CDummyPed
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CDummyPed;
} }

namespace reiv { namespace memory_map { namespace type_5fa8659cca7fdb0d {
inline constexpr char name[] = "CDummyPed";
inline constexpr char mangled[] = ".?AVCDummyPed@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CDynamicEntity;CEntity;CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3e360u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3e360u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecdb24u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dafa24u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_5fa8659cca7fdb0d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 58u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00bc9210u, 0x007c9210u, 0x00dafa24u, 0, "FUN_00bc9210", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009eaf60u, 0x005eaf60u, 0x00dafa24u, 1, "FUN_009eaf60", "CEntity::Teleport", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CEntity.h:43", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089e930u, 0x0049e930u, 0x00dafa24u, 2, "FUN_0089e930", "CEntity::Teleport", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CEntity.h:48", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089bc10u, 0x0049bc10u, 0x00dafa24u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1960u, 0x005e1960u, 0x00dafa24u, 4, "FUN_009e1960", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e9e10u, 0x005e9e10u, 0x00dafa24u, 5, "FUN_009e9e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1ed0u, 0x005e1ed0u, 0x00dafa24u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0410u, 0x005e0410u, 0x00dafa24u, 7, "FUN_009e0410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0440u, 0x005e0440u, 0x00dafa24u, 8, "FUN_009e0440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00dafa24u, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00dafa24u, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00dafa24u, 11, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089bbf0u, 0x0049bbf0u, 0x00dafa24u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; set or clear flag 0x20 on isolated storage; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bc7270u, 0x007c7270u, 0x00dafa24u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc6dc0u, 0x007c6dc0u, 0x00dafa24u, 14, "FUN_00bc6dc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e69e0u, 0x005e69e0u, 0x00dafa24u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e7cf0u, 0x005e7cf0u, 0x00dafa24u, 16, "FUN_009e7cf0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e22a0u, 0x005e22a0u, 0x00dafa24u, 17, "FUN_009e22a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e18a0u, 0x005e18a0u, 0x00dafa24u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e6a40u, 0x005e6a40u, 0x00dafa24u, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e05c0u, 0x005e05c0u, 0x00dafa24u, 20, "FUN_009e05c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e04d0u, 0x005e04d0u, 0x00dafa24u, 21, "FUN_009e04d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0490u, 0x005e0490u, 0x00dafa24u, 22, "FUN_009e0490", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0610u, 0x005e0610u, 0x00dafa24u, 23, "FUN_009e0610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0660u, 0x005e0660u, 0x00dafa24u, 24, "FUN_009e0660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0690u, 0x005e0690u, 0x00dafa24u, 25, "FUN_009e0690", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e06c0u, 0x005e06c0u, 0x00dafa24u, 26, "FUN_009e06c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0bd0u, 0x005e0bd0u, 0x00dafa24u, 27, "FUN_009e0bd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00dafa24u, 28, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bc8170u, 0x007c8170u, 0x00dafa24u, 29, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447970u, 0x00047970u, 0x00dafa24u, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete XOR AL,AL/RET 12 body; three synthetic arguments discarded; low-byte zero checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00491800u, 0x00091800u, 0x00dafa24u, 31, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 12 body; three explicit synthetic stack arguments discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c28820u, 0x00828820u, 0x00dafa24u, 32, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bc7080u, 0x007c7080u, 0x00dafa24u, 33, "FUN_00bc7080", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1b70u, 0x005e1b70u, 0x00dafa24u, 34, "FUN_009e1b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7230u, 0x007c7230u, 0x00dafa24u, 35, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00dafa24u, 36, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00dafa24u, 37, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bc64c0u, 0x007c64c0u, 0x00dafa24u, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7450u, 0x007c7450u, 0x00dafa24u, 39, "FUN_00bc7450", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008e05a0u, 0x004e05a0u, 0x00dafa24u, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; read field +0x38 with flag 0x04000000 on/off; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00dafa24u, 41, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009eab70u, 0x005eab70u, 0x00dafa24u, 42, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e8710u, 0x005e8710u, 0x00dafa24u, 43, "FUN_009e8710", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e7110u, 0x005e7110u, 0x00dafa24u, 44, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009eac60u, 0x005eac60u, 0x00dafa24u, 45, "FUN_009eac60", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e7140u, 0x005e7140u, 0x00dafa24u, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc77a0u, 0x007c77a0u, 0x00dafa24u, 47, "FUN_00bc77a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009d6a60u, 0x005d6a60u, 0x00dafa24u, 48, "FUN_009d6a60", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00dafa24u, 49, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00dafa24u, 50, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bc5f20u, 0x007c5f20u, 0x00dafa24u, 51, "FUN_00bc5f20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7770u, 0x007c7770u, 0x00dafa24u, 52, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7770u, 0x007c7770u, 0x00dafa24u, 53, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009dfe70u, 0x005dfe70u, 0x00dafa24u, 54, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc5cb0u, 0x007c5cb0u, 0x00dafa24u, 55, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7780u, 0x007c7780u, 0x00dafa24u, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00bc7790u, 0x007c7790u, 0x00dafa24u, 57, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
