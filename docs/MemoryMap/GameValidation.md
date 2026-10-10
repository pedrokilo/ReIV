# Inventario de validación de game

Se inventariaron 1,223 headers de `source/game`, con 25,393 referencias y 5,719 destinos únicos. Las referencias compartidas no representan funciones independientes. El banco de tablas abarca 25,345 referencias virtuales; las 48 referencias del SDK no forman parte de esa comprobación.

[game_validation.csv](game_validation.csv) conserva las direcciones, propietarios y evidencias originales. `historical_runtime_reference_test` únicamente reconoce pruebas históricas ya registradas; `pending_static_analysis` no confirma firma ni llamada. Los campos `enabled` y `reconstructed` conservan su valor original.

El análisis de bytes del ejecutable canónico, SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`, encontró 518 destinos cuyo cuerpo completo coincide con un retorno simple o un retorno de constante. Se excluyeron retornos que limpian argumentos (`RET n`). [Candidatos](../../reversing/GameValidation/evidence/simple-candidates.json) contiene bytes de entrada, longitud, máscara del valor de retorno y propietarios. `relocated_imm` identifica únicamente constantes `B8` cuyo inmediato tiene una entrada PE `HIGHLOW` comprobada: el banco puede ajustar ese inmediato y su resultado esperado por la diferencia de base cargada. Se excluyen otras relocaciones dentro del cuerpo. Esta coincidencia estática no valida semántica de clase ni habilita un hook; permite preparar una prueba acotada del cuerpo simple.

NMutils mantiene su banco independiente: cinco destinos probados, 320 llamadas en total, y un sexto destino fatal excluido. [Resultados y límites](NMutilsValidation.md). No se vuelven a contar esos destinos como referencias de `source/game`.

| Carpeta | Referencias |
|---|---:|
| Cutscene | 72 |
| Objects | 123 |
| PedGroup | 24 |
| Peds | 447 |
| Stats | 35 |
| Vehicles | 828 |
| animation | 108 |
| audio | 236 |
| camera | 1,067 |
| control | 31 |
| event | 1,778 |
| frontend | 6,639 |
| ik | 6 |
| modelinfo | 111 |
| network | 2,879 |
| physics | 296 |
| renderer | 1,211 |
| scene | 406 |
| script | 13 |
| shaders | 68 |
| streaming | 64 |
| task | 8,542 |
| templates | 11 |
| vfx | 381 |
| weapons | 17 |

## Prueba runtime registrada

La auditoría comparó 25,345 referencias virtuales con sus destinos esperados y permisos ejecutables: 12 fallos. Comprueba direcciones; no llama esas funciones ni establece sus firmas. Las 48 referencias del SDK no forman parte de esta auditoría.

- [GameValidation: resumen](../../reversing/GameValidation/evidence/runtime-summary.json): 518 destinos, 33,152 llamadas, 0 fallos y 0 excepciones; alcance cuerpos completos de retorno simple.
- [AudioValidation: resumen](../../reversing/AudioValidation/evidence/runtime-summary.json): 19 destinos, 1,344 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.
- [AnimationValidation: resumen](../../reversing/AnimationValidation/evidence/runtime-summary.json): 7 destinos, 448 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.
- [ExtraStubValidation: resumen](../../reversing/ExtraStubValidation/evidence/runtime-summary.json): 7 destinos, 448 llamadas, 0 fallos y 0 excepciones; alcance cuerpos completos de retorno simple.

El CSV diferencia `runtime_pure_stub` y `runtime_fixture`. `runtime_slot_result=0` acredita únicamente la auditoría de esa referencia virtual. Todos los registros continúan deshabilitados y sin reconstruir. El catálogo usa nombres descriptivos inferidos por RVA; ninguna clase se declara completa.

| Estado de referencia | Cantidad |
|---|---:|
| `excluded_runtime_slot_mismatch` | 12 |
| `historical_runtime_reference_test` | 1 |
| `pending_static_analysis` | 17,857 |
| `runtime_fixture` | 118 |
| `runtime_pure_stub` | 7,405 |

La cobertura [file-coverage.json](../../reversing/GameValidation/evidence/file-coverage.json) contrasta el manifiesto con el disco: 1.223 headers, ninguno faltante o sin listar; 1.206 tienen referencias y 17 no disponen de destinos en el CSV. Incluye los 28 headers de audio y los 14 de animation.

Las 12 referencias que no coincidieron quedaron como `excluded_runtime_slot_mismatch`, detalladas en [rejected-slots.csv](../../reversing/GameValidation/evidence/rejected-slots.csv). El escáner puede haber atravesado el límite de una tabla virtual; estas entradas se excluyen como referencias invocables.

Los cuatro bancos de game suman 551 destinos y 35.392 llamadas, sin fallos ni excepciones. Audio y animación están incluidos en ese total. [Audio](AudioValidation.md) comprobó 29 destinos y [animación](AnimationValidation.md) 21. NMutils repitió sus cinco destinos, con 320 llamadas adicionales, conservando excluida su entrada fatal. El juego terminó normalmente y la consola estuvo visible.

Los headers, `hooks.csv` y `ClassesAndHooks.md` incorporan las evidencias. La compilación final y la comprobación sintáctica conjunta de los 4.016 headers pasaron. Se instaló la compilación final en la copia de prueba con los bancos desactivados y la consola automática. [Registro de instalación](../../reversing/GameValidation/evidence/installation.json) distingue su hash del ASI usado en la prueba: después se regeneraron el catálogo histórico y los metadatos de direcciones; las implementaciones de los bancos permanecen iguales.

Para repetir las pruebas con una compilación nueva: `powershell -File reversing/GameValidation/run.ps1`. El banco respalda y restaura la copia del juego y sus marcadores; los resultados se guardan bajo `reversing/*Validation/evidence`.
