param(
    [string]$GameDirectory = 'C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV - copia'
)
$ErrorActionPreference = 'Stop'
$gameExe = Join-Path $GameDirectory 'GTAIV.exe'
$expectedHash = 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
if ((Get-FileHash -LiteralPath $gameExe -Algorithm SHA256).Hash -ne $expectedHash) {
    throw 'El GTAIV.exe no coincide con el binario de referencia.'
}
if (Get-Process GTAIV -ErrorAction SilentlyContinue) {
    throw 'Ya hay un GTAIV ejecutándose. Ciérralo antes de iniciar otra prueba.'
}
Start-Process -FilePath $gameExe -WorkingDirectory $GameDirectory -ArgumentList '-windowed -width 800 -height 600' -WindowStyle Normal -PassThru
