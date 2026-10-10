"""Inventory relocations in compiled reconstructed MSVC x86 COMDAT bodies.

No GTAIV bytes are consumed, no process is opened, and no hook is installed.
The output is a design artifact, not an executable native binding.
"""
from pathlib import Path
import hashlib
import json
import re
import struct
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

ROOT = Path(__file__).resolve().parents[2]
SPECS = [
    ("Update", "build/privateNativeBinding/check-update.obj", "source/game/Peds/CPlayerPed.h"),
    ("Adjust", "build/privateNativeBinding/check-value-adjust.obj", "source/game/Peds/CPlayerPed.h"),
    ("Select", "build/privateNativeBinding/check-input-select.obj", "source/game/Peds/CPlayerPed.h"),
]
SNAPSHOT_HASHES = {
    "Update": ("cf34ebdac8a2f0012f358da3779a5b7941522803ffd3a0d56de4d2eb31d4e1f8", "45c299b8ecbf1dafc2c163e0aab4a3a9fa7e5c812e75965825e0582cc779d1c3"),
    "Adjust": ("fee014ed9e645079a9a4d9ad4300eab383a5d42472d660038d3379abc566a616", "45c299b8ecbf1dafc2c163e0aab4a3a9fa7e5c812e75965825e0582cc779d1c3"),
    "Select": ("a3169bef417fc5c41e85e2c7d95c59520791b6b044e7f20f8b996c7f1938005d", "45c299b8ecbf1dafc2c163e0aab4a3a9fa7e5c812e75965825e0582cc779d1c3"),
}


def inspect(method, objpath, sourcepath):
    data = (ROOT / objpath).read_bytes()
    source_hash = hashlib.sha256((ROOT / sourcepath).read_bytes()).hexdigest()
    assert (hashlib.sha256(data).hexdigest(), source_hash) == SNAPSHOT_HASHES[method], "Snapshot/source changed; recompile and reaudit before updating pinned hashes"
    machine, count, _, symbol_offset, symbol_count, optional_size, _ = struct.unpack_from("<HHIIIHH", data)
    assert machine == 0x14C and optional_size == 0
    strings = symbol_offset + symbol_count * 18

    def name(raw):
        zero, offset = struct.unpack("<II", raw)
        if zero == 0:
            start = strings + offset
            return data[start:data.index(b"\0", start)].decode()
        return raw.rstrip(b"\0").decode()

    symbols = {}
    index = 0
    while index < symbol_count:
        position = symbol_offset + index * 18
        value, section, typ, storage, auxiliary = struct.unpack_from("<IhHBB", data, position + 8)
        symbols[index] = (name(data[position:position + 8]), value, section, typ, storage)
        index += 1 + auxiliary
    matches = [s for s in symbols.values() if s[0].startswith("?" + method + "@")] 
    assert len(matches) == 1
    function = matches[0]
    section = function[2]
    assert function[1] == 0 and 0 < section <= count
    header = 20 + (section - 1) * 40
    length, raw_offset, relocation_offset = struct.unpack_from("<III", data, header + 16)
    relocation_count = struct.unpack_from("<H", data, header + 32)[0]
    flags = struct.unpack_from("<I", data, header + 36)[0]
    assert flags & 0x20 and flags & 0x1000  # code, independent COMDAT
    body = data[raw_offset:raw_offset + length]
    decoder = Cs(CS_ARCH_X86, CS_MODE_32)
    decoder.detail = True
    instructions = list(decoder.disasm(body, 0))
    assert sum(i.size for i in instructions) == length
    fields = {}
    for instruction in instructions:
        for offset, size in [(instruction.disp_offset, instruction.disp_size), (instruction.imm_offset, instruction.imm_size)]:
            if size == 4:
                fields[instruction.address + offset] = instruction
    rows = []
    for index in range(relocation_count):
        offset, symbol_index, kind = struct.unpack_from("<IIH", data, relocation_offset + index * 10)
        symbol, value, symbol_section, _, _ = symbols[symbol_index]
        assert kind == 6 and offset in fields  # IMAGE_REL_I386_DIR32, operand boundary
        addend = struct.unpack_from("<I", body, offset)[0]
        if symbol_section == section:
            assert symbol.startswith("$L") and value + addend < length
            category, va = "local_label", None
        else:
            match = re.match(r"\?(g|object|call|table)([0-9A-F]{8})@", symbol)
            assert match, symbol
            category, va = match[1], int(match[2], 16)
            assert va >= 0x400000
        instruction = fields[offset]
        rows.append(dict(offset=offset, kind=kind, symbol=symbol, category=category,
                         original_va=va, symbol_value=value, addend=addend,
                         instruction_offset=instruction.address,
                         instruction=instruction.mnemonic + " " + instruction.op_str))
    assert len({r['offset'] for r in rows}) == len(rows)

    # Verify patch arithmetic and operand positions independently of a live game.
    # Synthetic game addresses, private callback cells and tables never point at fixtures.
    for copy_base, game_base, cell_base, table_base in [
        (0x20000000, 0x00400000, 0x30000000, 0x30001000),
        (0x18000000, 0x12000000, 0x31000000, 0x31001000),
    ]:
        patched = bytearray(body)
        calls = sorted({r['symbol'] for r in rows if r['category'] == 'call'})
        tables = sorted({r['symbol'] for r in rows if r['category'] == 'table'})
        expected = {}
        for row in rows:
            category = row['category']
            if category == 'local_label':
                address = copy_base + row['symbol_value']
            elif category == 'call':
                address = cell_base + calls.index(row['symbol']) * 4
            elif category == 'table':
                address = table_base + tables.index(row['symbol']) * 16
            else:
                address = game_base + row['original_va'] - 0x400000
            result = address + row['addend']
            assert 0 <= result <= 0xFFFFFFFF
            struct.pack_into('<I', patched, row['offset'], result)
            expected[row['offset']] = result
        decoded = list(decoder.disasm(bytes(patched), copy_base))
        assert [i.size for i in decoded] == [i.size for i in instructions]
        changed = {n for r in rows for n in range(r['offset'], r['offset'] + 4)}
        assert all(a == b or n in changed for n, (a, b) in enumerate(zip(body, patched)))
        assert all(struct.unpack_from('<I', patched, offset)[0] == target for offset, target in expected.items())
    return dict(method=method, object_path=objpath, source_path=sourcepath,
                object_sha256=hashlib.sha256(data).hexdigest(),
                source_sha256=source_hash,
                compiled_section=section, compiled_bytes=length, compiled_sha256=hashlib.sha256(body).hexdigest(),
                relocation_count=relocation_count, relocations=rows,
                patch_arithmetic_cases=2, all_patch_fields_verified=True,
                compiled_template_hex=body.hex())


if __name__ == '__main__':
    output = dict(origin='Compiled reconstructed source COMDAT; no original game body copied',
                  scope='Static extraction and synthetic byte patch arithmetic only',
                  native_clone_executed=False, game_runtime_validated=False, hooks_installed=False,
                  bodies=[inspect(*spec) for spec in SPECS])
    destination = ROOT / 'reversing/CPlayerPed/evidence/native-binding-design.json'
    destination.write_text(json.dumps(output, indent=2) + '\n', encoding='utf-8')
    print('PASS static compiled-body relocation inventory', [(b['method'], b['compiled_bytes'], b['relocation_count']) for b in output['bodies']])
