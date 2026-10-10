"""Inventory art references; exact pure-return patterns are candidates, not validation."""

import csv

import hashlib

import json

import struct

from collections import Counter

from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

EXE = Path(r"D:\GTA IV\Grand Theft Auto IV\GTAIV.exe")

SHA = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"

def read_csv(path):

    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:

        return list(csv.DictReader(stream))

def main():

    refs = [r for r in read_csv("docs/MemoryMap/pending_hooks.csv") if r["file"].startswith("source/external/ART/")]

    classes = [r for r in read_csv("source/class-files.csv") if r["file"].startswith("source/external/ART/")]

    data = EXE.read_bytes()

    assert hashlib.sha256(data).hexdigest() == SHA

    pe = struct.unpack_from("<I", data, 0x3c)[0]

    assert data[pe:pe+4] == b"PE\0\0"

    machine, count = struct.unpack_from("<HH", data, pe+4)

    assert machine == 0x14c

    optsize = struct.unpack_from("<H", data, pe+20)[0]

    opt = pe+24

    assert struct.unpack_from("<H", data, opt)[0] == 0x10b

    base = struct.unpack_from("<I", data, opt+28)[0]

    sections = []

    for i in range(count):

        pos = opt+optsize+i*40

        vs, va, size, ptr = struct.unpack_from("<IIII", data, pos+8)

        flags = struct.unpack_from("<I", data, pos+36)[0]

        sections.append((va, size, ptr, flags))

    def file_offset(rva):

        section = next((s for s in sections if s[0] <= rva < s[0]+s[1]), None)

        return None if section is None else section[2]+rva-section[0]

    reloc_rva, reloc_size = struct.unpack_from("<II", data, opt+96+5*8)

    relocations = {}

    if reloc_rva and reloc_size:

        cursor = file_offset(reloc_rva)

        assert cursor is not None

        end = cursor+reloc_size

        while cursor+8 <= end:

            page, block_size = struct.unpack_from("<II", data, cursor)

            assert block_size >= 8 and cursor+block_size <= end

            for pos in range(cursor+8, cursor+block_size, 2):

                encoded = struct.unpack_from("<H", data, pos)[0]

                kind, offset = encoded >> 12, encoded & 0xfff

                if kind:

                    relocations[page+offset] = kind

            cursor += block_size

    candidates = []

    by_rva = {}

    for ref in refs:

        by_rva.setdefault(int(ref["rva"], 16), []).append(ref)

    for rva, owners in sorted(by_rva.items()):

        section = next((s for s in sections if s[0] <= rva < s[0]+s[1]), None)

        if not section or not section[3] & 0x20000000:

            continue

        start = section[2]+rva-section[0]

        b = data[start:start+16]

        pattern, length, mask, expected = None, 0, 0, 0

        stack_pop, float_return = 0, False

        # RET n must discard a whole number of explicit synthetic x86 arguments.

        if b[:1] == b"\xc2" and len(b)>=3 and int.from_bytes(b[1:3],"little") in (4,8,12,16,20):

            pattern,length,stack_pop="return_only_stack_pop",3,int.from_bytes(b[1:3],"little")

        elif b[:2] in (b"\x33\xc0",b"\x31\xc0",b"\x32\xc0") and b[2:3]==b"\xc2" and int.from_bytes(b[3:5],"little") in (4,8,12,16,20):

            pattern,length,stack_pop="return_zero_stack_pop",5,int.from_bytes(b[3:5],"little")

            mask=0xff if b[0]==0x32 else 0xffffffff

        elif b.startswith(b"\xd9\xe8\xc3"):

            pattern,length,float_return="return_float_one",3,True

        if b.startswith(b"\xc3"):

            pattern, length = "return_only", 1

        elif b[:3] in (b"\x33\xc0\xc3", b"\x31\xc0\xc3"):

            pattern, length, mask = "return_eax_zero", 3, 0xffffffff

        elif b.startswith(b"\x32\xc0\xc3"):

            pattern, length, mask = "return_al_zero", 3, 0xff

        elif len(b) >= 6 and b[0] == 0xb8 and b[5] == 0xc3:

            pattern, length, mask, expected = "return_eax_constant", 6, 0xffffffff, int.from_bytes(b[1:5], "little")

        elif len(b) >= 3 and b[0] == 0xb0 and b[2] == 0xc3:

            pattern, length, mask, expected = "return_al_constant", 3, 0xff, b[1]

        if pattern:

            body_relocs = {pos:kind for pos,kind in relocations.items() if rva <= pos < rva+length}

            relocated = body_relocs == {rva+1:3} and pattern == "return_eax_constant"

            if body_relocs and not relocated:

                continue

            candidates.append(dict(va=f"0x{base+rva:08X}", rva=f"0x{rva:08X}", bytes=b.hex(" "), length=length,

                pattern=pattern, return_mask=mask, expected_return=expected,

                relocated_imm=relocated, stack_pop=stack_pop, float_return=float_return,

                owners=sorted(set(r["owner"] for r in owners)), reference_count=len(owners),

                status="static_candidate_not_runtime_validated"))

    evidence = ROOT / "reversing/ARTValidation/evidence"

    evidence.mkdir(parents=True, exist_ok=True)

    result = dict(exe_sha256=SHA, image_base=f"0x{base:08X}", header_count=len(classes),

                  reference_count=len(refs), unique_destinations=len(by_rva), candidates=candidates)

    (evidence / "simple-candidates.json").write_text(json.dumps(result, indent=2)+"\n", encoding="utf-8")

    bindings = "// Generated exact complete pure-return bodies. Included inside namespace artstubs after Candidate.\n"

    for i, c in enumerate(candidates):

        raw = bytes.fromhex(c["bytes"])[:c["length"]]

        bindings += f"inline constexpr unsigned char bytes{i}[] = {{" + ",".join(f"0x{b:02x}" for b in raw) + "};\n"

    bindings += "inline constexpr Candidate candidates[] = {\n"

    for i, c in enumerate(candidates):

        bindings += f'{{{c["rva"]}u,bytes{i},{c["length"]}u,0x{c["return_mask"]:08X}u,0x{c["expected_return"]:08X}u,{str(c["relocated_imm"]).lower()},{c["stack_pop"]}u,{str(c["float_return"]).lower()}}},\n'

    bindings += "};\n"

    (ROOT / "source/hooks/ARTStubBindings.h").write_text(bindings, encoding="utf-8")

    slots = [r for r in refs if r["origin"] == "VirtualSlot"]

    bindings = "// Generated table references. Included inside namespace artstubs after Slot.\ninline constexpr Slot slots[] = {\n"

    for r in slots:

        bindings += f'{{0x{int(r["vtable_va"],16)-base:08X}u,{int(r["slot"])}u,{r["rva"]}u}},\n'

    bindings += "};\n"

    (ROOT / "source/hooks/ARTSlotBindings.h").write_text(bindings, encoding="utf-8")

    dest = ROOT / "docs/MemoryMap/art_validation.csv"

    fields = list(refs[0])+["validation_status", "simple_stub_candidate"]

    candidate_rvas = {int(c["rva"],16) for c in candidates}

    with dest.open("w", encoding="utf-8", newline="") as out:

        writer = csv.DictWriter(out, fieldnames=fields)

        writer.writeheader()

        for ref in refs:

            writer.writerow(dict(ref, validation_status="historical_runtime_reference_test" if ref["runtime_reference_tested"] == "1" else "pending_static_analysis",

                                 simple_stub_candidate=int(int(ref["rva"],16) in candidate_rvas)))

    disk = {str(p.relative_to(ROOT)).replace(chr(92),"/") for p in (ROOT/"source/external/ART").rglob("*.h")}

    listed = {r["file"] for r in classes}

    coverage = dict(manifest_headers=len(classes), disk_headers=len(disk), missing=sorted(listed-disk), additional=sorted(disk-listed), headers_with_references=len({r["file"] for r in refs}), headers_without_references=sorted(listed-{r["file"] for r in refs}))

    (evidence/"file-coverage.json").write_text(json.dumps(coverage,indent=2)+"\n",encoding="utf-8")

    dirs = Counter("/".join(r["file"].split("/")[3:-1]) or "ART" for r in refs)

    text = f"""# Inventario de validación de ART

Se inventariaron {len(classes):,} headers de `source/external/ART`, con {len(refs):,} referencias y {len(by_rva):,} destinos únicos. Las referencias compartidas no representan funciones independientes. El banco de tablas abarca {len(slots):,} referencias virtuales; las {len(refs)-len(slots):,} referencias del SDK no forman parte de esa comprobación.

[art_validation.csv](art_validation.csv) conserva las direcciones, propietarios y evidencias originales. `historical_runtime_reference_test` únicamente reconoce pruebas históricas ya registradas; `pending_static_analysis` no confirma firma ni llamada. Los campos `enabled` y `reconstructed` conservan su valor original.

El análisis de bytes del ejecutable canónico, SHA256 `{SHA}`, encontró {len(candidates):,} destinos cuyo cuerpo completo coincide con un retorno simple o un retorno de constante. Se incluyen solamente `RET n` de 4, 8, 12, 16 o 20 bytes con argumentos sinteticos explicitos, ademas de `FLD1/RET` con resultado flotante comprobado. [Candidatos](../../reversing/ARTValidation/evidence/simple-candidates.json) contiene bytes de entrada, longitud, máscara del valor de retorno y propietarios. `relocated_imm` identifica únicamente constantes `B8` cuyo inmediato tiene una entrada PE `HIGHLOW` comprobada: el banco puede ajustar ese inmediato y su resultado esperado por la diferencia de base cargada. Se excluyen otras relocaciones dentro del cuerpo. Esta coincidencia estática no valida semántica de clase ni habilita un hook; permite preparar una prueba acotada del cuerpo simple.

Todas las llamadas desconocidas o complejas permanecen deshabilitadas. El manejador fatal RVA `0x00001210` se excluye de llamadas. Los resultados runtime se registran por separado.

| Carpeta | Referencias |

|---|---:|

"""

    text += "".join(f"| {name} | {number:,} |\n" for name, number in sorted(dirs.items()))

    (ROOT / "docs/MemoryMap/ARTValidation.md").write_text(text, encoding="utf-8")

    print(json.dumps({k:v for k,v in result.items() if k != "candidates"} | {"simple_candidates":len(candidates), "historical_runtime_references":sum(r["runtime_reference_tested"]=="1" for r in refs)}))

if __name__ == "__main__":

    main()

