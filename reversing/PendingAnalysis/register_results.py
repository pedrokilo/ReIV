"""Register only complete, passed isolated-fixture reports; never enable hooks."""
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SHA = "ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c"
GROUPS = (
    ("game", "source/hooks/GamePendingProbe.h", "fixture-scope.json"),
    ("rage-art", "source/hooks/PendingScalarProbe.h", "evidence/fixture-scope.json"),
)


def read_csv(path):
    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def main():
    refs = read_csv("docs/MemoryMap/pending_hooks.csv")
    catalog_path = ROOT / "reversing/HookRegistry/catalog.json"
    catalog = json.loads(catalog_path.read_text())
    existing = {(row["class"], int(row["rva"], 16)) for row in catalog}
    overrides = {}
    evidence_root = ROOT / "reversing/PendingAnalysis/evidence"
    for group, source, scope_path in GROUPS:
        folder = ROOT / "reversing/PendingAnalysis" / group
        evidence = f"reversing/PendingAnalysis/{group}/evidence/runtime-summary.json"
        summary = json.loads((ROOT / evidence).read_text(encoding="utf-8-sig"))
        report = json.loads((folder / "evidence/runtime-report.json").read_text(encoding="utf-8-sig"))
        scope = json.loads((folder / scope_path).read_text())
        candidates = {int(row["rva"], 16): row for row in scope}
        assert summary["passed"] and summary["exe_sha256"] == SHA
        assert summary["implementation_sha256"] == hashlib.sha256((ROOT / source).read_bytes()).hexdigest()
        assert report == summary["result"] and report["phase"] == "passed" and not report["exceptions"]
        assert summary["game_run"]["exit_code"] == 0 and not summary["game_run"]["forced_stop"]
        assert {int(row["rva"], 16) for row in report["entries"]} == set(candidates)
        for result in report["entries"]:
            assert result["calls"] == 64 and not result["failures"] and not result["disabled"]
            rva = int(result["rva"], 16)
            candidate = candidates[rva]
            operation = candidate.get("operation", "straight-line scalar body")
            detail = f"64 isolated-storage calls; {operation}; complete entry bytes checked; full object guard; synthetic x86 convention only; not original class ABI or reconstruction"
            if group == "rage-art":
                detail += "; integer return validates only mask-defined EAX bits; EDX/high return and class semantics not established"
            for ref in refs:
                if int(ref["rva"], 16) != rva or ref["owner"] not in candidate["owners"]:
                    continue
                assert not ref["label"].startswith("excluded_")
                key = (ref["owner"], rva, int(ref["vtable_va"], 16), int(ref["slot"]))
                overrides[key] = dict(owner=ref["owner"], rva=ref["rva"], vtable_va=ref["vtable_va"], slot=ref["slot"], runtime_reference_tested=True, validation_status="runtime_fixture", evidence=evidence + "; " + detail)
                pair = (ref["owner"], rva)
                if pair in existing:
                    continue
                catalog.append({"class": ref["owner"], "fn_name": f"PendingFixture_RVA_{rva:08X}", "rva": f"0x{rva:08X}", "reversed": 0, "locked": 0, "validated": 1, "type": "M", "entry_kind": "original_call", "address_checked": 1, "runtime_checked": 1, "reconstruction_validated": 0, "standalone": 0, "source": source, "evidence": evidence, "scope": detail})
                existing.add(pair)
    # Mark every known fatal reference explicitly, including previously untested game owners.
    for ref in refs:
        if int(ref["rva"], 16) != 0x1210:
            continue
        key = (ref["owner"], 0x1210, int(ref["vtable_va"], 16), int(ref["slot"]))
        overrides[key] = dict(owner=ref["owner"], rva=ref["rva"], vtable_va=ref["vtable_va"], slot=ref["slot"], runtime_reference_tested=False, excluded=True, validation_status="excluded_fatal_handler", evidence="reversing/NMutils/evidence/00401210.txt; reversing/NMutils/evidence/005a8cb0.txt; process termination path excluded, never test-called")
    evidence_root.mkdir(parents=True, exist_ok=True)
    (evidence_root / "reference-results.json").write_text(json.dumps(list(overrides.values()), indent=2) + "\n")
    catalog_path.write_text(json.dumps(catalog, indent=2) + "\n")
    # Keep earlier folder reports current without rerunning their historical banks.
    for relative in ("docs/MemoryMap/game_validation.csv", "docs/MemoryMap/rage_validation.csv", "docs/MemoryMap/art_validation.csv"):
        rows = read_csv(relative)
        for row in rows:
            key = (row["owner"], int(row["rva"], 16), int(row["vtable_va"], 16), int(row["slot"]))
            update = overrides.get(key)
            if update:
                row["validation_status"] = update["validation_status"]
                row["runtime_reference_tested"] = int(update["runtime_reference_tested"])
                row["evidence"] += "; " + update["evidence"]
        with (ROOT / relative).open("w", encoding="utf-8", newline="") as stream:
            writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
            writer.writeheader()
            writer.writerows(rows)
    print(f"Registered {len(overrides)} scoped overrides; {len(catalog)} catalog entries; all pending hooks remain disabled.")


if __name__ == "__main__":
    main()
