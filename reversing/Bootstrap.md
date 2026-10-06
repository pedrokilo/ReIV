# Primera base de ReIV

La primera compilación usa IV-SDK directamente desde `contrib/IV SDK/IV-SDK-main`, sin modificar sus fuentes. El proyecto MSBuild está en `cmake/ReIV.vcxproj`; requiere Visual Studio con C++ y toolset v145. CMake todavía no está implementado.

```powershell
powershell -ExecutionPolicy Bypass -File .\contrib\build-reiv.ps1
```

Genera `bin/ReIV.asi` y `bin/ReIV.pdb`, x86. Incluye los hooks de eventos del SDK y registra la inicialización, `gameLoadEvent` e `ingameStartupEvent` en `ReIV.log`, junto al ejecutable. Todavía no reconstruye funciones del juego ni acredita equivalencia.

## Copia de pruebas

Ruta: `C:\Users\pedro\OneDrive\Desktop\GTA IV\Grand Theft Auto IV - copia`.

El SHA-256 de su `GTAIV.exe` coincide con el [binario registrado](../docs/ReferenceBinary.md). Se instalaron `ReIV.asi` y los símbolos en esta copia.

En `commandline.txt` se conservaron los argumentos previos y se añadieron:

```text
-windowed
-width 800
-height 600
```

Son argumentos documentados en el `ReadMe.txt` del juego. En `XLivelessAddon.ini`, `BorderlessWindowed = 0` y `SkipMenu = 0` permiten probar una ventana con bordes y el menú. Los originales se respaldaron en `ReIV-backup-20261006-164745` dentro de la copia de pruebas.

SHA-256 de la primera compilación:

```text
6167480e0a14b80d19e41268baa0dc98c642a414065fd70e0bbe58c7799a4cc9
```

El arranque se realiza exclusivamente mediante `GTAIV.exe`, por instrucción del usuario. Usar:

```powershell
powershell -ExecutionPolicy Bypass -File .\contrib\start-reiv.ps1
```

La ejecución directa confirmó mediante `ReIV.log` la carga del ASI y la detección de 1.0.7.0. Se debe abrir con ventana normal para la prueba interactiva.

El 6 de octubre de 2026 se comprobó una ventana visible de GTAIV y el renderizador en modo windowed con parámetros 800×600. El área útil inicial era 782×553 porque el tamaño incluía los bordes; se ajustó con `SetWindowPos` y se verificaron **800×600 de área útil**. El script de arranque aplica esa compensación automáticamente. La carga del ASI está confirmada; todavía no se ha acreditado equivalencia de funciones ni una sesión de juego estable.
