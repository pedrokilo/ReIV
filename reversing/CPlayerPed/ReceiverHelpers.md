# Helpers con receptor jugador confirmado

Las cinco funciones adicionales tienen receptor jugador confirmado por los callers en `evidence/neighbor-receiver-adjudication.json`, corroborados por `rea-neighbor-caller-proof.json`. Esto demuestra qué objeto reciben; no recupera la declaración C++ original ni su clase propietaria.

`CPlayerPed.h` contiene los cuerpos íntegros transcritos en MSVC x86 ASM:

| VA | API aislada propuesta | Tamaño | Contrato propio |
| --- | --- | --- | --- |
| 9BE5F0 | `TestEitherPredicate(player,nullptr)` | 29 bytes / 14 instrucciones | AL, RET0; cortocircuito de dos predicados |
| 9BEEF0 | `SetPairFirstRaw(player,nullptr,a1,a2)` | 46 / 17 | RET8; EAX opaco del callback |
| 9BEF20 | `SetPairSecondRaw(player,nullptr,a1,a2)` | 46 / 17 | RET8; EAX opaco del callback |
| 9BEF70 | `GetRelatedRaw(player,nullptr)` | 25 / 7 | tail JMP al callback 921320, RET0 |
| 9BE790 | `TestActionAllowed(player,nullptr,action,flag)` | 56 / 21 | AL, RET8; sólo compara el byte bajo de flag |

Los nombres Raw describen bits observables y dispatch de dependencias; no establecen semántica de retorno nativa. Los callbacks son bindings explícitos compartidos y requieren pruebas aisladas y secuenciales. Las dependencias permanecen sin reconstruir en este lote.

Se integraron wrappers de conveniencia en `CPlayerPed.h` y su override: `TestEitherPredicate`, `DispatchPairFirstRaw`, `DispatchPairSecondRaw`, `DispatchRelatedRaw` y `TestActionAllowed`, correspondientes a las cinco filas en orden. Las dos APIs de pareja y el tail conservan retorno EAX opaco. Esta integración no recupera la declaración C++ histórica ni autoriza ejecución sobre el jugador real.

Los dos wrappers de pareja calculan primero `member228 ? member228+60 : NULL`, después `transform20+30`, y pasan a la dependencia el puntero calculado, los dos argumentos y `1`. La suma se conserva como operación de 32 bits incluso cuando da cero o desborda. El tail wrapper calcula el mismo receptor y salta a la dependencia conservando su retorno de máquina. No inventa un guard para punteros nulos.

La consulta de acción llama primero a 924E80, obtiene el índice en `info+4`, lee `player+2EC+index*12` y devuelve verdadero si ese valor es cero o igual al argumento; para otros valores devuelve `flag_low_byte==0`. Se mantiene la lectura de tabla después del callback, para respetar sus modificaciones. El cortocircuito devuelve exactamente AL=1 cuando cualquiera de los predicados externos devuelve AL distinto de cero.

`check-receiver-helpers.cpp` ejecuta copias íntegras de cada cuerpo original con sus CALL/JMP externos parcheados y compara el cuerpo reconstruido. Pasaron **38.400 comparaciones, 7.680 por función**, sin diferencias en cuatro buffers completos, secuencia ordenada de callbacks, retorno observable y x87/MXCSR. Las seis dependencias se ejecutan en el banco.

Los casos incluyen AL 0/1/2/255; seis patrones de argumentos; cinco índices (incluido -1 en aritmética de 32 bits); flags con byte bajo cero y byte alto distinto de cero; receiver NULL, punteros reales, FFFFFFA0, FFFFFF9F y FFFFFFFF; transform NULL y sumas con wrap; y callbacks que modifican tabla, member228 y memoria vecina. La prueba de FP conserva el estado con cuatro redondeos y DAZ/FTZ combinados; las instrucciones propias son enteras y no se afirma equivalencia de las dependencias reales con los sustitutos.

Los callbacks aceptan punteros sin dereferenciarlos salvo memoria controlada. Por ello el banco confirma que el caller pasa el receptor nulo o desbordado original; no demuestra que la dependencia real admita esos valores. Ninguna función se ejecutó sobre el jugador del juego ni se instaló como reemplazo. El probe queda intacto; las APIs comunes se añadieron tras terminar el banco.

Evidencia final: `evidence/receiver-helpers-validation.json`, con bytes canónicos, contratos completos de las dependencias, hashes y límites de la validación.

## Iterador adicional 9BF250

`CPlayerPed.h` reconstruye las 37 instrucciones / 114 bytes del caller en C++ con callbacks explícitos. Su receptor jugador está confirmado por `B91D70`: llamada al getter `817F40`, `MOV ECX,EAX`, salto a `9BF250`. Conserva siete iteraciones, consulta fresca del bloque en cada una, aritmética módulo 2³² de `block+3D4` multiplicado por `5C` y sumado al base suministrado `1662178`, búsqueda del candidato por índice y rechazo de candidato nulo o byte `A70==2`.

Los candidatos restantes ejecutan el slot virtual 12 con argumento 1 antes de releer flags. Se aplica OR de bit cero a `candidate+24` cuando el byte `26C` no tiene bit 2, y se actualiza sólo bit 12 de `candidate+260` con el byte correspondiente de `16180E0`. La API `PlayerPedRelatedFlags::UpdateRaw(player,deps)` conserva también los bits EAX de cada salida: puntero de candidato en rutas rechazadas o diferencia XOR en la ruta actualizada. No atribuye tipo de retorno C++ nativo.

El banco de cuerpo original completo confirma **4.096 comparaciones** sin diferencias: cuatro bases, cuatro secuencias de flags y 256 combinaciones de candidatos/estados/efectos. Compara nueve buffers, siete bytes de flags, retorno EAX y callbacks ordenados. Incluye cambios de la vtable del jugador entre iteraciones, mutations del candidato por el virtual, modificación de flags del índice actual/siguiente, índices modelo negativos y sumas con wrap. Conserva x87/MXCSR y un valor ST0 activo de 80 bits. El código del slot 12 canónico `89E4B0` y sus RET4 se incluyen en el dossier; su reconstrucción sigue fuera de este lote.

El contrato de dependencia virtual incluye despachar el slot 12 de la vtable actual del jugador; el banco proporciona dos tablas para comprobarlo. Base, punteros y callbacks de configuración permanecen inmutables durante la llamada, aunque las memorias de flags/candidatos se pueden modificar en callbacks. El banco usa bloque no nulo con almacenamiento válido; no afirma validación de un getter real que devolviera NULL. Wrapper común integrado: `CPlayerPed::UpdateRelatedFlagsRaw(player,deps)`. Evidencia final `evidence/related-flags-validation.json`.
