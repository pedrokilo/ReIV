#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CAnimAssociations
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CAnimAssociations;
} }

namespace reiv { namespace memory_map { namespace type_8782e288fbc918bf {
inline constexpr char name[] = "CAnimAssociations";
inline constexpr char mangled[] = ".?AVCAnimAssociations@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f38cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f38cu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec3360u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d77b24u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_8782e288fbc918bf {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 3u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0092f320u, 0x0052f320u, 0x00d77b24u, 0, "FUN_0092f320", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00931120u, 0x00531120u, 0x00d77b24u, 1, "FUN_00931120", "CAnimManager::Initialise", "docs/MemoryMap/virtual_slots.csv; sdk_exact_function_address contrib/IV SDK/IV-SDK-main/include/CAnimManager.h:26", AddressOrigin::VirtualSlot, false, false, false},
    {0x0092fb30u, 0x0052fb30u, 0x00d77b24u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
