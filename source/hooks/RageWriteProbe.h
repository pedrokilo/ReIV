#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
namespace ragewrites {
struct Entry { reiv::original::FunctionAddress binding; unsigned offset,width; };
inline constexpr unsigned char bytes0[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes1[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x84,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x70,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes5[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes6[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x07,0xc2,0x04,0x00};
inline const Entry entries[]={
{{"Rage write 0x00554660",0x00154660,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},32,1},
{{"Rage write 0x00554710",0x00154710,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},32,4},
{{"Rage write 0x0055de60",0x0015de60,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},388,4},
{{"Rage write 0x0056a9e0",0x0016a9e0,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},368,4},
{{"Rage write 0x0059b9c0",0x0019b9c0,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},8,4},
{{"Rage write 0x005aa230",0x001aa230,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},4,4},
{{"Rage write 0x006848f0",0x002848f0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},7,1},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

int Check(unsigned i,unsigned sample);
void Report(const char* phase);
void Tick();
void Initialize();
}

