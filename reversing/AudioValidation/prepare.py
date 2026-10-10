import csv,json,re,pathlib
root=pathlib.Path(__file__).resolve().parent
ev=root/'evidence'
rows=list(csv.DictReader((ev/'scope.csv').open(newline='',encoding='utf-8-sig')))
# Complete instruction bodies prove only these isolated operations, not semantic names.
spec={
0x4d7030:('constant_u8',0),0x4d8bc0:('address_offset',4),0x7bdc00:('constant_u32',0),
0x8155a0:('outputs_minus_one',0),0x8155c0:('constant_u32',0x5d5c),
0x8161d0:('compare_u32',4),0x89bbb0:('set_u32',8),
0x8b4d00:('get_float',0x20),0x8b4d10:('get_u32',0x34),0x8b4d20:('compare_u32',0x30),
0x8b4d30:('set_pair',0x38),0x8b4d50:('get_pair',0x38),0x8b4d70:('constant_u32',3),
0x8b4d80:('get_u32',0x24),0x8b4d90:('get_u32',0x28),0x8b4da0:('get_float',0x2c),
0x92c4d0:('noop_two_args',0),0x988ac0:('identity_this',0),0x988b60:('constant_u8',15),
0xa2bd60:('set_u32',0x34),0xaaaf20:('noop_one_arg',0),0xaad200:('get_u32',0x120),
0xac7ba0:('set_u32',0xa4),0xaec4d0:('get_u32',0x820),0xc28820:('noop',0),
0xc5d610:('get_u8',0x40),0xc87a50:('constant_float',1),0xccf450:('get_u32',0x250),
0xcfaee0:('constant_u8',1)}
candidates=[]
for va,(op,value) in spec.items():
 text=(ev/f'{va:08x}.txt').read_text(encoding='utf-8')
 size=int(re.search(r'Body size: (\d+)',text)[1])
 entry=re.search(r'Entry bytes: (.*)',text)[1].split()[:size]
 assert len(entry)==size and not any(x in text for x in [' CALL ',' JMP '])
 candidates.append(dict(va=f'0x{va:08x}',rva=f'0x{va-0x400000:08x}',operation=op,value=value,
  abi='x86_thiscall_fixture',entry_bytes=' '.join(entry),body_size=size,
  owners=sorted(set(r['owner'] for r in rows if int(r['va'],16)==va)),
  evidence=f'reversing/AudioValidation/evidence/{va:08x}.txt',runtime_tested=False,enabled=False))
(ev/'candidates.json').write_text(json.dumps(candidates,indent=2)+'\n',encoding='utf-8')
for r in rows:
 va=int(r['va'],16)
 r['static_disposition']='fixture_candidate' if va in spec else ('blocked_process_termination' if va==0x401210 else 'pending_abi_lifetime_state')
 r['static_evidence']=f'reversing/AudioValidation/evidence/{va:08x}.txt'
with (ev/'scope.csv').open('w',newline='',encoding='utf-8') as f:
 w=csv.DictWriter(f,fieldnames=rows[0].keys());w.writeheader();w.writerows(rows)
print(json.dumps(dict(references=len(rows),unique_targets=len(set(r['va'] for r in rows)),candidates=len(candidates),candidate_references=sum(r['static_disposition']=='fixture_candidate' for r in rows))))
