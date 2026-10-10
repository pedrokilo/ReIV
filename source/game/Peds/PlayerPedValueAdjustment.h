#pragma once
#include <cstdint>
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
