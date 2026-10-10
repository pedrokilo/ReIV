"""Revalida los bancos aislados tras unir los cuerpos de los modulos PlayerPed* en CPlayerPed.h / CPlayerPed.cpp.

Ejecuta los checks ya compilados (build/checks/*.exe, enlazados con CPlayerPed.cpp), exige que cada uno pase con
exactamente el recuento de comparaciones de su evidencia original y escribe
reversing/CPlayerPed/evidence/cpp-split-revalidation.json con los hashes actuales de CPlayerPed.h y CPlayerPed.cpp,
indexados por la ruta de la evidencia original.
No reescribe la evidencia original; HookRegistry/generate.py y register_results.py usan este archivo solo si los
hashes actuales coinciden.
"""
import hashlib
import json
import re
import subprocess
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CANONICAL = 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
SOURCES = ['source/game/Peds/CPlayerPed.h', 'source/game/Peds/CPlayerPed.cpp']
CP = 'reversing/CPlayerPed/'
# evidencia original -> (recuento esperado, [(check fuente, exe)])
ITEMS = {
    CP + 'evidence/destruction-validation.json': (256, [(CP + 'check-destructor.cpp', 'check-destructor-CPlayerPed')]),
    CP + 'evidence/control-validation.json': (512, [(CP + 'check-control.cpp', 'check-control-CPlayerPed')]),
    CP + 'evidence/counter-validation-summary.json': (258048, [(CP + 'counter-check.cpp', 'counter-check-CPlayerPed')]),
    'reversing/PlayerPedProtectedValue/native-summary.json': (325248, [('reversing/PlayerPedProtectedValue/check.cpp', 'check-PlayerPedProtectedValue')]),
    CP + 'evidence/constructor-validation-summary.json': (49152, [(CP + 'constructor-check.cpp', 'constructor-check-CPlayerPed')]),
    CP + 'evidence/model-reset-validation.json': (10752, [(CP + 'check-model-reset.cpp', 'check-model-reset-CPlayerPed')]),
    CP + 'evidence/nonvirtual-validation-summary.json': (16384 + 41472, [(CP + 'nonvirtual-check.cpp', 'nonvirtual-check-CPlayerPed'), (CP + 'initialization-check.cpp', 'initialization-check-CPlayerPed')]),
    'reversing/PlayerPedStateHelpers/native-summary.json': (73728, [('reversing/PlayerPedStateHelpers/check.cpp', 'check-PlayerPedStateHelpers')]),
    CP + 'evidence/reference-clear-validation.json': (512, [(CP + 'check-reference-clear.cpp', 'check-reference-clear-CPlayerPed')]),
    CP + 'evidence/receiver-helpers-validation.json': (38400, [(CP + 'check-receiver-helpers.cpp', 'check-receiver-helpers-CPlayerPed')]),
    CP + 'evidence/related-flags-validation.json': (4096, [(CP + 'check-related-flags.cpp', 'check-related-flags-CPlayerPed')]),
    CP + 'evidence/actions-validation.json': (42320, [(CP + 'check-actions.cpp', 'check-actions-CPlayerPed')]),
    CP + 'evidence/action-selection-validation.json': (168960, [(CP + 'check-action-selection.cpp', 'check-action-selection-CPlayerPed')]),
    CP + 'evidence/accumulation-validation-summary.json': (204800, [(CP + 'accumulation-check.cpp', 'accumulation-check-CPlayerPed')]),
    CP + 'evidence/extra-fields-validation-summary.json': (409600, [(CP + 'extra-fields-check.cpp', 'extra-fields-check-CPlayerPed')]),
    CP + 'evidence/update-validation.json': (139920, [(CP + 'check-update.cpp', 'check-upd-CPlayerPed')]),
    CP + 'evidence/value-adjustment-validation.json': (2457600, [(CP + 'check-value-adjust.cpp', 'check-value-adjust-CPlayerPed')]),
    CP + 'evidence/input-selection-validation.json': (74448, [(CP + 'check-input-select.cpp', 'check-input-select-CPlayerPed')]),
    'reversing/PlayerPedFloatCopy/native-summary.json': (62976, [('reversing/PlayerPedFloatCopy/check.cpp', 'check-PlayerPedFloatCopy')]),
}


def sha(path):
    return hashlib.sha256((ROOT / path).read_bytes()).hexdigest()


def comparisons(output):
    found = [int(n) for n in re.findall(r'"comparisons":\s*(\d+)', output)]
    found += [int(n) for n in re.findall(r'comparisons=(\d+)', output)]
    found += [int(n) for n in re.findall(r'passed (\d+) ', output)]
    return found[-1] if found else None


def main():
    items = {}
    for evidence_path, (expected, checks) in ITEMS.items():
        if not (ROOT / evidence_path).exists():
            continue
        total, runs = 0, []
        for source, exe in checks:
            path = ROOT / 'build/checks' / (exe + '.exe')
            result = subprocess.run([str(path)], capture_output=True, text=True, errors='replace', cwd=ROOT)
            count = comparisons(result.stdout)
            if result.returncode != 0 or count is None or re.search(r'(?i)fail(ed)?[ =:]+[1-9]', result.stdout):
                raise SystemExit('FALLO: ' + evidence_path + ' ' + exe + ' rc=' + str(result.returncode) + '\n' + result.stdout[-400:])
            total += count
            runs.append(dict(check=source, check_sha256=sha(source), exe=path.name,
                             exe_sha256=sha(path.relative_to(ROOT).as_posix()), comparisons=count))
        if total != expected:
            raise SystemExit('Recuento distinto en ' + evidence_path + ': ' + str(total) + ' != ' + str(expected))
        items[evidence_path] = dict(comparisons=total, runs=runs, sources={s: sha(s) for s in SOURCES})
    out = dict(schema=2, passed=True, exe_sha256=CANONICAL,
               generated=datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ'),
               scope='Isolated Win32 banks rerun after merging the PlayerPed* modules into CPlayerPed.h/.cpp; same comparison counts as the original evidence. Not an in-game validation.',
               items=items)
    target = ROOT / 'reversing/CPlayerPed/evidence/cpp-split-revalidation.json'
    target.write_text(json.dumps(out, indent=2) + '\n', encoding='utf-8')
    print('Revalidated', len(items), 'evidence files;', sum(i['comparisons'] for i in items.values()), 'comparisons')


if __name__ == '__main__':
    main()
