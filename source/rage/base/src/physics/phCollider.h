#pragma once
#include <cstdint>

// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: rage::phCollider
// Layout, inheritance, signatures and behavior remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

namespace reiv { namespace rage {
class phCollider;
} }

namespace reiv { namespace memory_map { namespace type_d9f2679e0c651b9e {
inline constexpr char name[] = "rage::phCollider";
inline constexpr char mangled[] = ".?AVphCollider@rage@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "";
inline constexpr std::uint32_t type_descriptor_va = 0x010c0304u;
inline constexpr std::uint32_t type_descriptor_rva = 0x00cc0304u;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00f0520cu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00ebbd14u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_d9f2679e0c651b9e {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 50u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x00697dd0u, 0x00297dd0u, 0x00ebbd14u, 0, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c740u, 0x0029c740u, 0x00ebbd14u, 1, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c080u, 0x0029c080u, 0x00ebbd14u, 2, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069cba0u, 0x0029cba0u, 0x00ebbd14u, 3, "FUN_0069cba0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069cdf0u, 0x0029cdf0u, 0x00ebbd14u, 4, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ce60u, 0x0029ce60u, 0x00ebbd14u, 5, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d150u, 0x0029d150u, 0x00ebbd14u, 6, "FUN_0069d150", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00ebbd14u, 7, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_only_stack_pop machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0069d390u, 0x0029d390u, 0x00ebbd14u, 8, "FUN_0069d390", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d450u, 0x0029d450u, 0x00ebbd14u, 9, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ec40u, 0x0029ec40u, 0x00ebbd14u, 10, "FUN_0069ec40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d760u, 0x0029d760u, 0x00ebbd14u, 11, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d860u, 0x0029d860u, 0x00ebbd14u, 12, "FUN_0069d860", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069dd00u, 0x0029dd00u, 0x00ebbd14u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069de50u, 0x0029de50u, 0x00ebbd14u, 14, "FUN_0069de50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069d690u, 0x0029d690u, 0x00ebbd14u, 15, "FUN_0069d690", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ed90u, 0x0029ed90u, 0x00ebbd14u, 16, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json; 64 isolated-storage calls; straight-line scalar body; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0069eda0u, 0x0029eda0u, 0x00ebbd14u, 17, "FUN_0069eda0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ef20u, 0x0029ef20u, 0x00ebbd14u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f070u, 0x0029f070u, 0x00ebbd14u, 19, "FUN_0069f070", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f650u, 0x0029f650u, 0x00ebbd14u, 20, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ef40u, 0x0029ef40u, 0x00ebbd14u, 21, "FUN_0069ef40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f6a0u, 0x0029f6a0u, 0x00ebbd14u, 22, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f770u, 0x0029f770u, 0x00ebbd14u, 23, "FUN_0069f770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069f9e0u, 0x0029f9e0u, 0x00ebbd14u, 24, "FUN_0069f9e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069fbc0u, 0x0029fbc0u, 0x00ebbd14u, 25, "FUN_0069fbc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ff30u, 0x0029ff30u, 0x00ebbd14u, 26, "FUN_0069ff30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069ffe0u, 0x0029ffe0u, 0x00ebbd14u, 27, "FUN_0069ffe0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0760u, 0x002a0760u, 0x00ebbd14u, 28, "FUN_006a0760", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0890u, 0x002a0890u, 0x00ebbd14u, 29, "FUN_006a0890", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0a30u, 0x002a0a30u, 0x00ebbd14u, 30, "FUN_006a0a30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a09c0u, 0x002a09c0u, 0x00ebbd14u, 31, "FUN_006a09c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a10f0u, 0x002a10f0u, 0x00ebbd14u, 32, "FUN_006a10f0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a11f0u, 0x002a11f0u, 0x00ebbd14u, 33, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1240u, 0x002a1240u, 0x00ebbd14u, 34, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0b10u, 0x002a0b10u, 0x00ebbd14u, 35, "FUN_006a0b10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0f90u, 0x002a0f90u, 0x00ebbd14u, 36, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0c10u, 0x002a0c10u, 0x00ebbd14u, 37, "FUN_006a0c10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0e50u, 0x002a0e50u, 0x00ebbd14u, 38, "FUN_006a0e50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0fe0u, 0x002a0fe0u, 0x00ebbd14u, 39, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a0fe0u, 0x002a0fe0u, 0x00ebbd14u, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0069c0b0u, 0x0029c0b0u, 0x00ebbd14u, 41, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1290u, 0x002a1290u, 0x00ebbd14u, 42, "unknown_entry", "rage::phConstrainedCollider::SetVelocity", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/phConstrainedCollider.h:55", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1300u, 0x002a1300u, 0x00ebbd14u, 43, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1330u, 0x002a1330u, 0x00ebbd14u, 44, "FUN_006a1330", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1420u, 0x002a1420u, 0x00ebbd14u, 45, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a1450u, 0x002a1450u, 0x00ebbd14u, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x006a14a0u, 0x002a14a0u, 0x00ebbd14u, 47, "FUN_006a14a0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00ebbd14u, 48, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/RageValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x006a1620u, 0x002a1620u, 0x00ebbd14u, 49, "FUN_006a1620", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
