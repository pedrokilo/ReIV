#include <windows.h>
#include <xmmintrin.h>
#include <array>
#include <cstdio>
#include <cstring>
#include "game/Peds/PlayerPedExtraFields.h"
#include "extra-fields-body.inc"
int main() {
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;
 std::memcpy(code,testCode,sizeof(testCode));std::memcpy(code+128,resetCode,sizeof(resetCode));
 std::uint32_t global;
 auto pointer=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&global));std::memcpy(code+11,&pointer,4);std::memcpy(code+128+16,&pointer,4);
 DWORD old;if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Test=std::uint8_t(__thiscall*)(void*);using Reset=void(__thiscall*)(void*);
 reiv::game::PlayerPedExtraFieldsGlobals d{&global,&global};std::array<std::uint8_t,4096> object;unsigned count=0;
 const std::uint32_t values[]={0,0x80000000,1,0x80000001,0x007FFFFF,0x807FFFFF,0x00800000,0x80800000,0x3F800000,0xBF800000,0x41A00000,0x419FFFFF,0x41A00001,0x7F7FFFFF,0xFF7FFFFF,0x7F800000,0xFF800000,0x7FC12345,0x7F812345,0xFF812345};
 for(unsigned rounding=0;rounding<4;++rounding)for(unsigned daz=0;daz<2;++daz)for(unsigned ftz=0;ftz<2;++ftz)
 for(auto value:values)for(auto bits:values)for(unsigned sample=0;sample<32;++sample) {
  global=bits;for(unsigned i=0;i<object.size();++i)object[i]=static_cast<std::uint8_t>(i*37+sample*19);
  std::memcpy(object.data()+0xEE4,&value,4);std::memcpy(object.data()+0xEEC,&value,4);const auto seed=object;
  const auto control=0x1F80u|(rounding<<13)|(daz<<6)|(ftz<<15);
  _mm_setcsr(control);auto native=reinterpret_cast<Test>(code)(object.data());const auto csr=_mm_getcsr();
  _mm_setcsr(control);auto rebuilt=reiv::game::PlayerPedExtraFields::TestFieldEE4(object.data(),d);const auto rebuiltCsr=_mm_getcsr();
  if(native!=rebuilt||csr!=rebuiltCsr||object!=seed)return 3;
  ++count;
  _mm_setcsr(control);reinterpret_cast<Reset>(code+128)(object.data());const auto resetCsr=_mm_getcsr();const auto reference=object;
  object=seed;_mm_setcsr(control);reiv::game::PlayerPedExtraFields::ResetFieldEEC(object.data(),d);const auto resetRebuiltCsr=_mm_getcsr();
  if(object!=reference||resetCsr!=resetRebuiltCsr)return 4;
  ++count;
 }
 _mm_setcsr(0x1F80);VirtualFree(code,0,MEM_RELEASE);std::printf("passed %u extra-field body comparisons including full buffers and MXCSR\n",count);return 0;
}
