#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phConstrainedCollider
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phConstrainedCollider;
} }

namespace reiv { namespace memory_map { namespace type_7728996aa829401f {
inline constexpr char name[] = "rage::phConstrainedCollider";
inline constexpr char mangled[] = ".?AVphConstrainedCollider@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "rage::phCollider";
inline constexpr std::uint32_t type_descriptor_va = 0x010c567cu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc567cu;
inline constexpr bool in_sdk = true;
inline constexpr std::uint32_t locators[] = {0x00f054acu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebbfccu};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_7728996aa829401f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 50u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x006ac2e0u, 0x002ac2e0u, 0x00ebbfccu, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c740u, 0x0029c740u, 0x00ebbfccu, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c080u, 0x0029c080u, 0x00ebbfccu, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069cba0u, 0x0029cba0u, 0x00ebbfccu, 3, "FUN_0069cba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069cdf0u, 0x0029cdf0u, 0x00ebbfccu, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ce60u, 0x0029ce60u, 0x00ebbfccu, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afb00u, 0x002afb00u, 0x00ebbfccu, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebbfccu, 7, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006afb20u, 0x002afb20u, 0x00ebbfccu, 8, "FUN_006afb20", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afb50u, 0x002afb50u, 0x00ebbfccu, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ec40u, 0x0029ec40u, 0x00ebbfccu, 10, "FUN_0069ec40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afbd0u, 0x002afbd0u, 0x00ebbfccu, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d860u, 0x0029d860u, 0x00ebbfccu, 12, "FUN_0069d860", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069dd00u, 0x0029dd00u, 0x00ebbfccu, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069de50u, 0x0029de50u, 0x00ebbfccu, 14, "FUN_0069de50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afba0u, 0x002afba0u, 0x00ebbfccu, 15, "FUN_006afba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ed90u, 0x0029ed90u, 0x00ebbfccu, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069eda0u, 0x0029eda0u, 0x00ebbfccu, 17, "FUN_0069eda0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006af650u, 0x002af650u, 0x00ebbfccu, 18, "FUN_006af650", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006af010u, 0x002af010u, 0x00ebbfccu, 19, "FUN_006af010", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006af0e0u, 0x002af0e0u, 0x00ebbfccu, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ef40u, 0x0029ef40u, 0x00ebbfccu, 21, "FUN_0069ef40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f6a0u, 0x0029f6a0u, 0x00ebbfccu, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006ae320u, 0x002ae320u, 0x00ebbfccu, 23, "FUN_006ae320", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006ae5c0u, 0x002ae5c0u, 0x00ebbfccu, 24, "FUN_006ae5c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006ae7b0u, 0x002ae7b0u, 0x00ebbfccu, 25, "FUN_006ae7b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afe00u, 0x002afe00u, 0x00ebbfccu, 26, "FUN_006afe00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ffe0u, 0x0029ffe0u, 0x00ebbfccu, 27, "FUN_0069ffe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0760u, 0x002a0760u, 0x00ebbfccu, 28, "FUN_006a0760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0890u, 0x002a0890u, 0x00ebbfccu, 29, "FUN_006a0890", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0a30u, 0x002a0a30u, 0x00ebbfccu, 30, "FUN_006a0a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a09c0u, 0x002a09c0u, 0x00ebbfccu, 31, "FUN_006a09c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a10f0u, 0x002a10f0u, 0x00ebbfccu, 32, "FUN_006a10f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a11f0u, 0x002a11f0u, 0x00ebbfccu, 33, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1240u, 0x002a1240u, 0x00ebbfccu, 34, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0b10u, 0x002a0b10u, 0x00ebbfccu, 35, "FUN_006a0b10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0f90u, 0x002a0f90u, 0x00ebbfccu, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006aff80u, 0x002aff80u, 0x00ebbfccu, 37, "FUN_006aff80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0e50u, 0x002a0e50u, 0x00ebbfccu, 38, "FUN_006a0e50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0fe0u, 0x002a0fe0u, 0x00ebbfccu, 39, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0fe0u, 0x002a0fe0u, 0x00ebbfccu, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c0b0u, 0x0029c0b0u, 0x00ebbfccu, 41, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1290u, 0x002a1290u, 0x00ebbfccu, 42, "unknown_entry", "rage::phConstrainedCollider::SetVelocity", "docs/MemoryMap/virtual_slots.csv; sdk_exact_owner_slot contrib/IV SDK/IV-SDK-main/include/phConstrainedCollider.h:55", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1300u, 0x002a1300u, 0x00ebbfccu, 43, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1330u, 0x002a1330u, 0x00ebbfccu, 44, "FUN_006a1330", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1420u, 0x002a1420u, 0x00ebbfccu, 45, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afc30u, 0x002afc30u, 0x00ebbfccu, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006afc80u, 0x002afc80u, 0x00ebbfccu, 47, "FUN_006afc80", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00ebbfccu, 48, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006a1620u, 0x002a1620u, 0x00ebbfccu, 49, "FUN_006a1620", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
