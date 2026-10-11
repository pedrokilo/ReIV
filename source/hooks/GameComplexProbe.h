#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
#include "GameComplexScalarProbe.h"
namespace gamecomplex {
enum class Op { sete,setne,setg,setge,setl,setle,seta,setae,setb,setbe,bits };
enum class Arithmetic { none,shr,and_,or_,xor_,not_ };
struct Step { Arithmetic op; unsigned value; };
struct Entry { reiv::original::FunctionAddress binding;Op operation;unsigned offset,width,cleanup,value,stepCount;Step steps[8]; };
inline constexpr unsigned char bytes0[]={0x80,0xb9,0xd0,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes1[]={0x80,0xb9,0xd1,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes2[]={0x80,0xb9,0xe8,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes3[]={0x80,0xb9,0xe9,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes4[]={0x80,0xb9,0xea,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes5[]={0x80,0xb9,0xeb,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes6[]={0x33,0xc0,0x39,0x81,0xa8,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes7[]={0x33,0xc0,0x39,0x81,0xb4,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes8[]={0x80,0xb9,0xc8,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes9[]={0x80,0xb9,0xc4,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes10[]={0x80,0xb9,0xc5,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes11[]={0x80,0xb9,0xc6,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes12[]={0x80,0xb9,0xc7,0x00,0x00,0x00,0x00,0x0f,0x95,0xc0,0xc3};
inline constexpr unsigned char bytes13[]={0x33,0xc0,0x39,0x81,0x38,0x02,0x00,0x00,0x0f,0x94,0xc0,0xc3};
inline constexpr unsigned char bytes14[]={0x8b,0x81,0x18,0x01,0x00,0x00,0xc1,0xe8,0x03,0xf7,0xd0,0x83,0xe0,0x01,0xc3};
inline constexpr unsigned char bytes15[]={0x33,0xc0,0x83,0x79,0x54,0xff,0x0f,0x95,0xc0,0xc2,0x08,0x00};
inline constexpr unsigned char bytes16[]={0x8b,0x41,0x08,0xd1,0xe8,0x83,0xe0,0x01,0xc3};
inline constexpr unsigned char bytes17[]={0x33,0xc0,0x38,0x41,0x28,0x0f,0x94,0xc0,0xc3};
inline constexpr unsigned char bytes18[]={0x8a,0x41,0x11,0xc0,0xe8,0x03,0x24,0x01,0xc3};
inline constexpr unsigned char bytes19[]={0x33,0xc0,0x39,0x81,0x64,0x01,0x00,0x00,0x0f,0x9f,0xc0,0xc3};
inline constexpr unsigned char bytes20[]={0x33,0xc0,0x38,0x41,0x20,0x0f,0x94,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes21[]={0x33,0xc0,0x83,0x79,0x24,0x18,0x0f,0x9d,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes22[]={0x8a,0x81,0x6d,0x0f,0x00,0x00,0xc0,0xe8,0x04,0x24,0x01,0xc3};
inline constexpr unsigned char bytes23[]={0x8a,0x81,0x6d,0x0f,0x00,0x00,0xc0,0xe8,0x06,0x24,0x01,0xc3};
inline constexpr unsigned char bytes24[]={0x8a,0x41,0x38,0xd0,0xe8,0x24,0x01,0xc3};
inline constexpr unsigned char bytes25[]={0x33,0xc0,0x39,0x81,0x14,0x03,0x00,0x00,0x0f,0x94,0xc0,0xc3};
inline constexpr unsigned char bytes26[]={0x33,0xc0,0x83,0xb9,0x14,0x03,0x00,0x00,0x01,0x0f,0x94,0xc0,0xc3};
inline constexpr unsigned char bytes27[]={0x33,0xc0,0x83,0xb9,0x14,0x03,0x00,0x00,0x02,0x0f,0x94,0xc0,0xc3};
inline const Entry entries[]={
{{"Game complex 0x004352f0",0x000352f0,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},Op::setne,208u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435320",0x00035320,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},Op::setne,209u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435330",0x00035330,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},Op::setne,232u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435370",0x00035370,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},Op::setne,233u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435380",0x00035380,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},Op::setne,234u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435390",0x00035390,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},Op::setne,235u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435610",0x00035610,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},Op::setne,168u,4u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435620",0x00035620,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},Op::setne,180u,4u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435700",0x00035700,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},Op::setne,200u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435730",0x00035730,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},Op::setne,196u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435750",0x00035750,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},Op::setne,197u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00435770",0x00035770,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},Op::setne,198u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x004357c0",0x000357c0,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},Op::setne,199u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x0043b870",0x0003b870,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},Op::sete,568u,4u,0u,0x00000000u,0,{}},
{{"Game complex 0x00447b20",0x00047b20,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},Op::bits,280u,4u,0u,0x00000004u,3,{{Arithmetic::shr,0x00000003u},{Arithmetic::not_,0x00000000u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x0044cb30",0x0004cb30,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},Op::setne,84u,4u,8u,0xffffffffu,0,{}},
{{"Game complex 0x00454340",0x00054340,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},Op::bits,8u,4u,0u,0x00000004u,2,{{Arithmetic::shr,0x00000001u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x0048a520",0x0008a520,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},Op::sete,40u,1u,0u,0x00000000u,0,{}},
{{"Game complex 0x00493f80",0x00093f80,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},Op::bits,17u,1u,0u,0x00000001u,2,{{Arithmetic::shr,0x00000003u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x004e0b30",0x000e0b30,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},Op::setg,356u,4u,0u,0x00000000u,0,{}},
{{"Game complex 0x004f0140",0x000f0140,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},Op::sete,32u,1u,4u,0x00000000u,0,{}},
{{"Game complex 0x004f0cf0",0x000f0cf0,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},Op::setge,36u,4u,4u,0x00000018u,0,{}},
{{"Game complex 0x009c5360",0x005c5360,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},Op::bits,3949u,1u,0u,0x00000001u,2,{{Arithmetic::shr,0x00000004u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x009c5430",0x005c5430,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},Op::bits,3949u,1u,0u,0x00000001u,2,{{Arithmetic::shr,0x00000006u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x00ab9a50",0x006b9a50,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},Op::bits,56u,1u,0u,0x00000001u,2,{{Arithmetic::shr,0x00000001u},{Arithmetic::and_,0x00000001u}}},
{{"Game complex 0x00c28260",0x00828260,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},Op::sete,788u,4u,0u,0x00000000u,0,{}},
{{"Game complex 0x00c28270",0x00828270,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},Op::sete,788u,4u,0u,0x00000001u,0,{}},
{{"Game complex 0x00c28830",0x00828830,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},Op::sete,788u,4u,0u,0x00000002u,0,{}},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

template<class R> inline R Invoke(uintptr_t address,void* object,unsigned cleanup) {
 switch(cleanup){
 case 0:return reinterpret_cast<R(__thiscall*)(void*)>(address)(object);
 case 4:return reinterpret_cast<R(__thiscall*)(void*,unsigned)>(address)(object,0);
 case 8:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned)>(address)(object,0,0);
 case 12:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned)>(address)(object,0,0,0);
 case 16:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned)>(address)(object,0,0,0,0);
 default:return reinterpret_cast<R(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned)>(address)(object,0,0,0,0,0);
 }
}
int Check(unsigned index,unsigned sample);
void Report(const char* phase);
void Tick();
void Initialize();
}

