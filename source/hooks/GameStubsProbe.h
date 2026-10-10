#pragma once
// Pure, complete instruction bodies only. No inferred class ABI is exercised.
namespace gamestubs {
struct Candidate { unsigned rva; const unsigned char* bytes; unsigned size; unsigned mask; unsigned expected; bool relocated; };
#include "GameStubBindings.h"
struct Slot { unsigned vtableRva; unsigned slot; unsigned targetRva; };
#include "GameSlotBindings.h"
inline unsigned slotsChecked=0, slotsFailed=0;
inline int CheckSlot(const Slot& s, std::uintptr_t& actual) {
    __try {
        const auto base=reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr));
        const auto dos=reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
        const auto nt=reinterpret_cast<const IMAGE_NT_HEADERS32*>(base+dos->e_lfanew);
        const auto size=nt->OptionalHeader.SizeOfImage;
        const std::uint64_t tableOffset=std::uint64_t(s.vtableRva)+std::uint64_t(s.slot)*4;
        if(tableOffset+4>size || s.targetRva>=size) return 1;
        actual=*reinterpret_cast<const std::uintptr_t*>(base+static_cast<unsigned>(tableOffset));
        if(actual!=base+s.targetRva) return 2;
        MEMORY_BASIC_INFORMATION info{};
        if(!VirtualQuery(reinterpret_cast<void*>(actual),&info,sizeof(info)) || info.State!=MEM_COMMIT || info.AllocationBase!=reinterpret_cast<void*>(base) || (info.Protect&(PAGE_GUARD|PAGE_NOACCESS))) return 3;
        const unsigned p=info.Protect&0xff;
        return p==PAGE_EXECUTE_READ || p==PAGE_EXECUTE_READWRITE || p==PAGE_EXECUTE_WRITECOPY ? 0:4;
    } __except(EXCEPTION_EXECUTE_HANDLER) { return 5; }
}
inline void AuditSlots() {
    FILE* f=nullptr;
    if(fopen_s(&f,hashprobe::GameFile("ReIV-game-slots.csv").c_str(),"wb") || !f) { ++slotsFailed; return; }
    fputs("vtable_rva,slot,target_rva,runtime_target,result\n",f);
    if(!reiv::original::Initialize()) { ++slotsFailed; fclose(f); return; }
    for(const auto& s:slots) {
        std::uintptr_t actual=0; const int result=CheckSlot(s,actual);
        ++slotsChecked; if(result) ++slotsFailed;
        fprintf(f,"0x%08X,%u,0x%08X,0x%08X,%d\n",s.vtableRva,s.slot,s.targetRva,static_cast<unsigned>(actual),result);
    }
    fclose(f);
    REIV_INFO("Game virtual slot audit checked=%u failures=%u (addresses only; not calls)",slotsChecked,slotsFailed);
}
inline unsigned calls[sizeof(candidates)/sizeof(candidates[0])]{}, failures[sizeof(candidates)/sizeof(candidates[0])]{};
inline unsigned exceptions=0;
inline bool enabled=false,done=false;
inline int Check(unsigned i) {
    __try {
        const auto& c=candidates[i];
        unsigned char expectedBytes[16]{};
        std::memcpy(expectedBytes,c.bytes,c.size);
        unsigned expected=c.expected;
        if(c.relocated) {
            const unsigned delta=static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr))-0x400000u);
            expected+=delta;
            std::memcpy(expectedBytes+1,&expected,sizeof(expected));
        }
        const reiv::original::FunctionAddress binding{"pure game stub",c.rva,expectedBytes,c.size,reiv::original::BindingState::StaticVerified};
        const auto address=reiv::original::ResolveAddress(binding);
        if(!address) return 1;
        if(c.mask) {
            using Fn=unsigned(__cdecl*)();
            if((reinterpret_cast<Fn>(address)() & c.mask)!=expected) return 2;
        } else {
            using Fn=void(__cdecl*)();
            reinterpret_cast<Fn>(address)();
        }
        return 0;
    } __except(EXCEPTION_EXECUTE_HANDLER) { return 3; }
}
inline void Report(const char* phase) {
    FILE* f=nullptr;
    if(fopen_s(&f,hashprobe::GameFile("ReIV-game-stubs.json").c_str(),"wb") || !f) return;
    fprintf(f,"{\"phase\":\"%s\",\"exceptions\":%u,\"slots_checked\":%u,\"slots_failed\":%u,\"scope\":\"complete pure stub bodies only; slot audit is address-only; no class ABI or gameplay semantics established\",\"entries\":[",phase,exceptions,slotsChecked,slotsFailed);
    for(unsigned i=0;i<sizeof(candidates)/sizeof(candidates[0]);++i)
        fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"mask\":%u,\"expected\":%u}",i?",":"",candidates[i].rva,calls[i],failures[i],candidates[i].mask,candidates[i].expected);
    fprintf(f,"]}\n"); fclose(f);
}
inline void Initialize() {
    enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-stubs-test").c_str())!=INVALID_FILE_ATTRIBUTES;
    if(enabled) Report("waiting_for_game");
}
inline void Tick() {
    if(!enabled || done || !hashprobe::gameLoaded) return;
    done=true; unsigned failed=0;
    AuditSlots();
    for(unsigned i=0;i<sizeof(candidates)/sizeof(candidates[0]);++i) {
        for(unsigned n=0;n<64;++n) {
            ++calls[i]; const int result=Check(i);
            if(result) { ++failures[i]; ++failed; if(result==3) ++exceptions; break; }
        }
        REIV_INFO("Pure game stub RVA 0x%08X calls=%u failures=%u",candidates[i].rva,calls[i],failures[i]);
    }
    Report(failed?"failed":"passed");
}
}
