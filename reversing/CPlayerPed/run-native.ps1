param([string]$GameDirectory='D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference='Stop'
$repoRoot=Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
& (Join-Path $repoRoot 'contrib/build-reiv.ps1')
$asiHash=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'bin/ReIV.asi') -Algorithm SHA256).Hash.ToLower()
$sources=[ordered]@{}
foreach($relative in @('source/core/ReIV.cpp','source/hooks/PlayerPedNativeProbe.h','source/game/Peds/CPlayerPed.h','reversing/CPlayerPed/CoffClone.h','reversing/CPlayerPed/NativeObserverBridge.h','reversing/CPlayerPed/NativeValidatedResolver.h','reversing/CPlayerPed/native-clone/templates.h','reversing/CPlayerPed/native-clone/native-validation.h')) {
    $sources[$relative]=(Get-FileHash -LiteralPath (Join-Path $repoRoot $relative) -Algorithm SHA256).Hash.ToLower()
}
$started=Get-Date
$marker=Join-Path $GameDirectory 'ReIV.player-native-test'
$report=Join-Path $GameDirectory 'ReIV-CPlayerPed-native.json'
if(Test-Path -LiteralPath $marker){throw 'Existing native test marker'}
$previousReport=if(Test-Path -LiteralPath $report){[IO.File]::ReadAllBytes($report)}else{$null}
try {
    [IO.File]::WriteAllText($marker,'Observe natural Update calls, then opt-in reconstructed Update; restore original slot.')
    & "$PSScriptRoot/../OriginalCalls/run.ps1" -GameDirectory $GameDirectory
    if(!(Test-Path -LiteralPath $report)){throw 'Missing native player report'}
    $result=Get-Content -LiteralPath $report -Raw|ConvertFrom-Json
    Copy-Item -LiteralPath $report -Destination "$PSScriptRoot/evidence/native-runtime-report.json" -Force
    foreach($relative in $sources.Keys){if((Get-FileHash -LiteralPath (Join-Path $repoRoot $relative) -Algorithm SHA256).Hash.ToLower() -ne $sources[$relative]){throw "Source changed during test: $relative"}}
    $artifact=Get-ChildItem -LiteralPath (Join-Path $repoRoot 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*' | Where-Object {$_.LastWriteTime -ge $started} | Sort-Object LastWriteTime -Descending | Select-Object -First 1
    if(!$artifact){throw 'Missing baseline evidence'}
    $baseline=Get-Content -LiteralPath (Join-Path $artifact.FullName 'summary.json') -Raw|ConvertFrom-Json
    if(!$baseline.passed -or $baseline.asi_sha256 -ne $asiHash){throw 'Baseline does not match tested ASI'}
    $passed=$result.passed -and $result.original_calls -ge 32 -and $result.clone_calls -ge 64 -and !$result.exceptions -and $result.restored
    $summary=[ordered]@{passed=[bool]$passed;exe_sha256=$baseline.exe_sha256;asi_sha256=$asiHash;implementation_sha256=$sources['source/game/Peds/CPlayerPed.h'];additional_source_sha256=$sources;result=$result;baseline=$baseline;scope='Natural Update calls redirected to compiled reconstructed caller with original external callees. No duplicate update comparison or complete class certification.'}
    $summary | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath "$PSScriptRoot/evidence/native-runtime-attempt-$($started.ToString('yyyyMMdd-HHmmss')).json" -Encoding utf8
    if(!$passed){throw 'Native Update did not pass'}
    $summary | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath "$PSScriptRoot/evidence/native-runtime-summary.json" -Encoding utf8
} finally {
    Remove-Item -LiteralPath $marker -ErrorAction SilentlyContinue
    if($null -ne $previousReport){[IO.File]::WriteAllBytes($report,$previousReport)}elseif(Test-Path -LiteralPath $report){Remove-Item -LiteralPath $report}
}
