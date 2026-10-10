#pragma once
#include <cstring>
namespace gamepending {
enum class Operation { address_offset,compare_u32,get_float,get_pair,get_u32,get_u8,identity_this,outputs_minus_one,set_pair,set_u32,set_u8 };
struct Entry { reiv::original::FunctionAddress binding; Operation operation; unsigned offset; };
inline constexpr unsigned char bytes0[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xca,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes1[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xd0,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes2[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xd1,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes3[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xe8,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes4[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xe9,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes5[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xea,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes6[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xeb,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes7[]={0x8b,0x81,0x9c,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes8[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xa0,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes9[]={0xd9,0x41,0x18,0xc3};
inline constexpr unsigned char bytes10[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x14,0xc2,0x04,0x00};
inline constexpr unsigned char bytes11[]={0x8d,0x81,0xa4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes12[]={0xd9,0x81,0xa4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes13[]={0xd9,0x81,0xb0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes14[]={0xd9,0x41,0x04,0xc3};
inline constexpr unsigned char bytes15[]={0xd9,0x41,0x08,0xc3};
inline constexpr unsigned char bytes16[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc8,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes17[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc4,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes18[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc5,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes19[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc6,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes20[]={0x8a,0x81,0xc9,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes21[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc9,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes22[]={0x8a,0x81,0xca,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes23[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xc7,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes24[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xd4,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes25[]={0x8b,0x81,0xd4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes26[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xd8,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes27[]={0x8b,0x81,0xd8,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes28[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xdc,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes29[]={0x8b,0x81,0xdc,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes30[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xe0,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes31[]={0x8b,0x81,0xe0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes32[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xe4,0x00,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes33[]={0x8b,0x81,0xe4,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes34[]={0xd9,0x81,0xf0,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes35[]={0x8b,0x81,0x1c,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes36[]={0x8b,0x81,0xbc,0x07,0x00,0x00,0xc3};
inline constexpr unsigned char bytes37[]={0x8b,0x81,0xc4,0x07,0x00,0x00,0xc3};
inline constexpr unsigned char bytes38[]={0x8b,0x41,0x3c,0xc3};
inline constexpr unsigned char bytes39[]={0x8d,0x81,0xf0,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes40[]={0x8d,0x81,0x30,0x03,0x00,0x00,0xc3};
inline constexpr unsigned char bytes41[]={0xd9,0x41,0x34,0xc3};
inline constexpr unsigned char bytes42[]={0x8b,0x41,0x18,0xc3};
inline constexpr unsigned char bytes43[]={0x8a,0x81,0x1d,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes44[]={0x8a,0x81,0x1c,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes45[]={0x8b,0x41,0x04,0xc3};
inline constexpr unsigned char bytes46[]={0x8d,0x81,0x08,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes47[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x10,0xc2,0x04,0x00};
inline constexpr unsigned char bytes48[]={0x8b,0x41,0x14,0xc3};
inline constexpr unsigned char bytes49[]={0x8d,0x41,0x7c,0xc3};
inline constexpr unsigned char bytes50[]={0x8d,0x41,0x44,0xc3};
inline constexpr unsigned char bytes51[]={0x8d,0x81,0x18,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes52[]={0x8d,0x41,0x20,0xc3};
inline constexpr unsigned char bytes53[]={0x8d,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes54[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xdc,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes55[]={0x8d,0x81,0xd4,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes56[]={0x8b,0x81,0xec,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes57[]={0x8a,0x41,0x0c,0xc3};
inline constexpr unsigned char bytes58[]={0xd9,0x41,0x10,0xc3};
inline constexpr unsigned char bytes59[]={0x8b,0x81,0x14,0x0e,0x00,0x00,0xc3};
inline constexpr unsigned char bytes60[]={0x8b,0x81,0x60,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes61[]={0x8b,0x41,0x20,0xc3};
inline constexpr unsigned char bytes62[]={0xd9,0x41,0x14,0xc3};
inline constexpr unsigned char bytes63[]={0x8b,0x41,0x70,0xc3};
inline constexpr unsigned char bytes64[]={0x8b,0x41,0x78,0xc3};
inline constexpr unsigned char bytes65[]={0x8d,0x41,0x60,0xc3};
inline constexpr unsigned char bytes66[]={0x8b,0x81,0x54,0x09,0x00,0x00,0xc3};
inline constexpr unsigned char bytes67[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x14,0xc2,0x04,0x00};
inline constexpr unsigned char bytes68[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x18,0xc2,0x04,0x00};
inline constexpr unsigned char bytes69[]={0x8b,0x81,0xbc,0x0e,0x00,0x00,0xc3};
inline constexpr unsigned char bytes70[]={0x8d,0x81,0xc0,0x0e,0x00,0x00,0xc3};
inline constexpr unsigned char bytes71[]={0x8d,0x81,0xd0,0x0e,0x00,0x00,0xc3};
inline constexpr unsigned char bytes72[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xbc,0x0e,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes73[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xf0,0x0e,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes74[]={0x8b,0x81,0x70,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes75[]={0xd9,0x41,0x3c,0xc3};
inline constexpr unsigned char bytes76[]={0x8d,0x81,0x90,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes77[]={0x8d,0x41,0x40,0xc3};
inline constexpr unsigned char bytes78[]={0xd9,0x41,0x30,0xc3};
inline constexpr unsigned char bytes79[]={0xd9,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes80[]={0xd9,0x81,0x8c,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes81[]={0xd9,0x41,0x50,0xc3};
inline constexpr unsigned char bytes82[]={0x8b,0x44,0x24,0x04,0x89,0x41,0x38,0xc2,0x04,0x00};
inline constexpr unsigned char bytes83[]={0xd9,0x41,0x6c,0xc3};
inline constexpr unsigned char bytes84[]={0x8d,0x81,0xb0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes85[]={0x8b,0x41,0x38,0xc3};
inline constexpr unsigned char bytes86[]={0x8b,0x41,0x1c,0xc3};
inline constexpr unsigned char bytes87[]={0x8b,0x81,0xa4,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes88[]={0x8d,0x41,0x50,0xc3};
inline constexpr unsigned char bytes89[]={0x8a,0x44,0x24,0x04,0x88,0x81,0x0d,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes90[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xf4,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes91[]={0x8a,0x44,0x24,0x04,0x88,0x81,0x08,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes92[]={0x8a,0x44,0x24,0x04,0x88,0x81,0x09,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes93[]={0x8a,0x44,0x24,0x04,0x88,0x81,0x0a,0x02,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes94[]={0x8d,0x81,0x0e,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes95[]={0x8d,0x81,0x00,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes96[]={0x8b,0x81,0x40,0x09,0x00,0x00,0xc3};
inline constexpr unsigned char bytes97[]={0xd9,0x41,0x34,0xc3};
inline constexpr unsigned char bytes98[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x10,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes99[]={0x8b,0x81,0x10,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes100[]={0x8a,0x44,0x24,0x04,0x88,0x81,0x14,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes101[]={0x8a,0x81,0x14,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes102[]={0x8b,0x81,0x04,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes103[]={0x8b,0x81,0x84,0x03,0x00,0x00,0xc3};
inline constexpr unsigned char bytes104[]={0x8b,0x81,0xec,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes105[]={0x8b,0x81,0xe8,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes106[]={0x8a,0x81,0xf8,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes107[]={0x8d,0x81,0xf8,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes108[]={0xd9,0x81,0xfc,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes109[]={0x8a,0x81,0xe0,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes110[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xe0,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes111[]={0xd9,0x81,0xe4,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes112[]={0x8a,0x81,0xef,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes113[]={0x8d,0x81,0xf0,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes114[]={0x8d,0x81,0x00,0x03,0x00,0x00,0xc3};
inline constexpr unsigned char bytes115[]={0xd9,0x81,0xe0,0x02,0x00,0x00,0xc3};
inline constexpr unsigned char bytes116[]={0x8b,0x81,0xa0,0x09,0x00,0x00,0xc3};
inline constexpr unsigned char bytes117[]={0x8b,0x81,0x40,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes118[]={0x8b,0x81,0xf0,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes119[]={0x8b,0x41,0x0c,0xc3};
inline constexpr unsigned char bytes120[]={0x8b,0x41,0x10,0xc3};
inline constexpr unsigned char bytes121[]={0xd9,0x41,0x18,0xc3};
inline constexpr unsigned char bytes122[]={0xd9,0x41,0x78,0xc3};
inline constexpr unsigned char bytes123[]={0xd9,0x81,0x88,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes124[]={0x8a,0x41,0x5c,0xc3};
inline constexpr unsigned char bytes125[]={0x8a,0x81,0xa1,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes126[]={0x8a,0x41,0x54,0xc3};
inline constexpr unsigned char bytes127[]={0x8b,0x41,0x50,0xc3};
inline constexpr unsigned char bytes128[]={0x8b,0x81,0xa0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes129[]={0x8b,0x81,0xb8,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes130[]={0x8d,0x81,0xc0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes131[]={0x8b,0x81,0xb0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes132[]={0x8b,0x44,0x24,0x04,0x89,0x81,0xe8,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes133[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xec,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes134[]={0x8a,0x81,0xec,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes135[]={0x8b,0x81,0xf4,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes136[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xef,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes137[]={0x8a,0x44,0x24,0x04,0x88,0x81,0xf0,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes138[]={0x8b,0x41,0x30,0xc3};
inline constexpr unsigned char bytes139[]={0x8d,0x81,0xa0,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes140[]={0x8b,0x41,0x18,0xc3};
inline constexpr unsigned char bytes141[]={0x8d,0x81,0xc5,0x00,0x00,0x00,0xc3};
inline constexpr unsigned char bytes142[]={0x8d,0x81,0x05,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes143[]={0x8b,0x81,0x48,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes144[]={0x8b,0x81,0x4c,0x01,0x00,0x00,0xc3};
inline constexpr unsigned char bytes145[]={0x8b,0x44,0x24,0x04,0x89,0x81,0x4c,0x01,0x00,0x00,0xc2,0x04,0x00};
inline constexpr unsigned char bytes146[]={0x8a,0x44,0x24,0x04,0x88,0x41,0x41,0xc2,0x04,0x00};
inline constexpr unsigned char bytes147[]={0x8a,0x41,0x41,0xc3};
inline const Entry entries[]={
{{"Game pending 0x004352c0",0x000352c0,bytes0,sizeof(bytes0),reiv::original::BindingState::StaticVerified},Operation::set_u8,202},
{{"Game pending 0x00435300",0x00035300,bytes1,sizeof(bytes1),reiv::original::BindingState::StaticVerified},Operation::set_u8,208},
{{"Game pending 0x00435310",0x00035310,bytes2,sizeof(bytes2),reiv::original::BindingState::StaticVerified},Operation::set_u8,209},
{{"Game pending 0x00435340",0x00035340,bytes3,sizeof(bytes3),reiv::original::BindingState::StaticVerified},Operation::set_u8,232},
{{"Game pending 0x00435350",0x00035350,bytes4,sizeof(bytes4),reiv::original::BindingState::StaticVerified},Operation::set_u8,233},
{{"Game pending 0x00435360",0x00035360,bytes5,sizeof(bytes5),reiv::original::BindingState::StaticVerified},Operation::set_u8,234},
{{"Game pending 0x004353a0",0x000353a0,bytes6,sizeof(bytes6),reiv::original::BindingState::StaticVerified},Operation::set_u8,235},
{{"Game pending 0x004353b0",0x000353b0,bytes7,sizeof(bytes7),reiv::original::BindingState::StaticVerified},Operation::get_u32,156},
{{"Game pending 0x004353f0",0x000353f0,bytes8,sizeof(bytes8),reiv::original::BindingState::StaticVerified},Operation::set_u32,160},
{{"Game pending 0x00435400",0x00035400,bytes9,sizeof(bytes9),reiv::original::BindingState::StaticVerified},Operation::get_float,24},
{{"Game pending 0x00435410",0x00035410,bytes10,sizeof(bytes10),reiv::original::BindingState::StaticVerified},Operation::set_u32,20},
{{"Game pending 0x00435450",0x00035450,bytes11,sizeof(bytes11),reiv::original::BindingState::StaticVerified},Operation::address_offset,164},
{{"Game pending 0x00435630",0x00035630,bytes12,sizeof(bytes12),reiv::original::BindingState::StaticVerified},Operation::get_float,164},
{{"Game pending 0x00435640",0x00035640,bytes13,sizeof(bytes13),reiv::original::BindingState::StaticVerified},Operation::get_float,176},
{{"Game pending 0x00435650",0x00035650,bytes14,sizeof(bytes14),reiv::original::BindingState::StaticVerified},Operation::get_float,4},
{{"Game pending 0x00435670",0x00035670,bytes15,sizeof(bytes15),reiv::original::BindingState::StaticVerified},Operation::get_float,8},
{{"Game pending 0x00435710",0x00035710,bytes16,sizeof(bytes16),reiv::original::BindingState::StaticVerified},Operation::set_u8,200},
{{"Game pending 0x00435720",0x00035720,bytes17,sizeof(bytes17),reiv::original::BindingState::StaticVerified},Operation::set_u8,196},
{{"Game pending 0x00435740",0x00035740,bytes18,sizeof(bytes18),reiv::original::BindingState::StaticVerified},Operation::set_u8,197},
{{"Game pending 0x00435760",0x00035760,bytes19,sizeof(bytes19),reiv::original::BindingState::StaticVerified},Operation::set_u8,198},
{{"Game pending 0x00435780",0x00035780,bytes20,sizeof(bytes20),reiv::original::BindingState::StaticVerified},Operation::get_u8,201},
{{"Game pending 0x00435790",0x00035790,bytes21,sizeof(bytes21),reiv::original::BindingState::StaticVerified},Operation::set_u8,201},
{{"Game pending 0x004357a0",0x000357a0,bytes22,sizeof(bytes22),reiv::original::BindingState::StaticVerified},Operation::get_u8,202},
{{"Game pending 0x004357b0",0x000357b0,bytes23,sizeof(bytes23),reiv::original::BindingState::StaticVerified},Operation::set_u8,199},
{{"Game pending 0x00435810",0x00035810,bytes24,sizeof(bytes24),reiv::original::BindingState::StaticVerified},Operation::set_u32,212},
{{"Game pending 0x00435820",0x00035820,bytes25,sizeof(bytes25),reiv::original::BindingState::StaticVerified},Operation::get_u32,212},
{{"Game pending 0x00435830",0x00035830,bytes26,sizeof(bytes26),reiv::original::BindingState::StaticVerified},Operation::set_u32,216},
{{"Game pending 0x00435840",0x00035840,bytes27,sizeof(bytes27),reiv::original::BindingState::StaticVerified},Operation::get_u32,216},
{{"Game pending 0x00435850",0x00035850,bytes28,sizeof(bytes28),reiv::original::BindingState::StaticVerified},Operation::set_u32,220},
{{"Game pending 0x00435860",0x00035860,bytes29,sizeof(bytes29),reiv::original::BindingState::StaticVerified},Operation::get_u32,220},
{{"Game pending 0x00435870",0x00035870,bytes30,sizeof(bytes30),reiv::original::BindingState::StaticVerified},Operation::set_u32,224},
{{"Game pending 0x00435880",0x00035880,bytes31,sizeof(bytes31),reiv::original::BindingState::StaticVerified},Operation::get_u32,224},
{{"Game pending 0x00435890",0x00035890,bytes32,sizeof(bytes32),reiv::original::BindingState::StaticVerified},Operation::set_u32,228},
{{"Game pending 0x004358a0",0x000358a0,bytes33,sizeof(bytes33),reiv::original::BindingState::StaticVerified},Operation::get_u32,228},
{{"Game pending 0x00447b30",0x00047b30,bytes34,sizeof(bytes34),reiv::original::BindingState::StaticVerified},Operation::get_float,496},
{{"Game pending 0x00447b90",0x00047b90,bytes35,sizeof(bytes35),reiv::original::BindingState::StaticVerified},Operation::get_u32,540},
{{"Game pending 0x00447c00",0x00047c00,bytes36,sizeof(bytes36),reiv::original::BindingState::StaticVerified},Operation::get_u32,1980},
{{"Game pending 0x00447c10",0x00047c10,bytes37,sizeof(bytes37),reiv::original::BindingState::StaticVerified},Operation::get_u32,1988},
{{"Game pending 0x00448450",0x00048450,bytes38,sizeof(bytes38),reiv::original::BindingState::StaticVerified},Operation::get_u32,60},
{{"Game pending 0x00451a00",0x00051a00,bytes39,sizeof(bytes39),reiv::original::BindingState::StaticVerified},Operation::address_offset,752},
{{"Game pending 0x00451a10",0x00051a10,bytes40,sizeof(bytes40),reiv::original::BindingState::StaticVerified},Operation::address_offset,816},
{{"Game pending 0x00457940",0x00057940,bytes41,sizeof(bytes41),reiv::original::BindingState::StaticVerified},Operation::get_float,52},
{{"Game pending 0x0045a970",0x0005a970,bytes42,sizeof(bytes42),reiv::original::BindingState::StaticVerified},Operation::get_u32,24},
{{"Game pending 0x00493fe0",0x00093fe0,bytes43,sizeof(bytes43),reiv::original::BindingState::StaticVerified},Operation::get_u8,285},
{{"Game pending 0x00493ff0",0x00093ff0,bytes44,sizeof(bytes44),reiv::original::BindingState::StaticVerified},Operation::get_u8,284},
{{"Game pending 0x00496870",0x00096870,bytes45,sizeof(bytes45),reiv::original::BindingState::StaticVerified},Operation::get_u32,4},
{{"Game pending 0x00496ea0",0x00096ea0,bytes46,sizeof(bytes46),reiv::original::BindingState::StaticVerified},Operation::address_offset,264},
{{"Game pending 0x0049f3d0",0x0009f3d0,bytes47,sizeof(bytes47),reiv::original::BindingState::StaticVerified},Operation::set_u8,16},
{{"Game pending 0x004a10f0",0x000a10f0,bytes48,sizeof(bytes48),reiv::original::BindingState::StaticVerified},Operation::get_u32,20},
{{"Game pending 0x004d9500",0x000d9500,bytes49,sizeof(bytes49),reiv::original::BindingState::StaticVerified},Operation::address_offset,124},
{{"Game pending 0x004e4530",0x000e4530,bytes50,sizeof(bytes50),reiv::original::BindingState::StaticVerified},Operation::address_offset,68},
{{"Game pending 0x004f4d10",0x000f4d10,bytes51,sizeof(bytes51),reiv::original::BindingState::StaticVerified},Operation::address_offset,280},
{{"Game pending 0x004fb660",0x000fb660,bytes52,sizeof(bytes52),reiv::original::BindingState::StaticVerified},Operation::address_offset,32},
{{"Game pending 0x0050f2f0",0x0010f2f0,bytes53,sizeof(bytes53),reiv::original::BindingState::StaticVerified},Operation::address_offset,28},
{{"Game pending 0x007c4160",0x003c4160,bytes54,sizeof(bytes54),reiv::original::BindingState::StaticVerified},Operation::set_u32,476},
{{"Game pending 0x007c4170",0x003c4170,bytes55,sizeof(bytes55),reiv::original::BindingState::StaticVerified},Operation::address_offset,468},
{{"Game pending 0x00839a00",0x00439a00,bytes56,sizeof(bytes56),reiv::original::BindingState::StaticVerified},Operation::get_u32,236},
{{"Game pending 0x0088f6b0",0x0048f6b0,bytes57,sizeof(bytes57),reiv::original::BindingState::StaticVerified},Operation::get_u8,12},
{{"Game pending 0x00897d50",0x00497d50,bytes58,sizeof(bytes58),reiv::original::BindingState::StaticVerified},Operation::get_float,16},
{{"Game pending 0x008b86c0",0x004b86c0,bytes59,sizeof(bytes59),reiv::original::BindingState::StaticVerified},Operation::get_u32,3604},
{{"Game pending 0x008e05b0",0x004e05b0,bytes60,sizeof(bytes60),reiv::original::BindingState::StaticVerified},Operation::get_u32,608},
{{"Game pending 0x00918170",0x00518170,bytes61,sizeof(bytes61),reiv::original::BindingState::StaticVerified},Operation::get_u32,32},
{{"Game pending 0x00919ef0",0x00519ef0,bytes62,sizeof(bytes62),reiv::original::BindingState::StaticVerified},Operation::get_float,20},
{{"Game pending 0x00988e60",0x00588e60,bytes63,sizeof(bytes63),reiv::original::BindingState::StaticVerified},Operation::get_u32,112},
{{"Game pending 0x00988e70",0x00588e70,bytes64,sizeof(bytes64),reiv::original::BindingState::StaticVerified},Operation::get_u32,120},
{{"Game pending 0x00989130",0x00589130,bytes65,sizeof(bytes65),reiv::original::BindingState::StaticVerified},Operation::address_offset,96},
{{"Game pending 0x00990d70",0x00590d70,bytes66,sizeof(bytes66),reiv::original::BindingState::StaticVerified},Operation::get_u32,2388},
{{"Game pending 0x009a03e0",0x005a03e0,bytes67,sizeof(bytes67),reiv::original::BindingState::StaticVerified},Operation::set_u32,20},
{{"Game pending 0x009a56c0",0x005a56c0,bytes68,sizeof(bytes68),reiv::original::BindingState::StaticVerified},Operation::set_u32,24},
{{"Game pending 0x009c1c90",0x005c1c90,bytes69,sizeof(bytes69),reiv::original::BindingState::StaticVerified},Operation::get_u32,3772},
{{"Game pending 0x009c1ca0",0x005c1ca0,bytes70,sizeof(bytes70),reiv::original::BindingState::StaticVerified},Operation::address_offset,3776},
{{"Game pending 0x009c1cb0",0x005c1cb0,bytes71,sizeof(bytes71),reiv::original::BindingState::StaticVerified},Operation::address_offset,3792},
{{"Game pending 0x009c1cc0",0x005c1cc0,bytes72,sizeof(bytes72),reiv::original::BindingState::StaticVerified},Operation::set_u32,3772},
{{"Game pending 0x009c1cd0",0x005c1cd0,bytes73,sizeof(bytes73),reiv::original::BindingState::StaticVerified},Operation::set_u32,3824},
{{"Game pending 0x009d6a70",0x005d6a70,bytes74,sizeof(bytes74),reiv::original::BindingState::StaticVerified},Operation::get_u32,368},
{{"Game pending 0x009f5c70",0x005f5c70,bytes75,sizeof(bytes75),reiv::original::BindingState::StaticVerified},Operation::get_float,60},
{{"Game pending 0x00a0a070",0x0060a070,bytes76,sizeof(bytes76),reiv::original::BindingState::StaticVerified},Operation::address_offset,144},
{{"Game pending 0x00a0a2f0",0x0060a2f0,bytes77,sizeof(bytes77),reiv::original::BindingState::StaticVerified},Operation::address_offset,64},
{{"Game pending 0x00a0a5b0",0x0060a5b0,bytes78,sizeof(bytes78),reiv::original::BindingState::StaticVerified},Operation::get_float,48},
{{"Game pending 0x00a0a630",0x0060a630,bytes79,sizeof(bytes79),reiv::original::BindingState::StaticVerified},Operation::get_float,28},
{{"Game pending 0x00a0eba0",0x0060eba0,bytes80,sizeof(bytes80),reiv::original::BindingState::StaticVerified},Operation::get_float,140},
{{"Game pending 0x00a1ec80",0x0061ec80,bytes81,sizeof(bytes81),reiv::original::BindingState::StaticVerified},Operation::get_float,80},
{{"Game pending 0x00a2c5b0",0x0062c5b0,bytes82,sizeof(bytes82),reiv::original::BindingState::StaticVerified},Operation::set_u32,56},
{{"Game pending 0x00a353e0",0x006353e0,bytes83,sizeof(bytes83),reiv::original::BindingState::StaticVerified},Operation::get_float,108},
{{"Game pending 0x00a3c6d0",0x0063c6d0,bytes84,sizeof(bytes84),reiv::original::BindingState::StaticVerified},Operation::address_offset,176},
{{"Game pending 0x00a624f0",0x006624f0,bytes85,sizeof(bytes85),reiv::original::BindingState::StaticVerified},Operation::get_u32,56},
{{"Game pending 0x00abc570",0x006bc570,bytes86,sizeof(bytes86),reiv::original::BindingState::StaticVerified},Operation::get_u32,28},
{{"Game pending 0x00b2c9f0",0x0072c9f0,bytes87,sizeof(bytes87),reiv::original::BindingState::StaticVerified},Operation::get_u32,676},
{{"Game pending 0x00b42fb0",0x00742fb0,bytes88,sizeof(bytes88),reiv::original::BindingState::StaticVerified},Operation::address_offset,80},
{{"Game pending 0x00b4ef00",0x0074ef00,bytes89,sizeof(bytes89),reiv::original::BindingState::StaticVerified},Operation::set_u8,525},
{{"Game pending 0x00b4ef10",0x0074ef10,bytes90,sizeof(bytes90),reiv::original::BindingState::StaticVerified},Operation::set_u32,500},
{{"Game pending 0x00b4ef20",0x0074ef20,bytes91,sizeof(bytes91),reiv::original::BindingState::StaticVerified},Operation::set_u8,520},
{{"Game pending 0x00b4ef30",0x0074ef30,bytes92,sizeof(bytes92),reiv::original::BindingState::StaticVerified},Operation::set_u8,521},
{{"Game pending 0x00b4ef40",0x0074ef40,bytes93,sizeof(bytes93),reiv::original::BindingState::StaticVerified},Operation::set_u8,522},
{{"Game pending 0x00b4ef50",0x0074ef50,bytes94,sizeof(bytes94),reiv::original::BindingState::StaticVerified},Operation::address_offset,526},
{{"Game pending 0x00b4ef60",0x0074ef60,bytes95,sizeof(bytes95),reiv::original::BindingState::StaticVerified},Operation::address_offset,512},
{{"Game pending 0x00b53bc0",0x00753bc0,bytes96,sizeof(bytes96),reiv::original::BindingState::StaticVerified},Operation::get_u32,2368},
{{"Game pending 0x00b864f0",0x007864f0,bytes97,sizeof(bytes97),reiv::original::BindingState::StaticVerified},Operation::get_float,52},
{{"Game pending 0x00bc5cb0",0x007c5cb0,bytes98,sizeof(bytes98),reiv::original::BindingState::StaticVerified},Operation::set_u32,272},
{{"Game pending 0x00bc7770",0x007c7770,bytes99,sizeof(bytes99),reiv::original::BindingState::StaticVerified},Operation::get_u32,272},
{{"Game pending 0x00bc7780",0x007c7780,bytes100,sizeof(bytes100),reiv::original::BindingState::StaticVerified},Operation::set_u8,276},
{{"Game pending 0x00bc7790",0x007c7790,bytes101,sizeof(bytes101),reiv::original::BindingState::StaticVerified},Operation::get_u8,276},
{{"Game pending 0x00bd3a30",0x007d3a30,bytes102,sizeof(bytes102),reiv::original::BindingState::StaticVerified},Operation::get_u32,516},
{{"Game pending 0x00bd9060",0x007d9060,bytes103,sizeof(bytes103),reiv::original::BindingState::StaticVerified},Operation::get_u32,900},
{{"Game pending 0x00c13d80",0x00813d80,bytes104,sizeof(bytes104),reiv::original::BindingState::StaticVerified},Operation::get_u32,492},
{{"Game pending 0x00c13da0",0x00813da0,bytes105,sizeof(bytes105),reiv::original::BindingState::StaticVerified},Operation::get_u32,488},
{{"Game pending 0x00c13db0",0x00813db0,bytes106,sizeof(bytes106),reiv::original::BindingState::StaticVerified},Operation::get_u8,760},
{{"Game pending 0x00c13dc0",0x00813dc0,bytes107,sizeof(bytes107),reiv::original::BindingState::StaticVerified},Operation::address_offset,504},
{{"Game pending 0x00c13e10",0x00813e10,bytes108,sizeof(bytes108),reiv::original::BindingState::StaticVerified},Operation::get_float,764},
{{"Game pending 0x00c15e70",0x00815e70,bytes109,sizeof(bytes109),reiv::original::BindingState::StaticVerified},Operation::get_u8,480},
{{"Game pending 0x00c15e80",0x00815e80,bytes110,sizeof(bytes110),reiv::original::BindingState::StaticVerified},Operation::set_u8,480},
{{"Game pending 0x00c15ea0",0x00815ea0,bytes111,sizeof(bytes111),reiv::original::BindingState::StaticVerified},Operation::get_float,484},
{{"Game pending 0x00c15eb0",0x00815eb0,bytes112,sizeof(bytes112),reiv::original::BindingState::StaticVerified},Operation::get_u8,495},
{{"Game pending 0x00c284b0",0x008284b0,bytes113,sizeof(bytes113),reiv::original::BindingState::StaticVerified},Operation::address_offset,752},
{{"Game pending 0x00c284c0",0x008284c0,bytes114,sizeof(bytes114),reiv::original::BindingState::StaticVerified},Operation::address_offset,768},
{{"Game pending 0x00c28840",0x00828840,bytes115,sizeof(bytes115),reiv::original::BindingState::StaticVerified},Operation::get_float,736},
{{"Game pending 0x00c2d560",0x0082d560,bytes116,sizeof(bytes116),reiv::original::BindingState::StaticVerified},Operation::get_u32,2464},
{{"Game pending 0x00c3c240",0x0083c240,bytes117,sizeof(bytes117),reiv::original::BindingState::StaticVerified},Operation::get_u32,320},
{{"Game pending 0x00c3d1a0",0x0083d1a0,bytes118,sizeof(bytes118),reiv::original::BindingState::StaticVerified},Operation::get_u32,496},
{{"Game pending 0x00c4e4c0",0x0084e4c0,bytes119,sizeof(bytes119),reiv::original::BindingState::StaticVerified},Operation::get_u32,12},
{{"Game pending 0x00c4e4d0",0x0084e4d0,bytes120,sizeof(bytes120),reiv::original::BindingState::StaticVerified},Operation::get_u32,16},
{{"Game pending 0x00c4e4e0",0x0084e4e0,bytes121,sizeof(bytes121),reiv::original::BindingState::StaticVerified},Operation::get_float,24},
{{"Game pending 0x00c4e580",0x0084e580,bytes122,sizeof(bytes122),reiv::original::BindingState::StaticVerified},Operation::get_float,120},
{{"Game pending 0x00c4e5d0",0x0084e5d0,bytes123,sizeof(bytes123),reiv::original::BindingState::StaticVerified},Operation::get_float,136},
{{"Game pending 0x00c592f0",0x008592f0,bytes124,sizeof(bytes124),reiv::original::BindingState::StaticVerified},Operation::get_u8,92},
{{"Game pending 0x00c5a620",0x0085a620,bytes125,sizeof(bytes125),reiv::original::BindingState::StaticVerified},Operation::get_u8,161},
{{"Game pending 0x00c5ac00",0x0085ac00,bytes126,sizeof(bytes126),reiv::original::BindingState::StaticVerified},Operation::get_u8,84},
{{"Game pending 0x00c70e90",0x00870e90,bytes127,sizeof(bytes127),reiv::original::BindingState::StaticVerified},Operation::get_u32,80},
{{"Game pending 0x00c71240",0x00871240,bytes128,sizeof(bytes128),reiv::original::BindingState::StaticVerified},Operation::get_u32,160},
{{"Game pending 0x00c71840",0x00871840,bytes129,sizeof(bytes129),reiv::original::BindingState::StaticVerified},Operation::get_u32,184},
{{"Game pending 0x00c71850",0x00871850,bytes130,sizeof(bytes130),reiv::original::BindingState::StaticVerified},Operation::address_offset,192},
{{"Game pending 0x00c72300",0x00872300,bytes131,sizeof(bytes131),reiv::original::BindingState::StaticVerified},Operation::get_u32,176},
{{"Game pending 0x00cd2de0",0x008d2de0,bytes132,sizeof(bytes132),reiv::original::BindingState::StaticVerified},Operation::set_u32,488},
{{"Game pending 0x00cd2df0",0x008d2df0,bytes133,sizeof(bytes133),reiv::original::BindingState::StaticVerified},Operation::set_u8,492},
{{"Game pending 0x00cd2e00",0x008d2e00,bytes134,sizeof(bytes134),reiv::original::BindingState::StaticVerified},Operation::get_u8,492},
{{"Game pending 0x00cd2e10",0x008d2e10,bytes135,sizeof(bytes135),reiv::original::BindingState::StaticVerified},Operation::get_u32,500},
{{"Game pending 0x00cd2e20",0x008d2e20,bytes136,sizeof(bytes136),reiv::original::BindingState::StaticVerified},Operation::set_u8,495},
{{"Game pending 0x00cd2e30",0x008d2e30,bytes137,sizeof(bytes137),reiv::original::BindingState::StaticVerified},Operation::set_u8,496},
{{"Game pending 0x00cee030",0x008ee030,bytes138,sizeof(bytes138),reiv::original::BindingState::StaticVerified},Operation::get_u32,48},
{{"Game pending 0x00cef7a0",0x008ef7a0,bytes139,sizeof(bytes139),reiv::original::BindingState::StaticVerified},Operation::address_offset,160},
{{"Game pending 0x00cf7480",0x008f7480,bytes140,sizeof(bytes140),reiv::original::BindingState::StaticVerified},Operation::get_u32,24},
{{"Game pending 0x00d33d40",0x00933d40,bytes141,sizeof(bytes141),reiv::original::BindingState::StaticVerified},Operation::address_offset,197},
{{"Game pending 0x00d33d50",0x00933d50,bytes142,sizeof(bytes142),reiv::original::BindingState::StaticVerified},Operation::address_offset,261},
{{"Game pending 0x00d33e90",0x00933e90,bytes143,sizeof(bytes143),reiv::original::BindingState::StaticVerified},Operation::get_u32,328},
{{"Game pending 0x00d33ea0",0x00933ea0,bytes144,sizeof(bytes144),reiv::original::BindingState::StaticVerified},Operation::get_u32,332},
{{"Game pending 0x00d33eb0",0x00933eb0,bytes145,sizeof(bytes145),reiv::original::BindingState::StaticVerified},Operation::set_u32,332},
{{"Game pending 0x00d33f40",0x00933f40,bytes146,sizeof(bytes146),reiv::original::BindingState::StaticVerified},Operation::set_u8,65},
{{"Game pending 0x00d33f50",0x00933f50,bytes147,sizeof(bytes147),reiv::original::BindingState::StaticVerified},Operation::get_u8,65},
};
inline constexpr unsigned count=sizeof(entries)/sizeof(entries[0]);
inline bool enabled=false,done=false;
inline unsigned calls[count]{},failures[count]{},exceptions=0;

inline int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i]; auto address=reiv::original::ResolveAddress(e.binding); if(!address)return 1;
  alignas(16) unsigned char object[4096], expected[4096]; memset(object,(sample*17+0xa5)&255,sizeof(object));
  unsigned a=0x12345678^(sample*0x01020408),b=0x87654321^(sample*0x04030201); float value=3.25f+sample;
  memcpy(object+e.offset,&a,4); if(e.operation==Operation::get_float)memcpy(object+e.offset,&value,4);
  if(e.operation==Operation::get_u8)object[e.offset]=static_cast<unsigned char>(0x71+sample);
  memcpy(expected,object,sizeof(object));
  switch(e.operation) {
   case Operation::address_offset: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object+e.offset)return 2;break;}
   case Operation::identity_this: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object)return 2;break;}
   case Operation::get_u32: {using F=unsigned(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=a)return 2;break;}
   case Operation::get_u8: {using F=unsigned char(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=static_cast<unsigned char>(0x71+sample))return 2;break;}
   case Operation::get_float: {using F=float(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=value)return 2;break;}
   case Operation::compare_u32: {using F=bool(__thiscall*)(void*,unsigned);auto fn=reinterpret_cast<F>(address);if(!fn(object,a)||fn(object,b))return 2;break;}
   case Operation::set_u8: {using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,b);memcpy(expected+e.offset,&b,1);break;}
   case Operation::set_u32: {using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,b);memcpy(expected+e.offset,&b,4);break;}
   case Operation::set_pair: {using F=void(__thiscall*)(void*,unsigned,unsigned);reinterpret_cast<F>(address)(object,a,b);memcpy(expected+e.offset,&a,4);memcpy(expected+e.offset+4,&b,4);break;}
   case Operation::get_pair: {unsigned out[4]={0x11111111,0,0,0x22222222};memcpy(object+e.offset+4,&b,4);memcpy(expected,object,sizeof(object));using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=a||out[2]!=b||out[3]!=0x22222222)return 2;break;}
   case Operation::outputs_minus_one: {unsigned out[4]={0x11111111,0,0,0x22222222};using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=0xffffffff||out[2]!=0xffffffff||out[3]!=0x22222222)return 2;break;}
  }
  return memcmp(object,expected,sizeof(object))?3:0;
 } __except(EXCEPTION_EXECUTE_HANDLER) { return 4; }
}
inline void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-game-pending.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}
inline void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);calls[i]+=entries[i].operation==Operation::compare_u32?2:1;if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Game pending RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-pending-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}

