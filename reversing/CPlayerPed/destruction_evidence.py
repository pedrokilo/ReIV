"""Extract the complete canonical destructor instructions, without running cleanup."""
import hashlib, json, struct
from pathlib import Path
import capstone
ROOT = Path(__file__).resolve().parents[2]
data = Path(r'D:/GTA IV/Grand Theft Auto IV/GTAIV.exe').read_bytes()
digest = hashlib.sha256(data).hexdigest()
assert digest == 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
pe = struct.unpack_from('<I', data, 60)[0]
table = pe + 24 + struct.unpack_from('<H', data, pe + 20)[0]
sections = [struct.unpack_from('<III', data, table + i * 40 + 12) for i in range(struct.unpack_from('<H', data, pe + 6)[0])]
def raw(va, size):
    rva = va - 0x400000
    section = next(s for s in sections if s[0] <= rva < s[0] + s[1])
    offset = section[2] + rva - section[0]
    return data[offset:offset + size]
decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
functions = []
for va, size in [(0x9C1E60, 0x12B), (0x9C2260, 0x21)]:
    body = raw(va, size)
    instructions = [dict(va=f'0x{i.address:08X}', bytes=i.bytes.hex(' '), mnemonic=i.mnemonic, operands=i.op_str) for i in decoder.disasm(body, va)]
    assert sum(len(bytes.fromhex(i['bytes'])) for i in instructions) == size
    functions.append(dict(va=f'0x{va:08X}', size=size, bytes=body.hex(' '), instructions=instructions))
dependencies = []
for va in [0x8DD270, 0x8DD8B0, 0x5B1C10, 0x92F4D0, 0x8631E0, 0x9C0A70, 0x920CD0, 0x4475F0, 0x8AC1E0, 0x448300]:
    ins = []
    for i in decoder.disasm(raw(va, 1024), va):
        if i.mnemonic == 'int3': break
        ins.append(dict(va=f'0x{i.address:08X}', mnemonic=i.mnemonic, operands=i.op_str))
        if i.mnemonic == 'ret' or (i.address == va and i.mnemonic == 'jmp'): break
    dependencies.append(dict(va=f'0x{va:08X}', entry_linear_disassembly=ins, note='Linear prefix only; dependency body remains external.'))
out = ROOT/'reversing/CPlayerPed/evidence/destruction-static.json'
out.write_text(json.dumps(dict(exe_sha256=digest, functions=functions, dependencies=dependencies, reconstructed_scope='Caller control flow only; dependency bodies and gameplay meaning not reconstructed.', runtime_validated=False), indent=2)+'\n', encoding='utf-8')
lines = ['#pragma once', 'struct DestructorPatch { unsigned offset, target; };']
for name, va, size in [('body',0x9C1E60,0x12B),('wrapper',0x9C2260,0x21)]:
    code = raw(va,size)
    lines.append('inline constexpr unsigned char '+name+'Bytes[] = {'+','.join('0x'+f'{x:02X}' for x in code)+'};')
    patches=[]
    for i in decoder.disasm(code,va):
        if i.mnemonic in ('call','jmp') and i.op_str.startswith('0x'):
            target=int(i.op_str,16)
            if not va<=target<va+size: patches.append((i.address-va+1,target))
    lines.append('inline constexpr DestructorPatch '+name+'Patches[] = {'+','.join('{'+f'{o},0x{t:X}'+'}' for o,t in patches)+'};')
(ROOT/'reversing/CPlayerPed/destruction-fixture.h').write_text('\n'.join(lines)+'\n',encoding='utf-8')
for d in dependencies:
    rets = [i for i in d['entry_linear_disassembly'] if i['mnemonic'] == 'ret']
    print(d['va'], rets)
