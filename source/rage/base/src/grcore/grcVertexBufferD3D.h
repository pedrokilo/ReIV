#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::grcVertexBufferD3D
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class grcVertexBufferD3D;
} }

namespace reiv { namespace memory_map { namespace type_c7aadac834213313 {
inline constexpr char name[] = "rage::grcVertexBufferD3D";
inline constexpr char mangled[] = ".?AVgrcVertexBufferD3D@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::grcVertexBuffer;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c4fc0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc4fc0u;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00f048a0u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb4f0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c7aadac834213313 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 8u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0064f670u, 0x0024f670u, 0x00ebb4f0u, 0, "FUN_0064f670", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f9d0u, 0x0024f9d0u, 0x00ebb4f0u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064fac0u, 0x0024fac0u, 0x00ebb4f0u, 2, "FUN_0064fac0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064fb70u, 0x0024fb70u, 0x00ebb4f0u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064fc00u, 0x0024fc00u, 0x00ebb4f0u, 4, "FUN_0064fc00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064fd30u, 0x0024fd30u, 0x00ebb4f0u, 5, "FUN_0064fd30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064fda0u, 0x0024fda0u, 0x00ebb4f0u, 6, "FUN_0064fda0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f830u, 0x0024f830u, 0x00ebb4f0u, 7, "FUN_0064f830", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
