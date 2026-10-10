<img src="docs/images/Logo%20Re%20IV%20estilo%20Grand%20Theft%20Auto.png" alt="ReIV logo" width="400">

# GTA IV · Reversing en ReIV

Recrear **GTA IV PC 1.0.7.0** de forma funcionalmente equivalente mediante código C++ reconstruido y validado contra el ejecutable original. La meta es reducir hasta eliminar la dependencia de sus funciones y, finalmente, construir un ejecutable propio que utilice los recursos del juego proporcionados por el usuario.

**[📊 Estado](#estado-del-trabajo) · [🧭 Plan](#plan-de-trabajo) · [🧪 Validación](#validación-contra-el-original) · [📁 Estructura](#estructura-del-repositorio)**

**[🗺 Mapa de memoria](docs/MemoryMap/README.md) · [Visor local de direcciones](docs/MemoryMap/index.html)** — 4.016 tipos RTTI, 3.478 vtables y 34.141 direcciones de código fichadas, con procedencia y referencias separadas del SDK y del documento histórico. Este inventario no añade reconstrucciones ni validaciones.

> [!NOTE]
> Primera función reconstruida, hookeada y validada: [rage::atStringHash](reversing/AtStringHash/README.md). `ReIV.asi` usa IV-SDK y la copia de pruebas arranca directamente con `GTAIV.exe`, en ventana. Todavía no existe un ejecutable independiente. [Compilación y configuración de pruebas](reversing/Bootstrap.md).

[REA y Ghidra para este ejecutable x86](docs/ReaGhidra.md): instalación local, adaptaciones, evidencia y recuperación.

[FLOSS: instalación local y análisis de cadenas](docs/FLOSS.md). Disponible para Codex y Claude en `C:\Users\pedro\Tools\FLOSS\floss.exe`; todavía no hay resultados de FLOSS registrados para ReIV.

## Intro

### Cómo funciona

La primera etapa prevé compilar una DLL x86 y cargarla en una copia de pruebas de GTA IV. Los hooks redirigirán funciones concretas del ejecutable a las implementaciones propias. Cada sustitución se comparará con la función original antes de declararla validada.

La segunda etapa reducirá las llamadas directas y transitivas al ejecutable. El standalone llegará cuando los subsistemas necesarios puedan funcionar con implementaciones propias; tener todas las clases declaradas no demuestra esa independencia.

### Versión de referencia

| Dato | Objetivo |
| --- | --- |
| Juego | GTA IV PC |
| Versión | 1.0.7.0, verificada en FileVersion y ProductVersion; edición EFIGS pendiente de confirmar |
| Arquitectura | x86 / 32 bits |
| Ejecutable | `GTAIV.exe` |
| SHA-256 canónico | `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c` |

Verificación local del 6 de octubre de 2026: archivo de **15.505.792 bytes**, cabecera PE válida, máquina `0x014C` (Intel i386) y formato PE32 `0x010B`. Detalles en [el registro del binario de referencia](docs/ReferenceBinary.md). La versión declarada y el hash identifican esta copia; no acreditan por sí solos que sea un ejecutable original sin modificaciones.

Cada dirección, offset y evidencia deberá corresponder al binario identificado por ese hash. Otras versiones se estudiarán por separado.

## Preparación

1. Conservar una copia original de `GTAIV.exe` fuera del repositorio y crear otra instalación para pruebas.
2. Verificar versión y arquitectura; calcular el hash con `Get-FileHash .\GTAIV.exe -Algorithm SHA256`.
3. Importar ese binario en Ghidra para análisis estático x86; usar x32dbg para comprobaciones dinámicas.
4. Compilar con Visual Studio y herramientas C++ mediante `contrib/build-reiv.ps1`. La base actual usa MSBuild; la integración con CMake está pendiente.
5. Elegir una clase pequeña y llevarla por todo el recorrido: identificación, C++, hook y comparación con el original.

Las partidas y configuraciones personales se conservarán fuera de los bancos. Las sondas deberán respaldar y restaurar los archivos que sustituyan, registrar hashes y cerrar únicamente el proceso que ellas mismas abran.

## Estructura del repositorio

Se conserva la distribución existente, incluidos los nombres de las carpetas de referencias:

```text
ReIV/
├── bin/                         Artefactos de ReIV previstos
├── cmake/                       Soporte de compilación previsto
├── contrib/
│   ├── IV SDK/
│   ├── IV SDK.Net/
│   ├── Plugin SDK (es el mismo que se usa para GTA SA)/
│   └── x64dbg/
├── docs/
│   └── images/
├── reversing/                   Bancos, direcciones y evidencias previstos
├── source/                      Implementaciones propias, organizadas según la base del SDK
│   ├── core/                    Entrada del ASI y eventos
│   ├── rage/                    Funciones del motor RAGE
│   ├── game/                    Clases y sistemas del juego
│   ├── Scripting/               Scripting
│   └── hooks/                   Hooks y bancos integrados
└── README.md
```

Las carpetas existentes se conservan. La base de compilación, fuente y documentación está en `cmake`, `source` y `reversing`; los binarios locales se generan en `bin`. Los catálogos se añadirán conforme se implementen.

### Referencias y criterio de evidencia

IV-SDK y el componente de GTA IV de plugin-sdk servirán para contrastar nombres, tamaños, herencia, miembros, virtuales, firmas y direcciones. IV-SDK-DotNet aportará contexto sobre sus wrappers y usos. **El ejecutable canónico decide cuando haya discrepancias.** Una coincidencia entre SDKs es una pista y debe contrastarse con el binario.

LibertyRecomp, Xbox 360, otras versiones PC y EFLC podrán incorporarse posteriormente como referencias comparativas. Sus direcciones y layouts no se trasladarán automáticamente a PC 1.0.7.0. El código de terceros conserva sus licencias y avisos originales.

## Mejoras

### Estado del trabajo

**Entrega del 6 de octubre de 2026:** binario canónico registrado, proyecto importado en Ghidra y primera función reconstruida y validada. [rage::atStringHash](reversing/AtStringHash/README.md) pasó 8.320 comparaciones sintéticas y 4.096 comparaciones durante llamadas reales, sin diferencias. El hook recibió 383.860 llamadas; llegaron ambos eventos de carga, se procesaron 428 ciclos de scripts y el juego cerró con código 0 sin terminación forzada. El usuario confirmó la entrada a partida y una cinemática. Esto valida el primer caso, no todos los sistemas del juego.

| Dimensión | Estado |
| --- | --- |
| Funciones identificadas | 1 en el [catálogo inicial](docs/functions.csv) |
| Funciones reconstruidas | 1: `rage::atStringHash` |
| Hooks instalados y comprobados | 1 propio, además de los eventos de IV-SDK |
| Funciones validadas contra el original | 1, con [evidencia vinculada](reversing/AtStringHash/evidence/validation-summary.json) |
| Funciones independientes del EXE | La implementación pura del hash es independiente; la sonda aún llama al original para comparar |
| Standalone | Objetivo a largo plazo |

No se publicarán porcentajes hasta definir y comprobar los denominadores del catálogo.

### Dimensiones de progreso

Cada función tendrá estados separados:

| Estado | Condición para registrarlo |
| --- | --- |
| `identified` | Dirección y firma identificadas para el hash canónico, con evidencia |
| `reversed` | Implementación propia reconstruida; un wrapper que llama al EXE no basta |
| `hooked` | Redirección a la implementación propia comprobada en ejecución |
| `validated` | Banco comparativo aprobado y evidencia vinculada a la revisión probada |
| `standalone` | Dependencias directas y transitivas de funciones originales eliminadas y comprobadas |

También se registrarán bloqueos, dependencias y vigencia de las pruebas. Un cambio en una función o sus dependencias requiere revisar la evidencia anterior.

## Plan de trabajo

| Fase | Trabajo | Criterio de salida |
| --- | --- | --- |
| 0 · Referencia | Congelar versión, hash y copia de pruebas | Binario canónico identificado |
| 1 · Análisis | Importar en Ghidra y contrastar SDKs | Primera clase con firmas, tamaños y offsets documentados |
| 2 · Catálogo | Registrar funciones, clases, direcciones, estados y dependencias en `docs/` | Entradas trazables al EXE, sin direcciones de ejemplo |
| 3 · Compilación | Preparar C++ x86, CMake y carga de DLL | Artefacto reproducible que arranca en la copia de pruebas |
| 4 · Primera reconstrucción | Implementar una clase pequeña y conectar sus hooks | Sustituciones verificadas en runtime |
| 5 · Primera validación | Comparar original y reconstrucción con entradas equivalentes | Banco aprobado, logs y hashes archivados |
| 6 · Automatización | Auditar fuente, catálogo, hooks activos y evidencias | Detectar estados incoherentes y validaciones sin respaldo |
| 7 · Subsistemas | Extender reconstrucción y bancos según dependencias | Avance medido por función y subsistema |
| 8 · Comparación adicional | Contrastar otras versiones PC, Xbox 360 y EFLC cuando ayuden | Hipótesis confirmadas en el binario canónico |
| 9 · Independencia | Sustituir llamadas y dependencias del EXE | Auditoría de dependencias y pruebas de integración |
| 10 · Standalone | Integrar arranque, motor y carga de recursos en ejecutable propio | Ejecución sin funciones del `GTAIV.exe` original |

Orden inicial por dependencias: núcleo de RAGE, matemáticas y memoria; streaming; entidades y mundo; peds y vehículos; física y animación; IA y tareas; armas; audio; renderizado; scripts y UI. El orden se ajustará a lo que revele el análisis.

### Validación contra el original

Los bancos en `reversing/` compararán entradas equivalentes y estados iniciales controlados. Según la función, comprobarán valores de retorno, memoria, estado de objetos, efectos secundarios, llamadas, flags y errores. Los números flotantes requerirán un criterio explícito de comparación.

Cada evidencia deberá incluir hash del EXE, revisión del código, hash de la DLL, funciones y hooks efectivos, casos y resultados, exclusiones y limitaciones. Compilar o llegar al menú son comprobaciones de integración, pero no acreditan equivalencia de una función.

La automatización detectará, entre otros casos, hooks activos fuera del catálogo, wrappers marcados como reconstruidos, registros validados sin evidencia y funciones declaradas independientes que todavía llaman al original. Las pruebas conjuntas y sesiones prolongadas complementarán los bancos individuales.

### Primer hito

- [x] Verificar `GTAIV.exe` 1.0.7.0 y registrar SHA-256.
- [x] Importar el binario en Ghidra.
- [ ] Seleccionar una clase pequeña y catalogar sus funciones.
- [ ] Contrastar firmas y layouts con las referencias.
- [x] Preparar una compilación C++ x86 reproducible.
- [ ] Reconstruir, hookear y comparar la clase contra el original.
- [x] Archivar evidencia y comprobar la restauración de la instalación de pruebas.

El primer recorrido completo se hizo con una función libre de RAGE, `atStringHash`. La selección y reconstrucción de una clase completa siguen pendientes.

## Créditos

- Todos los colaboradores del proyecto [plugin-sdk](https://github.com/DK22Pac/plugin-sdk).
- [IV-SDK de Zolika1351](https://github.com/Zolika1351/iv-sdk), referencia principal del proyecto para GTA IV 1.0.7.0.
- [IV-SDK-DotNet de ClonkAndre](https://github.com/ClonkAndre/IV-SDK-DotNet).
- Cientos de personas que han compartido sus conocimientos en [gtaforums.com](https://gtaforums.com/topic/194199-documenting-gta-sa-memory-addresses).
