#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CMediaStreamReaderCallback
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class CMediaStreamReaderCallback;
} }

namespace reiv { namespace memory_map { namespace type_138392cc7ba8f989 {
inline constexpr char name[] = "CMediaStreamReaderCallback";
inline constexpr char mangled[] = ".?AVCMediaStreamReaderCallback@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "IWMReaderCallback;IWMStatusCallback;IUnknown";
inline constexpr std::uint32_t type_descriptor_va = 0x00f3c4acu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b3c4acu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ecd25cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00da8d3cu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_138392cc7ba8f989 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 5u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00b4d290u, 0x0074d290u, 0x00da8d3cu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00b4d2e0u, 0x0074d2e0u, 0x00da8d3cu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00b4dc30u, 0x0074dc30u, 0x00da8d3cu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00b4dc70u, 0x0074dc70u, 0x00da8d3cu, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00b4e310u, 0x0074e310u, 0x00da8d3cu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
