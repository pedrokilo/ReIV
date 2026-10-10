"""Lee los offsets nombrados de IV-SDK.Net para 1.0.7.0 (1070.ini) y los resuelve en el EXE canónico.
Salida: docs/MemoryMap/sdknet_addresses.csv. Son pistas de nombre, no validaciones."""
import importlib.util, re, sys
from pathlib import Path
root = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('bmm', root/'contrib/build-memory-map.py')
bmm = importlib.util.module_from_spec(spec); spec.loader.exec_module(bmm)
exe = Path(sys.argv[1]) if len(sys.argv) > 1 else root.parent/'Grand Theft Auto IV - copia/GTAIV.exe'
pe = bmm.PE(exe)
cfg = root/'contrib/IV SDK.Net/IV-SDK-DotNet-main/IVSDKDotNet/Memory Offset Config Files/IVSDK'
def parse(path):
    section, out = '', []
    for n, line in enumerate(path.read_text(encoding='utf-8-sig', errors='replace').splitlines(), 1):
        line = line.split(';')[0].strip()
        if not line: continue
        if line.startswith('['): section = line.strip('[]'); continue
        if '=' in line: out.append((section, *line.split('=', 1), n))
    return out
v8 = {(s, k): v.strip() for s, k, v, _ in parse(cfg/'1080.ini')}
rows = []
for s, k, v, n in parse(cfg/'1070.ini'):
    v = v.strip(); m = re.fullmatch(r'0[xX][0-9A-Fa-f]+', v)
    row = dict(owner=s, name=k, value=v, file=f'{cfg.relative_to(root).as_posix()}/1070.ini', line=n,
               rva='', va='', section='', executable='', kind='byte_pattern' if not m else '', in_1080=v8.get((s, k), ''))
    if m:
        rva = int(v, 16); va = pe.base+rva; sec = pe.section(va)
        row.update(rva=bmm.hx(rva), va=bmm.hx(va), section=sec['name'] if sec else '', executable=pe.code(va),
                   kind='function_or_code' if pe.code(va) else ('data' if sec else 'unmapped'))
    row['status'] = 'sdknet_1070_reference_not_validated'
    rows.append(row)
bmm.write_csv(root/'docs/MemoryMap/sdknet_addresses.csv', rows,
    ['owner','name','kind','value','rva','va','section','executable','in_1080','file','line','status'])
code = [r for r in rows if r['kind'] == 'function_or_code']
print(len(rows), 'entradas;', len(code), 'código;', sum(r['kind']=='data' for r in rows), 'datos;', sum(r['kind']=='byte_pattern' for r in rows), 'patrones;', sum(r['kind']=='unmapped' for r in rows), 'fuera de imagen')
