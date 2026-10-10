"""Verify the two complete float-copy bodies against the canonical GTA IV EXE."""
import hashlib
import json
from pathlib import Path
import struct

EXE = Path(r"D:\GTA IV\Grand Theft Auto IV\GTAIV.exe")
EXPECTED_HASH = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
body = bytes.fromhex("8b442404d900f30f104004f30f104808d999c00e0000f30f1181c40e0000f30f1189c80e0000d9400cd999cc0e0000c20400")
data = EXE.read_bytes()
assert hashlib.sha256(data).hexdigest() == EXPECTED_HASH
pe = struct.unpack_from("<I", data, 0x3c)[0]
section_count = struct.unpack_from("<H", data, pe + 6)[0]
optional_size = struct.unpack_from("<H", data, pe + 20)[0]
entries = []
for slot, rva, destination in [(79, 0x5c1d90, 0xec0), (80, 0x5c1dd0, 0xed0)]:
    expected = bytearray(body)
    if slot == 80:
        for offset in [18, 26, 34, 43]:
            expected[offset] += 0x10
    actual = None
    for i in range(section_count):
        header = pe + 24 + optional_size + i * 40
        _, start, size, file_start = struct.unpack_from("<IIII", data, header + 8)
        if start <= rva < start + size:
            actual = data[file_start + rva - start:file_start + rva - start + len(expected)]
            break
    assert actual == expected, f"Complete body mismatch at RVA {rva:08x}"
    entries.append(dict(slot=slot, rva=f"0x{rva:08x}", destination=f"0x{destination:x}", bytes=actual.hex(" "), body_size=len(actual), stack_cleanup=4))
print(json.dumps(dict(exe_sha256=EXPECTED_HASH, entries=entries), indent=2))
