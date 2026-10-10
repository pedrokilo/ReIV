# Pruebas adicionales de funciones complejas

Se probaron **212 destinos distintos**, asociados a **3,699 referencias**, con **13,568 llamadas sin errores ni excepciones**. El juego terminó normalmente y la consola estuvo visible y escribible.

Los resultados tienen alcance limitado. Ninguna prueba reconstruye clases ni habilita hooks pendientes. [Referencias y evidencia](complex_validation.csv).

| Banco | Destinos | Llamadas | Alcance |
| --- | ---: | ---: | --- |
| [game](../../reversing/ComplexValidation/game/evidence/runtime-summary.json) | 28 | 1,792 | Objetos/buffers aislados y resultados comparados |
| [game (escalares)](../../reversing/ComplexValidation/game/evidence/scalar-runtime-summary.json) | 70 | 4,480 | Objetos/buffers aislados y resultados comparados |
| [rage](../../reversing/ComplexValidation/rage/evidence/runtime-summary.json) | 29 | 1,856 | Objetos/buffers aislados y resultados comparados |
| [ART](../../reversing/ComplexValidation/ART/evidence/runtime-summary.json) | 15 | 960 | Objetos/buffers aislados y resultados comparados |
| [destructors](../../reversing/ComplexValidation/destructors/evidence/runtime-summary.json) | 70 | 4,480 | Solo flags bit0 desactivado; rama de liberación excluida |

## Qué se comprobó

- Game: comparaciones con límites signed/unsigned, operaciones de bits y cuerpos escalares completos. Se verifican los bits definidos de EAX y las modificaciones de memoria previstas; no se afirma el retorno completo EDX:EAX de una función que escriba ambos registros.
- Rage: cada camino del grafo de control estático termina en RET y excluye llamadas, ciclos, globals/TLS y lecturas de punteros encadenados. Los 64 casos comparan los bits definidos de EAX y todo el buffer. `expected_nodes_mask` describe caminos del modelo esperado; no instrumenta las ramas nativas ni demuestra que todas se ejecutaron.
- ART: setters y copias condicionados por bits, resets locales, selección de this, una lectura con objeto anidado válido y salida en buffer separado. Las condiciones de bits se prueban con ambos resultados; se protegen objeto, objeto anidado y salida.
- Destructores: solo se llama con `flags & 1 == 0`. El TEST y el salto omiten por completo el acceso TLS y la llamada al liberador. Se verifica que únicamente cambie la vtable y que se devuelva this. La rama de liberación no fue ejecutada ni validada. Los bytes completos y la reubicación HIGHLOW del inmediato se comprueban antes de llamar.

Las convenciones de llamada son fixtures x86 deducidos de cuerpos completos; no equivalen a una firma original o a un layout completo de clase. Los nombres del catálogo son descriptivos por RVA.

## Cobertura restante

| Carpeta | Referencias sin llamada (sin fatal/discrepancias) | Destinos sin llamada (incluido fatal/discrepancias) | Fatal excluido (referencias) |
| --- | ---: | ---: | ---: |
| game | 13,507 | 4,911 | 272 |
| rage | 9,624 | 3,044 | 291 |
| ART | 157 | 138 | 52 |

Los destinos compartidos pueden aparecer en más de una carpeta. Las 772 referencias `runtime_restricted_mode` siguen limitadas al modo sin liberación; no deben tratarse como destructores completamente comprobados. El manejador fatal RVA `0x00001210` nunca se llamó. Los 581 tipos sin destinos siguen en Desconocido.

## Qué requiere la siguiente prueba

Las funciones restantes necesitan firmas y layouts, referencias de objetos existentes, dependencias y el estado correcto del sistema. Los caminos con allocators/TLS, constructores, liberaciones o callbacks indirectos no se convierten en pruebas pasando direcciones aleatorias. Las llamadas de este banco no certifican estabilidad durante gameplay.

## Repetición y actualización

Compilar con `contrib/build-reiv.ps1` y repetir el banco combinado con `reversing/ComplexValidation/run.ps1`. Respalda y restaura el ASI de la copia del juego y todos los marcadores/reportes. Registrar con `python reversing/ComplexValidation/register_results.py`, regenerar headers y catálogo, y actualizar esta ficha con `python reversing/ComplexValidation/summarize.py`.

## Compilación e instalación

Pasaron Release/Win32 y la comprobación sintáctica de los 4.016 headers. Se instaló la compilación final en la copia del juego con respaldo, consola automática y sin marcadores activos. [Registro de instalación](../../reversing/ComplexValidation/evidence/installation.json) distingue su hash del ASI probado; las sondas no cambiaron.
