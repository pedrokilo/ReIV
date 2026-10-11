# Auditoría de `source/`

[Inicio](../README.md) · [Progreso del reversing](ReversedClasses.md) · [Organización de source](../source/README.md)

> Generado por `tools/ReIV.Tools audit` (C#). Solo lee `source/`; detalle por archivo en [source_audit.csv](source_audit.csv).

Se revisan dos reglas, como en ReSA: **cada clase tiene su `.h` y su `.cpp`** (con sus subcarpetas) y **todo está escrito en C++, no en ensamblador**.

## Resumen

| Medida | Cantidad |
| --- | ---: |
| Headers | 4,053 |
| — de tipos RTTI generados (identidad y tabla de direcciones, sin código) | 4,016 |
| — escritos a mano con código | 2 |
| — de solo datos o declaraciones (sin cuerpos de función) | 35 |
| Archivos `.cpp` | 28 |
| Headers con su `.cpp` | 27 |
| Headers sin `.cpp` | 4,026 |
| — de ellos, con código que debería tener `.cpp` | 0 |
| `.cpp` sin `.h` | 1 |
| Archivos con ensamblador (`__asm` o `naked`) | 3 |
| Bloques `__asm` | 59 |
| Funciones `naked` | 20 |

## Headers sin `.cpp` por carpeta

| Carpeta | Headers | De tipos RTTI | A mano o datos | Con `.cpp` | Sin `.cpp` | Con ensamblador |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `core` | 4 | 0 | 4 | 2 | 2 | 0 |
| `external` | 48 | 48 | 0 | 0 | 48 | 0 |
| `game/Cutscene` | 1 | 1 | 0 | 0 | 1 | 0 |
| `game/Objects` | 2 | 2 | 0 | 0 | 2 | 0 |
| `game/PedGroup` | 8 | 8 | 0 | 0 | 8 | 0 |
| `game/Peds` | 37 | 37 | 0 | 1 | 36 | 1 |
| `game/Stats` | 7 | 7 | 0 | 0 | 7 | 0 |
| `game/Vehicles` | 10 | 10 | 0 | 0 | 10 | 0 |
| `game/animation` | 14 | 14 | 0 | 0 | 14 | 0 |
| `game/audio` | 28 | 28 | 0 | 0 | 28 | 0 |
| `game/camera` | 176 | 176 | 0 | 0 | 176 | 0 |
| `game/control` | 12 | 12 | 0 | 0 | 12 | 0 |
| `game/event` | 85 | 85 | 0 | 0 | 85 | 0 |
| `game/frontend` | 70 | 70 | 0 | 0 | 70 | 0 |
| `game/ik` | 2 | 2 | 0 | 0 | 2 | 0 |
| `game/modelinfo` | 7 | 7 | 0 | 0 | 7 | 0 |
| `game/network` | 159 | 159 | 0 | 0 | 159 | 0 |
| `game/physics` | 30 | 30 | 0 | 0 | 30 | 0 |
| `game/renderer` | 137 | 137 | 0 | 0 | 137 | 0 |
| `game/scene` | 11 | 11 | 0 | 1 | 10 | 0 |
| `game/script` | 5 | 5 | 0 | 0 | 5 | 0 |
| `game/shaders` | 8 | 8 | 0 | 0 | 8 | 0 |
| `game/streaming` | 3 | 3 | 0 | 0 | 3 | 0 |
| `game/system` | 5 | 5 | 0 | 0 | 5 | 0 |
| `game/task` | 390 | 390 | 0 | 0 | 390 | 0 |
| `game/templates` | 3 | 3 | 0 | 0 | 3 | 0 |
| `game/vfx` | 12 | 12 | 0 | 0 | 12 | 0 |
| `game/weapons` | 1 | 1 | 0 | 0 | 1 | 0 |
| `hooks` | 32 | 0 | 32 | 22 | 10 | 0 |
| `rage` | 1 | 0 | 1 | 1 | 0 | 0 |
| `rage/base` | 2527 | 2527 | 0 | 0 | 2527 | 0 |
| `rage/framework` | 4 | 4 | 0 | 0 | 4 | 0 |
| `rage/script` | 1 | 1 | 0 | 0 | 1 | 0 |
| `rage/suite` | 213 | 213 | 0 | 0 | 213 | 0 |

## Headers escritos a mano o de datos

Los que tienen cuerpos de función dentro del header deben tener su `.cpp`, como en ReSA. «Cuerpos» es una cuenta aproximada de definiciones con llaves; los cuerpos que quedan en un header que sí tiene `.cpp` son plantillas o miembros de clase.

| Header | Líneas | Cuerpos en el header | `.cpp` | Ensamblador |
| --- | ---: | ---: | :---: | :---: |
| [source/core/DebugLog.h](../source/core/DebugLog.h) | 9 | 0 | sí | no |
| [source/core/HooksCatalog.h](../source/core/HooksCatalog.h) | 16002 | 0 | no | no |
| [source/core/OriginalCall.h](../source/core/OriginalCall.h) | 40 | 1 | sí | no |
| [source/core/PendingHook.h](../source/core/PendingHook.h) | 20 | 0 | no | no |
| [source/hooks/ARTComplexProbe.h](../source/hooks/ARTComplexProbe.h) | 49 | 0 | sí | no |
| [source/hooks/ARTExtraProbe.h](../source/hooks/ARTExtraProbe.h) | 51 | 0 | sí | no |
| [source/hooks/ARTFixtureProbe.h](../source/hooks/ARTFixtureProbe.h) | 67 | 0 | sí | no |
| [source/hooks/ARTSlotBindings.h](../source/hooks/ARTSlotBindings.h) | 356 | 0 | no | no |
| [source/hooks/ARTStubBindings.h](../source/hooks/ARTStubBindings.h) | 23 | 0 | no | no |
| [source/hooks/ARTStubsProbe.h](../source/hooks/ARTStubsProbe.h) | 20 | 0 | sí | no |
| [source/hooks/AnimationFixtureBindings.h](../source/hooks/AnimationFixtureBindings.h) | 17 | 0 | no | no |
| [source/hooks/AnimationFixtureProbe.h](../source/hooks/AnimationFixtureProbe.h) | 14 | 0 | sí | no |
| [source/hooks/AtStringHashProbe.h](../source/hooks/AtStringHashProbe.h) | 24 | 0 | sí | no |
| [source/hooks/AtStringHashSignature.h](../source/hooks/AtStringHashSignature.h) | 2 | 0 | no | no |
| [source/hooks/AudioFixtureProbe.h](../source/hooks/AudioFixtureProbe.h) | 57 | 0 | sí | no |
| [source/hooks/DestructorModeProbe.h](../source/hooks/DestructorModeProbe.h) | 156 | 0 | sí | no |
| [source/hooks/ExtraStubsProbe.h](../source/hooks/ExtraStubsProbe.h) | 21 | 0 | sí | no |
| [source/hooks/GameComplexProbe.h](../source/hooks/GameComplexProbe.h) | 88 | 2 | sí | no |
| [source/hooks/GameComplexScalarProbe.h](../source/hooks/GameComplexScalarProbe.h) | 159 | 0 | sí | no |
| [source/hooks/GamePendingProbe.h](../source/hooks/GamePendingProbe.h) | 315 | 0 | sí | no |
| [source/hooks/GameSlotBindings.h](../source/hooks/GameSlotBindings.h) | 25348 | 0 | no | no |
| [source/hooks/GameStubBindings.h](../source/hooks/GameStubBindings.h) | 1039 | 0 | no | no |
| [source/hooks/GameStubsProbe.h](../source/hooks/GameStubsProbe.h) | 20 | 0 | sí | no |
| [source/hooks/GetBoneMatrixProbe.h](../source/hooks/GetBoneMatrixProbe.h) | 23 | 0 | sí | no |
| [source/hooks/NMutilsBindings.h](../source/hooks/NMutilsBindings.h) | 15 | 0 | no | no |
| [source/hooks/NMutilsProbe.h](../source/hooks/NMutilsProbe.h) | 20 | 0 | sí | no |
| [source/hooks/PendingScalarProbe.h](../source/hooks/PendingScalarProbe.h) | 185 | 0 | sí | no |
| [source/hooks/PlayerPedNativeProbe.h](../source/hooks/PlayerPedNativeProbe.h) | 23 | 0 | sí | no |
| [source/hooks/PlayerPedProbe.h](../source/hooks/PlayerPedProbe.h) | 30 | 0 | sí | no |
| [source/hooks/ProbeCommon.h](../source/hooks/ProbeCommon.h) | 11 | 0 | no | no |
| [source/hooks/RageComplexProbe.h](../source/hooks/RageComplexProbe.h) | 110 | 0 | sí | no |
| [source/hooks/RageFixtureProbe.h](../source/hooks/RageFixtureProbe.h) | 107 | 0 | sí | no |
| [source/hooks/RageSlotBindings.h](../source/hooks/RageSlotBindings.h) | 19802 | 0 | no | no |
| [source/hooks/RageStubBindings.h](../source/hooks/RageStubBindings.h) | 2387 | 0 | no | no |
| [source/hooks/RageStubsProbe.h](../source/hooks/RageStubsProbe.h) | 20 | 0 | sí | no |
| [source/hooks/RageWriteProbe.h](../source/hooks/RageWriteProbe.h) | 32 | 0 | sí | no |
| [source/rage/AtStringHash.h](../source/rage/AtStringHash.h) | 7 | 0 | sí | no |

## Excepciones documentadas

- `core/ReIV.cpp` es el punto de entrada del plugin y no tiene header, como `app.cpp` en ReSA.
- `hooks/AtStringHashProbe.cpp`, `hooks/GetBoneMatrixProbe.cpp`, `hooks/PlayerPedProbe.cpp` y `hooks/PlayerPedNativeProbe.cpp` dependen del IV-SDK, que solo admite una unidad de compilación (`IVSDK.cpp`): se incluyen dentro de `core/ReIV.cpp` y no figuran por separado en el vcxproj.
- Los tipos RTTI generados no tienen código; su `.cpp` se crea cuando la clase se reconstruye.
- Los headers de datos (`HooksCatalog.h`, `PendingHook.h`, tablas `*Bindings.h`) solo contienen constantes y declaraciones.

## Ensamblador en línea

| Archivo | Bloques `__asm` | Funciones `naked` |
| --- | ---: | ---: |
| [source/game/Peds/CPlayerPed.cpp](../source/game/Peds/CPlayerPed.cpp) | 40 | 17 |
| [source/game/Peds/CPlayerPed.h](../source/game/Peds/CPlayerPed.h) | 3 | 3 |
| [source/hooks/PlayerPedProbe.cpp](../source/hooks/PlayerPedProbe.cpp) | 16 | 0 |

## `.cpp` sin `.h`

- [source/core/ReIV.cpp](../source/core/ReIV.cpp)

