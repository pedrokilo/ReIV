param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$gameRoot = [IO.Path]::GetFullPath($GameDirectory)
$gameExe = Join-Path $gameRoot 'GTAIV.exe'
if ((Get-FileHash -LiteralPath $gameExe).Hash -ne 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c') { throw 'EXE no canónico' }
if (Get-Process GTAIV -ErrorAction SilentlyContinue) { throw 'Ya hay un GTAIV abierto' }
$marker = Join-Path $gameRoot 'ReIV.original-calls-test'
if ((Test-Path -LiteralPath $marker) -or (Test-Path -LiteralPath (Join-Path $gameRoot 'ReIV.validation-test'))) { throw 'Ya existe un marcador de prueba' }
$runDir = Join-Path $repoRoot ('reversing\artifacts\GetBoneMatrix-' + (Get-Date -Format 'yyyyMMdd-HHmmss'))
New-Item -ItemType Directory -Path $runDir | Out-Null
$protected = @('XLivelessAddon.ini','ReIV.asi','ReIV.pdb','ReIV.log','ReIV-atStringHash.json','ReIV-GetBoneMatrix.json','GTAIV_d3d9.log','ReIV-runtime-hooks.csv','ReIV.debug-console','ReIV-debug-console.json')
$existing = @()
foreach ($name in $protected) {
    $path = Join-Path $gameRoot $name
    if (Test-Path -LiteralPath $path) { Copy-Item -LiteralPath $path -Destination (Join-Path $runDir $name); $existing += $name }
}
$process = $null
$forced = $false
try {
    foreach ($name in @('ReIV.log','ReIV-atStringHash.json','ReIV-GetBoneMatrix.json','GTAIV_d3d9.log','ReIV-debug-console.json')) {
        $path = [IO.Path]::GetFullPath((Join-Path $gameRoot $name))
        if (!$path.StartsWith($gameRoot + '\',[StringComparison]::OrdinalIgnoreCase)) { throw 'Ruta fuera de la copia' }
        if (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path }
    }
    Copy-Item -LiteralPath (Join-Path $repoRoot 'bin\ReIV.asi'),(Join-Path $repoRoot 'bin\ReIV.pdb') -Destination $gameRoot -Force
    $saves = Join-Path $runDir 'saves'
    $settings = Join-Path $runDir 'settings'
    New-Item -ItemType Directory -Path $saves,$settings | Out-Null
    $iniPath = Join-Path $gameRoot 'XLivelessAddon.ini'
    $ini = [IO.File]::ReadAllText($iniPath)
    $ini = [regex]::Replace($ini,'(?m)^SkipMenu\s*=.*$','SkipMenu = 1')
    $ini = [regex]::Replace($ini,'(?m)^CustomSavePath\s*=.*$',('CustomSavePath = "' + $saves + '\"'))
    $ini = [regex]::Replace($ini,'(?m)^CustomSettingsPath\s*=.*$',('CustomSettingsPath = "' + $settings + '\"'))
    [IO.File]::WriteAllText($iniPath,$ini,[Text.UTF8Encoding]::new($false))
    [IO.File]::WriteAllText($marker,'GetBoneMatrix probe: root bone on the live player, 64 samples, orderly close.')
    $process = Start-Process -FilePath $gameExe -WorkingDirectory $gameRoot -ArgumentList '-windowed -width 800 -height 600' -WindowStyle Normal -PassThru
    Write-Output ('Started test PID ' + $process.Id)
    $deadline = (Get-Date).AddSeconds(240)
    while (!$process.WaitForExit(10000)) {
        if ((Get-Date) -gt $deadline) { $forced = $true; Stop-Process -Id $process.Id; $process.WaitForExit(); break }
        $reportPath = Join-Path $gameRoot 'ReIV-GetBoneMatrix.json'
        if (Test-Path -LiteralPath $reportPath) { Write-Output ([IO.File]::ReadAllText($reportPath)) }
    }
    foreach ($name in @('ReIV.log','ReIV-atStringHash.json','ReIV-GetBoneMatrix.json','GTAIV_d3d9.log','ReIV-runtime-hooks.csv','ReIV-debug-console.json')) {
        $path = Join-Path $gameRoot $name
        if (Test-Path -LiteralPath $path) { Copy-Item -LiteralPath $path -Destination (Join-Path $runDir ('result-' + $name)) }
    }
    $report = Get-Content -LiteralPath (Join-Path $runDir 'result-ReIV-GetBoneMatrix.json') -Raw | ConvertFrom-Json
    $consoleReport = Get-Content -LiteralPath (Join-Path $runDir 'result-ReIV-debug-console.json') -Raw | ConvertFrom-Json
    $hashReport = Get-Content -LiteralPath (Join-Path $runDir 'result-ReIV-atStringHash.json') -Raw | ConvertFrom-Json
    $hashPassed = $hashReport.hooked -and $hashReport.bank_pairs -eq 8320 -and $hashReport.bank_failures -eq 0 -and $hashReport.runtime_pairs -eq 4096 -and $hashReport.runtime_failures -eq 0 -and $hashReport.phase -eq 'process_detach'
    $passed = !$forced -and $process.ExitCode -eq 0 -and $report.phase -eq 'passed' -and $report.calls -eq 64 -and $report.failures -eq 0 -and $report.exceptions -eq 0 -and $report.game_loaded -and $consoleReport.visible -and $consoleReport.writable -and $hashPassed
    $summary = [ordered]@{ date=(Get-Date -Format o); passed=$passed; forced_stop=$forced; exit_code=$process.ExitCode; exe_sha256=(Get-FileHash -LiteralPath $gameExe).Hash.ToLower(); asi_sha256=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'bin\ReIV.asi')).Hash.ToLower(); wrapper_sha256=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'source\game\scene\CDynamicEntity.cpp')).Hash.ToLower(); probe_sha256=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'source\hooks\GetBoneMatrixProbe.h')).Hash.ToLower(); result=$report; evidence_directory=$runDir }
    $summary['console'] = $consoleReport
    $summary['atStringHash'] = $hashReport
    $summary['atStringHash_passed'] = $hashPassed
    $summary | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $runDir 'summary.json') -Encoding UTF8
    $summary | ConvertTo-Json -Depth 6
    if (!$passed) { throw 'GetBoneMatrix no aprobó la prueba en juego.' }
} finally {
    if ($process -and !$process.HasExited) { Stop-Process -Id $process.Id; $process.WaitForExit() }
    foreach ($name in $existing) { Copy-Item -LiteralPath (Join-Path $runDir $name) -Destination (Join-Path $gameRoot $name) -Force }
    foreach ($name in $protected) {
        $path = [IO.Path]::GetFullPath((Join-Path $gameRoot $name))
        if (!$path.StartsWith($gameRoot + '\',[StringComparison]::OrdinalIgnoreCase)) { throw 'Ruta fuera de la copia' }
        if ($name -notin $existing -and (Test-Path -LiteralPath $path)) { Remove-Item -LiteralPath $path }
    }
    if (Test-Path -LiteralPath $marker) { Remove-Item -LiteralPath $marker }
}
