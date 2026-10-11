# Inventario de validación de rage

Se inventariaron 2,745 headers de `source/rage`, con 19,806 referencias y 4,444 destinos únicos. Las referencias compartidas no representan funciones independientes. El banco de tablas abarca 19,799 referencias virtuales; las 7 referencias del SDK no forman parte de esa comprobación.

[rage_validation.csv](rage_validation.csv) conserva las direcciones, propietarios y evidencias originales. `historical_runtime_reference_test` únicamente reconoce pruebas históricas ya registradas; `pending_static_analysis` no confirma firma ni llamada. Los campos `enabled` y `reconstructed` conservan su valor original.

El análisis de bytes del ejecutable canónico, SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`, encontró 1,192 destinos cuyo cuerpo completo coincide con un retorno simple o un retorno de constante. Se incluyen solamente `RET n` de 4, 8, 12, 16 o 20 bytes con argumentos sinteticos explicitos, ademas de `FLD1/RET` con resultado flotante comprobado. [Candidatos](../../reversing/RageValidation/evidence/simple-candidates.json) contiene bytes de entrada, longitud, máscara del valor de retorno y propietarios. `relocated_imm` identifica únicamente constantes `B8` cuyo inmediato tiene una entrada PE `HIGHLOW` comprobada: el banco puede ajustar ese inmediato y su resultado esperado por la diferencia de base cargada. Se excluyen otras relocaciones dentro del cuerpo. Esta coincidencia estática no valida semántica de clase ni habilita un hook; permite preparar una prueba acotada del cuerpo simple.

NMutils mantiene su banco independiente: cinco destinos probados, 320 llamadas en total, y un sexto destino fatal excluido. [Resultados y límites](NMutilsValidation.md). No se vuelven a contar esos destinos como referencias de `source/rage`.

| Carpeta | Referencias |
|---|---:|
| base | 18,323 |
| framework | 79 |
| script | 5 |
| suite | 1,399 |

## Prueba runtime registrada

La auditoría comparó 19,799 referencias virtuales con sus destinos esperados y permisos ejecutables: 0 fallos. Comprueba direcciones; no llama esas funciones ni establece sus firmas. Las referencias del SDK no forman parte de esta auditoría.

- [RageValidation: resumen](../../reversing/RageValidation/evidence/runtime-summary.json): 1,192 destinos, 76,288 llamadas, 0 fallos y 0 excepciones; alcance cuerpos completos de retorno simple.
- [RageFixtureValidation: resumen](../../reversing/RageFixtureValidation/evidence/runtime-summary.json): 44 destinos, 2,816 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.
- [RageWriteValidation: resumen](../../reversing/RageWriteValidation/evidence/runtime-summary.json): 7 destinos, 448 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.

El CSV diferencia `runtime_pure_stub` y `runtime_fixture`. `runtime_slot_result=0` acredita únicamente la auditoría de esa referencia virtual. Todos los registros continúan deshabilitados y sin reconstruir. El catálogo usa nombres descriptivos inferidos por RVA; ninguna clase se declara completa.

| Estado de referencia | Cantidad |
|---|---:|
| `excluded_fatal_handler` | 291 |
| `historical_runtime_reference_test` | 2,246 |
| `pending_static_analysis` | 9,624 |
| `runtime_fixture` | 2,120 |
| `runtime_pure_stub` | 5,525 |

La cobertura [file-coverage.json](../../reversing/RageValidation/evidence/file-coverage.json) registra 2,745 headers del manifiesto, 2,746 headers en disco y 568 headers sin destinos. Los adicionales se enumeran por separado (incluido AtStringHash).

No hubo discrepancias de tablas virtuales; [rejected-slots.csv](../../reversing/RageValidation/evidence/rejected-slots.csv) contiene únicamente la cabecera.

Se comprobaron llamadas acotadas de 1,243 destinos distintos (79,552 llamadas), asociados a 7,645 referencias compartidas. Quedan 3,201 destinos sin llamada comprobada, incluido el manejador fatal. La auditoría de direcciones no completa las clases de rage.

Las 291 referencias al manejador fatal RVA `0x00001210` están en [fatal-references.csv](../../reversing/RageValidation/evidence/fatal-references.csv): `excluded_fatal_handler`, sin llamada y deshabilitadas. Sus punteros virtuales sí coincidieron; no se presentan como discrepancias de tabla.

El [primer intento](../../reversing/RageValidation/evidence/startup-timeout-summary.json) agotó el tiempo de arranque. Los resultados aprobados corresponden al segundo intento, con salida normal (código 0), consola visible y la misma compilación ASI del banco inicial. Los siete setters suplementarios tienen su propia compilación y evidencia; no reemplazan la prueba anterior.
