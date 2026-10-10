# CPlayerPed: actualización propia, slot 29

`PlayerPedUpdate.h` transcribe las **567 instrucciones** del cuerpo completo `0x009C0B00..0x009C12FD` (**2046 bytes**) a ensamblador inline MSVC x86. `CPlayerPed::UpdateIsolated` expone esta operación para fixtures aislados. Se conservan el frame alineado, registros preservados, argumentos de stack, saltos, lecturas repetidas y orden de acceso. El retorno definido es solamente `AL=1`; no se atribuye significado a los bits altos de EAX.

La implementación mantiene las operaciones SSE `COMISS`, `MULSS`, `ADDSS`, `SUBSS` y `SQRTSS`, y los `FLD`/`FSTP` x87 utilizados para argumentos. Los campos `+0xEE0`, `+0xEE4`, `+0xEE8` y `+0xEEC` almacenan bits IEEE-754; las conversiones a entero que sugiere el pseudocódigo Ghidra no se trasladaron al código. Se conservaron las condiciones unordered de COMISS y el tratamiento de denormales del hardware.

Los 28 operandos globales se representan mediante almacenamiento explícito denominado por su dirección original; el contexto `0x0168F910` es una identidad opaca para callbacks. Las 27 funciones externas se suministran por punteros de código. Los dos calls virtuales mantienen su selección desde la vtable original del objeto fixture. Los contratos de limpieza del stack se documentan en `evidence/update-callback-contracts.json`, derivados de los RET canónicos y de dos destinos de salto final. El par `AA83F0/AA80D0` conserva que el primer call deja los tres argumentos pendientes y el segundo limpia 12 bytes; una API convencional que limpiara ambos cambiaría el contrato.

**Uso aislado y secuencial:** el almacenamiento y los punteros de callbacks son compartidos y mutables. No hay vínculo con los globals del juego ni hook instalado. Deben configurarse bajo propiedad exclusiva del banco; esta versión no admite concurrencia. Los cuerpos externos, layout y significado de gameplay continúan pendientes.

## Comparación del cuerpo completo

`update_inventory.py` extrae el cuerpo canónico y enumera 17 bloques; `update_asm.py` produce la transcripción y un fixture independiente con bytes originales. `check-update.cpp` copia esos bytes y parchea únicamente CALL externos y operandos globales. Los callbacks son deterministas y usan los contratos de stack originales. Nunca se ejecutó la función completa original sobre el jugador real.

Resultado: **139.920 comparaciones, cero diferencias** en retorno AL, traza de llamadas, estado x87/MXCSR, diez buffers completos de 16.384 bytes, un objeto anidado de 8192 bytes y los 28 globals. Incluye 265 escenarios de flags, 11 patrones flotantes (ceros con signo, positivos/negativos, NaN/sNaN, denormal e infinitos), cuatro redondeos, tres precisiones x87 y cuatro combinaciones DAZ/FTZ. Todas las 27 dependencias directas y las dos virtuales fueron invocadas al menos una vez. La primera dependencia cambia el reloj global para comprobar lecturas posteriores.

Esto no equivale a cobertura exhaustiva de todas las instrucciones o aristas. Los gates globales de bypass se mantuvieron en valores de la ruta principal; se ejercitó el bypass por `+0x218/+0x219`. El fallo original con bloque `+0x228` nulo no se probó en este banco. Las excepciones flotantes permanecieron enmascaradas. Los stubs naked capturan el EBP del caller y comparan los punteros locales por su desplazamiento exacto respecto a ese frame; así mantienen diferentes identidades de buffers y argumentos, incluido el buffer de salida virtual, sin comparar direcciones absolutas de dos ejecuciones.

La firma y límites están en `evidence/update-validation.json`; los bytes y bloques en `evidence/update-static.json`. La reconstrucción del caller no demuestra que la clase completa o sus sistemas externos estén reconstruidos.
