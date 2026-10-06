# Binario de referencia de ReIV

Verificación realizada el **6 de octubre de 2026**, fecha de México, mediante lectura del archivo, sus recursos de versión y cabeceras PE. No se ejecutó ni modificó el binario.

| Campo | Resultado |
| --- | --- |
| Ruta local | `C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV\GTAIV.exe` |
| Tamaño | 15.505.792 bytes |
| FileVersion | `1, 0, 7, 0` |
| ProductVersion | `1, 0, 7, 0` |
| Firma DOS | `0x5A4D` (MZ) |
| Firma PE | `0x00004550` |
| Machine | `0x014C` (Intel i386 / x86) |
| OptionalHeader.Magic | `0x010B` (PE32) |
| Secciones | 6 |
| SHA-256 | `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c` |

Este hash identifica el binario local elegido como referencia de análisis. Los recursos declaran la versión **1.0.7.0** y las cabeceras confirman **x86 de 32 bits**. La edición EFIGS y la autenticidad de una copia sin modificaciones quedan pendientes de corroborar mediante procedencia y una referencia independiente.

La instalación separada de pruebas es `C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV - copia`. Se comprobó que su `GTAIV.exe` tiene el mismo hash, también después del primer banco de validación. Los hooks modifican memoria del proceso; el archivo EXE no se alteró.

Cada dirección, offset, hook y banco deberá vincularse a este hash. Si cambia el archivo, comprobar el hash antes de reutilizar direcciones o evidencias.

## Repetir la comprobación

```powershell
$referenceExe = 'C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV\GTAIV.exe'
(Get-Item -LiteralPath $referenceExe).VersionInfo | Select-Object FileVersion, ProductVersion
Get-FileHash -LiteralPath $referenceExe -Algorithm SHA256
```
