#include "GameComplexProbe.h"

namespace gamecomplex {
int Check(unsigned index,unsigned sample) {
 __try {
  const auto& e=entries[index];auto address=reiv::original::ResolveAddress(e.binding);if(!address)return 1;
  alignas(16) unsigned char object[4096],expected[4096];memset(object,(sample*17+0xa5)&255,sizeof(object));
  const unsigned patterns[]={0,1,0xffffffffu,0x80000000u,0x7fffffffu,e.value,e.value-1,e.value+1};
  unsigned input=sample<8?patterns[sample]:sample*0x10204081u;memcpy(object+e.offset,&input,e.width);memcpy(expected,object,sizeof(object));
  unsigned mask=e.width==1?255u:0xffffffffu;input&=mask;unsigned rhs=e.value&mask;bool truth=false;
  int signedInput=e.width==1?static_cast<signed char>(input):static_cast<int>(input);int signedRhs=e.width==1?static_cast<signed char>(rhs):static_cast<int>(rhs);
  switch(e.operation){
   case Op::sete:truth=input==rhs;break;case Op::setne:truth=input!=rhs;break;case Op::setg:truth=signedInput>signedRhs;break;case Op::setge:truth=signedInput>=signedRhs;break;
   case Op::setl:truth=signedInput<signedRhs;break;case Op::setle:truth=signedInput<=signedRhs;break;case Op::seta:truth=input>rhs;break;case Op::setae:truth=input>=rhs;break;case Op::setb:truth=input<rhs;break;case Op::setbe:truth=input<=rhs;break;
   case Op::bits:break;
  }
  if(e.operation==Op::bits){unsigned want=input;unsigned registerMask=e.value==1?255u:0xffffffffu;for(unsigned j=0;j<e.stepCount;++j){const auto& s=e.steps[j];switch(s.op){case Arithmetic::shr:want>>=(s.value&31);break;case Arithmetic::and_:want&=s.value;break;case Arithmetic::or_:want|=s.value;break;case Arithmetic::xor_:want^=s.value;break;case Arithmetic::not_:want=~want;break;default:break;}want&=registerMask;}
   unsigned got=e.value==1?Invoke<unsigned char>(address,object,e.cleanup):Invoke<unsigned>(address,object,e.cleanup);if(got!=want)return 2;
  }else if(Invoke<unsigned char>(address,object,e.cleanup)!=(truth?1:0))return 2;
  return memcmp(object,expected,sizeof(object))?3:0;
 }__except(EXCEPTION_EXECUTE_HANDLER){return 4;}
}

void Report(const char* phase) {FILE* f=nullptr;if(fopen_s(&f,hashprobe::GameFile("ReIV-game-complex.json").c_str(),"wb")||!f)return;fprintf(f,"{\"phase\":\"%s\",\"fixture_only\":true,\"exceptions\":%u,\"entries\":[",phase,exceptions);for(unsigned i=0;i<count;++i)fprintf(f,"%s{\"rva\":\"0x%08X\",\"calls\":%u,\"failures\":%u,\"disabled\":%s}",i?",":"",entries[i].binding.rva,calls[i],failures[i],failures[i]?"true":"false");fprintf(f,"]}\n");fclose(f);}

void Tick() {gamecomplexscalar::Tick();if(!enabled||done||!hashprobe::gameLoaded)return;done=true;unsigned failed=0;for(unsigned i=0;i<count;++i){for(unsigned n=0;n<64;++n){int result=Check(i,n);++calls[i];if(result){++failures[i];++failed;if(result==4)++exceptions;break;}}REIV_INFO("Game complex RVA 0x%08X calls=%u failures=%u",entries[i].binding.rva,calls[i],failures[i]);}Report(failed?"failed":"passed");}

void Initialize() {gamecomplexscalar::Initialize();enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.game-complex-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(enabled)Report("waiting_for_game");}

} // namespace gamecomplex
