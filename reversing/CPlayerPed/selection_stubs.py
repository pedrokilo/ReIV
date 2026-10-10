from pathlib import Path
p=Path(__file__).parent
contracts=[(0x441F20,0,0,False),(0x462F90,0,0,False),(0x9BF360,4,1,False),(0x9BF390,4,1,True),(0x9BF420,4,1,True),(0x9C03E0,20,5,False),(0x9C0660,12,3,False),(0x9C07A0,24,6,True),(0x9E9090,16,4,False),(0x9E9340,0,0,False),(0xD0C8E4,0,10,False)]
lines=['#pragma once']
for va,pop,words,fp in contracts:
 lines += [f'__declspec(naked) static void S{va:08X}(){{',' __asm{',' mov eax,esp',' add eax,4']
 if va==0x9E9090:lines+=[' cmp stackAnchor,0',' jne anchored',' mov stackAnchor,ebp',' anchored:']
 lines += [f' push {words}',' push eax',' push ecx',f' push 0{va:X}h',' call Record',' add esp,16']
 if fp:lines+=[' push eax',' fld dword ptr [esp]',' add esp,4']
 lines += [f' ret {pop}' if pop else ' ret',' }','}']
lines+=['__declspec(naked) static void Noop(){__asm{ret}}','static void* Stub(unsigned a){switch(a){case 0xC28820:return reinterpret_cast<void*>(&Noop);']+[f'case 0x{v:X}:return reinterpret_cast<void*>(&S{v:08X});' for v,_,_,_ in contracts]+['default:return nullptr;}}']
(p/'selection-stubs.h').write_text('\n'.join(lines)+'\n')
