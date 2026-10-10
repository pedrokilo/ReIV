#include "game/Peds/PlayerPedProtectedValue.h"
#include <cstdint>

namespace reiv::game::player_detail {
__declspec(naked) void* __fastcall WriteProtected(void* field, const ProtectedCallbacks* callbacks, float value) {
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

__declspec(naked) float __fastcall ReadProtected(void* field, const ProtectedCallbacks* callbacks) {
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

__declspec(naked) void __fastcall UpdateValueFlags(void* object, void*, float value) {
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
__declspec(naked) void __fastcall SetProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value) {
    REIV_PLAYER_PROTECTED_SET_BODY(4)
}

__declspec(naked) void __fastcall SetProtectedAndFlagsWithUnused(void* object, const ProtectedCallbacks* callbacks, float value, std::uint32_t unused) {
    REIV_PLAYER_PROTECTED_SET_BODY(8)
}
#undef REIV_PLAYER_PROTECTED_SET_BODY

__declspec(naked) void __fastcall AddProtectedAndFlags(void* object, const ProtectedCallbacks* callbacks, float value) {
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

__declspec(naked) float __fastcall GetPlayerProtected(void* object, const ProtectedCallbacks* callbacks) {
    __asm {
        add ecx, 0EACh
        jmp ReadProtected
    }
}
}
