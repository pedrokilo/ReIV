#include "ExtraStubsProbe.h"

namespace extrastubs {
int Check(unsigned i) {
    __try {
        auto address=reiv::original::ResolveAddress(bindings[i]); if(!address)return 1;
        // The full stub bodies ignore ECX and arguments. Explicit stack cleanup
        // is tested here; these aliases do not establish original class signatures.
        if(i==0){using F=void(__stdcall*)(unsigned,unsigned);reinterpret_cast<F>(address)(0,0);}
        else if(i==1||i==5){using F=void(__stdcall*)(unsigned);reinterpret_cast<F>(address)(0);}
        else if(i==2){using F=float(__cdecl*)();if(reinterpret_cast<F>(address)()!=1.0f)return 2;}
        else if(i==3){using F=unsigned char(__stdcall*)(unsigned,unsigned,unsigned);if(reinterpret_cast<F>(address)(0,0,0)!=0)return 2;}
        else if(i==4){using F=void(__stdcall*)(unsigned,unsigned,unsigned);reinterpret_cast<F>(address)(0,0,0);}
        else {using F=unsigned(__stdcall*)(unsigned,unsigned,unsigned,unsigned,unsigned);if(reinterpret_cast<F>(address)(0,0,0,0,0)!=0)return 2;}
        return 0;
    }__except(EXCEPTION_EXECUTE_HANDLER){return 3;}
}

void Report(const char* phase) {
    FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-extra-stubs.json").c_str(),"wb")||!f)return;
    fprintf(f,"{\"phase\":\"%s\",\"exceptions\":%u,\"scope\":\"pure stack-pop or float-return stub bodies only; class ABI unknown\",\"entries\":[",phase,exceptions);
    for(unsigned i=0;i<7;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u}",i?",":"",bindings[i].rva,calls[i],failures[i]);
    fprintf(f,"]}\n");fclose(f);
}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.extra-stubs-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

void Tick() {if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned total=0;
    for(unsigned i=0;i<7;++i){for(unsigned n=0;n<64;++n){++calls[i];int result=Check(i);if(result){++failures[i];++total;if(result==3)++exceptions;break;}}REIV_INFO("Extra pure stub RVA 0x%08X calls=%u failures=%u",bindings[i].rva,calls[i],failures[i]);}Report(total?"failed":"passed");}

} // namespace extrastubs
