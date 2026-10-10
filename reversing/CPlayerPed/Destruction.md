# CPlayerPed: destructor y wrapper de liberación

`source/game/Peds/CPlayerPed.h` reconstruye el flujo propio de `0x009C1E60` (299 bytes, incluido el salto final al destructor de CPed) y el wrapper virtual `0x009C2260` (33 bytes, `RET 4`). Las funciones externas se expresan como callbacks explícitos; sus implementaciones siguen pendientes. Esta separación permite comparar el cuerpo propio sin destruir al jugador real.

El destructor escribe la vtable `0x00D819C4`, limpia el puntero en `+0xEA8` y lo vuelve a leer tras la primera limpieza. Libera dos referencias almacenadas en el bloque que resulta de `[this+0x228]+0x60`, offsets `+0x3E4` y `+0x3E8`: consulta el objeto global de `0x01548F88` mediante `0x0092F4D0`, transforma el resultado mediante `0x008631E0` y llama `0x009C0A70`. Vuelve a leer el bloque antes de escribir cero. Después llama `0x00920CD0` con argumento cero, limpia el miembro `this+0xEAC` con `0x004475F0` y termina en el destructor base `0x008AC1E0`.

El wrapper siempre ejecuta el destructor. Cuando el bit 0 de su argumento está activo, carga el objeto global de `0x018A82AC` y llama `0x00448300` con el puntero original. Retorna ese puntero incluso después de liberarlo. No se atribuyen nombres de gameplay a los handles ni a los objetos globales: el uso como contexto `ECX` se conoce; su significado requiere reconstruir las dependencias.

El código original permite que `[this+0x228]` sea cero en una selección previa, pero después lee la dirección baja `0x3E4`. No se añadió un retorno anticipado: un bloque válido es una precondición del destructor original. El test comprobó que ambas versiones producen `EXCEPTION_ACCESS_VIOLATION` para el bloque nulo.

## Comparación independiente Win32

`destruction_evidence.py` extrae los cuerpos completos del EXE canónico y genera `destruction-fixture.h`. `check-destructor.cpp` copia estos cuerpos y conserva todas las instrucciones de flujo y acceso al objeto. Parchea únicamente los destinos externos `CALL`/`JMP` y las tres cargas de direcciones globales para dirigirlos a dependencias deterministas.

Resultado: **256 comparaciones, cero diferencias** en la traza ordenada de llamadas, el retorno y los tres buffers de 4096 bytes. Incluye ambos modos del wrapper, referencias presentes/ausentes, cambio o eliminación de `EA8` por la primera llamada, y cambio de `[this+0x228]` durante la limpieza. Las dependencias no liberan memoria real. El caso de bloque nulo coincide como fallo esperado. Esto valida el flujo del caller frente a la máquina original con dependencias simuladas; no valida el destructor sobre el jugador real ni reconstruye sus diez dependencias.

Los hashes de fuente, fixture, ejecutable de prueba, bytes parcheados y estados comparados están en `evidence/destruction-validation.json`. Las instrucciones extraídas están en `evidence/destruction-static.json`. El test y sus resultados binarios permanecen en `build/` como artefactos locales.
