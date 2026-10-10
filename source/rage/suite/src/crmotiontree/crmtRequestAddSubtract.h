#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::crmtRequestAddSubtract
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class crmtRequestAddSubtract;
} }

namespace reiv { namespace memory_map { namespace type_de15189a7237e42a {
inline constexpr char name[] = "rage::crmtRequestAddSubtract";
inline constexpr char mangled[] = ".?AVcrmtRequestAddSubtract@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::crmtRequestSource<2>;rage::crmtRequest";
inline constexpr std::uint32_t type_descriptor_va = 0x010c08acu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc08acu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00efd6bcu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eb6eb4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_de15189a7237e42a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005118e0u, 0x001118e0u, 0x00eb6eb4u, 0, "FUN_005118e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005119c0u, 0x001119c0u, 0x00eb6eb4u, 1, "FUN_005119c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00511a00u, 0x00111a00u, 0x00eb6eb4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
