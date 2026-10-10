#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CCamScriptInstruction_SequenceWait
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CCamScriptInstruction_SequenceWait;
} }

namespace reiv { namespace memory_map { namespace type_d653c1e639d0b59d {
inline constexpr char name[] = "CCamScriptInstruction_SequenceWait";
inline constexpr char mangled[] = ".?AVCCamScriptInstruction_SequenceWait@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CCamScriptInstruction";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3a6bcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3a6bcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecbb24u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d99af8u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d653c1e639d0b59d {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00afc370u, 0x006fc370u, 0x00d99af8u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00afcf30u, 0x006fcf30u, 0x00d99af8u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00afcf20u, 0x006fcf20u, 0x00d99af8u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
