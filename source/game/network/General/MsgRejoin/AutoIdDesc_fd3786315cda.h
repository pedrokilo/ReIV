#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: MsgRejoin::AutoIdDesc__
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_99abc3ffc040b004 {
inline constexpr char name[] = "MsgRejoin::AutoIdDesc__";
inline constexpr char mangled[] = ".?AUAutoIdDesc__@MsgRejoin@@";
inline constexpr char kind[] = "struct";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::AutoIdDescriptor_T<rage::netMessage>;rage::AutoIdDescriptor";
inline constexpr std::uint32_t type_descriptor_va = 0x01090024u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00c90024u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ed4b4cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00e9f7e0u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_99abc3ffc040b004 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x0045e9d0u, 0x0005e9d0u, 0x00e9f7e0u, 0, "FUN_0045e9d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
