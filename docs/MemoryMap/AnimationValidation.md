# Validación de animation

Se revisaron los 14 headers dentro de `source/game/animation`, incluida la clase anidada `crmtManagerPriority::crFrameFilterWeightCorrection`. Sus 108 referencias virtuales apuntan a 85 destinos distintos. La revisión estática cubre todos los destinos; la ejecución se limita a cuerpos constantes y operaciones cuyo comportamiento permite preparar objetos sintéticos aislados.

| Clase | Referencias | Destinos distintos | Constantes/no-op | Operaciones con objeto sintético | Pendientes |
|---|---:|---:|---:|---:|---:|
| CAnimAssociations | 3 | 3 | 0 | 0 | 3 |
| CAnimAssociationsNY | 3 | 3 | 0 | 0 | 3 |
| CAnimatedBuilding | 55 | 47 | 19 | 3 | 33 |
| CAnimPlayer | 3 | 3 | 0 | 0 | 3 |
| CAnimRequestHelper | 1 | 1 | 0 | 0 | 1 |
| CAtdNodeAnimChangePooledObject | 1 | 1 | 0 | 0 | 1 |
| CAtdNodeAnimPlayerPooledObject | 1 | 1 | 0 | 0 | 1 |
| crExpressionProcessorPooledObject | 3 | 3 | 0 | 2 | 1 |
| crFrameFilterBoneMask | 5 | 5 | 0 | 3 | 2 |
| crmtManagerChannel | 9 | 9 | 1 | 0 | 8 |
| crmtManagerPriority | 9 | 9 | 1 | 0 | 8 |
| crmtManagerPriority::crFrameFilterWeightCorrection | 7 | 7 | 2 | 3 | 2 |
| crmtObserverFunctorNoRefCount | 4 | 4 | 2 | 0 | 2 |
| crmtObserverPooledObject | 4 | 4 | 1 | 2 | 1 |
| **Total** | **108** | **85 globales** | **26** | **13** | **69** |

Las últimas tres columnas cuentan referencias por clase. Algunos destinos se comparten entre clases o slots; los 39 registros seleccionados corresponden a 21 destinos: 14 constantes/no-op y 7 operaciones con objeto sintético. Los 69 registros pendientes corresponden a 64 destinos distintos. No deben sumarse los destinos únicos de cada clase para obtener el total global.

## Operaciones controladas

El banco `source/hooks/AnimationFixtureProbe.h` verifica siete entradas con 64 llamadas cada una. Las direcciones son VA preferidas de GTA IV PC 1.0.7.0; el código obtiene la dirección real mediante base del módulo más RVA, valida el EXE y compara los bytes iniciales antes de llamar.

| VA preferida | Comprobación |
|---|---|
| 0x0050B6E0 | Incrementa el campo +4 y verifica su valor final |
| 0x0050B6F0 | Decrementa el campo +4 y verifica valor y retorno; mantiene el contador distinto de cero |
| 0x0059BC50 | Lee el campo +8 con valores diferentes |
| 0x0089BBF0 | Cambia el bit 0x20 del campo +0x24 y conserva los demás bits |
| 0x008E05A0 | Lee el campo +0x38 cuando el bit 0x04000000 está activo y devuelve cero cuando está apagado |
| 0x008B8FE0 | Copia cuatro floats; verifica tanto el almacenamiento local como la rama con objeto padre |
| 0x009EB110 | Lee el campo +8 y escribe 128 en el parámetro de salida |

El banco genérico comprueba por separado los cuerpos constantes y no-op. Los nombres descriptivos del banco identifican el comportamiento observado; no son nombres originales recuperados de métodos.

## Evidencia y límites

Los 85 cuerpos están en [`reversing/AnimationValidation/evidence`](../../reversing/AnimationValidation/evidence). El [`CSV de revisión`](../../reversing/AnimationValidation/evidence/static-targets.csv) conserva cada clase, archivo, tabla virtual, slot, dirección, clasificación y vínculo al desensamblado. Los bytes iniciales provienen del EXE canónico; Ghidra se ejecutó sobre el proyecto existente en modo de lectura sin guardar cambios ni realizar análisis global.

La prueba del decremento no cubre la rama que invoca el destructor cuando el contador llega a cero. Los objetos sintéticos no establecen el tamaño completo ni el ciclo de vida de las clases. Las entradas pendientes necesitan firmas y objetos válidos; permanecen deshabilitadas. Ninguna de estas comprobaciones instala reemplazos ni declara una función reconstruida.

La ejecución dentro del juego aprobó 21 destinos: 1.344 llamadas en total, sin fallos ni excepciones. El banco de objetos sintéticos aprobó sus siete entradas con 448 llamadas; el banco genérico aprobó 14 entradas constantes/no-op con 896 llamadas. Las 39 referencias correspondientes quedaron documentadas como llamadas comprobadas en estos casos controlados.

Los cuatro cuerpos constantes/no-op con limpieza de argumentos en el retorno (0x00447970, 0x00491800, 0x00550FF0 y 0x009C80B0) se comprobaron posteriormente mediante un banco específico con 256 llamadas. Sus cinco referencias quedaron comprobadas. Permanecen pendientes y deshabilitadas las 69 referencias a 64 destinos complejos.

Los resultados están en el [informe de objetos sintéticos](../../reversing/AnimationValidation/evidence/runtime-report.json) el [informe del banco genérico](../../reversing/GameValidation/evidence/runtime-report.json) y el [informe de stubs adicionales](../../reversing/ExtraStubValidation/evidence/runtime-report.json); el [resumen de la ejecución](../../reversing/AnimationValidation/evidence/runtime-summary.json) identifica el EXE y la compilación usados. Ningún resultado declara métodos reconstruidos.

## Resultado por clase

| Clase | Referencias con llamada comprobada | Referencias sin llamada comprobada |
|---|---:|---:|
| CAnimAssociations | 0 | 3 |
| CAnimAssociationsNY | 0 | 3 |
| CAnimatedBuilding | 22 | 33 |
| CAnimPlayer | 0 | 3 |
| CAnimRequestHelper | 0 | 1 |
| CAtdNodeAnimChangePooledObject | 0 | 1 |
| CAtdNodeAnimPlayerPooledObject | 0 | 1 |
| crExpressionProcessorPooledObject | 2 | 1 |
| crFrameFilterBoneMask | 3 | 2 |
| crmtManagerChannel | 1 | 8 |
| crmtManagerPriority | 1 | 8 |
| crmtManagerPriority::crFrameFilterWeightCorrection | 5 | 2 |
| crmtObserverFunctorNoRefCount | 2 | 2 |
| crmtObserverPooledObject | 3 | 1 |
| **Total** | **39** | **69** |

