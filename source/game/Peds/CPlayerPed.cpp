#include "game/Peds/CPlayerPed.h"
#include <cstdint>
#include <cstring>
#include <initializer_list>

// ======================================================================
// FloatCopy
// ======================================================================
namespace reiv::game::player_detail {
void CopyBlockEC0(void* object, const void* input) {
    __asm {
        mov ecx, object
        mov eax, input
        fld dword ptr [eax]
        movss xmm0, dword ptr [eax + 4]
        movss xmm1, dword ptr [eax + 8]
        fstp dword ptr [ecx + 0EC0h]
        movss dword ptr [ecx + 0EC4h], xmm0
        movss dword ptr [ecx + 0EC8h], xmm1
        fld dword ptr [eax + 12]
        fstp dword ptr [ecx + 0ECCh]
    }
}

void CopyBlockED0(void* object, const void* input) {
    __asm {
        mov ecx, object
        mov eax, input
        fld dword ptr [eax]
        movss xmm0, dword ptr [eax + 4]
        movss xmm1, dword ptr [eax + 8]
        fstp dword ptr [ecx + 0ED0h]
        movss dword ptr [ecx + 0ED4h], xmm0
        movss dword ptr [ecx + 0ED8h], xmm1
        fld dword ptr [eax + 12]
        fstp dword ptr [ecx + 0EDCh]
    }
}
}

// ======================================================================
// Destruction
// ======================================================================
namespace reiv { namespace game {
std::uint32_t PlayerPedDestruction::Read(const void* p, std::uint32_t offset) {
        std::uint32_t value;
        std::memcpy(&value, reinterpret_cast<const void*>(reinterpret_cast<std::uintptr_t>(p) + offset), 4);
        return value;
    }

void PlayerPedDestruction::Write(void* p, std::uint32_t offset, std::uint32_t value) {
        std::memcpy(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(p) + offset), &value, 4);
    }

void* PlayerPedDestruction::Pointer(std::uint32_t value) { return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value)); }

void* PlayerPedDestruction::Member228(void* object) {
        const auto value = Read(object, 0x228);
        return value ? Pointer(value + 0x60u) : nullptr;
    }

    // VA 0x009C1E60, complete body ending in JMP 0x008AC1E0.
    // Requires readable [member228 + 0x3E4/0x3E8], as does the original.
    // The EA8 pointer and member228 are deliberately re-read after callbacks.
void PlayerPedDestruction::Destroy(void* object, const PlayerPedDestructionDependencies& d) {
        auto owned = Read(object, 0xEA8);
        Write(object, 0, d.playerVtable);
        if (owned) {
            d.call8DD270(d.context, Pointer(owned));
            owned = Read(object, 0xEA8);
            if (owned) {
                d.call8DD8B0(d.context, Pointer(owned));
                d.call5B1C10(d.context, Pointer(owned));
            }
            Write(object, 0xEA8, 0);
        }
        for (const std::uint32_t offset : {0x3E4u, 0x3E8u}) {
            const auto handle = Read(Member228(object), offset);
            if (handle) {
                const auto first = d.call92F4D0(d.context, d.load1548F88(d.context), handle);
                const auto second = d.call8631E0(d.context, first);
                d.call9C0A70(d.context, second);
                Write(Member228(object), offset, 0);
            }
        }
        d.call920CD0(d.context, Member228(object), 0);
        d.call4475F0(d.context, reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(object) + 0xEAC));
        d.call8AC1E0(d.context, object);
    }

    // VA 0x009C2260, scalar deleting-destructor wrapper, RET 4.
    // Return is the original pointer, even when the allocator has released it.
void* PlayerPedDestruction::DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& d) {
        Destroy(object, d);
        if (flags & 1u) d.call448300(d.context, d.load18A82AC(d.context), object);
        return object;
    }
} }

// ======================================================================
// Control
// ======================================================================
namespace reiv { namespace game {
std::uint32_t PlayerPedControl::Read(const void* p, unsigned offset) {
        std::uint32_t value;std::memcpy(&value,static_cast<const unsigned char*>(p)+offset,4);return value;
    }

void PlayerPedControl::Write(void* p,unsigned offset,std::uint32_t value) {std::memcpy(static_cast<unsigned char*>(p)+offset,&value,4);}

    // VA 0x009C0AA0, slot 14. Raw EAX result; its gameplay meaning is unknown.
std::uint32_t PlayerPedControl::ApplyModel(void* object,std::uint32_t model,const PlayerPedControlDependencies& d) {
        const auto descriptor=d.modelAt15F73B0(d.context,model);
        std::uint8_t flag;std::memcpy(&flag,static_cast<const unsigned char*>(descriptor)+0x8C,1);
        if(!flag)return d.call8AC500(d.context,object,model);
        d.call8DB2B0(d.context,model);
        d.call8AC500(d.context,object,model);
        // The original SETNE CL leaves high bits of ECX unspecified; 9BF660
        // reads only its argument's low byte (CMP BYTE [ESP+8],0).
        d.call9BF660(d.context,object,static_cast<std::uint8_t>(Read(object,0x68)!=0xFFFFFFFFu));
        return d.call8DD530(d.context,object,Read(object,0x21C));
    }

    // VA 0x009C1E10, slot 47, five stack arguments, RET 20.
void* PlayerPedControl::CreateControl(void* object,std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t e,std::uint32_t count,const PlayerPedControlDependencies& d) {
        auto allocated=d.call439CB0(d.context,d.load18A839C(d.context));
        auto created=allocated?d.call4F4D20(d.context,allocated,object,0,a,b,c,e):nullptr;
        Write(object,0x6C,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created)));
        // Deliberately invoked even for null, matching the original caller.
        d.call49F330(d.context,created,count);
        return reinterpret_cast<void*>(static_cast<std::uintptr_t>(Read(object,0x6C)));
    }
} }

// ======================================================================
// Counter
// ======================================================================
namespace reiv { namespace game {
namespace {
static std::uint32_t Read32(const void* p, std::uint32_t offset) {
    std::uint32_t v; std::memcpy(&v, static_cast<const std::uint8_t*>(p) + offset, 4); return v;
}
static void Write32(void* p, std::uint32_t offset, std::uint32_t v) {
    std::memcpy(static_cast<std::uint8_t*>(p) + offset, &v, 4);
}
static std::uint8_t Read8(const void* p, std::uint32_t offset) {
    return static_cast<const std::uint8_t*>(p)[offset];
}
static void* Pointer(std::uint32_t bits) {
    return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits));
}
static void* QueryReceiver(void* player) {
    // x86 addition wraps; the original has no null-pointer fallback.
    return Pointer(Read32(player, 0x224) + 0x2E0u);
}
}

// RVA 0x005BE610. Unsigned arithmetic preserves x86 counter overflow.
void PlayerPedCounter::Update(void* player, const PlayerPedCounterDependencies& d) {
    if (Read8(player, 0x219) == 0) return;
    void* receiver = QueryReceiver(player);
    if (d.query426910(receiver, 0x410, 0) == 0 &&
        d.query426910(receiver, 0x41E, 0) == 0) return;
    void* related = d.resolve9BE5D0(player);
    if (related == nullptr) return; // explicit original branch
    std::uint32_t value = 0;
    std::uint8_t flag = 0;
    bool eligible = true;
    bool stateEight = false;
    if (d.state9C2720(Pointer(Read32(player, 0x224)), &value, &flag) != 0) {
        eligible = value == 5 || value == 8;
        stateEight = value == 8;
    }
    if (d.query426910(QueryReceiver(player), 0x413, 0) != 0) {
        const auto delta = d.ticks448330();
        const auto bits = Read32(player, 0xEB0) - delta;
        Write32(player, 0xEB0, (bits & 0x80000000u) ? 0u : bits); // JNS
    } else if (!stateEight) {
        const auto delta = d.ticks448330();
        const auto bits = Read32(player, 0xEB0) + delta;
        // CMP bits,10000/JLE uses a signed comparison, even after overflow.
        Write32(player, 0xEB0, !(bits & 0x80000000u) && bits > 10000u ? 10000u : bits);
    }
    const auto difference = static_cast<std::uint8_t>(Read8(related, 0x26DE) ^ Read8(related, 0x26DC));
    const bool retain = eligible && (stateEight ||
        (difference > 100u && difference < *d.thresholdF2F067));
    Write32(player, 0xEB4, Read32(player, 0xEB0));
    if (!retain) Write32(player, 0xEB0, 0);
}
// RVA 0x005BE770, CPlayerPed virtual slot 73.
void PlayerPedCounter::UpdateSlot73(void* player, const PlayerPedCounterDependencies& d) {
    d.before8A3990(player);
    Update(player, d);
}
} }

// ======================================================================
// ProtectedValue
// ======================================================================
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

// ======================================================================
// Construction
// ======================================================================
namespace reiv { namespace game {
std::uint32_t PlayerPedConstruction::R(const void* p, std::uint32_t off) {
        std::uint32_t v; std::memcpy(&v, static_cast<const std::uint8_t*>(p)+off,4); return v;
    }

void PlayerPedConstruction::W(void* p, std::uint32_t off, std::uint32_t value) {
        std::memcpy(static_cast<std::uint8_t*>(p)+off,&value,4);
    }

void PlayerPedConstruction::B(void* p, std::uint32_t off, std::uint8_t value) {
        static_cast<std::uint8_t*>(p)[off]=value;
    }

std::uint8_t PlayerPedConstruction::Byte(const void* p, std::uint32_t off) {
        return static_cast<const std::uint8_t*>(p)[off];
    }

std::uint32_t PlayerPedConstruction::Bits(const void* p) {
        return static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(p));
    }

void* PlayerPedConstruction::P(std::uint32_t bits) { return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits)); }

void* PlayerPedConstruction::Add(void* p, std::uint32_t off) { return P(Bits(p)+off); }

void* PlayerPedConstruction::LinkReceiver(void* player) {
        const auto value=R(player,0x228); return P(value?value+0x60u:0u);
    }

    // FLD/FSTP keeps original single-precision conversion behavior for NaNs.
std::uint32_t PlayerPedConstruction::LoadStoreX87(std::uint32_t bits) {
        std::uint32_t result;
        __asm {
            fld dword ptr bits
            fstp dword ptr result
        }
        return result;
    }

    // Exactly the original x87 arithmetic and saved-control-word sequence.
    // Isolated for independent FPU-state comparison; MSVC x86 only.
std::uint32_t PlayerPedConstruction::RandomOffset(std::uint32_t random, std::uint32_t scaleBits, std::uint32_t rangeBits) {
        const std::uint32_t value=random&0xFFFFu;
        std::uint16_t saved, truncate;
        std::uint64_t result;
        __asm {
            fild dword ptr value
            fnstcw word ptr saved
            fmul dword ptr scaleBits
            mov ax, saved
            or ax, 0C00h
            mov truncate, ax
            fmul dword ptr rangeBits
            fldcw word ptr truncate
            fistp qword ptr result
            fldcw word ptr saved
        }
        return static_cast<std::uint32_t>(result);
    }

void* PlayerPedConstruction::Construct(void* player, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3,
                           const PlayerPedConstructionDependencies& d) {
        d.base8ABF10(player,a1,a2);
        W(player,0,d.address(0x00D819C4));
        d.embeddedC68B50(Add(player,0xE80));
        d.embedded4475C0(Add(player,0xEAC));
        W(player,0xEBC,d.readGlobal32(0x012308B0));
        W(player,0xEC0,d.readGlobal32(0x00F21F10));
        W(player,0xEC4,d.readGlobal32(0x00F21F14));
        W(player,0xEC8,d.readGlobal32(0x00F21F18));
        W(player,0xED0,d.readGlobal32(0x00F21F20));
        W(player,0xED4,d.readGlobal32(0x00F21F24));
        const auto ed8=d.readGlobal32(0x00F21F28);
        W(player,0xED8,ed8);
        d.blockB2A8F0(Add(player,0x80),1);
        d.blockB29E50(Add(player,0x80));
        d.writeGlobal32(0x01724200,0);
        W(player,0x228,Bits(d.resolve817F20(a3)));
        if(d.readGlobal32(0x010D0170)!=1 && d.readGlobal32(0x010E1984)==d.readGlobal32(0x00E3447C) &&
           d.readGlobal32(0x00F0E4A0)!=0x12) {
            d.link920CD0(LinkReceiver(player),player);
            d.link921050(LinkReceiver(player));
        }
        d.writeGlobal32(0x01724210,100);
        W(LinkReceiver(player),0x3D4,0xFFFFFFFFu);
        W(P(R(player,0x21C)),0x12C,0);
        if(Byte(player,0x218)==0 || Byte(player,0x219)==0) d.initialize9BE4C0(player);
        const auto time=d.readGlobal32(0x011DDE74);
        const auto random=d.randomD0D21A();
        const auto scale=d.readGlobal32(0x00EBE1D8);
        const auto range=d.readGlobal32(0x00D819BC);
        d.writeGlobal32(0x016180EC,time-RandomOffset(random,scale,range)+60000u);
        W(player,0x260,R(player,0x260)|0x80u);
        const auto hash=d.hash8631E0(d.address(0x00D8195C));
        const auto initial=d.readGlobal32(0x00D8D70C);
        d.writeGlobal32(0x016180FC,hash);
        W(player,0xA94,initial);
        d.value447610(Add(player,0xEAC),LoadStoreX87(d.readGlobal32(0x00D8D70C)));
        d.flags89E5A0(player,LoadStoreX87(R(player,0xA94)));
        d.reset9720E0(Add(P(R(player,0x21C)),0x110));
        d.writeGlobal32(0x01724214,d.address(0x016180E8));
        auto link=LinkReceiver(player);
        W(player,0xE74,0); W(player,0xE78,0); B(player,0xE70,0);
        const auto value=d.readGlobal32(0x00D50978);
        B(link,0x416,0);
        auto target=P(R(player,0x224));
        B(player,0xE71,0); W(target,0xEC,value); W(target,0xE8,2);
        if(d.readGlobal32(0x010D0170)==1 || d.readGlobal32(0x010E1984)!=d.readGlobal32(0x00E3447C) ||
           d.readGlobal32(0x00F0E4A0)==0x12) {
            const auto index=d.index797D70();
            const auto comparison=d.readGlobal32(0x010D00A0);
            auto selected=d.readGlobal32(0x010CF7E0);
            if(comparison==index) selected+=1;
            W(player,0x68,selected);
        }
        const auto message=d.readGlobal32(0x01724240);
        const auto window=d.readGlobal32(0x01724234);
        d.sendMessageA(window,message,0,d.address(0x01724200));
        W(player,0xE7C,Bits(player));
        auto allocation=d.allocate4011D0(0x60);
        if(allocation) allocation=d.create8DA9A0(allocation);
        // Original reads this+228 before finishing the final field writes.
        auto finalReceiver=P(R(player,0x228));
        W(player,0xEA8,Bits(allocation)); B(player,0x63,0xFF);
        B(player,0xEA6,0); B(player,0xEA4,0); B(player,0xEA5,0); B(player,0xEA7,0);
        W(player,0xEB0,0); W(player,0xEB4,0); W(player,0xEB8,0);
        W(player,0xEE0,0); W(player,0xEE4,0);
        W(player,0xEE8,d.readGlobal32(0x00D81958));
        W(player,0xEEC,d.readGlobal32(0x00D81958));
        W(player,0xEF0,0xFFFFFFFFu); W(player,0xEF4,0);
        if(d.flag878A00(finalReceiver)) d.writeGlobal8(0x00F3FDDC,1);
        return player;
    }
} }

// ======================================================================
// Nonvirtual
// ======================================================================
namespace reiv { namespace game {
std::uint32_t PlayerPedNonvirtual::R(const void* p, unsigned off) {
        std::uint32_t v; std::memcpy(&v,static_cast<const std::uint8_t*>(p)+off,4); return v;
    }

void PlayerPedNonvirtual::W(void* p, unsigned off, std::uint32_t value) {
        std::memcpy(static_cast<std::uint8_t*>(p)+off,&value,4);
    }

void* PlayerPedNonvirtual::Pointer(std::uint32_t bits) {return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits));}

void* PlayerPedNonvirtual::LinkReceiver(void* player) {
        const auto bits=R(player,0x228);return Pointer(bits?bits+0x60u:0u);
    }

bool PlayerPedNonvirtual::Enabled(const void* player) {
        auto bytes=static_cast<const std::uint8_t*>(player);
        return bytes[0x218]==0 && bytes[0x219]!=0;
    }

    // VA 0x009BE4C0. Captured write destination survives create callback.
    // Null dependent pointers remain invalid, as in the original low-address accesses.
void PlayerPedNonvirtual::InitializeRelations(void* player, const PlayerPedInitializationDependencies& d) {
        const auto oldHandle=R(LinkReceiver(player),0x3D4);
        if(!(oldHandle&0x80000000u)) {
            auto receiver=Pointer(d.table1662170+oldHandle*0x5Cu);
            d.resetA677D0(receiver,1,1);
        }
        auto destination=LinkReceiver(player);
        const auto created=d.createA66F20(player);
        W(destination,0x3D4,created);
        auto handle=R(LinkReceiver(player),0x3D4);
        d.linkA67AA0(Pointer(d.table1662170+8u+handle*0x5Cu),player);
        handle=R(LinkReceiver(player),0x3D4);
        d.startA67D70(Pointer(d.table1662170+handle*0x5Cu));
        auto link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFEFFu);
        link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFDFFu);
        link=LinkReceiver(player);
        W(link,0x3D0,R(link,0x3D0)&0xFFFFFBFFu);
    }

    // VA 0x009BE5D0; original tail-calls global helper 0x007C3900.
void* PlayerPedNonvirtual::ResolveIfPlayerFlags(const void* player, const PlayerPedNonvirtualDependencies& d) {
        return Enabled(player)?d.resolve7C3900():nullptr;
    }

    // VA 0x009BEE70; original passes receiver+0x2B0 and one zero argument.
void PlayerPedNonvirtual::CallBlockIfPlayerFlags(void* player, const PlayerPedNonvirtualDependencies& d) {
        if(Enabled(player)) {
            const auto receiverBits=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(player))+0x2B0u;
            d.call9A9EF0(reinterpret_cast<void*>(static_cast<std::uintptr_t>(receiverBits)),0);
        }
    }
} }

// ======================================================================
// Accumulation
// ======================================================================
namespace reiv { namespace game {
    // VA 0x009BF5F0. SSE instructions preserve NaNs, MXCSR, and store order.
    // COMISS runs before the EE0 store; an unmasked comparison exception must
    // therefore occur before that store. Unordered and <= skip the reset.
void PlayerPedAccumulation::AdvanceFieldEE0(void* object, const PlayerPedAccumulationGlobals& globals) {
        const auto value=globals.value11DDE7C;
        const auto multiplier=globals.multiplierDCC5EC;
        const auto limit=globals.limitD81948;
        const auto reset=globals.resetD81950;
        __asm {
            mov ecx, object
            mov eax, value
            movss xmm0, dword ptr [eax]
            mov eax, multiplier
            mulss xmm0, dword ptr [eax]
            addss xmm0, dword ptr [ecx+0EE0h]
            mov eax, limit
            comiss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EE0h], xmm0
            jbe accumulation_done
            mov eax, reset
            movss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EE4h], xmm0
            xorps xmm0, xmm0
            movss dword ptr [ecx+0EE0h], xmm0
        accumulation_done:
        }
    }
} }

// ======================================================================
// ExtraFields
// ======================================================================
namespace reiv { namespace game {
    // VA 0x009BF5D0. The original defines AL only. Unordered COMISS returns one.
std::uint8_t PlayerPedExtraFields::TestFieldEE4(const void* object, const PlayerPedExtraFieldsGlobals& globals) {
        const auto limit=globals.limitDECD60;
        std::uint8_t result;
        __asm {
            mov ecx, object
            mov eax, limit
            movss xmm0, dword ptr [ecx+0EE4h]
            comiss xmm0, dword ptr [eax]
            jbe field_ee4_one
            mov result, 0
            jmp field_ee4_done
        field_ee4_one:
            mov result, 1
        field_ee4_done:
        }
        return result;
    }

    // VA 0x009BF640. Ordered zero/negative resets; unordered comparison skips.
void PlayerPedExtraFields::ResetFieldEEC(void* object, const PlayerPedExtraFieldsGlobals& globals) {
        const auto reset=globals.resetD81958;
        __asm {
            mov ecx, object
            xorps xmm0, xmm0
            comiss xmm0, dword ptr [ecx+0EECh]
            jb field_eec_done
            mov eax, reset
            movss xmm0, dword ptr [eax]
            movss dword ptr [ecx+0EECh], xmm0
        field_eec_done:
        }
    }
} }

// ======================================================================
// ModelReset
// ======================================================================
namespace reiv { namespace game {
std::uint32_t PlayerPedModelReset::Read(const void*p,unsigned offset) {std::uint32_t v;std::memcpy(&v,static_cast<const unsigned char*>(p)+offset,4);return v;}

void PlayerPedModelReset::Write(void*p,unsigned offset,std::uint32_t v) {std::memcpy(static_cast<unsigned char*>(p)+offset,&v,4);}

void* PlayerPedModelReset::Member(std::uint32_t bits) {return reinterpret_cast<void*>(static_cast<std::uintptr_t>(bits+0x60u));}

    // VA 0x009BF660. One byte-valued stack argument; original RET 4.
    // MOVSS global transfer is a bit copy, with no numeric float conversion.
void PlayerPedModelReset::Reset(void* player,std::uint8_t argument,const PlayerPedModelResetDependencies& d) {
        *d.globalF1D9D8=*d.sourceD50398;
        Write(player,0x24,Read(player,0x24)|1u);
        Write(player,0xA80,0);
        d.call8A92C0(player,0);
        d.call8A07E0(player,1);
        d.call8A70C0(player,0,0xFFFFFFFFu);
        d.call89C8B0(player,0xFFFFFFFFu);
        auto member=Read(player,0x228);
        Write(player,0x26C,Read(player,0x26C)|0x20000u);
        if(member&&member+0x60u)Write(Member(member),0x3D0,Read(Member(member),0x3D0)&~2u);
        d.virtualSlot68(player);
        Write(player,0x24,Read(player,0x24)|1u);
        if(!argument)d.call9BF0D0(player,1,0,1);
        member=Read(player,0x228);
        if(member&&member+0x60u)d.call8793F0(Member(member));
    }
} }

// ======================================================================
// ReferenceClear
// ======================================================================
namespace reiv { namespace game {
    // VA 0x009BEED0. Zero is written after the external call, including if
    // the external call rewrites the pointer field. No complete layout claimed.
void PlayerPedReferenceClear::ClearFieldE74(void* object,const PlayerPedReferenceClearDependencies& d) {
        auto field=reinterpret_cast<std::uint32_t*>(static_cast<unsigned char*>(object)+0xE74);
        std::uint32_t value;std::memcpy(&value,field,4);
        if(value){
            d.call9E6580(reinterpret_cast<void*>(static_cast<std::uintptr_t>(value)),field);
            const std::uint32_t zero=0;std::memcpy(field,&zero,4);
        }
    }
} }

// ======================================================================
// StateHelpers
// ======================================================================
namespace reiv::game::player_detail {
void ClearState3D8(void* player, const StateHelperDependencies& d) {
    std::uint32_t info;
    std::memcpy(&info, static_cast<unsigned char*>(player) + 0x228, 4);
    const std::uint32_t member = info ? info + 0x60u : 0u;
    const auto p = reinterpret_cast<unsigned char*>(static_cast<std::uintptr_t>(member));
    if ((p[0x3D0] & 2) == 0) return;
    std::uint32_t state;
    std::memcpy(&state, p + 0x3D8, 4);
    if (!state) return;
    const auto bits = *d.sourceD50398;
    const std::uint32_t zero = 0;
    std::memcpy(p + 0x3D8, &zero, 4);
    *d.destinationF1D9D8 = bits;
}

__declspec(naked) void __fastcall StoreQuery7(void* player, const StateHelperDependencies* dependencies) {
    __asm {
        push esi
        push edi
        mov edi, edx
        mov eax, dword ptr [ecx + 228h]
        test eax, eax
        jz query7null
        lea esi, [eax + 60h]
        jmp query7ready
    query7null:
        xor esi, esi
    query7ready:
        push 7
        call dword ptr [edi + 8]
        fstp dword ptr [esi + 3B4h]
        add esp, 4
        pop edi
        pop esi
        ret
    }
}

__declspec(naked) void __fastcall StoreQuery8AndClearFlag(void* player, const StateHelperDependencies* dependencies) {
    __asm {
        push ebx
        push esi
        push edi
        mov ebx, edx
        mov edi, ecx
        mov eax, dword ptr [edi + 228h]
        test eax, eax
        jz query8null
        lea esi, [eax + 60h]
        jmp query8ready
    query8null:
        xor esi, esi
    query8ready:
        push 8
        call dword ptr [ebx + 8]
        fstp dword ptr [esi + 3E0h]
        mov eax, dword ptr [edi + 228h]
        add esp, 4
        test eax, eax
        pop edi
        pop esi
        pop ebx
        jz query8clearzero
        and dword ptr [eax + 430h], 0FFFFFF7Fh
        ret
    query8clearzero:
        xor eax, eax
        and dword ptr [eax + 3D0h], 0FFFFFF7Fh
        ret
    }
}
}

// ======================================================================
// ActionRange
// ======================================================================
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

// ======================================================================
// ActionRequest
// ======================================================================
namespace reiv::game::player_action_request {
__declspec(naked) std::uint8_t __fastcall Act(void* object, void*, std::uint32_t flag, std::uint32_t argument) {
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

// ======================================================================
// ActionSelection
// ======================================================================
namespace reiv::game::player_action_selection {
__declspec(naked) std::uint32_t __fastcall Select(void* embeddedReceiver, void*, std::uint32_t flags, std::uint32_t rangeBits, std::uint32_t argument, float* output, std::uint32_t last) {
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

// ======================================================================
// ReceiverHelpers
// ======================================================================
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

// ======================================================================
// RelatedFlags
// ======================================================================
namespace reiv::game {
std::uint32_t PlayerPedRelatedFlags::Read(const void* p, std::uint32_t off) { std::uint32_t x; std::memcpy(&x,static_cast<const unsigned char*>(p)+off,4);return x; }

void PlayerPedRelatedFlags::Write(void* p, std::uint32_t off, std::uint32_t x) { std::memcpy(static_cast<unsigned char*>(p)+off,&x,4); }

    // 0x009BF250: complete caller. Player receiver confirmed, original declaring class unknown.
    // Returns opaque EAX bits to preserve every original return path, without native type claims.
    // Dependencies are supplied explicitly; isolated sequential fixtures only.
std::uint32_t PlayerPedRelatedFlags::UpdateRaw(void* player,const PlayerPedRelatedFlagDependencies& deps) {
        static_assert(sizeof(void*)==4,"Related flags preserve x86 pointer/return bits.");
        std::uint32_t result=0;
        for(std::uint32_t index=0;index<7;++index) {
            const auto block=deps.getBlock4389D0(player);
            const auto receiver=Read(block,0x3D4)*std::uint32_t{0x5C}+deps.base1662178;
            auto candidate=deps.enumerateA66B70(receiver,index);
            result=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(candidate));
            if(!candidate||*(static_cast<unsigned char*>(candidate)+0xA70)==2)continue;
            deps.virtualSlot12(player,1);
            if((*(static_cast<unsigned char*>(candidate)+0x26C)&4)==0)Write(candidate,0x24,Read(candidate,0x24)|1);
            result=((std::uint32_t{deps.flags16180E0[index]}<<12)^Read(candidate,0x260))&0x1000;
            Write(candidate,0x260,Read(candidate,0x260)^result);
        }
        return result;
    }
}
