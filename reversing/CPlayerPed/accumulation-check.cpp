#include <windows.h>
#include <xmmintrin.h>
#include <array>
#include <cstdio>
#include <cstring>
#include "game/Peds/PlayerPedAccumulation.h"
int main() {
 const std::uint8_t body[]={
#include "accumulation-body.inc"
 };
 std::uint32_t globals[4];
 auto code=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!code)return 1;
 std::memcpy(code,body,sizeof(body));unsigned i=0;
 for(unsigned offset:{4u,12u,27u,45u}) {auto pointer=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&globals[i++]));std::memcpy(code+offset,&pointer,4);}
 DWORD old;if(!VirtualProtect(code,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),code,4096);
 using Native=void(__thiscall*)(void*);
 reiv::game::PlayerPedAccumulationGlobals d{globals,globals+1,globals+2,globals+3};
 const std::uint32_t values[]={0,0x80000000,1,0x80000001,0x007FFFFF,0x807FFFFF,0x00800000,0x80800000,0x3F800000,0xBF800000,0x41A00000,0x419FFFFF,0x41A00001,0x7F7FFFFF,0xFF7FFFFF,0x7F800000,0xFF800000,0x7FC12345,0x7F812345,0xFF812345};
 const std::uint32_t scales[]={0x3F8CCCCD,0,0x3F800000,0xBF800000,1,0x7F800000,0x7FC12345,0x7F812345};
 std::array<std::uint8_t,4096> object;unsigned count=0;
 for(unsigned rounding=0;rounding<4;++rounding)for(unsigned daz=0;daz<2;++daz)for(unsigned ftz=0;ftz<2;++ftz)
 for(auto time:values)for(auto previous:values)for(auto scale:scales)for(unsigned limit:{0x41A00000u,0u,0x7FC12345u,0x7F800000u}) {
  globals[0]=time;globals[1]=scale;globals[2]=limit;globals[3]=values[count%20];
  for(unsigned j=0;j<object.size();++j)object[j]=static_cast<std::uint8_t>(j*37+count*19);
  std::memcpy(object.data()+0xEE0,&previous,4);auto seeded=object;
  auto control=0x1F80u|(rounding<<13)|(daz<<6)|(ftz<<15);
  _mm_setcsr(control);reinterpret_cast<Native>(code)(object.data());const auto status=_mm_getcsr();auto reference=object;
  object=seeded;_mm_setcsr(control);reiv::game::PlayerPedAccumulation::AdvanceFieldEE0(object.data(),d);const auto rebuiltStatus=_mm_getcsr();
  if(object!=reference||status!=rebuiltStatus) {std::printf("failed time=%08x previous=%08x scale=%08x limit=%08x csr=%x/%x\n",time,previous,scale,limit,status,rebuiltStatus);return 3;}
  ++count;
 }
 _mm_setcsr(0x1F80);VirtualFree(code,0,MEM_RELEASE);std::printf("passed %u accumulation body comparisons including full buffers and MXCSR\n",count);return 0;
}
