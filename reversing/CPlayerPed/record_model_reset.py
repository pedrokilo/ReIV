import json,hashlib,subprocess
from pathlib import Path
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[2]
run=subprocess.run([str(ROOT/'build/player-model-reset-check.exe')],cwd=ROOT,capture_output=True,text=True,timeout=20)
assert run.returncode==0 and 'PASS comparisons=10752 failures=0 globals_trace_buffers_fp_state_matched=1' in run.stdout,run.stdout+run.stderr
files=['source/game/Peds/CPlayerPed.h','reversing/CPlayerPed/check-model-reset.cpp','reversing/CPlayerPed/model-reset-fixture.h','reversing/CPlayerPed/model_reset_evidence.py','build/player-model-reset-check.exe','build/player-model-reset-patched.bin']
hashes={p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in files}
result=dict(timestamp_utc=datetime.now(timezone.utc).isoformat(),passed=True,comparisons=10752,failures=0,va='0x009BF660',rva='0x005BF660',complete_body_bytes=163,implementation_kind='C++_own_caller_body_with_explicit_dependencies',implementation_sha256=hashes[files[0]],exe_sha256='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c',game_runtime_validated=False,external_dependencies_reconstructed=False,dependency_scope='Six direct callees and virtual slot68 deterministic substitutes, original thiscall stack cleanup preserved',checks=['256 combinations of null/validA/validB/FFFFFFA0 member states across callbacks','6 DWORD argument patterns exercising low-byte-zero and nonzero with varying upper bits','7 global bit patterns including NaN/sNaN and signed zero','Ordered callback traces with argument/flags/global observations','Three full4096byte buffers and both global words','x87 status and MXCSR identical; masked exceptions'],limitations=['Own caller behavior tested against complete canonical body with external CALLs and two global operands patched.','The original virtual callee selected by slot68 remains a dependency.','No real-player reset or replacement installed.','Complete class layout and external subsystem semantics remain unresolved.'],hashes=hashes,output=run.stdout.strip())
(ROOT/'reversing/CPlayerPed/evidence/model-reset-validation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(run.stdout.strip())
