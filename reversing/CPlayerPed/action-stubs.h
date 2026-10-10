#pragma once
__declspec(naked) static void S00924E80(){
 __asm{
 mov eax,esp
 add eax,4
 cmp stackAnchor,0
 jne anchored9588352
 mov stackAnchor,eax
 anchored9588352:
 push 1
 push eax
 push ecx
 push 0924E80h
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
__declspec(naked) static void S009C1300(){
 __asm{
 mov eax,esp
 add eax,4
 push 5
 push eax
 push ecx
 push 09C1300h
 call Record
 add esp,16
 ret 20
 }
}
__declspec(naked) static void S009A9EF0(){
 __asm{
 mov eax,esp
 add eax,4
 push 1
 push eax
 push ecx
 push 09A9EF0h
 call Record
 add esp,16
 ret 4
 }
}
__declspec(naked) static void S009A9CF0(){
 __asm{
 mov eax,esp
 add eax,4
 cmp stackAnchor,0
 jne anchored10132720
 mov stackAnchor,eax
 anchored10132720:
 push 0
 push eax
 push ecx
 push 09A9CF0h
 call Record
 add esp,16
 ret
 }
}
__declspec(naked) static void Noop(){__asm{ret}}
static void* Stub(unsigned a){switch(a){case 0xC28820:return reinterpret_cast<void*>(&Noop);
case 0x924E80:return reinterpret_cast<void*>(&S00924E80);
case 0x462F90:return reinterpret_cast<void*>(&S00462F90);
case 0x9C1300:return reinterpret_cast<void*>(&S009C1300);
case 0x9A9EF0:return reinterpret_cast<void*>(&S009A9EF0);
case 0x9A9CF0:return reinterpret_cast<void*>(&S009A9CF0);
default:return nullptr;}}
