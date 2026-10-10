"""Record successful independent Win32 caller-body comparison."""
import hashlib,json,subprocess
from datetime import datetime, timezone
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path): return hashlib.sha256((ROOT/path).read_bytes()).hexdigest()
exe=ROOT/'build/check-destructor.exe'
run=subprocess.run([str(exe)],cwd=ROOT,capture_output=True,text=True)
assert run.returncode==0,run.stdout+run.stderr
assert 'PASS comparisons=256 failures=0 null_member_access_violation=matched dependencies=deterministic_stubs' in run.stdout
files=['source/game/Peds/PlayerPedDestruction.h','reversing/CPlayerPed/check-destructor.cpp','reversing/CPlayerPed/destruction-fixture.h','reversing/CPlayerPed/destruction_evidence.py','build/check-destructor.exe','build/cplayerped-destructor-patched.bin','build/cplayerped-destructor-baseline.bin','build/cplayerped-destructor-reconstruction.bin']
hashes={p:sha(Path(p)) for p in files}
assert hashes['build/cplayerped-destructor-baseline.bin']==hashes['build/cplayerped-destructor-reconstruction.bin']
result=dict(timestamp_utc=datetime.now(timezone.utc).isoformat(),passed=True,comparisons=256,failures=0,return_and_ordered_events_and_three_4096_byte_buffers_compared=True,null_member_fault='Both EXCEPTION_ACCESS_VIOLATION, expected original precondition',live_game_test=False,dependencies_reconstructed=False,dependency_mode='Ten deterministic stubs; original calls/tail jump replaced; three absolute global operands relocated to local fixtures',exe_sha256='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c',hashes=hashes,output=run.stdout.strip())
(ROOT/'reversing/CPlayerPed/evidence/destruction-validation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(run.stdout.strip())
