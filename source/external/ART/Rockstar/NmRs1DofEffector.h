#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: ART::Rockstar::NmRs1DofEffector
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// Nested/template type: declaration deferred until its owner/parameters are known.

namespace reiv { namespace memory_map { namespace type_ab1c1feabece6d98 {
inline constexpr char name[] = "ART::Rockstar::NmRs1DofEffector";
inline constexpr char mangled[] = ".?AVNmRs1DofEffector@Rockstar@ART@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "ART::Rockstar::NmRsEffectorBase";
inline constexpr std::uint32_t type_descriptor_va = 0x010c3fa4u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc3fa4u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f03820u};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00eba804u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_ab1c1feabece6d98 {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 28u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x005e3540u, 0x001e3540u, 0x00eba804u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/destructors/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eeaf0u, 0x001eeaf0u, 0x00eba804u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e39e0u, 0x001e39e0u, 0x00eba804u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; zero_u32 at synthetic field offset/value 228; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eebc0u, 0x001eebc0u, 0x00eba804u, 3, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eed20u, 0x001eed20u, 0x00eba804u, 4, "FUN_005eed20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005ee880u, 0x001ee880u, 0x00eba804u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 272; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee890u, 0x001ee890u, 0x00eba804u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 240; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee8a0u, 0x001ee8a0u, 0x00eba804u, 7, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_u32 at synthetic field offset/value 244; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eed50u, 0x001eed50u, 0x00eba804u, 8, "FUN_005eed50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eedb0u, 0x001eedb0u, 0x00eba804u, 9, "FUN_005eedb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eee40u, 0x001eee40u, 0x00eba804u, 10, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eee70u, 0x001eee70u, 0x00eba804u, 11, "FUN_005eee70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005e35a0u, 0x001e35a0u, 0x00eba804u, 12, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTExtraValidation/evidence/runtime-summary.json; 64 calls; bit_u8 at synthetic field offset/value 232; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eef10u, 0x001eef10u, 0x00eba804u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eef70u, 0x001eef70u, 0x00eba804u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eefc0u, 0x001eefc0u, 0x00eba804u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005eefe0u, 0x001eefe0u, 0x00eba804u, 16, "FUN_005eefe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005ef060u, 0x001ef060u, 0x00eba804u, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ef080u, 0x001ef080u, 0x00eba804u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005ee8f0u, 0x001ee8f0u, 0x00eba804u, 19, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee920u, 0x001ee920u, 0x00eba804u, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee8c0u, 0x001ee8c0u, 0x00eba804u, 21, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee950u, 0x001ee950u, 0x00eba804u, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/ART/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee8e0u, 0x001ee8e0u, 0x00eba804u, 23, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_float at synthetic field offset/value 300; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee910u, 0x001ee910u, 0x00eba804u, 24, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_float at synthetic field offset/value 304; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee8b0u, 0x001ee8b0u, 0x00eba804u, 25, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_float at synthetic field offset/value 296; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005ee940u, 0x001ee940u, 0x00eba804u, 26, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ARTFixtureValidation/evidence/runtime-summary.json; 64 calls; get_float at synthetic field offset/value 308; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005eeac0u, 0x001eeac0u, 0x00eba804u, 27, "FUN_005eeac0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
