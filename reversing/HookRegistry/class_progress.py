"""Render class reconstruction progress independently of address validation."""
import csv
from sdk_refs import load as load_references
from collections import defaultdict
from datetime import datetime, timezone


def render(root, entries):
    def read(relative):
        with (root / relative).open(encoding="utf-8-sig", newline="") as stream:
            return list(csv.DictReader(stream))

    classes = read("source/class-files.csv")
    _, references = load_references(root)
    known = defaultdict(set)
    for row in read("docs/MemoryMap/pending_hooks.csv"):
        known[row["owner"]].add(int(row["rva"], 16))
    reconstructed = defaultdict(set)
    validated = defaultdict(set)
    for row in entries:
        if row["reversed"]:
            reconstructed[row["class"]].add(int(row["rva"], 16))
            if row["reconstruction_validated"]:
                validated[row["class"]].add(int(row["rva"], 16))
    # The available RTTI inventory is not an exhaustive method inventory.
    groups = {"sin-revertir": [], "parciales": [], "completas": [], "desconocido": []}
    for row in sorted(classes, key=lambda item: item["name"].casefold()):
        category = "parciales" if reconstructed[row["name"]] else ("sin-revertir" if known[row["name"]] else "desconocido")
        groups[category].append(row)
    total = len(classes)
    count = sum(bool(reconstructed[row["name"]]) for row in classes)
    unknown = len(groups["desconocido"])
    unreversed = len(groups["sin-revertir"])
    stamp = datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M UTC")
    lines = ["# Progreso del reversing", "",
             "[Inicio](../README.md) · [Clases y hooks](MemoryMap/ClassesAndHooks.md) · [Proceso y evidencia](AddressBindingProcess.md)", "",
             f"> **Fuente:** [hooks.csv](hooks.csv) · [Inventario de clases](../source/class-files.csv) · **Generado:** {stamp}", "",
             "## Objetivo y dimensiones de progreso", "",
             "Reconstruir las funciones de GTA IV y comprobar su comportamiento. Registrar una dirección o llamar al original acredita ese alcance de prueba; no cuenta como código revertido.", "",
             "| Dimensión | Medición |", "| --- | --- |",
             f"| Clases completamente revertidas | 0/{total:,} · 0.00% |",
             f"| Clases parcialmente revertidas | {count}/{total:,} |",
             f"| Clases sin revertir | {unreversed:,}/{total:,} |",
             f"| Desconocido: sin direcciones de métodos | {unknown:,}/{total:,} |",
             f"| Entradas de funciones reconstruidas | {sum(bool(e['reversed']) for e in entries):,}/{len(entries):,} |",
             f"| Reconstrucciones con prueba aprobada | {sum(bool(e['reconstruction_validated']) for e in entries):,} |", "",
             f"Hay {len(entries):,} entradas por propietario y RVA, correspondientes a {len({int(e['rva'],16) for e in entries}):,} destinos únicos con pruebas acotadas. Este catálogo no es un inventario exhaustivo del EXE. Los auxiliares [NOTIV](hooks_notiv.csv) quedan fuera del progreso de clases.", "",
             "## Vista general", "",
             "| Sin revertir | Parcialmente revertidas | Completamente revertidas | Desconocido |",
             "| :---: | :---: | :---: | :---: |",
             f"| **{unreversed:,}** | **{count}** | **0** | **{unknown:,}** |", "",
             "**Ir a:** [Sin revertir](#sin-revertir) · [Parcialmente revertidas](#parciales) · [Completamente revertidas](#completas) · [Desconocido](#desconocido) · [Cómo leer y actualizar](#metodo)", "",
             "> [!NOTE]", "> Una llamada comprobada al original, un retorno simple probado y una dirección virtual coincidente no convierten una clase en parcialmente revertida. No se declara completa ninguna clase sin un inventario exhaustivo de sus métodos.", ""]
    sdk_counts = {sdk: sum(sdk in references.get(row["name"], ()) for row in classes) for sdk in ("IV-SDK", "plugin_IV", "IV-SDK.Net")}
    lines += ["## Referencias de nombres (SDKs)", "",
              "📚 marca las clases que alguna referencia declara con direcciones de métodos o campos: [IV-SDK](../contrib/IV%20SDK/IV-SDK-main), [plugin_IV](MemoryMap/PluginIvPatterns.md) e [IV-SDK.Net](MemoryMap/sdknet_addresses.csv). "
              "Son pistas no validadas; el EXE canónico decide. Cruce de offsets de campos: [SdkCrossReference.md](MemoryMap/SdkCrossReference.md). Los nombres por dirección de función se anotan en la columna `reference_names` de [hooks.csv](hooks.csv).", "",
              "| Referencia | Clases del inventario con entradas |", "| --- | ---: |"]
    lines += [f"| {sdk} | {count:,} |" for sdk, count in sdk_counts.items()]
    lines += [""]
    for anchor, title, icon in (("sin-revertir", "Sin revertir", "🔴"), ("parciales", "Parcialmente revertidas", "🟡"), ("completas", "Completamente revertidas", "🟢"), ("desconocido", "Desconocido", "⚪")):
        rows = groups[anchor]
        lines += [f'<a id="{anchor}"></a>', f"## {icon} {title} · {len(rows):,} clases", ""]
        if anchor == "desconocido":
            game_unknown = sum(row["file"].startswith("source/game/") for row in rows)
            rage_unknown = sum(row["file"].startswith("source/rage/") for row in rows)
            lines += [f"Estos headers provienen de los nombres y descriptores RTTI registrados en [classes.csv](MemoryMap/classes.csv). Se conoce la identidad del tipo y la dirección de su descriptor; no hay destinos de métodos asociados en el inventario actual. No implica que el tipo carezca de métodos. Este grupo incluye {game_unknown} headers de game y {rage_unknown} de rage sin referencias conocidas. [Análisis de tipos sin métodos](../reversing/UnknownTypesAnalysis/README.md).", ""]
        if not rows:
            lines += ["Ninguna clase en esta categoría.", ""]
            continue
        lines += ["Orden alfabético por columna. Entre paréntesis: destinos conocidos distintos; R: reconstruidos; ✅: reconstrucciones con prueba aprobada.", "", "<details>", f"<summary>Mostrar catálogo de clases {title.lower()}</summary>", "", "| Clase (destinos) | Clase (destinos) | Clase (destinos) |", "| --- | --- | --- |"]
        height = (len(rows) + 2) // 3
        for index in range(height):
            cells = []
            for column in range(3):
                position = index + column * height
                if position >= len(rows):
                    cells.append("")
                    continue
                row = rows[position]
                name = row["name"]
                label = name.replace("|", "&#124;").replace("[", "&#91;").replace("]", "&#93;").replace("<", "&lt;").replace(">", "&gt;")
                cells.append(f"[{label}](../{row['file']}) ({len(known[name])}) · R {len(reconstructed[name])}" + (f" · ✅ {len(validated[name])}" if validated[name] else "") + (f" · 📚 {', '.join(sorted(references[name]))}" if references.get(name) else ""))
            lines.append("| " + " | ".join(cells) + " |")
        lines += ["", "</details>", ""]
    lines += ["## Funciones fuera del inventario de clases", "", "`rage::atStringHash` está reconstruida y tiene evidencia de comparación. El propietario `rage` es un espacio de nombres, no una clase RTTI; por eso no se clasifica todo el motor como parcialmente revertido.", "", "[Implementación](../source/rage/AtStringHash.h) · [Evidencia](../reversing/AtStringHash/evidence/validation-summary.json)", "", '<a id="metodo"></a>', "## Cómo leer y actualizar", "", "- **Desconocido:** tipo identificado por RTTI, sin direcciones de métodos asociadas. La reconstrucción todavía no puede medirse.", "- **Sin revertir:** ninguna función registrada como reconstruida. Puede tener direcciones y llamadas al original comprobadas.", "- **Parcialmente revertida:** tiene al menos una función reconstruida y todavía no se acredita la reconstrucción completa de la clase.", "- **Completamente revertida:** todos los métodos de un inventario exhaustivo están reconstruidos. El inventario actual no permite acreditar esta categoría.", "- `reversed=1` mide reconstrucción; `reconstruction_validated=1` acredita la prueba de esa reconstrucción. `validated=1` también puede acreditar solo una llamada al original. Los porcentajes no miden estabilidad del juego ni vigencia completa del ASI.", "", "Actualizar el catálogo y regenerar con `python reversing/HookRegistry/generate.py`. El detalle de direcciones, fuentes, pruebas y alcance permanece en [hooks.csv](hooks.csv) y [Clases y hooks](MemoryMap/ClassesAndHooks.md).", ""]
    (root / "docs/ReversedClasses.md").write_text("\n".join(lines), encoding="utf-8")
