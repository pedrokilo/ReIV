import hashlib,json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256((ROOT/path).read_bytes()).hexdigest()
ledger=json.loads((ROOT/'reversing/CPlayerPed/evidence/actions-static.json').read_text())
assert sha(Path('../Grand Theft Auto IV/GTAIV.exe'))==ledger['exe_sha256']
def run(name):
 r=subprocess.run([str(ROOT/'build'/name)],cwd=ROOT,capture_output=True,text=True)
 print(r.stdout,end='');assert r.returncode==0 and 'PASS comparisons=' in r.stdout and 'failures=0' in r.stdout
 return r.stdout
actions=run('player-actions-check.exe');selection=run('player-action-selection-check.exe')
assert 'comparisons=42320' in actions and 'explicit_matching_null_415_faults=7460' in actions
assert 'comparisons=168960' in selection
contracts=[dict(va=hex(v),callee_pop=p,stack_words=w,return_kind=k) for v,p,w,k in [(0x441F20,0,0,'EAX pointer'),(0x462F90,0,0,'AL predicate'),(0x9BF360,4,1,'AL predicate'),(0x9BF390,4,1,'ST0 float'),(0x9BF420,4,1,'ST0 float'),(0x9C03E0,20,5,'AL predicate'),(0x9C0660,12,3,'AL predicate'),(0x9C07A0,24,6,'ST0 float'),(0x9E9090,16,4,'iterator constructor'),(0x9E9340,0,0,'EAX candidate'),(0xC28820,0,0,'canonical RET only, no effect'),(0xD0C8E4,0,10,'cdecl formatting callback'),(0x924E80,0,1,'cdecl EAX info pointer'),(0x9A9CF0,0,0,'EAX action pointer'),(0x9A9EF0,4,1,'setter, return unused')]]
for filename,vas,count,output,paths in [
 ('actions-validation.json',[0x9C1F90,0x9C2180],42320,actions,['source/game/Peds/PlayerPedActionRange.h','source/game/Peds/PlayerPedActionRequest.h','reversing/CPlayerPed/check-actions.cpp','reversing/CPlayerPed/range-fixture.h','reversing/CPlayerPed/request-fixture.h','reversing/CPlayerPed/action-stubs.h','build/player-actions-check.exe','build/player-action-range-patched.bin','build/player-action-request-patched.bin']),
 ('action-selection-validation.json',[0x9C1300],168960,selection,['source/game/Peds/PlayerPedActionSelection.h','reversing/CPlayerPed/check-action-selection.cpp','reversing/CPlayerPed/selection-fixture.h','reversing/CPlayerPed/selection-stubs.h','build/player-action-selection-check.exe','build/player-action-selection-patched.bin'])]:
 data=dict(passed=True,exe_sha256=ledger['exe_sha256'],implementation_kind='MSVC_x86_ASM',comparisons=count,failures=0,runtime_checked=False,original_full_body=True,methods=[x for x in ledger['methods'] if int(x['va'],16) in vas],contracts=contracts,output=output,hashes={p:sha(Path(p)) for p in paths},scope=dict(isolated_only=True,concurrent_bindings_supported=False,callbacks_are_deterministic_substitutes=True,dependencies_reconstructed=False,live_player_execution=False,exhaustive_edge_coverage=False,canonical_c28820_no_effect_ret=True))
 if filename.startswith('actions-'):data.update(fault_comparisons=7460,fault_code='0xC0000005',fault_address='0x415',per_method_comparisons=21160)
 else:
  counts={m[1]:int(m[2]) for m in re.finditer(r'dependency ([0-9A-F]{8}) calls=(\d+)',output)}
  assert all(counts[f'{v:08X}']>0 for v in [0x441F20,0x462F90,0x9BF360,0x9BF390,0x9BF420,0x9C03E0,0x9C0660,0x9C07A0,0x9E9090,0x9E9340,0xD0C8E4])
  recursion=counts['009E9090']//2-count;assert recursion==16096
  data.update(receiver='embedded CPlayerPed+0xE7C auxiliary',tls_environment_remap='FS:[2C] -> supplied vector via NOP/absolute operand, same instruction length',recursion_calls_per_variant=recursion,recursive_target='own reconstructed Select; baseline own copied original body',dependency_counts=counts)
 (ROOT/'reversing/CPlayerPed/evidence'/filename).write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
