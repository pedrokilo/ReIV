#pragma once
__declspec(naked) static void InputStub004255A0(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 04255A0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub00426780(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 0426780h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub00426910(){
 __asm{
  mov eax,esp
  add eax,4
  push 2
  push eax
  push ecx
  push 0426910h
  call Record
  add esp,16
  ret 8
 }
}
__declspec(naked) static void InputStub00462F90(){
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
__declspec(naked) static void InputStub00785EB0(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 0785EB0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub0089E300(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 089E300h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub008FF470(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 08FF470h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub00924E80(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 0924E80h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009252D0(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 09252D0h
  call Record
  add esp,16
  ret 4
 }
}
__declspec(naked) static void InputStub00987730(){
 __asm{
  mov eax,esp
  add eax,4
  push 6
  push eax
  push ecx
  push 0987730h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub0099C5E0(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 099C5E0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009A9CF0(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 09A9CF0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009AA330(){
 __asm{
  mov eax,esp
  add eax,4
  push 4
  push eax
  push ecx
  push 09AA330h
  call Record
  add esp,16
  ret 16
 }
}
__declspec(naked) static void InputStub009AC110(){
 __asm{
  mov eax,esp
  add eax,4
  push 3
  push eax
  push ecx
  push 09AC110h
  call Record
  add esp,16
  ret 12
 }
}
__declspec(naked) static void InputStub009ADB90(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 09ADB90h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009B3B00(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 09B3B00h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009BE4A0(){
 __asm{
  mov eax,esp
  add eax,4
  push 0
  push eax
  push ecx
  push 09BE4A0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009BE5D0(){
 __asm{
  mov eax,esp
  add eax,4
  mov stackAnchor,eax
  push 0
  push eax
  push ecx
  push 09BE5D0h
  call Record
  add esp,16
  ret
 }
}
__declspec(naked) static void InputStub009C5D60(){
 __asm{
  mov eax,esp
  add eax,4
  push 1
  push eax
  push ecx
  push 09C5D60h
  call Record
  add esp,16
  ret 4
 }
}
static void* Stub(unsigned target){switch(target){
case 0x4255A0:return reinterpret_cast<void*>(&InputStub004255A0);
case 0x426780:return reinterpret_cast<void*>(&InputStub00426780);
case 0x426910:return reinterpret_cast<void*>(&InputStub00426910);
case 0x462F90:return reinterpret_cast<void*>(&InputStub00462F90);
case 0x785EB0:return reinterpret_cast<void*>(&InputStub00785EB0);
case 0x89E300:return reinterpret_cast<void*>(&InputStub0089E300);
case 0x8FF470:return reinterpret_cast<void*>(&InputStub008FF470);
case 0x924E80:return reinterpret_cast<void*>(&InputStub00924E80);
case 0x9252D0:return reinterpret_cast<void*>(&InputStub009252D0);
case 0x987730:return reinterpret_cast<void*>(&InputStub00987730);
case 0x99C5E0:return reinterpret_cast<void*>(&InputStub0099C5E0);
case 0x9A9CF0:return reinterpret_cast<void*>(&InputStub009A9CF0);
case 0x9AA330:return reinterpret_cast<void*>(&InputStub009AA330);
case 0x9AC110:return reinterpret_cast<void*>(&InputStub009AC110);
case 0x9ADB90:return reinterpret_cast<void*>(&InputStub009ADB90);
case 0x9B3B00:return reinterpret_cast<void*>(&InputStub009B3B00);
case 0x9BE4A0:return reinterpret_cast<void*>(&InputStub009BE4A0);
case 0x9BE5D0:return reinterpret_cast<void*>(&InputStub009BE5D0);
case 0x9C5D60:return reinterpret_cast<void*>(&InputStub009C5D60);
default:return nullptr;}}
