# Inventario de CPlayerPed

La vtable conocida contiene **82 slots** y **77 destinos distintos**. Frente a CPed (81 slots), **64 slots conservan el destino** y **18 cambian o amplían la tabla**. Eso no prueba que existan sólo 18 métodos propios: quedan métodos no virtuales, construcción, destrucción y comportamiento heredado.

Se recuperó pseudocódigo previo para 71 slots. Se incluye íntegro en `evidence/method-inventory.json`; las entradas restantes conservan sus bytes iniciales para localizar sus cuerpos completos. El pseudocódigo y las primeras 48 posiciones de bytes no constituyen una reconstrucción validada.

Estado actual: los cuerpos de los 18 slots diferentes están reconstruidos y tienen pruebas acotadas; los complejos conservan dependencias explícitas. También hay cuerpos propios no virtuales reconstruidos. Ver `README.md` y los summaries de cada banco para su alcance. La tabla siguiente conserva el estado inicial del descubrimiento, no el estado actual de validación.

| Slot | Dirección | Dependencias directas candidatas | Estado de inventario |
| --- | --- | --- | --- |
| 0 | `0x009c2260` | `0x00448300`, `0x009c1e60` | Pseudocódigo disponible |
| 14 | `0x009c0aa0` | `0x008ac500`, `0x008db2b0`, `0x008dd530`, `0x009bf660` | Pseudocódigo disponible |
| 29 | `0x009c0b00` | `0x00401950`, `0x004269b0`, `0x004389d0`, `0x00462f90`, `0x0088f5d0`, `0x0089ea80`, `0x008aadc0`, `0x008ae670`, `0x0091a050`, `0x0091a0a0`, `0x00922850`, `0x00924e80`, `0x00976e90`, `0x0097d7c0`, `0x00987730`, `0x009a9cf0`, `0x009be5d0`, `0x009be7d0`, `0x009bee70`, `0x009beed0`, `0x009bfd80`, `0x009e6630`, `0x00aa80d0`, `0x00aa83f0`, `0x00ab3b60`, `0x00afe160`, `0x00afea00` | Pseudocódigo disponible |
| 47 | `0x009c1e10` | `0x00439cb0`, `0x0049f330`, `0x004f4d20` | Pseudocódigo disponible |
| 48 | `0x007bdc00` |  | Cuerpo simple compartido; revisar bytes |
| 60 | `0x009c1cf0` | `0x00447610`, `0x0089e5a0` | Pseudocódigo disponible |
| 61 | `0x009c1d20` | `0x00447610`, `0x0089e5a0` | Pseudocódigo disponible |
| 62 | `0x009c1d50` | `0x00447610`, `0x00447640`, `0x0089e5a0` | Pseudocódigo disponible |
| 63 | `0x009c1ce0` | `0x00447640` | Pseudocódigo disponible |
| 73 | `0x009be770` | `0x008a3990`, `0x009be610` | Pseudocódigo disponible |
| 74 | `0x00cfaee0` |  | Cuerpo simple compartido; revisar bytes |
| 75 | `0x009c1c90` |  | Cinco operaciones ya reconstruidas |
| 76 | `0x009c1ca0` |  | Cinco operaciones ya reconstruidas |
| 77 | `0x009c1cb0` |  | Cinco operaciones ya reconstruidas |
| 78 | `0x009c1cc0` |  | Cinco operaciones ya reconstruidas |
| 79 | `0x009c1d90` |  | Pseudocódigo disponible |
| 80 | `0x009c1dd0` |  | Pseudocódigo disponible |
| 81 | `0x009c1cd0` |  | Cinco operaciones ya reconstruidas |

## Construcción y destrucción

El escaneo del EXE canónico encontró dos inmediatos de la vtable `0x00D819C4` dentro de código: `0x009C1932` y `0x009C1E6D`. La segunda referencia cae en la función destructora candidata `0x009C1E60`, llamada desde el slot 0 (`0x009C2260`). La primera requiere identificar la entrada real del constructor y verificar todas sus rutas. No se asigna nombre o firma definitivo a partir de un inmediato.

El slot 29 (`0x009C0B00`) contiene un pseudocódigo extenso con 27 destinos directos candidatos, más llamadas indirectas y estado global. Las dependencias y offsets extraídos son candidatos: las expresiones de Ghidra también pueden emplear ECX como un tipo escalado.

Los slots 60–63 necesitan verificar los helpers `0x00447610`, `0x00447640` y `0x0089E5A0`, el receptor usado en cada llamada y la precisión x87. Los slots 79–80 usan copias de cuatro valores con instrucciones x87 y SSE; no basta sustituirlos por memcpy sin comparar conversión flotante, orden y solapamiento.

Este inventario mantiene `full_class_reconstructed: false`. No habilita hooks ni cuenta wrappers como reconstrucción completa.

## Evidencia adicional de layout y dependencias

El constructor candidato comienza en `0x009C1910` y termina con `RET 12` en `0x009C1C81`. Escribe una palabra de cuatro bytes en `this + 0xEF4`, lo que exige al menos `0xEF8` bytes de almacenamiento; no demuestra el tamaño de asignación completo. El desensamblado y los offsets observados se conservan en `evidence/lifecycle-layout-inventory.json`.

Los slots 60–63 pasan `this + 0xEAC` a los helpers. El slot 61 descarta ocho bytes de argumentos y sólo lee el primero. Los thunks `0x00D30318` y `0x00D3031E` resuelven, respectivamente, a los ordinales 5021 y 5020 de `xlive.dll`, según el directorio de imports del PE. Sus nombres simbólicos y contratos completos requieren evidencia de la biblioteca.

El escaneo raw inicial no encontró llamadas relativas directas al constructor `0x009C1910` ni referencias absolutas a esa entrada. El análisis posterior identificó el salto final desde `0x0096D870`: la fábrica recibe almacenamiento del pool global `0x018A82AC` y salta al constructor. El inicializador `0x0043A9E0` fija stride `0xF00` y 120 entradas; evidencia completa en `../PlayerPedLayout/pool-stride-evidence.json`. Esto acredita el almacenamiento de entradas del pool; la frontera exacta del base CPed sigue pendiente.

## Helper de contador y slot 73

`source/game/Peds/CPlayerPed.h` conserva el helper `0x009BE610` y el wrapper `0x009BE770` con dependencias explícitas. Pasaron 258.048 comparaciones aisladas Win32 contra el cuerpo completo original, sustituyendo llamadas externas por callbacks deterministas. Se compararon el buffer de jugador de 4096 bytes y el orden/receptor/argumentos de las llamadas. Esto valida el algoritmo propio bajo esos contratos; no reconstruye las dependencias ni constituye una prueba en el juego. Evidencia: `counter-validation-summary.json`, `counter-fixture.json`; banco: `counter-check.cpp`.

## Métodos no virtuales: adjudicación y alcance

El escaneo encontró 17 candidatos iniciales y añadió `0x009BE4C0` desde el constructor, para 18 registros. Se conserva la distinción entre receptor jugador probado, propiedad probable y clase C++ original desconocida. Las llamadas desde el slot 29 pasan el receptor original en ECX a `9BE5D0`, `9BE7D0`, `9BEE70`, `9BEED0` y `9BFD80`; no se les atribuye propiedad sólo por proximidad de código. `9BE610` se asocia además mediante el slot 73, y `9BE4C0` mediante el constructor.

La rutina `9BF5F0` tiene evidencia adicional: el caller `A4FB50` pregunta por el virtual slot 74 y sólo llama al método si AL no es cero. Entre las tablas RTTI inventariadas, ese slot devuelve uno mediante CFAEE0 para CPlayerPed, y cero mediante 5FDCD0 para CPed. Es un indicio fuerte de receptor CPlayerPed; no recupera la declaración C++ original ni enumera tablas no conocidas. `9BF5D0` y `9BF640` mantienen pendientes los callers de tareas/scripts; `9C1F90` y `9C2180` usan offsets compatibles pero carecen aún de consumidores adjudicados. `9C2680`, `9C2960` y `9C3090` aparecen desde slots heredados de CPed, por lo que no se adjudican al hijo.

Se reconstruyeron `9BE5D0`, `9BEE70` y `9BE4C0` con contratos de dependencia explícitos en CPlayerPed.h. Pasaron 57.856 comparaciones aisladas de cuerpos originales completos. Inicialización respeta el destino capturado antes de crear el handle, relee el puntero después de callbacks y conserva cálculo modular de receptores indexados y máscaras de bits. Las APIs se exponen en CPlayerPed.h y su declaración persistente. Esto no supone prueba dentro del juego.

El inventario completo sigue pendiente: 64 slots compartidos con CPed requieren reconstrucción heredada; la cadena RTTI CPed→CPhysical→CDynamicEntity→CEntity→CVirtualBase no define por sí sola una herencia C++ segura. Faltan enumerar métodos no virtuales fuera del rango examinado, recuperar identidades/firmas de todos los callbacks y resolver nombres y tipos de campos. La evidencia SDK incluye headers vacíos de CPlayerPed y VALIDATE_SIZE F00, mientras el SDK también asigna F00 a CPed: esas declaraciones no prueban un layout completo. La ruta de asignación y la capa de almacenamiento se documentan aparte con la evidencia canónica; no se inventa sizeof ni padding para cerrar esta clase.

Detalles: nonvirtual-candidates.json, nonvirtual-player-receiver-proof.json, nonvirtual-type-query-guard.json y nonvirtual-validation-summary.json. `inventory_exhaustive` permanece false.

## Confirmaciones posteriores de receptores y acumulación

Se verificaron también los consumidores de `9BF5D0` y `9BF640`: `AB94C0` comprueba byte `[ESI+219]` antes de pasar ESI por ECX al primer método; `956680` obtiene EDI de `[context+40]`, comprueba `[EDI+219]`, y pasa ese mismo EDI al segundo. Esto confirma el contrato de receptor con flag de jugador, aunque la clase C++ original no se recupera. La evidencia de ensamblado está en `nonvirtual-player-flag-caller-proof.json`. Sus cuerpos completos quedan pendientes.

`9BF5F0` se implementó aparte en CPlayerPed.h y se expone como AdvanceFieldEE0. Conserva MOVSS/MULSS/ADDSS/COMISS, el store previo al salto, el caso unordered y el reset EE4/EE0. Pasaron 204.800 comparaciones aisladas con el cuerpo completo de 69 bytes, buffers de 4.096 bytes y MXCSR idéntico, cubriendo cuatro redondeos y DAZ/FTZ, NaNs señalizantes/silenciosos, infinitos, signed zero, denormales y límites. Los cuatro globales se vinculan explícitamente. La entrada `11DDE7C` es estado virtual de datos sin bytes file-backed; no se le inventa valor constante. Evidencia: accumulation-fixture.json y accumulation-validation-summary.json.

El probe posterior añade esta operación como décimo método, siempre en buffers aislados. Verifica 69 bytes del original con ajuste ASLR, cuatro globales de sólo lectura, full-buffer, MXCSR y control/status x87; FXSAVE/FXRSTOR protege el contexto flotante del juego. La entrada en el jugador real de EE0 no se escribe. La comparación aislada sigue siendo un alcance distinto de una prueba aprobada dentro del juego; el informe runtime posterior registra ese resultado por separado.

## Campos EE4 y EEC

Después de confirmar los consumidores con flag de jugador, se implementaron `9BF5D0` y `9BF640` en CPlayerPed.h, con globales explícitos y las instrucciones SSE originales. Pasaron 409.600 comparaciones aisladas de cuerpos completos (204.800 por función), con guards completos de 4.096 bytes y MXCSR idéntico. Se preserva el resultado AL de ocho bits del primer método, incluido uno para COMISS unordered; no se reconstruyen bits superiores de EAX. El segundo sólo resetea EEC cuando la comparación ordenada con cero no es menor; unordered no escribe.

El banco prueba 20 patrones de campos por 20 patrones globales, 32 buffers y 16 modos de MXCSR. Se conservan NaN señalizante/silencioso, signed zero, infinitos, denormales, DAZ/FTZ y redondeos. Los traps con excepciones flotantes no enmascaradas mantienen el orden de instrucciones pero no se ejecutan. Evidencia: extra-fields-fixture.json y extra-fields-validation-summary.json; repetir con extra-fields-check.cpp. Estos resultados siguen siendo distintos de una prueba dentro del juego.
