# Segunda etapa de pruebas aisladas de game

Se reconocieron 98 destinos adicionales no registrados como comprobados en el catálogo actual: 28 comparaciones o extracciones de bits, y 70 cuerpos escalares lineales. Corresponden a 1.792 referencias del inventario.

Cada candidato conserva los bytes completos desde la entrada hasta `RET`. Los reconocedores excluyen llamadas, saltos, memoria global, registros no inicializados y accesos indirectos a otros objetos. Los accesos al objeto están limitados a memoria aislada. Esta etapa no presupone una firma semántica de las clases originales.

`prepare.py` genera `GameComplexProbe.h` y `evidence/fixture-scope.json`, con comprobaciones de igualdad, desigualdad, comparaciones con signo o sin signo y cadenas de operaciones sobre bits. `prepare_scalar.py` genera `GameComplexScalarProbe.h` y `evidence/scalar-scope.json`, modelando las instrucciones escalares admitidas. Deben ejecutarse en ese orden al regenerar. Los destinos ya comprobados y los del primer banco quedan excluidos del segundo.

`gamecomplex::Initialize()` y `Tick()` coordinan ambos bancos. El marcador único es `ReIV.game-complex-test`. `run.ps1` captura los dos reportes y verifica 64 muestras por destino, sin fallos ni excepciones, además del resultado de la prueba principal del juego. La expectativa son 6.272 llamadas aisladas; únicamente los reportes de ejecución confirman el resultado.

El éxito de estos bancos acredita las operaciones descritas y los argumentos probados. Las funciones no están reconstruidas, no se instalan reemplazos y siguen sin demostrarse tamaños y vida útil de objetos reales para cada propietario que comparte la dirección.
