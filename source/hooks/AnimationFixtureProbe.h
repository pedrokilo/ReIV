#pragma once
#include <cstring>
// Exact assembly-derived ABI tests on isolated storage; no hooks are installed.
namespace animationfixtures {
inline bool enabled=false,done=false;
inline unsigned calls[7]{},failures[7]{},exceptions=0;
#include "AnimationFixtureBindings.h"
inline int Check(unsigned index,unsigned sample) {
    __try {
        auto address=reiv::original::ResolveAddress(bindings[index]);
        if(!address) return 1;
        alignas(16) unsigned words[32]{};
        alignas(16) unsigned parent[32]{};
        const unsigned seed=0x12345678u+sample;
        using Getter=unsigned(__thiscall*)(void*);
        using Action=void(__thiscall*)(void*);
        if(index==0) {
            words[1]=seed;
            reinterpret_cast<Action>(address)(words);
            return words[1]==seed+1?0:2;
        }
        if(index==1) {
            words[1]=seed; // Nonzero after decrement: never enters destructor branch.
            unsigned result=reinterpret_cast<Getter>(address)(words);
            return result==seed-1&&words[1]==seed-1?0:2;
        }
        if(index==2) {
            words[2]=seed;
            return reinterpret_cast<Getter>(address)(words)==seed?0:2;
        }
        if(index==3) {
            words[9]=seed;
            using Setter=void(__thiscall*)(void*,unsigned);
            reinterpret_cast<Setter>(address)(words,sample&1);
            return words[9]==((seed&~0x20u)|((sample&1)<<5))?0:2;
        }
        if(index==4) {
            words[9]=(sample&1)?0x04000000u:0;
            words[14]=seed;
            return reinterpret_cast<Getter>(address)(words)==((sample&1)?seed:0)?0:2;
        }
        if(index==5) {
            float vector[4]={1.25f,-2.5f,3.75f,4.5f},output[4]{};
            if(sample&1) { words[8]=reinterpret_cast<unsigned>(parent);memcpy(parent+12,vector,16); }
            else memcpy(words+4,vector,16);
            using ReadVector=void(__thiscall*)(void*,float*);
            reinterpret_cast<ReadVector>(address)(words,output);
            return memcmp(output,vector,16)==0?0:2;
        }
        words[2]=seed;
        unsigned output=0;
        using ReadWithSize=unsigned(__thiscall*)(void*,unsigned*);
        return reinterpret_cast<ReadWithSize>(address)(words,&output)==seed&&output==128?0:2;
    } __except(EXCEPTION_EXECUTE_HANDLER) { return 3; }
}
inline void Report(const char* phase) {
    FILE* file=nullptr;
    if(fopen_s(&file,hashprobe::GameFile("ReIV-animation-fixtures.json").c_str(),"wb")||!file) return;
    fprintf(file,"{\"phase\":\"%s\",\"exceptions\":%u,\"entries\":[",phase,exceptions);
    for(unsigned i=0;i<7;++i) fprintf(file,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",bindings[i].rva,calls[i],failures[i],failures[i]?"true":"false");
    fprintf(file,"]}\n");fclose(file);
}
inline void Initialize() {
    enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.animation-fixtures-test").c_str())!=INVALID_FILE_ATTRIBUTES;
    if(enabled) Report("waiting_for_game");
}
inline void Tick() {
    if(!enabled||done||!hashprobe::gameLoaded) return;
    done=true;unsigned total=0;
    for(unsigned i=0;i<7;++i) {
        for(unsigned n=0;n<64;++n) {
            ++calls[i];int result=Check(i,n);
            if(result) { ++failures[i];++total;if(result==3) ++exceptions;break; }
        }
        REIV_INFO("Animation fixture RVA 0x%08X calls=%u failures=%u",bindings[i].rva,calls[i],failures[i]);
    }
    Report(total?"failed":"passed");
}
}
