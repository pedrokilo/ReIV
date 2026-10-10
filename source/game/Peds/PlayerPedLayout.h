#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>

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
