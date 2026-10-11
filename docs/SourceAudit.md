# Auditoría de `source/`

[Inicio](../README.md) · [Progreso del reversing](ReversedClasses.md) · [Organización de source](../source/README.md)

> Generado por `tools/ReIV.Tools audit` (C#). Solo lee `source/`; detalle por archivo en [source_audit.csv](source_audit.csv).

Se revisan dos reglas, como en ReSA: **cada clase tiene su `.h` y su `.cpp`** (con sus subcarpetas) y **todo está escrito en C++, no en ensamblador**.

## Resumen

| Medida | Cantidad |
| --- | ---: |
| Headers | 4,052 |
| — de tipos RTTI generados (identidad y tabla de direcciones, sin código) | 4,016 |
| — escritos a mano | 36 |
| Archivos `.cpp` | 5 |
| Headers con su `.cpp` | 4 |
| Headers sin `.cpp` | 4,048 |
| `.cpp` sin `.h` | 1 |
| Archivos con ensamblador (`__asm` o `naked`) | 3 |
| Bloques `__asm` | 59 |
| Funciones `naked` | 20 |

## Headers sin `.cpp` por carpeta

| Carpeta | Headers | De tipos RTTI | A mano | Con `.cpp` | Sin `.cpp` | Con ensamblador |
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
| `hooks` | 31 | 0 | 31 | 0 | 31 | 1 |
| `rage` | 1 | 0 | 1 | 0 | 1 | 0 |
| `rage/base` | 2527 | 2527 | 0 | 0 | 2527 | 0 |
| `rage/framework` | 4 | 4 | 0 | 0 | 4 | 0 |
| `rage/script` | 1 | 1 | 0 | 0 | 1 | 0 |
| `rage/suite` | 213 | 213 | 0 | 0 | 213 | 0 |

## Headers escritos a mano

Los que tienen cuerpos de función dentro del header deberían tener su `.cpp`, como en ReSA. «Cuerpos» es una cuenta aproximada de definiciones con llaves.

| Header | Líneas | Cuerpos en el header | `.cpp` | Ensamblador |
| --- | ---: | ---: | :---: | :---: |
| [source/core/DebugLog.h](../source/core/DebugLog.h) | 9 | 0 | sí | no |
| [source/core/HooksCatalog.h](../source/core/HooksCatalog.h) | 16002 | 0 | no | no |
| [source/core/OriginalCall.h](../source/core/OriginalCall.h) | 40 | 1 | sí | no |
| [source/core/PendingHook.h](../source/core/PendingHook.h) | 20 | 0 | no | no |
| [source/hooks/ARTComplexProbe.h](../source/hooks/ARTComplexProbe.h) | 72 | 5 | no | no |
| [source/hooks/ARTExtraProbe.h](../source/hooks/ARTExtraProbe.h) | 79 | 5 | no | no |
| [source/hooks/ARTFixtureProbe.h](../source/hooks/ARTFixtureProbe.h) | 96 | 5 | no | no |
| [source/hooks/ARTSlotBindings.h](../source/hooks/ARTSlotBindings.h) | 356 | 0 | no | no |
| [source/hooks/ARTStubBindings.h](../source/hooks/ARTStubBindings.h) | 23 | 0 | no | no |
| [source/hooks/ARTStubsProbe.h](../source/hooks/ARTStubsProbe.h) | 103 | 15 | no | no |
| [source/hooks/AnimationFixtureBindings.h](../source/hooks/AnimationFixtureBindings.h) | 17 | 0 | no | no |
| [source/hooks/AnimationFixtureProbe.h](../source/hooks/AnimationFixtureProbe.h) | 79 | 12 | no | no |
| [source/hooks/AtStringHashProbe.h](../source/hooks/AtStringHashProbe.h) | 120 | 10 | no | no |
| [source/hooks/AtStringHashSignature.h](../source/hooks/AtStringHashSignature.h) | 2 | 0 | no | no |
| [source/hooks/AudioFixtureProbe.h](../source/hooks/AudioFixtureProbe.h) | 86 | 5 | no | no |
| [source/hooks/DestructorModeProbe.h](../source/hooks/DestructorModeProbe.h) | 172 | 4 | no | no |
| [source/hooks/ExtraStubsProbe.h](../source/hooks/ExtraStubsProbe.h) | 38 | 9 | no | no |
| [source/hooks/GameComplexProbe.h](../source/hooks/GameComplexProbe.h) | 104 | 8 | no | no |
| [source/hooks/GameComplexScalarProbe.h](../source/hooks/GameComplexScalarProbe.h) | 256 | 9 | no | no |
| [source/hooks/GamePendingProbe.h](../source/hooks/GamePendingProbe.h) | 345 | 5 | no | no |
| [source/hooks/GameSlotBindings.h](../source/hooks/GameSlotBindings.h) | 25348 | 0 | no | no |
| [source/hooks/GameStubBindings.h](../source/hooks/GameStubBindings.h) | 1039 | 0 | no | no |
| [source/hooks/GameStubsProbe.h](../source/hooks/GameStubsProbe.h) | 90 | 12 | no | no |
| [source/hooks/GetBoneMatrixProbe.h](../source/hooks/GetBoneMatrixProbe.h) | 74 | 10 | no | no |
| [source/hooks/NMutilsBindings.h](../source/hooks/NMutilsBindings.h) | 15 | 0 | no | no |
| [source/hooks/NMutilsProbe.h](../source/hooks/NMutilsProbe.h) | 75 | 10 | no | no |
| [source/hooks/PendingScalarProbe.h](../source/hooks/PendingScalarProbe.h) | 295 | 9 | no | no |
| [source/hooks/PlayerPedNativeProbe.h](../source/hooks/PlayerPedNativeProbe.h) | 74 | 13 | no | no |
| [source/hooks/PlayerPedProbe.h](../source/hooks/PlayerPedProbe.h) | 146 | 7 | no | sí |
| [source/hooks/RageComplexProbe.h](../source/hooks/RageComplexProbe.h) | 690 | 41 | no | no |
| [source/hooks/RageFixtureProbe.h](../source/hooks/RageFixtureProbe.h) | 136 | 5 | no | no |
| [source/hooks/RageSlotBindings.h](../source/hooks/RageSlotBindings.h) | 19802 | 0 | no | no |
| [source/hooks/RageStubBindings.h](../source/hooks/RageStubBindings.h) | 2387 | 0 | no | no |
| [source/hooks/RageStubsProbe.h](../source/hooks/RageStubsProbe.h) | 103 | 15 | no | no |
| [source/hooks/RageWriteProbe.h](../source/hooks/RageWriteProbe.h) | 47 | 4 | no | no |
| [source/rage/AtStringHash.h](../source/rage/AtStringHash.h) | 24 | 2 | no | no |

## Ensamblador en línea

| Archivo | Bloques `__asm` | Funciones `naked` |
| --- | ---: | ---: |
| [source/game/Peds/CPlayerPed.cpp](../source/game/Peds/CPlayerPed.cpp) | 40 | 17 |
| [source/game/Peds/CPlayerPed.h](../source/game/Peds/CPlayerPed.h) | 3 | 3 |
| [source/hooks/PlayerPedProbe.h](../source/hooks/PlayerPedProbe.h) | 16 | 0 |

## `.cpp` sin `.h`

- [source/core/ReIV.cpp](../source/core/ReIV.cpp)

