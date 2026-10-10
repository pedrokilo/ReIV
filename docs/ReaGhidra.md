# REA y Ghidra para GTA IV x86

Configuración local preparada el 7 de octubre de 2026. Ghidra puede analizar x86 de 32 bits; el bloqueo encontrado pertenecía al adaptador Windows P0 de REA 5.0.0, que admite únicamente aplicaciones PE x86-64 en su versión oficial.

## Instalación local

- Herramientas: `C:\Users\pedro\Tools\ReIV-analysis`.
- Ghidra: `ghidra_12.1.4_PUBLIC`, descargado de la [versión oficial](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.4_build).
- SHA-256 del ZIP original: `ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db`.
- JDK existente: `C:\Program Files\Eclipse Adoptium\jdk-25.0.3.9-hotspot`.
- REA: copia local de `rea-agents@5.0.0`, en `rea-x86\node_modules\rea-agents`.
- Binario de análisis: `targets\GTAIV.exe`, copiado fuera de OneDrive y verificado contra el [hash de referencia](ReferenceBinary.md).

`C:\Users\pedro\.codex\config.toml` apunta al servidor local mediante Node y proporciona `GHIDRA_INSTALL_DIR` y `JAVA_HOME` en el entorno del servidor. El respaldo previo está en `config.toml.before-rea-x86`, dentro del directorio de herramientas. Es necesario reiniciar Codex o reconectar REA para que una conversación existente utilice la nueva configuración; los servidores ya iniciados conservan su código y entorno anteriores.

## Adaptaciones

El script local `patch-rea-x86.mjs` conserva copias `.upstream` antes de cambiar el adaptador. La extensión admite x86 únicamente para el SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`. Mantiene las exclusiones de DLL, código administrado, otros formatos y otras arquitecturas. El perfil de evidencia identifica la extensión como `reiv-gtaiv-x86-sha256-bound-v1`.

El arranque de esta referencia permite hasta 30 minutos para el análisis automático completo y exige que Ghidra confirme `x86:LE:32:default` con compilador `windows`. No se fuerza una importación x64 ni se admite un análisis incompleto como completo.

También fue necesario adaptar dos lectores de Ghidra: `FileByteProvider` y el cálculo MD5 de `FSUtilities`. Sus lectores Java anteriores no compartían el acceso de borrado requerido por el handle retenido de REA y fallaban con una infracción de uso compartido. La adaptación utiliza canales y flujos NIO; los handles nativos siguen impidiendo escrituras y sustituciones de la copia analizada. El archivo original del juego no se modifica.

`patch-ghidra-reader.ps1` recompila esos lectores para Java 21 y los instala en `Base.jar`. Conserva `Base.jar.upstream` y los fuentes oficiales descargados en `ghidra-patch`. La instalación resultante de Ghidra está modificada localmente; el hash del ZIP oficial describe su procedencia, no el contenido actual de `Base.jar`.

Los controles nativos Windows, las DACL privadas, la propiedad de procesos mediante Job Objects, el transporte autenticado y el cierre de sesiones permanecen activos. Esta adaptación no constituye soporte oficial de REA para todos los binarios x86.

## Verificación

`rea-x86\verify-reader.mjs` comprobó lecturas aleatorias y de cabecera del snapshot, MD5 contra el archivo de referencia y escritura/lectura con límites de buffer en un archivo de prueba independiente. También verificó que los intentos de escribir y renombrar el snapshot siguen siendo rechazados.

`rea-x86\verify.mjs` comprueba la política de admisión y ejecuta una prueba real por MCP de importación, análisis de `atStringHash` en `0x005B1C30`, lectura de sus 106 bytes, correspondencia con el offset del archivo y cierre de sesión. Las respuestas completas se conservan localmente en `evidence`.

**Prueba real aprobada.** El análisis automático terminó y REA confirmó el lenguaje x86 de 32 bits y el compilador Windows. Se decompiló `atStringHash`, se recuperaron 694 funciones llamadoras y 1.638 referencias entrantes estáticas, y los 106 bytes leídos en `0x005B1C30` coincidieron exactamente con el EXE en el offset de archivo `0x001B1C30` (decimal `1776688`), obtenido mediante el mapeo de bytes de Ghidra. El cierre de REA fue correcto; no quedaron proyectos temporales ni procesos Java de estas pruebas. El hash del EXE de la instalación original volvió a comprobarse al finalizar y conserva el valor de referencia.

El [resumen de verificación](../reversing/AtStringHash/evidence/rea-ghidra-verification.json) registra los identificadores de evidencia. Las respuestas completas y el manifiesto con hashes de los archivos modificados están en `C:\Users\pedro\Tools\ReIV-analysis\evidence`. El pseudocódigo tiene evidencia `ev_38f123aeadf3bbd5ecdec7f4b5379433a16ce722dcdf53247b063c724bc1414f`; la comparación de bytes usa `ev_380f444f850e3df660f474ce2536c25a3567e475b5a92202d4c91c71ed2af650` y el mapeo usa `ev_869302f8753cb69ea93f0c25a89816cc19b7c5769fcac00f41b9a3ffd185b39a`. Esta verificación es estática; no añade una prueba de ejecución del juego ni demuestra reconstrucción semántica completa.

La importación y el análisis inicial de la última prueba tardaron aproximadamente 6 minutos y 25 segundos. Las siguientes consultas de bytes, mapeo y pseudocódigo en la misma sesión tardaron milisegundos. El informe completo de esta función contiene muchas referencias: la respuesta guardada ocupa unos 19,5 MB. El cliente de prueba necesitó ampliar su buffer por encima del límite predeterminado de 10 MiB; para consultas ordinarias conviene usar `procedure_pseudo_code`, `read_bytes` y otras operaciones específicas.

## Uso y recuperación

Después de reconectar REA, abrir `C:\Users\pedro\Tools\ReIV-analysis\targets\GTAIV.exe` con `provider_id: "ghidra"`. El primer análisis importa el ejecutable en un proyecto temporal; puede tardar varios minutos. Cerrar la sesión al terminar. Los proyectos temporales se eliminan al cerrar, por lo que una sesión nueva debe analizar otra vez el EXE.

Para usar la misma instalación desde una terminal, `C:\Users\pedro\Tools\ReIV-analysis\rea-reiv.cmd` proporciona el entorno correcto. Por ejemplo:

```powershell
& 'C:\Users\pedro\Tools\ReIV-analysis\rea-reiv.cmd' function 'C:\Users\pedro\Tools\ReIV-analysis\targets\GTAIV.exe' 0x005b1c30 --provider ghidra --format json
```

Para reproducir las adaptaciones tras reinstalar REA, ejecutar los scripts locales de parche y después ambas pruebas. Una reinstalación de npm puede reemplazar los archivos modificados; el respaldo de configuración permite volver al servidor oficial y `Base.jar.upstream` permite restaurar el lector original de esta instalación separada.

IDA sigue sin configurarse: esta ruta de análisis utiliza Ghidra. Hopper no ofrece el proveedor Windows que requiere REA.

## Nombres de referencia como semillas

Para etiquetar el análisis de Ghidra/REA se pueden usar como candidatos las direcciones nombradas por IV-SDK, plugin_IV e IV-SDK.Net: [sdk_addresses.csv](MemoryMap/sdk_addresses.csv), [plugin_iv_patterns.csv](MemoryMap/plugin_iv_patterns.csv) y [sdknet_addresses.csv](MemoryMap/sdknet_addresses.csv). Son pistas sin validar; confirmar firma y comportamiento en el desensamblado antes de renombrar nada.
