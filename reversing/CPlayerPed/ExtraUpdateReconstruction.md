# Tres métodos propios adicionales usados por Update

Los cuerpos canónicos enumerados en `remaining-update-methods.json` se reconstruyeron en archivos separados. Todos continúan usando dependencias explícitas. No se ejecutaron sobre objetos reales del juego ni se instalaron reemplazos. Las pruebas son Win32 contra cuerpos originales completos con CALLs/globals/tablas controladas.

| VA | Archivo | Comparaciones | Alcance |
|---|---|---:|---|
| `0x009BEED0` | `CPlayerPed.h` | 512 | C++ propio, 27 bytes, un callback |
| `0x009BFD80` | `CPlayerPed.h` | 2.457.600 | ASM propio, 332 bytes, tres callbacks y seis globals |
| `0x009BE7D0` | `CPlayerPed.h` | 74.448 | ASM propio, 1652 bytes, 19 callbacks, dos globals y dos tablas de cuatro entradas |

Todas las comparaciones terminaron sin diferencias. `record_extra_methods.py` ejecuta los tres bancos y registra hashes de fuente, test, binario y bytes parcheados, además de los límites, en los archivos `*-validation.json` correspondientes.

La limpieza `9BEED0` conserva la dirección del miembro `+0xE74` y escribe cero después de la dependencia, aunque esta haya cambiado el miembro. El banco compara todo el objeto de 4096 bytes y la traza con el valor observado antes del callback.

La operación `9BFD80` conserva las instrucciones SSE, `UCOMISS/LAHF/TEST AH,44h/JNP`, los tests `COMISS`, y la comparación x87 `FCOMIP` del límite que retorna `962B20` en ST0. Se compara AL, estado x87/MXCSR, tres buffers completos y la traza con 48 configuraciones flotantes, 128 conjuntos de gates, cuatro DWORDs de argumento y diez patrones para el campo y entrada. Los callbacks cambian el puntero del bloque durante consultas y durante el retorno x87 para verificar la selección del bloque anterior o actual según la instrucción original. Las excepciones se mantienen enmascaradas; las fallas por puntero nulo no se probaron en este banco.

La selección `9BE7D0` conserva todos los saltos, accesses, argumentos y la cola de toggles. El fixture original redirige las dos tablas a destinos dentro de su copia; la fuente resuelve las direcciones de sus etiquetas locales mediante LEA/MOV antes del prólogo original. Estas operaciones conservan flags y usan EAX, un registro caller-saved que la primera dependencia sustituye con su retorno. Por ello la implementación añade esa preparación explícita y no afirma identidad byte a byte de todo el código compilado.

En la selección se comparan cinco buffers completos de 4096 bytes, dos de 16.384 bytes, globals, trazas y estado flotante. Se observaron llamadas a las 19 dependencias y los ocho modos únicos enviados por los destinos de las tablas (2–5 y 20–23), incluyendo índices válidos 11–14 y salidas fuera del rango. Esto prueba esos destinos y las muestras registradas, sin atribuir cobertura exhaustiva de todas las aristas del método. Los punteros locales se comparan respecto al ESP guardado en el primer callback del caller.

Las versiones ASM utilizan bindings y almacenamiento mutable compartido para fixtures secuenciales. No son bindings de globals reales del juego y no admiten concurrencia. Los tres callers están reconstruidos dentro de ese alcance; sus sistemas externos, layout completo y ownership siguen pendientes.
