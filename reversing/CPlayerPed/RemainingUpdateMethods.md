# Métodos propios restantes llamados desde Update

Este análisis agrega evidencia canónica de tres funciones confirmadas por llamadas directas desde `0x009C0B00`. No modifica fuentes ni ejecuta los métodos. Los bytes, instrucciones completas y tablas están en `evidence/remaining-update-methods.json`, producidos por `remaining_update_methods.py`.

## 0x009BEED0: limpieza del miembro +0xE74

Cuerpo de **27 bytes**, `thiscall` sin argumentos explícitos y `RET`. Guarda la dirección `this+0xE74`, lee su puntero y, si no es nulo, llama `0x009E6580` con ese puntero como ECX y la dirección del miembro como argumento. Pone cero en el miembro después de la llamada, aunque la dependencia lo haya modificado. El cero inicial evita tanto la llamada como la escritura. No hay acceso global ni aritmética flotante propia.

Es el candidato más corto para C++ con una dependencia explícita. La prueba necesaria debe variar el miembro y permitir que el callback lo cambie, verificando el borrado posterior y todos los bytes del objeto. El callback es un contrato de liberación/referencia todavía externo; no debe asumirse su comportamiento a partir del nombre o destruir objetos reales.

## 0x009BFD80: valor condicionado por flag y límites flotantes

Cuerpo de **332 bytes**, `thiscall`, dos argumentos DWORD: el primero se consume como byte y el segundo como float de stack; termina `RET 8`. Retorno definido en AL. Usa tres dependencias directas: `462F90` (predicado AL), `4389D0` (puntero a bloque relacionado) y `962B20(7)` (valor x87 en ST0). Tiene seis operandos globales, incluyendo delta temporal, factores/límites flotantes y un gate byte.

El cálculo inicial SSE `delta * segundoArgumento * constante` ocurre **antes** de decidir la rama del primer argumento. Con byte distinto de cero, varias condiciones pueden omitir el cambio. Una comparación usa `UCOMISS`, `LAHF`, `TEST AH,44h` y `JNP`: igualdad ordenada salta; unordered no salta. Después `COMISS` establece las condiciones del límite inferior y de la resta; unordered sigue la condición hardware. Algunas salidas retornan AL=1 y otras AL=0. Estas diferencias impiden traducir todos los tests como comparaciones C++ ordinarias sin comprobar estado y NaN.

Con byte cero, captura primero `member228+0x60` en EDI y llama `962B20(7)`. Carga el float desde el bloque capturado **después** de esa llamada, compara mediante `FCOMIP` con el valor retornado en ST0 y elimina ambos valores x87. Si procede sumar, vuelve a leer `member228` para la escritura SSE. Un callback que cambie el puntero debe probar que la comparación usa el bloque anterior y la escritura usa el actual. La lectura inicial de `[member228+0x546]` en la otra rama ocurre antes de cualquier guard null: no debe añadirse un fallback seguro.

Recomendación técnica: transcripción MSVC x86 del caller, con stubs que preserven el retorno ST0 y las limpiezas reales. Comparar bits, AL, buffers, x87 status y MXCSR; variar NaN/sNaN, redondeo, DAZ/FTZ, gates y los bloques cambiados por callbacks. No ejecutar sobre el jugador real mientras las dependencias y ownership permanezcan externos.

## 0x009BE7D0: selección de acciones por estado/input

Cuerpo de **1652 bytes**, `thiscall` sin argumentos y `RET`. Contiene dos tablas de salto de cuatro entradas cada una en `0x009BEE44` y `0x009BEE54`, fuera del rango de instrucciones. Cada destino de tabla pertenece al cuerpo. El índice se limita con `SUB EAX,11; CMP EAX,3; JA`, antes del salto indirecto. Copiar solamente el rango de instrucciones deja las tablas apuntando a direcciones originales; deben mapearse por separado.

El método consulta el objeto relacionado, flags del jugador, vehículo y estado/input con múltiples lecturas de campos y callbacks. Agrupa decisiones de acciones mediante llamadas a `9AA330` y conserva salidas tempranas y el bloque final de toggles condicionado por globals y XOR de bytes. También genera un argumento cero con `FLDZ/FSTP` en una rama de evento. El objeto relacionado puede ser nulo en parte del caller, pero el bloque final lee sus campos bajo un gate global sin volver a comprobar el puntero: esa precondición debe conservarse.

La prioridad de las pruebas es construir fixture de input/vehículo y callbacks con contratos exactos; cubrir los ocho destinos de las tablas, las decisiones XOR alrededor de 127, valores signed positivos/cero/negativos, relecturas después de callbacks y el bloque final. La reconstrucción es más amplia que las otras dos y no se considera completada por este inventario.
