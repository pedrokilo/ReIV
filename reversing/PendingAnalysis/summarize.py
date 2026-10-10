"""Join static observations and runtime facts without conflating their scopes."""
import csv
import hashlib
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def rows(path):
    with (ROOT / path).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def main():
    refs = rows("docs/MemoryMap/pending_hooks.csv")
    lookup = {}
    for path, key in (("reversing/PendingAnalysis/game/targets.json", "untested_reason"), ("reversing/PendingAnalysis/rage-art/evidence/inventory.json", "classification")):
        for row in json.loads((ROOT / path).read_text()):
            lookup[int(row["rva"], 16)] = (row[key], path)
    boundaries = {int(row["rva"], 16): row for row in rows("reversing/PendingAnalysis/evidence/ghidra/functions.csv")}
    fresh = {int(row["address"], 16)-0x400000 for row in rows("reversing/PendingAnalysis/evidence/fresh-ghidra-procedures.csv") if row["address"].startswith("0x")}
    decompiled = {}
    for path in sorted((ROOT / "reversing/PendingAnalysis/evidence/decompilation").glob("batch-*.json")):
        result = json.loads(path.read_text())
        for item in result["result"]["items"]:
            decompiled[int(item["address"], 16)-0x400000] = (item["status"], path.relative_to(ROOT).as_posix())
    output = []
    for ref in refs:
        rva = int(ref["rva"], 16)
        classification, static_source = lookup.get(rva, ("no_new_entry_analysis", ""))
        boundary = boundaries.get(rva, {})
        output.append(dict(ref, static_entry_classification=classification, static_source=static_source,
            boundary_status=boundary.get("status", "not_in_initial_pending_export"),
            direct_calls_in_known_body=boundary.get("direct_calls", ""),
            indirect_calls_in_known_body=boundary.get("indirect_calls", ""),
            fresh_ghidra_entry=int(rva in fresh),
            decompilation_status=decompiled.get(rva, ("not_in_initial_pending_batch", ""))[0],
            decompilation_evidence=decompiled.get(rva, ("", ""))[1],
            analysis_complete=0))
    with (ROOT / "docs/MemoryMap/pending_analysis.csv").open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(output[0])); writer.writeheader(); writer.writerows(output)
    coverage = []
    for name, prefix in (("game", "source/game/"), ("rage", "source/rage/"), ("ART", "source/external/ART/")):
        selected = [ref for ref in refs if ref["file"].startswith(prefix)]
        untested = [ref for ref in selected if ref["runtime_reference_tested"] == "0"]
        fatal = [ref for ref in untested if int(ref["rva"], 16) == 0x1210]
        excluded = [ref for ref in untested if ref["label"] == "excluded_runtime_vtable_mismatch"]
        coverage.append(dict(folder=name, references=len(selected), checked_references=len(selected)-len(untested), fatal_references=len(fatal), rejected_references=len(excluded), untested_nonfatal_references=len(untested)-len(fatal)-len(excluded), untested_targets=len({int(ref["rva"],16) for ref in untested})))
    names = {ref["owner"] for ref in refs}
    unknown = [row for row in rows("source/class-files.csv") if row["name"] not in names]
    sha = hashlib.sha256(Path(r"D:/GTA IV/Grand Theft Auto IV/GTAIV.exe").read_bytes()).hexdigest()
    summary = dict(exe_sha256=sha, coverage=coverage, unknown_remaining=len(unknown), unknown_by_folder=dict(Counter(row["file"].split('/')[1] for row in unknown)), ghidra_boundaries=dict(Counter(row["status"] for row in boundaries.values())), fresh_entries_in_initial_pending=sum(rva in fresh for rva in boundaries), decompiled_results=dict(Counter(item[0] for item in decompiled.values())), complete_analysis_claimed=False)
    (ROOT / "reversing/PendingAnalysis/evidence/summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    lines = ["# Análisis de pendientes y pruebas adicionales", "", "Esta pasada revisa el inventario de pendientes y ejecuta solamente cuerpos completos con efectos locales comprobables. **No completa el análisis funcional ni las pruebas de todas las funciones complejas.**", "", "## Pruebas nuevas", "", "- Game: 148 direcciones, 9.472 llamadas. [Resultado](../../reversing/PendingAnalysis/game/evidence/runtime-summary.json).", "- Rage/ART: 83 direcciones (las 83 de rage), 5.312 llamadas. [Resultado](../../reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json).", "- Los dos bancos terminaron sin fallos ni excepciones, con salida normal del juego y consola visible. No reconstruyen las clases ni activan hooks pendientes.", "- Para RVA `0x001BDC60` se comprueba únicamente EAX y la memoria: el cuerpo también escribe EDX y su retorno completo permanece sin confirmar.", "", "## Cobertura actual", "", "| Carpeta | Referencias | Llamadas comprobadas (referencias) | Fatal excluido | Tablas discrepantes excluidas | Restantes sin llamada | Destinos sin llamada, incluido fatal |", "| --- | ---: | ---: | ---: | ---: | ---: | ---: |"]
    for row in coverage:
        lines.append("| " + " | ".join(str(row[key]) for key in ("folder", "references", "checked_references", "fatal_references", "rejected_references", "untested_nonfatal_references", "untested_targets")) + " |")
    lines += ["", "Las referencias pueden compartir una misma dirección. Estos totales no equivalen a clases reconstruidas ni a funciones independientes. [Detalle por referencia](pending_analysis.csv).", "", "## Análisis estático y límites", "", "[Game](../../reversing/PendingAnalysis/game/README.md) clasifica sus 5.719 destinos iniciales. [Rage/ART](../../reversing/PendingAnalysis/rage-art/README.md) clasifica 3.354 destinos pendientes distintos. Incluyen bytes de entrada, llamadas observadas y motivos concretos para no ejecutar. Fuera de los cuerpos completos reconocidos, el análisis se limita a un tramo de entrada y no recupera todo el flujo de control.", "", "La exportación del proyecto Ghidra existente revisó 8.377 direcciones iniciales: 3.809 tienen una función delimitada, 4.557 carecen de límite definido y 11 caen dentro de otra función. Para las funciones delimitadas se exportaron rangos de cuerpo y dependencias directas/indirectas. Son resultados del proyecto guardado: sus firmas inferidas no están verificadas y la ausencia de límites no prueba ausencia de código. [Funciones](../../reversing/PendingAnalysis/evidence/ghidra/functions.csv) · [Dependencias](../../reversing/PendingAnalysis/evidence/ghidra/dependencies.csv).", "", "## Tipos desconocidos", "", f"Se investigaron los 585 tipos originales. Se recuperaron seis callbacks de metadatos de excepciones MSVC pertenecientes a cuatro tipos; se añadieron a sus headers como direcciones estáticas, sin llamar ni reconstruir. Ahora quedan **{len(unknown)} desconocidos**: {summary['unknown_by_folder'].get('game',0)} de game y {summary['unknown_by_folder'].get('rage',0)} de rage. [Análisis reproducible](../../reversing/UnknownTypesAnalysis/README.md).", "", "578 tipos figuran como bases y siete solo tenían descriptores. El escaneo no encontró tablas virtuales propias omitidas. Una relación de herencia no permite adjudicar a la base métodos de una clase derivada. Para seguir hacen falta referencias de constructores/destructores y usos concretos de objetos, no direcciones inventadas.", "", "## Manejador fatal", "", "RVA `0x00001210` llama al helper `0x005A8CB0`. La evidencia muestra `MessageBoxW` y una escritura en dirección cero, seguida de una posible salida. Se utiliza para tratar un error irrecuperable; invocarlo deliberadamente puede terminar el proceso. Sus referencias permanecen excluidas. [Cuerpo](../../reversing/NMutils/evidence/00401210.txt) · [Helper](../../reversing/NMutils/evidence/005a8cb0.txt).", "", "## Qué sigue sin resolver", "", "Las funciones complejas requieren delimitar sus cuerpos, recuperar firmas y layouts, revisar sus llamadas y establecer cuándo existen objetos válidos. Las lecturas de punteros, globals/TLS, constructores, destructores y saltos indirectos no se probaron con objetos inventados. Las exclusiones fatales se conservan; ninguna prueba habilita automáticamente un hook.", "", "Regenerar esta ficha y el CSV con `python reversing/PendingAnalysis/summarize.py`, después de los headers y del catálogo. Los bancos se repiten con `reversing/PendingAnalysis/game/run.ps1` y `reversing/PendingAnalysis/rage-art/run.ps1`.", ""]
    (ROOT / "docs/MemoryMap/PendingAnalysis.md").write_text("\n".join(lines), encoding="utf-8")
    document = ROOT / "docs/MemoryMap/PendingAnalysis.md"
    with document.open("a", encoding="utf-8") as stream:
        stream.write(f"\n## Reanálisis nuevo de Ghidra\n\nEl nuevo análisis REA/Ghidra del mismo EXE reconoce {summary['fresh_entries_in_initial_pending']:,} de las 8.377 direcciones pendientes iniciales como entradas. Se guardaron {sum(item[0]=='ok' for item in decompiled.values()):,} resultados de decompilación con evidencia. Esto mejora el proyecto histórico, pero el pseudocódigo no es una firma aprobada, una reconstrucción ni una llamada probada. Los 23 destinos iniciales restantes requieren revisar referencias o límites. Los seis callbacks EH recuperados después están fuera del banco inicial. [Entradas nuevas](../../reversing/PendingAnalysis/evidence/fresh-ghidra-procedures.csv) · [Evidencia](../../reversing/PendingAnalysis/evidence/fresh-ghidra-evidence.json) · [Pseudocódigo por lotes](../../reversing/PendingAnalysis/evidence/decompilation).\n")
        if (ROOT / "reversing/PendingAnalysis/evidence/installation.json").exists():
            stream.write("\n## Compilación e instalación\n\nPasaron Release/Win32 y la comprobación sintáctica de los 4.016 headers. Se instaló el ASI final en la copia del juego con respaldo, consola automática y sin marcadores de prueba activos. [Registro de instalación](../../reversing/PendingAnalysis/evidence/installation.json).\n")
    print(json.dumps(summary))


if __name__ == "__main__":
    main()
