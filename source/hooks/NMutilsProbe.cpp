#include "NMutilsProbe.h"

namespace nmprobe {
void __fastcall Capture(void*, void*, unsigned level, const wchar_t* text) {
    ++callbackCalls; callbackLevel = level;
    wcsncpy_s(callbackText, text, _TRUNCATE);
}

void Report(const char* phase) {
    FILE* f = nullptr;
    if (fopen_s(&f, hashprobe::GameFile("ReIV-NMutils.json").c_str(), "wb") || !f) return;
    const unsigned rvas[] = {0x1d4f40,0x1d67f0,0x1210,0x1d67a0,0x1e1600,0x1e1820};
    fprintf(f,"{\"phase\":\"%s\",\"exceptions\":%u,\"entries\":[",phase,exceptions);
    for (unsigned i=0;i<6;++i) fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",rvas[i],calls[i],failures[i],i==2?"true":"false");
    fprintf(f,"]}\n"); fclose(f);
}

int Check(unsigned i) {
    __try {
        const auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr));
        auto address = reiv::original::ResolveAddress(bindings[i]);
        if (!address) return 1;
        alignas(4) unsigned char object[128]{};
        alignas(4) unsigned char parent[128]{};
        auto words = reinterpret_cast<std::uintptr_t*>(object);
        if (i==0 || i==4 || i==5) {
            if (i==5) { words[1]=reinterpret_cast<std::uintptr_t>(parent); *reinterpret_cast<void**>(parent+0x34)=object; }
            using Dtor = void*(__thiscall*)(void*,unsigned);
            if (reinterpret_cast<Dtor>(address)(object,0)!=object) return 2;
            const unsigned vt = i==0?0xaba548:i==4?0xaba6d0:0xaba6c8;
            if (words[0]!=base+vt) return 3;
            if (i==5 && *reinterpret_cast<void**>(parent+0x34)!=nullptr) return 4;
        } else {
            std::uintptr_t table[4]{};
            table[2]=reinterpret_cast<std::uintptr_t>(&Capture);
            words[0]=reinterpret_cast<std::uintptr_t>(table);
            callbackCalls=0; callbackLevel=0; callbackText[0]=0;
            if(i==1) {
                using Log = void(__thiscall*)(void*,unsigned,const char*);
                reinterpret_cast<Log>(address)(object,3,"ReIV NMutils 42");
            } else {
                using Logf = void(__cdecl*)(void*,unsigned,const wchar_t*,...);
                reinterpret_cast<Logf>(address)(object,3,L"ReIV NMutils %d",42);
            }
            if(callbackCalls!=1 || callbackLevel!=3 || wcscmp(callbackText,L"ReIV NMutils 42")) return 5;
        }
        return 0;
    } __except(EXCEPTION_EXECUTE_HANDLER) { return 6; }
}

void Tick() {
    if (!enabled || done || !hashprobe::gameLoaded) return;
    done=true;
    unsigned totalFailures=0;
    for(unsigned i=0;i<6;++i) {
        if(i==2) { REIV_INFO("NMutils RVA 0x00001210 disabled: fatal assertion handler"); continue; }
        for(unsigned n=0;n<64;++n) {
            ++calls[i]; const int result=Check(i);
            if(result) { ++failures[i]; ++totalFailures; if(result==6) ++exceptions; break; }
        }
        REIV_INFO("NMutils RVA 0x%08X synthetic test calls=%u failures=%u",bindings[i].rva,calls[i],failures[i]);
    }
    Report(totalFailures?"failed":"passed");
}

void Initialize() {
    enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.nmutils-test").c_str())!=INVALID_FILE_ATTRIBUTES;
    if(enabled) Report("waiting_for_game");
}

} // namespace nmprobe
