$ErrorActionPreference='Stop'
Set-Location (Resolve-Path "$PSScriptRoot/../../..").Path
$taskVs = & "${env:ProgramFiles(x86)}/Microsoft Visual Studio/Installer/vswhere.exe" -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
$taskTool = (Get-ChildItem "$taskVs/VC/Tools/MSVC" -Directory | Sort-Object Name -Descending | Select-Object -First 1).FullName
$taskSdk = (Get-ChildItem 'C:/Program Files (x86)/Windows Kits/10/Include' -Directory | Sort-Object Name -Descending | Select-Object -First 1).Name
$env:INCLUDE = "$taskTool/include;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/ucrt;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/shared;C:/Program Files (x86)/Windows Kits/10/Include/$taskSdk/um"
$env:LIB = "$taskTool/lib/x86;C:/Program Files (x86)/Windows Kits/10/Lib/$taskSdk/ucrt/x86;C:/Program Files (x86)/Windows Kits/10/Lib/$taskSdk/um/x86"
$env:PATH = "$taskTool/bin/Hostx64/x86;$env:PATH"
$taskResults=@()
foreach($taskName in @('observer-bridge','native-resolver')){
 $taskExe="build/privateNativeBinding/$taskName-check.exe"
 & cl /nologo /std:c++17 /O2 /EHsc "reversing/CPlayerPed/native-clone/check-$taskName.cpp" "/Fe$taskExe" "/Fobuild/privateNativeBinding/$taskName-check.obj"
 if($LASTEXITCODE){throw "Compile failed $taskName"}
 $taskOutput=& ".\$taskExe" 2>&1
 if($LASTEXITCODE -or ($taskOutput -join "`n") -notmatch '^PASS'){throw "Test failed $taskName"}
 $taskOutput | Write-Output
 $taskResults+=@{name=$taskName; output=($taskOutput -join "`n"); executable_sha256=(Get-FileHash $taskExe -Algorithm SHA256).Hash.ToLower()}
}
$taskHashes=@{}
foreach($taskFile in @('NativeObserverBridge.h','NativeValidatedResolver.h','native-clone/native-validation.h','native-clone/check-observer-bridge.cpp','native-clone/check-native-resolver.cpp','generate-native-validation.py')){
 $taskPath="reversing/CPlayerPed/$taskFile"
 $taskHashes[$taskPath]=(Get-FileHash $taskPath -Algorithm SHA256).Hash.ToLower()
}
@{game_runtime_validated=$false; hook_installed=$false; accepted_game_mappings_tested=$false; bridge_cases=16384; resolver_checks=14; exception_notification_scope='IP inside clone only; CONTINUE_SEARCH; external callee exceptions not attributed'; hashes=$taskHashes; results=$taskResults} | ConvertTo-Json -Depth 8 | Set-Content reversing/CPlayerPed/evidence/native-observer-detached-validation.json
