from pathlib import Path
import json
import hashlib
ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'reversing/CPlayerPed'
OUT=BASE/'native-clone'
OUT.mkdir(exist_ok=True)
manifest=json.loads((BASE/'evidence/native-binding-design.json').read_text())
headers=['#pragma once','#include "../CoffClone.h"','namespace reiv::player_clone {']
for b in manifest['bodies']:
    assert hashlib.sha256((ROOT/b['source_path']).read_bytes()).hexdigest()==b['source_sha256']
    assert hashlib.sha256((ROOT/b['object_path']).read_bytes()).hexdigest()==b['object_sha256']
    name=b['method']; data=bytes.fromhex(b['compiled_template_hex'])
    headers.append(f'inline constexpr unsigned char {name}Bytes[]={{'+','.join(hex(x) for x in data)+'};')
    headers.append(f'inline constexpr Relocation {name}Relocations[]={{')
    kinds={'g':'Global','object':'Object','call':'Call','table':'Table','local_label':'Label'}
    for r in b['relocations']:
        headers.append('{'+f"{r['offset']},Kind::{kinds[r['category']]},{r['original_va'] or 0},{r['symbol_value']},{r['addend']}"+'},')
    headers.append('};')
    entry=88 if name=='Select' else 0
    headers.append(f'inline constexpr Body {name}Body{{{name}Bytes,sizeof {name}Bytes,{name}Relocations,sizeof {name}Relocations/sizeof(Relocation),{entry}}};')
headers.append('}')
(OUT/'templates.h').write_text('\n'.join(headers)+'\n')
for method,filename,prefix in [('Update','check-update.cpp','Update'),('Adjust','check-value-adjust.cpp','Value'),('Select','check-input-select.cpp','Input')]:
    text=(BASE/filename).read_text()
    # Resolve only synthetic globals/opaque contexts and ABI stubs. Private CALL
    # cells and jump tables are owned by CoffClone, never fixture callback slots.
    resolver=f'''\n#include "templates.h"
static unsigned CloneResolve(reiv::player_clone::Kind kind,unsigned va){{
 if(kind==reiv::player_clone::Kind::Call){{for(auto b:{prefix}CallBindings)if(b.original==va)return U(*b.target);}}
'''
    if method=='Update':resolver+=' if(kind==reiv::player_clone::Kind::Object&&va==0x168F910)return U(P::object0168F910);\n'
    resolver+=f' for(auto g:{prefix}GlobalBindings)if(g.original==va)return U(g.storage);return 0;\n}}\n'
    text=text.replace('int main(){',resolver+'int main(){',1)
    needle=' auto code=static_cast<unsigned char*>'
    insertion=f''' reiv::player_clone::CoffClone clones[2];
 for(auto& clone:clones)clone.Create(reiv::player_clone::{method}Body,CloneResolve);
 const auto binding0=clones[0].BindingSnapshot(),binding1=clones[1].BindingSnapshot();
 if(clones[0].Entry()==clones[1].Entry()||!clones[0].Immutable()||!clones[1].Immutable())return 90;
'''
    assert needle in text
    text=text.replace(needle,insertion+needle,1)
    if method=='Update':
        extra='''for(auto& clone:clones){Initialize();_mm_setcsr(fpControl);__asm{fninit}__asm{fldcw x87Control}auto cloneResult=reinterpret_cast<Native>(clone.Entry())(player.data());unsigned short cloneStatus;__asm{fnstsw cloneStatus}if(value!=cloneResult||expected!=Snapshot()||log!=trace||mxcsr!=_mm_getcsr()||status!=cloneStatus)return 91;}'''
        text=text.replace('++comparisons;',extra+'++comparisons;')
    elif method=='Adjust':
        extra='''for(auto& clone:clones){Initialize(field);_mm_setcsr(fp);__asm{fninit}__asm{fldcw cw}auto cloneResult=reinterpret_cast<Original>(clone.Entry())(player.data(),flag,value);unsigned short cloneStatus;__asm{fnstsw cloneStatus}if(pp!=player||aa!=a||bb!=b||log!=trace||expected!=cloneResult||sw!=cloneStatus||mxcsr!=_mm_getcsr())return 91;}'''
        text=text.replace('++count;',extra+'++count;')
    else:
        extra='''for(auto& clone:clones){Initialize();_mm_setcsr(0x1F80);__asm{fninit}reinterpret_cast<Original>(clone.Entry())(player.data());unsigned short cloneStatus;__asm{fnstsw cloneStatus}if(expected!=Snapshot()||log!=trace||fp!=_mm_getcsr()||sw!=cloneStatus)return 91;}'''
        text=text.replace('++count;',extra+'++count;')
    final='''if(!clones[0].Immutable()||!clones[1].Immutable()||clones[0].BindingSnapshot()!=binding0||clones[1].BindingSnapshot()!=binding1)return 92;std::printf("CLONE PASS two_allocations original_source_and_clones_match immutable_bindings=1\\n");'''
    # Prepend checks before the final success message, not a per-group message.
    text=text.replace('std::printf("PASS comparisons=',final+'std::printf("PASS comparisons=',1)
    text=text.replace('build/player-', 'build/privateNativeBinding/clone-'+method.lower()+'-')
    (OUT/filename).write_text(text)
print('Generated source/original/two-clone banks from hashed compiled-source templates')
