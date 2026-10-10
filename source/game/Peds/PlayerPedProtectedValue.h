#pragma once
#include <cstdint>
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
