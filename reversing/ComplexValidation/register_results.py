"""Register scoped complex-fixture execution; restricted destructors stay restricted."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SHA = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
GROUPS = (
    ("game", "runtime", "GameComplexProbe.h", "fixture-scope.json"),
    ("game", "scalar-runtime", "GameComplexScalarProbe.h", "scalar-scope.json"),
    ("rage", "runtime", "RageComplexProbe.h", "fixture-scope.json"),
    ("ART", "runtime", "ARTComplexProbe.h", "fixture-scope.json"),
    ("destructors", "runtime", "DestructorModeProbe.h", "fixture-scope.json"),
)


def rows(path):
    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def main():
    refs = rows("docs/MemoryMap/pending_hooks.csv")
    catalog_path = ROOT / "reversing/HookRegistry/catalog.json"
    catalog = json.loads(catalog_path.read_text())
    existing = {(r["class"], int(r["rva"], 16)) for r in catalog}
    overrides = {}
    counts = []
    all_rvas = set()
    for folder, prefix, source, filename in GROUPS:
        directory = ROOT / "reversing/ComplexValidation" / folder / "evidence"
        evidence = f"reversing/ComplexValidation/{folder}/evidence/{prefix}-summary.json"
        summary = json.loads((ROOT / evidence).read_text(encoding="utf-8-sig"))
        report = json.loads((directory / (prefix + "-report.json")).read_text(encoding="utf-8-sig"))
        candidates = {int(c["rva"], 16): c for c in json.loads((directory / filename).read_text())}
        implementation = "source/hooks/" + source
        assert summary["passed"] and summary["exe_sha256"] == SHA
        assert summary["implementation_sha256"] == hashlib.sha256((ROOT / implementation).read_bytes()).hexdigest()
        assert summary["scope_sha256"] == hashlib.sha256((directory / filename).read_bytes()).hexdigest()
        assert report == summary["result"] and report["phase"] == "passed" and not report["exceptions"]
        assert summary["game_run"]["passed"] and summary["game_run"]["exit_code"] == 0 and not summary["game_run"]["forced_stop"]
        assert {int(e["rva"], 16) for e in report["entries"]} == set(candidates)
        assert not all_rvas.intersection(candidates)
        all_rvas.update(candidates)
        restricted = folder == "destructors"
        if restricted:
            assert report["restricted_nonfreeing_mode_only"]
        for item in report["entries"]:
            assert item["calls"] == 64 and not item["failures"] and not item["disabled"]
            rva = int(item["rva"], 16)
            c = candidates[rva]
            scope = "64 isolated-object samples; full body/envelope bytes checked; full memory guard; synthetic x86 convention; original class ABI and gameplay not established"
            if restricted:
                scope += "; ONLY flags bit0 clear; writes vtable and returns this; freeing/TLS allocator branch statically excluded and NEVER called; does not validate deleting mode"
            elif folder == "rage":
                scope += "; complete forward CFG reviewed; defined EAX mask only; expected_nodes_mask describes model paths, not instrumented native coverage"
            elif folder == "ART":
                scope += "; controlled nested object/output buffers where needed; both bit-predicate outcomes sampled"
            else:
                scope += "; comparison/bit/scalar bodies only; EDX/high return not established"
            for ref in refs:
                if int(ref["rva"], 16) != rva or ref["owner"] not in c["owners"]:
                    continue
                assert not ref["label"].startswith("excluded_") and rva != 0x1210
                key = (ref["owner"], rva, int(ref["vtable_va"], 16), int(ref["slot"]))
                overrides[key] = dict(owner=ref["owner"], rva=ref["rva"], vtable_va=ref["vtable_va"], slot=ref["slot"], runtime_reference_tested=True, validation_status="runtime_restricted_mode" if restricted else "runtime_fixture", evidence=evidence + "; " + scope)
                pair = (ref["owner"], rva)
                if pair in existing:
                    continue
                catalog.append({"class": ref["owner"], "fn_name": f"{'NonDeletingMode' if restricted else 'ComplexFixture'}_RVA_{rva:08X}", "rva": f"0x{rva:08X}", "reversed": 0, "locked": 0, "validated": 1, "type": "M", "entry_kind": "restricted_original_call" if restricted else "original_call", "address_checked": 1, "runtime_checked": 1, "reconstruction_validated": 0, "standalone": 0, "source": implementation, "evidence": evidence, "scope": scope})
                existing.add(pair)
        counts.append(dict(folder=folder, bank=prefix, targets=len(candidates), calls=sum(e["calls"] for e in report["entries"]), scope="restricted_nonfreeing_mode" if restricted else "isolated_fixture", evidence=evidence))
    output = ROOT / "reversing/ComplexValidation/evidence"
    output.mkdir(exist_ok=True)
    (output / "reference-results.json").write_text(json.dumps(list(overrides.values()), indent=2) + "\n", encoding="utf-8")
    (output / "summary.json").write_text(json.dumps(dict(exe_sha256=SHA, groups=counts, targets=len(all_rvas), calls=sum(c["calls"] for c in counts), references=len(overrides), hooks_enabled=0, reconstructed=0), indent=2) + "\n", encoding="utf-8")
    catalog_path.write_text(json.dumps(catalog, indent=2) + "\n", encoding="utf-8")
    for relative in ("docs/MemoryMap/game_validation.csv", "docs/MemoryMap/rage_validation.csv", "docs/MemoryMap/art_validation.csv"):
        records = rows(relative)
        for r in records:
            key = (r["owner"], int(r["rva"],16), int(r["vtable_va"],16), int(r["slot"]))
            update = overrides.get(key)
            if update:
                r["runtime_reference_tested"] = 1
                r["validation_status"] = update["validation_status"]
                if update["evidence"] not in r["evidence"]:
                    r["evidence"] += "; " + update["evidence"]
        with (ROOT / relative).open("w", encoding="utf-8", newline="") as stream:
            writer = csv.DictWriter(stream, fieldnames=list(records[0])); writer.writeheader(); writer.writerows(records)
    print(f"Registered {len(all_rvas)} targets/{sum(c['calls'] for c in counts)} calls/{len(overrides)} references; all hooks remain disabled.")


if __name__ == "__main__":
    main()
