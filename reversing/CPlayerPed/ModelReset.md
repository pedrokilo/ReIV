# CPlayerPed: reset posterior al cambio de modelo

`PlayerPedModelReset.h` reconstruye el cuerpo propio completo de `0x009BF660`, **163 bytes**, llamado desde la selección de modelo. Sus dependencias explícitas son seis funciones directas y el slot virtual 68 (`vtable+0x110`). Las implementaciones de esas siete dependencias siguen pendientes. No se instaló un reemplazo ni se ejecutó este reset sobre el jugador real.

El método copia exactamente los bits del global `0x00D50398` a `0x00F1D9D8`; `MOVSS` realiza una transferencia, sin conversión numérica. Activa el bit 0 en `this+0x24`, pone cero en `this+0xA80` y llama `8A92C0(0)`, `8A07E0(1)`, `8A70C0(0,-1)` y `89C8B0(-1)`, en ese orden. Después lee `this+0x228`, activa `0x20000` en `this+0x26C` y limpia el bit 1 de `[member+0x60]+0x3D0`, cuando el puntero y su suma de 32 bits no son cero.

La llamada virtual se conserva como dependencia. Después vuelve a activar el bit 0 de `this+0x24`. Si el byte bajo del argumento es cero, llama `9BF0D0(1,0,1)`. Vuelve a leer `this+0x228` después de todas esas llamadas y llama `8793F0` con `member+0x60` si ambos valores son distintos de cero. Se conserva el caso especial `member=0xFFFFFFA0`, cuya suma de 32 bits produce cero. El original descarta cuatro bytes de stack (`RET 4`), aunque solo consume el byte bajo del argumento.

## Comparación independiente Win32

El fixture procede del EXE canónico y ejecuta todas las instrucciones originales, sustituyendo únicamente destinos CALL directos, dos operandos globales y la vtable aislada. Los stubs modifican deliberadamente los flags, globals y el puntero de miembro para comprobar el orden y las relecturas. La implementación C++ usa callbacks y nunca reenvía la ejecución a la función original completa.

Pasaron **10.752 comparaciones, cero diferencias**: 256 combinaciones de estados de miembro entre llamadas, seis argumentos DWORD y siete patrones de bits globales. Incluye punteros nulos, dos bloques válidos y `0xFFFFFFA0`, argumentos con byte bajo cero y bits altos activos, ceros con signo, NaN/sNaN, denormal y otros bits. Se comparan trazas ordenadas con observaciones de flags, argumentos y globals; tres buffers completos de 4096 bytes; ambos globals; estado x87 y MXCSR con excepciones enmascaradas.

La firma está en `evidence/model-reset-validation.json`; instrucciones y contratos de stack en `evidence/model-reset-static.json`. La prueba acredita el cuerpo propio con dependencias deterministas, no la reconstrucción de sus sistemas externos ni de la clase completa.
