import hashlib,json,re,subprocess,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256((ROOT/path).read_bytes()).hexdigest()
ledger=json.loads((ROOT/'reversing/CPlayerPed/evidence/related-flags-static.json').read_text())
assert sha(Path('../Grand Theft Auto IV/GTAIV.exe'))==ledger['exe_sha256']
prefix=(ROOT/'reversing/CPlayerPed/remaining_update_methods.py').read_text().split('for va,n in')[0]
ns={'__file__':__file__};exec(prefix,ns);raw=ns['raw'];cs=ns['cs'];contracts=[]
for va,size,pop in [(0x4389D0,17,0),(0xA66B70,11,4),(0x89E4B0,62,4)]:
 body=raw(va,size);ins=list(cs.disasm(body,va));assert sum(i.size for i in ins)==size
 rets=[int(i.op_str,16) if i.op_str else 0 for i in ins if i.mnemonic=='ret'];assert rets and set(rets)=={pop}
 contracts.append(dict(va=hex(va),size=size,callee_pop=pop,body_sha256=hashlib.sha256(body).hexdigest(),instructions=[hex(i.address)+' '+i.mnemonic+' '+i.op_str for i in ins]))
assert struct.unpack('<I',raw(0xD819C4+12*4,4))[0]==0x89E4B0
fixture=(ROOT/'reversing/CPlayerPed/related-flags-fixture.h').read_text();match=re.search(r'RelatedFlagBytes\[\]=\{([^}]+)\}',fixture);assert match
assert bytes(int(x,16) for x in match[1].split(','))==raw(0x9BF250,114)
r=subprocess.run([str(ROOT/'build/player-related-flags-check.exe')],cwd=ROOT,capture_output=True,text=True);print(r.stdout,end='');assert r.returncode==0 and 'PASS comparisons=4096 failures=0' in r.stdout
source='source/game/Peds/CPlayerPed.h';paths=[source,'reversing/CPlayerPed/check-related-flags.cpp','reversing/CPlayerPed/related-flags-fixture.h','reversing/CPlayerPed/evidence/rea-seven-player-callers.json','build/player-related-flags-check.exe','build/player-related-flags-patched.bin']
data=dict(passed=True,failures=0,comparisons=4096,exe_sha256=ledger['exe_sha256'],implementation_sha256=sha(Path(source)),implementation_kind='CXX_x86_raw_fields_explicit_dependencies',methods=ledger['methods'],contracts=contracts,virtual_slot_12=dict(vtable='0xD819C4',target='0x89E4B0',callee_pop=4,argument_byte=1),external_storage=dict(array_base_1662178='uint32 immutable supplied base; model-index multiplication/addition wrap32',flags_16180E0='seven supplied bytes, read after virtual callback'),output=r.stdout,hashes={p:sha(Path(p)) for p in paths},scope=dict(isolated_only=True,runtime_checked=False,dependencies_reconstructed=False,original_declaring_cpp_class_recovered=False,receiver_player_confirmed=True,concurrent_bindings_supported=False,bindings_immutable_during_call=True,virtual_dependency_must_dispatch_current_player_vtable=True,get_block_nonnull_storage_required_for_bank=True,exhaustive_edge_coverage=False,live_player_execution=False))
(ROOT/'reversing/CPlayerPed/evidence/related-flags-validation.json').write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
