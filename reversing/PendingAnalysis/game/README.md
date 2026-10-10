# Análisis de direcciones pendientes de game

`analyze.py` analiza las 25.393 referencias disponibles de `source/game`: 5.719 destinos únicos. Conserva 579 destinos con evidencia histórica de llamadas y encuentra 148 cuerpos adicionales adecuados para pruebas aisladas, asociados a 2.244 referencias. Estos números describen el inventario al generar `summary.json`.

`references.csv` conserva cada propietario y dirección, junto con la razón por la que una llamada permanece pendiente. `targets.json` agrega destinos compartidos, instrucciones observadas y llamadas directas o indirectas. La lectura estática se limita a la primera trayectoria lineal, un máximo de 256 bytes o 64 instrucciones, y termina al encontrar un salto o retorno. No reconstruye límites completos ni caminos alternativos de funciones complejas.

Los candidatos de `fixture-scope.json` tienen un cuerpo completo reconocido por bytes exactos: lectura de entero, byte o flotante, dirección de campo, o escritura de uno o cuatro bytes. No contienen llamadas ni acceden a variables globales. `prepare_probe.py` genera `GamePendingProbe.h`; no activa hooks.

El banco usa memoria aislada de 4.096 bytes y 64 valores distintos por destino. Comprueba el valor devuelto y todos los bytes del objeto frente al resultado esperado. Sus resultados solo acreditan esa operación y esos argumentos; no acreditan el tamaño ni la vida útil de objetos reales de cada clase, ni una identidad semántica inferida del nombre del propietario.

`run.ps1` guarda el reporte, registro y hashes de la ejecución en `evidence`. El resultado efectivo debe consultarse en `runtime-summary.json`: generar los candidatos no demuestra que la prueba haya pasado. Las entradas complejas permanecen deshabilitadas y conservan una razón explícita de investigación pendiente.
