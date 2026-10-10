#pragma once
#include <cstring>
namespace pendingscalar {
struct Entry { reiv::original::FunctionAddress binding; unsigned pop; bool floating; unsigned mask; };
inline constexpr unsigned char bytes0[]={0x8b,0xc1,0xc3};
inline constexpr unsigned char bytes1[]={0x33,0xc0,0x33,0xd2,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0xb0,0x01,0xc2,0x08,0x00};
inline constexpr unsigned char bytes3[]={0x83,0xc8,0xff,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0x32,0xc0,0xc2,0x18,0x00};
inline constexpr unsigned char bytes5[]={0xb0,0x01,0xc2,0x08,0x00};
inline constexpr unsigned char bytes6[]={0x83,0x41,0x04,0x01,0xc3};
inline constexpr unsigned char bytes7[]={0x83,0xc8,0xff,0xc3};
inline constexpr unsigned char bytes8[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x1c,0xc2,0x04,0x00};
inline constexpr unsigned char bytes9[]={0x33,0xc0,0x89,0x41,0x1c,0x89,0x41,0x20,0x89,0x41,0x14,0xc3};
inline constexpr unsigned char bytes10[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x20,0xc2,0x04,0x00};
inline constexpr unsigned char bytes11[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x14,0xc2,0x04,0x00};
inline constexpr unsigned char bytes12[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x18,0xc2,0x04,0x00};
inline constexpr unsigned char bytes13[]={0x8b,0x44,0x24,0x04,0x01,0x81,0x20,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes14[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x20,0xf3,0x0f,0x10,0x44,0x24,0x08,0xf3,0x0f,0x11,0x41,0x24,0xc2,0x08,0x00};
inline constexpr unsigned char bytes15[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x20,0xf3,0x0f,0x10,0x44,0x24,0x08,0xf3,0x0f,0x11,0x41,0x24,0xf3,0x0f,0x10,0x44,0x24,0x0c,0xf3,0x0f,0x11,0x41,0x28,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes16[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x20,0xf3,0x0f,0x10,0x44,0x24,0x08,0xf3,0x0f,0x11,0x41,0x24,0xf3,0x0f,0x10,0x44,0x24,0x0c,0xf3,0x0f,0x11,0x41,0x28,0xf3,0x0f,0x10,0x44,0x24,0x10,0xf3,0x0f,0x11,0x41,0x2c,0xc2,0x10,0x00};
inline constexpr unsigned char bytes17[]={0x33,0xc0,0xc2,0x18,0x00};
inline constexpr unsigned char bytes18[]={0x83,0xa1,0x1c,0x01,0x00,0x00,0xfd,0xc2,0x04,0x00};
inline constexpr unsigned char bytes19[]={0x83,0xa1,0x1c,0x01,0x00,0x00,0xfd,0xc3};
inline constexpr unsigned char bytes20[]={0xd9,0xee,0xc3};
inline constexpr unsigned char bytes21[]={0x80,0x49,0x04,0x10,0xb8,0x01,0x00,0x80,0x7f,0x89,0x41,0x10,0x89,0x41,0x14,0x89,0x41,0x18,0x89,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes22[]={0x0f,0x57,0xc0,0x80,0x61,0x04,0xef,0xf3,0x0f,0x11,0x41,0x10,0xc3};
inline constexpr unsigned char bytes23[]={0x80,0x49,0x04,0x10,0xc7,0x41,0x10,0x01,0x00,0x80,0x7f,0xc3};
inline constexpr unsigned char bytes24[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x80,0x61,0x04,0xef,0xf3,0x0f,0x11,0x41,0x10,0xc2,0x04,0x00};
inline constexpr unsigned char bytes25[]={0x80,0x61,0x04,0xef,0xc7,0x41,0x10,0x00,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes26[]={0x80,0x49,0x04,0x10,0xc7,0x41,0x10,0x00,0x00,0x00,0x80,0xc3};
inline constexpr unsigned char bytes27[]={0x8b,0x44,0x24,0x04,0x80,0x61,0x04,0xef,0x89,0x41,0x10,0xc2,0x04,0x00};
inline constexpr unsigned char bytes28[]={0x33,0xc0,0x89,0x41,0x04,0x89,0x41,0x08,0xc3};
inline constexpr unsigned char bytes29[]={0xb0,0x01,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes30[]={0xb8,0x64,0x00,0x00,0x00,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes31[]={0xb8,0x28,0x00,0x00,0x00,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes32[]={0x8b,0x41,0x10,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes33[]={0x8b,0x41,0x14,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes34[]={0x33,0xc0,0x89,0x41,0x0c,0x89,0x41,0x04,0x89,0x41,0x08,0xc3};
inline constexpr unsigned char bytes35[]={0x0f,0xb7,0x41,0x0c,0x83,0xc0,0x01,0xc1,0xe0,0x04,0xc3};
inline constexpr unsigned char bytes36[]={0x0f,0xb7,0x41,0x0c,0x83,0xc0,0x10,0xc3};
inline constexpr unsigned char bytes37[]={0x83,0xc8,0xff,0xc2,0x08,0x00};
inline constexpr unsigned char bytes38[]={0x83,0xc8,0xff,0xc2,0x14,0x00};
inline constexpr unsigned char bytes39[]={0xb8,0x80,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes40[]={0x83,0xc8,0xff,0xc2,0x04,0x00};
inline constexpr unsigned char bytes41[]={0x83,0xc8,0xff,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes42[]={0x8b,0x41,0x10,0x8b,0x51,0x14,0xc2,0x04,0x00};
inline constexpr unsigned char bytes43[]={0x8b,0xc1,0xc2,0x04,0x00};
inline constexpr unsigned char bytes44[]={0x0f,0xb7,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes45[]={0x0f,0xb7,0x41,0x1e,0xc3};
inline constexpr unsigned char bytes46[]={0x0f,0xb6,0x41,0x27,0xc3};
inline constexpr unsigned char bytes47[]={0x0f,0xb7,0x41,0x3c,0xc3};
inline constexpr unsigned char bytes48[]={0x0f,0xb7,0x41,0x3e,0xc3};
inline constexpr unsigned char bytes49[]={0x66,0x33,0xc0,0xc3};
inline constexpr unsigned char bytes50[]={0x66,0x8b,0x41,0x36,0xc3};
inline constexpr unsigned char bytes51[]={0x66,0x8b,0x41,0x3e,0xc3};
inline constexpr unsigned char bytes52[]={0xc6,0x41,0x06,0x00,0xc7,0x41,0x14,0xff,0xff,0xff,0xff,0xb0,0x01,0xc3};
inline constexpr unsigned char bytes53[]={0x0f,0xb6,0x41,0x04,0xc3};
inline constexpr unsigned char bytes54[]={0x8b,0x81,0xd0,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes55[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xd0,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes56[]={0xc7,0x41,0x18,0x01,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes57[]={0xd9,0xee,0xc2,0x04,0x00};
inline constexpr unsigned char bytes58[]={0x66,0x8b,0x41,0x18,0xc3};
inline constexpr unsigned char bytes59[]={0x0f,0xb6,0x81,0xd8,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes60[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x24,0xc2,0x04,0x00};
inline constexpr unsigned char bytes61[]={0x32,0xc0,0xc2,0x18,0x00};
inline constexpr unsigned char bytes62[]={0x8b,0x81,0x90,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes63[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x90,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes64[]={0x8b,0x81,0x20,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes65[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x20,0x02,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes66[]={0x0f,0x57,0xc0,0xf3,0x0f,0x11,0x81,0x98,0x01,0x00,0x00,0xf3,0x0f,0x11,0x81,0x94,0x01,0x00,0x00,0xf3,0x0f,0x11,0x81,0x90,0x01,0x00,0x00,0xf3,0x0f,0x11,0x81,0x88,0x01,0x00,0x00,0xf3,0x0f,0x11,0x81,0x84,0x01,0x00,0x00,0xf3,0x0f,0x11,0x81,0x80,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes67[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x10,0xc2,0x04,0x00};
inline constexpr unsigned char bytes68[]={0xd9,0xee,0xc2,0x14,0x00};
inline constexpr unsigned char bytes69[]={0xc2,0x18,0x00};
inline constexpr unsigned char bytes70[]={0x8b,0x81,0x00,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes71[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x00,0x01,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes72[]={0x8b,0x81,0x40,0x09,0x00,0x00,0x83,0xc0,0x02,0xc3};
inline constexpr unsigned char bytes73[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0x70,0x02,0x00,0x00,0xf3,0x0f,0x11,0x81,0x78,0x02,0x00,0x00,0xf3,0x0f,0x10,0x44,0x24,0x08,0xf3,0x0f,0x11,0x81,0x74,0x02,0x00,0x00,0xf3,0x0f,0x11,0x81,0x7c,0x02,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes74[]={0x8b,0x81,0xb4,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes75[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xb4,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes76[]={0x66,0x8b,0x41,0x14,0xc3};
inline constexpr unsigned char bytes77[]={0x66,0x8b,0x41,0x40,0xc3};
inline constexpr unsigned char bytes78[]={0xb8,0x01,0x00,0x00,0x00,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes79[]={0xb0,0x01,0xc2,0x04,0x00};
inline constexpr unsigned char bytes80[]={0x8b,0xc1,0xc2,0x04,0x00};
inline constexpr unsigned char bytes81[]={0x8d,0x81,0x34,0x00,0x02,0x00,0xc3};
inline constexpr unsigned char bytes82[]={0x8d,0x81,0x74,0x00,0x02,0x00,0xc3};
inline const Entry entries[]={
{{"Pending scalar 0x00404B90",0x00004B90,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0043B5B0",0x0003B5B0,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00453AD0",0x00053AD0,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},8,false,0x000000ffu},
{{"Pending scalar 0x004C4C00",0x000C4C00,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x004C5030",0x000C5030,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},24,false,0x000000ffu},
{{"Pending scalar 0x004E76B0",0x000E76B0,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},8,false,0x000000ffu},
{{"Pending scalar 0x0050B6E0",0x0010B6E0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00510B90",0x00110B90,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x005119F0",0x001119F0,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00511B50",0x00111B50,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x00515F90",0x00115F90,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x0051EF10",0x0011EF10,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x0051EF20",0x0011EF20,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00520110",0x00120110,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00554860",0x00154860,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},8,false,0x00000000u},
{{"Pending scalar 0x00554920",0x00154920,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},12,false,0x00000000u},
{{"Pending scalar 0x005549E0",0x001549E0,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},16,false,0x00000000u},
{{"Pending scalar 0x0055A860",0x0015A860,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},24,false,0xffffffffu},
{{"Pending scalar 0x0055A8D0",0x0015A8D0,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x0055A8E0",0x0015A8E0,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00567170",0x00167170,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},0,true,0xffffffffu},
{{"Pending scalar 0x005881F0",0x001881F0,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0058C350",0x0018C350,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x0058C360",0x0018C360,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x0058C380",0x0018C380,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x0058C5C0",0x0018C5C0,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x0058C5D0",0x0018C5D0,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x0058C600",0x0018C600,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x0059B9D0",0x0019B9D0,bytes28,sizeof(bytes28),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0059BC80",0x0019BC80,bytes29,sizeof(bytes29),reiv::original::BindingState::StaticVerified},12,false,0x000000ffu},
{{"Pending scalar 0x0059F0F0",0x0019F0F0,bytes30,sizeof(bytes30),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x0059F100",0x0019F100,bytes31,sizeof(bytes31),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x0059F170",0x0019F170,bytes32,sizeof(bytes32),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x0059F180",0x0019F180,bytes33,sizeof(bytes33),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x0059F440",0x0019F440,bytes34,sizeof(bytes34),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x005A1F00",0x001A1F00,bytes35,sizeof(bytes35),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x005A2920",0x001A2920,bytes36,sizeof(bytes36),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x005AC220",0x001AC220,bytes37,sizeof(bytes37),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x005AC230",0x001AC230,bytes38,sizeof(bytes38),reiv::original::BindingState::StaticVerified},20,false,0xffffffffu},
{{"Pending scalar 0x005AC850",0x001AC850,bytes39,sizeof(bytes39),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x005BD3F0",0x001BD3F0,bytes40,sizeof(bytes40),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x005BDB10",0x001BDB10,bytes41,sizeof(bytes41),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x005BDC60",0x001BDC60,bytes42,sizeof(bytes42),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x005CB1D0",0x001CB1D0,bytes43,sizeof(bytes43),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x0062A2C0",0x0022A2C0,bytes44,sizeof(bytes44),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0062A2D0",0x0022A2D0,bytes45,sizeof(bytes45),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0062A2E0",0x0022A2E0,bytes46,sizeof(bytes46),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0062A340",0x0022A340,bytes47,sizeof(bytes47),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0062A350",0x0022A350,bytes48,sizeof(bytes48),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0064BB00",0x0024BB00,bytes49,sizeof(bytes49),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x0064C060",0x0024C060,bytes50,sizeof(bytes50),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x0064EDB0",0x0024EDB0,bytes51,sizeof(bytes51),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x00658F20",0x00258F20,bytes52,sizeof(bytes52),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Pending scalar 0x00686780",0x00286780,bytes53,sizeof(bytes53),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x0068E0C0",0x0028E0C0,bytes54,sizeof(bytes54),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x0068E0D0",0x0028E0D0,bytes55,sizeof(bytes55),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x0069AE90",0x0029AE90,bytes56,sizeof(bytes56),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x0069ED90",0x0029ED90,bytes57,sizeof(bytes57),reiv::original::BindingState::StaticVerified},4,true,0xffffffffu},
{{"Pending scalar 0x006A1F30",0x002A1F30,bytes58,sizeof(bytes58),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x006B8C50",0x002B8C50,bytes59,sizeof(bytes59),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x006BFBE0",0x002BFBE0,bytes60,sizeof(bytes60),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x006C1350",0x002C1350,bytes61,sizeof(bytes61),reiv::original::BindingState::StaticVerified},24,false,0x000000ffu},
{{"Pending scalar 0x006D4870",0x002D4870,bytes62,sizeof(bytes62),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x006D4880",0x002D4880,bytes63,sizeof(bytes63),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x006D7650",0x002D7650,bytes64,sizeof(bytes64),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x006D7670",0x002D7670,bytes65,sizeof(bytes65),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x006FE5E0",0x002FE5E0,bytes66,sizeof(bytes66),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00703540",0x00303540,bytes67,sizeof(bytes67),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00704070",0x00304070,bytes68,sizeof(bytes68),reiv::original::BindingState::StaticVerified},20,true,0xffffffffu},
{{"Pending scalar 0x00704080",0x00304080,bytes69,sizeof(bytes69),reiv::original::BindingState::StaticVerified},24,false,0x00000000u},
{{"Pending scalar 0x00704740",0x00304740,bytes70,sizeof(bytes70),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00704750",0x00304750,bytes71,sizeof(bytes71),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x0070DD40",0x0030DD40,bytes72,sizeof(bytes72),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x007139B0",0x003139B0,bytes73,sizeof(bytes73),reiv::original::BindingState::StaticVerified},8,false,0x00000000u},
{{"Pending scalar 0x00728C70",0x00328C70,bytes74,sizeof(bytes74),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00728C80",0x00328C80,bytes75,sizeof(bytes75),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x0073AB30",0x0033AB30,bytes76,sizeof(bytes76),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x0073DE50",0x0033DE50,bytes77,sizeof(bytes77),reiv::original::BindingState::StaticVerified},0,false,0x0000ffffu},
{{"Pending scalar 0x00779D80",0x00379D80,bytes78,sizeof(bytes78),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x00784520",0x00384520,bytes79,sizeof(bytes79),reiv::original::BindingState::StaticVerified},4,false,0x000000ffu},
{{"Pending scalar 0x00B044E0",0x007044E0,bytes80,sizeof(bytes80),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00CF6A10",0x008F6A10,bytes81,sizeof(bytes81),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x00CF6A20",0x008F6A20,bytes82,sizeof(bytes82),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline unsigned Load(const unsigned char* p,unsigned n){unsigned v=0;memcpy(&v,p,n);return v;}
inline void Store(unsigned char* p,unsigned n,unsigned v){memcpy(p,&v,n);}
inline unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args){unsigned eax=0,edx=0,xmm0=0;switch(i){
case 0: eax=(ecx); break;
case 1: eax=(0); edx=(0); break;
case 2: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 3: eax=(0xffffffffu); break;
case 4: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 5: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 6: Store(expected+4,4,(Load(expected+4,4))+(0x00000001u)); break;
case 7: eax=(0xffffffffu); break;
case 8: xmm0=args[0]; Store(expected+28,4,xmm0); break;
case 9: eax=(0); Store(expected+28,4,eax); Store(expected+32,4,eax); Store(expected+20,4,eax); break;
case 10: xmm0=args[0]; Store(expected+32,4,xmm0); break;
case 11: xmm0=args[0]; Store(expected+20,4,xmm0); break;
case 12: xmm0=args[0]; Store(expected+24,4,xmm0); break;
case 13: eax=(args[0]); Store(expected+544,4,(Load(expected+544,4))+(eax)); break;
case 14: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); break;
case 15: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); xmm0=args[2]; Store(expected+40,4,xmm0); break;
case 16: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); xmm0=args[2]; Store(expected+40,4,xmm0); xmm0=args[3]; Store(expected+44,4,xmm0); break;
case 17: eax=(0); break;
case 18: Store(expected+284,4,(Load(expected+284,4))&(0xfffffffdu)); break;
case 19: Store(expected+284,4,(Load(expected+284,4))&(0xfffffffdu)); break;
case 20:  break;
case 21: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); eax=(0x7f800001u); Store(expected+16,4,eax); Store(expected+20,4,eax); Store(expected+24,4,eax); Store(expected+28,4,eax); break;
case 22: xmm0=0; Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,xmm0); break;
case 23: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); Store(expected+16,4,0x7f800001u); break;
case 24: xmm0=args[0]; Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,xmm0); break;
case 25: Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,0x00000000u); break;
case 26: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); Store(expected+16,4,0x80000000u); break;
case 27: eax=(args[0]); Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,eax); break;
case 28: eax=(0); Store(expected+4,4,eax); Store(expected+8,4,eax); break;
case 29: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 30: eax=(0x00000064u); break;
case 31: eax=(0x00000028u); break;
case 32: eax=(Load(expected+16,4)); break;
case 33: eax=(Load(expected+20,4)); break;
case 34: eax=(0); Store(expected+12,4,eax); Store(expected+4,4,eax); Store(expected+8,4,eax); break;
case 35: eax=(Load(expected+12,2)); eax=((eax)+(0x00000001u)); eax=((eax)<<(0x00000004u)); break;
case 36: eax=(Load(expected+12,2)); eax=((eax)+(0x00000010u)); break;
case 37: eax=(0xffffffffu); break;
case 38: eax=(0xffffffffu); break;
case 39: eax=(0x00000080u); break;
case 40: eax=(0xffffffffu); break;
case 41: eax=(0xffffffffu); break;
case 42: eax=(Load(expected+16,4)); edx=(Load(expected+20,4)); break;
case 43: eax=(ecx); break;
case 44: eax=(Load(expected+28,2)); break;
case 45: eax=(Load(expected+30,2)); break;
case 46: eax=(Load(expected+39,1)); break;
case 47: eax=(Load(expected+60,2)); break;
case 48: eax=(Load(expected+62,2)); break;
case 49: eax=(eax&0xffff0000u)|((0)&0xffffu); break;
case 50: eax=(eax&0xffff0000u)|((Load(expected+54,2))&0xffffu); break;
case 51: eax=(eax&0xffff0000u)|((Load(expected+62,2))&0xffffu); break;
case 52: Store(expected+6,1,0x00000000u); Store(expected+20,4,0xffffffffu); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 53: eax=(Load(expected+4,1)); break;
case 54: eax=(Load(expected+208,4)); break;
case 55: eax=(args[0]); Store(expected+208,4,eax); break;
case 56: Store(expected+24,4,0x00000001u); break;
case 57:  break;
case 58: eax=(eax&0xffff0000u)|((Load(expected+24,2))&0xffffu); break;
case 59: eax=(Load(expected+216,1)); break;
case 60: xmm0=args[0]; Store(expected+36,4,xmm0); break;
case 61: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 62: eax=(Load(expected+144,4)); break;
case 63: eax=(args[0]); Store(expected+144,4,eax); break;
case 64: eax=(Load(expected+544,4)); break;
case 65: eax=(args[0]); Store(expected+544,4,eax); break;
case 66: xmm0=0; Store(expected+408,4,xmm0); Store(expected+404,4,xmm0); Store(expected+400,4,xmm0); Store(expected+392,4,xmm0); Store(expected+388,4,xmm0); Store(expected+384,4,xmm0); break;
case 67: xmm0=args[0]; Store(expected+16,4,xmm0); break;
case 68:  break;
case 69:  break;
case 70: eax=(Load(expected+256,4)); break;
case 71: eax=(args[0]); Store(expected+256,4,eax); break;
case 72: eax=(Load(expected+2368,4)); eax=((eax)+(0x00000002u)); break;
case 73: xmm0=args[0]; Store(expected+624,4,xmm0); Store(expected+632,4,xmm0); xmm0=args[1]; Store(expected+628,4,xmm0); Store(expected+636,4,xmm0); break;
case 74: eax=(Load(expected+180,4)); break;
case 75: eax=(args[0]); Store(expected+180,4,eax); break;
case 76: eax=(eax&0xffff0000u)|((Load(expected+20,2))&0xffffu); break;
case 77: eax=(eax&0xffff0000u)|((Load(expected+64,2))&0xffffu); break;
case 78: eax=(0x00000001u); break;
case 79: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 80: eax=(ecx); break;
case 81: eax=(ecx+131124u); break;
case 82: eax=(ecx+131188u); break;
}return eax;}
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;
inline int Check(unsigned i,unsigned sample){
 __try {
  const auto& e=entries[i];const auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  unsigned args[6];for(unsigned n=0;n<6;++n)args[n]=0x87654321u^(sample*0x01020408u)^(n*0x02030405u);
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
inline void Report(const char* phase){FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-pending-scalar.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.pending-scalar-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
inline void Tick(){if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){const int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Pending scalar RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}
}
