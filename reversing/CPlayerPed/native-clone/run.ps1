$ErrorActionPreference = 'Stop'
$taskRoot = (Resolve-Path "$PSScriptRoot/../../..").Path
Set-Location $taskRoot
python reversing/CPlayerPed/inspect-native-binding.py
if ($LASTEXITCODE) { throw 'Compiled snapshot validation failed' }
python reversing/CPlayerPed/generate-clone-checks.py
if ($LASTEXITCODE) { throw 'Clone bank generation failed' }
$taskVs = & "${env:ProgramFiles(x86)}/Microsoft Visual Studio/Installer/vswhere.exe" -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$taskTool = (Get-ChildItem "$taskVs/VC/Tools/MSVC" -Directory | Sort-Object Name -Descending | Select-Object -First 1).FullName
$taskSdk = (Get-ChildItem 'C:/Program Files (x86)/Windows Kits/10/Include' -Directory | Sort-Object Name -Descending | Select-Object -First 1).Name
$env:INCLUDE = "$taskTool/include;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/ucrt;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/shared;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/um"
$env:LIB = "$taskTool/lib/x86;C:/Program Files (x86)/Windows Kits/10/Lib/$taskSdk/ucrt/x86;C:/Program Files (x86)/Windows Kits/10/Lib/$taskSdk/um/x86"
$env:PATH = "$taskTool/bin/Hostx64/x86;$env:PATH"
$taskResults = @()
foreach ($taskName in @('loader-contract','update','value-adjust','input-select')) {
    $taskExecutableName = if ($taskName -eq 'update') { 'tick-check' } else { $taskName }
    $taskExe = "build/privateNativeBinding/clone-$taskExecutableName.exe"
    New-Item -ItemType Directory -Force "build/privateNativeBinding/clone-obj-$taskName" | Out-Null
    $taskPlayerSources = (Get-ChildItem source/game/Peds -Filter 'PlayerPed*.cpp' | ForEach-Object { "source/game/Peds/$($_.Name)" })
    & cl /nologo /std:c++17 /O2 /EHsc /I source /I reversing/CPlayerPed "reversing/CPlayerPed/native-clone/check-$taskName.cpp" $taskPlayerSources "/Fe$taskExe" "/Fobuild/privateNativeBinding/clone-obj-$taskName/"
    if ($LASTEXITCODE) { throw "Compilation failed: $taskName" }
    $taskOutput = & ".\$taskExe" 2>&1
    $taskExit = $LASTEXITCODE
    $taskOutput | Write-Output
    if ($taskExit -ne 0 -or ($taskOutput -join "`n") -notmatch 'PASS') { throw "Clone bank failed: $taskName exit=$taskExit" }
    $taskResults += @{bank=$taskName; exit_code=$taskExit; exe_sha256=(Get-FileHash $taskExe -Algorithm SHA256).Hash.ToLower(); output=($taskOutput -join "`n")}
}
$taskHashes = @{}
Get-ChildItem "$PSScriptRoot/*.cpp","$PSScriptRoot/templates.h","$PSScriptRoot/../CoffClone.h","$PSScriptRoot/../generate-clone-checks.py" | ForEach-Object {
    $taskKey = $_.FullName.Substring($taskRoot.Length+1).Replace('\','/')
    $taskHashes[$taskKey] = (Get-FileHash $_.FullName -Algorithm SHA256).Hash.ToLower()
}
@{game_runtime_validated=$false; hooks_installed=$false; native_clones_executed=$true; templates_origin='Compiled reconstructed source COFF snapshots'; allocations_per_body=2; scenario_counts=@{Update=139920; Adjust=2457600; Select=74448}; clone_executions=5343936; fixture_cases_exhaustive=$false; concurrent_execution_tested=$false; hashes=$taskHashes; results=$taskResults} | ConvertTo-Json -Depth 9 | Set-Content reversing/CPlayerPed/evidence/native-clone-validation.json
