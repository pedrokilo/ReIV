$ErrorActionPreference = 'Stop'
$repo = (Resolve-Path (Join-Path $PSScriptRoot '../..')).Path
Push-Location $repo
try {
    $staticJson = & python reversing/PlayerPedProtectedValue/prepare.py
    if ($LASTEXITCODE -ne 0) { throw 'Canonical EXE body verification failed' }
    $static = Get-Content reversing/PlayerPedProtectedValue/static-bodies.json -Raw | ConvertFrom-Json
    $vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio/Installer/vswhere.exe'
    $vsPath = & $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    $tool = (Get-ChildItem (Join-Path $vsPath 'VC/Tools/MSVC') -Directory | Sort-Object Name -Descending | Select-Object -First 1).FullName
    $sdk = (Get-ChildItem 'C:/Program Files (x86)/Windows Kits/10/Include' -Directory | Sort-Object Name -Descending | Select-Object -First 1).FullName
    $version = Split-Path $sdk -Leaf
    $env:INCLUDE = "${tool}/include;${sdk}/ucrt;${sdk}/shared;${sdk}/um"
    $env:LIB = "${tool}/lib/x86;C:/Program Files (x86)/Windows Kits/10/Lib/${version}/ucrt/x86;C:/Program Files (x86)/Windows Kits/10/Lib/${version}/um/x86"
    $env:PATH = "${tool}/bin/Hostx64/x86;" + $env:PATH
    New-Item -ItemType Directory -Force build/player-protected-check-obj | Out-Null
    & (Join-Path $tool 'bin/Hostx64/x86/cl.exe') /nologo /std:c++17 /O2 /EHsc /I source reversing/PlayerPedProtectedValue/check.cpp source/game/Peds/CPlayerPed.cpp /Febuild/player-protected-check.exe /Fobuild/player-protected-check-obj/
    if ($LASTEXITCODE -ne 0) { throw 'Native comparison compilation failed' }
    $output = & build/player-protected-check.exe
    if ($LASTEXITCODE -ne 0) { throw "Comparison failed: $output" }
    $result = ($output | Select-Object -Last 1) | ConvertFrom-Json
    $record = [ordered]@{
        date = (Get-Date).ToString('o')
        passed = $result.passed
        comparisons = $result.comparisons
        comparisons_per_body = $result.comparisons_per_body
        failures = $result.failures
        scope = $result.scope
        in_game = $false
        implementation_kind = 'MSVC x86 inline assembly reconstruction'
        exe_sha256 = $static.exe_sha256
        implementation_sha256 = (Get-FileHash source/game/Peds/CPlayerPed.h -Algorithm SHA256).Hash.ToLower()
        test_sha256 = (Get-FileHash reversing/PlayerPedProtectedValue/check.cpp -Algorithm SHA256).Hash.ToLower()
        comparison_exe_sha256 = (Get-FileHash build/player-protected-check.exe -Algorithm SHA256).Hash.ToLower()
        compiler = $tool
        entries = $static.entries
    }
    $record | ConvertTo-Json -Depth 8 | Set-Content (Join-Path $PSScriptRoot 'native-summary.json') -Encoding utf8
    $result | ConvertTo-Json -Compress
} finally { Pop-Location }

