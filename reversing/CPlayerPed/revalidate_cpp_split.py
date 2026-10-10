"""Revalida los bancos aislados tras mover los cuerpos de PlayerPed*.h a PlayerPed*.cpp.

Ejecuta los checks ya compilados (build/checks/*.exe, enlazados con los .cpp), exige que cada uno pase con
exactamente el recuento de comparaciones de su evidencia original y escribe
reversing/CPlayerPed/evidence/cpp-split-revalidation.json con los hashes actuales de .h y .cpp.
No reescribe la evidencia original; HookRegistry/generate.py usa este archivo solo si coincide con las fuentes.
"""
import hashlib
import json
import re
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CANONICAL = 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
PEDS = 'source/game/Peds/'
# header -> (evidencia original, recuento esperado, [(check fuente, exe)], cpp)
ITEMS = {
    'PlayerPedDestruction.h': ('reversing/CPlayerPed/evidence/destruction-validation.json', 256, [('reversing/CPlayerPed/check-destructor.cpp', 'check-destructor-CPlayerPed')]),
    'PlayerPedControl.h': ('reversing/CPlayerPed/evidence/control-validation.json', 512, [('reversing/CPlayerPed/check-control.cpp', 'check-control-CPlayerPed')]),
    'PlayerPedCounter.h': ('reversing/CPlayerPed/evidence/counter-validation-summary.json', 258048, [('reversing/CPlayerPed/counter-check.cpp', 'counter-check-CPlayerPed')]),
    'PlayerPedProtectedValue.h': ('reversing/PlayerPedProtectedValue/native-summary.json', 325248, [('reversing/PlayerPedProtectedValue/check.cpp', 'check-PlayerPedProtectedValue')]),
    'PlayerPedConstruction.h': ('reversing/CPlayerPed/evidence/constructor-validation-summary.json', 49152, [('reversing/CPlayerPed/constructor-check.cpp', 'constructor-check-CPlayerPed')]),
    'PlayerPedModelReset.h': ('reversing/CPlayerPed/evidence/model-reset-validation.json', 10752, [('reversing/CPlayerPed/check-model-reset.cpp', 'check-model-reset-CPlayerPed')]),
    'PlayerPedNonvirtual.h': ('reversing/CPlayerPed/evidence/nonvirtual-validation-summary.json', 16384 + 41472, [('reversing/CPlayerPed/nonvirtual-check.cpp', 'nonvirtual-check-CPlayerPed'), ('reversing/CPlayerPed/initialization-check.cpp', 'initialization-check-CPlayerPed')]),
    'PlayerPedStateHelpers.h': ('reversing/PlayerPedStateHelpers/native-summary.json', 73728, [('reversing/PlayerPedStateHelpers/check.cpp', 'check-PlayerPedStateHelpers')]),
    'PlayerPedReferenceClear.h': ('reversing/CPlayerPed/evidence/reference-clear-validation.json', 512, [('reversing/CPlayerPed/check-reference-clear.cpp', 'check-reference-clear-CPlayerPed')]),
    'PlayerPedReceiverHelpers.h': ('reversing/CPlayerPed/evidence/receiver-helpers-validation.json', 38400, [('reversing/CPlayerPed/check-receiver-helpers.cpp', 'check-receiver-helpers-CPlayerPed')]),
    'PlayerPedRelatedFlags.h': ('reversing/CPlayerPed/evidence/related-flags-validation.json', 4096, [('reversing/CPlayerPed/check-related-flags.cpp', 'check-related-flags-CPlayerPed')]),
    'PlayerPedActionRange.h': ('reversing/CPlayerPed/evidence/actions-validation.json', 42320, [('reversing/CPlayerPed/check-actions.cpp', 'check-actions-CPlayerPed')]),
    'PlayerPedActionRequest.h': ('reversing/CPlayerPed/evidence/actions-validation.json', 42320, [('reversing/CPlayerPed/check-actions.cpp', 'check-actions-CPlayerPed')]),
    'PlayerPedActionSelection.h': ('reversing/CPlayerPed/evidence/action-selection-validation.json', 168960, [('reversing/CPlayerPed/check-action-selection.cpp', 'check-action-selection-CPlayerPed')]),
    'PlayerPedAccumulation.h': ('reversing/CPlayerPed/evidence/accumulation-validation-summary.json', 204800, [('reversing/CPlayerPed/accumulation-check.cpp', 'accumulation-check-CPlayerPed')]),
    'PlayerPedExtraFields.h': ('reversing/CPlayerPed/evidence/extra-fields-validation-summary.json', 409600, [('reversing/CPlayerPed/extra-fields-check.cpp', 'extra-fields-check-CPlayerPed')]),
    'PlayerPedFloatCopy.h': ('reversing/CPlayerPed/evidence/runtime-summary.json', 62976, [('reversing/PlayerPedFloatCopy/check.cpp', 'check-PlayerPedFloatCopy')]),
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
    for header, (evidence_path, expected, checks) in ITEMS.items():
        cpp = PEDS + header[:-2] + '.cpp'
        assert (ROOT / cpp).exists(), cpp
        total, runs = 0, []
        for source, exe in checks:
            path = ROOT / 'build/checks' / (exe + '.exe')
            result = subprocess.run([str(path)], capture_output=True, text=True, errors='replace', cwd=ROOT)
            count = comparisons(result.stdout)
            if result.returncode != 0 or count is None or re.search(r'(?i)fail(ed)?[ =:]+[1-9]', result.stdout):
                raise SystemExit('FALLO: ' + header + ' ' + exe + ' rc=' + str(result.returncode) + '\n' + result.stdout[-400:])
            total += count
            runs.append(dict(check=source, check_sha256=sha(source), exe=path.name, exe_sha256=sha(path.relative_to(ROOT).as_posix()),
                             comparisons=count))
        # actions-validation cuenta Range+Request una sola vez
        if total != expected:
            raise SystemExit('Recuento distinto en ' + header + ': ' + str(total) + ' != ' + str(expected))
        items[header] = dict(evidence=evidence_path, comparisons=total, runs=runs,
                             sources={PEDS + header: sha(PEDS + header), cpp: sha(cpp)})
    out = dict(schema=1, passed=True, exe_sha256=CANONICAL, generated=datetime.now(timezone.utc).strftime('%Y-%m-%dT%H:%M:%SZ'),
               scope='Isolated Win32 banks rerun after moving bodies from PlayerPed*.h to PlayerPed*.cpp; same comparison counts as the original evidence. Not an in-game validation.',
               items=items)
    target = ROOT / 'reversing/CPlayerPed/evidence/cpp-split-revalidation.json'
    target.write_text(json.dumps(out, indent=2) + '\n', encoding='utf-8')
    print('Revalidated', len(items), 'headers;', sum(i['comparisons'] for i in items.values()), 'comparisons')


if __name__ == '__main__':
    main()
