#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <type_traits>
// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.
// RTTI type: CPlayerPed
// Own caller bodies have scoped reconstruction evidence; complete native layout/inheritance remain unverified.
// Runtime VA = module base + RVA; these addresses are not instances.

// ======================================================================
// FloatCopy
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error CPlayerPed float-copy operations require MSVC x86 inline assembly.
#endif

namespace reiv::game::player_detail {
// VA 0x009C1D90 / slot 79 and VA 0x009C1DD0 / slot 80.
// The original uses x87 loads/stores for components 0 and 3, MOVSS for 1/2.
// Keep that distinction and the late load of component 3: memcpy, or loading
// all four components first, changes signalling NaNs and overlapping inputs.
// Assembly-specific reconstruction; the complete object layout is not inferred.
void CopyBlockEC0(void* object, const void* input);

void CopyBlockED0(void* object, const void* input);
}

// ======================================================================
// Destruction
// ======================================================================
namespace reiv { namespace game {
// Reconstructed control flow, not the implementation of its external callees.
// Callbacks make every dependency explicit and allow isolated trace comparisons.
struct PlayerPedDestructionDependencies {
    void* context;
    std::uint32_t playerVtable; // relocated VA 0x00D819C4
    void (*call8DD270)(void*, void*); // thiscall, no stack arguments
    void (*call8DD8B0)(void*, void*); // thiscall, no stack arguments
    void (*call5B1C10)(void*, void*); // cdecl allocation release
    void* (*load1548F88)(void*); // load at each original call site
    std::uint32_t (*call92F4D0)(void*, void*, std::uint32_t); // thiscall, RET 4
    std::uint32_t (*call8631E0)(void*, std::uint32_t); // cdecl
    void (*call9C0A70)(void*, std::uint32_t); // cdecl
    void (*call920CD0)(void*, void*, std::uint32_t); // thiscall, RET 4
    void (*call4475F0)(void*, void*); // thiscall, embedded member
    void (*call8AC1E0)(void*, void*); // tail call to CPed destructor
    void* (*load18A82AC)(void*);
    void (*call448300)(void*, void*, void*); // thiscall allocator, RET 4
};

class PlayerPedDestruction {    static std::uint32_t Read(const void* p, std::uint32_t offset);    static void Write(void* p, std::uint32_t offset, std::uint32_t value);    static void* Pointer(std::uint32_t value);    static void* Member228(void* object);public:

    // VA 0x009C1E60, complete body ending in JMP 0x008AC1E0.
    // Requires readable [member228 + 0x3E4/0x3E8], as does the original.
    // The EA8 pointer and member228 are deliberately re-read after callbacks.
    static void Destroy(void* object, const PlayerPedDestructionDependencies& d);
    // VA 0x009C2260, scalar deleting-destructor wrapper, RET 4.
    // Return is the original pointer, even when the allocator has released it.
    static void* DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& d);

};
} }

// ======================================================================
// Control
// ======================================================================
namespace reiv { namespace game {
struct PlayerPedControlDependencies {
    void* context;
    const void* (*modelAt15F73B0)(void*, std::uint32_t);
    std::uint32_t (*call8AC500)(void*, void*, std::uint32_t); // thiscall, RET 4
    void (*call8DB2B0)(void*, std::uint32_t); // cdecl
    void (*call9BF660)(void*, void*, std::uint8_t); // thiscall, bool low byte, RET 4
    std::uint32_t (*call8DD530)(void*, void*, std::uint32_t); // cdecl
    void* (*load18A839C)(void*);
    void* (*call439CB0)(void*, void*); // thiscall, no explicit arguments
    void* (*call4F4D20)(void*, void*, void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t); // thiscall, RET 24
    void (*call49F330)(void*, void*, std::uint32_t); // thiscall, RET 4
};
class PlayerPedControl {    static std::uint32_t Read(const void* p, unsigned offset);    static void Write(void* p,unsigned offset,std::uint32_t value);public:

    // VA 0x009C0AA0, slot 14. Raw EAX result; its gameplay meaning is unknown.
    static std::uint32_t ApplyModel(void* object,std::uint32_t model,const PlayerPedControlDependencies& d);
    // VA 0x009C1E10, slot 47, five stack arguments, RET 20.
    static void* CreateControl(void* object,std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t e,std::uint32_t count,const PlayerPedControlDependencies& d);

};
} }

// ======================================================================
// Counter
// ======================================================================
namespace reiv { namespace game {
// Candidate reconstruction of RVA 0x005BE610 and slot 73 RVA 0x005BE770.
// Dependency callbacks must implement the original contracts; no hooks installed.
// The complete CPlayerPed layout and the dependent methods remain unreconstructed.
struct PlayerPedCounterDependencies {
    std::uint8_t (*query426910)(void* receiver, std::uint32_t id, std::uint32_t argument);
    void* (*resolve9BE5D0)(void* player);
    std::uint8_t (*state9C2720)(void* receiver, std::uint32_t* value, std::uint8_t* flag);
    std::uint32_t (*ticks448330)();
    void (*before8A3990)(void* player);
    const volatile std::uint8_t* thresholdF2F067;
};

class PlayerPedCounter {
public:
    // RVA 0x005BE610. Unsigned arithmetic preserves x86 counter overflow.
    static void Update(void* player, const PlayerPedCounterDependencies& d);
    // RVA 0x005BE770, CPlayerPed virtual slot 73.
    static void UpdateSlot73(void* player, const PlayerPedCounterDependencies& d);
};
} }

// ======================================================================
// ProtectedValue
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Protected player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_detail {
// xlive ordinal 5021/5020 are external dependencies, not reconstructed here.
// The machine bodies pass IEEE-754 bits as a DWORD, not a C++ float argument.
using ProtectedSetCallback = std::uint32_t(__stdcall*)(std::uint32_t handle, std::uint32_t offset, std::uint32_t bits);
using ProtectedGetCallback = std::uint32_t(__stdcall*)(std::uint32_t handle, std::uint32_t offset, std::uint32_t* bits);
struct ProtectedCallbacks { ProtectedSetCallback set; ProtectedGetCallback get; };
inline constexpr float FlagThreshold50 = 50.0f, FlagThreshold100 = 100.0f;

// VA 0x00447610: callback results are ignored; EAX returns the protected field.
void* __fastcall WriteProtected(void* field, const ProtectedCallbacks* callbacks, float value);
// VA 0x00447640: the returned float is callback output, never the handle.
float __fastcall ReadProtected(void* field, const ProtectedCallbacks* callbacks);
// VA 0x0089E5A0, preserved COMISS unordered and DAZ behavior.
void __fastcall UpdateValueFlags(void* object, void*, float value);

// VA 0x009C1CF0 / slot 60 and 0x009C1D20 / slot 61. The second
// argument of slot 61 is discarded, yet its original ABI must clean RET 8.
void __fastcall SetProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value);
void __fastcall SetProtectedAndFlagsWithUnused(void* object, const ProtectedCallbacks* callbacks, float value, std::uint32_t unused);

// VA 0x009C1D50 / slot 62. Both original single-precision FST stores occur:
// first overwrites the argument, then FSTP creates the protected setter argument.
void __fastcall AddProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value);
// VA 0x009C1CE0 / slot 63.
float __fastcall GetPlayerProtected(void* object, const ProtectedCallbacks* callbacks);
}

// ======================================================================
// Construction
// ======================================================================
namespace reiv { namespace game {
// Original RVA 0x005C1910. Algorithm with explicit dependency contracts.
// These callbacks describe used arguments, not complete native subsystem ABIs.
// No live constructor replacement is installed and no sizeof is declared.
// Global/address callbacks are pure memory/address access: they must not alter
// other memory, FP state, or call subsystems. Callee callbacks may mutate state.
struct PlayerPedConstructionDependencies {
    std::uint32_t (*readGlobal32)(std::uint32_t va);
    void (*writeGlobal32)(std::uint32_t va, std::uint32_t value);
    void (*writeGlobal8)(std::uint32_t va, std::uint8_t value);
    std::uint32_t (*address)(std::uint32_t canonicalVa);
    void (*base8ABF10)(void*, std::uint32_t, std::uint32_t);
    void (*embeddedC68B50)(void*);
    void (*embedded4475C0)(void*);
    void (*blockB2A8F0)(void*, std::uint32_t);
    void (*blockB29E50)(void*);
    void* (*resolve817F20)(std::uint32_t);
    void (*link920CD0)(void*, void*);
    void (*link921050)(void*);
    void (*initialize9BE4C0)(void*);
    std::uint32_t (*randomD0D21A)();
    std::uint32_t (*hash8631E0)(std::uint32_t);
    void (*value447610)(void*, std::uint32_t);
    void (*flags89E5A0)(void*, std::uint32_t);
    void (*reset9720E0)(void*);
    std::uint32_t (*index797D70)();
    void (*sendMessageA)(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
    void* (*allocate4011D0)(std::uint32_t);
    void* (*create8DA9A0)(void*);
    std::uint8_t (*flag878A00)(void*);
};

class PlayerPedConstruction {    static std::uint32_t R(const void* p, std::uint32_t off);    static void W(void* p, std::uint32_t off, std::uint32_t value);    static void B(void* p, std::uint32_t off, std::uint8_t value);    static std::uint8_t Byte(const void* p, std::uint32_t off);    static std::uint32_t Bits(const void* p);    static void* P(std::uint32_t bits);    static void* Add(void* p, std::uint32_t off);    static void* LinkReceiver(void* player);
    // FLD/FSTP keeps original single-precision conversion behavior for NaNs.
    static std::uint32_t LoadStoreX87(std::uint32_t bits);public:

    // Exactly the original x87 arithmetic and saved-control-word sequence.
    // Isolated for independent FPU-state comparison; MSVC x86 only.
    static std::uint32_t RandomOffset(std::uint32_t random, std::uint32_t scaleBits, std::uint32_t rangeBits);    static void* Construct(void* player, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3,
                           const PlayerPedConstructionDependencies& d);

};
} }

// ======================================================================
// Nonvirtual
// ======================================================================
namespace reiv { namespace game {
// Nonvirtual routines called with the player receiver by virtual slot 29.
// Names describe machine behavior. Defining original C++ class is not recovered.
// External callbacks are explicit contracts; no native hooks are installed.
struct PlayerPedNonvirtualDependencies {
    void* (*resolve7C3900)();
    void (*call9A9EF0)(void* receiver, std::uint32_t argument);
};
struct PlayerPedInitializationDependencies {
    std::uint32_t table1662170;
    void (*resetA677D0)(void* receiver, std::uint32_t, std::uint32_t);
    std::uint32_t (*createA66F20)(void* player);
    void (*linkA67AA0)(void* receiver, void* player);
    void (*startA67D70)(void* receiver);
};
class PlayerPedNonvirtual {    static std::uint32_t R(const void* p, unsigned off);    static void W(void* p, unsigned off, std::uint32_t value);    static void* Pointer(std::uint32_t bits);    static void* LinkReceiver(void* player);    static bool Enabled(const void* player);public:

    // VA 0x009BE4C0. Captured write destination survives create callback.
    // Null dependent pointers remain invalid, as in the original low-address accesses.
    static void InitializeRelations(void* player, const PlayerPedInitializationDependencies& d);
    // VA 0x009BE5D0; original tail-calls global helper 0x007C3900.
    static void* ResolveIfPlayerFlags(const void* player, const PlayerPedNonvirtualDependencies& d);
    // VA 0x009BEE70; original passes receiver+0x2B0 and one zero argument.
    static void CallBlockIfPlayerFlags(void* player, const PlayerPedNonvirtualDependencies& d);

};
} }

// ======================================================================
// Accumulation
// ======================================================================
namespace reiv { namespace game {
struct PlayerPedAccumulationGlobals {
    const std::uint32_t* value11DDE7C;
    const std::uint32_t* multiplierDCC5EC;
    const std::uint32_t* limitD81948;
    const std::uint32_t* resetD81950;
};
// Player receiver supported by the caller's virtual-slot74 type query.
// Original source class declaration and gameplay names remain unknown.
class PlayerPedAccumulation {public:

    // VA 0x009BF5F0. SSE instructions preserve NaNs, MXCSR, and store order.
    // COMISS runs before the EE0 store; an unmasked comparison exception must
    // therefore occur before that store. Unordered and <= skip the reset.
    static void AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals);

};
} }

// ======================================================================
// ExtraFields
// ======================================================================
namespace reiv { namespace game {
struct PlayerPedExtraFieldsGlobals {
    const std::uint32_t* limitDECD60;
    const std::uint32_t* resetD81958;
};
// Player-flag guarded callers pass their preserved player receiver in ECX.
// These names refer to offsets; original defining C++ class names are inferred.
class PlayerPedExtraFields {public:

    // VA 0x009BF5D0. The original defines AL only. Unordered COMISS returns one.
    static std::uint8_t TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals);
    // VA 0x009BF640. Ordered zero/negative resets; unordered comparison skips.
    static void ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals);

};
} }

// ======================================================================
// Layout
// ======================================================================
namespace reiv::game {
// Flat x86 storage view, not a C++ inheritance reconstruction. All addresses are
// uint32_t values, even when this header is parsed on a 64-bit host. Unknown
// bytes are explicit. Semantic labels correlate the local IV SDK; offsets
// and widths come from canonical bodies. CPed base boundary remains unknown.
// Evidence: reversing/PlayerPedLayout/pool-stride-evidence.json.
struct PlayerPedObservedStorage {
    std::uint32_t vtable_address; // +0x0; ctor009C1930; RTTI vtable
    std::uint8_t unknown_004_020[0x1C];
    std::uint32_t matrix_address; // +0x20; update009C0B00; SDK CEntity+20
    std::uint8_t unknown_024_028[0x4];
    std::uint32_t entity_flags_28; // +0x28; update009C0B00; SDK CEntity+28
    std::uint8_t unknown_02c_063[0x37];
    std::uint8_t alpha_63; // +0x63; ctor009C1BFA; SDK CEntity+63
    std::uint8_t unknown_064_068[0x4];
    std::uint32_t field_68; // +0x68; ctor009C1BB0
    std::uint32_t network_object_address; // +0x6C; slot47 009C1E10; SDK CEntity+6C
    std::uint8_t unknown_070_118[0xA8];
    std::uint32_t physical_flags_118; // +0x118; update009C0B00; SDK CPhysical+118
    std::uint8_t unknown_11c_210[0xF4];
    std::uint8_t dead_flag_210; // +0x210; helper0089E5A0; SDK CPed
    std::uint8_t injured_flag_211; // +0x211; helper0089E5A0; SDK CPed
    std::uint8_t fatal_injury_flag_212; // +0x212; helper0089E5A0; SDK CPed
    std::uint8_t unknown_213_214[0x1];
    std::uint32_t health_bits_214; // +0x214; helper0089E5A0; SDK CPed
    std::uint8_t player_index_218; // +0x218; ctor009C1A5C; SDK CPed
    std::uint8_t is_player_219; // +0x219; ctor009C1A64; SDK CPed
    std::uint8_t unknown_21a_21c[0x2];
    std::uint32_t drawable_info_address; // +0x21C; ctor009C1A50; SDK CPed
    std::uint8_t unknown_220_224[0x4];
    std::uint32_t intelligence_address; // +0x224; ctor009C1B5D; SDK CPed
    std::uint32_t player_info_address; // +0x228; ctor009C19DE; SDK CPed
    std::uint8_t unknown_22c_260[0x34];
    std::uint32_t ped_flags_260; // +0x260; ctor009C1ACC; SDK CPed
    std::uint8_t unknown_264_26c[0x8];
    std::uint32_t ped_flags_26c; // +0x26C; update009C0B00; SDK CPed
    std::uint8_t unknown_270_29c[0x2C];
    std::uint32_t field_29c; // +0x29C; update009C0B00 index0xA7
    std::uint8_t unknown_2a0_2dc[0x3C];
    std::uint32_t weapon_object_address; // +0x2DC; update009C0B00 index0xB7; SDK CPed
    std::uint8_t unknown_2e0_3a8[0xC8];
    std::uint32_t field_3a8; // +0x3A8; update009C0B00 index0xEA
    std::uint8_t unknown_3ac_7c4[0x418];
    std::uint32_t field_7c4; // +0x7C4; update009C0B00 index0x1F1
    std::uint8_t unknown_7c8_a84[0x2BC];
    std::uint32_t field_a84; // +0xA84; update009C0B00 index0x2A1
    std::uint8_t unknown_a88_a94[0xC];
    std::uint32_t max_health_bits_a94; // +0xA94; ctor009C1AEA; SDK CPed
    std::uint8_t unknown_a98_ac0[0x28];
    std::uint32_t field_ac0; // +0xAC0; update009C0B00 index0x2B0
    std::uint8_t unknown_ac4_b38[0x74];
    std::uint32_t field_b38; // +0xB38; update009C0B00 index0x2CE
    std::uint8_t unknown_b3c_b40[0x4];
    std::uint32_t vehicle_address; // +0xB40; update009C0B00 index0x2D0; SDK CPed
    std::uint8_t unknown_b44_b90[0x4C];
    std::uint32_t field_b90; // +0xB90; update009C0B00 index0x2E4
    std::uint8_t unknown_b94_e70[0x2DC];
    std::uint8_t field_e70; // +0xE70; ctor009C1B40
    std::uint8_t field_e71; // +0xE71; ctor009C1B63
    std::uint8_t unknown_e72_e74[0x2];
    std::uint32_t field_e74; // +0xE74; ctor009C1B34
    std::uint32_t field_e78; // +0xE78; ctor009C1B3A
    std::uint32_t self_address_e7c; // +0xE7C; ctor009C1BCE
    // Constructor calls an embedded initializer at +E80; its extent is unproven.
    std::uint8_t unknown_e80_ea4[0x24];
    std::uint8_t field_ea4; // ctor009C1C04
    std::uint8_t field_ea5; // ctor009C1C0A
    std::uint8_t field_ea6; // ctor009C1BFE
    std::uint8_t field_ea7; // ctor009C1C10
    std::uint32_t component_models_address; // +0xEA8; ctor009C1BF4; SDK CPed
    std::uint32_t protected_handle_eac; // +0xEAC; helpers00447610/00447640
    std::uint32_t counter_eb0; // +0xEB0; ctor009C1C16; helper009BE610
    std::uint32_t counter_eb4; // +0xEB4; ctor009C1C1C; helper009BE610
    std::uint32_t field_eb8; // +0xEB8; ctor009C1C22
    std::uint32_t field_ebc; // +0xEBC; slot75/78
    std::uint32_t block_ec0[4]; // +0xEC0; slot76/79
    std::uint32_t block_ed0[4]; // +0xED0; slot77/80
    std::uint32_t field_ee0; // +0xEE0; ctor009C1C28
    std::uint32_t field_ee4; // +0xEE4; ctor009C1C30
    std::uint32_t field_ee8; // +0xEE8; ctor009C1C40
    std::uint32_t field_eec; // +0xEEC; ctor009C1C50
    std::uint32_t field_ef0; // +0xEF0; slot81; ctor009C1C58
    std::uint32_t field_ef4; // +0xEF4; ctor009C1C62
};

// The allocator initializes the ped pool with stride 0xF00 and 120 slots.
// This proves slot storage extent, not exact sizeof of the original class.
struct PlayerPedPoolSlotStorage {
    PlayerPedObservedStorage observed;
    std::uint8_t unknown_ef8_f00[8];
};
inline constexpr std::size_t PlayerPedPoolStride = 0xF00;
inline constexpr std::size_t PlayerPedObservedMinimum = 0xEF8;
static_assert(std::is_standard_layout_v<PlayerPedObservedStorage>);
static_assert(sizeof(PlayerPedObservedStorage) == PlayerPedObservedMinimum);
static_assert(sizeof(PlayerPedPoolSlotStorage) == PlayerPedPoolStride);
static_assert(offsetof(PlayerPedObservedStorage, vtable_address) == 0x0);
static_assert(offsetof(PlayerPedObservedStorage, matrix_address) == 0x20);
static_assert(offsetof(PlayerPedObservedStorage, entity_flags_28) == 0x28);
static_assert(offsetof(PlayerPedObservedStorage, alpha_63) == 0x63);
static_assert(offsetof(PlayerPedObservedStorage, field_68) == 0x68);
static_assert(offsetof(PlayerPedObservedStorage, network_object_address) == 0x6C);
static_assert(offsetof(PlayerPedObservedStorage, physical_flags_118) == 0x118);
static_assert(offsetof(PlayerPedObservedStorage, dead_flag_210) == 0x210);
static_assert(offsetof(PlayerPedObservedStorage, injured_flag_211) == 0x211);
static_assert(offsetof(PlayerPedObservedStorage, fatal_injury_flag_212) == 0x212);
static_assert(offsetof(PlayerPedObservedStorage, health_bits_214) == 0x214);
static_assert(offsetof(PlayerPedObservedStorage, player_index_218) == 0x218);
static_assert(offsetof(PlayerPedObservedStorage, is_player_219) == 0x219);
static_assert(offsetof(PlayerPedObservedStorage, drawable_info_address) == 0x21C);
static_assert(offsetof(PlayerPedObservedStorage, intelligence_address) == 0x224);
static_assert(offsetof(PlayerPedObservedStorage, player_info_address) == 0x228);
static_assert(offsetof(PlayerPedObservedStorage, ped_flags_260) == 0x260);
static_assert(offsetof(PlayerPedObservedStorage, ped_flags_26c) == 0x26C);
static_assert(offsetof(PlayerPedObservedStorage, field_29c) == 0x29C);
static_assert(offsetof(PlayerPedObservedStorage, weapon_object_address) == 0x2DC);
static_assert(offsetof(PlayerPedObservedStorage, field_3a8) == 0x3A8);
static_assert(offsetof(PlayerPedObservedStorage, field_7c4) == 0x7C4);
static_assert(offsetof(PlayerPedObservedStorage, field_a84) == 0xA84);
static_assert(offsetof(PlayerPedObservedStorage, max_health_bits_a94) == 0xA94);
static_assert(offsetof(PlayerPedObservedStorage, field_ac0) == 0xAC0);
static_assert(offsetof(PlayerPedObservedStorage, field_b38) == 0xB38);
static_assert(offsetof(PlayerPedObservedStorage, vehicle_address) == 0xB40);
static_assert(offsetof(PlayerPedObservedStorage, field_b90) == 0xB90);
static_assert(offsetof(PlayerPedObservedStorage, field_e70) == 0xE70);
static_assert(offsetof(PlayerPedObservedStorage, field_e71) == 0xE71);
static_assert(offsetof(PlayerPedObservedStorage, field_e74) == 0xE74);
static_assert(offsetof(PlayerPedObservedStorage, field_e78) == 0xE78);
static_assert(offsetof(PlayerPedObservedStorage, self_address_e7c) == 0xE7C);
static_assert(offsetof(PlayerPedObservedStorage, field_ea4) == 0xEA4);
static_assert(offsetof(PlayerPedObservedStorage, field_ea5) == 0xEA5);
static_assert(offsetof(PlayerPedObservedStorage, field_ea6) == 0xEA6);
static_assert(offsetof(PlayerPedObservedStorage, field_ea7) == 0xEA7);
static_assert(offsetof(PlayerPedObservedStorage, component_models_address) == 0xEA8);
static_assert(offsetof(PlayerPedObservedStorage, protected_handle_eac) == 0xEAC);
static_assert(offsetof(PlayerPedObservedStorage, counter_eb0) == 0xEB0);
static_assert(offsetof(PlayerPedObservedStorage, counter_eb4) == 0xEB4);
static_assert(offsetof(PlayerPedObservedStorage, field_eb8) == 0xEB8);
static_assert(offsetof(PlayerPedObservedStorage, field_ebc) == 0xEBC);
static_assert(offsetof(PlayerPedObservedStorage, block_ec0) == 0xEC0);
static_assert(offsetof(PlayerPedObservedStorage, block_ed0) == 0xED0);
static_assert(offsetof(PlayerPedObservedStorage, field_ee0) == 0xEE0);
static_assert(offsetof(PlayerPedObservedStorage, field_ee4) == 0xEE4);
static_assert(offsetof(PlayerPedObservedStorage, field_ee8) == 0xEE8);
static_assert(offsetof(PlayerPedObservedStorage, field_eec) == 0xEEC);
static_assert(offsetof(PlayerPedObservedStorage, field_ef0) == 0xEF0);
static_assert(offsetof(PlayerPedObservedStorage, field_ef4) == 0xEF4);
}

// ======================================================================
// Update
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player update transcription requires MSVC x86.
#endif
namespace reiv::game::player_update {
// Complete caller transcription, with external functions and globals explicit.
// ISOLATED FIXTURES ONLY: shared mutable storage is not thread-safe or a game binding.
// No live-game replacement is installed. Raw callback pointers retain original ABI.
inline std::uint32_t g00D50398=0; // original storage VA 0x00D50398, exact operand widths below
inline std::uint32_t g00D582A0=0; // original storage VA 0x00D582A0, exact operand widths below
inline std::uint32_t g00D796E4=0; // original storage VA 0x00D796E4, exact operand widths below
inline std::uint32_t g00D81944=0; // original storage VA 0x00D81944, exact operand widths below
inline std::uint32_t g00D81958=0; // original storage VA 0x00D81958, exact operand widths below
inline std::uint32_t g00D819B8=0; // original storage VA 0x00D819B8, exact operand widths below
inline std::uint32_t g00D8F340=0; // original storage VA 0x00D8F340, exact operand widths below
inline std::uint32_t g00DC9290=0; // original storage VA 0x00DC9290, exact operand widths below
inline std::uint32_t g00DCB2AC=0; // original storage VA 0x00DCB2AC, exact operand widths below
inline std::uint32_t g00E3447C=0; // original storage VA 0x00E3447C, exact operand widths below
inline std::uint32_t g00EBDED4=0; // original storage VA 0x00EBDED4, exact operand widths below
inline std::uint32_t g00F0E4A0=0; // original storage VA 0x00F0E4A0, exact operand widths below
inline std::uint32_t g00F21A70=0; // original storage VA 0x00F21A70, exact operand widths below
inline std::uint32_t g00F317B8=0; // original storage VA 0x00F317B8, exact operand widths below
inline std::uint32_t g010D0170=0; // original storage VA 0x010D0170, exact operand widths below
inline std::uint32_t g010E1984=0; // original storage VA 0x010E1984, exact operand widths below
inline std::uint32_t g011DDE74=0; // original storage VA 0x011DDE74, exact operand widths below
inline std::uint32_t g011DDE7C=0; // original storage VA 0x011DDE7C, exact operand widths below
inline std::uint32_t g011DDF38=0; // original storage VA 0x011DDF38, exact operand widths below
inline std::uint32_t g01618020=0; // original storage VA 0x01618020, exact operand widths below
inline std::uint32_t g016180E8=0; // original storage VA 0x016180E8, exact operand widths below
inline std::uint32_t g016180EC=0; // original storage VA 0x016180EC, exact operand widths below
inline std::uint32_t g016180F0=0; // original storage VA 0x016180F0, exact operand widths below
inline std::uint32_t g016180F4=0; // original storage VA 0x016180F4, exact operand widths below
inline std::uint32_t g016180F8=0; // original storage VA 0x016180F8, exact operand widths below
inline std::uint32_t g0161810C=0; // original storage VA 0x0161810C, exact operand widths below
inline std::uint32_t g01618110=0; // original storage VA 0x01618110, exact operand widths below
inline std::uint32_t g01724286=0; // original storage VA 0x01724286, exact operand widths below
inline unsigned char object0168F910[16]{}; // opaque context identity, dependency owns layout
inline void* call00401950=nullptr;
inline void* call004269B0=nullptr;
inline void* call004389D0=nullptr;
inline void* call00462F90=nullptr;
inline void* call0088F5D0=nullptr;
inline void* call0089EA80=nullptr;
inline void* call008AADC0=nullptr;
inline void* call008AE670=nullptr;
inline void* call0091A050=nullptr;
inline void* call0091A0A0=nullptr;
inline void* call00922850=nullptr;
inline void* call00924E80=nullptr;
inline void* call00976E90=nullptr;
inline void* call0097D7C0=nullptr;
inline void* call00987730=nullptr;
inline void* call009A9CF0=nullptr;
inline void* call009BE5D0=nullptr;
inline void* call009BE7D0=nullptr;
inline void* call009BEE70=nullptr;
inline void* call009BEED0=nullptr;
inline void* call009BFD80=nullptr;
inline void* call009E6630=nullptr;
inline void* call00AA80D0=nullptr;
inline void* call00AA83F0=nullptr;
inline void* call00AB3B60=nullptr;
inline void* call00AFE160=nullptr;
inline void* call00AFEA00=nullptr;
// All dependencies must be bound before use; original caller uses AL return.
__declspec(naked) inline std::uint8_t __fastcall Update(void* object, void*) {
    __asm {
        push ebp
        mov ebp, esp
        and esp, 0FFFFFFF0h
        sub esp, 034h
        push ebx
        push esi
        mov esi, ecx
        xor ebx, ebx
        cmp byte ptr [esi + 0218h], bl
        push edi
        mov edx, 1
        je L009C0B29
        cmp byte ptr [esi + 0219h], bl
        jne L009C12F0
    L009C0B29:
        cmp dword ptr [g010D0170], edx
        je L009C12F0
        mov eax, dword ptr [g010E1984]
        cmp eax, dword ptr [g00E3447C]
        jne L009C12F0
        cmp dword ptr [g00F0E4A0], 012h
        je L009C12F0
        mov eax, dword ptr [esi + 0228h]
        or dword ptr [esi + 028h], 010000000h
        cmp eax, ebx
        mov byte ptr [esi + 0E71h], bl
        je L009C0B6F
        lea ecx, [eax + 060h]
        jmp L009C0B71
    L009C0B6F:
        xor ecx, ecx
    L009C0B71:
        cmp byte ptr [ecx + 03BCh], bl
        jbe L009C0B8B
        cmp eax, ebx
        je L009C0B82
        add eax, 060h
        jmp L009C0B84
    L009C0B82:
        xor eax, eax
    L009C0B84:
        add byte ptr [eax + 03BCh], 0FFh
    L009C0B8B:
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0B9A
        lea ecx, [eax + 060h]
        jmp L009C0B9C
    L009C0B9A:
        xor ecx, ecx
    L009C0B9C:
        cmp byte ptr [ecx + 03BCh], bl
        jne L009C0BB5
        cmp eax, ebx
        je L009C0BAD
        add eax, 060h
        jmp L009C0BAF
    L009C0BAD:
        xor eax, eax
    L009C0BAF:
        mov dword ptr [eax + 03CCh], ebx
    L009C0BB5:
        cmp byte ptr [esi + 0219h], bl
        je L009C0BFE
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0BCC
        add eax, 060h
        jmp L009C0BCE
    L009C0BCC:
        xor eax, eax
    L009C0BCE:
        mov byte ptr [eax + 0415h], bl
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0BE3
        lea ecx, [eax + 060h]
        jmp L009C0BE5
    L009C0BE3:
        xor ecx, ecx
    L009C0BE5:
        cmp byte ptr [ecx + 0416h], bl
        je L009C0BFE
        cmp eax, ebx
        je L009C0BF6
        add eax, 060h
        jmp L009C0BF8
    L009C0BF6:
        xor eax, eax
    L009C0BF8:
        mov byte ptr [eax + 0415h], dl
    L009C0BFE:
        cmp dword ptr [g016180E8], edx
        je L009C0CDA
        mov eax, dword ptr [g011DDE74]
        cmp dword ptr [g016180EC], eax
        jge L009C0CDA
        cmp dword ptr [g016180F0], ebx
        jne L009C0CBC
        push 064h
        push ebx
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Ah
        jle L009C0CDA
        mov ecx, dword ptr [g00F21A70]
        push ecx
        mov ecx, dword ptr [g01618020]
        call dword ptr [call0088F5D0]
        test byte ptr [g01618110], 1
        mov edi, eax
        jne L009C0C78
        or dword ptr [g01618110], 1
        push 05Ah
        push 02Dh
        call dword ptr [call00401950]
        add esp, 8
        imul eax, eax, 03E8h
        mov dword ptr [g0161810C], eax
        jmp L009C0C7D
    L009C0C78:
        mov eax, dword ptr [g0161810C]
    L009C0C7D:
        fld dword ptr [g00F317B8]
        push eax
        push ecx
        fstp dword ptr [esp]
        push edi
        mov ecx, offset object0168F910
        call dword ptr [call00AFE160]
        push eax
        mov ecx, offset object0168F910
        call dword ptr [call00AFEA00]
        mov edx, dword ptr [g0161810C]
        mov eax, dword ptr [g011DDE74]
        add eax, edx
        mov dword ptr [g016180F4], eax
        mov dword ptr [g016180F0], 1
        jmp L009C0CDA
    L009C0CBC:
        cmp dword ptr [g016180F4], eax
        jge L009C0CDA
        push 064h
        push ebx
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Ah
        jle L009C0CDA
        mov dword ptr [g016180F0], ebx
    L009C0CDA:
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0CE9
        lea ecx, [eax + 060h]
        jmp L009C0CEB
    L009C0CE9:
        xor ecx, ecx
    L009C0CEB:
        cmp byte ptr [ecx + 03DDh], bl
        je L009C0D4E
        cmp eax, ebx
        je L009C0CFC
        lea ecx, [eax + 060h]
        jmp L009C0CFE
    L009C0CFC:
        xor ecx, ecx
    L009C0CFE:
        movzx ecx, byte ptr [ecx + 03DCh]
        sub ecx, 1
        test ecx, ecx
        jg L009C0D3C
        cmp eax, ebx
        je L009C0D15
        add eax, 060h
        jmp L009C0D17
    L009C0D15:
        xor eax, eax
    L009C0D17:
        mov byte ptr [eax + 03DCh], bl
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0D32
        add eax, 060h
        mov byte ptr [eax + 03DDh], bl
        jmp L009C0D4E
    L009C0D32:
        xor eax, eax
        mov byte ptr [eax + 03DDh], bl
        jmp L009C0D4E
    L009C0D3C:
        cmp eax, ebx
        je L009C0D45
        add eax, 060h
        jmp L009C0D47
    L009C0D45:
        xor eax, eax
    L009C0D47:
        add byte ptr [eax + 03DCh], 0FFh
    L009C0D4E:
        test byte ptr [esi + 0118h], 1
        je L009C0DAC
        mov eax, dword ptr [esi + 020h]
        movss xmm1, dword ptr [eax + 034h]
        movss xmm0, dword ptr [eax + 038h]
        movss xmm2, dword ptr [eax + 030h]
        add eax, 030h
        movaps xmm3, xmm1
        mulss xmm3, xmm1
        movaps xmm1, xmm0
        mulss xmm1, xmm0
        movaps xmm0, xmm2
        addss xmm3, xmm1
        mulss xmm0, xmm2
        addss xmm3, xmm0
        comiss xmm3, dword ptr [g00D819B8]
        jbe L009C0D9C
        movss xmm0, dword ptr [g00D81944]
        jmp L009C0DA4
    L009C0D9C:
        movss xmm0, dword ptr [g00D582A0]
    L009C0DA4:
        movss dword ptr [esi + 0B38h], xmm0
    L009C0DAC:
        movss xmm0, dword ptr [esi + 0EE4h]
        xorps xmm1, xmm1
        comiss xmm0, xmm1
        jbe L009C0DCC
        subss xmm0, dword ptr [g011DDE7C]
        movss dword ptr [esi + 0EE4h], xmm0
    L009C0DCC:
        movss xmm0, dword ptr [esi + 0EE0h]
        comiss xmm0, xmm1
        jbe L009C0DF5
        movss xmm1, dword ptr [g011DDE7C]
        mulss xmm1, dword ptr [g00DC9290]
        subss xmm0, xmm1
        movss dword ptr [esi + 0EE0h], xmm0
    L009C0DF5:
        mov ecx, esi
        call dword ptr [call008AADC0]
        or dword ptr [esi + 029Ch], 020h
        mov ecx, esi
        call dword ptr [call009BE5D0]
        mov ebx, eax
        mov eax, dword ptr [esi + 0AC0h]
        test eax, eax
        je L009C0E67
        mov edx, dword ptr [eax + 028h]
        and edx, 03C0h
        cmp edx, 080h
        jne L009C0E67
        cmp dword ptr [eax + 01354h], 0
        jne L009C0E67
        test byte ptr [eax + 0F6Fh], 040h
        je L009C0E67
        mov ecx, dword ptr [eax + 0FA0h]
        test ecx, ecx
        je L009C0E67
        mov ecx, dword ptr [ecx + 021Ch]
        cmp dword ptr [ecx + 012Ch], 2
        jne L009C0E67
        test byte ptr [g011DDF38], 03Fh
        jne L009C0E67
        push esi
        push eax
        push 0Ah
        call dword ptr [call00AB3B60]
        add esp, 0Ch
    L009C0E67:
        test byte ptr [esi + 026Ch], 4
        je L009C0E78
        mov edx, dword ptr [esi + 0B40h]
        jmp L009C0E7A
    L009C0E78:
        xor edx, edx
    L009C0E7A:
        mov eax, dword ptr [esi + 0228h]
        test eax, eax
        je L009C0E89
        lea ecx, [eax + 060h]
        jmp L009C0E8B
    L009C0E89:
        xor ecx, ecx
    L009C0E8B:
        push edx
        mov edx, dword ptr [esi + 020h]
        add edx, 030h
        push edx
        call dword ptr [call00922850]
        mov ecx, esi
        call dword ptr [call009E6630]
        cmp dword ptr [esi + 03A8h], 0
        je L009C0F0A
        lea edi, [esi + 02B0h]
        mov ecx, edi
        call dword ptr [call009A9CF0]
        test eax, eax
        je L009C0F03
        mov ecx, edi
        call dword ptr [call009A9CF0]
        mov eax, dword ptr [eax + 018h]
        push eax
        call dword ptr [call00924E80]
        add esp, 4
        cmp dword ptr [eax + 0Ch], 1
        je L009C0F03
        mov ecx, dword ptr [esi + 03A8h]
        push 0
        push ecx
        push esi
        lea ecx, [esp + 02Ch]
        call dword ptr [call0091A050]
        push 1
        lea edx, [esp + 024h]
        push 0
        push edx
        call dword ptr [call00AA83F0]
        mov ecx, eax
        call dword ptr [call00AA80D0]
        lea ecx, [esp + 020h]
        call dword ptr [call0091A0A0]
    L009C0F03:
        mov ecx, esi
        call dword ptr [call009BEED0]
    L009C0F0A:
        test ebx, ebx
        je L009C0FCB
        mov eax, dword ptr [esi + 038h]
        test eax, eax
        je L009C0FCB
        cmp eax, dword ptr [esi + 07C4h]
        jne L009C0FCB
        mov eax, dword ptr [esi + 02DCh]
        test eax, eax
        je L009C0FCB
        mov eax, dword ptr [eax + 025Ch]
        test eax, eax
        je L009C0FCB
        mov ecx, eax
        call dword ptr [call004269B0]
        test al, al
        je L009C0FCB
        mov al, byte ptr [ebx + 026DEh]
        xor al, byte ptr [ebx + 026DCh]
        cmp al, 07Fh
        jbe L009C0FCB
        mov ecx, dword ptr [esi + 0224h]
        call dword ptr [call0089EA80]
        test eax, eax
        je L009C0F7F
        mov edx, dword ptr [eax]
        mov ecx, eax
        mov eax, dword ptr [edx + 0Ch]
        call eax
        cmp eax, 0841h
        je L009C0FCB
    L009C0F7F:
        mov eax, dword ptr [esi + 02DCh]
        lea ecx, [esp + 010h]
        push ecx
        mov ecx, dword ptr [eax + 020h]
        lea edx, [esp + 024h]
        push edx
        push ecx
        mov ecx, dword ptr [eax + 025Ch]
        push eax
        call dword ptr [call00976E90]
        fld dword ptr [g00EBDED4]
        mov eax, dword ptr [esi + 02DCh]
        mov edx, dword ptr [eax + 020h]
        push ecx
        mov ecx, dword ptr [eax + 025Ch]
        fstp dword ptr [esp]
        push 0
        push 0
        push 0
        push 0
        push 0
        push 0
        push edx
        push esi
        call dword ptr [call0097D7C0]
    L009C0FCB:
        mov eax, dword ptr [esi + 0B90h]
        test eax, eax
        je L009C1029
        cmp eax, 3
        je L009C1002
        cmp eax, 4
        je L009C0FFD
        cmp dword ptr [g016180E8], 1
        je L009C105A
        mov eax, dword ptr [g016180EC]
        cmp eax, dword ptr [g011DDE74]
        jge L009C105A
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C0FFD:
        cmp eax, 3
        jne L009C1069
    L009C1002:
        cmp dword ptr [g016180E8], 1
        je L009C1021
        mov ecx, dword ptr [g016180EC]
        cmp ecx, dword ptr [g011DDE74]
        jge L009C1021
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C1021:
        fld dword ptr [g00D796E4]
        jmp L009C105C
    L009C1029:
        test byte ptr [esi + 026Ch], 4
        je L009C1069
        cmp dword ptr [esi + 0B40h], 0
        je L009C1069
        cmp dword ptr [g016180E8], 1
        je L009C105A
        mov edx, dword ptr [g016180EC]
        cmp edx, dword ptr [g011DDE74]
        jge L009C105A
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C105A:
        fld1 
    L009C105C:
        push ecx
        fstp dword ptr [esp]
        push 0
        mov ecx, esi
        call dword ptr [call009BFD80]
    L009C1069:
        mov eax, dword ptr [esi + 0A84h]
        cmp eax, 1
        je L009C1079
        cmp eax, 2
        jne L009C1089
    L009C1079:
        mov ecx, esi
        call dword ptr [call009BEE70]
        mov al, 1
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    L009C1089:
        mov eax, dword ptr [esi]
        mov edx, dword ptr [eax + 0ECh]
        lea ecx, [esp + 020h]
        push ecx
        mov ecx, esi
        call edx
        movss xmm1, dword ptr [eax + 4]
        movss xmm0, dword ptr [eax]
        mov eax, dword ptr [esi + 0228h]
        movaps xmm2, xmm1
        mulss xmm2, xmm1
        movaps xmm1, xmm0
        mulss xmm1, xmm0
        addss xmm2, xmm1
        movss xmm1, dword ptr [g00DC9290]
        sqrtss xmm0, xmm2
        comiss xmm1, xmm0
        jbe L009C111E
        test eax, eax
        je L009C10D5
        add eax, 060h
        jmp L009C10D7
    L009C10D5:
        xor eax, eax
    L009C10D7:
        cmp dword ptr [eax + 03C0h], 0
        mov ecx, esi
        jne L009C10FA
        mov eax, dword ptr [g011DDE74]
        lea edi, [eax + 01F4h]
        call dword ptr [call004389D0]
        mov dword ptr [eax + 03C0h], edi
        jmp L009C114B
    L009C10FA:
        call dword ptr [call004389D0]
        mov ecx, dword ptr [g011DDE74]
        cmp ecx, dword ptr [eax + 03C0h]
        jbe L009C114B
        mov ecx, esi
        call dword ptr [call004389D0]
        add eax, 03D0h
        or dword ptr [eax], 1
        jmp L009C114B
    L009C111E:
        test eax, eax
        je L009C1127
        add eax, 060h
        jmp L009C1129
    L009C1127:
        xor eax, eax
    L009C1129:
        mov dword ptr [eax + 03C0h], 0
        mov eax, dword ptr [esi + 0228h]
        test eax, eax
        je L009C1142
        add eax, 060h
        jmp L009C1144
    L009C1142:
        xor eax, eax
    L009C1144:
        and dword ptr [eax + 03D0h], 0FFFFFFFEh
    L009C114B:
        lea edi, [esi + 02B0h]
        mov ecx, edi
        call dword ptr [call009A9CF0]
        test eax, eax
        je L009C117C
        mov ecx, edi
        call dword ptr [call009A9CF0]
        cmp dword ptr [eax + 01Ch], 1
        jne L009C117C
        mov ecx, esi
        call dword ptr [call004389D0]
        mov edx, dword ptr [g011DDE74]
        mov dword ptr [eax + 03F8h], edx
    L009C117C:
        mov eax, dword ptr [esi + 0B40h]
        test eax, eax
        je L009C1203
        cmp dword ptr [g016180E8], 1
        je L009C1203
        mov ecx, dword ptr [g016180EC]
        cmp ecx, dword ptr [g011DDE74]
        jge L009C1203
        movss xmm0, dword ptr [g00D50398]
        push 064h
        push 0
        movss dword ptr [eax + 010C8h], xmm0
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Fh
        jle L009C11CB
        mov eax, dword ptr [esi + 0B40h]
        or byte ptr [eax + 0F64h], 080h
    L009C11CB:
        mov eax, dword ptr [g016180F8]
        test eax, eax
        je L009C11DC
        cmp dword ptr [esi + 0B40h], eax
        je L009C1203
    L009C11DC:
        mov edx, dword ptr [esi + 0B40h]
        fld dword ptr [g00D8F340]
        push ecx
        mov dword ptr [g016180F8], edx
        fstp dword ptr [esp]
        mov ecx, dword ptr [esi + 0B40h]
        add ecx, 01120h
        call dword ptr [call008AE670]
    L009C1203:
        cmp byte ptr [g01724286], 0
        je L009C1215
        call dword ptr [call00462F90]
        test al, al
        je L009C121C
    L009C1215:
        mov ecx, esi
        call dword ptr [call009BE7D0]
    L009C121C:
        cmp dword ptr [esi + 0B0h], 0
        je L009C1293
        cmp dword ptr [esi + 0B8h], 0
        jle L009C1293
        mov eax, dword ptr [esi + 0AC0h]
        test eax, eax
        je L009C1293
        mov eax, dword ptr [eax + 028h]
        and eax, 03C0h
        cmp eax, 0100h
        jne L009C1293
        movss xmm0, dword ptr [esi + 0EE8h]
        subss xmm0, dword ptr [g011DDE7C]
        xorps xmm1, xmm1
        comiss xmm1, xmm0
        movss dword ptr [esi + 0EE8h], xmm0
        jb L009C1293
        fldz 
        push ecx
        mov ecx, dword ptr [esi + 020h]
        fstp dword ptr [esp]
        push 0
        push 0
        push esi
        add ecx, 030h
        push ecx
        push 2
        call dword ptr [call00987730]
        movss xmm0, dword ptr [g00D81958]
        add esp, 018h
        movss dword ptr [esi + 0EE8h], xmm0
    L009C1293:
        movss xmm0, dword ptr [esi + 0EECh]
        xorps xmm1, xmm1
        comiss xmm0, xmm1
        jbe L009C12D4
        subss xmm0, dword ptr [g011DDE7C]
        comiss xmm1, xmm0
        movss dword ptr [esi + 0EECh], xmm0
        jb L009C12D4
        fldz 
        mov edx, dword ptr [esi + 020h]
        push ecx
        fstp dword ptr [esp]
        push 0
        push 0
        push esi
        add edx, 030h
        push edx
        push 015h
        call dword ptr [call00987730]
        add esp, 018h
    L009C12D4:
        mov eax, dword ptr [esi + 0EF4h]
        test eax, eax
        jle L009C12F5
        add eax, -1
        mov dword ptr [esi + 0EF4h], eax
        mov al, 1
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    L009C12F0:
        call dword ptr [call008AADC0]
    L009C12F5:
        pop edi
        pop esi
        mov al, 1
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    }
}
}

// ======================================================================
// ModelReset
// ======================================================================
namespace reiv { namespace game {
struct PlayerPedModelResetDependencies {
    const volatile std::uint32_t* sourceD50398;
    volatile std::uint32_t* globalF1D9D8;
    void (*call8A92C0)(void*,std::uint32_t);
    void (*call8A07E0)(void*,std::uint32_t);
    void (*call8A70C0)(void*,std::uint32_t,std::uint32_t);
    void (*call89C8B0)(void*,std::uint32_t);
    void (*virtualSlot68)(void*);
    void (*call9BF0D0)(void*,std::uint32_t,std::uint32_t,std::uint32_t);
    void (*call8793F0)(void*);
};
class PlayerPedModelReset {    static std::uint32_t Read(const void*p,unsigned offset);    static void Write(void*p,unsigned offset,std::uint32_t v);    static void* Member(std::uint32_t bits);public:

    // VA 0x009BF660. One byte-valued stack argument; original RET 4.
    // MOVSS global transfer is a bit copy, with no numeric float conversion.
    static void Reset(void* player,std::uint8_t argument,const PlayerPedModelResetDependencies& d);

};
} }

// ======================================================================
// ReferenceClear
// ======================================================================
namespace reiv { namespace game {
struct PlayerPedReferenceClearDependencies {
    void (*call9E6580)(void* receiver,std::uint32_t* field); // thiscall receiver, RET 4
};
class PlayerPedReferenceClear {public:

    // VA 0x009BEED0. Zero is written after the external call, including if
    // the external call rewrites the pointer field. No complete layout claimed.
    static void ClearFieldE74(void* object,const PlayerPedReferenceClearDependencies& d);

};
} }

// ======================================================================
// ValueAdjustment
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_adjustment {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g00D5A154=0;
inline std::uint32_t g00D819B4=0;
inline std::uint32_t g00DCEA38=0;
inline std::uint32_t g00DECD60=0;
inline std::uint32_t g011DDE7C=0;
inline std::uint32_t g01618104=0;
inline void* call004389D0=nullptr; // exact original stack contract must be supplied
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call00962B20=nullptr; // exact original stack contract must be supplied
__declspec(naked) inline std::uint8_t __fastcall Adjust(void* object, void*, std::uint32_t flag, float value) {
 __asm {
  push ecx
  cmp byte ptr [esp + 8], 0
  movss xmm0, dword ptr [g011DDE7C]
  mulss xmm0, dword ptr [esp + 0Ch]
  mulss xmm0, dword ptr [g00DCEA38]
  push esi
  mov esi, ecx
  movss dword ptr [esp + 4], xmm0
  je L009BFE63
  call dword ptr [call00462F90]
  test al, al
  jne L009BFE5C
  mov eax, dword ptr [esi + 0228h]
  cmp byte ptr [eax + 0546h], 0
  jne L009BFE5C
  test eax, eax
  je L009BFDD4
  add eax, 060h
  jmp L009BFDD6
 L009BFDD4:
  xor eax, eax
 L009BFDD6:
  test byte ptr [eax + 03D0h], 2
  jne L009BFE5C
  movss xmm0, dword ptr [esp + 010h]
  ucomiss xmm0, dword ptr [g00DECD60]
  lahf 
  test ah, 044h
  jnp L009BFE5C
  cmp byte ptr [g01618104], 0
  jne L009BFE5C
  mov ecx, esi
  call dword ptr [call004389D0]
  movss xmm0, dword ptr [eax + 03B4h]
  comiss xmm0, dword ptr [g00D819B4]
  jbe L009BFEC5
  mov ecx, esi
  call dword ptr [call004389D0]
  movss xmm0, dword ptr [eax + 03B4h]
  subss xmm0, dword ptr [esp + 4]
  movss xmm1, dword ptr [g00D819B4]
  comiss xmm1, xmm0
  jbe L009BFE41
  movss dword ptr [esp + 0Ch], xmm1
  jmp L009BFE47
 L009BFE41:
  movss dword ptr [esp + 0Ch], xmm0
 L009BFE47:
  mov ecx, esi
  call dword ptr [call004389D0]
  movss xmm0, dword ptr [esp + 0Ch]
  movss dword ptr [eax + 03B4h], xmm0
 L009BFE5C:
  mov al, 1
  pop esi
  pop ecx
  ret 8
 L009BFE63:
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  push edi
  je L009BFE73
  lea edi, [eax + 060h]
  jmp L009BFE75
 L009BFE73:
  xor edi, edi
 L009BFE75:
  push 7
  call dword ptr [call00962B20]
  fld dword ptr [edi + 03B4h]
  fxch st(1)
  add esp, 4
  fcomip st, st(1)
  fstp st(0)
  pop edi
  jbe L009BFEC5
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  je L009BFE9D
  add eax, 060h
  jmp L009BFE9F
 L009BFE9D:
  xor eax, eax
 L009BFE9F:
  movss xmm0, dword ptr [g011DDE7C]
  mulss xmm0, dword ptr [esp + 010h]
  mulss xmm0, dword ptr [g00D5A154]
  addss xmm0, dword ptr [eax + 03B4h]
  movss dword ptr [eax + 03B4h], xmm0
 L009BFEC5:
  xor al, al
  pop esi
  pop ecx
  ret 8
 }
}
}

// ======================================================================
// InputSelection
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_input {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g010F8044=0;
inline std::uint32_t g011DDF38=0;
inline void* call004255A0=nullptr; // exact original stack contract must be supplied
inline void* call00426780=nullptr; // exact original stack contract must be supplied
inline void* call00426910=nullptr; // exact original stack contract must be supplied
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call00785EB0=nullptr; // exact original stack contract must be supplied
inline void* call0089E300=nullptr; // exact original stack contract must be supplied
inline void* call008FF470=nullptr; // exact original stack contract must be supplied
inline void* call00924E80=nullptr; // exact original stack contract must be supplied
inline void* call009252D0=nullptr; // exact original stack contract must be supplied
inline void* call00987730=nullptr; // exact original stack contract must be supplied
inline void* call0099C5E0=nullptr; // exact original stack contract must be supplied
inline void* call009A9CF0=nullptr; // exact original stack contract must be supplied
inline void* call009AA330=nullptr; // exact original stack contract must be supplied
inline void* call009AC110=nullptr; // exact original stack contract must be supplied
inline void* call009ADB90=nullptr; // exact original stack contract must be supplied
inline void* call009B3B00=nullptr; // exact original stack contract must be supplied
inline void* call009BE4A0=nullptr; // exact original stack contract must be supplied
inline void* call009BE5D0=nullptr; // exact original stack contract must be supplied
inline void* call009C5D60=nullptr; // exact original stack contract must be supplied
inline std::uint32_t table009BEE44[4]{};
inline std::uint32_t table009BEE54[4]{};
__declspec(naked) inline void __fastcall Select(void* object, void*) {
 __asm {
 // Resolve local code labels; LEA/MOV preserve flags. EAX is caller-saved, overwritten by the first original call.
  lea eax, L009BE993
  mov dword ptr [table009BEE44+0], eax
  lea eax, L009BE96F
  mov dword ptr [table009BEE44+4], eax
  lea eax, L009BE97B
  mov dword ptr [table009BEE44+8], eax
  lea eax, L009BE987
  mov dword ptr [table009BEE44+12], eax
  lea eax, L009BE963
  mov dword ptr [table009BEE54+0], eax
  lea eax, L009BE93F
  mov dword ptr [table009BEE54+4], eax
  lea eax, L009BE94B
  mov dword ptr [table009BEE54+8], eax
  lea eax, L009BE957
  mov dword ptr [table009BEE54+12], eax
  sub esp, 8
  push ebx
  push esi
  mov esi, ecx
  call dword ptr [call009BE5D0]
  test byte ptr [esi + 02A0h], 010h
  mov dword ptr [esp + 0Ch], eax
  jne L009BEDB8
  test dword ptr [esi + 0264h], 080000000h
  jne L009BEDB8
  push ebp
  mov ebp, eax
  test ebp, ebp
  push edi
  je L009BED2F
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  je L009BE818
  lea ecx, [eax + 060h]
  jmp L009BE81A
 L009BE818:
  xor ecx, ecx
 L009BE81A:
  mov edx, dword ptr [g011DDF38]
  cmp dword ptr [ecx + 03C4h], edx
  je L009BED2F
  test eax, eax
  je L009BE835
  add eax, 060h
  jmp L009BE837
 L009BE835:
  xor eax, eax
 L009BE837:
  mov dword ptr [eax + 03C4h], edx
  cmp dword ptr [esi + 0B40h], 0
  je L009BEA80
  test byte ptr [esi + 026Ch], 4
  je L009BEA80
  call dword ptr [call008FF470]
  test eax, eax
  jne L009BED2F
  mov bl, byte ptr [ebp + 0328Dh]
  test bl, bl
  je L009BE882
  lea ecx, [ebp + 02D98h]
  call dword ptr [call00426780]
  test al, al
  mov byte ptr [esp + 013h], 1
  jne L009BE887
 L009BE882:
  mov byte ptr [esp + 013h], 0
 L009BE887:
  test bl, bl
  je L009BE89E
  lea ecx, [ebp + 02DA8h]
  call dword ptr [call00426780]
  test al, al
  je L009BE89E
  mov bl, 1
  jmp L009BE8A0
 L009BE89E:
  xor bl, bl
 L009BE8A0:
  cmp byte ptr [esp + 013h], 0
  jne L009BE925
  cmp byte ptr [ebp + 0328Ch], 0
  je L009BE8F4
  mov edi, dword ptr [esi + 0B40h]
  mov ecx, edi
  call dword ptr [call009BE4A0]
  test al, al
  jne L009BE916
  cmp dword ptr [edi + 01354h], 2
  je L009BE916
  push esi
  mov ecx, edi
  call dword ptr [call009C5D60]
  test al, al
  je L009BE916
  lea ecx, [ebp + 02938h]
  call dword ptr [call00785EB0]
  test al, al
  je L009BE8F4
  mov eax, dword ptr [esi + 0B40h]
  test byte ptr [eax + 0F71h], 1
  je L009BE925
 L009BE8F4:
  test bl, bl
  je L009BE99F
  mov ecx, esi
  call dword ptr [call0089E300]
  add eax, -0Bh
  cmp eax, 3
  ja L009BED2F
  jmp dword ptr [eax*4 + table009BEE44]
 L009BE916:
  lea ecx, [ebp + 02938h]
  call dword ptr [call00426780]
  test al, al
  je L009BE8F4
 L009BE925:
  mov ecx, esi
  call dword ptr [call0089E300]
  add eax, -0Bh
  cmp eax, 3
  ja L009BED2F
  jmp dword ptr [eax*4 + table009BEE54]
 L009BE93F:
  push esi
  push 0
  push 4
  push 3
  jmp L009BED24
 L009BE94B:
  push esi
  push 0
  push 4
  push 4
  jmp L009BED24
 L009BE957:
  push esi
  push 0
  push 4
  push 5
  jmp L009BED24
 L009BE963:
  push esi
  push 0
  push 4
  push 2
  jmp L009BED24
 L009BE96F:
  push esi
  push 0
  push 4
  push 015h
  jmp L009BED24
 L009BE97B:
  push esi
  push 0
  push 4
  push 016h
  jmp L009BED24
 L009BE987:
  push esi
  push 0
  push 4
  push 017h
  jmp L009BED24
 L009BE993:
  push esi
  push 0
  push 4
  push 014h
  jmp L009BED24
 L009BE99F:
  lea ecx, [ebp + 02CF8h]
  call dword ptr [call00426780]
  test al, al
  je L009BE9C1
  cmp dword ptr [esi + 0304h], 0
  jle L009BE9C1
  mov eax, 2
  jmp L009BEA6B
 L009BE9C1:
  lea ecx, [ebp + 02D18h]
  call dword ptr [call00426780]
  test al, al
  je L009BE9E3
  cmp dword ptr [esi + 031Ch], 0
  jle L009BE9E3
  mov eax, 4
  jmp L009BEA6B
 L009BE9E3:
  lea ecx, [ebp + 02D58h]
  call dword ptr [call00426780]
  test al, al
  je L009BEA02
  cmp dword ptr [esi + 034Ch], 0
  jle L009BEA02
  mov eax, 8
  jmp L009BEA6B
 L009BEA02:
  mov ecx, dword ptr [esi + 0B40h]
  cmp dword ptr [ecx + 01350h], 1
  jne L009BED2F
  lea ecx, [ebp + 02D08h]
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  mov edi, dword ptr [esi + 0310h]
  push edi
  call dword ptr [call00924E80]
  add esp, 4
  test eax, eax
  je L009BED2F
  push esi
  push edi
  call dword ptr [call00924E80]
  add esp, 4
  mov ecx, eax
  call dword ptr [call009252D0]
  test al, al
  je L009BED2F
  cmp edi, 016h
  je L009BEA66
  cmp edi, 01Ah
  jne L009BED2F
 L009BEA66:
  mov eax, 3
 L009BEA6B:
  cmp eax, dword ptr [esi + 02C8h]
  je L009BED2F
  push 0
  push 0
  jmp L009BED21
 L009BEA80:
  cmp byte ptr [ebp + 0328Ch], 0
  je L009BEB87
  mov dl, byte ptr [ebp + 0280Eh]
  xor dl, byte ptr [ebp + 0280Ch]
  cmp dl, 07Fh
  jbe L009BEB87
  mov al, byte ptr [ebp + 0271Eh]
  xor al, byte ptr [ebp + 0271Ch]
  cmp al, 07Fh
  jbe L009BEAC5
  cmp dword ptr [esi + 034Ch], 0
  jle L009BEAC5
  mov eax, 8
  jmp L009BED15
 L009BEAC5:
  mov cl, byte ptr [ebp + 0272Eh]
  xor cl, byte ptr [ebp + 0272Ch]
  cmp cl, 07Fh
  jbe L009BEAE9
  cmp dword ptr [esi + 0304h], 0
  jle L009BEAE9
  mov eax, 2
  jmp L009BED15
 L009BEAE9:
  mov dl, byte ptr [ebp + 027EEh]
  xor dl, byte ptr [ebp + 027ECh]
  lea edi, [ebp + 027E8h]
  cmp dl, 07Fh
  jbe L009BEB5C
  cmp dword ptr [esi + 0328h], 0
  jg L009BEB12
  cmp dword ptr [esi + 031Ch], 0
  jle L009BEB5C
 L009BEB12:
  push 040h
  call dword ptr [call004255A0]
  add esp, 4
  mov ecx, edi
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  cmp dword ptr [esi + 0328h], 0
  jle L009BEB52
  mov eax, 5
  cmp eax, dword ptr [esi + 02C8h]
  jne L009BED1D
  cmp dword ptr [esi + 031Ch], 0
  je L009BED15
 L009BEB52:
  mov eax, 4
  jmp L009BED15
 L009BEB5C:
  mov al, byte ptr [ebp + 027FEh]
  xor al, byte ptr [ebp + 027FCh]
  cmp al, 07Fh
  jbe L009BED2F
  cmp dword ptr [esi + 0310h], 0
  jle L009BED2F
  mov eax, 3
  jmp L009BED15
 L009BEB87:
  push 1
  call dword ptr [call009B3B00]
  add esp, 4
  test al, al
  jne L009BED2F
  call dword ptr [call009ADB90]
  test al, al
  jne L009BED2F
  lea ecx, [ebp + 02718h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBC2
  push 0
  push 1
  push 0
  push 1
  jmp L009BED24
 L009BEBC2:
  lea ecx, [ebp + 02728h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBDE
  push 0
  push 1
  push 0
  push 6
  jmp L009BED24
 L009BEBDE:
  lea ecx, [ebp + 02CD8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBF4
  xor eax, eax
  jmp L009BED15
 L009BEBF4:
  lea ecx, [ebp + 02CE8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC16
  cmp dword ptr [esi + 02F8h], 0
  jle L009BEC16
  mov eax, 1
  jmp L009BED15
 L009BEC16:
  lea ecx, [ebp + 02CF8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC38
  cmp dword ptr [esi + 0304h], 0
  jle L009BEC38
  mov eax, 2
  jmp L009BED15
 L009BEC38:
  lea ecx, [ebp + 02D08h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC5A
  cmp dword ptr [esi + 0310h], 0
  jle L009BEC5A
  mov eax, 3
  jmp L009BED15
 L009BEC5A:
  lea ecx, [ebp + 02D18h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC7C
  cmp dword ptr [esi + 031Ch], 0
  jle L009BEC7C
  mov eax, 4
  jmp L009BED15
 L009BEC7C:
  lea ecx, [ebp + 02D28h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC9B
  cmp dword ptr [esi + 0328h], 0
  jle L009BEC9B
  mov eax, 5
  jmp L009BED15
 L009BEC9B:
  lea ecx, [ebp + 02D38h]
  call dword ptr [call00426780]
  test al, al
  je L009BECBA
  cmp dword ptr [esi + 0334h], 0
  jle L009BECBA
  mov eax, 6
  jmp L009BED15
 L009BECBA:
  lea ecx, [ebp + 02D48h]
  call dword ptr [call00426780]
  test al, al
  je L009BECD9
  cmp dword ptr [esi + 0340h], 0
  jle L009BECD9
  mov eax, 7
  jmp L009BED15
 L009BECD9:
  lea ecx, [ebp + 02D58h]
  call dword ptr [call00426780]
  test al, al
  je L009BECF8
  cmp dword ptr [esi + 034Ch], 0
  jle L009BECF8
  mov eax, 8
  jmp L009BED15
 L009BECF8:
  lea ecx, [ebp + 02D68h]
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  cmp dword ptr [esi + 0358h], 0
  jle L009BED2F
  mov eax, 9
 L009BED15:
  cmp eax, dword ptr [esi + 02C8h]
  je L009BED2F
 L009BED1D:
  push 0
  push 1
 L009BED21:
  push eax
  push 0
 L009BED24:
  lea ecx, [esi + 02B0h]
  call dword ptr [call009AA330]
 L009BED2F:
  call dword ptr [call00462F90]
  test al, al
  je L009BEDB6
  lea edi, [esi + 02B0h]
  mov ecx, edi
  call dword ptr [call009A9CF0]
  test eax, eax
  jne L009BEDB6
  test byte ptr [esi + 026Ch], 4
  jne L009BEDB6
  mov eax, dword ptr [esi + 0224h]
  lea ebp, [eax + 02E0h]
  push 0
  push 8
  mov ecx, ebp
  call dword ptr [call00426910]
  test al, al
  jne L009BEDB6
  push 0
  push 013Fh
  mov ecx, ebp
  call dword ptr [call00426910]
  test al, al
  jne L009BEDB6
  push 0
  push -1
  push esi
  mov ecx, edi
  call dword ptr [call009AC110]
  test eax, eax
  je L009BEDB6
  mov eax, dword ptr [edi + 018h]
  fldz 
  push ecx
  fstp dword ptr [esp]
  add eax, 5
  lea ecx, [eax + eax*2]
  mov edx, dword ptr [edi + ecx*4]
  mov eax, dword ptr [esi + 020h]
  push edx
  push 0
  push esi
  add eax, 030h
  push eax
  push 3
  call dword ptr [call00987730]
  add esp, 018h
 L009BEDB6:
  pop edi
  pop ebp
 L009BEDB8:
  cmp dword ptr [g010F8044], 2
  jl L009BEE3E
  mov ecx, dword ptr [esp + 0Ch]
  mov dl, byte ptr [ecx + 0328Dh]
  test dl, dl
  jne L009BEE15
  mov al, byte ptr [ecx + 027FCh]
  mov bl, byte ptr [ecx + 027FEh]
  xor bl, al
  cmp bl, 07Fh
  jbe L009BEE11
  mov bl, byte ptr [ecx + 027FFh]
  xor bl, al
  cmp bl, 07Fh
  ja L009BEE11
  cmp dword ptr [esi + 0B40h], 0
  je L009BEE01
  test byte ptr [esi + 026Ch], 4
  jne L009BEE35
 L009BEE01:
  mov al, byte ptr [ecx + 0280Eh]
  xor al, byte ptr [ecx + 0280Ch]
  cmp al, 07Fh
  jbe L009BEE35
 L009BEE11:
  test dl, dl
  je L009BEE3E
 L009BEE15:
  mov al, byte ptr [ecx + 0321Ch]
  mov dl, byte ptr [ecx + 0321Eh]
  xor dl, al
  cmp dl, 07Fh
  jbe L009BEE3E
  mov cl, byte ptr [ecx + 0321Fh]
  xor cl, al
  cmp cl, 07Fh
  ja L009BEE3E
 L009BEE35:
  push esi
  call dword ptr [call0099C5E0]
  add esp, 4
 L009BEE3E:
  pop esi
  pop ebx
  add esp, 8
  ret 
 }
}
}

// ======================================================================
// StateHelpers
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player state helpers require MSVC x86.
#endif
namespace reiv::game::player_detail {
using StateQueryCallback = float(__cdecl*)(std::uint32_t selector);
struct StateHelperDependencies {
    const volatile std::uint32_t* sourceD50398;
    volatile std::uint32_t* destinationF1D9D8;
    StateQueryCallback query962B20;
};
// Bodies have proved player receivers at original callsites; the original
// defining C++ class is not inferred from proximity. No live hooks are installed.
// Null player-info paths retain original low-memory fault behavior.
// VA 0x009BF070. MOVSS copies the global as bits before the state write.
void ClearState3D8(void* player, const StateHelperDependencies& d);

// VA 0x009BF2D0. Preserve callback output in ST0 and the destination captured
// before the callback. A C++ float temporary can add an unwanted rounding store.
void __fastcall StoreQuery7(void* player, const StateHelperDependencies* dependencies);
// VA 0x009BF310. The FSTP destination is latched; the flag destination is
// reloaded from player+228 after the callback, allowing dependency mutations.
void __fastcall StoreQuery8AndClearFlag(void* player, const StateHelperDependencies* dependencies);
}

// ======================================================================
// ActionRange
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_action_range {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g00FC7EFF=0;
inline std::uint32_t g010C7A08=0;
inline std::uint32_t g010F8044=0;
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call00924E80=nullptr; // exact original stack contract must be supplied
inline void* call009A9EF0=nullptr; // exact original stack contract must be supplied
inline void* call009C1300=nullptr; // exact original stack contract must be supplied
inline void* call00C28820=nullptr; // exact original stack contract must be supplied
std::uint8_t __fastcall Act(void* object, void*, std::uint32_t flag);
}

// ======================================================================
// ActionRequest
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_action_request {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g010F8044=0;
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call00924E80=nullptr; // exact original stack contract must be supplied
inline void* call009A9CF0=nullptr; // exact original stack contract must be supplied
inline void* call009A9EF0=nullptr; // exact original stack contract must be supplied
inline void* call009C1300=nullptr; // exact original stack contract must be supplied
std::uint8_t __fastcall Act(void* object, void*, std::uint32_t flag, std::uint32_t argument);
}

// ======================================================================
// ActionSelection
// ======================================================================
// 0x009C1300 receives the embedded object at CPlayerPed + 0xE7C, not the player.
// The original FS:[0x2C] TLS-vector read is explicitly bound through g0000002C.
// Recursion calls this reconstruction. C28820 must be the canonical no-effect RET.
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_action_selection {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g0000002C=0;
inline std::uint32_t g00D50398=0;
inline std::uint32_t g00D81958=0;
inline std::uint32_t g00DC9290=0;
inline std::uint32_t g00DCB2A8=0;
inline std::uint32_t g00DCE03C=0;
inline std::uint32_t g00DECD60=0;
inline std::uint32_t g00EBDEE4=0;
inline std::uint32_t g00EBE128=0;
inline std::uint32_t g00EBE294=0;
inline std::uint32_t g00F2F869=0;
inline std::uint32_t g00F2F86A=0;
inline std::uint32_t g00F317A8=0;
inline std::uint32_t g00F317AC=0;
inline std::uint32_t g00F317B0=0;
inline std::uint32_t g00F317B4=0;
inline std::uint32_t g011DC4C0=0;
inline std::uint32_t g011DC4C4=0;
inline std::uint32_t g011DC4C8=0;
inline std::uint32_t g011DC4E0=0;
inline std::uint32_t g011DC4E4=0;
inline std::uint32_t g011DC4E8=0;
inline std::uint32_t g01618101=0;
inline std::uint32_t g01618106=0;
inline std::uint32_t g017237B0=0;
inline void* call00441F20=nullptr; // exact original stack contract must be supplied
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call009BF360=nullptr; // exact original stack contract must be supplied
inline void* call009BF390=nullptr; // exact original stack contract must be supplied
inline void* call009BF420=nullptr; // exact original stack contract must be supplied
inline void* call009C03E0=nullptr; // exact original stack contract must be supplied
inline void* call009C0660=nullptr; // exact original stack contract must be supplied
inline void* call009C07A0=nullptr; // exact original stack contract must be supplied
inline void* call009C1300=nullptr; // exact original stack contract must be supplied
inline void* call009E9090=nullptr; // exact original stack contract must be supplied
inline void* call009E9340=nullptr; // exact original stack contract must be supplied
inline void* call00C28820=nullptr; // exact original stack contract must be supplied
inline void* call00D0C8E4=nullptr; // exact original stack contract must be supplied
std::uint32_t __fastcall Select(void* embeddedReceiver, void*, std::uint32_t flags, std::uint32_t rangeBits, std::uint32_t argument, float* output, std::uint32_t last);
}

// ======================================================================
// ReceiverHelpers
// ======================================================================
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Receiver helpers require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_receiver_helpers {
// Player receiver proven; original declaring C++ class remains unknown.
// Complete caller ASM; raw EAX APIs describe bits, not the native semantic return type.
// Shared callback bindings are restricted to sequential isolated fixtures.
inline void* call0089DFB0=nullptr;
inline void* call008A3390=nullptr;
inline void* call00921320=nullptr;
inline void* call00921E00=nullptr;
inline void* call00922020=nullptr;
inline void* call00924E80=nullptr;
std::uint8_t __fastcall TestEitherPredicate(void* player, void*);
std::uint32_t __fastcall SetPairFirstRaw(void* player, void*, std::uint32_t a1, std::uint32_t a2);
std::uint32_t __fastcall SetPairSecondRaw(void* player, void*, std::uint32_t a1, std::uint32_t a2);
std::uint32_t __fastcall GetRelatedRaw(void* player, void*);
std::uint8_t __fastcall TestActionAllowed(void* player, void*, std::uint32_t action, std::uint32_t flag);
}

// ======================================================================
// RelatedFlags
// ======================================================================
namespace reiv::game {
struct PlayerPedRelatedFlagDependencies {
    const void* (*getBlock4389D0)(void* player);
    void* (*enumerateA66B70)(std::uint32_t receiverBits, std::uint32_t index);
    void (*virtualSlot12)(void* player, std::uint32_t argument);
    std::uint32_t base1662178;
    const std::uint8_t* flags16180E0; // Seven original bytes; read after the virtual callback.
};
class PlayerPedRelatedFlags {    static std::uint32_t Read(const void* p, std::uint32_t off);    static void Write(void* p, std::uint32_t off, std::uint32_t x);public:

    // 0x009BF250: complete caller. Player receiver confirmed, original declaring class unknown.
    // Returns opaque EAX bits to preserve every original return path, without native type claims.
    // Dependencies are supplied explicitly; isolated sequential fixtures only.
    static std::uint32_t UpdateRaw(void* player,const PlayerPedRelatedFlagDependencies& deps);

};
}


namespace reiv { namespace game {
// Reconstructed operations on an existing object. No complete layout or ownership.
// Offsets and names describe machine-code behavior, not gameplay semantics.
class CPlayerPed {
    static std::uint32_t Read(const void* object, std::uint32_t offset) {
        std::uint32_t value; std::memcpy(&value, static_cast<const unsigned char*>(object) + offset, 4); return value;
    }
    static void Write(void* object, std::uint32_t offset, std::uint32_t value) {
        std::memcpy(static_cast<unsigned char*>(object) + offset, &value, 4);
    }
public:
    CPlayerPed() = delete;
    // Additional confirmed own callers. ASM bindings are isolated single-thread fixtures.
    static void ClearReferenceE74(void* object, const PlayerPedReferenceClearDependencies& deps) { PlayerPedReferenceClear::ClearFieldE74(object, deps); }
    static std::uint8_t AdjustValueIsolated(void* object, std::uint32_t flag, float value) { return player_adjustment::Adjust(object, nullptr, flag, value); }
    static void SelectInputIsolated(void* object) { player_input::Select(object, nullptr); }
    static std::uint8_t ActInRangeIsolated(void* object, std::uint32_t flag) { return player_action_range::Act(object, nullptr, flag); }
    static std::uint8_t RequestActionIsolated(void* object, std::uint32_t flag, std::uint32_t argument) { return player_action_request::Act(object, nullptr, flag, argument); }
    // Receiver proven as player; convenience APIs do not recover original C++ declarations.
    // Raw returns preserve EAX bits without inventing native semantic return types.
    static std::uint8_t TestEitherPredicate(void* object) { return player_receiver_helpers::TestEitherPredicate(object, nullptr); }
    static std::uint32_t DispatchPairFirstRaw(void* object, std::uint32_t a1, std::uint32_t a2) { return player_receiver_helpers::SetPairFirstRaw(object, nullptr, a1, a2); }
    static std::uint32_t DispatchPairSecondRaw(void* object, std::uint32_t a1, std::uint32_t a2) { return player_receiver_helpers::SetPairSecondRaw(object, nullptr, a1, a2); }
    static std::uint32_t DispatchRelatedRaw(void* object) { return player_receiver_helpers::GetRelatedRaw(object, nullptr); }
    static std::uint8_t TestActionAllowed(void* object, std::uint32_t action, std::uint32_t flag) { return player_receiver_helpers::TestActionAllowed(object, nullptr, action, flag); }
    static std::uint32_t UpdateRelatedFlagsRaw(void* object, const PlayerPedRelatedFlagDependencies& deps) { return PlayerPedRelatedFlags::UpdateRaw(object, deps); }
    // Player-receiver routines; original declaring C++ class is not recovered.
    static void ClearState3D8(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::ClearState3D8(object, deps); }
    static void StoreQuery7(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::StoreQuery7(object, &deps); }
    static void StoreQuery8AndClearFlag(void* object, const player_detail::StateHelperDependencies& deps) { player_detail::StoreQuery8AndClearFlag(object, &deps); }
    // VA 0x009BF660. Complete own caller; external reset methods remain callbacks.
    static void ResetModelState(void* object, std::uint8_t argument, const PlayerPedModelResetDependencies& deps) { PlayerPedModelReset::Reset(object, argument, deps); }
    // VA 0x009C0B00, slot 29. Complete ASM caller, isolated bindings only.
    // Shared player_update globals/callbacks require exclusive fixture ownership.
    static std::uint8_t UpdateIsolated(void* object) { return player_update::Update(object, nullptr); }
    // VA 0x009C1910; constructor body with explicit dependency contracts.
    static void* Construct(void* object, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3, const PlayerPedConstructionDependencies& deps) { return PlayerPedConstruction::Construct(object, a1, a2, a3, deps); }
    static void* ResolveIfPlayerFlags(const void* object, const PlayerPedNonvirtualDependencies& deps) { return PlayerPedNonvirtual::ResolveIfPlayerFlags(object, deps); }
    static void CallBlockIfPlayerFlags(void* object, const PlayerPedNonvirtualDependencies& deps) { PlayerPedNonvirtual::CallBlockIfPlayerFlags(object, deps); }
    static void InitializeRelations(void* object, const PlayerPedInitializationDependencies& deps) { PlayerPedNonvirtual::InitializeRelations(object, deps); }
    static void AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals) { PlayerPedAccumulation::AdvanceFieldEE0(object, globals); }
    static std::uint8_t TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals) { return PlayerPedExtraFields::TestFieldEE4(object, globals); }
    static void ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals) { PlayerPedExtraFields::ResetFieldEEC(object, globals); }
    // These reconstructed bodies require explicitly supplied external dependencies.
    // They do not resolve or install native game hooks automatically.
    static void Destroy(void* object, const PlayerPedDestructionDependencies& deps) { PlayerPedDestruction::Destroy(object, deps); }
    static void* DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& deps) { return PlayerPedDestruction::DestroyDeleting(object, flags, deps); }
    static std::uint32_t ApplyModel(void* object, std::uint32_t model, const PlayerPedControlDependencies& deps) { return PlayerPedControl::ApplyModel(object, model, deps); }
    static void* CreateControl(void* object, std::uint32_t a, std::uint32_t b, std::uint32_t c, std::uint32_t e, std::uint32_t count, const PlayerPedControlDependencies& deps) { return PlayerPedControl::CreateControl(object, a, b, c, e, count, deps); }
    static void UpdateCounter(void* object, const PlayerPedCounterDependencies& deps) { PlayerPedCounter::Update(object, deps); }
    static void UpdateSlot73(void* object, const PlayerPedCounterDependencies& deps) { PlayerPedCounter::UpdateSlot73(object, deps); }
    static void SetProtectedAndFlags(void* object, float value, const player_detail::ProtectedCallbacks& deps) { player_detail::SetProtectedAndFlags(object, &deps, value); }
    static void SetProtectedAndFlagsWithUnused(void* object, float value, std::uint32_t unused, const player_detail::ProtectedCallbacks& deps) { player_detail::SetProtectedAndFlagsWithUnused(object, &deps, value, unused); }
    static void AddProtectedAndFlags(void* object, float value, const player_detail::ProtectedCallbacks& deps) { player_detail::AddProtectedAndFlags(object, &deps, value); }
    static float GetPlayerProtected(void* object, const player_detail::ProtectedCallbacks& deps) { return player_detail::GetPlayerProtected(object, &deps); }
    // VA 0x007BDC00 / slot 48; return-register bits, semantic type unknown.
    static std::uint32_t ReturnZeroSlot48() { return 0; }
    // VA 0x00CFAEE0 / slot 74; original defines AL only.
    static std::uint8_t ReturnOneSlot74() { return 1; }
    // VA 0x009C1C90, virtual slot 75.
    static std::uint32_t GetFieldEBC(const void* object) { return Read(object, 0xEBC); }
    // VA 0x009C1CA0, virtual slot 76.
    static void* GetBlockEC0(void* object) { return static_cast<unsigned char*>(object) + 0xEC0; }
    // VA 0x009C1CB0, virtual slot 77.
    static void* GetBlockED0(void* object) { return static_cast<unsigned char*>(object) + 0xED0; }
    // VA 0x009C1CC0, virtual slot 78.
    static void SetFieldEBC(void* object, std::uint32_t value) { Write(object, 0xEBC, value); }
    // VA 0x009C1D90 / slot 79; x87/SSE-specific implementation.
    static void CopyBlockEC0(void* object, const void* input) { player_detail::CopyBlockEC0(object, input); }
    // VA 0x009C1DD0 / slot 80; x87/SSE-specific implementation.
    static void CopyBlockED0(void* object, const void* input) { player_detail::CopyBlockED0(object, input); }
    // VA 0x009C1CD0, virtual slot 81.
    static void SetFieldEF0(void* object, std::uint32_t value) { Write(object, 0xEF0, value); }
};
} }

namespace reiv { namespace memory_map { namespace type_05a24c6871b3ba9f {
inline constexpr char name[] = "CPlayerPed";
inline constexpr char mangled[] = ".?AVCPlayerPed@@";
inline constexpr char kind[] = "class";
inline constexpr char section[] = ".data";
inline constexpr char status[] = "exe_rtti_with_vtable";
inline constexpr char bases[] = "CPed;CPhysical;CDynamicEntity;CEntity;CVirtualBase";
inline constexpr std::uint32_t type_descriptor_va = 0x00f317bcu;
inline constexpr std::uint32_t type_descriptor_rva = 0x00b317bcu;
inline constexpr bool in_sdk = false;
inline constexpr std::uint32_t locators[] = {0x00ec58acu};
inline constexpr std::uint32_t locators_count = 1u;
inline constexpr std::uint32_t vtables[] = {0x00d819c4u};
inline constexpr std::uint32_t vtables_count = 1u;
} } }
// BEGIN GENERATED PENDING HOOK ADDRESSES
#include "core/PendingHook.h"
namespace reiv { namespace memory_map { namespace type_05a24c6871b3ba9f {
// Destinations from the inventory; names/ABI remain candidates. Never auto-install.
inline constexpr std::uint32_t pending_hook_count = 82u;
inline constexpr PendingHook pending_hook_storage[] = {
    {0x009c2260u, 0x005c2260u, 0x00d819c4u, 0, "FUN_009c2260", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48eb0u, 0x00648eb0u, 0x00d819c4u, 1, "FUN_00a48eb0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48e40u, 0x00648e40u, 0x00d819c4u, 2, "FUN_00a48e40", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089ed00u, 0x0049ed00u, 0x00d819c4u, 3, "FUN_0089ed00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1960u, 0x005e1960u, 0x00d819c4u, 4, "FUN_009e1960", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e9e10u, 0x005e9e10u, 0x00d819c4u, 5, "FUN_009e9e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1ed0u, 0x005e1ed0u, 0x00d819c4u, 6, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0410u, 0x005e0410u, 0x00d819c4u, 7, "FUN_009e0410", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0440u, 0x005e0440u, 0x00d819c4u, 8, "FUN_009e0440", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 9, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 10, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 11, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089e4b0u, 0x0049e4b0u, 0x00d819c4u, 12, "FUN_0089e4b0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447ba0u, 0x00047ba0u, 0x00d819c4u, 13, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c0aa0u, 0x005c0aa0u, 0x00d819c4u, 14, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e69e0u, 0x005e69e0u, 0x00d819c4u, 15, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c520u, 0x0049c520u, 0x00d819c4u, 16, "FUN_0089c520", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c5a0u, 0x0049c5a0u, 0x00d819c4u, 17, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e18a0u, 0x005e18a0u, 0x00d819c4u, 18, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c560u, 0x0049c560u, 0x00d819c4u, 19, "FUN_0089c560", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e05c0u, 0x005e05c0u, 0x00d819c4u, 20, "FUN_009e05c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e04d0u, 0x005e04d0u, 0x00d819c4u, 21, "FUN_009e04d0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0490u, 0x005e0490u, 0x00d819c4u, 22, "FUN_009e0490", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0610u, 0x005e0610u, 0x00d819c4u, 23, "FUN_009e0610", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0660u, 0x005e0660u, 0x00d819c4u, 24, "FUN_009e0660", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0690u, 0x005e0690u, 0x00d819c4u, 25, "FUN_009e0690", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e06c0u, 0x005e06c0u, 0x00d819c4u, 26, "FUN_009e06c0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e0bd0u, 0x005e0bd0u, 0x00d819c4u, 27, "FUN_009e0bd0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00707920u, 0x00307920u, 0x00d819c4u, 28, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c0b00u, 0x005c0b00u, 0x00d819c4u, 29, "FUN_009c0b00", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447970u, 0x00047970u, 0x00d819c4u, 30, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete XOR AL,AL/RET 12 body; three synthetic arguments discarded; low-byte zero checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a8cc0u, 0x004a8cc0u, 0x00d819c4u, 31, "FUN_008a8cc0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089d360u, 0x0049d360u, 0x00d819c4u, 32, "FUN_0089d360", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a3850u, 0x004a3850u, 0x00d819c4u, 33, "FUN_008a3850", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009e1b70u, 0x005e1b70u, 0x00d819c4u, 34, "FUN_009e1b70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a3b30u, 0x004a3b30u, 0x00d819c4u, 35, "FUN_008a3b30", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x005fdcd0u, 0x001fdcd0u, 0x00d819c4u, 36, "FUN_005fdcd0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00550ff0u, 0x00150ff0u, 0x00d819c4u, 37, "FUN_00550ff0", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ExtraStubValidation/evidence/runtime-summary.json; 64 calls; complete RET 4 body; one explicit synthetic stack argument discarded; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a3ec0u, 0x004a3ec0u, 0x00d819c4u, 38, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a5060u, 0x004a5060u, 0x00d819c4u, 39, "FUN_008a5060", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447c10u, 0x00047c10u, 0x00d819c4u, 40, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447c00u, 0x00047c00u, 0x00d819c4u, 41, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a6780u, 0x004a6780u, 0x00d819c4u, 42, "FUN_008a6780", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c100u, 0x0049c100u, 0x00d819c4u, 43, "FUN_0089c100", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008aac30u, 0x004aac30u, 0x00d819c4u, 44, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089f050u, 0x0049f050u, 0x00d819c4u, 45, "FUN_0089f050", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089c200u, 0x0049c200u, 0x00d819c4u, 46, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1e10u, 0x005c1e10u, 0x00d819c4u, 47, "FUN_009c1e10", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x007bdc00u, 0x003bdc00u, 0x00d819c4u, 48, "FUN_007bdc00", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_eax_zero machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d819c4u, 49, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x00549100u, 0x00149100u, 0x00d819c4u, 50, "FUN_00549100", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_only machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a8340u, 0x004a8340u, 0x00d819c4u, 51, "FUN_008a8340", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b90u, 0x00047b90u, 0x00d819c4u, 52, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447b90u, 0x00047b90u, 0x00d819c4u, 53, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x008a3250u, 0x004a3250u, 0x00d819c4u, 54, "FUN_008a3250", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008ac520u, 0x004ac520u, 0x00d819c4u, 55, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b20u, 0x00047b20u, 0x00d819c4u, 56, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/game/evidence/runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; comparison/bit/scalar bodies only; EDX/high return not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x0089efe0u, 0x0049efe0u, 0x00d819c4u, 57, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a15e0u, 0x004a15e0u, 0x00d819c4u, 58, "FUN_008a15e0", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a477f0u, 0x006477f0u, 0x00d819c4u, 59, "unknown_entry", "CPhysical::GetVelocity", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CPhysical.h:46", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1cf0u, 0x005c1cf0u, 0x00d819c4u, 60, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1d20u, 0x005c1d20u, 0x00d819c4u, 61, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1d50u, 0x005c1d50u, 0x00d819c4u, 62, "FUN_009c1d50", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1ce0u, 0x005c1ce0u, 0x00d819c4u, 63, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a49650u, 0x00649650u, 0x00d819c4u, 64, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a7d70u, 0x004a7d70u, 0x00d819c4u, 65, "FUN_008a7d70", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00447b40u, 0x00047b40u, 0x00d819c4u, 66, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/ComplexValidation/game/evidence/scalar-runtime-summary.json; 64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established; comparison/bit/scalar bodies only; EDX/high return not established", AddressOrigin::VirtualSlot, true, false, false},
    {0x00447b50u, 0x00047b50u, 0x00d819c4u, 67, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00a48550u, 0x00648550u, 0x00d819c4u, 68, "FUN_00a48550", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008a9070u, 0x004a9070u, 0x00d819c4u, 69, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x008ac540u, 0x004ac540u, 0x00d819c4u, 70, "FUN_008ac540", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x0089dce0u, 0x0049dce0u, 0x00d819c4u, 71, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009be780u, 0x005be780u, 0x00d819c4u, 72, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009be770u, 0x005be770u, 0x00d819c4u, 73, "FUN_009be770", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x00cfaee0u, 0x008faee0u, 0x00d819c4u, 74, "FUN_00cfaee0", "CBaseModelInfo::GetModelType", "docs/MemoryMap/virtual_slots.csv; sdk_shared_virtual_target contrib/IV SDK/IV-SDK-main/include/CModelInfo.h:39; reversing/GameValidation/evidence/runtime-summary.json; 64 calls of complete return_al_constant machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1c90u, 0x005c1c90u, 0x00d819c4u, 75, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; get_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1ca0u, 0x005c1ca0u, 0x00d819c4u, 76, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; address_offset; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1cb0u, 0x005c1cb0u, 0x00d819c4u, 77, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; address_offset; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1cc0u, 0x005c1cc0u, 0x00d819c4u, 78, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; set_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
    {0x009c1d90u, 0x005c1d90u, 0x00d819c4u, 79, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1dd0u, 0x005c1dd0u, 0x00d819c4u, 80, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ", AddressOrigin::VirtualSlot, false, false, false},
    {0x009c1cd0u, 0x005c1cd0u, 0x00d819c4u, 81, "unknown_entry", "", "docs/MemoryMap/virtual_slots.csv; ; reversing/PendingAnalysis/game/evidence/runtime-summary.json; 64 isolated-storage calls; set_u32; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction", AddressOrigin::VirtualSlot, true, false, false},
};
inline constexpr const PendingHook* pending_hooks = pending_hook_storage;
} } }
// END GENERATED PENDING HOOK ADDRESSES
