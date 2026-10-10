"""Create one C++ reference header per RTTI type without inventing layouts."""
import csv
import hashlib
import json
import re
from collections import Counter
from pathlib import Path
from pending_hooks import MARKER, block, write_index

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "source"
MANIFEST = SOURCE / "class-files.csv"
ORGANIZATION = Path(__file__).with_name("game-folders.csv")
GAME_FOLDERS = {}
RAGE_FOLDERS = {}
rage_organization = Path(__file__).with_name("rage-folders.csv")
if rage_organization.exists():
    with rage_organization.open(encoding="utf-8", newline="") as stream:
        RAGE_FOLDERS = {row["name"]: row["folder"] for row in csv.DictReader(stream)}
if ORGANIZATION.exists():
    with ORGANIZATION.open(encoding="utf-8", newline="") as stream:
        GAME_FOLDERS = {row["name"]: row["folder"] for row in csv.DictReader(stream)}


def qualified_parts(name):
    parts, start, depth = [], 0, 0
    for i, char in enumerate(name):
        if char in "<([":
            depth += 1
        elif char in ">)]":
            depth -= 1
        elif name[i:i + 2] == "::" and depth == 0:
            parts.append(name[start:i])
            start = i + 2
    parts.append(name[start:])
    return parts


def safe_component(name):
    safe = re.sub(r"[^A-Za-z0-9_]+", "_", name).strip("_") or "type"
    if safe != name or len(safe) > 70 or safe.upper() in {"CON", "PRN", "AUX", "NUL", *(f"COM{i}" for i in range(10)), *(f"LPT{i}" for i in range(10))}:
        safe = safe[:55] + "_" + hashlib.sha256(name.encode()).hexdigest()[:12]
    return safe


def location(name):
    parts = qualified_parts(name)
    if parts[0] == "rage":
        folder, parts = Path("rage") / RAGE_FOLDERS.get(name, ""), parts[1:]
    elif parts[0] in {"ART", "NMutils"}:
        folder, parts = Path("external") / parts[0], parts[1:]
    else:
        folder = Path("game") / GAME_FOLDERS.get(name, "")
    return folder.joinpath(*(safe_component(p) for p in parts)).with_suffix(".h")


def header(row):
    name = row["name"]
    identifier = "type_" + hashlib.sha256(name.encode()).hexdigest()[:16]
    lines = ["#pragma once", "#include <cstdint>", "", "// GTA IV PC 1.0.7.0, x86. Reference from docs/MemoryMap/classes.csv.", f"// RTTI type: {name}", "// Layout, inheritance, signatures and behavior remain unverified.", "// Runtime VA = module base + RVA; these addresses are not instances.", ""]
    parts = qualified_parts(name)
    # Only simple top-level types can be forward-declared from this inventory.
    # RTTI cannot distinguish a nested class owner from a namespace or recover
    # a template's parameter declarations.
    declaration = parts[-1]
    override = Path(__file__).with_name("declarations") / (safe_component(name) + ".inc")
    if override.exists():
        lines += override.read_text(encoding="utf-8").splitlines() + [""]
    elif re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", declaration) and (len(parts) == 1 or len(parts) == 2 and parts[0] in {"rage", "ART", "NMutils"}):
        scope = parts[0] if len(parts) == 2 else "game"
        lines += [f"namespace reiv {{ namespace {scope} {{", f"{row['kind']} {declaration};", "} }", ""]
    else:
        lines += ["// Nested/template type: declaration deferred until its owner/parameters are known.", ""]
    lines += [f"namespace reiv {{ namespace memory_map {{ namespace {identifier} {{"]
    for key in ("name", "mangled", "kind", "section", "status", "bases"):
        lines.append(f"inline constexpr char {key}[] = {json.dumps(row[key], ensure_ascii=True)};")
    for key in ("type_descriptor_va", "type_descriptor_rva"):
        lines.append(f"inline constexpr std::uint32_t {key} = {row[key]}u;")
    lines.append(f"inline constexpr bool in_sdk = {row['in_sdk'].lower()};")
    for field in ("locators", "vtables"):
        addresses = [value for value in row[field].split(";") if value]
        # A sentinel array plus count avoids non-standard zero-length arrays.
        values = ", ".join(value + "u" for value in addresses) or "0u"
        lines += [f"inline constexpr std::uint32_t {field}[] = {{{values}}};", f"inline constexpr std::uint32_t {field}_count = {len(addresses)}u;"]
    lines += ["} } }", ""]
    return "\n".join(lines) + block(name)


def main():
    with (ROOT / "docs/MemoryMap/classes.csv").open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    planned, seen = [], set()
    for row in rows:
        relative = location(row["name"])
        if relative.as_posix().casefold() in seen:
            relative = relative.with_name(relative.stem + "_" + hashlib.sha256(row["name"].encode()).hexdigest()[:12] + ".h")
        assert relative.as_posix().casefold() not in seen, relative
        seen.add(relative.as_posix().casefold())
        target = SOURCE / relative
        assert len(str(target)) < 250, target
        planned.append((row, relative, target, header(row)))
    # Refuse to replace edited or pre-existing headers. Validate before writing.
    for _, _, target, content in planned:
        if target.exists() and target.read_text(encoding="utf-8").split(MARKER)[0] != content.split(MARKER)[0]:
            raise RuntimeError(f"Existing header differs; preserve it: {target}")
    for _, _, target, content in planned:
        target.parent.mkdir(parents=True, exist_ok=True)
        if not target.exists() or target.read_text(encoding="utf-8") != content:
            target.write_text(content, encoding="utf-8", newline="\n")
    with MANIFEST.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=["name", "kind", "file", "type_descriptor_va", "type_descriptor_rva"])
        writer.writeheader()
        for row, relative, _, _ in planned:
            writer.writerow({"name": row["name"], "kind": row["kind"], "file": "source/" + relative.as_posix(), "type_descriptor_va": row["type_descriptor_va"], "type_descriptor_rva": row["type_descriptor_rva"]})
    print(f"Headers: {len(planned)}; folders: {dict(Counter(relative.parts[0] for _, relative, _, _ in planned))}")
    write_index({row['name']: 'source/' + relative.as_posix() for row, relative, _, _ in planned})


if __name__ == "__main__":
    main()
