# Inventario de validación de ART

Se inventariaron 45 headers de `source/external/ART`, con 353 referencias y 215 destinos únicos. Las referencias compartidas no representan funciones independientes. El banco de tablas abarca 353 referencias virtuales; las 0 referencias del SDK no forman parte de esa comprobación.

[art_validation.csv](art_validation.csv) conserva las direcciones, propietarios y evidencias originales. `historical_runtime_reference_test` únicamente reconoce pruebas históricas ya registradas; `pending_static_analysis` no confirma firma ni llamada. Los campos `enabled` y `reconstructed` conservan su valor original.

El análisis de bytes del ejecutable canónico, SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`, encontró 10 destinos cuyo cuerpo completo coincide con un retorno simple o un retorno de constante. Se incluyen solamente `RET n` de 4, 8, 12, 16 o 20 bytes con argumentos sinteticos explicitos, ademas de `FLD1/RET` con resultado flotante comprobado. [Candidatos](../../reversing/ARTValidation/evidence/simple-candidates.json) contiene bytes de entrada, longitud, máscara del valor de retorno y propietarios. `relocated_imm` identifica únicamente constantes `B8` cuyo inmediato tiene una entrada PE `HIGHLOW` comprobada: el banco puede ajustar ese inmediato y su resultado esperado por la diferencia de base cargada. Se excluyen otras relocaciones dentro del cuerpo. Esta coincidencia estática no valida semántica de clase ni habilita un hook; permite preparar una prueba acotada del cuerpo simple.

Todas las llamadas desconocidas o complejas permanecen deshabilitadas. Los 52 registros del manejador fatal RVA `0x00001210` se excluyen de llamadas. Los resultados runtime aprobados se detallan a continuación.

## Prueba runtime registrada

La auditoría comparó 353 referencias virtuales con sus destinos esperados y permisos ejecutables: 0 fallos. Comprueba direcciones; no llama esas funciones ni establece sus firmas. Las referencias del SDK no forman parte de esta auditoría.

- [ARTValidation: resumen](../../reversing/ARTValidation/evidence/runtime-summary.json): 10 destinos, 640 llamadas, 0 fallos y 0 excepciones; alcance cuerpos completos de retorno simple.
- [ARTFixtureValidation: resumen](../../reversing/ARTFixtureValidation/evidence/runtime-summary.json): 24 destinos, 1,536 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.
- [ARTExtraValidation: resumen](../../reversing/ARTExtraValidation/evidence/runtime-summary.json): 16 destinos, 1,024 llamadas, 0 fallos y 0 excepciones; alcance operaciones comprobadas en almacenamiento sintético.

El CSV diferencia `runtime_pure_stub` y `runtime_fixture`. `runtime_slot_result=0` acredita únicamente la auditoría de esa referencia virtual. Todos los registros continúan deshabilitados y sin reconstruir. El catálogo usa nombres descriptivos inferidos por RVA; ninguna clase se declara completa.

| Estado de referencia | Cantidad |
|---|---:|
| `excluded_fatal_handler` | 52 |
| `historical_runtime_reference_test` | 49 |
| `pending_static_analysis` | 157 |
| `runtime_fixture` | 67 |
| `runtime_pure_stub` | 28 |

La cobertura [file-coverage.json](../../reversing/ARTValidation/evidence/file-coverage.json) registra 45 headers del manifiesto, 45 headers en disco y 0 headers sin destinos. Los adicionales se enumeran por separado.

No hubo discrepancias de tablas virtuales; [rejected-slots.csv](../../reversing/ARTValidation/evidence/rejected-slots.csv) contiene únicamente la cabecera.

Se comprobaron llamadas acotadas de 50 destinos distintos (3,200 llamadas), asociados a 95 referencias compartidas. Quedan 165 destinos sin llamada comprobada, incluido el manejador fatal. La auditoría de direcciones no completa las clases de ART.

Las 52 referencias al manejador fatal RVA `0x00001210` están en [fatal-references.csv](../../reversing/ARTValidation/evidence/fatal-references.csv): `excluded_fatal_handler`, sin llamada y deshabilitadas. Sus punteros virtuales sí coincidieron; no se presentan como discrepancias de tabla.
