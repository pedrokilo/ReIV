param([string]$GameDirectory = 'D:\GTA IV\Grand Theft Auto IV - copia')
$ErrorActionPreference = 'Stop'
$marker = Join-Path $GameDirectory 'ReIV.nmutils-test'
$reportPath = Join-Path $GameDirectory 'ReIV-NMutils.json'
if (Test-Path -LiteralPath $marker) { throw 'Ya existe un marcador NMutils' }
$priorReport = if (Test-Path -LiteralPath $reportPath) { [IO.File]::ReadAllBytes($reportPath) } else { $null }
try {
    if ($null -ne $priorReport) { Remove-Item -LiteralPath $reportPath }
    [IO.File]::WriteAllText($marker,'Synthetic NMutils tests; exclude fatal assertion handler')
    & (Join-Path $PSScriptRoot '../OriginalCalls/run.ps1') -GameDirectory $GameDirectory
    $report = Get-Content -LiteralPath $reportPath -Raw | ConvertFrom-Json
    Copy-Item -LiteralPath $reportPath -Destination (Join-Path $PSScriptRoot 'evidence/runtime-report.json') -Force
    if ($report.phase -ne 'passed' -or $report.exceptions -ne 0 -or @($report.entries | Where-Object { !$_.disabled -and ($_.calls -ne 64 -or $_.failures -ne 0) }).Count -ne 0) { throw 'NMutils no aprobó' }
    $report | ConvertTo-Json -Depth 5
} finally {
    if (Test-Path -LiteralPath $marker) { Remove-Item -LiteralPath $marker }
    if ($null -ne $priorReport) { [IO.File]::WriteAllBytes($reportPath,$priorReport) }
    elseif (Test-Path -LiteralPath $reportPath) { Remove-Item -LiteralPath $reportPath }
}
