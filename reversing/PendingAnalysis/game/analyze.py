"""Bounded static analysis of every game destination, never invokes unknown code."""
import csv,hashlib,json,pathlib,struct,collections
import capstone
ROOT=pathlib.Path(__file__).resolve().parents[3]
OUT=pathlib.Path(__file__).resolve().parent;OUT.mkdir(parents=True,exist_ok=True)
EXE=pathlib.Path(r'D:\GTA IV\Grand Theft Auto IV\GTAIV.exe')
d=EXE.read_bytes();sha=hashlib.sha256(d).hexdigest()
assert sha=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe=struct.unpack_from('<I',d,60)[0];opt=pe+24;base=struct.unpack_from('<I',d,opt+28)[0];sections=[]
for i in range(struct.unpack_from('<H',d,pe+6)[0]):
 p=opt+struct.unpack_from('<H',d,pe+20)[0]+40*i;va,size,ptr=struct.unpack_from('<III',d,p+12);sections.append((va,size,ptr,struct.unpack_from('<I',d,p+36)[0]))
refs=[r for r in csv.DictReader((ROOT/'docs/MemoryMap/pending_hooks.csv').open(encoding='utf-8-sig')) if r['file'].startswith('source/game/')]
known={int(r['rva'],16) for r in csv.DictReader((ROOT/'docs/hooks.csv').open(encoding='utf-8-sig')) if r['runtime_checked']=='1' and r['source_matches_evidence']=='1'}
groups={}
for r in refs:groups.setdefault(int(r['rva'],16),[]).append(r)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True
items=[];candidates=[]
for rva,rows in sorted(groups.items()):
 va=rva+base;sec=next((s for s in sections if s[0]<=rva<s[0]+s[1] and s[3]&0x20000000),None)
 op=None;off=0;length=0;ins=[];reason='not_executable_file_backed';direct=[];indirect=[];complete=False
 if sec:
  pos=sec[2]+rva-sec[0];raw=d[pos:min(pos+256,sec[2]+sec[1])]
  for prefix,name in [(bytes.fromhex('8b41'),'get_u32'),(bytes.fromhex('8a41'),'get_u8'),(bytes.fromhex('d941'),'get_float'),(bytes.fromhex('8d41'),'address_offset')]:
   if raw.startswith(prefix) and raw[3]==0xc3 and raw[2]<128:op,off,length=name,raw[2],4
  for prefix,name in [(bytes.fromhex('8b81'),'get_u32'),(bytes.fromhex('8a81'),'get_u8'),(bytes.fromhex('d981'),'get_float'),(bytes.fromhex('8d81'),'address_offset')]:
   if raw.startswith(prefix) and raw[6]==0xc3:
    n=int.from_bytes(raw[2:6],'little',signed=True)
    if 0<=n<=4092:op,off,length=name,n,7
  for lead,store,name in [(bytes.fromhex('8b442404'),bytes.fromhex('8941'),'set_u32'),(bytes.fromhex('8a442404'),bytes.fromhex('8841'),'set_u8')]:
   if raw.startswith(lead+store) and raw[7:10]==bytes.fromhex('c20400') and raw[6]<128:op,off,length=name,raw[6],10
  for lead,store,name in [(bytes.fromhex('8b442404'),bytes.fromhex('8981'),'set_u32'),(bytes.fromhex('8a442404'),bytes.fromhex('8881'),'set_u8')]:
   if raw.startswith(lead+store) and raw[10:13]==bytes.fromhex('c20400'):
    n=int.from_bytes(raw[6:10],'little',signed=True)
    if 0<=n<=4092:op,off,length=name,n,13
  reason='bounded_path_requires_abi_object_lifetime_and_state'
  for i in md.disasm(raw,va):
   ins.append(f'{i.address:08x}: {i.mnemonic} {i.op_str}')
   if i.mnemonic=='call':
    if i.operands[0].type==capstone.x86.X86_OP_IMM:direct.append(hex(i.operands[0].imm&0xffffffff))
    else:indirect.append(i.op_str)
   if i.group(capstone.CS_GRP_RET):complete=True;break
   if i.group(capstone.CS_GRP_JUMP):reason='branch_or_tail_jump_requires_control_flow_and_callee_analysis';break
   if len(ins)>=64:reason='instruction_limit_requires_full_control_flow_analysis';break
  if direct:reason='direct_callees_require_abi_and_state_validation'
  if indirect:reason='indirect_callee_and_object_layout_unverified'
  if not ins:reason='instruction_decode_failed'
  if op:reason='exact_fixture_candidate' if rva not in known else 'historical_runtime_fixture'
 if va==0x401210:reason='fatal_process_termination_handler_never_call';op=None
 item=dict(rva=f'0x{rva:08x}',va=f'0x{va:08x}',owners=sorted(set(r['owner'] for r in rows)),reference_count=len(rows),historical_runtime_checked=rva in known,exact_operation=op or '',offset=off if op else '',untested_reason=reason,first_path_reaches_ret=complete,direct_calls=direct,indirect_calls=indirect,disassembly=ins,enabled=False)
 items.append(item)
 if op and rva not in known:candidates.append(dict(va=item['va'],rva=item['rva'],operation=op,value=off,entry_bytes=raw[:length].hex(' '),body_size=length,abi='x86_thiscall_fixture',owners=item['owners'],reference_count=len(rows),runtime_tested=False,enabled=False,exe_sha256=sha))
(OUT/'targets.json').write_text(json.dumps(items,indent=2)+'\n')
(OUT/'fixture-scope.json').write_text(json.dumps(candidates,indent=2)+'\n')
by={i['rva']:i for i in items}
fields=list(refs[0])+['historical_runtime_checked','exact_operation','offset','untested_reason','direct_calls','indirect_calls','first_path_reaches_ret']
with (OUT/'references.csv').open('w',newline='',encoding='utf-8') as f:
 w=csv.DictWriter(f,fieldnames=fields);w.writeheader()
 for r in refs:
  i=by[f"0x{int(r['rva'],16):08x}"];w.writerow(dict(r,**{k:(';'.join(i[k]) if isinstance(i[k],list) else i[k]) for k in fields[len(refs[0]):]}))
summary=dict(exe_sha256=sha,scope='all source/game pending-address references; historical checked addresses retained',references=len(refs),unique_targets=len(items),historical_runtime_targets=sum(i['historical_runtime_checked'] for i in items),new_exact_fixture_targets=len(candidates),new_exact_fixture_references=sum(i['reference_count'] for i in candidates),dispositions=dict(collections.Counter(i['untested_reason'] for i in items)),analysis_limit='first linear path only, at most256bytes/64instructions; branches stop analysis; no full function boundaries inferred')
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary))
