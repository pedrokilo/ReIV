"""Nombres de referencia (IV-SDK, plugin_IV, IV-SDK.Net) por dirección y por clase.
Son pistas sin validar; el EXE canónico decide. Fuentes: docs/MemoryMap/*.csv."""
import csv
from collections import defaultdict


def _read(root, name):
    path = root / "docs/MemoryMap" / name
    if not path.exists():
        return []
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def load(root):
    """Devuelve (por_va, clases): por_va[va_minúscula] -> [etiquetas]; clases[nombre] -> {fuentes}."""
    by_va, classes = defaultdict(list), defaultdict(set)
    for r in _read(root, "sdk_addresses.csv"):
        if r["owner"]:
            classes[r["owner"]].add("IV-SDK")
        if r["kind"] == "function_reference" and r["executable"] == "True":
            by_va[r["va"].lower()].append("IV-SDK:" + r["name"])
    for r in _read(root, "plugin_iv_patterns.csv"):
        if r["owner"]:
            classes[r["owner"]].add("plugin_IV")
        if r["kind"] == "function_start" and r["target_va"]:
            by_va[r["target_va"].lower()].append("plugin_IV:" + r["owner"] + "::" + r["name"])
    for r in _read(root, "sdknet_addresses.csv"):
        if r["owner"] and r["kind"] != "byte_pattern":
            classes[r["owner"]].add("IV-SDK.Net")
        if r["kind"] == "function_or_code":
            by_va[r["va"].lower()].append("IV-SDK.Net:" + r["owner"] + "::" + r["name"])
    return {k: list(dict.fromkeys(v)) for k, v in by_va.items()}, classes
