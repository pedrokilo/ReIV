#pragma once
#include <windows.h>
#include <cstdint>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Native player observer bridge requires MSVC x86.
#endif
namespace reiv::player_observer {
// Detached opt-in bridge. This header does not patch a vtable or register a VEH.
// Entry addresses/lifetime must stay fixed until all possible callers quiesce.
inline void* originalEntry=nullptr;
inline void* cloneEntry=nullptr;
inline volatile LONG targetPlayer=0,enabled=0,calls=0,targetCalls=0,selected=0,exceptions=0;
inline std::uintptr_t cloneBegin=0,cloneEnd=0;
inline unsigned __cdecl Choose(void* receiver){
 InterlockedIncrement(&calls);
 const auto target=static_cast<std::uint32_t>(InterlockedCompareExchange(&targetPlayer,0,0));
 if(target&&reinterpret_cast<std::uintptr_t>(receiver)==target){
  InterlockedIncrement(&targetCalls);
  if(InterlockedCompareExchange(&enabled,0,0)){InterlockedIncrement(&selected);return 1;}
 }
 return 0;
}
__declspec(naked) inline void Thunk(){
 __asm {
  pushfd
  pushad
  mov eax,dword ptr [esp+24]
  push eax
  call Choose
  add esp,4
  test eax,eax
  jz Original
  popad
  popfd
  jmp dword ptr [cloneEntry]
 Original:
  popad
  popfd
  jmp dword ptr [originalEntry]
 }
}
inline void Disable(){InterlockedExchange(&enabled,0);}
// Optional first-chance notification only. External callee exceptions are not
// attributed here. Never swallow, retry or rerun an original after partial writes.
inline LONG CALLBACK NotifyException(EXCEPTION_POINTERS* p){
 if(p&&p->ExceptionRecord){
  const auto ip=reinterpret_cast<std::uintptr_t>(p->ExceptionRecord->ExceptionAddress);
  if(cloneBegin&&ip>=cloneBegin&&ip<cloneEnd){InterlockedIncrement(&exceptions);Disable();}
 }
 return EXCEPTION_CONTINUE_SEARCH;
}
}
