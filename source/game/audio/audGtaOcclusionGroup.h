#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: audGtaOcclusionGroup
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class audGtaOcclusionGroup;
} }

namespace reiv { namespace memory_map { namespace type_0d24413dfdda7905 {
inline constexpr char name[] = "audGtaOcclusionGroup";
inline constexpr char mangled[] = ".?AVaudGtaOcclusionGroup@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::audOcclusionGroupInterface";
inline constexpr std::uint32_t type_descriptor_va = 0x00f38810u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b38810u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecaa64u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d9459cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0d24413dfdda7905 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 4u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00ac8fe0u, 0x006c8fe0u, 0x00d9459cu, 0, "FUN_00ac8fe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00aaaf20u, 0x006aaf20u, 0x00d9459cu, 1, "FUN_00aaaf20", "CCustomShaderEffectBase::Update", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CCustomShaderEffectBase.h:6; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00ac7ba0u, 0x006c7ba0u, 0x00d9459cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AudioValidation/evidence/runtime-summary.json; 64 calls; set_u32 at synthetic offset/value 164; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x004d8bc0u, 0x000d8bc0u, 0x00d9459cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AudioValidation/evidence/runtime-summary.json; 64 calls; address_offset at synthetic offset/value 4; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
