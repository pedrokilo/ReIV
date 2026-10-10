param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference = 'Stop'
$repoPath = Split-Path (Split-Path (Split-Path $PSScriptRoot -Parent) -Parent) -Parent
$markerPath = Join-Path $GameDirectory 'ReIV.pending-scalar-test'
$reportPath = Join-Path $GameDirectory 'ReIV-pending-scalar.json'
if (Test-Path -LiteralPath $markerPath) { throw 'Marcador de escrituras existente' }
foreach ($name in @('ReIV.rage-test','ReIV.rage-fixtures-test','ReIV.rage-writes-test','ReIV.art-test','ReIV.art-fixtures-test','ReIV.art-extras-test','ReIV.game-stubs-test','ReIV.audio-fixtures-test','ReIV.animation-fixtures-test')) {
    if (Test-Path -LiteralPath (Join-Path $GameDirectory $name)) { throw ('Otro banco activo: '+$name) }
}
$backup = if (Test-Path -LiteralPath $reportPath) { [IO.File]::ReadAllBytes($reportPath) } else { $null }
try {
    if (Test-Path -LiteralPath $reportPath) { Remove-Item -LiteralPath $reportPath }
    [IO.File]::WriteAllText($markerPath,'Controlled isolated memory write validation')
    & (Join-Path $PSScriptRoot '../../OriginalCalls/run.ps1') -GameDirectory $GameDirectory
    $runPath = (Get-ChildItem -LiteralPath (Join-Path $repoPath 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*' | Sort-Object LastWriteTime -Descending | Select-Object -First 1).FullName
    $gameSummary = Get-Content -LiteralPath (Join-Path $runPath 'summary.json') -Raw | ConvertFrom-Json
    $result = Get-Content -LiteralPath $reportPath -Raw | ConvertFrom-Json
    $destination = Join-Path $PSScriptRoot 'evidence'
    [IO.Directory]::CreateDirectory($destination) | Out-Null
    Copy-Item -LiteralPath $reportPath -Destination (Join-Path $destination 'runtime-report.json') -Force
    Copy-Item -LiteralPath (Join-Path $runPath 'result-ReIV.log') -Destination (Join-Path $destination 'runtime.log') -Force
    $passed = $gameSummary.passed -and $result.phase -eq 'passed' -and $result.exceptions -eq 0 -and @($result.entries).Count -eq @((Get-Content -LiteralPath (Join-Path $PSScriptRoot 'evidence/fixture-scope.json') -Raw | ConvertFrom-Json)).Count -and @($result.entries | Where-Object { $_.failures -ne 0 -or $_.calls -ne 64 }).Count -eq 0
    $summary = [ordered]@{passed=$passed;date=$gameSummary.date;exe_sha256=$gameSummary.exe_sha256;asi_sha256=$gameSummary.asi_sha256;implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath 'source/hooks/PendingScalarProbe.h')).Hash.ToLower();scope_sha256=(Get-FileHash -LiteralPath (Join-Path $PSScriptRoot 'evidence/fixture-scope.json')).Hash.ToLower();result=$result;game_run=$gameSummary}
    $summary | ConvertTo-Json -Depth 10 | Set-Content -LiteralPath (Join-Path $destination 'runtime-summary.json') -Encoding utf8
    Write-Output ('PendingScalarValidation: passed='+$passed)
    if (!$passed) { throw 'Banco de escrituras fallido' }
} finally {
    if (Test-Path -LiteralPath $markerPath) { Remove-Item -LiteralPath $markerPath }
    if ($null -ne $backup) { [IO.File]::WriteAllBytes($reportPath,$backup) }
    elseif (Test-Path -LiteralPath $reportPath) { Remove-Item -LiteralPath $reportPath }
}
