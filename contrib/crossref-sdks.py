"""Cruza offsets de IV-SDK, plugin_IV (Plugin SDK) e IV-SDK-DotNet con PlayerPedLayout.h.
Salida: docs/MemoryMap/SdkCrossReference.md. Una coincidencia entre SDKs es una pista, no una prueba."""
import re, pathlib
root = pathlib.Path(__file__).resolve().parents[1]
SRC = {
    'IV-SDK': root / 'contrib/IV SDK/IV-SDK-main/include',
    'plugin_IV': root / 'contrib/Plugin SDK (es el mismo que se usa para GTA SA)/plugin-sdk-master/plugin_IV/game_IV',
    'IV-SDK.Net': root / 'contrib/IV SDK.Net/IV-SDK-DotNet-main/IVSDKDotNet/IVSDK',
}
CLASSES = ['CEntity', 'CDynamicEntity', 'CPhysical', 'CPed']
rx = re.compile(r'^\s*VALIDATE_OFFSET\(\s*(\w+)\s*,\s*(\w+)\s*,\s*0x([0-9A-Fa-f]+)\s*\)', re.M)
data = {}  # (class, offset) -> {sdk: name}
for sdk, d in SRC.items():
    for c in CLASSES:
        f = d / f'{c}.h'
        if not f.exists(): continue
        for cls, name, off in rx.findall(f.read_text(encoding='utf-8', errors='replace')):
            if cls == c: data.setdefault((c, int(off, 16)), {})[sdk] = name
layout = (root / 'source/game/Peds/PlayerPedLayout.h').read_text(encoding='utf-8')
ours = {int(o, 16): n for n, o in re.findall(r'(\w+);\s*//\s*\+0x([0-9A-Fa-f]+)', layout)}

out = ['# Cruce de SDKs: IV-SDK, plugin_IV e IV-SDK.Net', '',
       'Generado por `contrib/crossref-sdks.py`. Compara los `VALIDATE_OFFSET` de CEntity, CDynamicEntity, CPhysical y CPed. '
       'Una coincidencia entre SDKs es una pista; **el ejecutable decide**. `PlayerPedLayout.h` aporta los offsets observados en cuerpos del EXE.', '']
cnt = {s: sum(1 for v in data.values() if s in v) for s in SRC}
out += ['## Cobertura', '', '| SDK | Offsets nombrados (4 clases) |', '| --- | ---: |'] + [f'| {s} | {n} |' for s, n in cnt.items()] + ['']
conf = [(k, v) for k, v in sorted(data.items()) if len(set(v.values())) > 1]
only_plugin = [(k, v) for k, v in sorted(data.items()) if set(v) == {'plugin_IV'}]
out += ['## Offsets que solo nombra plugin_IV', '', 'Candidatos para nombrar campos aún sin etiqueta. Si el offset aparece en el layout observado se marca.', '',
        '| Clase | Offset | Nombre plugin_IV | En layout observado |', '| --- | ---: | --- | --- |']
for (c, o), v in only_plugin:
    out.append(f'| {c} | 0x{o:X} | `{v["plugin_IV"]}` | {("`"+ours[o]+"`") if o in ours else ""} |')
out += ['', '## Offsets nombrados distinto entre SDKs', '', '| Clase | Offset | ' + ' | '.join(SRC) + ' |', '| --- | ---: | ' + ' | '.join('---' for _ in SRC) + ' |']
for (c, o), v in conf:
    out.append(f'| {c} | 0x{o:X} | ' + ' | '.join(f'`{v[s]}`' if s in v else '' for s in SRC) + ' |')
hit = sorted({o for (c, o) in data if o in ours})
out += ['', '## Layout observado de CPlayerPed con nombre en algún SDK', '', f'{len(hit)} offsets de `PlayerPedLayout.h` tienen nombre en al menos un SDK.', '',
        '| Offset | Layout observado | ' + ' | '.join(SRC) + ' |', '| ---: | --- | ' + ' | '.join('---' for _ in SRC) + ' |']
for o in hit:
    names = {}
    for (c, oo), v in data.items():
        if oo == o:
            for s, n in v.items(): names.setdefault(s, f'{c}::{n}')
    out.append(f'| 0x{o:X} | `{ours[o]}` | ' + ' | '.join(f'`{names[s]}`' if s in names else '' for s in SRC) + ' |')
out += ['', '## Notas', '', '- plugin_IV `CPlayerPed.h` está vacío: solo hereda de CPed y valida tamaño `0xF00`. IV-SDK e IV-SDK.Net no declaran CPlayerPed.',
        '- IV-SDK.Net replica en gran parte los headers de IV-SDK; su aporte es independiente solo donde difiere.', '']
(root / 'docs/MemoryMap/SdkCrossReference.md').write_text('\n'.join(out), encoding='utf-8')
print(cnt, len(only_plugin), 'solo plugin_IV;', len(conf), 'conflictos;', len(hit), 'en layout')
