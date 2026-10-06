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
$startedGame = Start-Process -FilePath $gameExe -WorkingDirectory $GameDirectory -ArgumentList '-windowed -width 800 -height 600' -WindowStyle Normal -PassThru
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
public class ReIVWindowSize {
    [StructLayout(LayoutKind.Sequential)] public struct Rect { public int L,T,R,B; }
    [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h,out Rect r);
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h,out Rect r);
    [DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr h,IntPtr a,int x,int y,int w,int z,uint f);
}
'@
$windowDeadline = (Get-Date).AddSeconds(45)
do {
    Start-Sleep -Milliseconds 500
    $startedGame.Refresh()
    if ($startedGame.HasExited) { throw 'GTAIV terminó antes de crear la ventana.' }
} while ($startedGame.MainWindowHandle -eq 0 -and (Get-Date) -lt $windowDeadline)
if ($startedGame.MainWindowHandle -eq 0) { throw 'No apareció una ventana de GTAIV en 45 segundos.' }
$clientRect = New-Object ReIVWindowSize+Rect
$outerRect = New-Object ReIVWindowSize+Rect
[void][ReIVWindowSize]::GetClientRect($startedGame.MainWindowHandle,[ref]$clientRect)
[void][ReIVWindowSize]::GetWindowRect($startedGame.MainWindowHandle,[ref]$outerRect)
$frameWidth = ($outerRect.R-$outerRect.L)-($clientRect.R-$clientRect.L)
$frameHeight = ($outerRect.B-$outerRect.T)-($clientRect.B-$clientRect.T)
if (![ReIVWindowSize]::SetWindowPos($startedGame.MainWindowHandle,[IntPtr]::Zero,0,0,(800+$frameWidth),(600+$frameHeight),6)) {
    throw 'No se pudo ajustar el tamaño de la ventana.'
}
[void][ReIVWindowSize]::GetClientRect($startedGame.MainWindowHandle,[ref]$clientRect)
Write-Output ('GTAIV PID={0}, área útil={1}x{2}' -f $startedGame.Id,($clientRect.R-$clientRect.L),($clientRect.B-$clientRect.T))
