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
__declspec(naked) inline std::uint32_t __fastcall Select(void* embeddedReceiver, void*, std::uint32_t flags, std::uint32_t rangeBits, std::uint32_t argument, float* output, std::uint32_t last) {
 __asm {
  push ebp
  mov ebp, esp
  and esp, 0FFFFFFF0h
  sub esp, 0A4h
  xorps xmm0, xmm0
  mov al, byte ptr [g00F2F869]
  test al, al
  push ebx
  mov ebx, dword ptr [ebp + 8]
  push esi
  push edi
  mov edi, ecx
  mov dword ptr [esp + 018h], 0
  movss dword ptr [esp + 028h], xmm0
  movss dword ptr [esp + 02Ch], xmm0
  movss dword ptr [esp + 020h], xmm0
  jne L009C133D
  and ebx, 0FFFFFFFDh
 L009C133D:
  mov ecx, dword ptr [edi]
  cmp dword ptr [ecx + 0D78h], 0
  mov cl, byte ptr [g01618106]
  jne L009C1352
  test cl, cl
  jne L009C1355
 L009C1352:
  and ebx, 0FFFFFFFEh
 L009C1355:
  test al, al
  jne L009C1360
  test cl, cl
  jne L009C1360
  or ebx, 010h
 L009C1360:
  cmp byte ptr [g00F2F86A], 0
  jne L009C136F
  and ebx, 0FFFFFEFFh
 L009C136F:
  xor eax, eax
  test bl, 020h
  je L009C137B
  mov eax, 1
 L009C137B:
  test bl, 040h
  je L009C1383
  or eax, 2
 L009C1383:
  test bl, bl
  jns L009C138A
  or eax, 4
 L009C138A:
  test ebx, 0100h
  je L009C1395
  or eax, 040h
 L009C1395:
  fld dword ptr [g00EBE294]
  mov edx, dword ptr [ebp + 010h]
  push ecx
  fstp dword ptr [esp]
  push 0
  push edx
  push eax
  lea ecx, [esp + 090h]
  call dword ptr [call009E9090]
  lea ecx, [esp + 080h]
  call dword ptr [call009E9340]
  movss xmm1, dword ptr [g00F317A8]
  movss xmm0, dword ptr [g00EBE128]
  mov esi, eax
  mov eax, ebx
  and eax, 4
  mulss xmm1, xmm0
  movss dword ptr [esp + 01Ch], xmm1
  mov dword ptr [esp + 038h], eax
  jne L009C13EA
  test bl, 8
  je L009C13FC
 L009C13EA:
  movss xmm1, dword ptr [g00F317AC]
  mulss xmm1, xmm0
  movss dword ptr [esp + 01Ch], xmm1
 L009C13FC:
  mov eax, ebx
  and eax, 010h
  mov dword ptr [esp + 058h], eax
  je L009C1415
  movss xmm0, dword ptr [g00EBDEE4]
  movss dword ptr [esp + 01Ch], xmm0
 L009C1415:
  test esi, esi
  je L009C17F6
 L009C141D:
  mov eax, dword ptr [ebp + 018h]
  fld dword ptr [ebp + 0Ch]
  push eax
  lea ecx, [esp + 017h]
  push ecx
  push ecx
  fstp dword ptr [esp]
  push esi
  push ebx
  mov ecx, edi
  mov byte ptr [esp + 027h], 0
  call dword ptr [call009C03E0]
  test al, al
  jne L009C1449
  cmp byte ptr [esp + 013h], al
  je L009C17E0
 L009C1449:
  test bl, 1
  xorps xmm0, xmm0
  movss dword ptr [esp + 014h], xmm0
  movss xmm0, dword ptr [g00D50398]
  movss dword ptr [esp + 030h], xmm0
  movss dword ptr [esp + 024h], xmm0
  movss xmm0, dword ptr [g00D81958]
  movss dword ptr [esp + 03Ch], xmm0
  je L009C14D6
  mov edx, dword ptr [edi]
  fld dword ptr [esp + 01Ch]
  mov eax, dword ptr [edx + 020h]
  movss xmm0, dword ptr [eax + 010h]
  push ebx
  push 0
  movss dword ptr [esp + 078h], xmm0
  movss xmm0, dword ptr [eax + 014h]
  push ecx
  movss dword ptr [esp + 080h], xmm0
  fstp dword ptr [esp]
  movss xmm0, dword ptr [eax + 018h]
  add eax, 030h
  push eax
  lea eax, [esp + 080h]
  push eax
  push esi
  mov ecx, edi
  movss dword ptr [esp + 090h], xmm0
  call dword ptr [call009C07A0]
  fstp dword ptr [esp + 014h]
  movss xmm0, dword ptr [g00D50398]
  movss dword ptr [esp + 03Ch], xmm0
 L009C14D6:
  test bl, 2
  je L009C153F
  mov ecx, dword ptr [edi]
  fld dword ptr [esp + 01Ch]
  mov eax, dword ptr [ecx + 020h]
  movss xmm0, dword ptr [g011DC4C0]
  push ebx
  push 0
  push ecx
  fstp dword ptr [esp]
  add eax, 030h
  push eax
  movss dword ptr [esp + 070h], xmm0
  movss xmm0, dword ptr [g011DC4C4]
  lea edx, [esp + 070h]
  push edx
  movss dword ptr [esp + 078h], xmm0
  movss xmm0, dword ptr [g011DC4C8]
  push esi
  mov ecx, edi
  movss dword ptr [esp + 080h], xmm0
  call dword ptr [call009C07A0]
  fadd dword ptr [esp + 014h]
  movss xmm0, dword ptr [esp + 03Ch]
  mulss xmm0, dword ptr [g00DCE03C]
  fstp dword ptr [esp + 014h]
 L009C153F:
  cmp dword ptr [esp + 038h], 0
  mulss xmm0, dword ptr [esp + 014h]
  movss dword ptr [esp + 014h], xmm0
  jne L009C155B
  test bl, 8
  je L009C167C
 L009C155B:
  movss xmm0, dword ptr [g011DC4C0]
  mov ecx, dword ptr [ebp + 010h]
  test ecx, ecx
  movss dword ptr [esp + 040h], xmm0
  movss xmm0, dword ptr [g011DC4C4]
  movss dword ptr [esp + 044h], xmm0
  movss xmm0, dword ptr [g011DC4C8]
  movss dword ptr [esp + 048h], xmm0
  je L009C1626
  call dword ptr [call00441F20]
  movss xmm0, dword ptr [eax + 4]
  movss xmm1, dword ptr [eax + 8]
  movss xmm2, dword ptr [esp + 06Ch]
  subss xmm0, dword ptr [g011DC4E4]
  subss xmm1, dword ptr [g011DC4E8]
  movss xmm3, dword ptr [eax]
  subss xmm3, dword ptr [g011DC4E0]
  movss dword ptr [esp + 04Ch], xmm2
  movaps xmm2, xmm0
  mulss xmm2, xmm0
  movaps xmm4, xmm1
  mulss xmm4, xmm1
  addss xmm2, xmm4
  movaps xmm4, xmm3
  mulss xmm4, xmm3
  addss xmm2, xmm4
  xorps xmm4, xmm4
  ucomiss xmm2, xmm4
  lahf 
  test ah, 044h
  jp L009C15F5
  movaps xmm2, xmm4
  jmp L009C1605
 L009C15F5:
  sqrtss xmm4, xmm2
  movss xmm2, dword ptr [g00D50398]
  divss xmm2, xmm4
 L009C1605:
  movaps xmm4, xmm2
  mulss xmm4, xmm3
  mulss xmm0, xmm2
  mulss xmm1, xmm2
  movss dword ptr [esp + 040h], xmm4
  movss dword ptr [esp + 044h], xmm0
  movss dword ptr [esp + 048h], xmm1
 L009C1626:
  cmp dword ptr [esp + 038h], 0
  je L009C1652
  fld dword ptr [esp + 01Ch]
  push ebx
  push 1
  push ecx
  fstp dword ptr [esp]
  push 011DC4E0h
  lea eax, [esp + 050h]
  push eax
  push esi
  mov ecx, edi
  call dword ptr [call009C07A0]
  fadd dword ptr [esp + 014h]
  fstp dword ptr [esp + 014h]
 L009C1652:
  test bl, 8
  je L009C167C
  fld dword ptr [esp + 01Ch]
  push ebx
  push 2
  push ecx
  fstp dword ptr [esp]
  push 011DC4E0h
  lea ecx, [esp + 050h]
  push ecx
  push esi
  mov ecx, edi
  call dword ptr [call009C07A0]
  fadd dword ptr [esp + 014h]
  fstp dword ptr [esp + 014h]
 L009C167C:
  movss xmm0, dword ptr [esp + 014h]
  ucomiss xmm0, dword ptr [g00DECD60]
  lahf 
  test ah, 044h
  jp L009C169A
  cmp dword ptr [esp + 058h], 0
  je L009C17E0
 L009C169A:
  test ebx, 0400h
  je L009C16B4
  push esi
  mov ecx, edi
  call dword ptr [call009BF390]
  fmul dword ptr [g00F317B4]
  fstp dword ptr [esp + 030h]
 L009C16B4:
  push esi
  mov ecx, edi
  call dword ptr [call009BF420]
  fmul dword ptr [g00F317B0]
  test ebx, 0200h
  fstp dword ptr [esp + 05Ch]
  je L009C16DA
  movss xmm0, dword ptr [esp + 05Ch]
  movss dword ptr [esp + 024h], xmm0
 L009C16DA:
  cmp byte ptr [g01618101], 0
  movss xmm0, dword ptr [esp + 030h]
  mulss xmm0, dword ptr [esp + 014h]
  addss xmm0, dword ptr [esp + 024h]
  movss dword ptr [esp + 034h], xmm0
  je L009C176C
  mov edx, ebx
  shr edx, 0Eh
  and edx, 0FFFFFF01h
  push edx
  push 0
  push esi
  mov ecx, edi
  call dword ptr [call009C0660]
  cvtss2sd xmm0, dword ptr [esp + 024h]
  mov eax, dword ptr [g0000002C]
  mov ecx, dword ptr [g017237B0]
  mov edx, dword ptr [eax + ecx*4]
  sub esp, 020h
  movsd qword ptr [esp + 018h], xmm0
  cvtss2sd xmm0, dword ptr [esp + 050h]
  movsd qword ptr [esp + 010h], xmm0
  cvtss2sd xmm0, dword ptr [esp + 034h]
  movsd qword ptr [esp + 8], xmm0
  cvtss2sd xmm0, dword ptr [esp + 054h]
  movsd qword ptr [esp], xmm0
  add edx, 04D0h
  push 0D81968h
  push edx
  call dword ptr [call00D0C8E4]
  movss xmm0, dword ptr [esp + 05Ch]
  add esp, 028h
 L009C176C:
  cmp dword ptr [esp + 018h], 0
  je L009C1783
  movss xmm1, dword ptr [esp + 028h]
  comiss xmm0, xmm1
  jbe L009C17E0
  comiss xmm0, xmm1
  jbe L009C17E0
 L009C1783:
  cmp byte ptr [esp + 013h], 0
  jne L009C17CD
  push esi
  mov ecx, edi
  call dword ptr [call009BF360]
  test al, al
  je L009C17B5
  mov eax, ebx
  shr eax, 0Eh
  and eax, 0FFFFFF01h
  push eax
  push 0
  push esi
  mov ecx, edi
  call dword ptr [call009C0660]
  test al, al
  jne L009C17CD
  movss xmm0, dword ptr [esp + 034h]
 L009C17B5:
  movss dword ptr [esp + 028h], xmm0
  movss xmm0, dword ptr [esp + 024h]
  mov dword ptr [esp + 018h], esi
  movss dword ptr [esp + 02Ch], xmm0
  jmp L009C17E0
 L009C17CD:
  movss xmm0, dword ptr [esp + 024h]
  comiss xmm0, dword ptr [esp + 020h]
  jbe L009C17E0
  movss dword ptr [esp + 020h], xmm0
 L009C17E0:
  lea ecx, [esp + 080h]
  call dword ptr [call009E9340]
  mov esi, eax
  test esi, esi
  jne L009C141D
 L009C17F6:
  mov eax, dword ptr [ebp + 014h]
  test eax, eax
  movss xmm1, dword ptr [esp + 02Ch]
  je L009C1807
  movss dword ptr [eax], xmm1
 L009C1807:
  movss xmm2, dword ptr [g00DC9290]
  movaps xmm0, xmm1
  divss xmm0, dword ptr [g00F317B0]
  comiss xmm2, xmm0
  jb L009C18F2
  test eax, eax
  jne L009C18F2
  movss xmm0, dword ptr [esp + 020h]
  comiss xmm0, xmm1
  mov byte ptr [esp + 013h], al
  jbe L009C1894
  test ebx, 04000h
  jne L009C1894
  mov edx, dword ptr [ebp + 010h]
  fld dword ptr [ebp + 0Ch]
  xorps xmm0, xmm0
  push eax
  lea ecx, [esp + 02Ch]
  push ecx
  push edx
  push ecx
  fstp dword ptr [esp]
  or ebx, 04000h
  push ebx
  mov ecx, edi
  movss dword ptr [esp + 03Ch], xmm0
  call Select
  test eax, eax
  je L009C188E
  movss xmm0, dword ptr [esp + 028h]
  divss xmm0, dword ptr [g00F317B0]
  comiss xmm0, dword ptr [g00DC9290]
  jbe L009C188E
  mov byte ptr [esp + 013h], 1
  mov esi, eax
  jmp L009C18B1
 L009C188E:
  movss xmm0, dword ptr [esp + 020h]
 L009C1894:
  divss xmm0, dword ptr [g00F317B0]
  comiss xmm0, dword ptr [g00DCB2A8]
  jbe L009C18AD
  mov dword ptr [esp + 018h], 0
 L009C18AD:
  mov esi, dword ptr [esp + 018h]
 L009C18B1:
  call dword ptr [call00462F90]
  test al, al
  je L009C18F6
  cmp byte ptr [esp + 013h], 0
  jne L009C18F6
  mov eax, dword ptr [edi]
  test byte ptr [eax + 0267h], 1
  jne L009C18F6
  test esi, esi
  je L009C18EA
  mov ecx, dword ptr [esi + 028h]
  and ecx, 03C0h
  cmp ecx, 0C0h
  jne L009C18EA
  cmp byte ptr [esi + 0A70h], 2
  je L009C18F6
 L009C18EA:
  mov dword ptr [esp + 018h], 0
 L009C18F2:
  mov esi, dword ptr [esp + 018h]
 L009C18F6:
  lea ecx, [esp + 080h]
  call dword ptr [call00C28820]
  pop edi
  mov eax, esi
  pop esi
  pop ebx
  mov esp, ebp
  pop ebp
  ret 014h
 }
}
}
