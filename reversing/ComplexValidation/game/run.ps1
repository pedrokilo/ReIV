param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference='Stop'
$repoPath=Split-Path (Split-Path (Split-Path $PSScriptRoot -Parent) -Parent) -Parent
$markerPath=Join-Path $GameDirectory 'ReIV.game-complex-test'
if(Test-Path -LiteralPath $markerPath){throw 'Marcador existente'}
$groups=@(@{report='ReIV-game-complex.json';prefix='runtime';count=28;source='GameComplexProbe.h'},@{report='ReIV-game-complex-scalar.json';prefix='scalar-runtime';count=70;source='GameComplexScalarProbe.h'})
$backup=@{}
foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;$backup[$g.report]=if(Test-Path -LiteralPath $path){[IO.File]::ReadAllBytes($path)}else{$null}}
try{
 foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;if(Test-Path -LiteralPath $path){Remove-Item -LiteralPath $path}}
 [IO.File]::WriteAllText($markerPath,'Controlled finite fixture validation')
 & (Join-Path $PSScriptRoot '../../OriginalCalls/run.ps1') -GameDirectory $GameDirectory
 $runPath=(Get-ChildItem -LiteralPath (Join-Path $repoPath 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*'|Sort-Object LastWriteTime -Descending|Select-Object -First 1).FullName
 $gameSummary=Get-Content -LiteralPath (Join-Path $runPath 'summary.json') -Raw|ConvertFrom-Json
 $destination=Join-Path $PSScriptRoot 'evidence';[IO.Directory]::CreateDirectory($destination)|Out-Null
 foreach($g in $groups){
  $result=Get-Content -LiteralPath (Join-Path $GameDirectory $g.report) -Raw|ConvertFrom-Json
  Copy-Item -LiteralPath (Join-Path $GameDirectory $g.report) -Destination (Join-Path $destination ($g.prefix+'-report.json')) -Force
  Copy-Item -LiteralPath (Join-Path $runPath 'result-ReIV.log') -Destination (Join-Path $destination ($g.prefix+'.log')) -Force
  $passed=$gameSummary.passed -and $result.phase -eq 'passed' -and $result.exceptions -eq 0 -and @($result.entries).Count -eq $g.count -and @($result.entries|Where-Object{$_.failures -ne 0 -or $_.calls -ne 64}).Count -eq 0
  $summary=[ordered]@{passed=$passed;date=$gameSummary.date;exe_sha256=$gameSummary.exe_sha256;asi_sha256=$gameSummary.asi_sha256;implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath ('source/hooks/'+$g.source))).Hash.ToLower();scalar_implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath 'source/hooks/GameComplexScalarProbe.h')).Hash.ToLower();result=$result;game_run=$gameSummary}
  $summary|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $destination ($g.prefix+'-summary.json')) -Encoding utf8
  Write-Output ($g.source+': passed='+$passed)
  if(!$passed){throw ('Banco fallido '+$g.source)}
 }
}finally{
 if(Test-Path -LiteralPath $markerPath){Remove-Item -LiteralPath $markerPath}
 foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;if($null -ne $backup[$g.report]){[IO.File]::WriteAllBytes($path,$backup[$g.report])}elseif(Test-Path -LiteralPath $path){Remove-Item -LiteralPath $path}}
}
