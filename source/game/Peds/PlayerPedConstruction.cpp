#include "game/Peds/PlayerPedConstruction.h"
#include <cstdint>
#include <cstring>

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
