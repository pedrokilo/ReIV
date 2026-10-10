#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ARTFeedbackInterfaceGta
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class ARTFeedbackInterfaceGta;
} }

namespace reiv { namespace memory_map { namespace type_7a2054a7a27d8ba5 {
inline constexpr char name[] = "ARTFeedbackInterfaceGta";
inline constexpr char mangled[] = ".?AVARTFeedbackInterfaceGta@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::ARTFeedbackInterface";
inline constexpr std::uint32_t type_descriptor_va = 0x00f40edcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b40edcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecf660u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00dc24f4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_7a2054a7a27d8ba5 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 7u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00c728c0u, 0x008728c0u, 0x00dc24f4u, 0, "FUN_00c728c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc24f4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c728e0u, 0x008728e0u, 0x00dc24f4u, 2, "FUN_00c728e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c72950u, 0x00872950u, 0x00dc24f4u, 3, "FUN_00c72950", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c729c0u, 0x008729c0u, 0x00dc24f4u, 4, "FUN_00c729c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00c72a30u, 0x00872a30u, 0x00dc24f4u, 5, "FUN_00c72a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x004ee420u, 0x000ee420u, 0x00dc24f4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
