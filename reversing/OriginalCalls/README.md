# Llamadas a funciones originales

La primera vinculación es `CDynamicEntity::GetBoneMatrix`, para el EXE canónico de GTA IV PC 1.0.7.0 x86. Sigue llamando al juego; no es una reconstrucción ni instala un hook.

| Dato | Valor |
| --- | --- |
| RVA | `0x005C7710` |
| VA con base preferida `0x00400000` | `0x009C7710` |
| Firma candidata del SDK | `CMatrix* (__thiscall*)(CDynamicEntity*, int)` |
| Fuente | `contrib/IV SDK/IV-SDK-main/include/CDynamicEntity.h:11` |
| SHA-256 del EXE | `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c` |

## Uso

```cpp
#include "game/scene/CDynamicEntity.h"

// entity debe ser una instancia real y válida del juego/SDK.
// boneID debe corresponder al esqueleto de esa instancia.
::CMatrix* matrix = reiv::game::CDynamicEntity::GetBoneMatrix(entity, boneID);
```

El método recibe explícitamente el puntero original: la clase de ReIV es un puente estático, no una estructura C++ con campos o herencia reconstruidos. No se debe crear una instancia de este puente ni convertir su dirección en una entidad del juego. La matriz devuelta pertenece al juego; no liberarla. La disponibilidad de una dirección no acredita la validez o vida útil de una entidad ni de su índice de hueso.

`source/core/OriginalCall` comprueba una vez el hash del EXE anfitrión y su formato PE32 x86. Resuelve cada función como `base real + RVA`, comprobando rango, memoria ejecutable legible y firma de entrada. Un EXE diferente, bytes cambiados, una entidad nula o una vinculación no disponible dan `nullptr` en este wrapper. El log de inicio distingue disponibilidad de la vinculación de una llamada realmente probada. Las convenciones `Cdecl`, `Stdcall` y `Thiscall` requieren firmas explícitas.

No instalar un hook sobre este destino y seguir llamándolo mediante este wrapper: una sustitución necesita un trampoline separado. La firma de entrada permite rechazar cambios en los primeros bytes; no inspecciona todas las modificaciones posibles del cuerpo.

## Comprobaciones

- Dirección y primeros 16 bytes contrastados con el EXE de hash canónico mediante mapeo PE.
- [Desensamblado acotado](evidence/GetBoneMatrix.asm.txt): `ECX` contiene `this`, se lee un argumento de 32 bits en la pila, se devuelve una dirección en `EAX` y ambas salidas usan `ret 4`. Esto corrobora la convención `__thiscall` del SDK. El nombre semántico `CMatrix` y el comportamiento con entidades reales siguen pendientes de validar.
- Compilación completa `Release|Win32` mediante `contrib/build-reiv.ps1`.
- `check-original-calls.cpp`: llamadas x86 cdecl/stdcall/thiscall, 10.000 iteraciones, rechazo del anfitrión de pruebas, rechazo de wrapper nulo o no vinculado. En este banco, la equivalencia de un puntero a método simple con el destino `thiscall` se comprueba con MSVC x86; no se extrapola a herencia múltiple.
- Prueba en juego aprobada el 9 de octubre de 2026: 64 llamadas al hueso raíz (`0`) de la entidad devuelta por `FindPlayerPed()`, sin fallos ni excepciones. Cada llamada devolvió el mismo puntero que el SDK, una matriz con componentes finitos y un destino distinto del fallback de identidad. El proceso cerró con código 0, sin terminación forzada.
- Alcance: carga de escena tras `gameLoadEvent`, antes de `ingameStartupEvent`. No demuestra comportamiento durante gameplay completo, otros huesos ni otras entidades. El SDK es otra ruta hacia la misma función original, no una implementación independiente de comparación. La prueba valida el wrapper en ese escenario; no valida una reconstrucción.

La [evidencia](evidence/CDynamicEntity.GetBoneMatrix.json) registra identidad, dirección, firma de bytes y límites de validación. Las declaraciones propias se guardan en `reversing/MemoryMap/declarations/CDynamicEntity.inc`; el generador de headers las conserva.

El [resultado en juego](evidence/runtime-summary.json) registra los hashes y contadores; el [log](evidence/runtime-ReIV.log) conserva la carga y cierre. Para repetir: `powershell -ExecutionPolicy Bypass -File reversing/OriginalCalls/run.ps1`. El banco usa un marcador temporal, aisla saves/settings y restaura los archivos previos de la copia de pruebas. Sin marcador, el probe no ejecuta llamadas ni cierra el juego. El primer intento quedó sin llamadas por esperar `ingameStartupEvent`; se corrigió el banco para esperar una entidad real tras `gameLoadEvent`.
