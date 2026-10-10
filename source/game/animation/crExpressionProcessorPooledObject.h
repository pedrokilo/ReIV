#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: crExpressionProcessorPooledObject
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class crExpressionProcessorPooledObject;
} }

namespace reiv { namespace memory_map { namespace type_d5b98fca8350df08 {
inline constexpr char name[] = "crExpressionProcessorPooledObject";
inline constexpr char mangled[] = ".?AVcrExpressionProcessorPooledObject@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crExpressionProcessor;rage::atReferenceCounter;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f34780u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b34780u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec5c50u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d83f84u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d5b98fca8350df08 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009ee680u, 0x005ee680u, 0x00d83f84u, 0, "FUN_009ee680", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0050b6e0u, 0x0010b6e0u, 0x00d83f84u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; increment field +4 on isolated storage; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0050b6f0u, 0x0010b6f0u, 0x00d83f84u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/AnimationValidation/evidence/runtime-summary.json; 64 calls; decrement field +4: nonzero branch only, no release; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
