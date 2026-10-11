#include "ARTComplexProbe.h"

namespace artcomplex {
int Check(unsigned i,unsigned sample) {
 __try {
  const auto& e=entries[i];const auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096],nested[4096],nestedExpected[4096],output[96],outputExpected[96];
  memset(object,(sample*17+0xa5)&255,sizeof(object));memset(nested,0x5a,sizeof(nested));memset(output,0xa5,sizeof(output));
  object[232]=static_cast<unsigned char>(((sample*17)&~4u)|((sample&1)?4:0));object[10]=static_cast<unsigned char>(((sample*13)&~8u)|((sample&1)?8:0));
  unsigned ptr=reinterpret_cast<unsigned>(nested);memcpy(object+80,&ptr,4);unsigned value=0x12345678u^(sample*0x01020408u);memcpy(nested+844,&value,4);
  for(unsigned n=0;n<3;++n){float f=3.25f+sample+n;memcpy(object+332+n*4,&f,4);}float f=2.5f+sample;memcpy(object+280,&f,4);
  memcpy(expected,object,sizeof(object));memcpy(nestedExpected,nested,sizeof(nested));memcpy(outputExpected,output,sizeof(output));
  using Void=void(__thiscall*)(void*);using One=void(__thiscall*)(void*,unsigned);using Select=void*(__thiscall*)(void*,unsigned);using Read=unsigned(__thiscall*)(void*);using Out=void(__thiscall*)(void*,void*,unsigned,unsigned,unsigned,unsigned,unsigned);
  switch(e.op){
   case guarded_float_store:{float v=4.75f+sample;unsigned bits=0;memcpy(&bits,&v,4);if(!(object[232]&4))memcpy(expected+e.offset,&bits,4);reinterpret_cast<One>(address)(object,bits);break;}
   case guarded_copy3:if(!(object[232]&4))memcpy(expected+356,object+332,12);reinterpret_cast<Void>(address)(object);break;
   case guarded_zero3:if(!(object[232]&4))memset(expected+356,0,12);reinterpret_cast<Void>(address)(object);break;
   case reset_and_guarded_copy:memset(expected+308,0,4);if(!(object[232]&4))memcpy(expected+288,object+280,4);reinterpret_cast<Void>(address)(object);break;
   case guarded_zero1:if(!(object[232]&4))memset(expected+288,0,4);reinterpret_cast<Void>(address)(object);break;
   case select_this:if(reinterpret_cast<Select>(address)(object,0)!=(object[10]&8?nullptr:object))return 2;break;
   case nested_read:if(reinterpret_cast<Read>(address)(object)!=value)return 2;break;
   case zero_output9:for(unsigned n=0;n<3;++n)memset(outputExpected+16+n*16,0,12);reinterpret_cast<Out>(address)(object,output+16,0,0,0,0,0);break;
  }
  return memcmp(object,expected,sizeof(object))||memcmp(nested,nestedExpected,sizeof(nested))||memcmp(output,outputExpected,sizeof(output))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}

void Report(const char* phase) {FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-art-complex.json").c_str(),"wb")||!f)return;
 fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"both_branch_outcomes\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);
 for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}

void Initialize() {enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.art-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

void Tick() {if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;
 for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("ART complex RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}

} // namespace artcomplex
