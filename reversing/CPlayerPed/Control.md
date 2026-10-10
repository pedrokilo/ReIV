# CPlayerPed: selección de modelo y creación de control

`CPlayerPed.h` reconstruye el flujo propio de los slots 14 (`0x009C0AA0`, 87 bytes) y 47 (`0x009C1E10`, 74 bytes). Las siete funciones externas permanecen explícitas en una interfaz de callbacks y no están reconstruidas en este archivo. No se instaló ningún reemplazo ni se cambiaron estos estados del jugador real.

El slot 14 consulta el descriptor en el array global `0x015F73B0`, indexado por el argumento, y prueba el byte `+0x8C`. Para cero llama únicamente `0x008AC500`. Para otro valor llama, en orden, `0x008DB2B0`, `0x008AC500`, `0x009BF660` y `0x008DD530`. El argumento booleano de `0x009BF660` resulta de comparar `[this+0x68]` con `-1` después de `0x008AC500`. Su argumento original conserva bits altos indeterminados porque usa `SETNE CL`; la dependencia lee solamente el byte bajo (`CMP BYTE [ESP+8],0`). El argumento final de `0x008DD530` se lee de `this+0x21C` después de `0x009BF660`. El retorno representa el EAX final; su significado de gameplay permanece desconocido.

El slot 47 tiene cinco argumentos de stack y termina `RET 20`. Carga el manager en `0x018A839C` y llama `0x00439CB0`. Si recibe un puntero, llama `0x004F4D20` con contexto ECX igual a ese puntero y seis argumentos: jugador, cero y los primeros cuatro argumentos originales, en ese orden. Escribe el resultado en `this+0x6C`, llama `0x0049F330` con ese resultado como contexto y el quinto argumento original, y devuelve el campo `+0x6C` releído después de la dependencia. La llamada a `0x0049F330` se conserva incluso si el resultado es nulo; esa dependencia real escribe memoria relativa a ECX y requiere un objeto válido. El banco simulado puede cubrir esta rama sin efectuar esas escrituras externas.

## Comparación independiente Win32

`control_evidence.py` extrae cuerpos completos del EXE canónico y produce `control-fixture.h`. `check-control.cpp` ejecuta esos bytes, parcheando solo los destinos CALL y dos operandos globales a fixtures aislados y stubs deterministas. Se conservan todos los accesos al jugador, ramas, orden y relecturas del caller.

Resultado: **512 comparaciones, cero diferencias**, 256 por método. Se comparan retorno, traza ordenada de argumentos y tres buffers completos de 4096 bytes. Las muestras cubren ambas ramas del byte del modelo, el estado `+0x68` cambiado por la primera dependencia, `+0x21C` cambiado por otra dependencia, asignación o construcción nula en el banco simulado, y `+0x6C` cambiado por la última dependencia. Los hashes de fuentes, fixture, ejecutable, parches y estados están en `evidence/control-validation.json`. Las instrucciones canónicas están en `evidence/control-static.json`.

Esto verifica los dos cuerpos propios con dependencias simuladas. No constituye una prueba dentro del juego ni reconstruye los managers, la asignación, el control creado o el resto de la jerarquía de clases.
