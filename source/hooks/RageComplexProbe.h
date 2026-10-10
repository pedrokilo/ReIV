#pragma once
#include <cstring>
namespace ragecomplex {
struct Entry { reiv::original::FunctionAddress binding; unsigned pop; bool floating; unsigned mask; };
inline constexpr unsigned char bytes0[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x03,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x01,0x75,0x1f,0xb8,0x0f,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0e,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes1[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x03,0x7f,0x21,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x01,0x75,0x1c,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0x8b,0x44,0x24,0x04,0x3b,0x41,0x08,0x73,0x0c,0x69,0xc0,0x60,0x01,0x00,0x00,0x03,0x41,0x0c,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x03,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x01,0x75,0x1f,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x3e,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x03,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x01,0x75,0x1f,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes5[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x02,0x75,0x1f,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes6[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x1f,0x74,0x15,0x83,0xe8,0x01,0x74,0x08,0x83,0xe8,0x02,0x75,0x1a,0xc2,0x04,0x00,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes7[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x05,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x02,0x75,0x1f,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes8[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x05,0x7f,0x21,0x74,0x17,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x02,0x75,0x1c,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes9[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x02,0x75,0x1f,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes10[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x21,0x74,0x17,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x02,0x75,0x1c,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes11[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x07,0x7f,0x1f,0x74,0x15,0x83,0xe8,0x01,0x74,0x08,0x83,0xe8,0x05,0x75,0x1f,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x04,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes12[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x07,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x05,0x75,0x24,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x1d,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes13[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x07,0x7f,0x21,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x05,0x75,0x21,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00,0x33,0xc0,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x04,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes14[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x07,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x05,0x75,0x24,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x1d,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes15[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x24,0x74,0x1a,0x83,0xe8,0x01,0x74,0x0d,0x83,0xe8,0x04,0x75,0x24,0xb8,0x26,0x00,0x00,0x10,0xc2,0x04,0x00,0xb8,0x1d,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x27,0x00,0x00,0x10,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x37,0x00,0x00,0x20,0xc2,0x04,0x00,0xb8,0x0d,0x00,0x00,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes16[]={0x8b,0x44,0x24,0x04,0x83,0xf8,0x06,0x7f,0x1f,0x74,0x15,0x83,0xe8,0x01,0x74,0x08,0x83,0xe8,0x04,0x75,0x1f,0xc2,0x04,0x00,0xb8,0x03,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x01,0x00,0x00,0x00,0xc2,0x04,0x00,0x83,0xf8,0x08,0x74,0x15,0x3d,0xfe,0xff,0x00,0x00,0x74,0x06,0x83,0xc8,0xff,0xc2,0x04,0x00,0xb8,0x04,0x00,0x00,0x00,0xc2,0x04,0x00,0xb8,0x02,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes17[]={0x8a,0x41,0x08,0xa8,0x02,0x75,0x0b,0xa8,0x01,0x74,0x07,0x24,0xfb,0x0c,0x02,0x88,0x41,0x08,0xc3};
inline constexpr unsigned char bytes18[]={0x8a,0x41,0x08,0xa8,0x02,0xc7,0x41,0x1c,0x00,0x00,0x00,0x00,0x75,0x0b,0xa8,0x01,0x74,0x07,0x24,0xfb,0x0c,0x02,0x88,0x41,0x08,0xc3};
inline constexpr unsigned char bytes19[]={0x33,0xc0,0x39,0x41,0x14,0x89,0x81,0x34,0x0c,0x00,0x00,0x74,0x0c,0x8b,0x51,0x04,0x89,0x51,0x10,0x8b,0x51,0x20,0x89,0x51,0x24,0x89,0x41,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes20[]={0x83,0x79,0x04,0x00,0x75,0x12,0x83,0xb9,0x34,0x0c,0x00,0x00,0x00,0x75,0x09,0x83,0x79,0x0c,0x00,0x75,0x03,0x33,0xc0,0xc3,0xb8,0x01,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes21[]={0x8b,0x44,0x24,0x04,0x33,0xd2,0x39,0x41,0x0c,0x75,0x03,0x89,0x51,0x0c,0x39,0x41,0x10,0x75,0x03,0x89,0x51,0x10,0x39,0x41,0x04,0x75,0x03,0x89,0x51,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes22[]={0x8b,0x41,0x48,0x85,0xc0,0x75,0x05,0xb8,0x01,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes23[]={0x8a,0x44,0x24,0x04,0x38,0x41,0x3c,0x74,0x08,0x88,0x41,0x3c,0xb0,0x01,0xc2,0x04,0x00,0x32,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes24[]={0x8b,0x44,0x24,0x04,0x85,0xc0,0x75,0x06,0x8d,0x41,0x60,0xc2,0x04,0x00,0x83,0xf8,0x01,0x75,0x06,0x8d,0x41,0x70,0xc2,0x04,0x00,0xc1,0xe0,0x06,0x8d,0x44,0x08,0x50,0xc2,0x04,0x00};
inline constexpr unsigned char bytes25[]={0x8b,0x44,0x24,0x04,0x85,0xc0,0x75,0x06,0x8d,0x41,0x40,0xc2,0x04,0x00,0x83,0xf8,0x01,0x75,0x06,0x8d,0x41,0x50,0xc2,0x04,0x00,0xc1,0xe0,0x06,0x8d,0x44,0x08,0x60,0xc2,0x04,0x00};
inline constexpr unsigned char bytes26[]={0x8d,0x81,0x40,0x01,0x00,0x00,0x85,0xc0,0x74,0x07,0x8d,0x81,0x50,0x01,0x00,0x00,0xc3,0x33,0xc0,0xc3};
inline constexpr unsigned char bytes27[]={0x8a,0x41,0x08,0xa8,0x02,0xc7,0x81,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x75,0x0b,0xa8,0x01,0x74,0x07,0x24,0xfb,0x0c,0x02,0x88,0x41,0x08,0xc3};
inline constexpr unsigned char bytes28[]={0x8a,0x41,0x08,0xa8,0x02,0xc7,0x41,0x10,0x00,0x00,0x00,0x00,0x75,0x0b,0xa8,0x01,0x74,0x07,0x24,0xfb,0x0c,0x02,0x88,0x41,0x08,0xc3};
inline const Entry entries[]={
{{"Rage complete CFG 0x004CA290",0x000CA290,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CA440",0x000CA440,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CA6E0",0x000CA6E0,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CD2F0",0x000CD2F0,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CD4B0",0x000CD4B0,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CD810",0x000CD810,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CD9C0",0x000CD9C0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CDBC0",0x000CDBC0,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CDC20",0x000CDC20,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CDDD0",0x000CDDD0,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CDE30",0x000CDE30,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CE620",0x000CE620,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CE890",0x000CE890,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CE900",0x000CE900,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CEAE0",0x000CEAE0,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CEC30",0x000CEC30,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x004CEC90",0x000CEC90,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x0053BE10",0x0013BE10,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Rage complete CFG 0x0057A170",0x0017A170,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Rage complete CFG 0x005C9680",0x001C9680,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x005C9700",0x001C9700,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Rage complete CFG 0x005C9830",0x001C9830,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x0062C8E0",0x0022C8E0,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Rage complete CFG 0x0065FB10",0x0025FB10,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},4,false,0x000000ffu},
{{"Rage complete CFG 0x0070D5F0",0x0030D5F0,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x0070D620",0x0030D620,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Rage complete CFG 0x0070DE40",0x0030DE40,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Rage complete CFG 0x007756F0",0x003756F0,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Rage complete CFG 0x00775B20",0x00375B20,bytes28,sizeof(bytes28),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline unsigned long long visited[count]{};
inline unsigned Load(const unsigned char* p,unsigned n){unsigned v=0;memcpy(&v,p,n);return v;}
inline void Store(unsigned char* p,unsigned n,unsigned v){memcpy(p,&v,n);}
inline void LogicFlags(unsigned a,unsigned n,bool& z,bool& s,bool& v,bool& c){unsigned mask=n==4?0xffffffffu:(1u<<(n*8))-1;unsigned sign=1u<<(n*8-1);a&=mask;z=!a;s=(a&sign)!=0;v=c=false;}
inline void Flags(unsigned a,unsigned b,unsigned n,bool test,bool& z,bool& s,bool& v,bool& c){if(test){LogicFlags(a&b,n,z,s,v,c);return;}unsigned mask=n==4?0xffffffffu:(1u<<(n*8))-1;unsigned sign=1u<<(n*8-1);a&=mask;b&=mask;unsigned r=(a-b)&mask;z=!r;s=(r&sign)!=0;c=a<b;v=((a^b)&(a^r)&sign)!=0;}
inline unsigned Expected0(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=0;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000003u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x1000000fu);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x1000000eu);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x2000000du);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0x20000037u);goto L63;
L63: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected1(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=1;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000003u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L42;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L49;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x00000002u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x00000001u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0);z=true;s=v=c=false;goto L39;
L39: visited[index]|=1ull<<13; return eax;
L42: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L47;
L47: visited[index]|=1ull<<15; if(z)goto L55;goto L49;
L49: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L52;
L52: visited[index]|=1ull<<17; return eax;
L55: visited[index]|=1ull<<18; eax=(0x00000003u);goto L60;
L60: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected2(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=2;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,Load(expected+8,4),4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!c)goto L21;goto L9;
L9: visited[index]|=1ull<<3; eax=((eax)*(0x00000160u));goto L15;
L15: visited[index]|=1ull<<4; eax=((eax)+(Load(expected+12,4)));goto L18;
L18: visited[index]|=1ull<<5; return eax;
L21: visited[index]|=1ull<<6; eax=(0);z=true;s=v=c=false;goto L23;
L23: visited[index]|=1ull<<7; return eax;
}
inline unsigned Expected3(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=3;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000003u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000027u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x10000026u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x2000000du);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0x2000003eu);goto L63;
L63: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected4(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=4;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000003u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x00000003u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x00000002u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x00000001u);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0);z=true;s=v=c=false;goto L60;
L60: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected5(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=5;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000026u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x10000027u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x2000000du);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0x20000037u);goto L63;
L63: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected6(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=6;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L40;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L32;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L24;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L47;goto L21;
L21: visited[index]|=1ull<<8; return eax;
L24: visited[index]|=1ull<<9; eax=(0x00000001u);goto L29;
L29: visited[index]|=1ull<<10; return eax;
L32: visited[index]|=1ull<<11; eax=(0x00000002u);goto L37;
L37: visited[index]|=1ull<<12; return eax;
L40: visited[index]|=1ull<<13; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L45;
L45: visited[index]|=1ull<<14; if(z)goto L53;goto L47;
L47: visited[index]|=1ull<<15; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L50;
L50: visited[index]|=1ull<<16; return eax;
L53: visited[index]|=1ull<<17; eax=(0x00000003u);goto L58;
L58: visited[index]|=1ull<<18; return eax;
}
inline unsigned Expected7(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=7;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000005u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000027u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x10000026u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x2000000du);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0x20000037u);goto L63;
L63: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected8(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=8;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000005u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L42;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L34;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L49;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x00000001u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0);z=true;s=v=c=false;goto L31;
L31: visited[index]|=1ull<<11; return eax;
L34: visited[index]|=1ull<<12; eax=(0x00000002u);goto L39;
L39: visited[index]|=1ull<<13; return eax;
L42: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L47;
L47: visited[index]|=1ull<<15; if(z)goto L55;goto L49;
L49: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L52;
L52: visited[index]|=1ull<<17; return eax;
L55: visited[index]|=1ull<<18; eax=(0x00000003u);goto L60;
L60: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected9(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=9;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000027u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x10000026u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x2000000du);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<15; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<17; return eax;
L58: visited[index]|=1ull<<18; eax=(0x20000037u);goto L63;
L63: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected10(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=10;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L42;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L34;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000002u,4,false,z,s,v,c);eax=((eax)-(0x00000002u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L49;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x00000001u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0);z=true;s=v=c=false;goto L31;
L31: visited[index]|=1ull<<11; return eax;
L34: visited[index]|=1ull<<12; eax=(0x00000002u);goto L39;
L39: visited[index]|=1ull<<13; return eax;
L42: visited[index]|=1ull<<14; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L47;
L47: visited[index]|=1ull<<15; if(z)goto L55;goto L49;
L49: visited[index]|=1ull<<16; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L52;
L52: visited[index]|=1ull<<17; return eax;
L55: visited[index]|=1ull<<18; eax=(0x00000003u);goto L60;
L60: visited[index]|=1ull<<19; return eax;
}
inline unsigned Expected11(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=11;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000007u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L40;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L32;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L24;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000005u,4,false,z,s,v,c);eax=((eax)-(0x00000005u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; return eax;
L24: visited[index]|=1ull<<9; eax=(0x00000003u);goto L29;
L29: visited[index]|=1ull<<10; return eax;
L32: visited[index]|=1ull<<11; eax=(0x00000001u);goto L37;
L37: visited[index]|=1ull<<12; return eax;
L40: visited[index]|=1ull<<13; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L43;
L43: visited[index]|=1ull<<14; if(z)goto L66;goto L45;
L45: visited[index]|=1ull<<15; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<16; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<17; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<18; return eax;
L58: visited[index]|=1ull<<19; eax=(0x00000004u);goto L63;
L63: visited[index]|=1ull<<20; return eax;
L66: visited[index]|=1ull<<21; eax=(0x00000002u);goto L71;
L71: visited[index]|=1ull<<22; return eax;
}
inline unsigned Expected12(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=12;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000007u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000005u,4,false,z,s,v,c);eax=((eax)-(0x00000005u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L57;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000027u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x2000001du);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x10000026u);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L48;
L48: visited[index]|=1ull<<15; if(z)goto L71;goto L50;
L50: visited[index]|=1ull<<16; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L55;
L55: visited[index]|=1ull<<17; if(z)goto L63;goto L57;
L57: visited[index]|=1ull<<18; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L60;
L60: visited[index]|=1ull<<19; return eax;
L63: visited[index]|=1ull<<20; eax=(0x20000037u);goto L68;
L68: visited[index]|=1ull<<21; return eax;
L71: visited[index]|=1ull<<22; eax=(0x2000000du);goto L76;
L76: visited[index]|=1ull<<23; return eax;
}
inline unsigned Expected13(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=13;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000007u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L42;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000005u,4,false,z,s,v,c);eax=((eax)-(0x00000005u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L54;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x00000001u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x00000003u);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0);z=true;s=v=c=false;goto L39;
L39: visited[index]|=1ull<<13; return eax;
L42: visited[index]|=1ull<<14; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L45;
L45: visited[index]|=1ull<<15; if(z)goto L68;goto L47;
L47: visited[index]|=1ull<<16; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L52;
L52: visited[index]|=1ull<<17; if(z)goto L60;goto L54;
L54: visited[index]|=1ull<<18; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L57;
L57: visited[index]|=1ull<<19; return eax;
L60: visited[index]|=1ull<<20; eax=(0x00000004u);goto L65;
L65: visited[index]|=1ull<<21; return eax;
L68: visited[index]|=1ull<<22; eax=(0x00000002u);goto L73;
L73: visited[index]|=1ull<<23; return eax;
}
inline unsigned Expected14(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=14;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000007u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000005u,4,false,z,s,v,c);eax=((eax)-(0x00000005u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L57;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000026u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x2000001du);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x10000027u);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L48;
L48: visited[index]|=1ull<<15; if(z)goto L71;goto L50;
L50: visited[index]|=1ull<<16; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L55;
L55: visited[index]|=1ull<<17; if(z)goto L63;goto L57;
L57: visited[index]|=1ull<<18; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L60;
L60: visited[index]|=1ull<<19; return eax;
L63: visited[index]|=1ull<<20; eax=(0x20000037u);goto L68;
L68: visited[index]|=1ull<<21; return eax;
L71: visited[index]|=1ull<<22; eax=(0x2000000du);goto L76;
L76: visited[index]|=1ull<<23; return eax;
}
inline unsigned Expected15(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=15;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L45;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L37;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L29;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000004u,4,false,z,s,v,c);eax=((eax)-(0x00000004u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L57;goto L21;
L21: visited[index]|=1ull<<8; eax=(0x10000026u);goto L26;
L26: visited[index]|=1ull<<9; return eax;
L29: visited[index]|=1ull<<10; eax=(0x2000001du);goto L34;
L34: visited[index]|=1ull<<11; return eax;
L37: visited[index]|=1ull<<12; eax=(0x10000027u);goto L42;
L42: visited[index]|=1ull<<13; return eax;
L45: visited[index]|=1ull<<14; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L48;
L48: visited[index]|=1ull<<15; if(z)goto L71;goto L50;
L50: visited[index]|=1ull<<16; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L55;
L55: visited[index]|=1ull<<17; if(z)goto L63;goto L57;
L57: visited[index]|=1ull<<18; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L60;
L60: visited[index]|=1ull<<19; return eax;
L63: visited[index]|=1ull<<20; eax=(0x20000037u);goto L68;
L68: visited[index]|=1ull<<21; return eax;
L71: visited[index]|=1ull<<22; eax=(0x2000000du);goto L76;
L76: visited[index]|=1ull<<23; return eax;
}
inline unsigned Expected16(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=16;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,0x00000006u,4,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(!z&&(s==v))goto L40;goto L9;
L9: visited[index]|=1ull<<3; if(z)goto L32;goto L11;
L11: visited[index]|=1ull<<4; Flags(eax,0x00000001u,4,false,z,s,v,c);eax=((eax)-(0x00000001u));goto L14;
L14: visited[index]|=1ull<<5; if(z)goto L24;goto L16;
L16: visited[index]|=1ull<<6; Flags(eax,0x00000004u,4,false,z,s,v,c);eax=((eax)-(0x00000004u));goto L19;
L19: visited[index]|=1ull<<7; if(!z)goto L52;goto L21;
L21: visited[index]|=1ull<<8; return eax;
L24: visited[index]|=1ull<<9; eax=(0x00000003u);goto L29;
L29: visited[index]|=1ull<<10; return eax;
L32: visited[index]|=1ull<<11; eax=(0x00000001u);goto L37;
L37: visited[index]|=1ull<<12; return eax;
L40: visited[index]|=1ull<<13; Flags(eax,0x00000008u,4,false,z,s,v,c);goto L43;
L43: visited[index]|=1ull<<14; if(z)goto L66;goto L45;
L45: visited[index]|=1ull<<15; Flags(eax,0x0000fffeu,4,false,z,s,v,c);goto L50;
L50: visited[index]|=1ull<<16; if(z)goto L58;goto L52;
L52: visited[index]|=1ull<<17; LogicFlags((eax)|(0xffffffffu),4,z,s,v,c);eax=((eax)|(0xffffffffu));goto L55;
L55: visited[index]|=1ull<<18; return eax;
L58: visited[index]|=1ull<<19; eax=(0x00000004u);goto L63;
L63: visited[index]|=1ull<<20; return eax;
L66: visited[index]|=1ull<<21; eax=(0x00000002u);goto L71;
L71: visited[index]|=1ull<<22; return eax;
}
inline unsigned Expected17(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=17;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(eax&0xffffff00u)|((Load(expected+8,1))&0xffu);goto L3;
L3: visited[index]|=1ull<<1; Flags((eax&0xffu),0x00000002u,1,true,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; if(!z)goto L18;goto L7;
L7: visited[index]|=1ull<<3; Flags((eax&0xffu),0x00000001u,1,true,z,s,v,c);goto L9;
L9: visited[index]|=1ull<<4; if(z)goto L18;goto L11;
L11: visited[index]|=1ull<<5; LogicFlags(((eax&0xffu))&(0x000000fbu),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000fbu))&0xffu);goto L13;
L13: visited[index]|=1ull<<6; LogicFlags(((eax&0xffu))|(0x00000002u),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000002u))&0xffu);goto L15;
L15: visited[index]|=1ull<<7; Store(expected+8,1,(eax&0xffu));goto L18;
L18: visited[index]|=1ull<<8; return eax;
}
inline unsigned Expected18(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=18;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(eax&0xffffff00u)|((Load(expected+8,1))&0xffu);goto L3;
L3: visited[index]|=1ull<<1; Flags((eax&0xffu),0x00000002u,1,true,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; Store(expected+28,4,0x00000000u);goto L12;
L12: visited[index]|=1ull<<3; if(!z)goto L25;goto L14;
L14: visited[index]|=1ull<<4; Flags((eax&0xffu),0x00000001u,1,true,z,s,v,c);goto L16;
L16: visited[index]|=1ull<<5; if(z)goto L25;goto L18;
L18: visited[index]|=1ull<<6; LogicFlags(((eax&0xffu))&(0x000000fbu),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000fbu))&0xffu);goto L20;
L20: visited[index]|=1ull<<7; LogicFlags(((eax&0xffu))|(0x00000002u),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000002u))&0xffu);goto L22;
L22: visited[index]|=1ull<<8; Store(expected+8,1,(eax&0xffu));goto L25;
L25: visited[index]|=1ull<<9; return eax;
}
inline unsigned Expected19(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=19;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(0);z=true;s=v=c=false;goto L2;
L2: visited[index]|=1ull<<1; Flags(Load(expected+20,4),eax,4,false,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; Store(expected+3124,4,eax);goto L11;
L11: visited[index]|=1ull<<3; if(z)goto L25;goto L13;
L13: visited[index]|=1ull<<4; edx=(Load(expected+4,4));goto L16;
L16: visited[index]|=1ull<<5; Store(expected+16,4,edx);goto L19;
L19: visited[index]|=1ull<<6; edx=(Load(expected+32,4));goto L22;
L22: visited[index]|=1ull<<7; Store(expected+36,4,edx);goto L25;
L25: visited[index]|=1ull<<8; Store(expected+4,4,eax);goto L28;
L28: visited[index]|=1ull<<9; return eax;
}
inline unsigned Expected20(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=20;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; Flags(Load(expected+4,4),0x00000000u,4,false,z,s,v,c);goto L4;
L4: visited[index]|=1ull<<1; if(!z)goto L24;goto L6;
L6: visited[index]|=1ull<<2; Flags(Load(expected+3124,4),0x00000000u,4,false,z,s,v,c);goto L13;
L13: visited[index]|=1ull<<3; if(!z)goto L24;goto L15;
L15: visited[index]|=1ull<<4; Flags(Load(expected+12,4),0x00000000u,4,false,z,s,v,c);goto L19;
L19: visited[index]|=1ull<<5; if(!z)goto L24;goto L21;
L21: visited[index]|=1ull<<6; eax=(0);z=true;s=v=c=false;goto L23;
L23: visited[index]|=1ull<<7; return eax;
L24: visited[index]|=1ull<<8; eax=(0x00000001u);goto L29;
L29: visited[index]|=1ull<<9; return eax;
}
inline unsigned Expected21(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=21;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; edx=(0);z=true;s=v=c=false;goto L6;
L6: visited[index]|=1ull<<2; Flags(Load(expected+12,4),eax,4,false,z,s,v,c);goto L9;
L9: visited[index]|=1ull<<3; if(!z)goto L14;goto L11;
L11: visited[index]|=1ull<<4; Store(expected+12,4,edx);goto L14;
L14: visited[index]|=1ull<<5; Flags(Load(expected+16,4),eax,4,false,z,s,v,c);goto L17;
L17: visited[index]|=1ull<<6; if(!z)goto L22;goto L19;
L19: visited[index]|=1ull<<7; Store(expected+16,4,edx);goto L22;
L22: visited[index]|=1ull<<8; Flags(Load(expected+4,4),eax,4,false,z,s,v,c);goto L25;
L25: visited[index]|=1ull<<9; if(!z)goto L30;goto L27;
L27: visited[index]|=1ull<<10; Store(expected+4,4,edx);goto L30;
L30: visited[index]|=1ull<<11; return eax;
}
inline unsigned Expected22(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=22;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(Load(expected+72,4));goto L3;
L3: visited[index]|=1ull<<1; Flags(eax,eax,4,true,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; if(!z)goto L12;goto L7;
L7: visited[index]|=1ull<<3; eax=(0x00000001u);goto L12;
L12: visited[index]|=1ull<<4; return eax;
}
inline unsigned Expected23(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=23;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(eax&0xffffff00u)|(((args[0]&0xffu))&0xffu);goto L4;
L4: visited[index]|=1ull<<1; Flags(Load(expected+60,1),(eax&0xffu),1,false,z,s,v,c);goto L7;
L7: visited[index]|=1ull<<2; if(z)goto L17;goto L9;
L9: visited[index]|=1ull<<3; Store(expected+60,1,(eax&0xffu));goto L12;
L12: visited[index]|=1ull<<4; eax=(eax&0xffffff00u)|((0x00000001u)&0xffu);goto L14;
L14: visited[index]|=1ull<<5; return eax;
L17: visited[index]|=1ull<<6; eax=(eax&0xffffff00u)|((0)&0xffu);z=true;s=v=c=false;goto L19;
L19: visited[index]|=1ull<<7; return eax;
}
inline unsigned Expected24(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=24;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,eax,4,true,z,s,v,c);goto L6;
L6: visited[index]|=1ull<<2; if(!z)goto L14;goto L8;
L8: visited[index]|=1ull<<3; eax=(96u+ecx*1u);goto L11;
L11: visited[index]|=1ull<<4; return eax;
L14: visited[index]|=1ull<<5; Flags(eax,0x00000001u,4,false,z,s,v,c);goto L17;
L17: visited[index]|=1ull<<6; if(!z)goto L25;goto L19;
L19: visited[index]|=1ull<<7; eax=(112u+ecx*1u);goto L22;
L22: visited[index]|=1ull<<8; return eax;
L25: visited[index]|=1ull<<9; eax=((eax)<<(0x00000006u));goto L28;
L28: visited[index]|=1ull<<10; eax=(80u+eax*1u+ecx*1u);goto L32;
L32: visited[index]|=1ull<<11; return eax;
}
inline unsigned Expected25(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=25;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=((args[0]&0xffffffffu));goto L4;
L4: visited[index]|=1ull<<1; Flags(eax,eax,4,true,z,s,v,c);goto L6;
L6: visited[index]|=1ull<<2; if(!z)goto L14;goto L8;
L8: visited[index]|=1ull<<3; eax=(64u+ecx*1u);goto L11;
L11: visited[index]|=1ull<<4; return eax;
L14: visited[index]|=1ull<<5; Flags(eax,0x00000001u,4,false,z,s,v,c);goto L17;
L17: visited[index]|=1ull<<6; if(!z)goto L25;goto L19;
L19: visited[index]|=1ull<<7; eax=(80u+ecx*1u);goto L22;
L22: visited[index]|=1ull<<8; return eax;
L25: visited[index]|=1ull<<9; eax=((eax)<<(0x00000006u));goto L28;
L28: visited[index]|=1ull<<10; eax=(96u+eax*1u+ecx*1u);goto L32;
L32: visited[index]|=1ull<<11; return eax;
}
inline unsigned Expected26(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=26;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(320u+ecx*1u);goto L6;
L6: visited[index]|=1ull<<1; Flags(eax,eax,4,true,z,s,v,c);goto L8;
L8: visited[index]|=1ull<<2; if(z)goto L17;goto L10;
L10: visited[index]|=1ull<<3; eax=(336u+ecx*1u);goto L16;
L16: visited[index]|=1ull<<4; return eax;
L17: visited[index]|=1ull<<5; eax=(0);z=true;s=v=c=false;goto L19;
L19: visited[index]|=1ull<<6; return eax;
}
inline unsigned Expected27(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=27;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(eax&0xffffff00u)|((Load(expected+8,1))&0xffu);goto L3;
L3: visited[index]|=1ull<<1; Flags((eax&0xffu),0x00000002u,1,true,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; Store(expected+384,4,0x00000000u);goto L15;
L15: visited[index]|=1ull<<3; if(!z)goto L28;goto L17;
L17: visited[index]|=1ull<<4; Flags((eax&0xffu),0x00000001u,1,true,z,s,v,c);goto L19;
L19: visited[index]|=1ull<<5; if(z)goto L28;goto L21;
L21: visited[index]|=1ull<<6; LogicFlags(((eax&0xffu))&(0x000000fbu),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000fbu))&0xffu);goto L23;
L23: visited[index]|=1ull<<7; LogicFlags(((eax&0xffu))|(0x00000002u),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000002u))&0xffu);goto L25;
L25: visited[index]|=1ull<<8; Store(expected+8,1,(eax&0xffu));goto L28;
L28: visited[index]|=1ull<<9; return eax;
}
inline unsigned Expected28(unsigned char* expected,unsigned ecx,const unsigned* args){constexpr unsigned index=28;unsigned eax=0,edx=0;bool z=false,s=false,v=false,c=false;
L0: visited[index]|=1ull<<0; eax=(eax&0xffffff00u)|((Load(expected+8,1))&0xffu);goto L3;
L3: visited[index]|=1ull<<1; Flags((eax&0xffu),0x00000002u,1,true,z,s,v,c);goto L5;
L5: visited[index]|=1ull<<2; Store(expected+16,4,0x00000000u);goto L12;
L12: visited[index]|=1ull<<3; if(!z)goto L25;goto L14;
L14: visited[index]|=1ull<<4; Flags((eax&0xffu),0x00000001u,1,true,z,s,v,c);goto L16;
L16: visited[index]|=1ull<<5; if(z)goto L25;goto L18;
L18: visited[index]|=1ull<<6; LogicFlags(((eax&0xffu))&(0x000000fbu),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000fbu))&0xffu);goto L20;
L20: visited[index]|=1ull<<7; LogicFlags(((eax&0xffu))|(0x00000002u),1,z,s,v,c);eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000002u))&0xffu);goto L22;
L22: visited[index]|=1ull<<8; Store(expected+8,1,(eax&0xffu));goto L25;
L25: visited[index]|=1ull<<9; return eax;
}
inline unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args){switch(i){
case 0:return Expected0(expected,ecx,args);
case 1:return Expected1(expected,ecx,args);
case 2:return Expected2(expected,ecx,args);
case 3:return Expected3(expected,ecx,args);
case 4:return Expected4(expected,ecx,args);
case 5:return Expected5(expected,ecx,args);
case 6:return Expected6(expected,ecx,args);
case 7:return Expected7(expected,ecx,args);
case 8:return Expected8(expected,ecx,args);
case 9:return Expected9(expected,ecx,args);
case 10:return Expected10(expected,ecx,args);
case 11:return Expected11(expected,ecx,args);
case 12:return Expected12(expected,ecx,args);
case 13:return Expected13(expected,ecx,args);
case 14:return Expected14(expected,ecx,args);
case 15:return Expected15(expected,ecx,args);
case 16:return Expected16(expected,ecx,args);
case 17:return Expected17(expected,ecx,args);
case 18:return Expected18(expected,ecx,args);
case 19:return Expected19(expected,ecx,args);
case 20:return Expected20(expected,ecx,args);
case 21:return Expected21(expected,ecx,args);
case 22:return Expected22(expected,ecx,args);
case 23:return Expected23(expected,ecx,args);
case 24:return Expected24(expected,ecx,args);
case 25:return Expected25(expected,ecx,args);
case 26:return Expected26(expected,ecx,args);
case 27:return Expected27(expected,ecx,args);
case 28:return Expected28(expected,ecx,args);
}return 0;}
inline void Setup(unsigned i,unsigned sample,unsigned char* object,const unsigned* args){switch(i){
case 0: break;
case 1: break;
case 2: Store(object+8,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+12,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u);break;
case 3: break;
case 4: break;
case 5: break;
case 6: break;
case 7: break;
case 8: break;
case 9: break;
case 10: break;
case 11: break;
case 12: break;
case 13: break;
case 14: break;
case 15: break;
case 16: break;
case 17: Store(object+8,1,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u);break;
case 18: Store(object+8,1,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+28,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u);break;
case 19: Store(object+4,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+16,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u); Store(object+20,4,sample<32?((sample>>2)&1?args[0]:0):args[0]^132102u); Store(object+32,4,sample<32?((sample>>3)&1?args[0]:0):args[0]^198153u); Store(object+36,4,sample<32?((sample>>4)&1?args[0]:0):args[0]^264204u); Store(object+3124,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^330255u);break;
case 20: Store(object+4,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+12,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u); Store(object+3124,4,sample<32?((sample>>2)&1?args[0]:0):args[0]^132102u);break;
case 21: Store(object+4,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+12,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u); Store(object+16,4,sample<32?((sample>>2)&1?args[0]:0):args[0]^132102u);break;
case 22: Store(object+72,4,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u);break;
case 23: Store(object+60,1,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u);break;
case 24: break;
case 25: break;
case 26: break;
case 27: Store(object+8,1,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+384,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u);break;
case 28: Store(object+8,1,sample<32?((sample>>0)&1?args[0]:0):args[0]^0u); Store(object+16,4,sample<32?((sample>>1)&1?args[0]:0):args[0]^66051u);break;
}}
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;
inline int Check(unsigned i,unsigned sample){
 __try {
  const auto& e=entries[i];const auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  unsigned args[6];for(unsigned n=0;n<6;++n)args[n]=sample<32?sample+n:(sample==32?0xffffffffu:0x80000000u+(sample-33)*0x1020304u+n);
  Setup(i,sample,object,args);memcpy(expected,object,sizeof(object));
  const unsigned wanted=Expected(i,expected,reinterpret_cast<unsigned>(object),args);unsigned result=0;
  if(e.floating){float f=1;switch(e.pop){
   case 0:{using F=float(__thiscall*)(void*);f=reinterpret_cast<F>(address)(object);break;}
   case 4:{using F=float(__thiscall*)(void*,unsigned);f=reinterpret_cast<F>(address)(object,args[0]);break;}
   case 20:{using F=float(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned);f=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4]);break;}
   default:return 5;
  }if(f!=0)return 2;}
  else switch(e.pop){
   case 0:{using F=unsigned(__thiscall*)(void*);result=reinterpret_cast<F>(address)(object);break;}
   case 4:{using F=unsigned(__thiscall*)(void*,unsigned);result=reinterpret_cast<F>(address)(object,args[0]);break;}
   case 8:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1]);break;}
   case 12:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2]);break;}
   case 16:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3]);break;}
   case 20:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4]);break;}
   case 24:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4],args[5]);break;}
   default:return 5;
  }
  if(!e.floating && (result&e.mask)!=(wanted&e.mask))return 2;
  return memcmp(object,expected,sizeof(object))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}
inline void Report(const char* phase){FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-rage-complex.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s,\"expected_nodes_mask\":\"0x%016llX\"}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false",visited[i]);fprintf(f,"]}\n");fclose(f);}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.rage-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
inline void Tick(){if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){const int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Rage complete CFG RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}
}
