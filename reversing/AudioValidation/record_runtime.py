import csv,json,pathlib
root=pathlib.Path(__file__).resolve().parents[2]
ev=root/'reversing/AudioValidation/evidence'
audio=json.loads((ev/'runtime-report.json').read_text(encoding='utf-8-sig'))
game=json.loads((root/'reversing/GameValidation/evidence/runtime-report.json').read_text(encoding='utf-8-sig'))
passed={int(x['rva'],16)+0x400000:'audio_fixture' for x in audio['entries'] if x['calls'] and not x['failures']}
passed.update({int(x['rva'],16)+0x400000:'shared_stub' for x in game['entries'] if x['calls'] and not x['failures']})
extra_path=root/'reversing/ExtraStubValidation/evidence/runtime-report.json'
if extra_path.exists():
 extra=json.loads(extra_path.read_text(encoding='utf-8-sig'))
 if extra['phase']=='passed' and not extra['exceptions']:
  passed.update({int(x['rva'],16)+0x400000:'extra_stub' for x in extra['entries'] if x['calls'] and not x['failures']})
rows=list(csv.DictReader((ev/'scope.csv').open(encoding='utf-8-sig',newline='')))
for row in rows:
 va=int(row['va'],16);ok=va in passed
 row['runtime_reference_tested']='1' if ok else '0'
 row['runtime_disposition']='passed_'+passed[va] if ok else row['static_disposition']
 row['runtime_evidence']={'audio_fixture':'reversing/AudioValidation/evidence/runtime-report.json','shared_stub':'reversing/GameValidation/evidence/runtime-report.json','extra_stub':'reversing/ExtraStubValidation/evidence/runtime-report.json'}.get(passed.get(va),'')
 row['enabled']='0';row['reconstructed']='0'
with (ev/'scope.csv').open('w',newline='',encoding='utf-8') as f:
 w=csv.DictWriter(f,fieldnames=rows[0].keys());w.writeheader();w.writerows(rows)
files=list(csv.DictReader((ev/'files.csv').open(encoding='utf-8-sig',newline='')))
for file in files:file['runtime_tested']=sum(row['runtime_reference_tested']=='1' for row in rows if row['file']==file['file'])
with (ev/'files.csv').open('w',newline='',encoding='utf-8') as f:
 w=csv.DictWriter(f,fieldnames=files[0].keys());w.writeheader();w.writerows(files)
print(json.dumps({'proven_references':sum(row['runtime_reference_tested']=='1' for row in rows),'unique_targets':len({row['va'] for row in rows if row['runtime_reference_tested']=='1'}),'fixture_calls':sum(e['calls'] for e in audio['entries'])}))
