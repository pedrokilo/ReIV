"""Register only source-matching isolated reconstruction evidence.

This does not certify native replacements or complete class reconstruction.
"""
import hashlib
import json
import sys
import os
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CANONICAL = 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'

def read(path):
    return json.loads((ROOT / path).read_text(encoding='utf-8-sig'))

def main():
    groups = [
        ('PlayerPedDestruction.h', 'reversing/CPlayerPed/evidence/destruction-validation.json', [('Destroy', '005C1E60'), ('DestroyDeleting', '005C2260')]),
        ('PlayerPedControl.h', 'reversing/CPlayerPed/evidence/control-validation.json', [('ApplyModel', '005C0AA0'), ('CreateControl', '005C1E10')]),
        ('PlayerPedCounter.h', 'reversing/CPlayerPed/evidence/counter-validation-summary.json', [('UpdateCounter', '005BE610'), ('UpdateSlot73', '005BE770')]),
        ('PlayerPedProtectedValue.h', 'reversing/PlayerPedProtectedValue/native-summary.json', [('SetProtectedAndFlags', '005C1CF0'), ('SetProtectedAndFlagsWithUnused', '005C1D20'), ('AddProtectedAndFlags', '005C1D50'), ('GetPlayerProtected', '005C1CE0')]),
        ('PlayerPedConstruction.h', 'reversing/CPlayerPed/evidence/constructor-validation-summary.json', [('Construct', '005C1910')]),
        ('PlayerPedUpdate.h', 'reversing/CPlayerPed/evidence/update-validation.json', [('UpdateIsolated', '005C0B00')]),
        ('PlayerPedModelReset.h', 'reversing/CPlayerPed/evidence/model-reset-validation.json', [('ResetModelState', '005BF660')]),
        ('PlayerPedNonvirtual.h', 'reversing/CPlayerPed/evidence/nonvirtual-validation-summary.json', [('ResolveIfPlayerFlags', '005BE5D0'), ('CallBlockIfPlayerFlags', '005BEE70'), ('InitializeRelations', '005BE4C0')]),
        ('PlayerPedStateHelpers.h', 'reversing/PlayerPedStateHelpers/native-summary.json', [('ClearState3D8', '005BF070'), ('StoreQuery7', '005BF2D0'), ('StoreQuery8AndClearFlag', '005BF310')]),
        ('PlayerPedReferenceClear.h', 'reversing/CPlayerPed/evidence/reference-clear-validation.json', [('ClearReferenceE74', '005BEED0')]),
        ('PlayerPedValueAdjustment.h', 'reversing/CPlayerPed/evidence/value-adjustment-validation.json', [('AdjustValueIsolated', '005BFD80')]),
        ('PlayerPedInputSelection.h', 'reversing/CPlayerPed/evidence/input-selection-validation.json', [('SelectInputIsolated', '005BE7D0')]),
        ('PlayerPedReceiverHelpers.h', 'reversing/CPlayerPed/evidence/receiver-helpers-validation.json', [('TestEitherPredicate', '005BE5F0'), ('DispatchPairFirstRaw', '005BEEF0'), ('DispatchPairSecondRaw', '005BEF20'), ('DispatchRelatedRaw', '005BEF70'), ('TestActionAllowed', '005BE790')]),
        ('PlayerPedRelatedFlags.h', 'reversing/CPlayerPed/evidence/related-flags-validation.json', [('UpdateRelatedFlagsRaw', '005BF250')]),
        ('PlayerPedActionRange.h', 'reversing/CPlayerPed/evidence/actions-validation.json', [('ActInRangeIsolated', '005C1F90')]),
        ('PlayerPedActionRequest.h', 'reversing/CPlayerPed/evidence/actions-validation.json', [('RequestActionIsolated', '005C2180')]),
    ]
    catalog_path = 'reversing/HookRegistry/catalog.json'
    catalog = read(catalog_path)
    if '--runtime' in sys.argv:
        evidence_path = 'reversing/CPlayerPed/evidence/runtime-summary.json'
        evidence = read(evidence_path)
        assert evidence['passed'] and evidence['exe_sha256'] == CANONICAL
        assert evidence['result']['comparisons'] == 768 and not evidence['result']['failures'] and not evidence['result']['exceptions']
        source = 'source/game/Peds/CPlayerPed.h'
        assert hashlib.sha256((ROOT / source).read_bytes()).hexdigest() == evidence['implementation_sha256']
        for path, digest in evidence['additional_source_sha256'].items():
            assert hashlib.sha256((ROOT / path).read_bytes()).hexdigest() == digest, path
        methods = [('GetFieldEBC','005C1C90'),('GetBlockEC0','005C1CA0'),('GetBlockED0','005C1CB0'),('SetFieldEBC','005C1CC0'),('SetFieldEF0','005C1CD0'),('CopyBlockEC0','005C1D90'),('CopyBlockED0','005C1DD0'),('ReturnZeroSlot48','003BDC00'),('ReturnOneSlot74','008FAEE0'),('AdvanceFieldEE0','005BF5F0')]
        methods += [('TestFieldEE4','005BF5D0'),('ResetFieldEEC','005BF640')]
        for name, rva in methods:
            catalog = [row for row in catalog if not (row['class'] == 'CPlayerPed' and row['rva'].lower() == ('0x'+rva).lower())]
            catalog.append({'class':'CPlayerPed','fn_name':name,'rva':'0x'+rva,'reversed':1,'locked':0,'validated':1,'type':'S','entry_kind':'runtime_reconstruction_comparison','address_checked':1,'runtime_checked':1,'reconstruction_validated':1,'standalone':0,'source':source,'evidence':evidence_path,'scope':evidence['scope']})
    for filename, evidence_path, methods in groups:
        evidence = read(evidence_path)
        if evidence_path == 'reversing/CPlayerPed/evidence/actions-validation.json':
            assert evidence['original_full_body'] and evidence['comparisons'] == 42320
            assert evidence['per_method_comparisons'] == 21160 and evidence['failures'] == 0
            assert evidence['fault_comparisons'] == 7460 and evidence['fault_address'] == '0x415'
            assert not evidence['runtime_checked'] and evidence['scope']['isolated_only']
            assert all(any(int(entry['va'], 16) == int(rva, 16) + 0x400000 for entry in evidence['methods']) for _, rva in methods)
        else:
            assert evidence['passed'] and evidence['failures'] == 0
        source = 'source/game/Peds/' + filename
        expected = evidence.get('implementation_sha256')
        if expected is None:
            expected = evidence.get('hashes', evidence.get('source_sha256', {}))[source]
        assert hashlib.sha256((ROOT / source).read_bytes()).hexdigest() == expected, source
        exe_hash = evidence.get('exe_sha256')
        if exe_hash is None:
            fixture_path = evidence.get('fixture', evidence.get('fixtures'))
            exe_hash = read(fixture_path)['exe_sha256']
        assert exe_hash == CANONICAL
        # Evidence is immutable input: source matching must not rewrite prior results.
        for name, rva in methods:
            catalog = [row for row in catalog if not (row['class'] == 'CPlayerPed' and row['rva'].lower() == ('0x'+rva).lower())]
            catalog.append(dict(
                class_='CPlayerPed', fn_name=name, rva='0x'+rva, reversed=1,
                locked=0, validated=1, type='S', entry_kind='isolated_reconstruction_comparison',
                address_checked=1, runtime_checked=0, reconstruction_validated=1,
                standalone=1, source=source, evidence=evidence_path,
                scope='Complete own caller body compared with canonical instructions; external dependencies patched to deterministic fixtures. Not a native replacement or complete class/gameplay validation.'
            ))
            catalog[-1]['class'] = catalog[-1].pop('class_')
    if '--native' in sys.argv:
        evidence_path = 'reversing/CPlayerPed/evidence/native-runtime-summary.json'
        evidence = read(evidence_path)
        result = evidence['result']
        assert evidence['passed'] and evidence['exe_sha256'] == CANONICAL
        assert result['passed'] and result['original_calls'] >= 32 and result['clone_calls'] >= 64
        assert result['restored'] and not result['exceptions']
        source = 'source/game/Peds/PlayerPedUpdate.h'
        for path, digest in evidence['additional_source_sha256'].items():
            assert hashlib.sha256((ROOT / path).read_bytes()).hexdigest() == digest, path
        assert evidence['implementation_sha256'] == evidence['additional_source_sha256'][source]
        row = next(row for row in catalog if row['class'] == 'CPlayerPed' and int(row['rva'], 16) == 0x5C0B00)
        row.update(entry_kind='runtime_replacement_smoke', runtime_checked=1, standalone=0,
                   source=source, evidence=evidence_path, scope=evidence['scope'])
    target = ROOT / catalog_path
    with tempfile.NamedTemporaryFile(mode='w', encoding='utf-8', dir=target.parent, suffix='.tmp', delete=False) as stream:
        json.dump(catalog, stream, indent=2)
        stream.write('\n')
        temporary = stream.name
    os.replace(temporary, target)
    print('Registered source-matching isolated bodies; live validation remains separately recorded.')

if __name__ == '__main__':
    main()
