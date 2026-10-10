#include <windows.h>
#include <array>
#include <cstring>
#include <cstdint>
#include "game/Peds/CPlayerPed.h"
using P = reiv::game::CPlayerPed;
int main() {
 const unsigned char code[][13] = {
 {0x8b,0x81,0xbc,0x0e,0,0,0xc3}, {0x8d,0x81,0xc0,0x0e,0,0,0xc3}, {0x8d,0x81,0xd0,0x0e,0,0,0xc3},
 {0x8b,0x44,0x24,4,0x89,0x81,0xbc,0x0e,0,0,0xc2,4,0}, {0x8b,0x44,0x24,4,0x89,0x81,0xf0,0x0e,0,0,0xc2,4,0}};
 auto block = static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));
 if(!block) return 1;
 std::memcpy(block,code,sizeof(code)); DWORD previous;
 if(!VirtualProtect(block,4096,PAGE_EXECUTE_READ,&previous)) return 2;
 FlushInstructionCache(GetCurrentProcess(),block,sizeof(code));
 using Get = std::uint32_t(__thiscall*)(void*);
 using Address = void*(__thiscall*)(void*);
 using Set = void(__thiscall*)(void*,std::uint32_t);
 for(unsigned sample=0;sample<256;++sample) {
  std::array<unsigned char,4096> original, rebuilt;
  for(unsigned i=0;i<4096;++i) original[i]=static_cast<unsigned char>(i*37+sample*19);
  rebuilt=original;
  if(reinterpret_cast<Get>(block)(original.data())!=P::GetFieldEBC(rebuilt.data())) return 3;
  if(static_cast<unsigned char*>(reinterpret_cast<Address>(block+13)(original.data()))-original.data()!=static_cast<unsigned char*>(P::GetBlockEC0(rebuilt.data()))-rebuilt.data()) return 4;
  if(static_cast<unsigned char*>(reinterpret_cast<Address>(block+26)(original.data()))-original.data()!=static_cast<unsigned char*>(P::GetBlockED0(rebuilt.data()))-rebuilt.data()) return 5;
  auto value=sample*0x01020409u;
  reinterpret_cast<Set>(block+39)(original.data(),value); P::SetFieldEBC(rebuilt.data(),value);
  reinterpret_cast<Set>(block+52)(original.data(),~value); P::SetFieldEF0(rebuilt.data(),~value);
  if(original!=rebuilt) return 6;
 }
 VirtualFree(block,0,MEM_RELEASE); return 0;
}
