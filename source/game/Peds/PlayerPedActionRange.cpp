#include "game/Peds/PlayerPedActionRange.h"
#include <cstdint>

namespace reiv::game::player_action_range {
__declspec(naked) std::uint8_t __fastcall Act(void* object, void*, std::uint32_t flag) {
 __asm {
  sub esp, 010h
  push ebx
  push ebp
  push esi
  mov esi, ecx
  mov eax, dword ptr [esi + 02C8h]
  lea ecx, [esi + 02B0h]
  add eax, 5
  lea eax, [eax + eax*2]
  mov eax, dword ptr [ecx + eax*4]
  push edi
  push eax
  mov dword ptr [esp + 018h], ecx
  call dword ptr [call00924E80]
  mov ebp, eax
  movss xmm0, dword ptr [ebp + 014h]
  add esp, 4
  cmp dword ptr [g010F8044], 2
  movss dword ptr [esp + 010h], xmm0
  jne L009C1FF8
  call dword ptr [call00462F90]
  test al, al
  je L009C1FF8
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  je L009C1FF8
  movss xmm0, dword ptr [eax + 05A8h]
  mulss xmm0, dword ptr [esp + 010h]
  movss dword ptr [esp + 010h], xmm0
 L009C1FF8:
  cmp byte ptr [esp + 024h], 0
  mov ebx, 026E3h
  je L009C2009
  mov ebx, 022E3h
 L009C2009:
  mov edi, dword ptr [esi + 03A8h]
  test edi, edi
  je L009C2109
  mov ecx, dword ptr [esi + 0E7Ch]
  test dword ptr [ecx + 0264h], 0800000h
  jne L009C2044
  cmp dword ptr [g010C7A08], 0
  je L009C2044
  call dword ptr [call00462F90]
  test al, al
  je L009C2072
  cmp byte ptr [g00FC7EFF], 0
  jne L009C2072
 L009C2044:
  test ebx, 01000h
  jne L009C2072
  mov edx, dword ptr [edi + 028h]
  and edx, 03C0h
  cmp edx, 0C0h
  jne L009C2109
  mov eax, dword ptr [edi + 0270h]
  shr eax, 4
  test al, 1
  je L009C2109
 L009C2072:
  mov eax, dword ptr [esi + 03A8h]
  mov ecx, dword ptr [eax + 020h]
  test ecx, ecx
  lea edx, [ecx + 030h]
  jne L009C2085
  lea edx, [eax + 010h]
 L009C2085:
  movss xmm0, dword ptr [edx]
  mov ecx, dword ptr [esi + 020h]
  mov edx, dword ptr [eax + 020h]
  test edx, edx
  subss xmm0, dword ptr [ecx + 030h]
  movss dword ptr [esp + 018h], xmm0
  je L009C20A3
  add edx, 030h
  jmp L009C20A6
 L009C20A3:
  lea edx, [eax + 010h]
 L009C20A6:
  movss xmm0, dword ptr [edx + 4]
  subss xmm0, dword ptr [ecx + 034h]
  lea ecx, [esp + 010h]
  push ecx
  push esi
  push eax
  movss dword ptr [esp + 028h], xmm0
  call dword ptr [call00C28820]
  movss xmm0, dword ptr [esp + 028h]
  movaps xmm1, xmm0
  mulss xmm1, xmm0
  movss xmm0, dword ptr [esp + 024h]
  movaps xmm2, xmm0
  mulss xmm2, xmm0
  addss xmm1, xmm2
  sqrtss xmm0, xmm1
  movss xmm1, dword ptr [esp + 01Ch]
  add esp, 0Ch
  comiss xmm1, xmm0
  jae L009C2167
  mov ecx, dword ptr [esp + 014h]
  push 0
  call dword ptr [call009A9EF0]
 L009C20FD:
  pop edi
  pop esi
  pop ebp
  xor al, al
  pop ebx
  add esp, 010h
  ret 4
 L009C2109:
  cmp dword ptr [ebp + 0Ch], 1
  fld dword ptr [esp + 010h]
  push 0
  push 0
  push 0
  push ecx
  fstp dword ptr [esp]
  lea ecx, [esi + 0E7Ch]
  jne L009C212A
  push 036F3h
  jmp L009C212B
 L009C212A:
  push ebx
 L009C212B:
  call dword ptr [call009C1300]
  test eax, eax
  je L009C20FD
  mov ecx, dword ptr [esp + 014h]
  push eax
  call dword ptr [call009A9EF0]
  mov esi, dword ptr [esi + 0228h]
  test esi, esi
  je L009C215E
  pop edi
  lea eax, [esi + 060h]
  pop esi
  pop ebp
  mov byte ptr [eax + 0415h], 1
  mov al, 1
  pop ebx
  add esp, 010h
  ret 4
 L009C215E:
  xor eax, eax
  mov byte ptr [eax + 0415h], 1
 L009C2167:
  pop edi
  pop esi
  pop ebp
  mov al, 1
  pop ebx
  add esp, 010h
  ret 4
 }
}
}
