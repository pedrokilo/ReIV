#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
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
int Check(unsigned i);
void Report(const char* phase);
void Initialize();
void Tick();
}
