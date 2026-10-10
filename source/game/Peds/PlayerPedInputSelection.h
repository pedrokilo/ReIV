#pragma once
#include <cstdint>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player operations require MSVC x86 inline assembly.
#endif
namespace reiv::game::player_input {
// Complete own caller transcription. Dependencies and storage are explicit.
// ISOLATED SINGLE-THREAD FIXTURES ONLY; no game-global mapping or installed hook.
inline std::uint32_t g010F8044=0;
inline std::uint32_t g011DDF38=0;
inline void* call004255A0=nullptr; // exact original stack contract must be supplied
inline void* call00426780=nullptr; // exact original stack contract must be supplied
inline void* call00426910=nullptr; // exact original stack contract must be supplied
inline void* call00462F90=nullptr; // exact original stack contract must be supplied
inline void* call00785EB0=nullptr; // exact original stack contract must be supplied
inline void* call0089E300=nullptr; // exact original stack contract must be supplied
inline void* call008FF470=nullptr; // exact original stack contract must be supplied
inline void* call00924E80=nullptr; // exact original stack contract must be supplied
inline void* call009252D0=nullptr; // exact original stack contract must be supplied
inline void* call00987730=nullptr; // exact original stack contract must be supplied
inline void* call0099C5E0=nullptr; // exact original stack contract must be supplied
inline void* call009A9CF0=nullptr; // exact original stack contract must be supplied
inline void* call009AA330=nullptr; // exact original stack contract must be supplied
inline void* call009AC110=nullptr; // exact original stack contract must be supplied
inline void* call009ADB90=nullptr; // exact original stack contract must be supplied
inline void* call009B3B00=nullptr; // exact original stack contract must be supplied
inline void* call009BE4A0=nullptr; // exact original stack contract must be supplied
inline void* call009BE5D0=nullptr; // exact original stack contract must be supplied
inline void* call009C5D60=nullptr; // exact original stack contract must be supplied
inline std::uint32_t table009BEE44[4]{};
inline std::uint32_t table009BEE54[4]{};
__declspec(naked) inline void __fastcall Select(void* object, void*) {
 __asm {
 // Resolve local code labels; LEA/MOV preserve flags. EAX is caller-saved, overwritten by the first original call.
  lea eax, L009BE993
  mov dword ptr [table009BEE44+0], eax
  lea eax, L009BE96F
  mov dword ptr [table009BEE44+4], eax
  lea eax, L009BE97B
  mov dword ptr [table009BEE44+8], eax
  lea eax, L009BE987
  mov dword ptr [table009BEE44+12], eax
  lea eax, L009BE963
  mov dword ptr [table009BEE54+0], eax
  lea eax, L009BE93F
  mov dword ptr [table009BEE54+4], eax
  lea eax, L009BE94B
  mov dword ptr [table009BEE54+8], eax
  lea eax, L009BE957
  mov dword ptr [table009BEE54+12], eax
  sub esp, 8
  push ebx
  push esi
  mov esi, ecx
  call dword ptr [call009BE5D0]
  test byte ptr [esi + 02A0h], 010h
  mov dword ptr [esp + 0Ch], eax
  jne L009BEDB8
  test dword ptr [esi + 0264h], 080000000h
  jne L009BEDB8
  push ebp
  mov ebp, eax
  test ebp, ebp
  push edi
  je L009BED2F
  mov eax, dword ptr [esi + 0228h]
  test eax, eax
  je L009BE818
  lea ecx, [eax + 060h]
  jmp L009BE81A
 L009BE818:
  xor ecx, ecx
 L009BE81A:
  mov edx, dword ptr [g011DDF38]
  cmp dword ptr [ecx + 03C4h], edx
  je L009BED2F
  test eax, eax
  je L009BE835
  add eax, 060h
  jmp L009BE837
 L009BE835:
  xor eax, eax
 L009BE837:
  mov dword ptr [eax + 03C4h], edx
  cmp dword ptr [esi + 0B40h], 0
  je L009BEA80
  test byte ptr [esi + 026Ch], 4
  je L009BEA80
  call dword ptr [call008FF470]
  test eax, eax
  jne L009BED2F
  mov bl, byte ptr [ebp + 0328Dh]
  test bl, bl
  je L009BE882
  lea ecx, [ebp + 02D98h]
  call dword ptr [call00426780]
  test al, al
  mov byte ptr [esp + 013h], 1
  jne L009BE887
 L009BE882:
  mov byte ptr [esp + 013h], 0
 L009BE887:
  test bl, bl
  je L009BE89E
  lea ecx, [ebp + 02DA8h]
  call dword ptr [call00426780]
  test al, al
  je L009BE89E
  mov bl, 1
  jmp L009BE8A0
 L009BE89E:
  xor bl, bl
 L009BE8A0:
  cmp byte ptr [esp + 013h], 0
  jne L009BE925
  cmp byte ptr [ebp + 0328Ch], 0
  je L009BE8F4
  mov edi, dword ptr [esi + 0B40h]
  mov ecx, edi
  call dword ptr [call009BE4A0]
  test al, al
  jne L009BE916
  cmp dword ptr [edi + 01354h], 2
  je L009BE916
  push esi
  mov ecx, edi
  call dword ptr [call009C5D60]
  test al, al
  je L009BE916
  lea ecx, [ebp + 02938h]
  call dword ptr [call00785EB0]
  test al, al
  je L009BE8F4
  mov eax, dword ptr [esi + 0B40h]
  test byte ptr [eax + 0F71h], 1
  je L009BE925
 L009BE8F4:
  test bl, bl
  je L009BE99F
  mov ecx, esi
  call dword ptr [call0089E300]
  add eax, -0Bh
  cmp eax, 3
  ja L009BED2F
  jmp dword ptr [eax*4 + table009BEE44]
 L009BE916:
  lea ecx, [ebp + 02938h]
  call dword ptr [call00426780]
  test al, al
  je L009BE8F4
 L009BE925:
  mov ecx, esi
  call dword ptr [call0089E300]
  add eax, -0Bh
  cmp eax, 3
  ja L009BED2F
  jmp dword ptr [eax*4 + table009BEE54]
 L009BE93F:
  push esi
  push 0
  push 4
  push 3
  jmp L009BED24
 L009BE94B:
  push esi
  push 0
  push 4
  push 4
  jmp L009BED24
 L009BE957:
  push esi
  push 0
  push 4
  push 5
  jmp L009BED24
 L009BE963:
  push esi
  push 0
  push 4
  push 2
  jmp L009BED24
 L009BE96F:
  push esi
  push 0
  push 4
  push 015h
  jmp L009BED24
 L009BE97B:
  push esi
  push 0
  push 4
  push 016h
  jmp L009BED24
 L009BE987:
  push esi
  push 0
  push 4
  push 017h
  jmp L009BED24
 L009BE993:
  push esi
  push 0
  push 4
  push 014h
  jmp L009BED24
 L009BE99F:
  lea ecx, [ebp + 02CF8h]
  call dword ptr [call00426780]
  test al, al
  je L009BE9C1
  cmp dword ptr [esi + 0304h], 0
  jle L009BE9C1
  mov eax, 2
  jmp L009BEA6B
 L009BE9C1:
  lea ecx, [ebp + 02D18h]
  call dword ptr [call00426780]
  test al, al
  je L009BE9E3
  cmp dword ptr [esi + 031Ch], 0
  jle L009BE9E3
  mov eax, 4
  jmp L009BEA6B
 L009BE9E3:
  lea ecx, [ebp + 02D58h]
  call dword ptr [call00426780]
  test al, al
  je L009BEA02
  cmp dword ptr [esi + 034Ch], 0
  jle L009BEA02
  mov eax, 8
  jmp L009BEA6B
 L009BEA02:
  mov ecx, dword ptr [esi + 0B40h]
  cmp dword ptr [ecx + 01350h], 1
  jne L009BED2F
  lea ecx, [ebp + 02D08h]
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  mov edi, dword ptr [esi + 0310h]
  push edi
  call dword ptr [call00924E80]
  add esp, 4
  test eax, eax
  je L009BED2F
  push esi
  push edi
  call dword ptr [call00924E80]
  add esp, 4
  mov ecx, eax
  call dword ptr [call009252D0]
  test al, al
  je L009BED2F
  cmp edi, 016h
  je L009BEA66
  cmp edi, 01Ah
  jne L009BED2F
 L009BEA66:
  mov eax, 3
 L009BEA6B:
  cmp eax, dword ptr [esi + 02C8h]
  je L009BED2F
  push 0
  push 0
  jmp L009BED21
 L009BEA80:
  cmp byte ptr [ebp + 0328Ch], 0
  je L009BEB87
  mov dl, byte ptr [ebp + 0280Eh]
  xor dl, byte ptr [ebp + 0280Ch]
  cmp dl, 07Fh
  jbe L009BEB87
  mov al, byte ptr [ebp + 0271Eh]
  xor al, byte ptr [ebp + 0271Ch]
  cmp al, 07Fh
  jbe L009BEAC5
  cmp dword ptr [esi + 034Ch], 0
  jle L009BEAC5
  mov eax, 8
  jmp L009BED15
 L009BEAC5:
  mov cl, byte ptr [ebp + 0272Eh]
  xor cl, byte ptr [ebp + 0272Ch]
  cmp cl, 07Fh
  jbe L009BEAE9
  cmp dword ptr [esi + 0304h], 0
  jle L009BEAE9
  mov eax, 2
  jmp L009BED15
 L009BEAE9:
  mov dl, byte ptr [ebp + 027EEh]
  xor dl, byte ptr [ebp + 027ECh]
  lea edi, [ebp + 027E8h]
  cmp dl, 07Fh
  jbe L009BEB5C
  cmp dword ptr [esi + 0328h], 0
  jg L009BEB12
  cmp dword ptr [esi + 031Ch], 0
  jle L009BEB5C
 L009BEB12:
  push 040h
  call dword ptr [call004255A0]
  add esp, 4
  mov ecx, edi
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  cmp dword ptr [esi + 0328h], 0
  jle L009BEB52
  mov eax, 5
  cmp eax, dword ptr [esi + 02C8h]
  jne L009BED1D
  cmp dword ptr [esi + 031Ch], 0
  je L009BED15
 L009BEB52:
  mov eax, 4
  jmp L009BED15
 L009BEB5C:
  mov al, byte ptr [ebp + 027FEh]
  xor al, byte ptr [ebp + 027FCh]
  cmp al, 07Fh
  jbe L009BED2F
  cmp dword ptr [esi + 0310h], 0
  jle L009BED2F
  mov eax, 3
  jmp L009BED15
 L009BEB87:
  push 1
  call dword ptr [call009B3B00]
  add esp, 4
  test al, al
  jne L009BED2F
  call dword ptr [call009ADB90]
  test al, al
  jne L009BED2F
  lea ecx, [ebp + 02718h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBC2
  push 0
  push 1
  push 0
  push 1
  jmp L009BED24
 L009BEBC2:
  lea ecx, [ebp + 02728h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBDE
  push 0
  push 1
  push 0
  push 6
  jmp L009BED24
 L009BEBDE:
  lea ecx, [ebp + 02CD8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEBF4
  xor eax, eax
  jmp L009BED15
 L009BEBF4:
  lea ecx, [ebp + 02CE8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC16
  cmp dword ptr [esi + 02F8h], 0
  jle L009BEC16
  mov eax, 1
  jmp L009BED15
 L009BEC16:
  lea ecx, [ebp + 02CF8h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC38
  cmp dword ptr [esi + 0304h], 0
  jle L009BEC38
  mov eax, 2
  jmp L009BED15
 L009BEC38:
  lea ecx, [ebp + 02D08h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC5A
  cmp dword ptr [esi + 0310h], 0
  jle L009BEC5A
  mov eax, 3
  jmp L009BED15
 L009BEC5A:
  lea ecx, [ebp + 02D18h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC7C
  cmp dword ptr [esi + 031Ch], 0
  jle L009BEC7C
  mov eax, 4
  jmp L009BED15
 L009BEC7C:
  lea ecx, [ebp + 02D28h]
  call dword ptr [call00426780]
  test al, al
  je L009BEC9B
  cmp dword ptr [esi + 0328h], 0
  jle L009BEC9B
  mov eax, 5
  jmp L009BED15
 L009BEC9B:
  lea ecx, [ebp + 02D38h]
  call dword ptr [call00426780]
  test al, al
  je L009BECBA
  cmp dword ptr [esi + 0334h], 0
  jle L009BECBA
  mov eax, 6
  jmp L009BED15
 L009BECBA:
  lea ecx, [ebp + 02D48h]
  call dword ptr [call00426780]
  test al, al
  je L009BECD9
  cmp dword ptr [esi + 0340h], 0
  jle L009BECD9
  mov eax, 7
  jmp L009BED15
 L009BECD9:
  lea ecx, [ebp + 02D58h]
  call dword ptr [call00426780]
  test al, al
  je L009BECF8
  cmp dword ptr [esi + 034Ch], 0
  jle L009BECF8
  mov eax, 8
  jmp L009BED15
 L009BECF8:
  lea ecx, [ebp + 02D68h]
  call dword ptr [call00426780]
  test al, al
  je L009BED2F
  cmp dword ptr [esi + 0358h], 0
  jle L009BED2F
  mov eax, 9
 L009BED15:
  cmp eax, dword ptr [esi + 02C8h]
  je L009BED2F
 L009BED1D:
  push 0
  push 1
 L009BED21:
  push eax
  push 0
 L009BED24:
  lea ecx, [esi + 02B0h]
  call dword ptr [call009AA330]
 L009BED2F:
  call dword ptr [call00462F90]
  test al, al
  je L009BEDB6
  lea edi, [esi + 02B0h]
  mov ecx, edi
  call dword ptr [call009A9CF0]
  test eax, eax
  jne L009BEDB6
  test byte ptr [esi + 026Ch], 4
  jne L009BEDB6
  mov eax, dword ptr [esi + 0224h]
  lea ebp, [eax + 02E0h]
  push 0
  push 8
  mov ecx, ebp
  call dword ptr [call00426910]
  test al, al
  jne L009BEDB6
  push 0
  push 013Fh
  mov ecx, ebp
  call dword ptr [call00426910]
  test al, al
  jne L009BEDB6
  push 0
  push -1
  push esi
  mov ecx, edi
  call dword ptr [call009AC110]
  test eax, eax
  je L009BEDB6
  mov eax, dword ptr [edi + 018h]
  fldz 
  push ecx
  fstp dword ptr [esp]
  add eax, 5
  lea ecx, [eax + eax*2]
  mov edx, dword ptr [edi + ecx*4]
  mov eax, dword ptr [esi + 020h]
  push edx
  push 0
  push esi
  add eax, 030h
  push eax
  push 3
  call dword ptr [call00987730]
  add esp, 018h
 L009BEDB6:
  pop edi
  pop ebp
 L009BEDB8:
  cmp dword ptr [g010F8044], 2
  jl L009BEE3E
  mov ecx, dword ptr [esp + 0Ch]
  mov dl, byte ptr [ecx + 0328Dh]
  test dl, dl
  jne L009BEE15
  mov al, byte ptr [ecx + 027FCh]
  mov bl, byte ptr [ecx + 027FEh]
  xor bl, al
  cmp bl, 07Fh
  jbe L009BEE11
  mov bl, byte ptr [ecx + 027FFh]
  xor bl, al
  cmp bl, 07Fh
  ja L009BEE11
  cmp dword ptr [esi + 0B40h], 0
  je L009BEE01
  test byte ptr [esi + 026Ch], 4
  jne L009BEE35
 L009BEE01:
  mov al, byte ptr [ecx + 0280Eh]
  xor al, byte ptr [ecx + 0280Ch]
  cmp al, 07Fh
  jbe L009BEE35
 L009BEE11:
  test dl, dl
  je L009BEE3E
 L009BEE15:
  mov al, byte ptr [ecx + 0321Ch]
  mov dl, byte ptr [ecx + 0321Eh]
  xor dl, al
  cmp dl, 07Fh
  jbe L009BEE3E
  mov cl, byte ptr [ecx + 0321Fh]
  xor cl, al
  cmp cl, 07Fh
  ja L009BEE3E
 L009BEE35:
  push esi
  call dword ptr [call0099C5E0]
  add esp, 4
 L009BEE3E:
  pop esi
  pop ebx
  add esp, 8
  ret 
 }
}
}
