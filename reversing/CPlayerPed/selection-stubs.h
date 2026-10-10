#pragma once
__declspec(naked) static void S00441F20(){
 __asm{
 mov eax,esp
 add eax,4
 push 0
 push eax
 push ecx
 push 0441F20h
 call Record
 add esp,16
 ret
 }
}
__declspec(naked) static void S00462F90(){
 __asm{
 mov eax,esp
 add eax,4
 push 0
 push eax
 push ecx
 push 0462F90h
 call Record
 add esp,16
 ret
 }
}
__declspec(naked) static void S009BF360(){
 __asm{
 mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 09BF360h
 call Record
 add esp,16
 ret 4
 }
}
__declspec(naked) static void S009BF390(){
 __asm{
 mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 09BF390h
 call Record
 add esp,16
 push eax
 fld dword ptr [esp]
 add esp,4
 ret 4
 }
}
__declspec(naked) static void S009BF420(){
 __asm{
 mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 09BF420h
 call Record
 add esp,16
 push eax
 fld dword ptr [esp]
 add esp,4
 ret 4
 }
}
__declspec(naked) static void S009C03E0(){
 __asm{
 mov eax,esp
 add eax,4
 push 5
 push eax
 push ecx
 push 09C03E0h
 call Record
 add esp,16
 ret 20
 }
}
__declspec(naked) static void S009C0660(){
 __asm{
 mov eax,esp
 add eax,4
 push 3
 push eax
 push ecx
 push 09C0660h
 call Record
 add esp,16
 ret 12
 }
}
__declspec(naked) static void S009C07A0(){
 __asm{
 mov eax,esp
 add eax,4
 push 6
 push eax
 push ecx
 push 09C07A0h
 call Record
 add esp,16
 push eax
 fld dword ptr [esp]
 add esp,4
 ret 24
 }
}
__declspec(naked) static void S009E9090(){
 __asm{
 mov eax,esp
 add eax,4
 cmp stackAnchor,0
 jne anchored
 mov stackAnchor,ebp
 anchored:
 push 4
 push eax
 push ecx
 push 09E9090h
 call Record
 add esp,16
 ret 16
 }
}
__declspec(naked) static void S009E9340(){
 __asm{
 mov eax,esp
 add eax,4
 push 0
 push eax
 push ecx
 push 09E9340h
 call Record
 add esp,16
 ret
 }
}
__declspec(naked) static void S00D0C8E4(){
 __asm{
 mov eax,esp
 add eax,4
 push 10
 push eax
 push ecx
 push 0D0C8E4h
 call Record
 add esp,16
 ret
 }
}
__declspec(naked) static void Noop(){__asm{ret}}
static void* Stub(unsigned a){switch(a){case 0xC28820:return reinterpret_cast<void*>(&Noop);
case 0x441F20:return reinterpret_cast<void*>(&S00441F20);
case 0x462F90:return reinterpret_cast<void*>(&S00462F90);
case 0x9BF360:return reinterpret_cast<void*>(&S009BF360);
case 0x9BF390:return reinterpret_cast<void*>(&S009BF390);
case 0x9BF420:return reinterpret_cast<void*>(&S009BF420);
case 0x9C03E0:return reinterpret_cast<void*>(&S009C03E0);
case 0x9C0660:return reinterpret_cast<void*>(&S009C0660);
case 0x9C07A0:return reinterpret_cast<void*>(&S009C07A0);
case 0x9E9090:return reinterpret_cast<void*>(&S009E9090);
case 0x9E9340:return reinterpret_cast<void*>(&S009E9340);
case 0xD0C8E4:return reinterpret_cast<void*>(&S00D0C8E4);
default:return nullptr;}}
