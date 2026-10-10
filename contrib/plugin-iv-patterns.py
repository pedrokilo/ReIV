"""Resuelve contra el EXE canónico los patrones gpattern/gpatternt de plugin_IV.
Salida: docs/MemoryMap/plugin_iv_patterns.csv y PluginIvPatterns.md.
Un patrón que coincide una sola vez es una pista de dirección; no valida nombre ni firma."""
import importlib.util, re, struct, sys
from collections import Counter
from pathlib import Path
root = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('bmm', root/'contrib/build-memory-map.py')
bmm = importlib.util.module_from_spec(spec); spec.loader.exec_module(bmm)
exe = Path(sys.argv[1]) if len(sys.argv) > 1 else root.parent/'Grand Theft Auto IV - copia/GTAIV.exe'
pe = bmm.PE(exe)
src = root/'contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV'
call = re.compile(r'gpattern(t?)\(\s*(?:[^,"]*,\s*)?"([^"]+)"(?:\s*,\s*(\d+))?')
defn = re.compile(r'^[A-Za-z_][^\n=;]*?\b([A-Za-z_]\w*)::(~?\w+)\s*(?:\(|=)')
sections = [s for s in pe.sections if s['executable']]
cache = {}
def scan(pattern):
    if pattern in cache: return cache[pattern]
    toks = pattern.split()
    rx = re.compile(b''.join(b'.' if t in ('?', '??') else re.escape(bytes([int(t, 16)])) for t in toks), re.S)
    hits = []
    for s in sections:
        blob = pe.data[s['raw_offset']:s['raw_offset']+s['raw_size']]
        hits += [s['va']+m.start() for m in rx.finditer(blob)]
        if len(hits) > 8: break
    cache[pattern] = hits; return hits
rows = []
for path in sorted(src.glob('*.cpp')):
    cur = ('', '')
    for n, line in enumerate(path.read_text(encoding='utf-8', errors='replace').splitlines(), 1):
        m = defn.match(line)
        if m: cur = (m.group(1), m.group(2))
        for g in call.finditer(line):
            data, pattern, off = g.group(1) == 't', g.group(2), int(g.group(3) or 0)
            hits = scan(pattern)
            va = hits[0] if len(hits) == 1 else None
            target, kind = va, 'function_start'
            if data:
                kind = 'data_reference'
                if va is not None:
                    raw = pe.offset(va+off, 4)
                    target = struct.unpack_from('<I', pe.data, raw)[0] if raw is not None else None
            rows.append(dict(owner=cur[0], name=cur[1], kind=kind, matches=len(hits) if len(hits) <= 8 else '8+',
                target_va=bmm.hx(target) if target is not None else '', target_rva=bmm.hx(target-pe.base) if target is not None else '',
                section=(pe.section(target) or {}).get('name', '') if target is not None else '',
                pattern=pattern, file=path.relative_to(root).as_posix(), line=n,
                status='plugin_iv_unique_pattern_not_validated' if va is not None else 'plugin_iv_pattern_no_unique_match'))
out = root/'docs/MemoryMap'
bmm.write_csv(out/'plugin_iv_patterns.csv', rows, ['owner','name','kind','matches','target_va','target_rva','section','file','line','status','pattern'])
c = Counter(r['status'] for r in rows); f = [r for r in rows if r['kind']=='function_start']
uniq = [r for r in f if r['target_va']]
md = ['# Patrones de plugin_IV resueltos en el EXE', '',
      f'Generado por `contrib/plugin-iv-patterns.py` contra `GTAIV.exe` canónico (SHA-256 `{bmm.CANONICAL}`).', '',
      'plugin_IV localiza sus funciones y globales con patrones de bytes (`gpattern`). Cada patrón se buscó en las secciones ejecutables. '
      'Solo una coincidencia única da una dirección candidata; el nombre y la firma siguen sin validar.', '',
      f'- Patrones: {len(rows)} ({len(f)} de función, {len(rows)-len(f)} de datos).',
      f'- Sin ninguna coincidencia: {sum(r["matches"]==0 for r in rows)}; con varias: {sum(r["matches"] not in (0,1) for r in rows)}. Muchos patrones de plugin_IV parecen apuntar a otra compilación del juego, por lo que **la ausencia de coincidencia no dice nada sobre la función** en 1.0.7.0.',
      f'- Con coincidencia única: {c["plugin_iv_unique_pattern_not_validated"]}; sin coincidencia única: {c["plugin_iv_pattern_no_unique_match"]}.', '',
      '## Funciones con dirección candidata por clase', '', '| Clase | Candidatas | Total |', '| --- | ---: | ---: |']
for owner in sorted({r['owner'] for r in f}):
    t = [r for r in f if r['owner']==owner]; md.append(f'| {owner or "(libre)"} | {sum(bool(r["target_va"]) for r in t)} | {len(t)} |')
md += ['', 'Detalle completo en [plugin_iv_patterns.csv](plugin_iv_patterns.csv).', '']
(out/'PluginIvPatterns.md').write_text('\n'.join(md), encoding='utf-8')
print(len(rows), dict(c))
