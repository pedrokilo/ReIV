#pragma once
#include <cstdint>
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
