#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: btGjkEpaPenetrationDepthSolver
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class btGjkEpaPenetrationDepthSolver;
} }

namespace reiv { namespace memory_map { namespace type_dabef235864a10ed {
inline constexpr char name[] = "btGjkEpaPenetrationDepthSolver";
inline constexpr char mangled[] = ".?AVbtGjkEpaPenetrationDepthSolver@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ConvexPenetrationDepthSolver";
inline constexpr std::uint32_t type_descriptor_va = 0x010c5c74u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc5c74u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f06180u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebcf94u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_dabef235864a10ed {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 2u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x007340b0u, 0x003340b0u, 0x00ebcf94u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x00756180u, 0x00356180u, 0x00ebcf94u, 1, "FUN_00756180", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
