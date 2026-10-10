# Validación de audio

El lote abarca los 28 headers de `source/game/audio`: 236 referencias virtuales apuntan a 98 destinos únicos del ejecutable GTA IV PC 1.0.7.0, SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

Se exportaron cuerpos completos, instrucciones, decompilación y bytes de entrada desde el proyecto Ghidra existente. De los 98 destinos, 29 permiten pruebas aisladas: 19 operaciones sobre objetos temporales y 10 stubs constantes o vacíos. Los otros 69 quedan deshabilitados: 68 necesitan comprobar firmas, vida de objetos o estado del motor, y `0x00401210` es el manejador fatal compartido que puede terminar el proceso.

Los 29 candidatos corresponden a 137 referencias, porque varias tablas comparten funciones. Las 99 referencias restantes quedan pendientes o excluidas. Los nombres de comportamiento son inferencias del código máquina, no símbolos originales recuperados.

## Alcance por archivo

La columna «Admitidas» suma referencias a fixtures y stubs; no representa funciones únicas. «Pendientes» incluye el destino fatal, cuando aparece.

| Header | Referencias | Candidatas estáticas | Fuera del banco aislado | Probadas runtime |
|---|---:|---:|---:|---:|
| [audAmbientAudioEntity.h](../../source/game/audio/audAmbientAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audBoatAudioEntity.h](../../source/game/audio/audBoatAudioEntity.h) | 7 | 5 | 2 | 5 |
| [audCollisionAudioEntity.h](../../source/game/audio/audCollisionAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audCutsceneAudioEntity.h](../../source/game/audio/audCutsceneAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audDoorAudioEntity.h](../../source/game/audio/audDoorAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audEmitterAudioEntity.h](../../source/game/audio/audEmitterAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audEntityRadioEmitter.h](../../source/game/audio/audEntityRadioEmitter.h) | 17 | 7 | 10 | 7 |
| [audExplosionAudioEntity.h](../../source/game/audio/audExplosionAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audFireAudioEntity.h](../../source/game/audio/audFireAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audFrontendAudioEntity.h](../../source/game/audio/audFrontendAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audGtaAudioEntity.h](../../source/game/audio/audGtaAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audGtaOcclusionGroup.h](../../source/game/audio/audGtaOcclusionGroup.h) | 4 | 3 | 1 | 3 |
| [audGtaOcclusionGroupManager.h](../../source/game/audio/audGtaOcclusionGroupManager.h) | 2 | 0 | 2 | 0 |
| [audObjectAudioEntity.h](../../source/game/audio/audObjectAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audPedAudioEntity.h](../../source/game/audio/audPedAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audPlaceableTracker.h](../../source/game/audio/audPlaceableTracker.h) | 3 | 1 | 2 | 1 |
| [audPoliceScanner.h](../../source/game/audio/audPoliceScanner.h) | 7 | 4 | 3 | 4 |
| [audRadioAudioEntity.h](../../source/game/audio/audRadioAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audRadioEmitter.h](../../source/game/audio/audRadioEmitter.h) | 17 | 7 | 10 | 7 |
| [audScriptAudioEntity.h](../../source/game/audio/audScriptAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audSmashableAudioEntity.h](../../source/game/audio/audSmashableAudioEntity.h) | 7 | 4 | 3 | 4 |
| [audSpeechAudioEntity.h](../../source/game/audio/audSpeechAudioEntity.h) | 7 | 5 | 2 | 5 |
| [audSpeechManager.h](../../source/game/audio/audSpeechManager.h) | 6 | 3 | 3 | 3 |
| [audStaticRadioEmitter.h](../../source/game/audio/audStaticRadioEmitter.h) | 17 | 14 | 3 | 14 |
| [audVehicleAudioEntity.h](../../source/game/audio/audVehicleAudioEntity.h) | 7 | 3 | 4 | 3 |
| [audWeaponAudioEntity.h](../../source/game/audio/audWeaponAudioEntity.h) | 7 | 5 | 2 | 5 |
| [audWeatherAudioEntity.h](../../source/game/audio/audWeatherAudioEntity.h) | 7 | 2 | 5 | 2 |
| [CAudioAttr.h](../../source/game/audio/CAudioAttr.h) | 30 | 29 | 1 | 29 |

## Pruebas aisladas

`source/hooks/AudioFixtureProbe.h` requiere el marcador `ReIV.audio-fixtures-test`. Espera a que el juego esté cargado, valida el ejecutable y todos los bytes del cuerpo de cada candidato, y ejecuta 64 rondas por destino. Las dos comparaciones cubren igualdad y desigualdad, con dos llamadas por ronda. El lote completo contiene 1.344 llamadas nativas.

Los objetos temporales ocupan 4.096 bytes y se comparan íntegramente contra el estado esperado después de cada operación. Los parámetros de salida tienen valores de guarda. Los setters deben modificar únicamente los campos conocidos; los getters deben devolver el valor sembrado. Las excepciones y los resultados inesperados detienen las repeticiones de la entrada afectada y la marcan deshabilitada en el informe.

| VA preferida | Operación probada | Valor / desplazamiento | Modalidad |
|---|---|---|---|
| [0x004d7030](../../reversing/AudioValidation/evidence/004d7030.txt) | `constant_u8` | `0x0` | Stub compartido |
| [0x004d8bc0](../../reversing/AudioValidation/evidence/004d8bc0.txt) | `address_offset` | `0x4` | Fixture temporal |
| [0x007bdc00](../../reversing/AudioValidation/evidence/007bdc00.txt) | `constant_u32` | `0x0` | Stub compartido |
| [0x008155a0](../../reversing/AudioValidation/evidence/008155a0.txt) | `outputs_minus_one` | `0x0` | Fixture temporal |
| [0x008155c0](../../reversing/AudioValidation/evidence/008155c0.txt) | `constant_u32` | `0x5D5C` | Stub compartido |
| [0x008161d0](../../reversing/AudioValidation/evidence/008161d0.txt) | `compare_u32` | `0x4` | Fixture temporal |
| [0x0089bbb0](../../reversing/AudioValidation/evidence/0089bbb0.txt) | `set_u32` | `0x8` | Fixture temporal |
| [0x008b4d00](../../reversing/AudioValidation/evidence/008b4d00.txt) | `get_float` | `0x20` | Fixture temporal |
| [0x008b4d10](../../reversing/AudioValidation/evidence/008b4d10.txt) | `get_u32` | `0x34` | Fixture temporal |
| [0x008b4d20](../../reversing/AudioValidation/evidence/008b4d20.txt) | `compare_u32` | `0x30` | Fixture temporal |
| [0x008b4d30](../../reversing/AudioValidation/evidence/008b4d30.txt) | `set_pair` | `0x38` | Fixture temporal |
| [0x008b4d50](../../reversing/AudioValidation/evidence/008b4d50.txt) | `get_pair` | `0x38` | Fixture temporal |
| [0x008b4d70](../../reversing/AudioValidation/evidence/008b4d70.txt) | `constant_u32` | `0x3` | Stub compartido |
| [0x008b4d80](../../reversing/AudioValidation/evidence/008b4d80.txt) | `get_u32` | `0x24` | Fixture temporal |
| [0x008b4d90](../../reversing/AudioValidation/evidence/008b4d90.txt) | `get_u32` | `0x28` | Fixture temporal |
| [0x008b4da0](../../reversing/AudioValidation/evidence/008b4da0.txt) | `get_float` | `0x2C` | Fixture temporal |
| [0x0092c4d0](../../reversing/AudioValidation/evidence/0092c4d0.txt) | `noop_two_args` | `0x0` | Stub compartido |
| [0x00988ac0](../../reversing/AudioValidation/evidence/00988ac0.txt) | `identity_this` | `0x0` | Fixture temporal |
| [0x00988b60](../../reversing/AudioValidation/evidence/00988b60.txt) | `constant_u8` | `0xF` | Stub compartido |
| [0x00a2bd60](../../reversing/AudioValidation/evidence/00a2bd60.txt) | `set_u32` | `0x34` | Fixture temporal |
| [0x00aaaf20](../../reversing/AudioValidation/evidence/00aaaf20.txt) | `noop_one_arg` | `0x0` | Stub compartido |
| [0x00aad200](../../reversing/AudioValidation/evidence/00aad200.txt) | `get_u32` | `0x120` | Fixture temporal |
| [0x00ac7ba0](../../reversing/AudioValidation/evidence/00ac7ba0.txt) | `set_u32` | `0xA4` | Fixture temporal |
| [0x00aec4d0](../../reversing/AudioValidation/evidence/00aec4d0.txt) | `get_u32` | `0x820` | Fixture temporal |
| [0x00c28820](../../reversing/AudioValidation/evidence/00c28820.txt) | `noop` | `0x0` | Stub compartido |
| [0x00c5d610](../../reversing/AudioValidation/evidence/00c5d610.txt) | `get_u8` | `0x40` | Fixture temporal |
| [0x00c87a50](../../reversing/AudioValidation/evidence/00c87a50.txt) | `constant_float` | `0x1` | Stub compartido |
| [0x00ccf450](../../reversing/AudioValidation/evidence/00ccf450.txt) | `get_u32` | `0x250` | Fixture temporal |
| [0x00cfaee0](../../reversing/AudioValidation/evidence/00cfaee0.txt) | `constant_u8` | `0x1` | Stub compartido |

La firma mínima de los fixtures está determinada por las instrucciones de acceso a ECX, los argumentos de pila y el retorno. Se utilizan llamadas x86 `__thiscall`. Los getters de coma flotante devuelven el valor en x87. El banco general de stubs cubre las funciones constantes admitidas por su propio inventario; no se presupone que incluya todos los candidatos de audio.

Estas pruebas comprueban la llamada y el comportamiento acotado de cuerpos simples. No validan el diseño completo de las clases, sus constructores, objetos reales del audio, reproducción sonora, limpieza de recursos ni llamadas en otros estados del motor. No instalan hooks de sustitución ni reconstruyen funciones. Todas las entradas conservan `enabled=false` y `reconstructed=false`.

## Evidencia

- [Inventario de referencias y disposición estática](../../reversing/AudioValidation/evidence/scope.csv).
- [Resumen de los 28 archivos](../../reversing/AudioValidation/evidence/files.csv).
- [29 candidatos con ABI, bytes completos y propietarios](../../reversing/AudioValidation/evidence/candidates.json).
- [19 fixtures del banco específico](../../reversing/AudioValidation/evidence/fixture-scope.json).

## Ejecución en el juego

La ejecución integrada aprobó los 19 fixtures: 1.344 llamadas, cero fallos y cero excepciones. El banco general aprobó otros 7 destinos de audio con 448 llamadas. En total, 29 destinos y 137 referencias de audio tienen evidencia de llamada; no hubo hooks de sustitución instalados. El juego cerró normalmente con código 0 y la consola estuvo visible y disponible para escritura.

La segunda ejecución aprobó los tres stubs restantes: `0x0092C4D0` (no-op con RET 8), `0x00AAAF20` (no-op con RET 4) y `0x00C87A50` (constante float 1), con 192 llamadas adicionales y cero fallos o excepciones. Los 29 candidatos acumulan 1.984 llamadas en ambos bancos. Los 69 destinos complejos o fatales permanecen sin llamar y deshabilitados.

[Informe de los stubs adicionales](../../reversing/ExtraStubValidation/evidence/runtime-report.json).

Evidencia: [resumen runtime y hashes](../../reversing/AudioValidation/evidence/runtime-summary.json), [19 fixtures y contadores](../../reversing/AudioValidation/evidence/runtime-report.json), [stubs compartidos y contadores](../../reversing/GameValidation/evidence/runtime-report.json), [log integrado](../../reversing/AudioValidation/evidence/runtime.log). Los CSV distinguen candidatos estáticos de referencias comprobadas en runtime.
