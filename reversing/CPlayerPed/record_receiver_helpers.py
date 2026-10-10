import hashlib,json,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256((ROOT/path).read_bytes()).hexdigest()
ledger=json.loads((ROOT/'reversing/CPlayerPed/evidence/receiver-helpers-static.json').read_text())
assert sha(Path('../Grand Theft Auto IV/GTAIV.exe'))==ledger['exe_sha256']
fixture=(ROOT/'reversing/CPlayerPed/receiver-helpers-fixture.h').read_text()
for m in ledger['methods']:
 va=int(m['va'],16);match=re.search(r'Bytes'+f'{va:X}'+r'\[\]=\{([^}]+)\}',fixture);assert match
 baseline=bytes(int(x,16) for x in match[1].split(','));assert baseline==bytes.fromhex(m['body_bytes'])
deps=json.loads((ROOT/'reversing/CPlayerPed/evidence/rea-neighbor-dependency-contracts.json').read_text())
expected={0x921E00:16,0x922020:16,0x921320:0,0x8A3390:0,0x89DFB0:0};contracts=[]
for d in deps:
 va=int(d['address'],16)
 if va not in expected:continue
 ins=d['result']['result']['instructions'];ret=[]
 for i in ins:
  x=re.search(r': RET(?: (0x[0-9a-f]+))?$',i)
  if x:ret.append(int(x[1],16) if x[1] else 0)
 assert ret and set(ret)=={expected[va]}
 contracts.append(dict(va=hex(va),callee_pop=expected[va],return_semantics='AL predicate' if va in (0x8A3390,0x89DFB0) else 'EAX raw bits; semantic C++ return type unknown',instructions=ins))
assert len(contracts)==5
contracts.append(dict(va='0x924e80',callee_pop=0,stack_words=1,return_semantics='EAX info pointer',evidence='rea-input-callee-instructions.json'))
r=subprocess.run([str(ROOT/'build/player-receiver-helpers-check.exe')],cwd=ROOT,capture_output=True,text=True);print(r.stdout,end='');assert r.returncode==0 and 'PASS comparisons=38400 per_method=7680 failures=0' in r.stdout
counts={m[1]:int(m[2]) for m in re.finditer(r'dependency ([0-9A-F]{8}) calls=(\d+)',r.stdout)};assert len(counts)==6 and all(counts.values())
source='source/game/Peds/PlayerPedReceiverHelpers.h'
paths=[source,'reversing/CPlayerPed/check-receiver-helpers.cpp','reversing/CPlayerPed/receiver-helpers-fixture.h','reversing/CPlayerPed/evidence/neighbor-receiver-adjudication.json','reversing/CPlayerPed/evidence/rea-neighbor-dependency-contracts.json','build/player-receiver-helpers-check.exe']+[f'build/player-receiver-{i}-patched.bin' for i in range(5)]
data=dict(passed=True,failures=0,comparisons=38400,per_method_comparisons=7680,exe_sha256=ledger['exe_sha256'],implementation_sha256=sha(Path(source)),implementation_kind='MSVC_x86_ASM',methods=ledger['methods'],contracts=contracts,dependency_counts=counts,output=r.stdout,hashes={p:sha(Path(p)) for p in paths},scope=dict(isolated_only=True,runtime_checked=False,dependencies_reconstructed=False,original_declaring_cpp_class_recovered=False,receiver_player_confirmed=True,concurrent_bindings_supported=False,native_null_dependency_behavior_validated=False,exhaustive_edge_coverage=False,live_player_execution=False))
(ROOT/'reversing/CPlayerPed/evidence/receiver-helpers-validation.json').write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
