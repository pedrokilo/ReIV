#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPlayStatIntInt
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CPlayStatIntInt;
} }

namespace reiv { namespace memory_map { namespace type_0bf7acf3ab6aeb3a {
inline constexpr char name[] = "CPlayStatIntInt";
inline constexpr char mangled[] = ".?AVCPlayStatIntInt@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPlayStatInt;CPlayStatBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f1ccfcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b1ccfcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec0af8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d5b234u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_0bf7acf3ab6aeb3a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0081e790u, 0x0041e790u, 0x00d5b234u, 0, "FUN_0081e790", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0081d140u, 0x0041d140u, 0x00d5b234u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00bcb2b0u, 0x007cb2b0u, 0x00d5b234u, 2, "FUN_00bcb2b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00820210u, 0x00420210u, 0x00d5b234u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00820230u, 0x00420230u, 0x00d5b234u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
