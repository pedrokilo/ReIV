#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
namespace artextras {
enum Operation { and_u8,bit_u8,echo_u8_pop4,return_minus_one,return_one_pop4,zero_output3,zero_pair,zero_u32 };
struct Entry { reiv::original::FunctionAddress binding; Operation op; unsigned offset,arg; };
inline constexpr unsigned char bytes0[]={0x83,0xc8,0xff,0xc3};
inline constexpr unsigned char bytes1[]={0xb0,0x01,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0x8a,0x44,0x24,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[]={0xc7,0x81,0xe4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes4[]={0x80,0xa1,0xe8,0x00,0x00,0x00,0xe7,0xc3};
inline constexpr unsigned char bytes5[]={0x33,0xc0,0x89,0x41,0x0c,0x89,0x41,0x10,0xc3};
inline constexpr unsigned char bytes6[]={0x8b,0x44,0x24,0x04,0x0f,0x57,0xc0,0xf3,0x0f,0x11,0x40,0x08,0xf3,0x0f,0x11,0x40,0x04,0xf3,0x0f,0x11,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes7[]={0x8a,0x81,0xe8,0x00,0x00,0x00,0xd0,0xe8,0x24,0x01,0xc3};
inline constexpr unsigned char bytes8[]={0x8a,0x81,0x7c,0x02,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes9[]={0x8a,0x81,0x44,0x01,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes10[]={0x8a,0x81,0xfc,0x0b,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes11[]={0x8a,0x81,0xa8,0x00,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes12[]={0x8a,0x81,0x98,0x00,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes13[]={0x8a,0x81,0xb4,0x00,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes14[]={0x8a,0x81,0x90,0x00,0x00,0x00,0x24,0x01,0xc3};
inline constexpr unsigned char bytes15[]={0x8a,0x81,0x8c,0x00,0x00,0x00,0x24,0x01,0xc3};
inline const Entry entries[]={
{{"ART extra 0x004ee420",0x000ee420,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},return_minus_one,0,0},
{{"ART extra 0x00784520",0x00384520,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},return_one_pop4,0,0},
{{"ART extra 0x005fdd00",0x001fdd00,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},echo_u8_pop4,0,0},
{{"ART extra 0x005e39e0",0x001e39e0,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},zero_u32,228,0},
{{"ART extra 0x005e6340",0x001e6340,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},and_u8,232,231},
{{"ART extra 0x005efc70",0x001efc70,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},zero_pair,12,0},
{{"ART extra 0x00686be0",0x00286be0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},zero_output3,0,0},
{{"ART extra 0x005e35a0",0x001e35a0,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},bit_u8,232,1},
{{"ART extra 0x005f1e70",0x001f1e70,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},bit_u8,636,0},
{{"ART extra 0x005f3ce0",0x001f3ce0,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},bit_u8,324,0},
{{"ART extra 0x005f76a0",0x001f76a0,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},bit_u8,3068,0},
{{"ART extra 0x00600200",0x00200200,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},bit_u8,168,0},
{{"ART extra 0x00602440",0x00202440,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},bit_u8,152,0},
{{"ART extra 0x00605870",0x00205870,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},bit_u8,180,0},
{{"ART extra 0x00605fe0",0x00205fe0,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},bit_u8,144,0},
{{"ART extra 0x00608760",0x00208760,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},bit_u8,140,0},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

int Check(unsigned i,unsigned sample);
void Report(const char* phase);
void Tick();
void Initialize();
}

