$ErrorActionPreference = 'Stop'
$repoRoot = Split-Path $PSScriptRoot -Parent
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
$vsRoot = & $vswhere -latest -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (!$vsRoot) { throw 'Faltan Visual Studio y las herramientas C++ x86/x64.' }
$msbuild = Join-Path $vsRoot 'MSBuild\Current\Bin\MSBuild.exe'
& $msbuild (Join-Path $repoRoot 'cmake\ReIV.vcxproj') /p:Configuration=Release /p:Platform=Win32 /verbosity:minimal /nologo
if ($LASTEXITCODE -ne 0) { throw 'La compilación de ReIV falló.' }
Get-FileHash (Join-Path $repoRoot 'bin\ReIV.asi') -Algorithm SHA256
