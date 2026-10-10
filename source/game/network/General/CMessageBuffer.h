#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CMessageBuffer
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CMessageBuffer;
} }

namespace reiv { namespace memory_map { namespace type_94df188274806fde {
inline constexpr char name[] = "CMessageBuffer";
inline constexpr char mangled[] = ".?AVCMessageBuffer@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::datBitBuffer";
inline constexpr std::uint32_t type_descriptor_va = 0x01090230u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c90230u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed4e90u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9f8d4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_94df188274806fde {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00496800u, 0x00096800u, 0x00e9f8d4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004d7030u, 0x000d7030u, 0x00e9f8d4u, 1, "FUN_004d7030", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00c28820u, 0x00828820u, 0x00e9f8d4u, 2, "FUN_00c28820", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
