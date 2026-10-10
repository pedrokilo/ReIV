param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference = 'Stop'
$repoPath = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$markers = @('ReIV.game-stubs-test','ReIV.audio-fixtures-test','ReIV.animation-fixtures-test','ReIV.nmutils-test','ReIV.extra-stubs-test')
$reports = @('ReIV-game-stubs.json','ReIV-game-slots.csv','ReIV-audio-fixtures.json','ReIV-animation-fixtures.json','ReIV-NMutils.json','ReIV-extra-stubs.json')
$backup = @{}
foreach ($name in $markers) { if (Test-Path -LiteralPath (Join-Path $GameDirectory $name)) { throw ('Marcador existente: ' + $name) } }
foreach ($name in $reports) {
    $path = Join-Path $GameDirectory $name
    $backup[$name] = if (Test-Path -LiteralPath $path) { [IO.File]::ReadAllBytes($path) } else { $null }
}
try {
    foreach ($name in $reports) { $path = Join-Path $GameDirectory $name; if (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path } }
    foreach ($name in $markers) { [IO.File]::WriteAllText((Join-Path $GameDirectory $name),'Controlled validation only') }
    & (Join-Path $PSScriptRoot '../OriginalCalls/run.ps1') -GameDirectory $GameDirectory
    $runPath = (Get-ChildItem -LiteralPath (Join-Path $repoPath 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*' | Sort-Object LastWriteTime -Descending | Select-Object -First 1).FullName
    $gameSummary = Get-Content -LiteralPath (Join-Path $runPath 'summary.json') -Raw | ConvertFrom-Json
    $groups = @(
        @{folder='GameValidation';report='ReIV-game-stubs.json';source='source/hooks/GameStubsProbe.h'},
        @{folder='AudioValidation';report='ReIV-audio-fixtures.json';source='source/hooks/AudioFixtureProbe.h'},
        @{folder='AnimationValidation';report='ReIV-animation-fixtures.json';source='source/hooks/AnimationFixtureProbe.h'},
        @{folder='ExtraStubValidation';report='ReIV-extra-stubs.json';source='source/hooks/ExtraStubsProbe.h'},
        @{folder='NMutils';report='ReIV-NMutils.json';source='source/hooks/NMutilsProbe.h'}
    )
    foreach ($group in $groups) {
        $destination = Join-Path $repoPath ('reversing/' + $group.folder + '/evidence')
        [IO.Directory]::CreateDirectory($destination) | Out-Null
        $result = Get-Content -LiteralPath (Join-Path $GameDirectory $group.report) -Raw | ConvertFrom-Json
        Copy-Item -LiteralPath (Join-Path $GameDirectory $group.report) -Destination (Join-Path $destination 'runtime-report.json') -Force
        Copy-Item -LiteralPath (Join-Path $runPath 'result-ReIV.log') -Destination (Join-Path $destination 'runtime.log') -Force
        $passed = $gameSummary.passed -and $result.phase -eq 'passed' -and $result.exceptions -eq 0 -and @($result.entries | Where-Object { $_.failures -ne 0 }).Count -eq 0
        $summary = [ordered]@{passed=$passed;date=$gameSummary.date;exe_sha256=$gameSummary.exe_sha256;asi_sha256=$gameSummary.asi_sha256;implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath $group.source)).Hash.ToLower();result=$result;game_run=$gameSummary}
        if ($group.folder -eq 'NMutils') { $summary['nmutils'] = $result }
        $summary | ConvertTo-Json -Depth 10 | Set-Content -LiteralPath (Join-Path $destination 'runtime-summary.json') -Encoding utf8
        Write-Output ($group.folder + ': passed=' + $passed)
        if (!$passed) { throw ('Banco fallido: ' + $group.folder) }
    }
    Copy-Item -LiteralPath (Join-Path $GameDirectory 'ReIV-game-slots.csv') -Destination (Join-Path $PSScriptRoot 'evidence/runtime-slots.csv') -Force
} finally {
    foreach ($name in $markers) { $path = Join-Path $GameDirectory $name; if (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path } }
    foreach ($name in $reports) {
        $path = Join-Path $GameDirectory $name
        if ($null -ne $backup[$name]) { [IO.File]::WriteAllBytes($path,$backup[$name]) }
        elseif (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path }
    }
}
