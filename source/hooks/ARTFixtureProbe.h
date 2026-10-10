#pragma once
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

inline int Check(unsigned i) {
 __try {
  const auto& e=entries[i]; auto address=reiv::original::ResolveAddress(e.binding); if(!address)return 1;
  alignas(16) unsigned char object[4096], expected[4096]; memset(object,0xa5,sizeof(object));
  unsigned a=0x12345678,b=0x87654321; float value=3.25f;
  memcpy(object+e.offset,&a,4); if(e.operation==Operation::get_float)memcpy(object+e.offset,&value,4);
  if(e.operation==Operation::get_u8)object[e.offset]=0x71;
  memcpy(expected,object,sizeof(object));
  switch(e.operation) {
   case Operation::address_offset: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object+e.offset)return 2;break;}
   case Operation::identity_this: {using F=void*(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=object)return 2;break;}
   case Operation::get_u32: {using F=unsigned(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=a)return 2;break;}
   case Operation::get_u8: {using F=unsigned char(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=0x71)return 2;break;}
   case Operation::get_float: {using F=float(__thiscall*)(void*);if(reinterpret_cast<F>(address)(object)!=value)return 2;break;}
   case Operation::compare_u32: {using F=bool(__thiscall*)(void*,unsigned);auto fn=reinterpret_cast<F>(address);if(!fn(object,a)||fn(object,b))return 2;break;}
   case Operation::set_u32: {using F=void(__thiscall*)(void*,unsigned);reinterpret_cast<F>(address)(object,b);memcpy(expected+e.offset,&b,4);break;}
   case Operation::set_pair: {using F=void(__thiscall*)(void*,unsigned,unsigned);reinterpret_cast<F>(address)(object,a,b);memcpy(expected+e.offset,&a,4);memcpy(expected+e.offset+4,&b,4);break;}
   case Operation::get_pair: {unsigned out[4]={0x11111111,0,0,0x22222222};memcpy(object+e.offset+4,&b,4);memcpy(expected,object,sizeof(object));using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=a||out[2]!=b||out[3]!=0x22222222)return 2;break;}
   case Operation::outputs_minus_one: {unsigned out[4]={0x11111111,0,0,0x22222222};using F=void(__thiscall*)(void*,unsigned*,unsigned*);reinterpret_cast<F>(address)(object,out+1,out+2);if(out[0]!=0x11111111||out[1]!=0xffffffff||out[2]!=0xffffffff||out[3]!=0x22222222)return 2;break;}
  }
  return memcmp(object,expected,sizeof(object))?3:0;
 } __except(EXCEPTION_EXECUTE_HANDLER) { return 4; }
}
inline void Report(const char* phase) {
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-art-fixtures.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}
inline void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i);calls[i]+=entries[i].operation==Operation::compare_u32?2:1;if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("ART fixture RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.art-fixtures-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}

