#pragma once
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
 FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-audio-fixtures.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");
 fprintf(f,"]}\n");fclose(f);
}
inline void Tick() {
 if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i);calls[i]+=entries[i].operation==Operation::compare_u32?2:1;if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Audio fixture RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}
 Report(failed?"failed":"passed");
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.audio-fixtures-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}
}

