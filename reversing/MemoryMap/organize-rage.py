"""Move RTTI headers into the engine module structure; never copy reference code."""
import csv
import hashlib
import importlib.util
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
REFERENCE = Path("E:/Original/gta5/src/dev_ng/rage")


def classify(name):
    n = name[6:].split("::")[0].split("<")[0]
    rules = [
        (("rl", "AutoIdDescriptor", "TaskAndStatus"), "base/src/rline"),
        (("sn",), "suite/src/snet"),
        (("net", "CMsgPlayer", "CMsgText"), "base/src/net"),
        (("crmt", "crmf"), "suite/src/crmotiontree"),
        (("crExpression",), "suite/src/animExprData"),
        (("crSkeleton", "crBone"), "base/src/crskeleton"),
        (("crCreature",), "base/src/creature"),
        (("crClip",), "suite/src/crclip"),
        (("cr",), "base/src/cranimation"),
        (("aud",), "base/src/audioengine"),
        (("fi",), "base/src/file"),
        (("at",), "base/src/atl"),
        (("pg", "Resource"), "base/src/paging"),
        (("par", "ParseClass"), "base/src/parser"),
        (("dat",), "base/src/data"),
        (("sys", "miniheap"), "base/src/system"),
        (("phBound",), "base/src/phbound"),
        (("phArticulated",), "base/src/pharticulated"),
        (("bt", "Gjk", "TriangleShape"), "base/src/phbullet"),
        (("ph",), "base/src/physics"),
        (("frag",), "suite/src/fragment"),
        (("ptxgpu",), "suite/src/gpuptfx"),
        (("ptx", "rmPtfx"), "suite/src/rmptfx"),
        (("rageShader", "ShaderFragment", "VarCache"), "base/src/shaderMaterial"),
        (("grm",), "base/src/grmodel"),
        (("grb",), "base/src/grblendshapes"),
        (("grc",), "base/src/grcore"),
        (("CPostFX",), "base/src/grpostfx"),
        (("rmc", "rm"), "base/src/rmcore"),
        (("rsm", "DayLighting", "EnviromentDomeLighting", "FogControl", "WaterFogControl", "Sky", "AtmosphericScattering", "IntervalShadows", "Procedural"), "suite/src/shadercontrollers"),
        (("Vector", "Matrix"), "base/src/vector"),
        (("cv", "Curve"), "base/src/curve"),
        (("spd",), "base/src/spatialdata"),
        (("evt",), "suite/src/event"),
        (("scr",), "script/src/script"),
        (("CBaseStream", "CWMStream", "io"), "base/src/video"),
        (("nm",), "framework/src/phframework"),
        (("VerletWater",), "suite/src/shadercontrollers"),
    ]
    return next((folder for prefixes, folder in rules if n.startswith(prefixes)), "base/src/system")


def main():
    mapping_path = HERE / "rage-folders.csv"
    if mapping_path.exists():
        raise RuntimeError("Already organized; use generate-class-headers.py to verify or regenerate.")
    reference_files = defaultdict(set)
    for layer in ("base", "suite", "framework", "contrib", "script"):
        for path in (REFERENCE / layer / "src").rglob("*.h"):
            rel = path.relative_to(REFERENCE)
            if any(part.lower() in {"vcproj", "deprecated"} for part in rel.parts): continue
            reference_files[path.stem.casefold()].add(rel.parent.as_posix())
    entries = list(csv.DictReader((ROOT / "source/class-files.csv").open(encoding="utf-8")))
    rows, moves, counts = [], [], Counter()
    workspace = (ROOT / "source/rage").resolve()
    for entry in entries:
        if not entry["file"].startswith("source/rage/"): continue
        name = entry["name"]
        folder = classify(name)
        matches = reference_files.get(name[6:].split("::")[0].split("<")[0].casefold(), set())
        basis = "name_family"
        if len(matches) == 1:
            folder = next(iter(matches)); basis = "reference_filename"
        source = (ROOT / entry["file"]).resolve()
        target = (workspace / folder / source.relative_to(workspace)).resolve()
        assert source.is_relative_to(workspace) and target.is_relative_to(workspace)
        assert source.is_file() and not target.exists(), target
        # Long template names are already sanitized by the header generator.
        assert len(str(target)) < 250, target
        rows.append({"name": name, "folder": folder, "basis": basis})
        moves.append((source, target, hashlib.sha256(source.read_bytes()).hexdigest()))
        counts[folder] += 1
    with mapping_path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=["name", "folder", "basis"])
        writer.writeheader(); writer.writerows(rows)
    for source, target, digest in moves:
        target.parent.mkdir(parents=True, exist_ok=True)
        source.rename(target)
        assert hashlib.sha256(target.read_bytes()).hexdigest() == digest
    for directory in sorted(workspace.rglob("*"), key=lambda p: len(p.parts), reverse=True):
        if directory.is_dir() and not any(directory.iterdir()): directory.rmdir()
    spec = importlib.util.spec_from_file_location("headers", HERE / "generate-class-headers.py")
    module = importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
    module.main()
    print(f"Moved {len(moves)} headers; content hashes preserved.")
    print(dict(sorted(counts.items())))
    print(f"Unique reference filename matches: {sum(row['basis'] == 'reference_filename' for row in rows)}")


if __name__ == "__main__": main()
