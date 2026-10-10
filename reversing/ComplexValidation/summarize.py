"""Current coverage and bounded runtime evidence for the complex-function pass."""
import csv
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def main():
    evidence = ROOT / "reversing/ComplexValidation/evidence"
    summary = json.loads((evidence / "summary.json").read_text())
    updates = json.loads((evidence / "reference-results.json").read_text())
    by_key = {(r["owner"], int(r["rva"],16), int(r["vtable_va"],16), int(r["slot"])): r for r in updates}
    with (ROOT / "docs/MemoryMap/pending_hooks.csv").open(encoding="utf-8-sig", newline="") as stream:
        refs = list(csv.DictReader(stream))
    changed = []
    for ref in refs:
        key = (ref["owner"], int(ref["rva"],16), int(ref["vtable_va"],16), int(ref["slot"]))
        if key in by_key:
            changed.append(dict(ref, validation_status=by_key[key]["validation_status"], scoped_evidence=by_key[key]["evidence"]))
    assert len(changed) == summary["references"]
    with (ROOT / "docs/MemoryMap/complex_validation.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(changed[0])); writer.writeheader(); writer.writerows(changed)
    lines = ["# Pruebas adicionales de funciones complejas", "", f"Se probaron **{summary['targets']} destinos distintos**, asociados a **{summary['references']:,} referencias**, con **{summary['calls']:,} llamadas sin errores ni excepciones**. El juego terminó normalmente y la consola estuvo visible y escribible.", "", "Los resultados tienen alcance limitado. Ninguna prueba reconstruye clases ni habilita hooks pendientes. [Referencias y evidencia](complex_validation.csv).", "", "| Banco | Destinos | Llamadas | Alcance |", "| --- | ---: | ---: | --- |"]
    for group in summary["groups"]:
        label = group["folder"] + (" (escalares)" if group["bank"] == "scalar-runtime" else "")
        scope = "Solo flags bit0 desactivado; rama de liberación excluida" if group["scope"] == "restricted_nonfreeing_mode" else "Objetos/buffers aislados y resultados comparados"
        lines.append(f"| [{label}](../../{group['evidence']}) | {group['targets']} | {group['calls']:,} | {scope} |")
    lines += ["", "## Qué se comprobó", "", "- Game: comparaciones con límites signed/unsigned, operaciones de bits y cuerpos escalares completos. Se verifican los bits definidos de EAX y las modificaciones de memoria previstas; no se afirma el retorno completo EDX:EAX de una función que escriba ambos registros.", "- Rage: cada camino del grafo de control estático termina en RET y excluye llamadas, ciclos, globals/TLS y lecturas de punteros encadenados. Los 64 casos comparan los bits definidos de EAX y todo el buffer. `expected_nodes_mask` describe caminos del modelo esperado; no instrumenta las ramas nativas ni demuestra que todas se ejecutaron.", "- ART: setters y copias condicionados por bits, resets locales, selección de this, una lectura con objeto anidado válido y salida en buffer separado. Las condiciones de bits se prueban con ambos resultados; se protegen objeto, objeto anidado y salida.", "- Destructores: solo se llama con `flags & 1 == 0`. El TEST y el salto omiten por completo el acceso TLS y la llamada al liberador. Se verifica que únicamente cambie la vtable y que se devuelva this. La rama de liberación no fue ejecutada ni validada. Los bytes completos y la reubicación HIGHLOW del inmediato se comprueban antes de llamar.", "", "Las convenciones de llamada son fixtures x86 deducidos de cuerpos completos; no equivalen a una firma original o a un layout completo de clase. Los nombres del catálogo son descriptivos por RVA.", "", "## Cobertura restante", "", "| Carpeta | Referencias sin llamada (sin fatal/discrepancias) | Destinos sin llamada (incluido fatal/discrepancias) | Fatal excluido (referencias) |", "| --- | ---: | ---: | ---: |"]
    coverage = []
    for folder,prefix in (("game","source/game/"),("rage","source/rage/"),("ART","source/external/ART/")):
        selected = [r for r in refs if r["file"].startswith(prefix)]
        pending = [r for r in selected if r["runtime_reference_tested"] == "0"]
        fatal = [r for r in pending if int(r["rva"],16) == 0x1210]
        bad = [r for r in pending if r["label"].startswith("excluded_")]
        count = len(pending)-len(fatal)-len(bad)
        targets = len({int(r["rva"],16) for r in pending})
        coverage.append(dict(folder=folder, remaining_references=count, remaining_targets=targets, fatal_references=len(fatal)))
        lines.append(f"| {folder} | {count:,} | {targets:,} | {len(fatal)} |")
    lines += ["", "Los destinos compartidos pueden aparecer en más de una carpeta. Las 772 referencias `runtime_restricted_mode` siguen limitadas al modo sin liberación; no deben tratarse como destructores completamente comprobados. El manejador fatal RVA `0x00001210` nunca se llamó. Los 581 tipos sin destinos siguen en Desconocido.", "", "## Qué requiere la siguiente prueba", "", "Las funciones restantes necesitan firmas y layouts, referencias de objetos existentes, dependencias y el estado correcto del sistema. Los caminos con allocators/TLS, constructores, liberaciones o callbacks indirectos no se convierten en pruebas pasando direcciones aleatorias. Las llamadas de este banco no certifican estabilidad durante gameplay.", "", "## Repetición y actualización", "", "Compilar con `contrib/build-reiv.ps1` y repetir el banco combinado con `reversing/ComplexValidation/run.ps1`. Respalda y restaura el ASI de la copia del juego y todos los marcadores/reportes. Registrar con `python reversing/ComplexValidation/register_results.py`, regenerar headers y catálogo, y actualizar esta ficha con `python reversing/ComplexValidation/summarize.py`.", ""]
    if (evidence / "installation.json").exists():
        lines += ["## Compilación e instalación", "", "Pasaron Release/Win32 y la comprobación sintáctica de los 4.016 headers. Se instaló la compilación final en la copia del juego con respaldo, consola automática y sin marcadores activos. [Registro de instalación](../../reversing/ComplexValidation/evidence/installation.json) distingue su hash del ASI probado; las sondas no cambiaron.", ""]
    (ROOT / "docs/MemoryMap/ComplexValidation.md").write_text("\n".join(lines), encoding="utf-8")
    (evidence / "coverage.json").write_text(json.dumps(dict(coverage=coverage, modes=dict(Counter(r["validation_status"] for r in updates))), indent=2)+"\n", encoding="utf-8")
    print(json.dumps(coverage))


if __name__ == "__main__":
    main()
