#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
namespace artfixtures {
enum class Operation { address_offset,compare_u32,get_float,get_pair,get_u32,get_u8,identity_this,outputs_minus_one,set_pair,set_u32 };
struct Entry { reiv::original::FunctionAddress binding; Operation operation; unsigned offset; };
inline constexpr unsigned char bytes0[] = {0x8a,0x41,0x20,0xc3};
inline constexpr unsigned char bytes1[] = {0x8d,0x41,0x10,0xc3};
inline constexpr unsigned char bytes2[] = {0x8b,0x81,0x00,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes3[] = {0x8b,0x81,0x04,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes4[] = {0x8b,0x81,0x08,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes5[] = {0xd9,0x81,0x7c,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes6[] = {0xd9,0x81,0x84,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes7[] = {0xd9,0x81,0x88,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes8[] = {0xd9,0x81,0x8c,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes9[] = {0x8b,0x81,0x10,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes10[] = {0x8b,0x81,0xf0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes11[] = {0x8b,0x81,0xf4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes12[] = {0xd9,0x81,0x28,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes13[] = {0xd9,0x81,0x2c,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes14[] = {0xd9,0x81,0x30,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes15[] = {0xd9,0x81,0x34,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes16[] = {0x8a,0x41,0x68,0xc3};
inline constexpr unsigned char bytes17[] = {0x8a,0x81,0x01,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes18[] = {0x8a,0x81,0xc0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes19[] = {0x8a,0x81,0xac,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes20[] = {0x8a,0x41,0x6c,0xc3};
inline constexpr unsigned char bytes21[] = {0x8a,0x41,0x54,0xc3};
inline constexpr unsigned char bytes22[] = {0x8a,0x81,0xd5,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes23[] = {0x8a,0x81,0xb8,0x00,0x00,0x00,0xc3};
inline const Entry entries[] = {
{{"ART fixture 0x0044cb40",0x0004cb40,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},Operation::get_u8,32},
{{"ART fixture 0x005879b0",0x001879b0,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},Operation::address_offset,16},
{{"ART fixture 0x005e3570",0x001e3570,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},Operation::get_u32,256},
{{"ART fixture 0x005e3580",0x001e3580,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},Operation::get_u32,260},
{{"ART fixture 0x005e3590",0x001e3590,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},Operation::get_u32,264},
{{"ART fixture 0x005e35b0",0x001e35b0,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},Operation::get_float,380},
{{"ART fixture 0x005e35e0",0x001e35e0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},Operation::get_float,388},
{{"ART fixture 0x005e3610",0x001e3610,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},Operation::get_float,392},
{{"ART fixture 0x005e3640",0x001e3640,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},Operation::get_float,396},
{{"ART fixture 0x005ee880",0x001ee880,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},Operation::get_u32,272},
{{"ART fixture 0x005ee890",0x001ee890,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},Operation::get_u32,240},
{{"ART fixture 0x005ee8a0",0x001ee8a0,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},Operation::get_u32,244},
{{"ART fixture 0x005ee8b0",0x001ee8b0,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},Operation::get_float,296},
{{"ART fixture 0x005ee8e0",0x001ee8e0,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},Operation::get_float,300},
{{"ART fixture 0x005ee910",0x001ee910,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},Operation::get_float,304},
{{"ART fixture 0x005ee940",0x001ee940,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},Operation::get_float,308},
{{"ART fixture 0x005efd40",0x001efd40,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},Operation::get_u8,104},
{{"ART fixture 0x005f03b0",0x001f03b0,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},Operation::get_u8,257},
{{"ART fixture 0x005ff420",0x001ff420,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},Operation::get_u8,192},
{{"ART fixture 0x006038e0",0x002038e0,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},Operation::get_u8,172},
{{"ART fixture 0x00604060",0x00204060,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},Operation::get_u8,108},
{{"ART fixture 0x00606880",0x00206880,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},Operation::get_u8,84},
{{"ART fixture 0x0060b000",0x0020b000,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},Operation::get_u8,213},
{{"ART fixture 0x0060f090",0x0020f090,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},Operation::get_u8,184},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

int Check(unsigned i);
void Report(const char* phase);
void Tick();
void Initialize();
}

