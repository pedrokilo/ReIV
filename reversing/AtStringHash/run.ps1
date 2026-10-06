param(
    [string]$GameDirectory = 'C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV - copia'
)
$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$gameExe = Join-Path $GameDirectory 'GTAIV.exe'
if ((Get-FileHash -LiteralPath $gameExe).Hash -ne 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c') { throw 'EXE no canónico' }
if (Get-Process GTAIV -ErrorAction SilentlyContinue) { throw 'Ya hay un GTAIV abierto' }
$runDir = Join-Path $repoRoot ('reversing\artifacts\atStringHash-' + (Get-Date -Format 'yyyyMMdd-HHmmss'))
New-Item -ItemType Directory -Path $runDir | Out-Null
$protectedNames = @('XLivelessAddon.ini','commandline.txt','ReIV.asi','ReIV.pdb','ReIV.log','ReIV-atStringHash.json')
$existingNames = @()
foreach ($name in $protectedNames) {
    $path = Join-Path $GameDirectory $name
    if (Test-Path -LiteralPath $path) { Copy-Item -LiteralPath $path -Destination (Join-Path $runDir $name); $existingNames += $name }
}
$marker = Join-Path $GameDirectory 'ReIV.validation-test'
if (Test-Path -LiteralPath $marker) { throw 'Ya existe un marcador de prueba' }
$probeProcess = $null
$forcedStop = $false
$exitCode = $null
try {
    Copy-Item -LiteralPath (Join-Path $repoRoot 'bin\ReIV.asi'),(Join-Path $repoRoot 'bin\ReIV.pdb') -Destination $GameDirectory
    $isolatedSaves = Join-Path $runDir 'saves'
    $isolatedSettings = Join-Path $runDir 'settings'
    New-Item -ItemType Directory -Path $isolatedSaves,$isolatedSettings | Out-Null
    $iniPath = Join-Path $GameDirectory 'XLivelessAddon.ini'
    $ini = [System.IO.File]::ReadAllText($iniPath)
    $ini = [regex]::Replace($ini,'(?m)^SkipMenu\s*=.*$','SkipMenu = 1')
    $ini = [regex]::Replace($ini,'(?m)^CustomSavePath\s*=.*$',('CustomSavePath = "' + $isolatedSaves + '\"'))
    $ini = [regex]::Replace($ini,'(?m)^CustomSettingsPath\s*=.*$',('CustomSettingsPath = "' + $isolatedSettings + '\"'))
    [System.IO.File]::WriteAllText($iniPath,$ini,[System.Text.UTF8Encoding]::new($false))
    [System.IO.File]::WriteAllText($marker,'Test-only close request after 20 seconds of script processing.')
    $probeProcess = Start-Process -FilePath $gameExe -WorkingDirectory $GameDirectory -ArgumentList '-windowed -width 800 -height 600' -WindowStyle Normal -PassThru
    $finished = $probeProcess.WaitForExit(120000)
    if (!$finished) { $forcedStop = $true; Stop-Process -Id $probeProcess.Id; $probeProcess.WaitForExit() }
    $exitCode = $probeProcess.ExitCode
    foreach ($name in @('ReIV.log','ReIV-atStringHash.json','GTAIV_d3d9.log')) {
        $path = Join-Path $GameDirectory $name
        if (Test-Path -LiteralPath $path) { Copy-Item -LiteralPath $path -Destination (Join-Path $runDir ('result-' + $name)) }
    }
    $report = Get-Content -LiteralPath (Join-Path $runDir 'result-ReIV-atStringHash.json') -Raw | ConvertFrom-Json
    $passed = !$forcedStop -and $exitCode -eq 0 -and $report.bank_failures -eq 0 -and $report.runtime_failures -eq 0 -and $report.hooked -and $report.hook_calls -gt 1 -and $report.game_loaded -and $report.ingame_started -and $report.script_ticks -gt 1
    $summary = [ordered]@{
        date = (Get-Date -Format o); exe_sha256 = (Get-FileHash $gameExe).Hash.ToLower()
        asi_sha256 = (Get-FileHash (Join-Path $repoRoot 'bin\ReIV.asi')).Hash.ToLower()
        implementation_sha256 = (Get-FileHash (Join-Path $repoRoot 'source\AtStringHash.h')).Hash.ToLower()
        probe_sha256 = (Get-FileHash (Join-Path $repoRoot 'source\AtStringHashProbe.h')).Hash.ToLower()
        pid = $probeProcess.Id; exit_code = $exitCode; forced_stop = $forcedStop; passed = $passed; result = $report
    }
    $summary | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $runDir 'summary.json') -Encoding UTF8
    $summary | ConvertTo-Json -Depth 6
    Write-Output ('Evidence: ' + $runDir)
} finally {
    if ($probeProcess -and !$probeProcess.HasExited) { Stop-Process -Id $probeProcess.Id }
    foreach ($name in $existingNames) { Copy-Item -LiteralPath (Join-Path $runDir $name) -Destination (Join-Path $GameDirectory $name) -Force }
    if (Test-Path -LiteralPath $marker) { Remove-Item -LiteralPath $marker }
}
