#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CVehicleFactoryNY
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CVehicleFactoryNY;
} }

namespace reiv { namespace memory_map { namespace type_69d8ca5855de086a {
inline constexpr char name[] = "CVehicleFactoryNY";
inline constexpr char mangled[] = ".?AVCVehicleFactoryNY@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CVehicleFactory";
inline constexpr std::uint32_t type_descriptor_va = 0x0108f430u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8f430u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00ed35d8u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9ed50u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_69d8ca5855de086a {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00443d30u, 0x00043d30u, 0x00e9ed50u, 0, "FUN_00443d30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00443d60u, 0x00043d60u, 0x00e9ed50u, 1, "unknown_entry", "CVehicleFactoryNY::CreateVehicle", "docs/MemoryMap/virtual_slots.csv; sdk_exact_owner_slot contrib/IV SDK/IV-SDK-main/include/CVehicleFactoryNY.h:13", AddressOrigin::VirtualSlot, false, false, false},
    {0x00973aa0u, 0x00573aa0u, 0x00e9ed50u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00443f50u, 0x00043f50u, 0x00e9ed50u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00443f60u, 0x00043f60u, 0x00e9ed50u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00443f70u, 0x00043f70u, 0x00e9ed50u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
