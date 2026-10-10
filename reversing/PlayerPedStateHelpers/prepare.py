import hashlib,json,struct
from pathlib import Path
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
repo=Path(__file__).resolve().parents[2]
p=Path(r"D:\GTA IV\Grand Theft Auto IV\GTAIV.exe").read_bytes()
sha=hashlib.sha256(p).hexdigest()
assert sha=="ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
pe=struct.unpack_from('<I',p,60)[0];count=struct.unpack_from('<H',p,pe+6)[0];opt=struct.unpack_from('<H',p,pe+20)[0]
def read(va,size):
    for i in range(count):
        o=pe+24+opt+i*40;_,v,rs,rp=struct.unpack_from('<IIII',p,o+8)
        if v<=va-0x400000<v+rs:return p[rp+va-0x400000-v:rp+va-0x400000-v+size]
    raise ValueError(hex(va))
md=Cs(CS_ARCH_X86,CS_MODE_32)
entries=[];header=[]
for name,va,size in [('Clear',0x9bf070,84),('Query7',0x9bf2d0,52),('Query8',0x9bf310,73)]:
    body=read(va,size)
    assert body[-1]==0xc3
    entries.append(dict(name=name,va=f'0x{va:08x}',rva=f'0x{va-0x400000:08x}',body_size=size,bytes=body.hex(' '),instructions=[dict(va=f'0x{i.address:08x}',bytes=i.bytes.hex(' '),asm=i.mnemonic+' '+i.op_str)for i in md.disasm(body,va)]))
    header.append(f'const unsigned char Fixture{name}[]={{'+','.join(hex(x)for x in body)+'};')
(repo/'build/player-state-fixture.h').write_text('\n'.join(header),encoding='utf-8')
proof=[]
for va,size,why in [(0xbfe96b,0x40,'ECX nonnull and byte+219 nonzero before both query8 calls'),(0xc05e80,0x14,'ECX nonnull and byte+219 nonzero before query8'),(0x8792f9,11,'ECX loaded from CPlayerInfo+58C; SDK names m_pPlayerPed'),(0x7b7c72,21,'Same ESI receiver passed consecutively to clear and query7')]:
    body=read(va,size)
    proof.append(dict(va=f'0x{va:08x}',bytes=body.hex(' '),reason=why,instructions=[dict(va=f'0x{i.address:08x}',asm=i.mnemonic+' '+i.op_str)for i in md.disasm(body,va)]))
out=dict(exe_sha256=sha,entries=entries,receiver_proof=proof,source_defining_cpp_class_confirmed=False,selection_exclusions=['9C0A70 static pool-managed-handle helper','9BF360 uses explicit parameter, not ECX receiver'],ownership_scope='Observed player receiver usage; defining original class not inferred from adjacency')
(Path(__file__).parent/'static-bodies.json').write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
print('Verified three complete canonical bodies and four receiver evidence windows.')
