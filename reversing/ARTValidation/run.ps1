param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference = 'Stop'
$repoPath = Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$markers = @('ReIV.art-test','ReIV.art-fixtures-test','ReIV.art-extras-test')
$reports = @('ReIV-art.json','ReIV-art-slots.csv','ReIV-art-fixtures.json','ReIV-art-extras.json')
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
        @{folder='ARTValidation';report='ReIV-art.json';source='source/hooks/ARTStubsProbe.h'},
        @{folder='ARTFixtureValidation';report='ReIV-art-fixtures.json';source='source/hooks/ARTFixtureProbe.h'},
        @{folder='ARTExtraValidation';report='ReIV-art-extras.json';source='source/hooks/ARTExtraProbe.h'}
    )
    foreach ($group in $groups) {
        $destination = Join-Path $repoPath ('reversing/' + $group.folder + '/evidence')
        [IO.Directory]::CreateDirectory($destination) | Out-Null
        $result = Get-Content -LiteralPath (Join-Path $GameDirectory $group.report) -Raw | ConvertFrom-Json
        Copy-Item -LiteralPath (Join-Path $GameDirectory $group.report) -Destination (Join-Path $destination 'runtime-report.json') -Force
        Copy-Item -LiteralPath (Join-Path $runPath 'result-ReIV.log') -Destination (Join-Path $destination 'runtime.log') -Force
        $passed = $gameSummary.passed -and $result.phase -eq 'passed' -and $result.exceptions -eq 0 -and @($result.entries | Where-Object { $_.failures -ne 0 -or $_.calls -ne 64 }).Count -eq 0
        if ($group.folder -eq 'ARTValidation') { $passed = $passed -and $result.slots_failed -eq 0 }
        $summary = [ordered]@{passed=$passed;date=$gameSummary.date;exe_sha256=$gameSummary.exe_sha256;asi_sha256=$gameSummary.asi_sha256;implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath $group.source)).Hash.ToLower();result=$result;game_run=$gameSummary}
        if ($group.folder -eq 'ARTValidation') {
            $summary['stub_bindings_sha256'] = (Get-FileHash -LiteralPath (Join-Path $repoPath 'source/hooks/ARTStubBindings.h')).Hash.ToLower()
            $summary['slot_bindings_sha256'] = (Get-FileHash -LiteralPath (Join-Path $repoPath 'source/hooks/ARTSlotBindings.h')).Hash.ToLower()
        }
        $summary | ConvertTo-Json -Depth 10 | Set-Content -LiteralPath (Join-Path $destination 'runtime-summary.json') -Encoding utf8
        Write-Output ($group.folder + ': passed=' + $passed)
        if (!$passed) { throw ('Banco fallido: ' + $group.folder) }
    }
    Copy-Item -LiteralPath (Join-Path $GameDirectory 'ReIV-art-slots.csv') -Destination (Join-Path $PSScriptRoot 'evidence/runtime-slots.csv') -Force
} finally {
    foreach ($name in $markers) { $path = Join-Path $GameDirectory $name; if (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path } }
    foreach ($name in $reports) {
        $path = Join-Path $GameDirectory $name
        if ($null -ne $backup[$name]) { [IO.File]::WriteAllBytes($path,$backup[$name]) }
        elseif (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path }
    }
}
