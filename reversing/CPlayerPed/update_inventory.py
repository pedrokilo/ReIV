"""Complete slot29 instruction ledger. No caller execution or guessed C++ casts."""
import hashlib,json,struct
from pathlib import Path
import capstone
ROOT=Path(__file__).resolve().parents[2]
b=Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes();digest=hashlib.sha256(b).hexdigest()
assert digest=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',b,60)[0];o=p+24+struct.unpack_from('<H',b,p+20)[0]
ss=[struct.unpack_from('<III',b,o+i*40+12) for i in range(struct.unpack_from('<H',b,p+6)[0])]
def raw(va,n):
 s=next(s for s in ss if s[0]<=va-0x400000<s[0]+s[1]);q=s[2]+va-0x400000-s[0];return b[q:q+n]
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);cs.detail=True
va=0x9C0B00;size=0x7FE;body=raw(va,size);ins=list(cs.disasm(body,va));assert sum(i.size for i in ins)==size
items=[dict(va=hex(i.address),bytes=i.bytes.hex(' '),mnemonic=i.mnemonic,operands=i.op_str) for i in ins]
direct=sorted({int(i.op_str,16) for i in ins if i.mnemonic=='call' and i.op_str.startswith('0x')})
global_uses={}
for i in ins:
 for op in i.operands:
  if op.type==capstone.x86.X86_OP_MEM and op.mem.base==0 and op.mem.index==0:
   global_uses.setdefault(hex(op.mem.disp&0xFFFFFFFF),[]).append(dict(va=hex(i.address),size=op.size,instruction=i.mnemonic+' '+i.op_str))
sections=[(0x9C0B00,0x9C0B53,'early bypass and AL=true'),(0x9C0B53,0x9C0BFE,'member counters and flags'),(0x9C0BFE,0x9C0CDA,'global timed event and random branches'),(0x9C0CDA,0x9C0D4E,'member countdown bytes'),(0x9C0D4E,0x9C0DF5,'SSE vector magnitude and EE0/EE4 float decrements'),(0x9C0DF5,0x9C0E67,'base update and nested entity event'),(0x9C0E67,0x9C0F0A,'position update and stack event lifetime'),(0x9C0F0A,0x9C0FCB,'related XOR test, dynamic slot3, stack vectors and action'),(0x9C0FCB,0x9C1069,'mode-dependent x87 float argument'),(0x9C1069,0x9C1089,'state early return'),(0x9C1089,0x9C114B,'virtual slot59 vector, SSE SQRTSS and COMISS timer'),(0x9C114B,0x9C117C,'related state timestamp'),(0x9C117C,0x9C1203,'nested vehicle state/random/protected value'),(0x9C1203,0x9C121C,'optional callback condition'),(0x9C121C,0x9C1293,'SSE EE8 timer and action2'),(0x9C1293,0x9C12D4,'SSE EEC timer and action21'),(0x9C12D4,0x9C12FE,'signed EF4 countdown and AL=true epilogue')]
transcribed=(ROOT/'source/game/Peds/PlayerPedUpdate.h').exists()
result=dict(exe_sha256=digest,va=hex(va),size=size,body_sha256=hashlib.sha256(body).hexdigest(),body_bytes=body.hex(' '),instructions=items,direct_dependencies=[hex(x) for x in direct],indirect_calls=[x for x in items if x['mnemonic']=='call' and not x['operands'].startswith('0x')],global_uses=global_uses,blocks=[dict(start=hex(s),end_exclusive=hex(e),purpose=t,caller_transcribed=transcribed,per_block_execution_coverage='Not instrumented; complete caller comparison evidence recorded separately') for s,e,t in sections],limitations=['Ghidra integer assignments EE8/EEC are float bit stores; preserve exact SSE semantics.', 'Original return defined in AL only, not entire EAX.', 'No original whole function execution over real game objects or live player update performed.', 'All external subsystem implementations remain dependencies.'])
(ROOT/'reversing/CPlayerPed/evidence/update-static.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
print(f'{size} bytes, {len(items)} instructions, {len(direct)} direct dependencies, {len(global_uses)} global operands')
print('\n'.join(hex(x) for x in direct))
