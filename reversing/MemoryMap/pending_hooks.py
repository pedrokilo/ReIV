"""Collect address candidates without treating unknown ABI as callable code."""
import csv
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MARKER = "// BEGIN GENERATED PENDING HOOK ADDRESSES\n"


def rows(path):
    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


CLASSES = {r["name"] for r in rows("docs/MemoryMap/classes.csv")}
TESTED = {(r["class"], r["fn_name"], int(r["rva"], 16)): r["evidence"] for r in rows("docs/hooks.csv") if r["runtime_checked"] == "1"}
ENTRIES = defaultdict(list)
UNMATCHED = []
NM_VALIDATION = ROOT / "reversing/NMutils/evidence/runtime-summary.json"
NM_TESTED = set()
if NM_VALIDATION.exists():
    nm_result = json.loads(NM_VALIDATION.read_text(encoding="utf-8-sig"))
    if nm_result["passed"] and nm_result["nmutils"]["phase"] == "passed":
        NM_TESTED = {int(e["rva"],16) for e in nm_result["nmutils"]["entries"] if e["calls"] == 64 and not e["failures"]}
for r in rows("docs/MemoryMap/virtual_slots.csv"):
    assert r["owner"] in CLASSES, r["owner"]
    ENTRIES[r["owner"]].append(dict(owner=r["owner"], va=r["function_va"], rva=r["function_rva"], vtable_va=r["vtable_va"], slot=r["slot"], label=r["function_name"], name_candidates=r["sdk_names"], evidence="docs/MemoryMap/virtual_slots.csv; " + r["sdk_evidence"], origin="VirtualSlot", runtime_reference_tested=0))
    if r["owner"] in {"NMutils::BasicLogger", "NMutils::MemoryStream", "NMutils::MemoryStreamReader"}:
        entry = ENTRIES[r["owner"]][-1]
        entry["evidence"] += "; docs/MemoryMap/NMutilsValidation.md"
        if int(entry["rva"],16) in NM_TESTED:
            entry["runtime_reference_tested"] = 1
            entry["evidence"] += "; 64 synthetic-object calls: reversing/NMutils/evidence/runtime-summary.json (not reconstructed; not installed)"
        if int(entry["rva"],16) == 0x1210:
            entry["label"] = "fatal_assertion_handler_do_not_call"
            entry["name_candidates"] = ""
            entry["evidence"] += "; binary body and helper provoke process termination; excluded from runtime test"
for r in rows("docs/MemoryMap/sdk_addresses.csv"):
    if r["kind"] != "function_reference" or r["mapped"] != "True" or r["executable"] != "True": continue
    entry = dict(owner=r["owner"], va=r["va"], rva=r["rva"], vtable_va="0x00000000", slot="-1", label=r["name"], name_candidates=r["name"], evidence=f"{r['file']}:{r['line']}; {r['status']}", origin="SdkFunctionReference", runtime_reference_tested=int((r["owner"], r["name"].removeprefix(r["owner"] + "::"), int(r["rva"],16)) in TESTED))
    if entry["runtime_reference_tested"]:
        entry["evidence"] += "; runtime reference test: " + TESTED[(r["owner"], r["name"].removeprefix(r["owner"] + "::"), int(r["rva"],16))]
    (ENTRIES[r["owner"]] if r["owner"] in CLASSES else UNMATCHED).append(entry)


# Non-virtual callbacks recovered from validated MSVC exception metadata chains.
exception_callbacks = ROOT / "reversing/UnknownTypesAnalysis/evidence/pending-overlay.csv"
if exception_callbacks.exists():
    for r in rows("reversing/UnknownTypesAnalysis/evidence/pending-overlay.csv"):
        assert r["owner"] in CLASSES
        assert r["origin"] in ("ExceptionCopyConstructor", "ExceptionUnwindDestructor")
        ENTRIES[r["owner"]].append({k: r[k] for k in ("owner", "va", "rva", "vtable_va", "slot", "label", "name_candidates", "evidence", "origin")} | {"vtable_va": r["vtable_va"] or "0x00000000", "slot": r["slot"] or "-1", "runtime_reference_tested": 0})

# Scoped validation records never make references executable or reconstructed.
for entries in ENTRIES.values():
    for entry in entries:
        if int(entry["rva"],16) == 0x1210:
            entry["label"] = "fatal_assertion_handler_do_not_call"
            entry["name_candidates"] = ""
            entry["evidence"] += "; reversing/NMutils/evidence/00401210.txt and 005a8cb0.txt: fatal handler, never test-called"
for relative_validation in ("reversing/GameValidation/evidence/reference-results.json", "reversing/RageValidation/evidence/reference-results.json", "reversing/ARTValidation/evidence/reference-results.json", "reversing/PendingAnalysis/evidence/reference-results.json", "reversing/ComplexValidation/evidence/reference-results.json"):
    validation_path = ROOT / relative_validation
    if not validation_path.exists():
        continue
    validation_rows = json.loads(validation_path.read_text(encoding="utf-8-sig"))
    validation_by_key = {(r["owner"],int(r["rva"],16),int(r["vtable_va"],16),int(r["slot"])):r for r in validation_rows}
    for entries in ENTRIES.values():
        for entry in entries:
            key = (entry["owner"],int(entry["rva"],16),int(entry["vtable_va"],16),int(entry["slot"]))
            result = validation_by_key.get(key)
            if result:
                entry["runtime_reference_tested"] = int(result["runtime_reference_tested"])
                entry["evidence"] += "; " + result["evidence"]
                if result.get("excluded") or result.get("validation_status") == "excluded_runtime_slot_mismatch":
                    entry["label"] = "fatal_assertion_handler_do_not_call" if result.get("validation_status") == "excluded_fatal_handler" else "excluded_runtime_vtable_mismatch"
                    entry["name_candidates"] = ""

def block(name):
    import hashlib
    identifier = "type_" + hashlib.sha256(name.encode()).hexdigest()[:16]
    entries = ENTRIES.get(name, [])
    lines = [MARKER.rstrip(), '#include "core/PendingHook.h"', f"namespace reiv {{ namespace memory_map {{ namespace {identifier} {{", "// Destinations from the inventory; names/ABI remain candidates. Never auto-install.", f"inline constexpr std::uint32_t pending_hook_count = {len(entries)}u;"]
    if entries:
        lines.append("inline constexpr PendingHook pending_hook_storage[] = {")
        for r in entries:
            assert int(r["va"],16) - int(r["rva"],16) == 0x400000
            values = [r["va"]+"u", r["rva"]+"u", r["vtable_va"]+"u", r["slot"], *(json.dumps(r[k],ensure_ascii=True) for k in ("label","name_candidates","evidence")), "AddressOrigin::"+r["origin"], str(bool(r["runtime_reference_tested"])).lower(), "false", "false"]
            lines.append("    {" + ", ".join(values) + "},")
        lines += ["};", "inline constexpr const PendingHook* pending_hooks = pending_hook_storage;"]
    else:
        lines += ["// No function destinations associated by exact owner name in the available CSVs.", "inline constexpr const PendingHook* pending_hooks = nullptr;"]
    lines += ["} } }", "// END GENERATED PENDING HOOK ADDRESSES", ""]
    return "\n".join(lines)


def write_index(files):
    fields = "owner file va rva vtable_va slot label name_candidates evidence origin runtime_reference_tested enabled reconstructed".split()
    with (ROOT / "docs/MemoryMap/pending_hooks.csv").open("w",encoding="utf-8",newline="") as stream:
        writer=csv.DictWriter(stream,fieldnames=fields);writer.writeheader()
        for owner in sorted(ENTRIES):
            for row in ENTRIES[owner]: writer.writerow(dict(row,file=files[owner],enabled=0,reconstructed=0))
    with (ROOT / "docs/MemoryMap/pending_hooks_unmatched.csv").open("w",encoding="utf-8",newline="") as stream:
        writer=csv.DictWriter(stream,fieldnames=fields);writer.writeheader()
        for row in UNMATCHED: writer.writerow(dict(row,file="",enabled=0,reconstructed=0))
    total = sum(map(len,ENTRIES.values()))
    print(f"Pending addresses: {total}; types with destinations: {len(ENTRIES)}; SDK references without RTTI owner: {len(UNMATCHED)}")
