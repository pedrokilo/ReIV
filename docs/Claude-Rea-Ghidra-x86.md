# Entrega a Claude: REA + Ghidra en Windows para GTA IV y GTA SA x86

Fecha: 7 de octubre de 2026. Esta guía describe una instalación local probada en el equipo de Pedro y cómo ampliarla para `gta_sa.exe`/`gtasa.exe` de 32 bits. GTA SA todavía no está admitido ni se ha probado con esta adaptación.

## 1. Qué está configurado globalmente

El servidor REA está registrado en la configuración de usuario de **Codex**, `C:\Users\pedro\.codex\config.toml`. Puede utilizarse desde sus proyectos después de reiniciar/reconectar el servidor, sujeto a las restricciones del proveedor y del cliente. No es una configuración exclusiva del repositorio ReIV.

**No está registrado automáticamente en Claude.** `GHIDRA_INSTALL_DIR` y `JAVA_HOME` se suministran al proceso MCP de REA en la configuración de Codex. No se estableció `GHIDRA_INSTALL_DIR` como variable global de usuario o de sistema Windows. El lanzador `rea-reiv.cmd` también proporciona esas variables para las consultas por terminal.

La adaptación **no admite cualquier EXE de 32 bits**. Solo añade el GTAIV.exe con SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`. La admisión x64 existente se conserva. Para GTA SA habrá que registrar explícitamente el hash del binario elegido y verificarlo.

## 2. Rutas exactas en este equipo

Directorio principal: `C:\Users\pedro\Tools\ReIV-analysis`.

| Elemento | Ruta relativa al directorio principal |
| --- | --- |
| Instalación de Ghidra modificada | `ghidra_12.1.4_PUBLIC` |
| Paquete REA modificado | `rea-x86\node_modules\rea-agents` |
| Entrada del servidor MCP | `rea-x86\node_modules\rea-agents\scripts\rea.mjs` |
| Parche reproducible del proveedor | `patch-rea-x86.mjs` |
| Parche reproducible de lectores Ghidra | `patch-ghidra-reader.ps1` |
| Lanzador CLI con entorno configurado | `rea-reiv.cmd` |
| Copia de GTA IV usada para análisis | `targets\GTAIV.exe` |
| Prueba real MCP de GTA IV | `rea-x86\verify.mjs` |
| Comprobación de respuestas y bytes | `rea-x86\check-evidence.mjs` |
| Prueba de lectores y bloqueo nativo | `rea-x86\verify-reader.mjs` |
| Prueba Java del lector | `ghidra-patch\ReaderProbe.java` |
| Fuentes oficiales de lectores | `ghidra-patch\FileByteProvider.upstream.java`, `ghidra-patch\FSUtilities.upstream.java` |
| Fuentes adaptados | `ghidra-patch\src\ghidra\app\util\bin\FileByteProvider.java`, `ghidra-patch\src\ghidra\formats\gfilesystem\FSUtilities.java` |
| Respaldo del JAR original | `ghidra_12.1.4_PUBLIC\Ghidra\Features\Base\lib\Base.jar.upstream` |
| Respuestas completas y manifiesto de hashes | `evidence` |
| Resumen de la prueba | `evidence\verification-summary.json` |
| Manifiesto de instalación local | `evidence\local-installation.json` |

Node: `C:\Program Files\nodejs\node.exe` (24.16.0 durante la prueba).

JDK: `C:\Program Files\Eclipse Adoptium\jdk-25.0.3.9-hotspot`.

Registro original: `C:\Users\pedro\OneDrive\Desktop\GTA IV\ReIV\docs\ReaGhidra.md`.

Resumen guardado en el repositorio: `C:\Users\pedro\OneDrive\Desktop\GTA IV\ReIV\reversing\AtStringHash\evidence\rea-ghidra-verification.json`.

El respaldo `config.toml.before-rea-x86` contiene la configuración anterior de Codex. Para el traspaso basta con el fragmento REA de esta guía; no es necesario compartir el archivo de configuración completo.

## 3. Configuración aplicada en Codex

```toml
[mcp_servers.rea]
command = 'C:\Program Files\nodejs\node.exe'
args = [ 'C:\Users\pedro\Tools\ReIV-analysis\rea-x86\node_modules\rea-agents\scripts\rea.mjs', 'mcp' ]
startup_timeout_sec = 60
tool_timeout_sec = 1900

[mcp_servers.rea.env]
GHIDRA_INSTALL_DIR = 'C:\Users\pedro\Tools\ReIV-analysis\ghidra_12.1.4_PUBLIC'
JAVA_HOME = 'C:\Program Files\Eclipse Adoptium\jdk-25.0.3.9-hotspot'
```

Los tiempos anteriores son campos de Codex; no deben copiarse como supuestos campos equivalentes de Claude. La conexión ya iniciada conserva el código y entorno anteriores hasta reconectarse.

## 4. Conectar Claude Code en este mismo equipo

Primero inspeccionar sus servidores existentes. Para añadir una entrada separada de usuario, usar la [documentación oficial de MCP de Claude Code](https://code.claude.com/docs/en/mcp):

```powershell
claude mcp list
claude mcp add --scope user --env 'GHIDRA_INSTALL_DIR=C:\Users\pedro\Tools\ReIV-analysis\ghidra_12.1.4_PUBLIC' 'JAVA_HOME=C:\Program Files\Eclipse Adoptium\jdk-25.0.3.9-hotspot' --transport stdio rea-reiv -- 'C:\Program Files\nodejs\node.exe' 'C:\Users\pedro\Tools\ReIV-analysis\rea-x86\node_modules\rea-agents\scripts\rea.mjs' mcp
claude mcp get rea-reiv
```

`--scope user` permite reutilizar la entrada en los proyectos de Claude Code. La inscripción anterior es una instrucción de entrega, **no se ejecutó en Claude durante el trabajo de Codex**. Si ya existe `rea-reiv`, revisar su definición antes de actualizarla. Reconectar y verificar que aparecen realmente las herramientas; un archivo de configuración correcto no prueba la conexión.

Para otro cliente de Claude con servidores stdio, adaptar a su formato una entrada con estos valores:

```json
{
  "command": "C:\\Program Files\\nodejs\\node.exe",
  "args": [
    "C:\\Users\\pedro\\Tools\\ReIV-analysis\\rea-x86\\node_modules\\rea-agents\\scripts\\rea.mjs",
    "mcp"
  ],
  "env": {
    "GHIDRA_INSTALL_DIR": "C:\\Users\\pedro\\Tools\\ReIV-analysis\\ghidra_12.1.4_PUBLIC",
    "JAVA_HOME": "C:\\Program Files\\Eclipse Adoptium\\jdk-25.0.3.9-hotspot"
  }
}
```

El cliente necesita acceso local a estas rutas. Pegar el MD en una conversación web sin herramientas locales no le da acceso a los archivos ni inicia el servidor.

## 5. Qué se modificó y por qué

### REA 5.0.0

Ghidra ya analiza x86; no hace falta una edición especial de Ghidra de 32 bits. La restricción pertenecía al proveedor Windows P0 de REA, documentado para aplicaciones PE x86-64.

Leer `patch-rea-x86.mjs` antes de cambiarlo. Sus modificaciones son:

1. `dist\ghidra\GhidraProvider.js`: permite `architecture === "x86"` únicamente cuando `target.sha256` coincide con la referencia de GTA IV. Mantiene las comprobaciones de PE, aplicación nativa y exclusión de DLL/administrados.
2. `dist\ghidra\GhidraProviderCapabilities.js`: declara la extensión local en las limitaciones devueltas con la evidencia.
3. `dist\ghidra\GhidraAnalysisProfile.js`: añade `local_provider_extension: "reiv-gtaiv-x86-sha256-bound-v1"` al perfil.
4. `dist\ghidra\GhidraProviderClient.js`: para x86 permite hasta `1_800_000` ms de arranque y exige lenguaje `x86:LE:32:default` y compilador `windows` en el handshake.

El parche guarda originales `.upstream` y verifica que cada sustitución corresponde al contenido esperado. Es una modificación del paquete compilado local, no un cambio publicado en REA. Una actualización/reinstalación npm puede sobrescribirla.

### Lectores de Ghidra 12.1.4

Se encontró una infracción de uso compartido en Windows: REA conserva handles de la copia privada con acceso de escritura/borrado para su ciclo de vida, mientras rechaza escrituras y borrados de terceros. Los lectores Java `RandomAccessFile` y `FileInputStream` no compartían ese acceso y no podían abrir el snapshot.

La reparación preservó los handles nativos y cambió dos lectores en `Base.jar`:

- `FileByteProvider`: canal `FileChannel`, con lectura, posición, tamaño y escritura completos; mantiene su buffer y comportamiento de lector/escritor.
- `FSUtilities.getFileMD5`: `Files.newInputStream` para calcular MD5.

`patch-ghidra-reader.ps1` compila los fuentes adaptados con `--release 21` usando el JDK existente y actualiza el JAR. Las pruebas comprobaron lectura del snapshot, MD5, límites de buffer y escritura en un archivo de prueba independiente, además del rechazo de escritura y renombrado del snapshot.

Los controles nativos Windows de REA, las DACL privadas, los Job Objects, el transporte autenticado y el cierre de sesiones siguen activos. No quitar estas protecciones para admitir GTA SA.

## 6. Resultado probado en GTA IV

- Binario de referencia: GTA IV PC 1.0.7.0, PE32 / x86.
- SHA-256: `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- Ghidra: lenguaje `x86:LE:32:default`, compilador `windows`.
- Función: `atStringHash`, dirección estática `0x005B1C30`.
- 106 bytes leídos mediante REA coinciden exactamente con el EXE en el offset de archivo `1776688`, obtenido del mapeo de Ghidra.
- Pseudocódigo y dossier recuperados; 694 funciones llamadoras y 1.638 referencias entrantes estáticas.
- Análisis automático completo de la última prueba: unos 6 minutos y 25 segundos. Consultas posteriores reutilizan esa sesión.
- Cierre correcto y limpieza de los proyectos temporales. El EXE original conserva su hash.

La respuesta guardada del dossier completo ocupa `19.455.935` bytes. El SDK de prueba tenía un buffer predeterminado de 10 MiB y cerró la conexión cuando el resultado lo excedió. `verify.mjs` utiliza un buffer de 256 MiB. Este ajuste corresponde al cliente de prueba, no configura el límite de Claude ni de Codex. Preferir consultas específicas para funciones con muchas referencias y guardar la evidencia extensa en archivos.

Evidencia de pseudocódigo: `ev_38f123aeadf3bbd5ecdec7f4b5379433a16ce722dcdf53247b063c724bc1414f`. Los demás identificadores están en el resumen JSON. Son observaciones estáticas de Ghidra; no equivalen a probar ejecución del juego ni reconstrucción semántica completa.

## 7. Cómo ampliar la instalación para GTA SA

1. Leer esta guía, los dos scripts de parche y las pruebas existentes. Inspeccionar herramientas y versiones instaladas; reutilizar Ghidra y Java disponibles.
2. Localizar el `gta_sa.exe`/`gtasa.exe` indicado por el usuario en su proyecto o instalación. Si hay candidatos distintos y no hay evidencia para elegir, pedir la ruta exacta. No asumir una edición, versión o hash de Internet.
3. Medir SHA-256, tamaño, recursos de versión y cabeceras PE. Confirmar PE32, máquina `0x014C`, aplicación nativa y ausencia de CLR. Crear una copia identificada por hash fuera de carpetas sincronizadas, en un volumen NTFS local admitido.
4. Preparar un respaldo de los archivos del proveedor que se vayan a modificar. Ampliar la admisión mediante una lista explícita de hashes para las referencias GTA IV y GTA SA. Conservar GTA IV y la admisión x64 existente. No reemplazar simplemente el hash de GTA IV por el de GTA SA.
5. Actualizar tanto el parche reproducible como el proveedor instalado. El parche actual reconoce sus propias sustituciones; editar únicamente el hash en el script y ejecutarlo sobre un paquete ya parcheado puede fallar. Implementar una migración comprobada del estado instalado o partir de originales `.upstream` coincidentes, sin perder los cambios anteriores.
6. Actualizar el identificador del perfil y las limitaciones para describir la nueva extensión. Mantener el handshake x86 y un timeout suficiente; no fingir análisis completo cuando se haya cancelado o agotado el tiempo.
7. Reutilizar los lectores NIO ya instalados. No recompilar ni reemplazar `Base.jar` si sus hashes y pruebas demuestran que la reparación sigue presente. Si hace falta repararlo, usar los fuentes y respaldos existentes.
8. Añadir pruebas de política: los hashes autorizados pasan; un x86 ajeno, DLL, administrado, formato distinto y arquitectura no admitida siguen rechazados. Verificar que GTA IV conserva su admisión y sus archivos de referencia.
9. Crear una prueba MCP específica de GTA SA. Los verificadores actuales contienen ruta, tamaño, MD5 calculado y dirección de GTA IV; son ejemplos, no pruebas válidas de GTA SA sin adaptar. Elegir una función pequeña del propio binario mediante evidencia de análisis. No reutilizar `0x005B1C30` ni los 106 bytes de GTA IV.
10. Abrir la copia de GTA SA con proveedor Ghidra; esperar análisis completo, recuperar pseudocódigo, leer bytes, obtener el offset de origen y comparar esos bytes con el archivo identificado por hash. No derivar el offset suponiendo que RVA y offset son iguales. Evitar zonas con relocaciones si la prueba espera igualdad literal.
11. Cerrar la sesión, comprobar limpieza de recursos y verificar que el original sigue conservando su hash. Guardar respuestas completas, identificadores de evidencia, hashes del paquete/parches/JAR, resultados y limitaciones.
12. Registrar/reconectar el servidor en el cliente Claude utilizado, preservando sus otras entradas. Si requiere reinicio, explicar el paso concreto. Actualizar esta guía o crear un registro específico de GTA SA con las rutas y las pruebas reales.

## 8. Reproducción en otro equipo

Este MD entrega el contexto y las rutas; **no contiene los ejecutables ni todos los fuentes**. En el mismo equipo, Claude puede leer los archivos enumerados. En otro equipo necesita los scripts, pruebas y fuentes de `ghidra-patch`, o una reconstrucción de esos archivos a partir de la modificación descrita, además de instalar las herramientas y recibir una copia del juego proporcionada por el usuario.

Versiones usadas: `rea-agents@5.0.0`, Ghidra 12.1.4 y un JDK completo. La carpeta `rea-x86` conserva `package.json` y `package-lock.json`, incluidos los módulos necesarios para el cliente MCP de prueba. Las rutas absolutas de los scripts deben ajustarse al equipo receptor.

Procedencia de Ghidra: [release oficial](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.4_build), ZIP `ghidra_12.1.4_PUBLIC_20260921.zip`, SHA-256 `ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db`. El JAR de la instalación local difiere del original por la reparación descrita; comprobar el manifiesto local.

Fuentes oficiales de los lectores: [FileByteProvider.java](https://github.com/NationalSecurityAgency/ghidra/blob/Ghidra_12.1.4_build/Ghidra/Features/Base/src/main/java/ghidra/app/util/bin/FileByteProvider.java) y [FSUtilities.java](https://github.com/NationalSecurityAgency/ghidra/blob/Ghidra_12.1.4_build/Ghidra/Features/Base/src/main/java/ghidra/formats/gfilesystem/FSUtilities.java).

IDA permanece sin configurar y Hopper no es un proveedor compatible en este Windows. La ruta probada utiliza Ghidra.

## 9. Prompt para Claude

Lee `C:\Users\pedro\OneDrive\Desktop\GTA IV\ReIV\docs\Claude-Rea-Ghidra-x86.md` y los scripts locales que enumera. Quiero que adaptes y configures REA Agents con Ghidra para analizar mi `gta_sa.exe`/`gtasa.exe` de 32 bits en Windows, con el mismo flujo que ya se verificó para GTA IV. Trabaja sobre la instalación existente de `C:\Users\pedro\Tools\ReIV-analysis` y conserva el soporte validado de GTA IV.

Localiza mi ejecutable desde el proyecto o la instalación con que estés trabajando; si no puedes identificarlo inequívocamente, pide su ruta. Comprueba arquitectura, versión disponible y SHA-256; admite esa copia de GTA SA por su hash además del GTA IV existente. Actualiza el parche reproducible y el paquete instalado, el perfil de evidencia y las limitaciones. Preserva los controles nativos, los lectores NIO ya probados, los respaldos y las demás configuraciones.

Configura el servidor MCP en el cliente Claude que esté usando; si es Claude Code, usa alcance de usuario para reutilizarlo entre proyectos. Verifica la conexión real. Después ejecuta una prueba completa sobre una función pequeña identificada en este GTA SA: análisis automático terminado, pseudocódigo, bytes, mapeo al archivo, comparación exacta con el original y cierre limpio. Adapta las pruebas a GTA SA; no copies la dirección ni los bytes de GTA IV. Guarda la evidencia y un MD con rutas, cambios, verificación y recuperación. Continúa hasta verificar el resultado; si encuentras un impedimento real, explica exactamente cuál y qué falta. No declares soporte funcionando solo porque hayas cambiado una variable o porque el proveedor acepte el archivo.

## Referencias de nombres

Al nombrar funciones desde el análisis, consultar primero la columna `reference_names` de [hooks.csv](hooks.csv) y los CSV de [MemoryMap](MemoryMap/README.md). Una dirección que dos SDKs nombran igual (por ejemplo IV-SDK e IV-SDK.Net) es una pista más fuerte, pero sigue sin validar.
