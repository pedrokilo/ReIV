"""Read-only source analysis; writes a new canonical evidence ledger only."""
import json,hashlib,struct
from pathlib import Path
import capstone
ROOT=Path(__file__).resolve().parents[2];b=Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes();digest=hashlib.sha256(b).hexdigest();assert digest=='ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
p=struct.unpack_from('<I',b,60)[0];o=p+24+struct.unpack_from('<H',b,p+20)[0];ss=[struct.unpack_from('<III',b,o+i*40+12) for i in range(struct.unpack_from('<H',b,p+6)[0])]
def raw(va,n):
 s=next(s for s in ss if s[0]<=va-0x400000<s[0]+s[1]);q=s[2]+va-0x400000-s[0];return b[q:q+n]
cs=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);cs.detail=True;items=[]
for va,n in [(0x9BEED0,27),(0x9BFD80,332),(0x9BE7D0,1652)]:
 body=raw(va,n);ins=list(cs.disasm(body,va));assert sum(i.size for i in ins)==n
 deps=sorted({int(i.op_str,16) for i in ins if i.mnemonic=='call' and i.op_str.startswith('0x')})
 globals_={}
 for i in ins:
  for op in i.operands:
   if op.type==capstone.x86.X86_OP_MEM and not op.mem.base and not op.mem.index:
    g=op.mem.disp&0xFFFFFFFF;globals_.setdefault(hex(g),[]).append(dict(va=hex(i.address),width=op.size,instruction=i.mnemonic+' '+i.op_str))
 tables=[]
 if va==0x9BE7D0:
  for address in [0x9BEE44,0x9BEE54]:
   targets=struct.unpack('<IIII',raw(address,16));assert all(va<=t<va+n for t in targets)
   tables.append(dict(va=hex(address),bytes=raw(address,16).hex(' '),targets=[hex(t) for t in targets],entries=4,reason='EAX index after SUB11/CMP3/JA out-of-range; indirect JMP uses table'))
 items.append(dict(va=hex(va),size=n,instruction_count=len(ins),body_sha256=hashlib.sha256(body).hexdigest(),body_bytes=body.hex(' '),instructions=[dict(va=hex(i.address),bytes=i.bytes.hex(' '),mnemonic=i.mnemonic,operands=i.op_str) for i in ins],direct_dependencies=[hex(t) for t in deps],global_uses=globals_,jump_tables=tables,reconstructed=False,runtime_validated=False))
out=ROOT/'reversing/CPlayerPed/evidence/remaining-update-methods.json';out.write_text(json.dumps(dict(exe_sha256=digest,scope='Three confirmed own nonvirtual functions called by player update; inventory only, no source changes or function execution',methods=items),indent=2)+'\n',encoding='utf-8')
for x in items:print(x['va'],x['size'],x['instruction_count'],'deps',len(x['direct_dependencies']),'globals',len(x['global_uses']))
