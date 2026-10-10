#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: bad_typeid
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace game {
class bad_typeid;
} }

namespace reiv { namespace memory_map { namespace type_f6daa49402eff026 {
inline constexpr char name[] = "bad_typeid";
inline constexpr char mangled[] = ".?AVbad_typeid@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_type";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x00f43ec0u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b43ec0u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0u};
inline constexpr std::uint32_t locators_count = 0u;
inline constexpr std::uint32_t vtables[] = {0u};
inline constexpr std::uint32_t vtables_count = 0u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_f6daa49402eff026 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 1u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00d1d8cbu, 0x0091d8cbu, 0x00000000u, -1, "msvc_eh_copy_constructor_callback", "", "reversing/UnknownTypesAnalysis/evidence/eh-summary.json; metadata 0x00f08944; CatchableTypeArray 0x00f0897c", AddressOrigin::ExceptionCopyConstructor, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
