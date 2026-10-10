#include "../NativeObserverBridge.h"
#include <cstdio>
#include <cstring>
namespace B=reiv::player_observer;
static unsigned captured[10]{},callerEsp,result;
static unsigned destination;
__declspec(naked) static void Destination(){
 __asm {
  mov dword ptr [captured+0],eax
  mov dword ptr [captured+4],ecx
  mov dword ptr [captured+8],edx
  mov dword ptr [captured+12],ebx
  mov dword ptr [captured+16],ebp
  mov dword ptr [captured+20],esi
  mov dword ptr [captured+24],edi
  mov dword ptr [captured+28],esp
  pushfd
  pop dword ptr [captured+32]
  mov eax,dword ptr [destination]
  mov dword ptr [captured+36],eax
  mov eax,0123456ABh
  ret
 }
}
__declspec(naked) static void Original(){__asm{mov dword ptr [destination],1}__asm{jmp Destination}}
__declspec(naked) static void Clone(){__asm{mov dword ptr [destination],2}__asm{jmp Destination}}
__declspec(naked) static void __stdcall Invoke(void*){
 __asm {
  push ebp
  push ebx
  push esi
  push edi
  mov dword ptr [callerEsp],esp
  mov ecx,dword ptr [esp+20]
  mov eax,011111111h
  mov edx,022222222h
  mov ebx,033333333h
  mov ebp,044444444h
  mov esi,055555555h
  mov edi,066666666h
  push 0246h
  popfd
  call B::Thunk
  mov dword ptr [result],eax
  pop edi
  pop esi
  pop ebx
  pop ebp
  ret 4
 }
}
int main(){
 B::originalEntry=reinterpret_cast<void*>(&Original);B::cloneEntry=reinterpret_cast<void*>(&Clone);
 B::targetPlayer=0x10000000;unsigned checks=0;
 __declspec(align(16)) unsigned char before[512]{},after[512]{};
 for(unsigned mode=0;mode<4;++mode)for(unsigned i=0;i<4096;++i){
  B::enabled=(mode&1)?1:0;auto receiver=reinterpret_cast<void*>((mode&2)?0x20000000:0x10000000);
  __asm fxsave before
  Invoke(receiver);
  __asm fxsave after
  unsigned expected[]={0x11111111,reinterpret_cast<unsigned>(receiver),0x22222222,0x33333333,0x44444444,0x55555555,0x66666666,callerEsp-4,0x246,mode==1?2u:1u};
  if(std::memcmp(captured,expected,sizeof expected)||std::memcmp(before,after,512)||result!=0x123456AB){std::printf("FAIL mode=%u\n",mode);return 1;}++checks;
 }
 if(B::calls!=16384||B::targetCalls!=8192||B::selected!=4096)return 2;
 B::cloneBegin=0x30000000;B::cloneEnd=0x30001000;EXCEPTION_RECORD r{};EXCEPTION_POINTERS p{&r,nullptr};
 B::enabled=1;r.ExceptionAddress=reinterpret_cast<void*>(0x30000008);
 if(B::NotifyException(&p)!=EXCEPTION_CONTINUE_SEARCH||B::enabled||B::exceptions!=1)return 3;
 B::enabled=1;r.ExceptionAddress=reinterpret_cast<void*>(0x40000000);
 if(B::NotifyException(&p)!=EXCEPTION_CONTINUE_SEARCH||!B::enabled||B::exceptions!=1)return 4;
 B::Disable();if(B::enabled)return 5;
 std::printf("PASS observer_bridge_cases=%u all_registers_flags_stack_FP_preserved=1 exception_continue_search=1\n",checks);
}
