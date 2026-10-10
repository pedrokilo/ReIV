"""Register completed scoped runtime tests, never promote unknown ABI or reconstruction."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SHA = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
GROUPS = (
    ("ARTValidation", "source/hooks/ARTStubsProbe.h", "pure_stub_call"),
    ("ARTFixtureValidation", "source/hooks/ARTFixtureProbe.h", "original_call"),
    ("ARTExtraValidation", "source/hooks/ARTExtraProbe.h", "original_call"),
)


def read_csv(path):
    with (ROOT/path).open(encoding="utf-8-sig",newline="") as stream:
        return list(csv.DictReader(stream))

def main():
    refs = [r for r in read_csv("docs/MemoryMap/pending_hooks.csv") if r["file"].startswith("source/external/ART/")]
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
        if group=="ARTValidation":
            assert summary["stub_bindings_sha256"]==hashlib.sha256((ROOT/"source/hooks/ARTStubBindings.h").read_bytes()).hexdigest()
            assert summary["slot_bindings_sha256"]==hashlib.sha256((ROOT/"source/hooks/ARTSlotBindings.h").read_bytes()).hexdigest()
            metadata={int(c["rva"],16):c for c in json.loads((ROOT/"reversing/ARTValidation/evidence/simple-candidates.json").read_text())["candidates"]}
        elif group in ("ARTFixtureValidation","ARTExtraValidation"):
            metadata={int(c["rva"],16):c for c in json.loads((ROOT/f"reversing/{group}/evidence/fixture-scope.json").read_text(encoding="utf-8"))}
        assert {int(e["rva"],16) for e in report["entries"]} == set(metadata), group
        assert len(report["entries"]) == len(metadata), group
        assert all(e["calls"] == 64 and e["failures"] == 0 and not e.get("disabled",False) for e in report["entries"]), group
        for entry in report["entries"]:
            if entry["calls"] not in (64,128) or entry["failures"] or entry.get("disabled",False):
                continue
            rva=int(entry["rva"],16)
            if kind=="pure_stub_call":
                assert rva in metadata
                scope=f'{entry["calls"]} calls of complete {metadata[rva]["pattern"]} machine-code body; return mask checked; synthetic stack arguments when RET n; no class ABI or gameplay semantics established; inferred descriptive name'
            else:
                if group in ("ARTFixtureValidation","ARTExtraValidation"):
                    assert rva in metadata
                    scope=f'{metadata[rva]["operation"]} at synthetic field offset/value {metadata[rva]["value"]}'
                scope=f'{entry["calls"]} calls; {scope}; isolated stoART only; no game-owned objects; no complete class layout established; inferred descriptive name'
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
    slots = read_csv("reversing/ARTValidation/evidence/runtime-slots.csv")
    slot_results = {(int(r["vtable_rva"],16),int(r["slot"]),int(r["target_rva"],16)):int(r["result"]) for r in slots}
    game_report=reports["ARTValidation"]
    assert len(slots)==game_report["slots_checked"]==sum(r["origin"]=="VirtualSlot" for r in refs)
    assert sum(int(r["result"])!=0 for r in slots)==game_report["slots_failed"]
    fields=list(refs[0])+["validation_status","simple_stub_candidate","runtime_slot_result"]
    candidate_rvas={int(c["rva"],16) for c in json.loads((ROOT/"reversing/ARTValidation/evidence/simple-candidates.json").read_text())["candidates"]}
    rows=[]
    rejected=[]
    overrides=[]
    fatal=[]
    fatal_evidence="reversing/NMutils/evidence/00401210.txt; complete fatal handler excluded; no runtime call attempted"
    for ref in refs:
        rva=int(ref["rva"],16)
        state=tested.get((ref["owner"],rva),"historical_runtime_reference_test" if ref["runtime_reference_tested"]=="1" else "pending_static_analysis")
        slot_result=""
        if ref["origin"]=="VirtualSlot":
            slot_result=slot_results[(int(ref["vtable_va"],16)-0x400000,int(ref["slot"]),rva)]
        if slot_result != "" and slot_result != 0:
            state="excluded_runtime_slot_mismatch"
            rejected.append(dict(ref,runtime_slot_result=slot_result,reason="runtime target differs from expected or memory protection check failed; excluded as a callable reference"))
        if rva==0x1210:
            state="excluded_fatal_handler"
            fatal.append(dict(ref,validation_status=state,runtime_slot_result=slot_result))
        if state=="excluded_fatal_handler":
            overrides.append(dict(owner=ref["owner"],rva=ref["rva"],vtable_va=ref["vtable_va"],slot=ref["slot"],origin=ref["origin"],runtime_reference_tested=0,enabled=0,reconstructed=0,validation_status=state,excluded=True,evidence=fatal_evidence))
        elif state in ("runtime_pure_stub","runtime_fixture"):
            overrides.append(dict(owner=ref["owner"],rva=ref["rva"],vtable_va=ref["vtable_va"],slot=ref["slot"],origin=ref["origin"],runtime_reference_tested=1,enabled=0,reconstructed=0,validation_status=state,
                                  evidence=tested_evidence[(ref["owner"],rva)]))
        elif state=="excluded_runtime_slot_mismatch":
            overrides.append(dict(owner=ref["owner"],rva=ref["rva"],vtable_va=ref["vtable_va"],slot=ref["slot"],origin=ref["origin"],runtime_reference_tested=0,enabled=0,reconstructed=0,validation_status=state,
                                  evidence="reversing/ARTValidation/evidence/rejected-slots.csv; excluded: runtime table target mismatch, possible crossed vtable boundary"))
        output=dict(ref,validation_status=state,simple_stub_candidate=int(rva in candidate_rvas),runtime_slot_result=slot_result)
        if state in ("runtime_pure_stub","runtime_fixture"):
            output["runtime_reference_tested"]="1"
            output["evidence"]=tested_evidence[(ref["owner"],rva)]
        elif state.startswith("excluded_"):
            output["runtime_reference_tested"]="0"
            if state=="excluded_fatal_handler": output["evidence"]=fatal_evidence
        rows.append(output)
    with (ROOT/"docs/MemoryMap/art_validation.csv").open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=fields);writer.writeheader();writer.writerows(rows)
    with (ROOT/"reversing/ARTValidation/evidence/rejected-slots.csv").open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=list(refs[0])+["runtime_slot_result","reason"]);writer.writeheader();writer.writerows(rejected)
    with (ROOT/"reversing/ARTValidation/evidence/fatal-references.csv").open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=list(refs[0])+["validation_status","runtime_slot_result"]);writer.writeheader();writer.writerows(fatal)
    (ROOT/"reversing/ARTValidation/evidence/reference-results.json").write_text(json.dumps(overrides,indent=2)+"\n",encoding="utf-8")
    catalog_path.write_text(json.dumps(catalog,indent=2)+"\n",encoding="utf-8")
    path=ROOT/"docs/MemoryMap/ARTValidation.md"
    text=path.read_text(encoding="utf-8").split("\n## Prueba runtime registrada")[0]
    text+="\n## Prueba runtime registrada\n\n"
    text+=f'La auditoría comparó {len(slots):,} referencias virtuales con sus destinos esperados y permisos ejecutables: {game_report["slots_failed"]} fallos. Comprueba direcciones; no llama esas funciones ni establece sus firmas. Las referencias del SDK no forman parte de esta auditoría.\n\n'
    for group,_,kind in GROUPS:
        report=reports[group]
        text+=f'- [{group}: resumen](../../reversing/{group}/evidence/runtime-summary.json): {len(report["entries"]):,} destinos, {sum(e["calls"] for e in report["entries"]):,} llamadas, {sum(e["failures"] for e in report["entries"])} fallos y {report["exceptions"]} excepciones; alcance {"cuerpos completos de retorno simple" if kind=="pure_stub_call" else "operaciones comprobadas en almacenamiento sintético"}.\n'
    text+='\nEl CSV diferencia `runtime_pure_stub` y `runtime_fixture`. `runtime_slot_result=0` acredita únicamente la auditoría de esa referencia virtual. Todos los registros continúan deshabilitados y sin reconstruir. El catálogo usa nombres descriptivos inferidos por RVA; ninguna clase se declara completa.\n'
    from collections import Counter
    states=Counter(row["validation_status"] for row in rows)
    text+='\n| Estado de referencia | Cantidad |\n|---|---:|\n'+''.join(f'| `{name}` | {number:,} |\n' for name,number in sorted(states.items()))
    coverage=json.loads((ROOT/"reversing/ARTValidation/evidence/file-coverage.json").read_text(encoding="utf-8"))
    text+=f'\nLa cobertura [file-coverage.json](../../reversing/ARTValidation/evidence/file-coverage.json) registra {coverage["manifest_headers"]:,} headers del manifiesto, {coverage["disk_headers"]:,} headers en disco y {len(coverage["headers_without_references"]):,} headers sin destinos. Los adicionales se enumeran por separado.\n'
    if rejected:
        text+=f'\nLas {len(rejected)} referencias discrepantes quedaron como `excluded_runtime_slot_mismatch`, detalladas en [rejected-slots.csv](../../reversing/ARTValidation/evidence/rejected-slots.csv).\n'
    else:
        text+='\nNo hubo discrepancias de tablas virtuales; [rejected-slots.csv](../../reversing/ARTValidation/evidence/rejected-slots.csv) contiene únicamente la cabecera.\n'
    tested_rvas={int(e["rva"],16) for report in reports.values() for e in report["entries"] if not e["failures"] and e["calls"]>=64}
    unique_rvas={int(r["rva"],16) for r in refs}
    calls=sum(e["calls"] for report in reports.values() for e in report["entries"])
    text+=f'\nSe comprobaron llamadas acotadas de {len(tested_rvas):,} destinos distintos ({calls:,} llamadas), asociados a {sum(r["validation_status"] in ("runtime_pure_stub","runtime_fixture") for r in rows):,} referencias compartidas. Quedan {len(unique_rvas-tested_rvas):,} destinos sin llamada comprobada, incluido el manejador fatal. La auditoría de direcciones no completa las clases de ART.\n'
    text+=f'\nLas {len(fatal):,} referencias al manejador fatal RVA `0x00001210` están en [fatal-references.csv](../../reversing/ARTValidation/evidence/fatal-references.csv): `excluded_fatal_handler`, sin llamada y deshabilitadas. Sus punteros virtuales sí coincidieron; no se presentan como discrepancias de tabla.\n'
    # Normalize paragraph spacing and preserve contiguous Markdown table rows.
    import re
    text=re.sub(r"\n{3,}","\n\n",text)
    text=re.sub(r"(?m)(^\|[^\n]*\|)\n\n(?=\|)",r"\1\n",text)
    path.write_text(text,encoding="utf-8")
    print(json.dumps(dict(catalog_entries=len(catalog),new_tested_owner_rvas=len(tested),runtime_slots=len(slots))))

if __name__=="__main__":
    main()
