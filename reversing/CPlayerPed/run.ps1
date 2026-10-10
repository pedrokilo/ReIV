param([string]$GameDirectory='D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference='Stop'
$repoRoot=Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
& (Join-Path $repoRoot 'contrib/build-reiv.ps1')
$implementation=Join-Path $repoRoot 'source/game/Peds/CPlayerPed.h'
$implementationHash=(Get-FileHash -LiteralPath $implementation -Algorithm SHA256).Hash.ToLower()
$probeHash=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'source/hooks/PlayerPedProbe.h') -Algorithm SHA256).Hash.ToLower()
$asiHash=(Get-FileHash -LiteralPath (Join-Path $repoRoot 'bin/ReIV.asi') -Algorithm SHA256).Hash.ToLower()
$additionalSources=[ordered]@{}
Get-ChildItem -Path (Join-Path (Join-Path $repoRoot 'source/game/Peds') '*') -Include 'PlayerPed*.h','PlayerPed*.cpp' | ForEach-Object {
    $additionalSources[('source/game/Peds/'+$_.Name)]=(Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLower()
}
$started=Get-Date
$marker=Join-Path $GameDirectory 'ReIV.player-ped-test'
$report=Join-Path $GameDirectory 'ReIV-CPlayerPed.json'
if(Test-Path -LiteralPath $marker){throw 'Existing marker'}
$previousReport=if(Test-Path -LiteralPath $report){[IO.File]::ReadAllBytes($report)}else{$null}
try {
[IO.File]::WriteAllText($marker,'Twelve reconstructed CPlayerPed operations; same-value live writes and isolated varied writes.')
& "$PSScriptRoot/../OriginalCalls/run.ps1" -GameDirectory $GameDirectory
if(!(Test-Path -LiteralPath $report)){throw 'Missing report'}
$result=Get-Content -LiteralPath $report -Raw|ConvertFrom-Json
Copy-Item -LiteralPath $report -Destination "$PSScriptRoot/evidence/runtime-report.json" -Force
if(!$result.passed -or $result.samples_per_method -ne 64 -or $result.failures -or $result.exceptions){throw 'Player reconstruction comparison failed'}
if($result.comparisons -ne 768){throw 'Unexpected method comparison count'}
if((Get-FileHash -LiteralPath $implementation -Algorithm SHA256).Hash.ToLower() -ne $implementationHash){throw 'Implementation changed during validation'}
if((Get-FileHash -LiteralPath (Join-Path $repoRoot 'source/hooks/PlayerPedProbe.h') -Algorithm SHA256).Hash.ToLower() -ne $probeHash){throw 'Probe changed during validation'}
foreach($sourcePath in $additionalSources.Keys){if((Get-FileHash -LiteralPath (Join-Path $repoRoot $sourcePath) -Algorithm SHA256).Hash.ToLower() -ne $additionalSources[$sourcePath]){throw "Dependency source changed during validation: $sourcePath"}}
$artifact=Get-ChildItem -LiteralPath (Join-Path $repoRoot 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*' | Where-Object {$_.LastWriteTime -ge $started} | Sort-Object LastWriteTime -Descending | Select-Object -First 1
if(!$artifact){throw 'Missing baseline evidence'}
$baseline=Get-Content -LiteralPath (Join-Path $artifact.FullName 'summary.json') -Raw | ConvertFrom-Json
if(!$baseline.passed -or $baseline.asi_sha256 -ne $asiHash){throw 'Baseline evidence does not match tested ASI'}
$summary=[ordered]@{passed=$true;exe_sha256=$baseline.exe_sha256;asi_sha256=$asiHash;implementation_sha256=$implementationHash;probe_sha256=$probeHash;additional_source_sha256=$additionalSources;result=$result;baseline=$baseline;scope='Twelve methods, 64 samples each. Live reads and same-value setters; varied writes, float copies, accumulator and extra fields on isolated buffers. Float routines use real read-only globals with full memory and MXCSR comparison; no replacement installed.'}
$summary | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath "$PSScriptRoot/evidence/runtime-summary.json" -Encoding utf8
} finally {
Remove-Item -LiteralPath $marker -ErrorAction SilentlyContinue
if($null -ne $previousReport){[IO.File]::WriteAllBytes($report,$previousReport)}elseif(Test-Path -LiteralPath $report){Remove-Item -LiteralPath $report}
}
