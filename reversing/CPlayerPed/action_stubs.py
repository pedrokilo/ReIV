from pathlib import Path
p=Path(__file__).parent
contracts=[(0x924E80,0,1,False),(0x462F90,0,0,False),(0x9C1300,20,5,True),(0x9A9EF0,4,1,True),(0x9A9CF0,0,0,True)]
lines=['#pragma once']
for va,pop,words,this in contracts:
 lines += [f'__declspec(naked) static void S{va:08X}(){{',' __asm{',' mov eax,esp',' add eax,4']
 if va in (0x924E80,0x9A9CF0):lines+=[' cmp stackAnchor,0',' jne anchored'+str(va),' mov stackAnchor,eax',' anchored'+str(va)+':']
 lines += [f' push {words}',' push eax',' push ecx',f' push 0{va:X}h',' call Record',' add esp,16',f' ret {pop}' if pop else ' ret',' }','}']
lines+=['__declspec(naked) static void Noop(){__asm{ret}}','static void* Stub(unsigned a){switch(a){case 0xC28820:return reinterpret_cast<void*>(&Noop);']+[f'case 0x{v:X}:return reinterpret_cast<void*>(&S{v:08X});' for v,_,_,_ in contracts]+['default:return nullptr;}}']
(p/'action-stubs.h').write_text('\n'.join(lines)+'\n')
