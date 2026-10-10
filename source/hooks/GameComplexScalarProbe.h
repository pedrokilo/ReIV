#pragma once
#include <cstring>
namespace gamecomplexscalar {
struct Entry { reiv::original::FunctionAddress binding; unsigned pop; bool floating; unsigned mask; };
inline constexpr unsigned char bytes0[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x33,0xc0,0xf3,0x0f,0x11,0x81,0xa4,0x00,0x00,0x00,0x89,0x81,0xa8,0x00,0x00,0x00,0x89,0x81,0xac,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes1[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x33,0xc0,0xf3,0x0f,0x11,0x81,0xb0,0x00,0x00,0x00,0x89,0x81,0xb4,0x00,0x00,0x00,0x89,0x81,0xb8,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x33,0xc0,0xf3,0x0f,0x11,0x81,0xa4,0x00,0x00,0x00,0xf3,0x0f,0x10,0x44,0x24,0x08,0x89,0x81,0xa8,0x00,0x00,0x00,0x89,0x81,0xac,0x00,0x00,0x00,0xf3,0x0f,0x11,0x81,0xb0,0x00,0x00,0x00,0x89,0x81,0xb4,0x00,0x00,0x00,0x89,0x81,0xb8,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes3[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes5[]={0xb8,0x01,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes6[]={0x8b,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes7[]={0xb8,0x32,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes8[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x38,0xc2,0x04,0x00};
inline constexpr unsigned char bytes9[]={0x8a,0x41,0x34,0xc2,0x04,0x00};
inline constexpr unsigned char bytes10[]={0xc6,0x41,0x10,0xff,0xc3};
inline constexpr unsigned char bytes11[]={0x8b,0x44,0x24,0x04,0xc2,0x04,0x00};
inline constexpr unsigned char bytes12[]={0x8b,0x44,0x24,0x04,0xc2,0x08,0x00};
inline constexpr unsigned char bytes13[]={0x8b,0x41,0x70,0x2b,0x41,0x40,0xc3};
inline constexpr unsigned char bytes14[]={0x33,0xc0,0x89,0x41,0x64,0x89,0x41,0x6c,0x89,0x41,0x74,0x89,0x41,0x7c,0x89,0x81,0x84,0x00,0x00,0x00,0x89,0x81,0x8c,0x00,0x00,0x00,0x89,0x81,0x94,0x00,0x00,0x00,0x89,0x81,0x9c,0x00,0x00,0x00,0x89,0x81,0xa4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes15[]={0xb8,0x0b,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes16[]={0xb8,0xd1,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes17[]={0xb8,0x79,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes18[]={0xb8,0x28,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes19[]={0x33,0xc0,0x89,0x41,0x40,0x89,0x41,0x48,0x89,0x41,0x50,0x89,0x41,0x58,0x89,0x41,0x60,0x89,0x41,0x68,0xc3};
inline constexpr unsigned char bytes20[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x0c,0xc2,0x04,0x00};
inline constexpr unsigned char bytes21[]={0x0f,0xb7,0x81,0xd8,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes22[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x33,0xc0,0xf3,0x0f,0x11,0x81,0xa4,0x00,0x00,0x00,0xf3,0x0f,0x10,0x44,0x24,0x08,0x89,0x81,0xa8,0x00,0x00,0x00,0x89,0x81,0xac,0x00,0x00,0x00,0xf3,0x0f,0x11,0x81,0xb0,0x00,0x00,0x00,0x89,0x81,0xb4,0x00,0x00,0x00,0x89,0x81,0xb8,0x00,0x00,0x00,0x89,0x81,0xd8,0x01,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes23[]={0x8b,0x44,0x24,0x04,0xf3,0x0f,0x10,0x44,0x24,0x08,0x89,0x41,0x14,0xf3,0x0f,0x11,0x41,0x18,0xc2,0x08,0x00};
inline constexpr unsigned char bytes24[]={0x32,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes25[]={0xb0,0x01,0xc2,0x04,0x00};
inline constexpr unsigned char bytes26[]={0xb8,0x01,0x00,0x00,0x00,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes27[]={0x0f,0x57,0xc0,0x83,0x61,0x5c,0xfe,0xf3,0x0f,0x11,0x41,0x50,0xc2,0x04,0x00};
inline constexpr unsigned char bytes28[]={0xb0,0x01,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes29[]={0x0f,0x57,0xc0,0xf3,0x0f,0x11,0x41,0x24,0xb0,0x01,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes30[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x40,0xc2,0x04,0x00};
inline constexpr unsigned char bytes31[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x3c,0xc2,0x04,0x00};
inline constexpr unsigned char bytes32[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x18,0xc2,0x04,0x00};
inline constexpr unsigned char bytes33[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x1c,0xc2,0x04,0x00};
inline constexpr unsigned char bytes34[]={0xc2,0x18,0x00};
inline constexpr unsigned char bytes35[]={0x33,0xc0,0xc2,0x04,0x00};
inline constexpr unsigned char bytes36[]={0x8b,0x41,0x08,0xc2,0x04,0x00};
inline constexpr unsigned char bytes37[]={0x83,0x41,0x34,0x01,0x32,0xc0,0xc3};
inline constexpr unsigned char bytes38[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x6c,0xc2,0x04,0x00};
inline constexpr unsigned char bytes39[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xf0,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes40[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xf0,0x01,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes41[]={0x32,0xc0,0xc2,0x10,0x00};
inline constexpr unsigned char bytes42[]={0x32,0xc0,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes43[]={0x32,0xc0,0xc2,0x08,0x00};
inline constexpr unsigned char bytes44[]={0x33,0xc0,0xc2,0x08,0x00};
inline constexpr unsigned char bytes45[]={0xb8,0x01,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes46[]={0x8b,0x44,0x24,0x08,0xc2,0x08,0x00};
inline constexpr unsigned char bytes47[]={0xb8,0xaf,0x01,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes48[]={0xb8,0x03,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes49[]={0xb8,0xc8,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes50[]={0xb8,0x8b,0x03,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes51[]={0x83,0xc8,0xff,0xc2,0x08,0x00};
inline constexpr unsigned char bytes52[]={0x80,0x61,0x38,0xfd,0xc3};
inline constexpr unsigned char bytes53[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xe0,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes54[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xe4,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes55[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xe8,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes56[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x81,0xec,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes57[]={0xd9,0xee,0xc3};
inline constexpr unsigned char bytes58[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0xf3,0x0f,0x11,0x41,0x38,0xc2,0x04,0x00};
inline constexpr unsigned char bytes59[]={0x81,0x49,0x24,0x00,0x04,0x00,0x00,0xc3};
inline constexpr unsigned char bytes60[]={0x81,0x61,0x50,0xff,0xcf,0xff,0xff,0xc3};
inline constexpr unsigned char bytes61[]={0x33,0xc0,0xc2,0x0c,0x00};
inline constexpr unsigned char bytes62[]={0x8a,0x81,0x3c,0x01,0x00,0x00,0x24,0xf7,0x0c,0x04,0x88,0x81,0x3c,0x01,0x00,0x00,0xb0,0x01,0xc3};
inline constexpr unsigned char bytes63[]={0x8d,0x81,0x20,0x14,0x00,0x00,0xc3};
inline constexpr unsigned char bytes64[]={0xf3,0x0f,0x10,0x44,0x24,0x04,0x33,0xc0,0xf3,0x0f,0x11,0x81,0xa4,0x00,0x00,0x00,0xf3,0x0f,0x10,0x44,0x24,0x08,0x89,0x81,0xa8,0x00,0x00,0x00,0x89,0x81,0xac,0x00,0x00,0x00,0xf3,0x0f,0x11,0x81,0xb0,0x00,0x00,0x00,0x89,0x81,0xb4,0x00,0x00,0x00,0x89,0x81,0xb8,0x00,0x00,0x00,0xc2,0x08,0x00};
inline constexpr unsigned char bytes65[]={0xc6,0x81,0x0e,0x02,0x00,0x00,0x01,0xc2,0x04,0x00};
inline constexpr unsigned char bytes66[]={0xc2,0x14,0x00};
inline constexpr unsigned char bytes67[]={0xc2,0x10,0x00};
inline constexpr unsigned char bytes68[]={0x32,0xc0,0x88,0x81,0x48,0x01,0x00,0x00,0x88,0x81,0x49,0x01,0x00,0x00,0xb8,0xe8,0x03,0x00,0x00,0x89,0x81,0x40,0x01,0x00,0x00,0x89,0x81,0x44,0x01,0x00,0x00,0xb0,0x01,0xc3};
inline constexpr unsigned char bytes69[]={0x0f,0xb7,0x41,0x18,0xc3};
inline const Entry entries[]={
{{"Pending scalar 0x00435470",0x00035470,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x004354D0",0x000354D0,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00435520",0x00035520,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00435660",0x00035660,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00435680",0x00035680,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00447B40",0x00047B40,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004496C0",0x000496C0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00454080",0x00054080,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004579A0",0x000579A0,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x0048D8D0",0x0008D8D0,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},4,false,0x000000ffu},
{{"Pending scalar 0x0049F3E0",0x0009F3E0,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x004A22B0",0x000A22B0,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x004A22C0",0x000A22C0,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004A4EA0",0x000A4EA0,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x004E4450",0x000E4450,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x004E6860",0x000E6860,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004E71E0",0x000E71E0,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004E8750",0x000E8750,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x004F54F0",0x000F54F0,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x004FB550",0x000FB550,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x00703530",0x00303530,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x007C55D0",0x003C55D0,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x008259D0",0x004259D0,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x008399E0",0x004399E0,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x008B8740",0x004B8740,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},4,false,0x000000ffu},
{{"Pending scalar 0x00919B60",0x00519B60,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},4,false,0x000000ffu},
{{"Pending scalar 0x00948FD0",0x00548FD0,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x0094EA70",0x0054EA70,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x009AE3C0",0x005AE3C0,bytes28,sizeof(bytes28),reiv::original::BindingState::StaticVerified},12,false,0x000000ffu},
{{"Pending scalar 0x009AE480",0x005AE480,bytes29,sizeof(bytes29),reiv::original::BindingState::StaticVerified},12,false,0x000000ffu},
{{"Pending scalar 0x009F0B90",0x005F0B90,bytes30,sizeof(bytes30),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A0B900",0x0060B900,bytes31,sizeof(bytes31),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A18BF0",0x00618BF0,bytes32,sizeof(bytes32),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A18C00",0x00618C00,bytes33,sizeof(bytes33),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A1B140",0x0061B140,bytes34,sizeof(bytes34),reiv::original::BindingState::StaticVerified},24,false,0x00000000u},
{{"Pending scalar 0x00A1E350",0x0061E350,bytes35,sizeof(bytes35),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00A1E860",0x0061E860,bytes36,sizeof(bytes36),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00A2BF10",0x0062BF10,bytes37,sizeof(bytes37),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Pending scalar 0x00A353F0",0x006353F0,bytes38,sizeof(bytes38),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A47930",0x00647930,bytes39,sizeof(bytes39),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00A47950",0x00647950,bytes40,sizeof(bytes40),reiv::original::BindingState::StaticVerified},8,false,0x00000000u},
{{"Pending scalar 0x00A6DD60",0x0066DD60,bytes41,sizeof(bytes41),reiv::original::BindingState::StaticVerified},16,false,0x000000ffu},
{{"Pending scalar 0x00A6DD70",0x0066DD70,bytes42,sizeof(bytes42),reiv::original::BindingState::StaticVerified},12,false,0x000000ffu},
{{"Pending scalar 0x00A6DD80",0x0066DD80,bytes43,sizeof(bytes43),reiv::original::BindingState::StaticVerified},8,false,0x000000ffu},
{{"Pending scalar 0x00A75BE0",0x00675BE0,bytes44,sizeof(bytes44),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A75DB0",0x00675DB0,bytes45,sizeof(bytes45),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A75E50",0x00675E50,bytes46,sizeof(bytes46),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A760C0",0x006760C0,bytes47,sizeof(bytes47),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A76740",0x00676740,bytes48,sizeof(bytes48),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A769F0",0x006769F0,bytes49,sizeof(bytes49),reiv::original::BindingState::StaticVerified},4,false,0xffffffffu},
{{"Pending scalar 0x00A76A00",0x00676A00,bytes50,sizeof(bytes50),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00A77700",0x00677700,bytes51,sizeof(bytes51),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00AB9A60",0x006B9A60,bytes52,sizeof(bytes52),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00B4EA60",0x0074EA60,bytes53,sizeof(bytes53),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00B4EA80",0x0074EA80,bytes54,sizeof(bytes54),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00B4EEC0",0x0074EEC0,bytes55,sizeof(bytes55),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00B4EEE0",0x0074EEE0,bytes56,sizeof(bytes56),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00B781A0",0x007781A0,bytes57,sizeof(bytes57),reiv::original::BindingState::StaticVerified},0,true,0xffffffffu},
{{"Pending scalar 0x00B86530",0x00786530,bytes58,sizeof(bytes58),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00BC64C0",0x007C64C0,bytes59,sizeof(bytes59),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00BC97D0",0x007C97D0,bytes60,sizeof(bytes60),reiv::original::BindingState::StaticVerified},0,false,0x00000000u},
{{"Pending scalar 0x00BCC9F0",0x007CC9F0,bytes61,sizeof(bytes61),reiv::original::BindingState::StaticVerified},12,false,0xffffffffu},
{{"Pending scalar 0x00BE1080",0x007E1080,bytes62,sizeof(bytes62),reiv::original::BindingState::StaticVerified},0,false,0x000000ffu},
{{"Pending scalar 0x00C03390",0x00803390,bytes63,sizeof(bytes63),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x00C128B0",0x008128B0,bytes64,sizeof(bytes64),reiv::original::BindingState::StaticVerified},8,false,0xffffffffu},
{{"Pending scalar 0x00C427F0",0x008427F0,bytes65,sizeof(bytes65),reiv::original::BindingState::StaticVerified},4,false,0x00000000u},
{{"Pending scalar 0x00C4C720",0x0084C720,bytes66,sizeof(bytes66),reiv::original::BindingState::StaticVerified},20,false,0x00000000u},
{{"Pending scalar 0x00C71460",0x00871460,bytes67,sizeof(bytes67),reiv::original::BindingState::StaticVerified},16,false,0x00000000u},
{{"Pending scalar 0x00C93E40",0x00893E40,bytes68,sizeof(bytes68),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
{{"Pending scalar 0x00CCEB10",0x008CEB10,bytes69,sizeof(bytes69),reiv::original::BindingState::StaticVerified},0,false,0xffffffffu},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline unsigned Load(const unsigned char* p,unsigned n){unsigned v=0;memcpy(&v,p,n);return v;}
inline void Store(unsigned char* p,unsigned n,unsigned v){memcpy(p,&v,n);}
inline unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args){unsigned eax=0,edx=0,xmm0=0;switch(i){
case 0: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); Store(expected+168,4,eax); Store(expected+172,4,eax); break;
case 1: xmm0=args[0]; eax=(0); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 2: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 3: xmm0=args[0]; Store(expected+4,4,xmm0); break;
case 4: xmm0=args[0]; Store(expected+8,4,xmm0); break;
case 5: eax=(0x00000001u); break;
case 6: eax=(Load(expected+8,4)); break;
case 7: eax=(0x00000032u); break;
case 8: xmm0=args[0]; Store(expected+56,4,xmm0); break;
case 9: eax=(eax&0xffffff00u)|((Load(expected+52,1))&0xffu); break;
case 10: Store(expected+16,1,0x000000ffu); break;
case 11: eax=(args[0]); break;
case 12: eax=(args[0]); break;
case 13: eax=(Load(expected+112,4)); eax=((eax)-(Load(expected+64,4))); break;
case 14: eax=(0); Store(expected+100,4,eax); Store(expected+108,4,eax); Store(expected+116,4,eax); Store(expected+124,4,eax); Store(expected+132,4,eax); Store(expected+140,4,eax); Store(expected+148,4,eax); Store(expected+156,4,eax); Store(expected+164,4,eax); break;
case 15: eax=(0x0000000bu); break;
case 16: eax=(0x000000d1u); break;
case 17: eax=(0x00000079u); break;
case 18: eax=(0x00000028u); break;
case 19: eax=(0); Store(expected+64,4,eax); Store(expected+72,4,eax); Store(expected+80,4,eax); Store(expected+88,4,eax); Store(expected+96,4,eax); Store(expected+104,4,eax); break;
case 20: xmm0=args[0]; Store(expected+12,4,xmm0); break;
case 21: eax=(Load(expected+472,2)); break;
case 22: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); Store(expected+472,4,eax); break;
case 23: eax=(args[0]); xmm0=args[1]; Store(expected+20,4,eax); Store(expected+24,4,xmm0); break;
case 24: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 25: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 26: eax=(0x00000001u); break;
case 27: xmm0=0; Store(expected+92,4,(Load(expected+92,4))&(0xfffffffeu)); Store(expected+80,4,xmm0); break;
case 28: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 29: xmm0=0; Store(expected+36,4,xmm0); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 30: xmm0=args[0]; Store(expected+64,4,xmm0); break;
case 31: xmm0=args[0]; Store(expected+60,4,xmm0); break;
case 32: xmm0=args[0]; Store(expected+24,4,xmm0); break;
case 33: xmm0=args[0]; Store(expected+28,4,xmm0); break;
case 34:  break;
case 35: eax=(0); break;
case 36: eax=(Load(expected+8,4)); break;
case 37: Store(expected+52,4,(Load(expected+52,4))+(0x00000001u)); eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 38: xmm0=args[0]; Store(expected+108,4,xmm0); break;
case 39: xmm0=args[0]; Store(expected+496,4,xmm0); break;
case 40: xmm0=args[0]; Store(expected+496,4,xmm0); break;
case 41: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 42: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 43: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 44: eax=(0); break;
case 45: eax=(0x00000001u); break;
case 46: eax=(args[1]); break;
case 47: eax=(0x000001afu); break;
case 48: eax=(0x00000003u); break;
case 49: eax=(0x000000c8u); break;
case 50: eax=(0x0000038bu); break;
case 51: eax=(0xffffffffu); break;
case 52: Store(expected+56,1,(Load(expected+56,1))&(0x000000fdu)); break;
case 53: xmm0=args[0]; Store(expected+480,4,xmm0); break;
case 54: xmm0=args[0]; Store(expected+484,4,xmm0); break;
case 55: xmm0=args[0]; Store(expected+488,4,xmm0); break;
case 56: xmm0=args[0]; Store(expected+492,4,xmm0); break;
case 57:  break;
case 58: xmm0=args[0]; Store(expected+56,4,xmm0); break;
case 59: Store(expected+36,4,(Load(expected+36,4))|(0x00000400u)); break;
case 60: Store(expected+80,4,(Load(expected+80,4))&(0xffffcfffu)); break;
case 61: eax=(0); break;
case 62: eax=(eax&0xffffff00u)|((Load(expected+316,1))&0xffu); eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000f7u))&0xffu); eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000004u))&0xffu); Store(expected+316,1,(eax&0xffu)); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 63: eax=(ecx+5152u); break;
case 64: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 65: Store(expected+526,1,0x00000001u); break;
case 66:  break;
case 67:  break;
case 68: eax=(eax&0xffffff00u)|((0)&0xffu); Store(expected+328,1,(eax&0xffu)); Store(expected+329,1,(eax&0xffu)); eax=(0x000003e8u); Store(expected+320,4,eax); Store(expected+324,4,eax); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 69: eax=(Load(expected+24,2)); break;
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
inline void Report(const char* phase){FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-game-complex-scalar.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
inline void Tick(){if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){const int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Game complex scalar RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}
}
