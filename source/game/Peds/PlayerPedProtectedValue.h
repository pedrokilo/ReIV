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
__declspec(naked) inline void* __fastcall WriteProtected(void* field, const ProtectedCallbacks* callbacks, float value) {
    __asm {
        movss xmm0, dword ptr [esp + 4]
        push esi
        movss dword ptr [esp + 8], xmm0
        mov eax, dword ptr [esp + 8]
        push eax
        mov esi, ecx
        mov ecx, dword ptr [esi]
        push 0
        push ecx
        call dword ptr [edx]
        mov eax, esi
        pop esi
        ret 4
    }
}
// VA 0x00447640: the returned float is callback output, never the handle.
__declspec(naked) inline float __fastcall ReadProtected(void* field, const ProtectedCallbacks* callbacks) {
    __asm {
        push esi
        mov esi, edx
        push ecx
        mov ecx, dword ptr [ecx]
        fldz
        lea eax, [esp]
        fstp dword ptr [esp]
        push eax
        push 0
        push ecx
        call dword ptr [esi + 4]
        fld dword ptr [esp]
        pop ecx
        pop esi
        ret
    }
}
// VA 0x0089E5A0, preserved COMISS unordered and DAZ behavior.
__declspec(naked) inline void __fastcall UpdateValueFlags(void* object, void*, float value) {
    __asm {
        movss xmm1, FlagThreshold50
        movss xmm0, dword ptr [esp + 4]
        comiss xmm1, xmm0
        jbe flag50zero
        mov eax, 1
        jmp flag50done
    flag50zero:
        xor eax, eax
    flag50done:
        movss xmm1, FlagThreshold100
        comiss xmm1, xmm0
        mov byte ptr [ecx + 212h], al
        jbe flag100zero
        mov eax, 1
        jmp flag100done
    flag100zero:
        xor eax, eax
    flag100done:
        xorps xmm1, xmm1
        comiss xmm1, xmm0
        mov byte ptr [ecx + 211h], al
        jb flag0zero
        mov eax, 1
        mov byte ptr [ecx + 210h], al
        movss dword ptr [ecx + 214h], xmm0
        ret 4
    flag0zero:
        xor eax, eax
        mov byte ptr [ecx + 210h], al
        movss dword ptr [ecx + 214h], xmm0
        ret 4
    }
}

// VA 0x009C1CF0 / slot 60 and 0x009C1D20 / slot 61. The second
// argument of slot 61 is discarded, yet its original ABI must clean RET 8.
#define REIV_PLAYER_PROTECTED_SET_BODY(cleanup) \
    __asm { fld dword ptr [esp + 4] } \
    __asm { push esi } \
    __asm { push edi } \
    __asm { mov esi, ecx } \
    __asm { mov edi, edx } \
    __asm { push ecx } \
    __asm { lea ecx, [esi + 0EACh] } \
    __asm { mov edx, edi } \
    __asm { fstp dword ptr [esp] } \
    __asm { call WriteProtected } \
    __asm { fld dword ptr [esp + 12] } \
    __asm { push ecx } \
    __asm { mov ecx, esi } \
    __asm { fstp dword ptr [esp] } \
    __asm { call UpdateValueFlags } \
    __asm { pop edi } \
    __asm { pop esi } \
    __asm { ret cleanup }
__declspec(naked) inline void __fastcall SetProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value) {
    REIV_PLAYER_PROTECTED_SET_BODY(4)
}
__declspec(naked) inline void __fastcall SetProtectedAndFlagsWithUnused(void* object, const ProtectedCallbacks* callbacks, float value, std::uint32_t unused) {
    REIV_PLAYER_PROTECTED_SET_BODY(8)
}
#undef REIV_PLAYER_PROTECTED_SET_BODY

// VA 0x009C1D50 / slot 62. Both original single-precision FST stores occur:
// first overwrites the argument, then FSTP creates the protected setter argument.
__declspec(naked) inline void __fastcall AddProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value) {
    __asm {
        push esi
        mov esi, ecx
        push edi
        push ebx
        mov ebx, edx
        lea edi, [esi + 0EACh]
        mov ecx, edi
        call ReadProtected
        fadd dword ptr [esp + 16]
        push ecx
        mov ecx, edi
        mov edx, ebx
        fst dword ptr [esp + 20]
        fstp dword ptr [esp]
        call WriteProtected
        fld dword ptr [esp + 16]
        push ecx
        mov ecx, esi
        fstp dword ptr [esp]
        call UpdateValueFlags
        pop ebx
        pop edi
        pop esi
        ret 4
    }
}
// VA 0x009C1CE0 / slot 63.
__declspec(naked) inline float __fastcall GetPlayerProtected(void* object, const ProtectedCallbacks* callbacks) {
    __asm {
        add ecx, 0EACh
        jmp ReadProtected
    }
}
}
