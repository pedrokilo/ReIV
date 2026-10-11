#include "GameComplexScalarProbe.h"

namespace gamecomplexscalar {
unsigned Load(const unsigned char* p,unsigned n) {unsigned v=0;memcpy(&v,p,n);return v;}

void Store(unsigned char* p,unsigned n,unsigned v) {memcpy(p,&v,n);}

unsigned Expected(unsigned i,unsigned char* expected,unsigned ecx,const unsigned* args) {unsigned eax=0,edx=0,xmm0=0;switch(i){
case 0: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); Store(expected+168,4,eax); Store(expected+172,4,eax); break;
case 1: xmm0=args[0]; eax=(0); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 2: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 3: xmm0=args[0]; Store(expected+4,4,xmm0); break;
case 4: xmm0=args[0]; Store(expected+8,4,xmm0); break;
case 5: eax=(0x00000001u); break;
case 6: eax=(Load(expected+8,4)); break;
case 7: eax=(0x00000032u); break;
case 8: xmm0=args[0]; Store(expected+56,4,xmm0); break;
case 9: eax=(eax&0xffffff00u)|((Load(expected+52,1))&0xffu); break;
case 10: Store(expected+16,1,0x000000ffu); break;
case 11: eax=(args[0]); break;
case 12: eax=(args[0]); break;
case 13: eax=(Load(expected+112,4)); eax=((eax)-(Load(expected+64,4))); break;
case 14: eax=(0); Store(expected+100,4,eax); Store(expected+108,4,eax); Store(expected+116,4,eax); Store(expected+124,4,eax); Store(expected+132,4,eax); Store(expected+140,4,eax); Store(expected+148,4,eax); Store(expected+156,4,eax); Store(expected+164,4,eax); break;
case 15: eax=(0x0000000bu); break;
case 16: eax=(0x000000d1u); break;
case 17: eax=(0x00000079u); break;
case 18: eax=(0x00000028u); break;
case 19: eax=(0); Store(expected+64,4,eax); Store(expected+72,4,eax); Store(expected+80,4,eax); Store(expected+88,4,eax); Store(expected+96,4,eax); Store(expected+104,4,eax); break;
case 20: xmm0=args[0]; Store(expected+12,4,xmm0); break;
case 21: eax=(Load(expected+472,2)); break;
case 22: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); Store(expected+472,4,eax); break;
case 23: eax=(args[0]); xmm0=args[1]; Store(expected+20,4,eax); Store(expected+24,4,xmm0); break;
case 24: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 25: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 26: eax=(0x00000001u); break;
case 27: xmm0=0; Store(expected+92,4,(Load(expected+92,4))&(0xfffffffeu)); Store(expected+80,4,xmm0); break;
case 28: eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 29: xmm0=0; Store(expected+36,4,xmm0); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 30: xmm0=args[0]; Store(expected+64,4,xmm0); break;
case 31: xmm0=args[0]; Store(expected+60,4,xmm0); break;
case 32: xmm0=args[0]; Store(expected+24,4,xmm0); break;
case 33: xmm0=args[0]; Store(expected+28,4,xmm0); break;
case 34:  break;
case 35: eax=(0); break;
case 36: eax=(Load(expected+8,4)); break;
case 37: Store(expected+52,4,(Load(expected+52,4))+(0x00000001u)); eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 38: xmm0=args[0]; Store(expected+108,4,xmm0); break;
case 39: xmm0=args[0]; Store(expected+496,4,xmm0); break;
case 40: xmm0=args[0]; Store(expected+496,4,xmm0); break;
case 41: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 42: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 43: eax=(eax&0xffffff00u)|((0)&0xffu); break;
case 44: eax=(0); break;
case 45: eax=(0x00000001u); break;
case 46: eax=(args[1]); break;
case 47: eax=(0x000001afu); break;
case 48: eax=(0x00000003u); break;
case 49: eax=(0x000000c8u); break;
case 50: eax=(0x0000038bu); break;
case 51: eax=(0xffffffffu); break;
case 52: Store(expected+56,1,(Load(expected+56,1))&(0x000000fdu)); break;
case 53: xmm0=args[0]; Store(expected+480,4,xmm0); break;
case 54: xmm0=args[0]; Store(expected+484,4,xmm0); break;
case 55: xmm0=args[0]; Store(expected+488,4,xmm0); break;
case 56: xmm0=args[0]; Store(expected+492,4,xmm0); break;
case 57:  break;
case 58: xmm0=args[0]; Store(expected+56,4,xmm0); break;
case 59: Store(expected+36,4,(Load(expected+36,4))|(0x00000400u)); break;
case 60: Store(expected+80,4,(Load(expected+80,4))&(0xffffcfffu)); break;
case 61: eax=(0); break;
case 62: eax=(eax&0xffffff00u)|((Load(expected+316,1))&0xffu); eax=(eax&0xffffff00u)|((((eax&0xffu))&(0x000000f7u))&0xffu); eax=(eax&0xffffff00u)|((((eax&0xffu))|(0x00000004u))&0xffu); Store(expected+316,1,(eax&0xffu)); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 63: eax=(ecx+5152u); break;
case 64: xmm0=args[0]; eax=(0); Store(expected+164,4,xmm0); xmm0=args[1]; Store(expected+168,4,eax); Store(expected+172,4,eax); Store(expected+176,4,xmm0); Store(expected+180,4,eax); Store(expected+184,4,eax); break;
case 65: Store(expected+526,1,0x00000001u); break;
case 66:  break;
case 67:  break;
case 68: eax=(eax&0xffffff00u)|((0)&0xffu); Store(expected+328,1,(eax&0xffu)); Store(expected+329,1,(eax&0xffu)); eax=(0x000003e8u); Store(expected+320,4,eax); Store(expected+324,4,eax); eax=(eax&0xffffff00u)|((0x00000001u)&0xffu); break;
case 69: eax=(Load(expected+24,2)); break;
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

void Report(const char* phase) {FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-game-complex-scalar.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

void Tick() {if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){const int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Game complex scalar RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}

} // namespace gamecomplexscalar
