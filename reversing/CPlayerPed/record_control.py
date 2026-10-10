import hashlib,json,subprocess
from pathlib import Path
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[2]
run=subprocess.run([str(ROOT/'build/check-control.exe')],cwd=ROOT,capture_output=True,text=True)
assert run.returncode==0 and 'PASS comparisons=512 failures=0 dependencies=deterministic_stubs' in run.stdout,run.stdout+run.stderr
files=['source/game/Peds/CPlayerPed.h','reversing/CPlayerPed/control_evidence.py','reversing/CPlayerPed/control-fixture.h','reversing/CPlayerPed/check-control.cpp','build/check-control.exe','build/cplayerped-control-patched.bin','build/cplayerped-control-baseline.bin','build/cplayerped-control-rebuilt.bin']
hashes={p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in files}
assert hashes['build/cplayerped-control-baseline.bin']==hashes['build/cplayerped-control-rebuilt.bin']
result=dict(timestamp_utc=datetime.now(timezone.utc).isoformat(),passed=True,comparisons=512,comparisons_per_method=256,failures=0,methods=['0x009C0AA0','0x009C1E10'],return_ordered_trace_and_full_three_buffers_matched=True,live_game_test=False,external_dependencies_reconstructed=False,scope='Own caller bodies compared against complete original instructions with deterministic patched external dependencies; globals redirected to fixtures. Null allocation branch included in stub mode, not real dependent 49F330.',bool_scope='9BF660 consumes only low argument byte; SETNE CL higher bits intentionally unclaimed.',exe_sha256='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c',hashes=hashes,output=run.stdout.strip())
(ROOT/'reversing/CPlayerPed/evidence/control-validation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(run.stdout.strip())
