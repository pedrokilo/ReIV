import hashlib
import json
from pathlib import Path
import struct

repo = Path(__file__).resolve().parents[2]
exe = Path(r"D:\GTA IV\Grand Theft Auto IV\GTAIV.exe")
data = exe.read_bytes()
sha = hashlib.sha256(data).hexdigest()
assert sha == "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
pe = struct.unpack_from("<I", data, 60)[0]
count = struct.unpack_from("<H", data, pe + 6)[0]
optional_size = struct.unpack_from("<H", data, pe + 20)[0]
def read(va, size):
    for i in range(count):
        off = pe + 24 + optional_size + i * 40
        _, rva, raw_size, raw_pointer = struct.unpack_from("<IIII", data, off + 8)
        if rva <= va - 0x400000 < rva + raw_size:
            start = raw_pointer + va - 0x400000 - rva
            return data[start:start + size]
    raise ValueError(hex(va))

entries = []
header = []
for name, va, size in [("Write",0x447610,36),("Read",0x447640,25),("Flags",0x89e5a0,111),("Set60",0x9c1cf0,41),("Set61",0x9c1d20,41),("Add62",0x9c1d50,56),("Get63",0x9c1ce0,11)]:
    body = read(va,size)
    assert body[-1] in [0,0xc3,0xff]
    entries.append(dict(name=name,va=f"0x{va:08x}",rva=f"0x{va-0x400000:08x}",body_size=size,bytes=body.hex(" ")))
    header.append(f"const unsigned char Fixture{name}[] = {{{','.join(hex(b) for b in body)}}};")
assert read(0xdcea38,4) == struct.pack("<f",50)
assert read(0xd8f340,4) == struct.pack("<f",100)
(repo/"build/player-protected-fixture.h").write_text("\n".join(header),encoding="utf-8")
(Path(__file__).parent/"static-bodies.json").write_text(json.dumps(dict(exe_sha256=sha,entries=entries),indent=2)+"\n",encoding="utf-8")
print("Verified seven complete bodies and both threshold constants against canonical EXE.")
