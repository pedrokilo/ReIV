#include <windows.h>
#include <array>
#include <vector>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include "game/Peds/PlayerPedDestruction.h"
#include "destruction-fixture.h"
using Dependencies=reiv::game::PlayerPedDestructionDependencies;
using Rebuilt=reiv::game::PlayerPedDestruction;
struct Event { unsigned function, self, value; bool operator==(const Event& o)const{return function==o.function&&self==o.self&&value==o.value;} };
static std::vector<Event> events;
static std::array<unsigned char,4096> object, memberA, memberB;
static unsigned sample, cleanupCount, resolveCount;
static void* manager=reinterpret_cast<void*>(0x12340000);
static void* allocator=reinterpret_cast<void*>(0x56780000);
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned offset,unsigned value){std::memcpy(static_cast<unsigned char*>(p)+offset,&value,4);}
static void EventLog(unsigned f,void*p,unsigned v=0){events.push_back({f,U(p),v});}
static void Cleanup(void*p){EventLog(0x8DD270,p);if((sample&8)&&++cleanupCount==1)W(object.data(),0xEA8,(sample&16)?0:0x12345678);}
static void Cleanup2(void*p){EventLog(0x8DD8B0,p);}
static void Free(void*p){EventLog(0x5B1C10,p);}
static unsigned Resolve(void*p,unsigned v){EventLog(0x92F4D0,p,v);return v^0xAA55AA55;}
static unsigned Transform(unsigned v){EventLog(0x8631E0,nullptr,v);return v+0x1234;}
static void Remove(unsigned v){EventLog(0x9C0A70,nullptr,v);if((sample&32)&&++resolveCount==1)W(object.data(),0x228,U(memberB.data()));}
static void Reset(void*p,unsigned v){EventLog(0x920CD0,p,v);}
static void Member(void*p){EventLog(0x4475F0,p);}
static void Base(void*p){EventLog(0x8AC1E0,p);W(p,0x10,0xBA5E0000|sample);}
static void Deallocate(void*p,void*o){EventLog(0x448300,p,U(o));}
static void __fastcall N270(void*p,void*){Cleanup(p);}
static void __fastcall N8B0(void*p,void*){Cleanup2(p);}
static void __cdecl NFree(void*p){Free(p);}
static unsigned __fastcall NResolve(void*p,void*,unsigned v){return Resolve(p,v);}
static unsigned __cdecl NTransform(unsigned v){return Transform(v);}
static void __cdecl NRemove(unsigned v){Remove(v);}
static void __fastcall NReset(void*p,void*,unsigned v){Reset(p,v);}
static void __fastcall NMember(void*p,void*){Member(p);}
static void __fastcall NBase(void*p,void*){Base(p);}
static void __fastcall NDeallocate(void*p,void*,void*o){Deallocate(p,o);}
static void C270(void*,void*p){Cleanup(p);} static void C8B0(void*,void*p){Cleanup2(p);}
static void CFree(void*,void*p){Free(p);} static void* M(void*){return manager;}
static unsigned CResolve(void*,void*p,unsigned v){return Resolve(p,v);}
static unsigned CTransform(void*,unsigned v){return Transform(v);} static void CRemove(void*,unsigned v){Remove(v);}
static void CReset(void*,void*p,unsigned v){Reset(p,v);} static void CMember(void*,void*p){Member(p);}
static void CBase(void*,void*p){Base(p);} static void* A(void*){return allocator;}
static void CDeallocate(void*,void*p,void*o){Deallocate(p,o);}
static void Initialize(){
 for(unsigned i=0;i<4096;++i){object[i]=static_cast<unsigned char>(i*37+sample);memberA[i]=static_cast<unsigned char>(i*19+sample);memberB[i]=static_cast<unsigned char>(i*17+sample);}
 W(object.data(),0x228,U(memberA.data()));W(object.data(),0xEA8,(sample&1)?0x87654321:0);
 W(memberA.data(),0x444,(sample&2)?0x11220000+sample:0);W(memberA.data(),0x448,(sample&4)?0x33440000+sample:0);
 W(memberB.data(),0x444,0x55660000+sample);W(memberB.data(),0x448,(sample&4)?0x77880000+sample:0);
 events.clear();cleanupCount=resolveCount=0;
}
static void* Address(unsigned target,unsigned char*body){
 switch(target){case 0x9C1E60:return body;case 0x8DD270:return reinterpret_cast<void*>(&N270);case 0x8DD8B0:return reinterpret_cast<void*>(&N8B0);case 0x5B1C10:return reinterpret_cast<void*>(&NFree);case 0x92F4D0:return reinterpret_cast<void*>(&NResolve);case 0x8631E0:return reinterpret_cast<void*>(&NTransform);case 0x9C0A70:return reinterpret_cast<void*>(&NRemove);case 0x920CD0:return reinterpret_cast<void*>(&NReset);case 0x4475F0:return reinterpret_cast<void*>(&NMember);case 0x8AC1E0:return reinterpret_cast<void*>(&NBase);case 0x448300:return reinterpret_cast<void*>(&NDeallocate);default:return nullptr;}
}
template<unsigned N>static bool Patch(unsigned char* code,const DestructorPatch(&patches)[N],unsigned char* body){
 for(auto p:patches){auto target=Address(p.target,body);if(!target)return false;unsigned delta=U(target)-U(code+p.offset+4);std::memcpy(code+p.offset,&delta,4);}return true;
}
static unsigned OriginalFault(void* wrapper){
 __try{reinterpret_cast<void*(__thiscall*)(void*,unsigned)>(wrapper)(object.data(),0);return 0;}
 __except(EXCEPTION_EXECUTE_HANDLER){return GetExceptionCode();}
}
static unsigned RebuiltFault(const Dependencies& d){
 __try{Rebuilt::DestroyDeleting(object.data(),0,d);return 0;}
 __except(EXCEPTION_EXECUTE_HANDLER){return GetExceptionCode();}
}
int main(){
 auto block=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE));if(!block)return 1;
 auto body=block;auto wrapper=block+512;std::memcpy(body,bodyBytes,sizeof(bodyBytes));std::memcpy(wrapper,wrapperBytes,sizeof(wrapperBytes));
 if(!Patch(body,bodyPatches,body)||!Patch(wrapper,wrapperPatches,body))return 2;
 // Absolute data operands: player vtable stays canonical (never dereferenced).
 unsigned mgr=U(&manager),alloc=U(&allocator);
 std::memcpy(body+(0x9C1ECB-0x9C1E60),&mgr,4);std::memcpy(body+(0x9C1F2D-0x9C1E60),&mgr,4);
 std::memcpy(wrapper+(0x9C2271-0x9C2260),&alloc,4);
 auto patched=std::fopen("build/cplayerped-destructor-patched.bin","wb");if(!patched)return 6;
 std::fwrite(block,1,1024,patched);std::fclose(patched);
 DWORD old;if(!VirtualProtect(block,4096,PAGE_EXECUTE_READ,&old))return 3;FlushInstructionCache(GetCurrentProcess(),block,4096);
 Dependencies d={nullptr,0xD819C4,C270,C8B0,CFree,M,CResolve,CTransform,CRemove,CReset,CMember,CBase,A,CDeallocate};
 using Original=void*(__thiscall*)(void*,unsigned);
 auto baseline=std::fopen("build/cplayerped-destructor-baseline.bin","wb");
 auto reconstruction=std::fopen("build/cplayerped-destructor-reconstruction.bin","wb");if(!baseline||!reconstruction)return 7;
 unsigned comparisons=0;
 for(sample=0;sample<256;++sample){
  Initialize();const unsigned flags=(sample*0x01020304u)|(sample>>6&1);
  auto result=reinterpret_cast<Original>(wrapper)(object.data(),flags);auto expectedEvents=events;auto expectedObject=object,expectedA=memberA,expectedB=memberB;
  Initialize();auto rebuilt=Rebuilt::DestroyDeleting(object.data(),flags,d);
  if(result!=rebuilt||expectedEvents!=events||expectedObject!=object||expectedA!=memberA||expectedB!=memberB){std::printf("FAIL sample %u\n",sample);return 4;}
  const unsigned count=static_cast<unsigned>(events.size());
  std::fwrite(&count,4,1,baseline);std::fwrite(expectedEvents.data(),sizeof(Event),count,baseline);
  std::fwrite(expectedObject.data(),1,4096,baseline);std::fwrite(expectedA.data(),1,4096,baseline);std::fwrite(expectedB.data(),1,4096,baseline);
  std::fwrite(&count,4,1,reconstruction);std::fwrite(events.data(),sizeof(Event),count,reconstruction);
  std::fwrite(object.data(),1,4096,reconstruction);std::fwrite(memberA.data(),1,4096,reconstruction);std::fwrite(memberB.data(),1,4096,reconstruction);
  ++comparisons;
 }
 std::fclose(baseline);std::fclose(reconstruction);
 // A null member228 is not tolerated by the original: it reads VA 0x3E4.
 unsigned originalFault=0,rebuiltFault=0;Initialize();W(object.data(),0x228,0);
 originalFault=OriginalFault(wrapper);
 Initialize();W(object.data(),0x228,0);
 rebuiltFault=RebuiltFault(d);
 if(originalFault!=EXCEPTION_ACCESS_VIOLATION||rebuiltFault!=originalFault)return 5;
 std::printf("PASS comparisons=%u failures=0 null_member_access_violation=matched dependencies=deterministic_stubs\n",comparisons);
 VirtualFree(block,0,MEM_RELEASE);return 0;
}
