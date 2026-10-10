param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference='Stop'
$repoPath=Split-Path (Split-Path $PSScriptRoot -Parent) -Parent
$markers=@('ReIV.game-complex-test','ReIV.rage-complex-test','ReIV.art-complex-test','ReIV.destructor-mode-test')
$groups=@(
 @{folder='game';prefix='runtime';report='ReIV-game-complex.json';source='GameComplexProbe.h';scope='fixture-scope.json';count=28},
 @{folder='game';prefix='scalar-runtime';report='ReIV-game-complex-scalar.json';source='GameComplexScalarProbe.h';scope='scalar-scope.json';count=70},
 @{folder='rage';prefix='runtime';report='ReIV-rage-complex.json';source='RageComplexProbe.h';scope='fixture-scope.json';count=29},
 @{folder='ART';prefix='runtime';report='ReIV-art-complex.json';source='ARTComplexProbe.h';scope='fixture-scope.json';count=15},
 @{folder='destructors';prefix='runtime';report='ReIV-destructor-mode.json';source='DestructorModeProbe.h';scope='fixture-scope.json';count=70}
)
$backup=@{}
if(@(Get-ChildItem -LiteralPath $GameDirectory -Filter 'ReIV.*test').Count){throw 'Otro marcador de prueba está activo'}
foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;$backup[$g.report]=if(Test-Path -LiteralPath $path){[IO.File]::ReadAllBytes($path)}else{$null}}
try{
 foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;if(Test-Path -LiteralPath $path){Remove-Item -LiteralPath $path}}
 foreach($marker in $markers){[IO.File]::WriteAllText((Join-Path $GameDirectory $marker),'Controlled isolated validation')}
 & (Join-Path $PSScriptRoot '../OriginalCalls/run.ps1') -GameDirectory $GameDirectory
 $runPath=(Get-ChildItem -LiteralPath (Join-Path $repoPath 'reversing/artifacts') -Directory -Filter 'GetBoneMatrix-*'|Sort-Object LastWriteTime -Descending|Select-Object -First 1).FullName
 $gameSummary=Get-Content -LiteralPath (Join-Path $runPath 'summary.json') -Raw|ConvertFrom-Json
 $failed=@()
 foreach($g in $groups){
  $destination=Join-Path $PSScriptRoot ($g.folder+'/evidence');[IO.Directory]::CreateDirectory($destination)|Out-Null
  $result=Get-Content -LiteralPath (Join-Path $GameDirectory $g.report) -Raw|ConvertFrom-Json
  Copy-Item -LiteralPath (Join-Path $GameDirectory $g.report) -Destination (Join-Path $destination ($g.prefix+'-report.json')) -Force
  Copy-Item -LiteralPath (Join-Path $runPath 'result-ReIV.log') -Destination (Join-Path $destination ($g.prefix+'.log')) -Force
  $passed=$gameSummary.passed -and $result.phase -eq 'passed' -and $result.exceptions -eq 0 -and @($result.entries).Count -eq $g.count -and @($result.entries|Where-Object{$_.failures -ne 0 -or $_.calls -ne 64 -or $_.disabled}).Count -eq 0
  $summary=[ordered]@{passed=$passed;date=$gameSummary.date;exe_sha256=$gameSummary.exe_sha256;asi_sha256=$gameSummary.asi_sha256;implementation_sha256=(Get-FileHash -LiteralPath (Join-Path $repoPath ('source/hooks/'+$g.source))).Hash.ToLower();scope_sha256=(Get-FileHash -LiteralPath (Join-Path $destination $g.scope)).Hash.ToLower();result=$result;game_run=$gameSummary}
  if($g.folder -eq 'game'){$summary['scalar_implementation_sha256']=(Get-FileHash -LiteralPath (Join-Path $repoPath 'source/hooks/GameComplexScalarProbe.h')).Hash.ToLower()}
  $summary|ConvertTo-Json -Depth 10|Set-Content -LiteralPath (Join-Path $destination ($g.prefix+'-summary.json')) -Encoding utf8
  Write-Output ($g.source+': passed='+$passed)
  if(!$passed){$failed+=$g.source}
 }
 if($failed.Count){throw ('Bancos fallidos: '+($failed -join ', '))}
}finally{
 foreach($marker in $markers){$path=Join-Path $GameDirectory $marker;if(Test-Path -LiteralPath $path){Remove-Item -LiteralPath $path}}
 foreach($g in $groups){$path=Join-Path $GameDirectory $g.report;if($null -ne $backup[$g.report]){[IO.File]::WriteAllBytes($path,$backup[$g.report])}elseif(Test-Path -LiteralPath $path){Remove-Item -LiteralPath $path}}
}
