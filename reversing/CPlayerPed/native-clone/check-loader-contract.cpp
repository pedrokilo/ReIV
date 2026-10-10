#include "templates.h"
#include <cstdio>
using namespace reiv::player_clone;
static unsigned Resolve(Kind,unsigned){return 0x10000000;}
static unsigned Missing(Kind,unsigned){return 0;}
static bool Reject(Body b,Resolver resolver){
 CoffClone c;try{c.Create(b,resolver);}catch(const std::exception&){try{c.Entry();return false;}catch(const std::exception&){return true;}}return false;
}
int main(){
 unsigned count=0;
 auto Check=[&](bool x){if(!x)throw std::runtime_error("Contract failed");++count;};
 auto b=AdjustBody;b.size=0;Check(Reject(b,Resolve));
 b=AdjustBody;b.size=3;Check(Reject(b,Resolve));
 b=AdjustBody;b.size=4097;Check(Reject(b,Resolve));
 b=AdjustBody;b.entry=b.size;Check(Reject(b,Resolve));
 Check(Reject(AdjustBody,nullptr));Check(Reject(AdjustBody,Missing));
 auto rows=std::vector<Relocation>(AdjustBody.relocations,AdjustBody.relocations+AdjustBody.count);
 b=AdjustBody;b.relocations=rows.data();rows[0].offset=b.size-3;Check(Reject(b,Resolve));
 rows.assign(AdjustBody.relocations,AdjustBody.relocations+AdjustBody.count);rows[1].offset=rows[0].offset;Check(Reject(b,Resolve));
 rows.assign(AdjustBody.relocations,AdjustBody.relocations+AdjustBody.count);rows[0].kind=static_cast<Kind>(99);Check(Reject(b,Resolve));
 rows.assign(SelectBody.relocations,SelectBody.relocations+SelectBody.count);b=SelectBody;b.relocations=rows.data();rows[0].value=b.size;Check(Reject(b,Resolve));
 rows.assign(SelectBody.relocations,SelectBody.relocations+SelectBody.count);rows[1].addend=16;Check(Reject(b,Resolve));
 rows.assign(SelectBody.relocations,SelectBody.relocations+SelectBody.count);rows[1].kind=Kind::Global;Check(Reject(b,Resolve));
 CoffClone valid;valid.Create(SelectBody,Resolve);Check(valid.Immutable());bool repeatedRejected=false;try{valid.Create(SelectBody,Resolve);}catch(const std::exception&){repeatedRejected=true;}Check(repeatedRejected);
 std::printf("PASS loader_contract_checks=%u invalid_inputs_unpublished=1\n",count);
}
