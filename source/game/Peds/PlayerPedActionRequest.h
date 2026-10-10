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
__declspec(naked) inline std::uint8_t __fastcall Act(void* object, void*, std::uint32_t flag, std::uint32_t argument) {
 __asm {
  push ecx
  push esi
  mov esi, ecx
  push edi
  lea edi, [esi + 02B0h]
  mov ecx, edi
  call dword ptr [call009A9CF0]
  test eax, eax
  je L009C2252
  mov eax, dword ptr [eax + 018h]
  push eax
  call dword ptr [call00924E80]
  movss xmm0, dword ptr [eax + 014h]
  add esp, 4
  cmp dword ptr [g010F8044], 2
  movss dword ptr [esp + 8], xmm0
  jne L009C21E1
  call dword ptr [call00462F90]
  test al, al
  je L009C21E1
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  je L009C21E1
  movss xmm0, dword ptr [eax + 05A8h]
  mulss xmm0, dword ptr [esp + 8]
  movss dword ptr [esp + 8], xmm0
 L009C21E1:
  cmp byte ptr [esp + 014h], 0
  fld dword ptr [esp + 8]
  push 0
  push 0
  je L009C2200
  mov ecx, dword ptr [esp + 018h]
  push ecx
  push ecx
  fstp dword ptr [esp]
  push 022E4h
  jmp L009C220E
 L009C2200:
  mov edx, dword ptr [esp + 018h]
  push edx
  push ecx
  fstp dword ptr [esp]
  push 022E8h
 L009C220E:
  lea ecx, [esi + 0E7Ch]
  call dword ptr [call009C1300]
  test eax, eax
  je L009C2252
  push eax
  mov ecx, edi
  call dword ptr [call009A9EF0]
  mov esi, dword ptr [esi + 0228h]
  test esi, esi
  je L009C2241
  lea eax, [esi + 060h]
  pop edi
  mov byte ptr [eax + 0415h], 1
  mov al, 1
  pop esi
  pop ecx
  ret 8
 L009C2241:
  xor eax, eax
  pop edi
  mov byte ptr [eax + 0415h], 1
  mov al, 1
  pop esi
  pop ecx
  ret 8
 L009C2252:
  pop edi
  xor al, al
  pop esi
  pop ecx
  ret 8
 }
}
}
