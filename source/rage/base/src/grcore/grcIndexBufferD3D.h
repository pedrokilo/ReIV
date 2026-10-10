#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::grcIndexBufferD3D
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class grcIndexBufferD3D;
} }

namespace reiv { namespace memory_map { namespace type_477ec5a6d8c22d5f {
inline constexpr char name[] = "rage::grcIndexBufferD3D";
inline constexpr char mangled[] = ".?AVgrcIndexBufferD3D@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::grcIndexBuffer;rage::datBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c4f98u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc4f98u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f04850u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebb4d4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_477ec5a6d8c22d5f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 6u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0064f030u, 0x0024f030u, 0x00ebb4d4u, 0, "FUN_0064f030", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f380u, 0x0024f380u, 0x00ebb4d4u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f390u, 0x0024f390u, 0x00ebb4d4u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f3a0u, 0x0024f3a0u, 0x00ebb4d4u, 3, "FUN_0064f3a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f410u, 0x0024f410u, 0x00ebb4d4u, 4, "FUN_0064f410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0064f480u, 0x0024f480u, 0x00ebb4d4u, 5, "FUN_0064f480", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
