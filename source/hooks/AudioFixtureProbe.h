#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
namespace audiofixtures {
enum class Operation { address_offset,compare_u32,get_float,get_pair,get_u32,get_u8,identity_this,outputs_minus_one,set_pair,set_u32 };
struct Entry { reiv::original::FunctionAddress binding; Operation operation; unsigned offset; };
inline constexpr unsigned char bytes0[] = {0x8d,0x41,0x04,0xc3};
inline constexpr unsigned char bytes1[] = {0x8b,0x44,0x24,0x04,0x8b,0x4c,0x24,0x08,0xc7,0x00,0xff,0xff,0xff,0xff,0xc7,0x01,0xff,0xff,0xff,0xff,0xc2,0x08,0x00};
inline constexpr unsigned char bytes2[] = {0x8b,0x54,0x24,0x04,0x33,0xc0,0x3b,0x51,0x04,0x0f,0x94,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[] = {0x8b,0x44,0x24,0x04,0x89,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[] = {0xd9,0x41,0x20,0xc3};
inline constexpr unsigned char bytes5[] = {0x8b,0x41,0x34,0xc3};
inline constexpr unsigned char bytes6[] = {0x8b,0x54,0x24,0x04,0x33,0xc0,0x3b,0x51,0x30,0x0f,0x94,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes7[] = {0x8b,0x44,0x24,0x04,0x8b,0x54,0x24,0x08,0x89,0x41,0x38,0x89,0x51,0x3c,0xc2,0x08,0x00};
inline constexpr unsigned char bytes8[] = {0x8b,0x41,0x38,0x8b,0x54,0x24,0x04,0x89,0x02,0x8b,0x41,0x3c,0x8b,0x4c,0x24,0x08,0x89,0x01,0xc2,0x08,0x00};
inline constexpr unsigned char bytes9[] = {0x8b,0x41,0x24,0xc3};
inline constexpr unsigned char bytes10[] = {0x8b,0x41,0x28,0xc3};
inline constexpr unsigned char bytes11[] = {0xd9,0x41,0x2c,0xc3};
inline constexpr unsigned char bytes12[] = {0x8b,0xc1,0xc3};
inline constexpr unsigned char bytes13[] = {0x8b,0x44,0x24,0x04,0x89,0x41,0x34,0xc2,0x04,0x00};
inline constexpr unsigned char bytes14[] = {0x8b,0x81,0x20,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes15[] = {0x8b,0x44,0x24,0x04,0x89,0x81,0xa4,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes16[] = {0x8b,0x81,0x20,0x08,0x00,0x00,0xc3};
inline constexpr unsigned char bytes17[] = {0x8a,0x41,0x40,0xc3};
inline constexpr unsigned char bytes18[] = {0x8b,0x81,0x50,0x02,0x00,0x00,0xc3};
inline const Entry entries[] = {
{{"Audio fixture 0x004d8bc0",0x000d8bc0,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},Operation::address_offset,4},
{{"Audio fixture 0x008155a0",0x004155a0,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},Operation::outputs_minus_one,0},
{{"Audio fixture 0x008161d0",0x004161d0,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},Operation::compare_u32,4},
{{"Audio fixture 0x0089bbb0",0x0049bbb0,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},Operation::set_u32,8},
{{"Audio fixture 0x008b4d00",0x004b4d00,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},Operation::get_float,32},
{{"Audio fixture 0x008b4d10",0x004b4d10,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},Operation::get_u32,52},
{{"Audio fixture 0x008b4d20",0x004b4d20,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},Operation::compare_u32,48},
{{"Audio fixture 0x008b4d30",0x004b4d30,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},Operation::set_pair,56},
{{"Audio fixture 0x008b4d50",0x004b4d50,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},Operation::get_pair,56},
{{"Audio fixture 0x008b4d80",0x004b4d80,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},Operation::get_u32,36},
{{"Audio fixture 0x008b4d90",0x004b4d90,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},Operation::get_u32,40},
{{"Audio fixture 0x008b4da0",0x004b4da0,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},Operation::get_float,44},
{{"Audio fixture 0x00988ac0",0x00588ac0,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},Operation::identity_this,0},
{{"Audio fixture 0x00a2bd60",0x0062bd60,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},Operation::set_u32,52},
{{"Audio fixture 0x00aad200",0x006ad200,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},Operation::get_u32,288},
{{"Audio fixture 0x00ac7ba0",0x006c7ba0,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},Operation::set_u32,164},
{{"Audio fixture 0x00aec4d0",0x006ec4d0,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},Operation::get_u32,2080},
{{"Audio fixture 0x00c5d610",0x0085d610,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},Operation::get_u8,64},
{{"Audio fixture 0x00ccf450",0x008cf450,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},Operation::get_u32,592},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

int Check(unsigned i);
void Report(const char* phase);
void Tick();
void Initialize();
}

