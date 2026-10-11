# Herramientas de ReIV (C#)

Toda herramienta nueva del proyecto, además del código del juego en C++, se escribe **únicamente en C#**. Los scripts de Python y PowerShell que ya existían se conservan hasta portarlos.

## ReIV.Tools

Proyecto `tools/ReIV.Tools/ReIV.Tools.csproj` (.NET Framework 4.5, sin dependencias). Se compila con el MSBuild de Visual Studio:

```powershell
& "$(& "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe" -latest -products '*' -property installationPath)\MSBuild\Current\Bin\MSBuild.exe" tools/ReIV.Tools/ReIV.Tools.csproj /p:Configuration=Release /v:minimal
bin\tools\ReIV.Tools.exe          # all
bin\tools\ReIV.Tools.exe provenance
bin\tools\ReIV.Tools.exe progress
```

| Comando | Genera |
| --- | --- |
| `provenance` | [FunctionClassification.md](../docs/MemoryMap/FunctionClassification.md) y `function_classification.csv`: **clasificación de funciones binarias** (*Binary Function Classification*) de cada entrada de código del EXE por procedencia y estado de reversión. [DependencyProvenance.md](../docs/MemoryMap/DependencyProvenance.md) y `dependency_provenance.csv`: **análisis de procedencia de dependencias** (*Dependency Provenance Analysis*) de los cuerpos de CPlayerPed. |
| `progress` | [ReversedClasses.md](../docs/ReversedClasses.md), con la estructura de ReSA y este orden: completamente revertidas, parcialmente revertidas, sin revertir, desconocido. |

Ejecutar siempre después de `python reversing/HookRegistry/generate.py`, que produce `docs/hooks.csv`. Una clase solo cuenta como completamente revertida si figura en `reversing/HookRegistry/exhaustive-classes.txt` (inventario exhaustivo acreditado) y todo lo conocido está reconstruido.
