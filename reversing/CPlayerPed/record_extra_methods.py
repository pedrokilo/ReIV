import hashlib,json,re,subprocess
from pathlib import Path
from datetime import datetime,timezone
ROOT=Path(__file__).resolve().parents[2]
configs=[('reference-clear',0x9BEED0,27,512,'CPlayerPed.h','check-reference-clear.cpp','player-reference-clear-check.exe',['C++ own caller; one external reference callback','Full4096byte object and ordered receiver/field/value trace; callback rewrites field before final zero','No layout or ownership inferred']),('value-adjustment',0x9BFD80,332,2457600,'CPlayerPed.h','check-value-adjust.cpp','player-value-adjust-check.exe',['MSVCx86 caller assembly; three external callbacks and six globals','48FP configurations:4rounding/3x87precision/4DAZFTZ; exceptions masked','Return AL, three full4096byte buffers, callback receiver/order and x87/MXCSR matched','Callbacks reassign member228 between lookup and comparison/write; external cap returned in ST0','Null-pointer memory faults not exercised in this bank']),('input-selection',0x9BE7D0,1652,74448,'CPlayerPed.h','check-input-select.cpp','player-input-select-check.exe',['MSVCx86 caller assembly;19external callbacks and2globalDWORDs','Two original four-entry tables relocated for native fixture; source LEA/MOV resolves local labels before original prologue','Table setup preserves flags; EAX caller-saved and overwritten by first dependency','Eight table destinations verified through unique callback modes2/3/4/5/20/21/22/23','Five4096byte and two16384byte buffers, ordered ABI trace/globals/x87/MXCSR matched','Single-thread isolated storage/callback binding; no game mapping/replacement; no exhaustive edge coverage claimed'])]
for stem,va,size,count,header,test,exe,scope in configs:
 run=subprocess.run([str(ROOT/'build'/exe)],cwd=ROOT,capture_output=True,text=True,timeout=90)
 assert run.returncode==0 and f'PASS comparisons={count} failures=0' in run.stdout,run.stdout+run.stderr
 files=[f'source/game/Peds/{header}',f'reversing/CPlayerPed/{test}',f'build/{exe}']
 if stem=='value-adjustment':files+=['reversing/CPlayerPed/value-fixture.h','build/player-value-adjust-patched.bin']
 elif stem=='input-selection':files+=['reversing/CPlayerPed/input-fixture.h','reversing/CPlayerPed/input-stubs.h','build/player-input-select-patched.bin']
 else:files+=['build/player-reference-clear-patched.bin']
 hashes={p:hashlib.sha256((ROOT/p).read_bytes()).hexdigest() for p in files}
 result=dict(timestamp_utc=datetime.now(timezone.utc).isoformat(),passed=True,comparisons=count,failures=0,va=f'0x{va:08X}',rva=f'0x{va-0x400000:08X}',complete_body_bytes=size,implementation_kind='C++_own_caller_explicit_dependencies' if stem=='reference-clear' else 'MSVC_x86_inline_assembly_caller_transcription',implementation_sha256=hashes[files[0]],exe_sha256='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c',game_runtime_validated=False,external_dependencies_reconstructed=False,scope=scope,hashes=hashes,output=run.stdout.strip())
 if stem=='input-selection':
  result['dependency_counts']={va:int(n) for va,n in re.findall(r'dependency ([0-9A-F]+) calls=(\d+)',run.stdout)}
  result['jump_mode_counts']={m:int(n) for m,n in re.findall(r'jump_mode (\d+) calls=(\d+)',run.stdout)}
  assert len(result['dependency_counts'])==19 and all(n>0 for n in result['dependency_counts'].values())
  assert set(result['jump_mode_counts'])=={'2','3','4','5','20','21','22','23'} and all(n>0 for n in result['jump_mode_counts'].values())
 (ROOT/f'reversing/CPlayerPed/evidence/{stem}-validation.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
 print(stem,run.stdout.splitlines()[0],flush=True)
