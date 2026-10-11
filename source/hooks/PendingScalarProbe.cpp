#include "PendingScalarProbe.h"

namespace pendingscalar {
unsigned Load(const unsigned char* p,unsigned n) {unsigned v=0;memcpy(&v,p,n);return v;}

void Store(unsigned char* p,unsigned n,unsigned v) {memcpy(p,&v,n);}

unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args) {unsigned eax=0,edx=0,xmm0=0;switch(i){
case 0: eax=(ecx); break;
case 1: eax=(0); edx=(0); break;
case 2: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 3: eax=(0xffffffffu); break;
case 4: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 5: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 6: Store(expected+4,4,(Load(expected+4,4))+(0x00000001u)); break;
case 7: eax=(0xffffffffu); break;
case 8: xmm0=args[0]; Store(expected+28,4,xmm0); break;
case 9: eax=(0); Store(expected+28,4,eax); Store(expected+32,4,eax); Store(expected+20,4,eax); break;
case 10: xmm0=args[0]; Store(expected+32,4,xmm0); break;
case 11: xmm0=args[0]; Store(expected+20,4,xmm0); break;
case 12: xmm0=args[0]; Store(expected+24,4,xmm0); break;
case 13: eax=(args[0]); Store(expected+544,4,(Load(expected+544,4))+(eax)); break;
case 14: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); break;
case 15: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); xmm0=args[2]; Store(expected+40,4,xmm0); break;
case 16: xmm0=args[0]; Store(expected+32,4,xmm0); xmm0=args[1]; Store(expected+36,4,xmm0); xmm0=args[2]; Store(expected+40,4,xmm0); xmm0=args[3]; Store(expected+44,4,xmm0); break;
case 17: eax=(0); break;
case 18: Store(expected+284,4,(Load(expected+284,4))&(0xfffffffdu)); break;
case 19: Store(expected+284,4,(Load(expected+284,4))&(0xfffffffdu)); break;
case 20:  break;
case 21: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); eax=(0x7f800001u); Store(expected+16,4,eax); Store(expected+20,4,eax); Store(expected+24,4,eax); Store(expected+28,4,eax); break;
case 22: xmm0=0; Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,xmm0); break;
case 23: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); Store(expected+16,4,0x7f800001u); break;
case 24: xmm0=args[0]; Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,xmm0); break;
case 25: Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,0x00000000u); break;
case 26: Store(expected+4,1,(Load(expected+4,1))|(0x00000010u)); Store(expected+16,4,0x80000000u); break;
case 27: eax=(args[0]); Store(expected+4,1,(Load(expected+4,1))&(0x000000efu)); Store(expected+16,4,eax); break;
case 28: eax=(0); Store(expected+4,4,eax); Store(expected+8,4,eax); break;
case 29: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 30: eax=(0x00000064u); break;
case 31: eax=(0x00000028u); break;
case 32: eax=(Load(expected+16,4)); break;
case 33: eax=(Load(expected+20,4)); break;
case 34: eax=(0); Store(expected+12,4,eax); Store(expected+4,4,eax); Store(expected+8,4,eax); break;
case 35: eax=(Load(expected+12,2)); eax=((eax)+(0x00000001u)); eax=((eax)<<(0x00000004u)); break;
case 36: eax=(Load(expected+12,2)); eax=((eax)+(0x00000010u)); break;
case 37: eax=(0xffffffffu); break;
case 38: eax=(0xffffffffu); break;
case 39: eax=(0x00000080u); break;
case 40: eax=(0xffffffffu); break;
case 41: eax=(0xffffffffu); break;
case 42: eax=(Load(expected+16,4)); edx=(Load(expected+20,4)); break;
case 43: eax=(ecx); break;
case 44: eax=(Load(expected+28,2)); break;
case 45: eax=(Load(expected+30,2)); break;
case 46: eax=(Load(expected+39,1)); break;
case 47: eax=(Load(expected+60,2)); break;
case 48: eax=(Load(expected+62,2)); break;
case 49: eax=(eax&0xffff0000u)|((0)&0xffffu); break;
case 50: eax=(eax&0xffff0000u)|((Load(expected+54,2))&0xffffu); break;
case 51: eax=(eax&0xffff0000u)|((Load(expected+62,2))&0xffffu); break;
case 52: Store(expected+6,1,0x00000000u); Store(expected+20,4,0xffffffffu); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 53: eax=(Load(expected+4,1)); break;
case 54: eax=(Load(expected+208,4)); break;
case 55: eax=(args[0]); Store(expected+208,4,eax); break;
case 56: Store(expected+24,4,0x00000001u); break;
case 57:  break;
case 58: eax=(eax&0xffff0000u)|((Load(expected+24,2))&0xffffu); break;
case 59: eax=(Load(expected+216,1)); break;
case 60: xmm0=args[0]; Store(expected+36,4,xmm0); break;
case 61: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 62: eax=(Load(expected+144,4)); break;
case 63: eax=(args[0]); Store(expected+144,4,eax); break;
case 64: eax=(Load(expected+544,4)); break;
case 65: eax=(args[0]); Store(expected+544,4,eax); break;
case 66: xmm0=0; Store(expected+408,4,xmm0); Store(expected+404,4,xmm0); Store(expected+400,4,xmm0); Store(expected+392,4,xmm0); Store(expected+388,4,xmm0); Store(expected+384,4,xmm0); break;
case 67: xmm0=args[0]; Store(expected+16,4,xmm0); break;
case 68:  break;
case 69:  break;
case 70: eax=(Load(expected+256,4)); break;
case 71: eax=(args[0]); Store(expected+256,4,eax); break;
case 72: eax=(Load(expected+2368,4)); eax=((eax)+(0x00000002u)); break;
case 73: xmm0=args[0]; Store(expected+624,4,xmm0); Store(expected+632,4,xmm0); xmm0=args[1]; Store(expected+628,4,xmm0); Store(expected+636,4,xmm0); break;
case 74: eax=(Load(expected+180,4)); break;
case 75: eax=(args[0]); Store(expected+180,4,eax); break;
case 76: eax=(eax&0xffff0000u)|((Load(expected+20,2))&0xffffu); break;
case 77: eax=(eax&0xffff0000u)|((Load(expected+64,2))&0xffffu); break;
case 78: eax=(0x00000001u); break;
case 79: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 80: eax=(ecx); break;
case 81: eax=(ecx+131124u); break;
case 82: eax=(ecx+131188u); break;
}return eax;}

int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i];const auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));memcpy(expected,object,sizeof(object));
  unsigned args[6];for(unsigned n=0;n<6;++n)args[n]=0x87654321u^(sample*0x01020408u)^(n*0x02030405u);
  const unsigned wanted=Expected(i,expected,reinterpret_cast<unsigned>(object),args);unsigned result=0;
  if(e.floating){float f=1;switch(e.pop){
   case 0:{using F=float(__thiscall*)(void*);f=reinterpret_cast<F>(address)(object);break;}
   case 4:{using F=float(__thiscall*)(void*,unsigned);f=reinterpret_cast<F>(address)(object,args[0]);break;}
   case 20:{using F=float(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned);f=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4]);break;}
   default:return 5;
  }if(f!=0)return 2;}
  else switch(e.pop){
   case 0:{using F=unsigned(__thiscall*)(void*);result=reinterpret_cast<F>(address)(object);break;}
   case 4:{using F=unsigned(__thiscall*)(void*,unsigned);result=reinterpret_cast<F>(address)(object,args[0]);break;}
   case 8:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1]);break;}
   case 12:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2]);break;}
   case 16:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3]);break;}
   case 20:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4]);break;}
   case 24:{using F=unsigned(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);result=reinterpret_cast<F>(address)(object,args[0],args[1],args[2],args[3],args[4],args[5]);break;}
   default:return 5;
  }
  if(!e.floating && (result&e.mask)!=(wanted&e.mask))return 2;
  return memcmp(object,expected,sizeof(object))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}

void Report(const char* phase) {FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-pending-scalar.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.pending-scalar-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

void Tick() {if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){const int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Pending scalar RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}

} // namespace pendingscalar
