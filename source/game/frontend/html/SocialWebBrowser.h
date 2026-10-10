#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: SocialWebBrowser
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class SocialWebBrowser;
} }

namespace reiv { namespace memory_map { namespace type_c7f86f3d4623d967 {
inline constexpr char name[] = "SocialWebBrowser";
inline constexpr char mangled[] = ".?AVSocialWebBrowser@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x0108ee34u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c8ee34u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed299cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9e9ccu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_c7f86f3d4623d967 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0042e620u, 0x0002e620u, 0x00e9e9ccu, 0, "FUN_0042e620", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
