#include "game/Peds/PlayerPedReceiverHelpers.h"
#include <cstdint>

namespace reiv::game::player_receiver_helpers {
__declspec(naked) std::uint8_t __fastcall TestEitherPredicate(void* player, void*) {
 __asm {
  push esi
  mov esi, ecx
  call dword ptr [call008A3390]
  test al, al
  jne L009BE609
  mov ecx, esi
  call dword ptr [call0089DFB0]
  test al, al
  jne L009BE609
  pop esi
  ret 
 L009BE609:
  mov al, 1
  pop esi
  ret 
 }
}

__declspec(naked) std::uint32_t __fastcall SetPairFirstRaw(void* player, void*, std::uint32_t a1, std::uint32_t a2) {
 __asm {
  mov eax, dword ptr [ecx + 0228h]
  test eax, eax
  je L009BEEFF
  add eax, 060h
  jmp L009BEF01
 L009BEEFF:
  xor eax, eax
 L009BEF01:
  mov edx, dword ptr [esp + 8]
  mov ecx, dword ptr [ecx + 020h]
  push 1
  push edx
  mov edx, dword ptr [esp + 0Ch]
  add ecx, 030h
  push edx
  push ecx
  mov ecx, eax
  call dword ptr [call00921E00]
  ret 8
 }
}

__declspec(naked) std::uint32_t __fastcall SetPairSecondRaw(void* player, void*, std::uint32_t a1, std::uint32_t a2) {
 __asm {
  mov eax, dword ptr [ecx + 0228h]
  test eax, eax
  je L009BEF2F
  add eax, 060h
  jmp L009BEF31
 L009BEF2F:
  xor eax, eax
 L009BEF31:
  mov edx, dword ptr [esp + 8]
  mov ecx, dword ptr [ecx + 020h]
  push 1
  push edx
  mov edx, dword ptr [esp + 0Ch]
  add ecx, 030h
  push edx
  push ecx
  mov ecx, eax
  call dword ptr [call00922020]
  ret 8
 }
}

__declspec(naked) std::uint32_t __fastcall GetRelatedRaw(void* player, void*) {
 __asm {
  mov eax, dword ptr [ecx + 0228h]
  test eax, eax
  je L009BEF82
  lea ecx, [eax + 060h]
  jmp dword ptr [call00921320]
 L009BEF82:
  xor ecx, ecx
  jmp dword ptr [call00921320]
 }
}

__declspec(naked) std::uint8_t __fastcall TestActionAllowed(void* player, void*, std::uint32_t action, std::uint32_t flag) {
 __asm {
  push esi
  push edi
  mov edi, dword ptr [esp + 0Ch]
  push edi
  mov esi, ecx
  call dword ptr [call00924E80]
  mov eax, dword ptr [eax + 4]
  lea eax, [eax + eax*2]
  mov eax, dword ptr [esi + eax*4 + 02ECh]
  add esp, 4
  cmp eax, edi
  pop edi
  pop esi
  je L009BE7C3
  test eax, eax
  je L009BE7C3
  cmp byte ptr [esp + 8], 0
  sete al
  ret 8
 L009BE7C3:
  mov al, 1
  ret 8
 }
}
}
