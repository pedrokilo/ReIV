#pragma once
#include <cstdint>
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
