#pragma once
// 0x009C1300 receives the embedded object at CPlayerPed + 0xE7C, not the player.
// The original FS:[0x2C] TLS-vector read is explicitly bound through g0000002C.
// Recursion calls this reconstruction. C28820 must be the canonical no-effect RET.
#include <cstdint>
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
