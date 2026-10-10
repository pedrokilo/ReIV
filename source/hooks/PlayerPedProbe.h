#pragma once
#include "../game/Peds/CPlayerPed.h"
#include <xmmintrin.h>
namespace playerprobe {
inline bool enabled=false;
inline unsigned samples=0, failures=0, exceptions=0;
inline std::uintptr_t player=0;
inline const unsigned char bytes[][13]={{0x8b,0x81,0xbc,0x0e,0,0,0xc3},{0x8d,0x81,0xc0,0x0e,0,0,0xc3},{0x8d,0x81,0xd0,0x0e,0,0,0xc3},{0x8b,0x44,0x24,4,0x89,0x81,0xbc,0x0e,0,0,0xc2,4,0},{0x8b,0x44,0x24,4,0x89,0x81,0xf0,0x0e,0,0,0xc2,4,0}};
inline const unsigned rvas[]={0x5c1c90,0x5c1ca0,0x5c1cb0,0x5c1cc0,0x5c1cd0};
inline const unsigned char copyBytes0[]={0x8b,0x44,0x24,4,0xd9,0,0xf3,0x0f,0x10,0x40,4,0xf3,0x0f,0x10,0x48,8,0xd9,0x99,0xc0,0x0e,0,0,0xf3,0x0f,0x11,0x81,0xc4,0x0e,0,0,0xf3,0x0f,0x11,0x89,0xc8,0x0e,0,0,0xd9,0x40,0x0c,0xd9,0x99,0xcc,0x0e,0,0,0xc2,4,0};
inline const unsigned char copyBytes1[]={0x8b,0x44,0x24,4,0xd9,0,0xf3,0x0f,0x10,0x40,4,0xf3,0x0f,0x10,0x48,8,0xd9,0x99,0xd0,0x0e,0,0,0xf3,0x0f,0x11,0x81,0xd4,0x0e,0,0,0xf3,0x0f,0x11,0x89,0xd8,0x0e,0,0,0xd9,0x40,0x0c,0xd9,0x99,0xdc,0x0e,0,0,0xc2,4,0};
inline const unsigned char zeroBytes[]={0x33,0xc0,0xc3};
inline const unsigned char oneBytes[]={0xb0,1,0xc3};
inline std::uintptr_t functions[12]{};
inline const unsigned char accumulationCanonical[]={0xf3,0xf,0x10,0x5,0x7c,0xde,0x1d,0x1,0xf3,0xf,0x59,0x5,0xec,0xc5,0xdc,0x0,0xf3,0xf,0x58,0x81,0xe0,0xe,0x0,0x0,0xf,0x2f,0x5,0x48,0x19,0xd8,0x0,0xf3,0xf,0x11,0x81,0xe0,0xe,0x0,0x0,0x76,0x1b,0xf3,0xf,0x10,0x5,0x50,0x19,0xd8,0x0,0xf3,0xf,0x11,0x81,0xe4,0xe,0x0,0x0,0xf,0x57,0xc0,0xf3,0xf,0x11,0x81,0xe0,0xe,0x0,0x0,0xc3};
inline unsigned char accumulationExpected[sizeof(accumulationCanonical)]{};
inline reiv::game::PlayerPedAccumulationGlobals accumulationGlobals{};
inline const unsigned char testEE4Canonical[]={0xf3,0x0f,0x10,0x81,0xe4,0x0e,0,0,0x0f,0x2f,0x05,0x60,0xcd,0xde,0,0x76,3,0x32,0xc0,0xc3,0xb0,1,0xc3};
inline const unsigned char resetEECCanonical[]={0x0f,0x57,0xc0,0x0f,0x2f,0x81,0xec,0x0e,0,0,0x72,0x10,0xf3,0x0f,0x10,0x05,0x58,0x19,0xd8,0,0xf3,0x0f,0x11,0x81,0xec,0x0e,0,0,0xc3};
inline unsigned char testEE4Expected[sizeof(testEE4Canonical)]{},resetEECExpected[sizeof(resetEECCanonical)]{};
inline reiv::game::PlayerPedExtraFieldsGlobals extraGlobals{};
inline void Report(){FILE* f=nullptr; if(fopen_s(&f,hashprobe::GameFile("ReIV-CPlayerPed.json").c_str(),"w")||!f)return;
 fprintf(f,"{\"passed\":%s,\"samples_per_method\":%u,\"comparisons\":%u,\"method_count\":12,\"accumulator_scope\":\"isolated-buffer-only\",\"extra_fields_scope\":\"isolated-buffer-only\",\"failures\":%u,\"exceptions\":%u,\"player\":\"0x%08X\",\"live_writes\":\"same-value only\",\"replacement_installed\":false}",samples==64&&!failures?"true":"false",samples,samples*12,failures,exceptions,unsigned(player));fclose(f);}
inline int CheckAccumulation(unsigned char* original, unsigned char* rebuilt) {
 __declspec(align(16)) unsigned char savedFpu[512];
 __asm fxsave savedFpu
 int result=0;
 __try {
  const unsigned patterns[]={0u,0x80000000u,1u,0x80000001u,0x007FFFFFu,0x00800000u,0x3f800000u,0xbf800000u,0x41a00000u,0x419fffffu,0x41a00001u,0x7f7fffffu,0x7f800000u,0xff800000u,0x7fc12345u,0x7f812345u};
  const unsigned bits=patterns[samples&15u];
  memcpy(original+0xee0,&bits,4);memcpy(rebuilt+0xee0,&bits,4);
  const unsigned* fields[]={accumulationGlobals.value11DDE7C,accumulationGlobals.multiplierDCC5EC,accumulationGlobals.limitD81948,accumulationGlobals.resetD81950,extraGlobals.limitDECD60,extraGlobals.resetD81958};
  unsigned before[6];for(unsigned i=0;i<6;++i)memcpy(before+i,fields[i],4);
  const unsigned mode=samples>>2;
  const unsigned csr=0x1f80u|((mode&3u)<<13)|(((mode>>2)&1u)<<6)|(((mode>>3)&1u)<<15);
  unsigned short cw0,sw0,cw1,sw1,cw2,sw2;
  __asm { fnstcw word ptr cw0 }
  __asm { fnstsw word ptr sw0 }
  _mm_setcsr(csr);
  using Call=reiv::original::Thiscall<void,void>;
  reinterpret_cast<Call>(functions[9])(original);
  const unsigned originalCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw1 }
  __asm { fnstsw word ptr sw1 }
  _mm_setcsr(csr);
  reiv::game::CPlayerPed::AdvanceFieldEE0(rebuilt,accumulationGlobals);
  const unsigned rebuiltCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw2 }
  __asm { fnstsw word ptr sw2 }
  if(memcmp(original,rebuilt,4096)||originalCsr!=rebuiltCsr||cw0!=cw1||cw1!=cw2||sw0!=sw1||sw1!=sw2)result=9;
  const unsigned ee4=patterns[(samples+7u)&15u];
  memcpy(original+0xee4,&ee4,4);memcpy(rebuilt+0xee4,&ee4,4);
  _mm_setcsr(csr);
  using ByteCall=reiv::original::Thiscall<unsigned char,void>;
  const auto nativeResult=reinterpret_cast<ByteCall>(functions[10])(original);
  const unsigned testOriginalCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw1 }
  __asm { fnstsw word ptr sw1 }
  _mm_setcsr(csr);
  const auto rebuiltResult=reiv::game::CPlayerPed::TestFieldEE4(rebuilt,extraGlobals);
  const unsigned testRebuiltCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw2 }
  __asm { fnstsw word ptr sw2 }
  if(nativeResult!=rebuiltResult||memcmp(original,rebuilt,4096)||testOriginalCsr!=testRebuiltCsr||cw0!=cw1||cw1!=cw2||sw0!=sw1||sw1!=sw2)result=11;
  const unsigned eec=patterns[(samples+11u)&15u];
  memcpy(original+0xeec,&eec,4);memcpy(rebuilt+0xeec,&eec,4);
  _mm_setcsr(csr);
  reinterpret_cast<Call>(functions[11])(original);
  const unsigned resetOriginalCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw1 }
  __asm { fnstsw word ptr sw1 }
  _mm_setcsr(csr);
  reiv::game::CPlayerPed::ResetFieldEEC(rebuilt,extraGlobals);
  const unsigned resetRebuiltCsr=_mm_getcsr();
  __asm { fnstcw word ptr cw2 }
  __asm { fnstsw word ptr sw2 }
  if(memcmp(original,rebuilt,4096)||resetOriginalCsr!=resetRebuiltCsr||cw0!=cw1||cw1!=cw2||sw0!=sw1||sw1!=sw2)result=12;
  for(unsigned i=0;i<6;++i)if(memcmp(before+i,fields[i],4))result=10;
 } __finally {
  __asm fxrstor savedFpu
 }
 return result;
}
inline int Check(CPed* ped){
 unsigned char original[4096], rebuilt[4096];
 using P=reiv::game::CPlayerPed; using Get=reiv::original::Thiscall<unsigned,void>;using Address=reiv::original::Thiscall<void*,void>;using Set=reiv::original::Thiscall<void,void,unsigned>;
 __try {
  if(reinterpret_cast<Get>(functions[7])(ped)!=P::ReturnZeroSlot48())return 7;
  using ByteGet=reiv::original::Thiscall<unsigned char,void>;
  if(reinterpret_cast<ByteGet>(functions[8])(ped)!=P::ReturnOneSlot74())return 8;
  auto p=reinterpret_cast<unsigned char*>(ped); player=reinterpret_cast<std::uintptr_t>(p);
  if(*reinterpret_cast<unsigned*>(p)!=reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr))+0x9819c4)return 1;
  if(reinterpret_cast<Get>(functions[0])(p)!=P::GetFieldEBC(p))return 2;
  if(reinterpret_cast<Address>(functions[1])(p)!=P::GetBlockEC0(p)||reinterpret_cast<Address>(functions[2])(p)!=P::GetBlockED0(p))return 3;
  unsigned ebc,ef0;memcpy(&ebc,p+0xebc,4);memcpy(&ef0,p+0xef0,4);
  reinterpret_cast<Set>(functions[3])(p,ebc);P::SetFieldEBC(p,ebc);
  reinterpret_cast<Set>(functions[4])(p,ef0);P::SetFieldEF0(p,ef0);
  if(memcmp(&ebc,p+0xebc,4)||memcmp(&ef0,p+0xef0,4))return 4;
  for(unsigned i=0;i<4096;++i)original[i]=static_cast<unsigned char>(i*37+samples*19);
  memcpy(rebuilt,original,4096);unsigned value=samples*0x01020409u;
  reinterpret_cast<Set>(functions[3])(original,value);P::SetFieldEBC(rebuilt,value);
  reinterpret_cast<Set>(functions[4])(original,~value);P::SetFieldEF0(rebuilt,~value);
  if(memcmp(original,rebuilt,4096))return 5;
  using Copy=reiv::original::Thiscall<void,void,const void*>;
  unsigned input[4]={0x3f800000u,0x80000000u,samples?0x7fc01234u:0x00000001u,0xbf800000u};
  reinterpret_cast<Copy>(functions[5])(original,input);P::CopyBlockEC0(rebuilt,input);
  reinterpret_cast<Copy>(functions[6])(original,input);P::CopyBlockED0(rebuilt,input);
  if(memcmp(original,rebuilt,4096))return 5;
  return CheckAccumulation(original,rebuilt);
 } __except(EXCEPTION_EXECUTE_HANDLER){return 6;}
}
inline void Initialize(){enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.player-ped-test").c_str())!=INVALID_FILE_ATTRIBUTES;if(!enabled)return;
 for(unsigned i=0;i<5;++i){reiv::original::FunctionAddress entry={"CPlayerPed reconstruction comparison",rvas[i],bytes[i],i<3?7u:13u,reiv::original::BindingState::StaticVerified};functions[i]=reiv::original::ResolveAddress(entry);if(!functions[i]){++failures;enabled=false;}}
 for(unsigned i=5;i<7;++i){reiv::original::FunctionAddress entry={"CPlayerPed float copy",i==5?0x5c1d90u:0x5c1dd0u,i==5?copyBytes0:copyBytes1,sizeof(copyBytes0),reiv::original::BindingState::StaticVerified};functions[i]=reiv::original::ResolveAddress(entry);if(!functions[i]){++failures;enabled=false;}}
 for(unsigned i=7;i<9;++i){reiv::original::FunctionAddress entry={"CPlayerPed constant body",i==7?0x3bdc00u:0x8faee0u,i==7?zeroBytes:oneBytes,3u,reiv::original::BindingState::StaticVerified};functions[i]=reiv::original::ResolveAddress(entry);if(!functions[i]){++failures;enabled=false;}}
 const auto module=reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr));
 memcpy(accumulationExpected,accumulationCanonical,sizeof(accumulationExpected));
 const unsigned delta=static_cast<unsigned>(module-0x400000u);
 const unsigned operandOffsets[]={4u,12u,27u,45u};
 const unsigned globalRvas[]={0x00ddde7cu,0x009cc5ecu,0x00981948u,0x00981950u,0x009ecd60u,0x00981958u};
 memcpy(testEE4Expected,testEE4Canonical,sizeof(testEE4Expected));
 memcpy(resetEECExpected,resetEECCanonical,sizeof(resetEECExpected));
 unsigned extraPointer;memcpy(&extraPointer,testEE4Expected+11,4);extraPointer+=delta;memcpy(testEE4Expected+11,&extraPointer,4);
 memcpy(&extraPointer,resetEECExpected+16,4);extraPointer+=delta;memcpy(resetEECExpected+16,&extraPointer,4);
 const unsigned* mapped[6]{};
 for(unsigned i=0;i<6;++i) {
  if(i<4){unsigned pointer;memcpy(&pointer,accumulationExpected+operandOffsets[i],4);pointer+=delta;memcpy(accumulationExpected+operandOffsets[i],&pointer,4);}
  const auto address=module+globalRvas[i];MEMORY_BASIC_INFORMATION mbi{};
  const bool committed=VirtualQuery(reinterpret_cast<void*>(address),&mbi,sizeof(mbi))==sizeof(mbi)&&mbi.State==MEM_COMMIT;
  const unsigned protection=mbi.Protect&0xffu;
  const bool readable=protection==PAGE_READONLY||protection==PAGE_READWRITE||protection==PAGE_WRITECOPY||protection==PAGE_EXECUTE_READ||protection==PAGE_EXECUTE_READWRITE||protection==PAGE_EXECUTE_WRITECOPY;
  if(!committed||!readable||(mbi.Protect&PAGE_GUARD)||address+4>reinterpret_cast<std::uintptr_t>(mbi.BaseAddress)+mbi.RegionSize){++failures;enabled=false;}
  mapped[i]=reinterpret_cast<const unsigned*>(address);
 }
 accumulationGlobals={mapped[0],mapped[1],mapped[2],mapped[3]};
 reiv::original::FunctionAddress accumulationEntry={"CPlayerPed fieldEE0 accumulation",0x5bf5f0u,accumulationExpected,sizeof(accumulationExpected),reiv::original::BindingState::StaticVerified};
 functions[9]=reiv::original::ResolveAddress(accumulationEntry);if(!functions[9]){++failures;enabled=false;}
 extraGlobals={mapped[4],mapped[5]};
 reiv::original::FunctionAddress testEntry={"CPlayerPed fieldEE4 comparison",0x5bf5d0u,testEE4Expected,sizeof(testEE4Expected),reiv::original::BindingState::StaticVerified};
 reiv::original::FunctionAddress resetEntry={"CPlayerPed fieldEEC reset",0x5bf640u,resetEECExpected,sizeof(resetEECExpected),reiv::original::BindingState::StaticVerified};
 functions[10]=reiv::original::ResolveAddress(testEntry);if(!functions[10]){++failures;enabled=false;}
 functions[11]=reiv::original::ResolveAddress(resetEntry);if(!functions[11]){++failures;enabled=false;}
 Report();}
inline void Tick(){if(!enabled||failures||samples==64||!hashprobe::gameLoaded)return;auto ped=FindPlayerPed();if(!ped)return;
 int result=Check(ped);++samples;if(result)++failures;if(result==6)++exceptions;Report();if(samples==64||failures)REIV_INFO("CPlayerPed comparison samples=%u failures=%u exceptions=%u",samples,failures,exceptions);}
}
