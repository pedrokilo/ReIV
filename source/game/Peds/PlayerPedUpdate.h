#pragma once
#include <cstdint>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player update transcription requires MSVC x86.
#endif
namespace reiv::game::player_update {
// Complete caller transcription, with external functions and globals explicit.
// ISOLATED FIXTURES ONLY: shared mutable storage is not thread-safe or a game binding.
// No live-game replacement is installed. Raw callback pointers retain original ABI.
inline std::uint32_t g00D50398=0; // original storage VA 0x00D50398, exact operand widths below
inline std::uint32_t g00D582A0=0; // original storage VA 0x00D582A0, exact operand widths below
inline std::uint32_t g00D796E4=0; // original storage VA 0x00D796E4, exact operand widths below
inline std::uint32_t g00D81944=0; // original storage VA 0x00D81944, exact operand widths below
inline std::uint32_t g00D81958=0; // original storage VA 0x00D81958, exact operand widths below
inline std::uint32_t g00D819B8=0; // original storage VA 0x00D819B8, exact operand widths below
inline std::uint32_t g00D8F340=0; // original storage VA 0x00D8F340, exact operand widths below
inline std::uint32_t g00DC9290=0; // original storage VA 0x00DC9290, exact operand widths below
inline std::uint32_t g00DCB2AC=0; // original storage VA 0x00DCB2AC, exact operand widths below
inline std::uint32_t g00E3447C=0; // original storage VA 0x00E3447C, exact operand widths below
inline std::uint32_t g00EBDED4=0; // original storage VA 0x00EBDED4, exact operand widths below
inline std::uint32_t g00F0E4A0=0; // original storage VA 0x00F0E4A0, exact operand widths below
inline std::uint32_t g00F21A70=0; // original storage VA 0x00F21A70, exact operand widths below
inline std::uint32_t g00F317B8=0; // original storage VA 0x00F317B8, exact operand widths below
inline std::uint32_t g010D0170=0; // original storage VA 0x010D0170, exact operand widths below
inline std::uint32_t g010E1984=0; // original storage VA 0x010E1984, exact operand widths below
inline std::uint32_t g011DDE74=0; // original storage VA 0x011DDE74, exact operand widths below
inline std::uint32_t g011DDE7C=0; // original storage VA 0x011DDE7C, exact operand widths below
inline std::uint32_t g011DDF38=0; // original storage VA 0x011DDF38, exact operand widths below
inline std::uint32_t g01618020=0; // original storage VA 0x01618020, exact operand widths below
inline std::uint32_t g016180E8=0; // original storage VA 0x016180E8, exact operand widths below
inline std::uint32_t g016180EC=0; // original storage VA 0x016180EC, exact operand widths below
inline std::uint32_t g016180F0=0; // original storage VA 0x016180F0, exact operand widths below
inline std::uint32_t g016180F4=0; // original storage VA 0x016180F4, exact operand widths below
inline std::uint32_t g016180F8=0; // original storage VA 0x016180F8, exact operand widths below
inline std::uint32_t g0161810C=0; // original storage VA 0x0161810C, exact operand widths below
inline std::uint32_t g01618110=0; // original storage VA 0x01618110, exact operand widths below
inline std::uint32_t g01724286=0; // original storage VA 0x01724286, exact operand widths below
inline unsigned char object0168F910[16]{}; // opaque context identity, dependency owns layout
inline void* call00401950=nullptr;
inline void* call004269B0=nullptr;
inline void* call004389D0=nullptr;
inline void* call00462F90=nullptr;
inline void* call0088F5D0=nullptr;
inline void* call0089EA80=nullptr;
inline void* call008AADC0=nullptr;
inline void* call008AE670=nullptr;
inline void* call0091A050=nullptr;
inline void* call0091A0A0=nullptr;
inline void* call00922850=nullptr;
inline void* call00924E80=nullptr;
inline void* call00976E90=nullptr;
inline void* call0097D7C0=nullptr;
inline void* call00987730=nullptr;
inline void* call009A9CF0=nullptr;
inline void* call009BE5D0=nullptr;
inline void* call009BE7D0=nullptr;
inline void* call009BEE70=nullptr;
inline void* call009BEED0=nullptr;
inline void* call009BFD80=nullptr;
inline void* call009E6630=nullptr;
inline void* call00AA80D0=nullptr;
inline void* call00AA83F0=nullptr;
inline void* call00AB3B60=nullptr;
inline void* call00AFE160=nullptr;
inline void* call00AFEA00=nullptr;
// All dependencies must be bound before use; original caller uses AL return.
__declspec(naked) inline std::uint8_t __fastcall Update(void* object, void*) {
    __asm {
        push ebp
        mov ebp, esp
        and esp, 0FFFFFFF0h
        sub esp, 034h
        push ebx
        push esi
        mov esi, ecx
        xor ebx, ebx
        cmp byte ptr [esi + 0218h], bl
        push edi
        mov edx, 1
        je L009C0B29
        cmp byte ptr [esi + 0219h], bl
        jne L009C12F0
    L009C0B29:
        cmp dword ptr [g010D0170], edx
        je L009C12F0
        mov eax, dword ptr [g010E1984]
        cmp eax, dword ptr [g00E3447C]
        jne L009C12F0
        cmp dword ptr [g00F0E4A0], 012h
        je L009C12F0
        mov eax, dword ptr [esi + 0228h]
        or dword ptr [esi + 028h], 010000000h
        cmp eax, ebx
        mov byte ptr [esi + 0E71h], bl
        je L009C0B6F
        lea ecx, [eax + 060h]
        jmp L009C0B71
    L009C0B6F:
        xor ecx, ecx
    L009C0B71:
        cmp byte ptr [ecx + 03BCh], bl
        jbe L009C0B8B
        cmp eax, ebx
        je L009C0B82
        add eax, 060h
        jmp L009C0B84
    L009C0B82:
        xor eax, eax
    L009C0B84:
        add byte ptr [eax + 03BCh], 0FFh
    L009C0B8B:
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0B9A
        lea ecx, [eax + 060h]
        jmp L009C0B9C
    L009C0B9A:
        xor ecx, ecx
    L009C0B9C:
        cmp byte ptr [ecx + 03BCh], bl
        jne L009C0BB5
        cmp eax, ebx
        je L009C0BAD
        add eax, 060h
        jmp L009C0BAF
    L009C0BAD:
        xor eax, eax
    L009C0BAF:
        mov dword ptr [eax + 03CCh], ebx
    L009C0BB5:
        cmp byte ptr [esi + 0219h], bl
        je L009C0BFE
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0BCC
        add eax, 060h
        jmp L009C0BCE
    L009C0BCC:
        xor eax, eax
    L009C0BCE:
        mov byte ptr [eax + 0415h], bl
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0BE3
        lea ecx, [eax + 060h]
        jmp L009C0BE5
    L009C0BE3:
        xor ecx, ecx
    L009C0BE5:
        cmp byte ptr [ecx + 0416h], bl
        je L009C0BFE
        cmp eax, ebx
        je L009C0BF6
        add eax, 060h
        jmp L009C0BF8
    L009C0BF6:
        xor eax, eax
    L009C0BF8:
        mov byte ptr [eax + 0415h], dl
    L009C0BFE:
        cmp dword ptr [g016180E8], edx
        je L009C0CDA
        mov eax, dword ptr [g011DDE74]
        cmp dword ptr [g016180EC], eax
        jge L009C0CDA
        cmp dword ptr [g016180F0], ebx
        jne L009C0CBC
        push 064h
        push ebx
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Ah
        jle L009C0CDA
        mov ecx, dword ptr [g00F21A70]
        push ecx
        mov ecx, dword ptr [g01618020]
        call dword ptr [call0088F5D0]
        test byte ptr [g01618110], 1
        mov edi, eax
        jne L009C0C78
        or dword ptr [g01618110], 1
        push 05Ah
        push 02Dh
        call dword ptr [call00401950]
        add esp, 8
        imul eax, eax, 03E8h
        mov dword ptr [g0161810C], eax
        jmp L009C0C7D
    L009C0C78:
        mov eax, dword ptr [g0161810C]
    L009C0C7D:
        fld dword ptr [g00F317B8]
        push eax
        push ecx
        fstp dword ptr [esp]
        push edi
        mov ecx, offset object0168F910
        call dword ptr [call00AFE160]
        push eax
        mov ecx, offset object0168F910
        call dword ptr [call00AFEA00]
        mov edx, dword ptr [g0161810C]
        mov eax, dword ptr [g011DDE74]
        add eax, edx
        mov dword ptr [g016180F4], eax
        mov dword ptr [g016180F0], 1
        jmp L009C0CDA
    L009C0CBC:
        cmp dword ptr [g016180F4], eax
        jge L009C0CDA
        push 064h
        push ebx
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Ah
        jle L009C0CDA
        mov dword ptr [g016180F0], ebx
    L009C0CDA:
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0CE9
        lea ecx, [eax + 060h]
        jmp L009C0CEB
    L009C0CE9:
        xor ecx, ecx
    L009C0CEB:
        cmp byte ptr [ecx + 03DDh], bl
        je L009C0D4E
        cmp eax, ebx
        je L009C0CFC
        lea ecx, [eax + 060h]
        jmp L009C0CFE
    L009C0CFC:
        xor ecx, ecx
    L009C0CFE:
        movzx ecx, byte ptr [ecx + 03DCh]
        sub ecx, 1
        test ecx, ecx
        jg L009C0D3C
        cmp eax, ebx
        je L009C0D15
        add eax, 060h
        jmp L009C0D17
    L009C0D15:
        xor eax, eax
    L009C0D17:
        mov byte ptr [eax + 03DCh], bl
        mov eax, dword ptr [esi + 0228h]
        cmp eax, ebx
        je L009C0D32
        add eax, 060h
        mov byte ptr [eax + 03DDh], bl
        jmp L009C0D4E
    L009C0D32:
        xor eax, eax
        mov byte ptr [eax + 03DDh], bl
        jmp L009C0D4E
    L009C0D3C:
        cmp eax, ebx
        je L009C0D45
        add eax, 060h
        jmp L009C0D47
    L009C0D45:
        xor eax, eax
    L009C0D47:
        add byte ptr [eax + 03DCh], 0FFh
    L009C0D4E:
        test byte ptr [esi + 0118h], 1
        je L009C0DAC
        mov eax, dword ptr [esi + 020h]
        movss xmm1, dword ptr [eax + 034h]
        movss xmm0, dword ptr [eax + 038h]
        movss xmm2, dword ptr [eax + 030h]
        add eax, 030h
        movaps xmm3, xmm1
        mulss xmm3, xmm1
        movaps xmm1, xmm0
        mulss xmm1, xmm0
        movaps xmm0, xmm2
        addss xmm3, xmm1
        mulss xmm0, xmm2
        addss xmm3, xmm0
        comiss xmm3, dword ptr [g00D819B8]
        jbe L009C0D9C
        movss xmm0, dword ptr [g00D81944]
        jmp L009C0DA4
    L009C0D9C:
        movss xmm0, dword ptr [g00D582A0]
    L009C0DA4:
        movss dword ptr [esi + 0B38h], xmm0
    L009C0DAC:
        movss xmm0, dword ptr [esi + 0EE4h]
        xorps xmm1, xmm1
        comiss xmm0, xmm1
        jbe L009C0DCC
        subss xmm0, dword ptr [g011DDE7C]
        movss dword ptr [esi + 0EE4h], xmm0
    L009C0DCC:
        movss xmm0, dword ptr [esi + 0EE0h]
        comiss xmm0, xmm1
        jbe L009C0DF5
        movss xmm1, dword ptr [g011DDE7C]
        mulss xmm1, dword ptr [g00DC9290]
        subss xmm0, xmm1
        movss dword ptr [esi + 0EE0h], xmm0
    L009C0DF5:
        mov ecx, esi
        call dword ptr [call008AADC0]
        or dword ptr [esi + 029Ch], 020h
        mov ecx, esi
        call dword ptr [call009BE5D0]
        mov ebx, eax
        mov eax, dword ptr [esi + 0AC0h]
        test eax, eax
        je L009C0E67
        mov edx, dword ptr [eax + 028h]
        and edx, 03C0h
        cmp edx, 080h
        jne L009C0E67
        cmp dword ptr [eax + 01354h], 0
        jne L009C0E67
        test byte ptr [eax + 0F6Fh], 040h
        je L009C0E67
        mov ecx, dword ptr [eax + 0FA0h]
        test ecx, ecx
        je L009C0E67
        mov ecx, dword ptr [ecx + 021Ch]
        cmp dword ptr [ecx + 012Ch], 2
        jne L009C0E67
        test byte ptr [g011DDF38], 03Fh
        jne L009C0E67
        push esi
        push eax
        push 0Ah
        call dword ptr [call00AB3B60]
        add esp, 0Ch
    L009C0E67:
        test byte ptr [esi + 026Ch], 4
        je L009C0E78
        mov edx, dword ptr [esi + 0B40h]
        jmp L009C0E7A
    L009C0E78:
        xor edx, edx
    L009C0E7A:
        mov eax, dword ptr [esi + 0228h]
        test eax, eax
        je L009C0E89
        lea ecx, [eax + 060h]
        jmp L009C0E8B
    L009C0E89:
        xor ecx, ecx
    L009C0E8B:
        push edx
        mov edx, dword ptr [esi + 020h]
        add edx, 030h
        push edx
        call dword ptr [call00922850]
        mov ecx, esi
        call dword ptr [call009E6630]
        cmp dword ptr [esi + 03A8h], 0
        je L009C0F0A
        lea edi, [esi + 02B0h]
        mov ecx, edi
        call dword ptr [call009A9CF0]
        test eax, eax
        je L009C0F03
        mov ecx, edi
        call dword ptr [call009A9CF0]
        mov eax, dword ptr [eax + 018h]
        push eax
        call dword ptr [call00924E80]
        add esp, 4
        cmp dword ptr [eax + 0Ch], 1
        je L009C0F03
        mov ecx, dword ptr [esi + 03A8h]
        push 0
        push ecx
        push esi
        lea ecx, [esp + 02Ch]
        call dword ptr [call0091A050]
        push 1
        lea edx, [esp + 024h]
        push 0
        push edx
        call dword ptr [call00AA83F0]
        mov ecx, eax
        call dword ptr [call00AA80D0]
        lea ecx, [esp + 020h]
        call dword ptr [call0091A0A0]
    L009C0F03:
        mov ecx, esi
        call dword ptr [call009BEED0]
    L009C0F0A:
        test ebx, ebx
        je L009C0FCB
        mov eax, dword ptr [esi + 038h]
        test eax, eax
        je L009C0FCB
        cmp eax, dword ptr [esi + 07C4h]
        jne L009C0FCB
        mov eax, dword ptr [esi + 02DCh]
        test eax, eax
        je L009C0FCB
        mov eax, dword ptr [eax + 025Ch]
        test eax, eax
        je L009C0FCB
        mov ecx, eax
        call dword ptr [call004269B0]
        test al, al
        je L009C0FCB
        mov al, byte ptr [ebx + 026DEh]
        xor al, byte ptr [ebx + 026DCh]
        cmp al, 07Fh
        jbe L009C0FCB
        mov ecx, dword ptr [esi + 0224h]
        call dword ptr [call0089EA80]
        test eax, eax
        je L009C0F7F
        mov edx, dword ptr [eax]
        mov ecx, eax
        mov eax, dword ptr [edx + 0Ch]
        call eax
        cmp eax, 0841h
        je L009C0FCB
    L009C0F7F:
        mov eax, dword ptr [esi + 02DCh]
        lea ecx, [esp + 010h]
        push ecx
        mov ecx, dword ptr [eax + 020h]
        lea edx, [esp + 024h]
        push edx
        push ecx
        mov ecx, dword ptr [eax + 025Ch]
        push eax
        call dword ptr [call00976E90]
        fld dword ptr [g00EBDED4]
        mov eax, dword ptr [esi + 02DCh]
        mov edx, dword ptr [eax + 020h]
        push ecx
        mov ecx, dword ptr [eax + 025Ch]
        fstp dword ptr [esp]
        push 0
        push 0
        push 0
        push 0
        push 0
        push 0
        push edx
        push esi
        call dword ptr [call0097D7C0]
    L009C0FCB:
        mov eax, dword ptr [esi + 0B90h]
        test eax, eax
        je L009C1029
        cmp eax, 3
        je L009C1002
        cmp eax, 4
        je L009C0FFD
        cmp dword ptr [g016180E8], 1
        je L009C105A
        mov eax, dword ptr [g016180EC]
        cmp eax, dword ptr [g011DDE74]
        jge L009C105A
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C0FFD:
        cmp eax, 3
        jne L009C1069
    L009C1002:
        cmp dword ptr [g016180E8], 1
        je L009C1021
        mov ecx, dword ptr [g016180EC]
        cmp ecx, dword ptr [g011DDE74]
        jge L009C1021
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C1021:
        fld dword ptr [g00D796E4]
        jmp L009C105C
    L009C1029:
        test byte ptr [esi + 026Ch], 4
        je L009C1069
        cmp dword ptr [esi + 0B40h], 0
        je L009C1069
        cmp dword ptr [g016180E8], 1
        je L009C105A
        mov edx, dword ptr [g016180EC]
        cmp edx, dword ptr [g011DDE74]
        jge L009C105A
        fld dword ptr [g00DCB2AC]
        jmp L009C105C
    L009C105A:
        fld1 
    L009C105C:
        push ecx
        fstp dword ptr [esp]
        push 0
        mov ecx, esi
        call dword ptr [call009BFD80]
    L009C1069:
        mov eax, dword ptr [esi + 0A84h]
        cmp eax, 1
        je L009C1079
        cmp eax, 2
        jne L009C1089
    L009C1079:
        mov ecx, esi
        call dword ptr [call009BEE70]
        mov al, 1
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    L009C1089:
        mov eax, dword ptr [esi]
        mov edx, dword ptr [eax + 0ECh]
        lea ecx, [esp + 020h]
        push ecx
        mov ecx, esi
        call edx
        movss xmm1, dword ptr [eax + 4]
        movss xmm0, dword ptr [eax]
        mov eax, dword ptr [esi + 0228h]
        movaps xmm2, xmm1
        mulss xmm2, xmm1
        movaps xmm1, xmm0
        mulss xmm1, xmm0
        addss xmm2, xmm1
        movss xmm1, dword ptr [g00DC9290]
        sqrtss xmm0, xmm2
        comiss xmm1, xmm0
        jbe L009C111E
        test eax, eax
        je L009C10D5
        add eax, 060h
        jmp L009C10D7
    L009C10D5:
        xor eax, eax
    L009C10D7:
        cmp dword ptr [eax + 03C0h], 0
        mov ecx, esi
        jne L009C10FA
        mov eax, dword ptr [g011DDE74]
        lea edi, [eax + 01F4h]
        call dword ptr [call004389D0]
        mov dword ptr [eax + 03C0h], edi
        jmp L009C114B
    L009C10FA:
        call dword ptr [call004389D0]
        mov ecx, dword ptr [g011DDE74]
        cmp ecx, dword ptr [eax + 03C0h]
        jbe L009C114B
        mov ecx, esi
        call dword ptr [call004389D0]
        add eax, 03D0h
        or dword ptr [eax], 1
        jmp L009C114B
    L009C111E:
        test eax, eax
        je L009C1127
        add eax, 060h
        jmp L009C1129
    L009C1127:
        xor eax, eax
    L009C1129:
        mov dword ptr [eax + 03C0h], 0
        mov eax, dword ptr [esi + 0228h]
        test eax, eax
        je L009C1142
        add eax, 060h
        jmp L009C1144
    L009C1142:
        xor eax, eax
    L009C1144:
        and dword ptr [eax + 03D0h], 0FFFFFFFEh
    L009C114B:
        lea edi, [esi + 02B0h]
        mov ecx, edi
        call dword ptr [call009A9CF0]
        test eax, eax
        je L009C117C
        mov ecx, edi
        call dword ptr [call009A9CF0]
        cmp dword ptr [eax + 01Ch], 1
        jne L009C117C
        mov ecx, esi
        call dword ptr [call004389D0]
        mov edx, dword ptr [g011DDE74]
        mov dword ptr [eax + 03F8h], edx
    L009C117C:
        mov eax, dword ptr [esi + 0B40h]
        test eax, eax
        je L009C1203
        cmp dword ptr [g016180E8], 1
        je L009C1203
        mov ecx, dword ptr [g016180EC]
        cmp ecx, dword ptr [g011DDE74]
        jge L009C1203
        movss xmm0, dword ptr [g00D50398]
        push 064h
        push 0
        movss dword ptr [eax + 010C8h], xmm0
        call dword ptr [call00401950]
        add esp, 8
        cmp eax, 05Fh
        jle L009C11CB
        mov eax, dword ptr [esi + 0B40h]
        or byte ptr [eax + 0F64h], 080h
    L009C11CB:
        mov eax, dword ptr [g016180F8]
        test eax, eax
        je L009C11DC
        cmp dword ptr [esi + 0B40h], eax
        je L009C1203
    L009C11DC:
        mov edx, dword ptr [esi + 0B40h]
        fld dword ptr [g00D8F340]
        push ecx
        mov dword ptr [g016180F8], edx
        fstp dword ptr [esp]
        mov ecx, dword ptr [esi + 0B40h]
        add ecx, 01120h
        call dword ptr [call008AE670]
    L009C1203:
        cmp byte ptr [g01724286], 0
        je L009C1215
        call dword ptr [call00462F90]
        test al, al
        je L009C121C
    L009C1215:
        mov ecx, esi
        call dword ptr [call009BE7D0]
    L009C121C:
        cmp dword ptr [esi + 0B0h], 0
        je L009C1293
        cmp dword ptr [esi + 0B8h], 0
        jle L009C1293
        mov eax, dword ptr [esi + 0AC0h]
        test eax, eax
        je L009C1293
        mov eax, dword ptr [eax + 028h]
        and eax, 03C0h
        cmp eax, 0100h
        jne L009C1293
        movss xmm0, dword ptr [esi + 0EE8h]
        subss xmm0, dword ptr [g011DDE7C]
        xorps xmm1, xmm1
        comiss xmm1, xmm0
        movss dword ptr [esi + 0EE8h], xmm0
        jb L009C1293
        fldz 
        push ecx
        mov ecx, dword ptr [esi + 020h]
        fstp dword ptr [esp]
        push 0
        push 0
        push esi
        add ecx, 030h
        push ecx
        push 2
        call dword ptr [call00987730]
        movss xmm0, dword ptr [g00D81958]
        add esp, 018h
        movss dword ptr [esi + 0EE8h], xmm0
    L009C1293:
        movss xmm0, dword ptr [esi + 0EECh]
        xorps xmm1, xmm1
        comiss xmm0, xmm1
        jbe L009C12D4
        subss xmm0, dword ptr [g011DDE7C]
        comiss xmm1, xmm0
        movss dword ptr [esi + 0EECh], xmm0
        jb L009C12D4
        fldz 
        mov edx, dword ptr [esi + 020h]
        push ecx
        fstp dword ptr [esp]
        push 0
        push 0
        push esi
        add edx, 030h
        push edx
        push 015h
        call dword ptr [call00987730]
        add esp, 018h
    L009C12D4:
        mov eax, dword ptr [esi + 0EF4h]
        test eax, eax
        jle L009C12F5
        add eax, -1
        mov dword ptr [esi + 0EF4h], eax
        mov al, 1
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    L009C12F0:
        call dword ptr [call008AADC0]
    L009C12F5:
        pop edi
        pop esi
        mov al, 1
        pop ebx
        mov esp, ebp
        pop ebp
        ret 
    }
}
}
