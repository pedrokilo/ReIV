"""Register completed scoped runtime tests, never promote unknown ABI or reconstruction."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SHA = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
GROUPS = (
    ("GameValidation", "source/hooks/GameStubsProbe.h", "pure_stub_call"),
    ("AudioValidation", "source/hooks/AudioFixtureProbe.h", "original_call"),
    ("AnimationValidation", "source/hooks/AnimationFixtureProbe.h", "original_call"),
    ("ExtraStubValidation", "source/hooks/ExtraStubsProbe.h", "pure_stub_call"),
)
EXTRA_SCOPE = {
    0x52c4d0:"complete RET 8 body; two explicit synthetic stack arguments discarded",
    0x6aaf20:"complete RET 4 body; one explicit synthetic stack argument discarded",
    0x887a50:"complete FLD1/RET body; floating result 1.0 checked",
    0x47970:"complete XOR AL,AL/RET 12 body; three synthetic arguments discarded; low-byte zero checked",
    0x91800:"complete RET 12 body; three explicit synthetic stack arguments discarded",
    0x150ff0:"complete RET 4 body; one explicit synthetic stack argument discarded",
    0x5c80b0:"complete XOR EAX,EAX/RET 20 body; five synthetic arguments discarded; zero checked",
}
ANIMATION_SCOPE = {
    0x10b6e0: "increment field +4 on isolated storage",
    0x10b6f0: "decrement field +4: nonzero branch only, no release",
    0x19bc50: "read field +8 on isolated storage",
    0x49bbf0: "set or clear flag 0x20 on isolated storage",
    0x4e05a0: "read field +0x38 with flag 0x04000000 on/off",
    0x4b8fe0: "read vector through both synthetic parent branches",
    0x5eb110: "read field +8 and output size 0x80 on isolated storage",
}

def read_csv(path):
    with (ROOT/path).open(encoding="utf-8-sig",newline="") as stream:
        return list(csv.DictReader(stream))

def main():
    refs = [r for r in read_csv("docs/MemoryMap/pending_hooks.csv") if r["file"].startswith("source/game/")]
    owner_rvas = {(r["owner"],int(r["rva"],16)) for r in refs}
    catalog_path = ROOT/"reversing/HookRegistry/catalog.json"
    catalog = json.loads(catalog_path.read_text(encoding="utf-8-sig"))
    existing = {(e["class"],int(e["rva"],16)) for e in catalog}
    tested = {}
    tested_evidence = {}
    reports = {}
    for group, source, kind in GROUPS:
        evidence = f"reversing/{group}/evidence/runtime-summary.json"
        summary = json.loads((ROOT/evidence).read_text(encoding="utf-8-sig"))
        report = json.loads((ROOT/f"reversing/{group}/evidence/runtime-report.json").read_text(encoding="utf-8-sig"))
        assert summary["passed"] and summary["exe_sha256"].lower()==SHA, group
        assert summary["implementation_sha256"].lower()==hashlib.sha256((ROOT/source).read_bytes()).hexdigest(), group
        assert report["phase"]=="passed" and report["exceptions"]==0 and report==summary["result"], group
        reports[group]=report
        metadata = {}
        if group=="GameValidation":
            metadata={int(c["rva"],16):c for c in json.loads((ROOT/"reversing/GameValidation/evidence/simple-candidates.json").read_text())["candidates"]}
        elif group=="AudioValidation":
            metadata={int(c["rva"],16):c for c in json.loads((ROOT/"reversing/AudioValidation/evidence/fixture-scope.json").read_text())}
        for entry in report["entries"]:
            if entry["calls"] not in (64,128) or entry["failures"] or entry.get("disabled",False):
                continue
            rva=int(entry["rva"],16)
            if kind=="pure_stub_call":
                if group=="ExtraStubValidation":
                    assert rva in EXTRA_SCOPE
                    scope=f'{entry["calls"]} calls; {EXTRA_SCOPE[rva]}; no class ABI or gameplay semantics established; inferred descriptive name'
                else:
                    assert rva in metadata
                    scope=f'{entry["calls"]} calls of complete {metadata[rva]["pattern"]} machine-code body; return mask checked; no class ABI or gameplay semantics established; inferred descriptive name'
            else:
                if group=="AudioValidation":
                    assert rva in metadata
                    scope=f'{metadata[rva]["operation"]} at synthetic offset/value {metadata[rva]["value"]}'
                else:
                    assert rva in ANIMATION_SCOPE
                    scope=ANIMATION_SCOPE[rva]
                scope=f'{entry["calls"]} calls; {scope}; isolated storage only; no game-owned objects; no complete class layout established; inferred descriptive name'
            for owner,address in sorted(owner_rvas):
                if address!=rva:
                    continue
                key=(owner,rva)
                tested[key]="runtime_pure_stub" if kind=="pure_stub_call" else "runtime_fixture"
                tested_evidence[key]=evidence+"; "+scope
                if key in existing:
                    continue
                catalog.append(dict(**{"class":owner},fn_name=f'{"ReturnStub" if kind=="pure_stub_call" else "Fixture"}_RVA_{rva:08X}',
                    rva=f"0x{rva:08X}",reversed=0,locked=0,validated=1,type="S" if kind=="pure_stub_call" else "M",
                    entry_kind=kind,address_checked=1,runtime_checked=1,reconstruction_validated=0,standalone=0,
                    source=source,evidence=evidence,scope=scope))
                existing.add(key)
    slots = read_csv("reversing/GameValidation/evidence/runtime-slots.csv")
    slot_results = {(int(r["vtable_rva"],16),int(r["slot"]),int(r["target_rva"],16)):int(r["result"]) for r in slots}
    game_report=reports["GameValidation"]
    assert len(slots)==game_report["slots_checked"]==sum(r["origin"]=="VirtualSlot" for r in refs)
    assert sum(int(r["result"])!=0 for r in slots)==game_report["slots_failed"]
    fields=list(refs[0])+["validation_status","simple_stub_candidate","runtime_slot_result"]
    candidate_rvas={int(c["rva"],16) for c in json.loads((ROOT/"reversing/GameValidation/evidence/simple-candidates.json").read_text())["candidates"]}
    rows=[]
    rejected=[]
    overrides=[]
    for ref in refs:
        rva=int(ref["rva"],16)
        state=tested.get((ref["owner"],rva),"historical_runtime_reference_test" if ref["runtime_reference_tested"]=="1" else "pending_static_analysis")
        slot_result=""
        if ref["origin"]=="VirtualSlot":
            slot_result=slot_results[(int(ref["vtable_va"],16)-0x400000,int(ref["slot"]),rva)]
        if slot_result != "" and slot_result != 0:
            state="excluded_runtime_slot_mismatch"
            rejected.append(dict(ref,runtime_slot_result=slot_result,reason="runtime target differs from expected or memory protection check failed; excluded as a callable reference"))
        if state in ("runtime_pure_stub","runtime_fixture"):
            overrides.append(dict(owner=ref["owner"],rva=ref["rva"],vtable_va=ref["vtable_va"],slot=ref["slot"],origin=ref["origin"],runtime_reference_tested=1,enabled=0,reconstructed=0,validation_status=state,
                                  evidence=tested_evidence[(ref["owner"],rva)]))
        elif state=="excluded_runtime_slot_mismatch":
            overrides.append(dict(owner=ref["owner"],rva=ref["rva"],vtable_va=ref["vtable_va"],slot=ref["slot"],origin=ref["origin"],runtime_reference_tested=0,enabled=0,reconstructed=0,validation_status=state,
                                  evidence="reversing/GameValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary"))
        rows.append(dict(ref,validation_status=state,simple_stub_candidate=int(rva in candidate_rvas),runtime_slot_result=slot_result))
    with (ROOT/"docs/MemoryMap/game_validation.csv").open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=fields);writer.writeheader();writer.writerows(rows)
    with (ROOT/"reversing/GameValidation/evidence/rejected-slots.csv").open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=list(refs[0])+["runtime_slot_result","reason"]);writer.writeheader();writer.writerows(rejected)
    (ROOT/"reversing/GameValidation/evidence/reference-results.json").write_text(json.dumps(overrides,indent=2)+"\n",encoding="utf-8")
    catalog_path.write_text(json.dumps(catalog,indent=2)+"\n",encoding="utf-8")
    path=ROOT/"docs/MemoryMap/GameValidation.md"
    text=path.read_text(encoding="utf-8").split("\n## Prueba runtime registrada")[0]
    text+="\n## Prueba runtime registrada\n\n"
    text+=f'La auditoría comparó {len(slots):,} referencias virtuales con sus destinos esperados y permisos ejecutables: {game_report["slots_failed"]} fallos. Comprueba direcciones; no llama esas funciones ni establece sus firmas. Las 48 referencias del SDK no forman parte de esta auditoría.\n\n'
    for group,_,kind in GROUPS:
        report=reports[group]
        text+=f'- [{group}: resumen](../../reversing/{group}/evidence/runtime-summary.json): {len(report["entries"]):,} destinos, {sum(e["calls"] for e in report["entries"]):,} llamadas, {sum(e["failures"] for e in report["entries"])} fallos y {report["exceptions"]} excepciones; alcance {"cuerpos completos de retorno simple" if kind=="pure_stub_call" else "operaciones comprobadas en almacenamiento sintético"}.\n'
    text+='\nEl CSV diferencia `runtime_pure_stub` y `runtime_fixture`. `runtime_slot_result=0` acredita únicamente la auditoría de esa referencia virtual. Todos los registros continúan deshabilitados y sin reconstruir. El catálogo usa nombres descriptivos inferidos por RVA; ninguna clase se declara completa.\n'
    from collections import Counter
    states=Counter(row["validation_status"] for row in rows)
    text+='\n| Estado de referencia | Cantidad |\n|---|---:|\n'+''.join(f'| `{name}` | {number:,} |\n' for name,number in sorted(states.items()))
    text+='\nLa cobertura [file-coverage.json](../../reversing/GameValidation/evidence/file-coverage.json) contrasta el manifiesto con el disco: 1.223 headers, ninguno faltante o sin listar; 1.206 tienen referencias y 17 no disponen de destinos en el CSV. Incluye los 28 headers de audio y los 14 de animation.\n'
    text+=f'\nLas {len(rejected)} referencias que no coincidieron quedaron como `excluded_runtime_slot_mismatch`, detalladas en [rejected-slots.csv](../../reversing/GameValidation/evidence/rejected-slots.csv). El escáner puede haber atravesado el límite de una tabla virtual; estas entradas se excluyen como referencias invocables.\n'
    path.write_text(text,encoding="utf-8")
    print(json.dumps(dict(catalog_entries=len(catalog),new_tested_owner_rvas=len(tested),runtime_slots=len(slots))))

if __name__=="__main__":
    main()
