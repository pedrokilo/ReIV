#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
namespace ragefixtures {
enum class Operation { address_offset,compare_u32,get_float,get_pair,get_u32,get_u8,identity_this,outputs_minus_one,set_pair,set_u32 };
struct Entry { reiv::original::FunctionAddress binding; Operation operation; unsigned offset; };
inline constexpr unsigned char bytes0[] = {0x8b,0x81,0xa0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes1[] = {0xd9,0x41,0x10,0xc3};
inline constexpr unsigned char bytes2[] = {0x8b,0x41,0x30,0xc3};
inline constexpr unsigned char bytes3[] = {0x8d,0x41,0x10,0xc3};
inline constexpr unsigned char bytes4[] = {0x8d,0x41,0x08,0xc3};
inline constexpr unsigned char bytes5[] = {0x8d,0x41,0x04,0xc3};
inline constexpr unsigned char bytes6[] = {0x8b,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes7[] = {0x8d,0x81,0x30,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes8[] = {0x8d,0x81,0x28,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes9[] = {0xd9,0x41,0x0c,0xc3};
inline constexpr unsigned char bytes10[] = {0x8b,0x81,0x24,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes11[] = {0xd9,0x81,0x14,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes12[] = {0x8b,0x81,0x14,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes13[] = {0x8b,0x81,0xb4,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes14[] = {0x8b,0x81,0xe0,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes15[] = {0x8d,0x41,0x10,0xc3};
inline constexpr unsigned char bytes16[] = {0x8b,0x41,0x10,0xc3};
inline constexpr unsigned char bytes17[] = {0x8b,0x41,0x08,0xc3};
inline constexpr unsigned char bytes18[] = {0x8b,0x81,0x98,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes19[] = {0x8b,0x41,0x0c,0xc3};
inline constexpr unsigned char bytes20[] = {0x8b,0x41,0x04,0xc3};
inline constexpr unsigned char bytes21[] = {0x8a,0x81,0x4f,0x04,0x00,0x00,0xc3};
inline constexpr unsigned char bytes22[] = {0x8b,0x41,0x14,0xc3};
inline constexpr unsigned char bytes23[] = {0x8a,0x41,0x4c,0xc3};
inline constexpr unsigned char bytes24[] = {0x8b,0x41,0x4c,0xc3};
inline constexpr unsigned char bytes25[] = {0x8b,0x41,0x50,0xc3};
inline constexpr unsigned char bytes26[] = {0x8b,0x41,0x58,0xc3};
inline constexpr unsigned char bytes27[] = {0x8b,0x41,0x38,0xc3};
inline constexpr unsigned char bytes28[] = {0x8a,0x41,0x07,0xc3};
inline constexpr unsigned char bytes29[] = {0xd9,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes30[] = {0xd9,0x41,0x20,0xc3};
inline constexpr unsigned char bytes31[] = {0x8d,0x41,0x30,0xc3};
inline constexpr unsigned char bytes32[] = {0x8d,0x41,0x40,0xc3};
inline constexpr unsigned char bytes33[] = {0xd9,0x41,0x24,0xc3};
inline constexpr unsigned char bytes34[] = {0xd9,0x41,0x28,0xc3};
inline constexpr unsigned char bytes35[] = {0xd9,0x41,0x2c,0xc3};
inline constexpr unsigned char bytes36[] = {0x8a,0x81,0xf0,0x0b,0x00,0x00,0xc3};
inline constexpr unsigned char bytes37[] = {0x8b,0x41,0x08,0xc3};
inline constexpr unsigned char bytes38[] = {0x8b,0x81,0xc4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes39[] = {0x8b,0x81,0xc0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes40[] = {0x8d,0x81,0xd0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes41[] = {0x8d,0x81,0x11,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes42[] = {0x8b,0x81,0xc8,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes43[] = {0x8b,0x41,0x74,0xc3};
inline const Entry entries[] = {
{{"Rage fixture 0x004353e0",0x000353e0,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},Operation::get_u32,160},
{{"Rage fixture 0x00435690",0x00035690,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},Operation::get_float,16},
{{"Rage fixture 0x0045aa90",0x0005aa90,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},Operation::get_u32,48},
{{"Rage fixture 0x004c5970",0x000c5970,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},Operation::address_offset,16},
{{"Rage fixture 0x004d8bb0",0x000d8bb0,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},Operation::address_offset,8},
{{"Rage fixture 0x004d8bc0",0x000d8bc0,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},Operation::address_offset,4},
{{"Rage fixture 0x0050ba50",0x0010ba50,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},Operation::get_u32,28},
{{"Rage fixture 0x00534ef0",0x00134ef0,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},Operation::address_offset,560},
{{"Rage fixture 0x0055a830",0x0015a830,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},Operation::address_offset,296},
{{"Rage fixture 0x0055a840",0x0015a840,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},Operation::get_float,12},
{{"Rage fixture 0x0055a870",0x0015a870,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},Operation::get_u32,292},
{{"Rage fixture 0x0055a8f0",0x0015a8f0,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},Operation::get_float,276},
{{"Rage fixture 0x00567160",0x00167160,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},Operation::get_u32,276},
{{"Rage fixture 0x00567d10",0x00167d10,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},Operation::get_u32,436},
{{"Rage fixture 0x00567d20",0x00167d20,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},Operation::get_u32,480},
{{"Rage fixture 0x005879b0",0x001879b0,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},Operation::address_offset,16},
{{"Rage fixture 0x0058c5f0",0x0018c5f0,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},Operation::get_u32,16},
{{"Rage fixture 0x0059bc50",0x0019bc50,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},Operation::get_u32,8},
{{"Rage fixture 0x005a9f50",0x001a9f50,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},Operation::get_u32,152},
{{"Rage fixture 0x005aa210",0x001aa210,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},Operation::get_u32,12},
{{"Rage fixture 0x005aa220",0x001aa220,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},Operation::get_u32,4},
{{"Rage fixture 0x005b57a0",0x001b57a0,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},Operation::get_u8,1103},
{{"Rage fixture 0x0062a2b0",0x0022a2b0,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},Operation::get_u32,20},
{{"Rage fixture 0x0062a330",0x0022a330,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},Operation::get_u8,76},
{{"Rage fixture 0x006335e0",0x002335e0,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},Operation::get_u32,76},
{{"Rage fixture 0x006335f0",0x002335f0,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},Operation::get_u32,80},
{{"Rage fixture 0x00634cc0",0x00234cc0,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},Operation::get_u32,88},
{{"Rage fixture 0x0064eda0",0x0024eda0,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},Operation::get_u32,56},
{{"Rage fixture 0x00684900",0x00284900,bytes28,sizeof(bytes28),reiv::original::BindingState::StaticVerified},Operation::get_u8,7},
{{"Rage fixture 0x006bf250",0x002bf250,bytes29,sizeof(bytes29),reiv::original::BindingState::StaticVerified},Operation::get_float,28},
{{"Rage fixture 0x006bf260",0x002bf260,bytes30,sizeof(bytes30),reiv::original::BindingState::StaticVerified},Operation::get_float,32},
{{"Rage fixture 0x006bf270",0x002bf270,bytes31,sizeof(bytes31),reiv::original::BindingState::StaticVerified},Operation::address_offset,48},
{{"Rage fixture 0x006bf280",0x002bf280,bytes32,sizeof(bytes32),reiv::original::BindingState::StaticVerified},Operation::address_offset,64},
{{"Rage fixture 0x006bf290",0x002bf290,bytes33,sizeof(bytes33),reiv::original::BindingState::StaticVerified},Operation::get_float,36},
{{"Rage fixture 0x006bf2a0",0x002bf2a0,bytes34,sizeof(bytes34),reiv::original::BindingState::StaticVerified},Operation::get_float,40},
{{"Rage fixture 0x006bf2b0",0x002bf2b0,bytes35,sizeof(bytes35),reiv::original::BindingState::StaticVerified},Operation::get_float,44},
{{"Rage fixture 0x0070bb90",0x0030bb90,bytes36,sizeof(bytes36),reiv::original::BindingState::StaticVerified},Operation::get_u8,3056},
{{"Rage fixture 0x00be61f0",0x007e61f0,bytes37,sizeof(bytes37),reiv::original::BindingState::StaticVerified},Operation::get_u32,8},
{{"Rage fixture 0x00cf5b80",0x008f5b80,bytes38,sizeof(bytes38),reiv::original::BindingState::StaticVerified},Operation::get_u32,196},
{{"Rage fixture 0x00cf5bc0",0x008f5bc0,bytes39,sizeof(bytes39),reiv::original::BindingState::StaticVerified},Operation::get_u32,192},
{{"Rage fixture 0x00cf5f30",0x008f5f30,bytes40,sizeof(bytes40),reiv::original::BindingState::StaticVerified},Operation::address_offset,208},
{{"Rage fixture 0x00cf5f40",0x008f5f40,bytes41,sizeof(bytes41),reiv::original::BindingState::StaticVerified},Operation::address_offset,273},
{{"Rage fixture 0x00cfb460",0x008fb460,bytes42,sizeof(bytes42),reiv::original::BindingState::StaticVerified},Operation::get_u32,200},
{{"Rage fixture 0x00cfb7c0",0x008fb7c0,bytes43,sizeof(bytes43),reiv::original::BindingState::StaticVerified},Operation::get_u32,116},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

int Check(unsigned i);
void Report(const char* phase);
void Tick();
void Initialize();
}

