#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phRopeConstraint
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phRopeConstraint;
} }

namespace reiv { namespace memory_map { namespace type_8ff6e584c8e5471b {
inline constexpr char name[] = "rage::phRopeConstraint";
inline constexpr char mangled[] = ".?AVphRopeConstraint@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phConstraint";
inline constexpr std::uint32_t type_descriptor_va = 0x010c59acu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc59acu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f05ba4u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebcaa4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_8ff6e584c8e5471b {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0070df90u, 0x0030df90u, 0x00ebcaa4u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070de10u, 0x0030de10u, 0x00ebcaa4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0070de40u, 0x0030de40u, 0x00ebcaa4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/rage/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; complete forward CFG reviewed; defined EAX mask only; expected_nodes_mask describes model paths, not instrumented native coverage", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
