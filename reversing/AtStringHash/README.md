# rage::atStringHash — primer caso de ReIV

**Reconstruida, hookeada y validada en GTA IV PC 1.0.7.0.** Banco aprobado el 6 de octubre de 2026: **8.320 comparaciones sintéticas y 4.096 comparaciones durante llamadas reales**, con cero diferencias. La sesión recibió ambos eventos de carga, procesó 428 ciclos de scripts y cerró con código 0, sin terminación forzada.

La evidencia vinculada a hashes está en [validation-summary.json](evidence/validation-summary.json). Los logs, respaldos y partidas temporales están localmente en `reversing/artifacts/atStringHash-20261006-170938/` y no se publican.

## Identificación

| Campo | Valor |
| --- | --- |
| Binario | SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c` |
| Image base del EXE | `0x00400000` |
| RVA | `0x001B1C30` |
| Dirección estática en Ghidra | `0x005B1C30` |
| Tamaño | 106 bytes, hasta el RET |
| Firma real | `uint32_t __cdecl(const char* text, uint32_t seed)` |
| Fuente reconstruida | [AtStringHash.h](../../source/rage/AtStringHash.h) |
| Banco y hook | [AtStringHashProbe.h](../../source/hooks/AtStringHashProbe.h) |

Se eligió una función corta con dirección documentada y sin dependencias de subsistemas. Los métodos de `CVector` del SDK son implementaciones en línea sin una entrada del EXE identificada: no bastaban para construir el primer banco contra el original.

El EXE se importó en Ghidra y el proyecto se guardó localmente en `build/ghidra-project/ReIV1070.gpr`. El análisis automático global alcanzó el límite configurado de 240 segundos; no se declara completo. El desensamblado y la decompilación de esta función sí se exportaron correctamente mediante [ExportAtStringHash.java](ExportAtStringHash.java). La salida local está en `build/evidence/atStringHash-ghidra.txt`.

Se utilizó [Ghidra 12.1.4 oficial](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.4_build), verificando el SHA-256 del ZIP: `ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db`. La herramienta, el proyecto de Ghidra y el EXE permanecen locales.

**Discrepancia corregida:** `IV-SDK/include/rage.h` declara el segundo parámetro como `uint32_t*`. En este EXE, `MOV ECX,[ESP+8]` obtiene el valor inicial y no lo desreferencia. La reconstrucción y el trampoline usan un entero por valor. Las fuentes de terceros no se modificaron.

## Comportamiento reconstruido

- Si la cadena comienza con comillas dobles, omite la primera y termina en la siguiente o en NUL. Las comillas internas de una cadena sin comillas iniciales son bytes normales.
- Normaliza `A..Z` a `a..z` y barra inversa a `/`.
- Extiende con signo los bytes de 128 a 255, como el `MOVSX` original.
- Usa acumulación y mezcla de enteros de 32 bits, con desbordamiento modular. También aplica la mezcla final a una cadena vacía y un seed no nulo.
- No modifica la cadena ni usa funciones originales en su implementación pura. El banco requiere una cadena accesible y terminada en NUL; no prueba punteros nulos o inválidos.

## Validación e instalación del hook

Antes de alterar memoria se comprueban los 106 bytes de la función contra la copia canónica. El banco cubre cadenas vacías, mayúsculas, rutas, comillas abiertas/cerradas, NUL interno, una cadena de 4.096 caracteres, todos los bytes no nulos con y sin comillas, ocho seeds y 4.096 cadenas generadas mediante un PRNG fijo. Compara el retorno exacto y comprueba que la cadena permanece intacta.

Sólo después de aprobar el banco se instala un JMP. El trampoline conserva las dos primeras instrucciones completas (MOV de cuatro bytes y PUSH de un byte) y salta al original después de ellas. Se prueba explícitamente la entrada parcheada y se comprueba que aumenta el contador del reemplazo. Las primeras 4.096 llamadas reales se contrastan con el trampoline.

Se contaron **383.860 llamadas al reemplazo** durante la sesión. Eso mide uso real, no 383.860 comparaciones: únicamente las primeras 4.096 se compararon con el original. No constituye una prueba exhaustiva de todos los inputs ni una campaña de estabilidad general.

`standalone=0` en el catálogo: aunque la implementación matemática es independiente, la sonda conserva llamadas al original para la comparación. Todavía no existe un ejecutable standalone.

## Repetir el banco

Cerrar cualquier GTAIV abierto, compilar y ejecutar:

```powershell
powershell -ExecutionPolicy Bypass -File .\contrib\build-reiv.ps1
powershell -ExecutionPolicy Bypass -File .\reversing\AtStringHash\run.ps1
```

El runner verifica el hash del EXE y usa exclusivamente `GTAIV.exe`. Respalda ASI, símbolos, configuración y logs; habilita temporalmente el inicio directo a partida con rutas separadas para partidas y ajustes. Un marcador de prueba permite solicitar un cierre normal tras 20 segundos de procesamiento de scripts. El timeout de 120 segundos se registra como terminación forzada y hace fallar el caso. Los archivos preexistentes se restauran al terminar.

El ASI de uso normal también incluye el banco inicial y el hook, pero no solicita el cierre automático si el marcador está ausente. Los hooks generales de eventos de IV-SDK siguen activos.
