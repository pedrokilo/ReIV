#pragma once
namespace extrastubs {
inline constexpr unsigned char ret8[]={0xc2,8,0},ret4[]={0xc2,4,0},float1[]={0xd9,0xe8,0xc3},false12[]={0x32,0xc0,0xc2,12,0},ret12[]={0xc2,12,0},zero20[]={0x33,0xc0,0xc2,20,0};
inline const reiv::original::FunctionAddress bindings[]={
{"RET8 stub",0x52c4d0,ret8,sizeof(ret8),reiv::original::BindingState::StaticVerified},
{"RET4 stub",0x6aaf20,ret4,sizeof(ret4),reiv::original::BindingState::StaticVerified},
{"Float1 stub",0x887a50,float1,sizeof(float1),reiv::original::BindingState::StaticVerified},
{"False RET12 stub",0x47970,false12,sizeof(false12),reiv::original::BindingState::StaticVerified},
{"RET12 stub",0x91800,ret12,sizeof(ret12),reiv::original::BindingState::StaticVerified},
{"RET4 stub",0x150ff0,ret4,sizeof(ret4),reiv::original::BindingState::StaticVerified},
{"Zero RET20 stub",0x5c80b0,zero20,sizeof(zero20),reiv::original::BindingState::StaticVerified}
};
inline unsigned calls[7]{},failures[7]{},exceptions=0;
inline bool enabled=false,done=false;
inline int Check(unsigned i) {
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
inline void Report(const char* phase){
    FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-extra-stubs.json").c_str(),"wb")||!f)return;
    fprintf(f,"{\"phase\":\"%s\",\"exceptions\":%u,\"scope\":\"pure stack-pop or float-return stub bodies only; class ABI unknown\",\"entries\":[",phase,exceptions);
    for(unsigned i=0;i<7;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u}",i?",":"",bindings[i].rva,calls[i],failures[i]);
    fprintf(f,"]}\n");fclose(f);
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.extra-stubs-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
inline void Tick(){if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned total=0;
    for(unsigned i=0;i<7;++i){for(unsigned n=0;n<64;++n){++calls[i];int result=Check(i);if(result){++failures[i];++total;if(result==3)++exceptions;break;}}REIV_INFO("Extra pure stub RVA 0x%08X calls=%u failures=%u",bindings[i].rva,calls[i],failures[i]);}Report(total?"failed":"passed");}
}
