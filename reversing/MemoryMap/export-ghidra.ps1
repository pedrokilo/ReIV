param([string]$GhidraDirectory)
$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
if (!$GhidraDirectory) { $GhidraDirectory = Join-Path $repoRoot 'build\tools\ghidra_12.1.4_PUBLIC' }
$headless = Join-Path $GhidraDirectory 'support\analyzeHeadless.bat'
if (!(Test-Path -LiteralPath $headless)) { throw 'Indica una instalación de Ghidra con -GhidraDirectory.' }
& $headless (Join-Path $repoRoot 'build\ghidra-project') ReIV1070 -process GTAIV.exe -noanalysis -readOnly -scriptPath $PSScriptRoot -postScript ExportMemoryInventory.java (Join-Path $repoRoot 'build\memory-map') -log (Join-Path $repoRoot 'build\memory-map-export.log')
if ($LASTEXITCODE -ne 0) { throw 'Falló la exportación del inventario de Ghidra.' }
