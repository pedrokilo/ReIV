"""Join RTTI types to catalog entries by exact owner name, never by namespace."""
import csv
import hashlib
from collections import defaultdict
from pathlib import Path
from urllib.parse import quote

ROOT = Path(__file__).resolve().parents[2]
OUTPUT = ROOT / "docs/MemoryMap/ClassesAndHooks.md"


def read(path):
    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def code(value):
    return "`" + value.replace("|", "\\|") + "`" if value else "—"


def link(label, path):
    return f"[{label}](../../{quote(path, safe='/')})"


def addresses(value):
    return "<br>".join(code(v) for v in value.split(";") if v) or "—"


def main():
    classes = read("docs/MemoryMap/classes.csv")
    hooks = read("docs/hooks.csv")
    files = {row["name"]: row["file"] for row in read("source/class-files.csv")}
    names = {row["name"] for row in classes}
    assert len(names) == len(classes), "Duplicate RTTI type names"
    matched, unmatched = defaultdict(list), []
    for hook in hooks:
        if hook["class"] in names:
            matched[hook["class"]].append(hook)
        else:
            unmatched.append(hook)
    matched_count = sum(map(len, matched.values()))
    lines = ["# Correlación entre clases RTTI y hooks de ReIV", "",
             "Fuentes: [classes.csv](classes.csv), [hooks.csv](../hooks.csv) e [índice de headers](../../source/class-files.csv).", "",
             "Cruce por **igualdad exacta** entre `classes.csv:name` y `hooks.csv:class`. No se asignan funciones por prefijo, namespace, herencia, destino virtual compartido o parecido de nombres.", "",
             "| Medición | Cantidad |", "| --- | ---: |",
             f"| Tipos RTTI | {len(classes):,} |", f"| Entradas del catálogo de hooks | {len(hooks):,} |",
             f"| Tipos con entradas asociadas | {len(matched):,} |",
             f"| Tipos sin entradas asociadas | {len(classes) - len(matched):,} |",
             f"| Entradas asociadas por nombre exacto | {matched_count:,} |",
             f"| Entradas sin tipo RTTI asociado | {len(unmatched):,} |", "",
             "Un TypeDescriptor, un locator y una vtable son metadatos del tipo; **no son direcciones de métodos**. Las bases RTTI pueden ser transitivas. Una clase sin entradas aquí puede tener numerosos destinos en [virtual_slots.csv](virtual_slots.csv); simplemente no están incorporados a `hooks.csv`. No hay un porcentaje de métodos completados por clase porque su total todavía se desconoce.", "",
             "`validated` se interpreta junto con `entry_kind` y `reconstruction_validated`: probar un wrapper hacia el original no equivale a reconstruirlo. Los resultados son evidencia histórica con el alcance indicado, no una garantía de vigencia de todo el ASI.", "",
             "## Tipos con métodos catalogados", ""]
    for cls in sorted(classes, key=lambda row: row["name"].casefold()):
        if cls["name"] not in matched: continue
        lines += [f"### {code(cls['name'])}", "",
                  f"Tipo: {code(cls['kind'])}. Descriptor VA {code(cls['type_descriptor_va'])}, RVA {code(cls['type_descriptor_rva'])}. Vtables: {addresses(cls['vtables'])}.", "",
                  f"Header: {link('abrir archivo', files[cls['name']])}. Bases registradas: {code(cls['bases'])}.", "",
                  "| Método | VA del método | RVA | Clase de entrada | Dirección comprobada | Reconstruido | Prueba de entrada | Reconstrucción validada | Fuente y evidencia |",
                  "| --- | --- | --- | --- | ---: | ---: | ---: | ---: | --- |"]
        for hook in matched[cls["name"]]:
            lines.append(f"| {code(hook['fn_name'])} | {code(hook['address'])} | {code(hook['rva'])} | {code(hook['entry_kind'])} | {hook['address_checked']} | {hook['reversed']} | {hook['validated']} | {hook['reconstruction_validated']} | {link('Código', hook['source'])} · {link('Evidencia', hook['evidence'])} |")
        lines += ["", "Alcance de las pruebas:", ""]
        for hook in matched[cls["name"]]:
            lines.append(f"- {code(hook['fn_name'])}: {hook['scope']}.")
        lines.append("")
    lines += ["## Entradas sin correspondencia RTTI", "",
              "Se conservan aquí; no se atribuyen automáticamente a ninguna clase.", "",
              "| Propietario del catálogo | Función | VA / RVA | Estado | Evidencia |",
              "| --- | --- | --- | --- | --- |"]
    for hook in unmatched:
        reason = "Namespace/grupo de motor, no una clase RTTI" if hook["class"] == "rage" else "Sin coincidencia exacta en classes.csv"
        lines.append(f"| {code(hook['class'])} | {link(hook['fn_name'], hook['source'])} | {code(hook['address'])} / {code(hook['rva'])} | {reason}; {code(hook['entry_kind'])} | {link('Ver evidencia', hook['evidence'])} |")
    lines += ["", "## Inventario completo por carpeta", "",
              "Cada uno de los tipos del CSV aparece una sola vez. La última columna cuenta entradas catalogadas, reconstruidas y probadas; cero significa ausencia en el catálogo, no ausencia de funciones en el EXE.", ""]
    groups = defaultdict(list)
    for cls in classes:
        assert cls["name"] in files, cls["name"]
        assert (ROOT / files[cls["name"]]).is_file(), files[cls["name"]]
        groups[files[cls["name"]].split("/")[1]].append(cls)
    for group in sorted(groups):
        lines += ["<details>", f"<summary>source/{group} · {len(groups[group]):,} tipos</summary>", "",
                  "| Tipo RTTI | Header | Descriptor VA / RVA | Locators VA | Vtables VA | Bases RTTI | Entradas / reconstruidas / probadas |",
                  "| --- | --- | --- | --- | --- | --- | ---: |"]
        for cls in sorted(groups[group], key=lambda row: row["name"].casefold()):
            related = matched.get(cls["name"], [])
            counts = f"{len(related)} / {sum(int(h['reversed']) for h in related)} / {sum(int(h['validated']) for h in related)}"
            lines.append(f"| {code(cls['name'])} | {link('Header', files[cls['name']])} | {code(cls['type_descriptor_va'])}<br>{code(cls['type_descriptor_rva'])} | {addresses(cls['locators'])} | {addresses(cls['vtables'])} | {code(cls['bases'])} | {counts} |")
        lines += ["", "</details>", ""]
    lines += ["## Actualización y procedencia", "",
              "Regenerar con `python reversing/HookRegistry/correlate_classes.py`, o con el generador general `python reversing/HookRegistry/generate.py`. No editar las tablas generadas a mano.", "",
              "SHA-256 de las fuentes usadas:", ""]
    for path in ("docs/MemoryMap/classes.csv", "docs/hooks.csv", "source/class-files.csv"):
        lines.append(f"- {code(path)}: {code(hashlib.sha256((ROOT / path).read_bytes()).hexdigest())}.")
    lines += ["", "[Proceso de vinculación](../AddressBindingProcess.md) · [Progreso de reconstrucción](../ReversedClasses.md).", ""]
    OUTPUT.write_text("\n".join(lines), encoding="utf-8")
    print(f"Correlated {len(classes)} types: {matched_count} catalog entries matched, {len(unmatched)} unmatched")


if __name__ == "__main__": main()
