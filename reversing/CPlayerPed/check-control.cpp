#include <windows.h>
#include <array>
#include <vector>
#include <cstdio>
#include "game/Peds/PlayerPedControl.h"
#include "control-fixture.h"
using C=reiv::game::PlayerPedControl;using D=reiv::game::PlayerPedControlDependencies;
struct Event{unsigned function,self,args[6];bool operator==(const Event&o)const{return std::memcmp(this,&o,sizeof(*this))==0;}};
static std::vector<Event> events;static std::array<unsigned char,4096> object,model,control;
static void* models[8];static void* manager=reinterpret_cast<void*>(0x12340000);static unsigned sample;
static unsigned U(const void*p){return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p));}
static void W(void*p,unsigned o,unsigned v){std::memcpy(static_cast<unsigned char*>(p)+o,&v,4);}
static void Log(unsigned f,void*p,unsigned a=0,unsigned b=0,unsigned c=0,unsigned d=0,unsigned e=0,unsigned g=0){events.push_back({f,U(p),{a,b,c,d,e,g}});}
static unsigned Base(void*p,unsigned id){Log(0x8AC500,p,id);W(p,0x68,(sample&2)?0xFFFFFFFF:sample);return 0xABCD0000|sample;}
static void Model(unsigned id){Log(0x8DB2B0,nullptr,id);}
static void Reset(void*p,unsigned flag){Log(0x9BF660,p,flag&255);W(p,0x21C,sample*0x123456);}
static unsigned Attach(void*p,unsigned v){Log(0x8DD530,p,v);return v^0x5678ABCD;}
static void* Allocate(void*p){Log(0x439CB0,p);return(sample&4)?nullptr:control.data();}
static void* Construct(void*p,void*o,unsigned z,unsigned a,unsigned b,unsigned c,unsigned d){Log(0x4F4D20,p,U(o),z,a,b,c,d);return(sample&8)?nullptr:p;}
static void Count(void*p,unsigned n){Log(0x49F330,p,n);W(object.data(),0x6C,(sample&16)?0xBAD00000|sample:U(p));}
static unsigned __fastcall NBase(void*p,void*,unsigned id){return Base(p,id);}
static void __cdecl NModel(unsigned id){Model(id);}
static void __fastcall NReset(void*p,void*,unsigned flag){Reset(p,flag);}
static unsigned __cdecl NAttach(void*p,unsigned v){return Attach(p,v);}
static void* __fastcall NAllocate(void*p,void*){return Allocate(p);}
static void* __fastcall NConstruct(void*p,void*,void*o,unsigned z,unsigned a,unsigned b,unsigned c,unsigned d){return Construct(p,o,z,a,b,c,d);}
static void __fastcall NCount(void*p,void*,unsigned n){Count(p,n);}
static const void* Lookup(void*,unsigned n){return models[n];}static void* Manager(void*){return manager;}
static unsigned B(void*,void*p,unsigned n){return Base(p,n);}static void M(void*,unsigned n){Model(n);}
static void R(void*,void*p,std::uint8_t v){Reset(p,v);}static unsigned T(void*,void*p,unsigned v){return Attach(p,v);}
static void* A(void*,void*p){return Allocate(p);}static void* K(void*,void*p,void*o,unsigned z,unsigned a,unsigned b,unsigned c,unsigned d){return Construct(p,o,z,a,b,c,d);}
static void N(void*,void*p,unsigned n){Count(p,n);}
static void Initialize(){for(unsigned i=0;i<4096;++i){object[i]=static_cast<unsigned char>(i*31+sample);model[i]=static_cast<unsigned char>(i*13+sample);control[i]=static_cast<unsigned char>(i*19+sample);}model[0x8C]=sample&1;for(auto&x:models)x=model.data();events.clear();}
static void* Target(unsigned f){switch(f){case 0x8AC500:return reinterpret_cast<void*>(&NBase);case 0x8DB2B0:return reinterpret_cast<void*>(&NModel);case 0x9BF660:return reinterpret_cast<void*>(&NReset);case 0x8DD530:return reinterpret_cast<void*>(&NAttach);case 0x439CB0:return reinterpret_cast<void*>(&NAllocate);case 0x4F4D20:return reinterpret_cast<void*>(&NConstruct);case 0x49F330:return reinterpret_cast<void*>(&NCount);default:return nullptr;}}
template<unsigned N>static void Patch(unsigned char*p,const ControlPatch(&patch)[N]){for(auto x:patch){unsigned delta=U(Target(x.target))-U(p+x.offset+4);std::memcpy(p+x.offset,&delta,4);}}
int main(){
 auto block=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));if(!block)return 1;auto m=block;auto c=block+256;
 std::memcpy(m,modelBytes,sizeof(modelBytes));std::memcpy(c,createBytes,sizeof(createBytes));Patch(m,modelPatches);Patch(c,createPatches);
 unsigned modelsAddress=U(models),managerAddress=U(&manager);std::memcpy(m+9,&modelsAddress,4);std::memcpy(c+5,&managerAddress,4);
 auto patched=std::fopen("build/cplayerped-control-patched.bin","wb");std::fwrite(block,1,512,patched);std::fclose(patched);
 DWORD old;if(!VirtualProtect(block,4096,PAGE_EXECUTE_READ,&old))return 2;FlushInstructionCache(GetCurrentProcess(),block,4096);
 D d={nullptr,Lookup,B,M,R,T,Manager,A,K,N};
 using ModelFn=unsigned(__thiscall*)(void*,unsigned);using CreateFn=void*(__thiscall*)(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
 auto baseline=std::fopen("build/cplayerped-control-baseline.bin","wb");auto rebuiltFile=std::fopen("build/cplayerped-control-rebuilt.bin","wb");if(!baseline||!rebuiltFile)return 3;
 for(sample=0;sample<256;++sample)for(unsigned operation=0;operation<2;++operation){
  auto Run=[&](bool native)->unsigned{if(operation==0)return native?reinterpret_cast<ModelFn>(m)(object.data(),sample&7):C::ApplyModel(object.data(),sample&7,d);unsigned a=sample*0x1234,b=~a,c1=a^0x4321,d1=sample*0xAA55,e=sample*3;return U(native?reinterpret_cast<CreateFn>(c)(object.data(),a,b,c1,d1,e):C::CreateControl(object.data(),a,b,c1,d1,e,d));};
  Initialize();auto expected=Run(true);auto trace=events;auto obj=object,mod=model,ctrl=control;
  Initialize();auto result=Run(false);if(result!=expected||trace!=events||obj!=object||mod!=model||ctrl!=control){std::printf("FAIL sample=%u operation=%u\n",sample,operation);return 4;}
  unsigned n=static_cast<unsigned>(trace.size());std::fwrite(&n,4,1,baseline);std::fwrite(trace.data(),sizeof(Event),n,baseline);std::fwrite(obj.data(),1,4096,baseline);std::fwrite(mod.data(),1,4096,baseline);std::fwrite(ctrl.data(),1,4096,baseline);
  std::fwrite(&n,4,1,rebuiltFile);std::fwrite(events.data(),sizeof(Event),n,rebuiltFile);std::fwrite(object.data(),1,4096,rebuiltFile);std::fwrite(model.data(),1,4096,rebuiltFile);std::fwrite(control.data(),1,4096,rebuiltFile);
 }
 std::fclose(baseline);std::fclose(rebuiltFile);std::printf("PASS comparisons=512 failures=0 dependencies=deterministic_stubs\n");VirtualFree(block,0,MEM_RELEASE);return 0;
}
