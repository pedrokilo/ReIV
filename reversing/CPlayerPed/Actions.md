# Acciones adicionales de CPlayerPed

El ejecutable canónico aporta tres cuerpos completos: `9C1F90` (483 bytes, 141 instrucciones, AL, RET4), `9C2180` (218 bytes, 71 instrucciones, AL, RET8) y `9C1300` (1549 bytes, 400 instrucciones, EAX, RET14). No contienen tablas de saltos. Las implementaciones son transcripciones MSVC x86 ASM del caller, con almacenamiento y dependencias explícitos. No delegan la función completa al ejecutable.

`9C1300` recibe el objeto auxiliar embebido en `CPlayerPed + E7C`: las acciones lo llaman mediante `LEA ECX,[ESI+E7C]` en `9C211B` y `9C220E`. Su primer miembro apunta al jugador. Por ello `CPlayerPed.h` representa un auxiliar; no se contabiliza como otro método directo del jugador. Su llamada recursiva utiliza su propia reconstrucción.

APIs integradas en `CPlayerPed.h` y el override `declarations/CPlayerPed.inc`:

- `CPlayerPed::ActInRangeIsolated(player, flag)` → AL.
- `CPlayerPed::RequestActionIsolated(player, flag, argument)` → AL.
- `player_action_selection::Select(embeddedReceiver, nullptr, flags, rangeBits, argument, output, last)` → EAX. Los argumentos sin semántica confirmada conservan los bits de máquina.

El auxiliar se incluye para uso explícito, sin añadirlo como método propio ni registrarlo bajo CPlayerPed. Las dos acciones se registran como reconstrucción aislada únicamente cuando coincide el hash de su header específico con `actions-validation.json`; `runtime_checked` permanece a cero. La integración no modifica el probe del juego y requiere una nueva compilación/prueba integrada de las doce operaciones anteriores.

Las acciones completas se compararon con copias íntegras de sus bytes originales, parcheando únicamente llamadas y almacenamiento global. Pasaron 42.320 comparaciones con 10 patrones de coma flotante, gates, cambios de `member228` por callbacks y variantes de ambos argumentos. Se comparan siete buffers, retorno AL, secuencia de callbacks y estado FP cuando la llamada termina normalmente. Ambas variantes comparten 7.460 fallos reproducidos: después de una acción exitosa con `member228` nulo, el original escribe en `0x415`. El banco captura el código y dirección del fallo mediante SEH y los compara, sin sustituirlo por una salida segura.

El auxiliar pasó 168.960 comparaciones con seis buffers, 25 palabras de entorno/globales, salida opcional, retorno EAX, secuencia ordenada con offsets exactos de pila y x87/MXCSR. El banco usa cuatro modos de redondeo y DAZ/FTZ activado/desactivado, con excepciones FP enmascaradas y precisión x87 de 64 bits; no afirma exhaustividad para otras configuraciones. Cubre dos candidatos por iterador, ramas de rechazo/puntuación y recursión. La construcción del iterador registra 16.096 llamadas recursivas por variante. La rama de logging se ejecuta 254.304 veces sumando ambas variantes.

El auxiliar depende de `FS:[2C]` y del índice TLS `17237B0`. Para probarlo sin acceder al TLS del juego, el vector se aporta explícitamente mediante `g0000002C`: en el baseline se reemplaza el prefijo FS por NOP y se enlaza la dirección absoluta al almacenamiento del banco, conservando la longitud de la instrucción. Esta es una adaptación declarada del entorno, no identidad binaria. La rutina de formato se reemplaza por un callback determinista; no se afirma reconstrucción de sus dependencias. `C28820` contiene únicamente RET y se proporciona como RET puro, conservando registros, flags y estado FP.

Los bindings son compartidos y las pruebas son secuenciales y aisladas. Ninguna de estas rutinas se ha instalado como hook ni ejecutado sobre el jugador real. Las ramas cubiertas no convierten la clase completa ni sus dependencias en reconstruidas. Los hashes, contratos y resultados quedan en `evidence/actions-validation.json` y `evidence/action-selection-validation.json`.
