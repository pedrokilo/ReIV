# Análisis de pendientes y pruebas adicionales

Esta pasada revisa el inventario de pendientes y ejecuta solamente cuerpos completos con efectos locales comprobables. **No completa el análisis funcional ni las pruebas de todas las funciones complejas.**

## Pruebas nuevas

- Game: 148 direcciones, 9.472 llamadas. [Resultado](../../reversing/PendingAnalysis/game/evidence/runtime-summary.json).
- Rage/ART: 83 direcciones (las 83 de rage), 5.312 llamadas. [Resultado](../../reversing/PendingAnalysis/rage-art/evidence/runtime-summary.json).
- Los dos bancos terminaron sin fallos ni excepciones, con salida normal del juego y consola visible. No reconstruyen las clases ni activan hooks pendientes.
- Para RVA `0x001BDC60` se comprueba únicamente EAX y la memoria: el cuerpo también escribe EDX y su retorno completo permanece sin confirmar.

## Cobertura actual

| Carpeta | Referencias | Llamadas comprobadas (referencias) | Fatal excluido | Tablas discrepantes excluidas | Restantes sin llamada | Destinos sin llamada, incluido fatal |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| game | 25399 | 11608 | 272 | 12 | 13507 | 4911 |
| rage | 19806 | 9891 | 291 | 0 | 9624 | 3044 |
| ART | 353 | 144 | 52 | 0 | 157 | 138 |

Las referencias pueden compartir una misma dirección. Estos totales no equivalen a clases reconstruidas ni a funciones independientes. [Detalle por referencia](pending_analysis.csv).

## Análisis estático y límites

[Game](../../reversing/PendingAnalysis/game/README.md) clasifica sus 5.719 destinos iniciales. [Rage/ART](../../reversing/PendingAnalysis/rage-art/README.md) clasifica 3.354 destinos pendientes distintos. Incluyen bytes de entrada, llamadas observadas y motivos concretos para no ejecutar. Fuera de los cuerpos completos reconocidos, el análisis se limita a un tramo de entrada y no recupera todo el flujo de control.

La exportación del proyecto Ghidra existente revisó 8.377 direcciones iniciales: 3.809 tienen una función delimitada, 4.557 carecen de límite definido y 11 caen dentro de otra función. Para las funciones delimitadas se exportaron rangos de cuerpo y dependencias directas/indirectas. Son resultados del proyecto guardado: sus firmas inferidas no están verificadas y la ausencia de límites no prueba ausencia de código. [Funciones](../../reversing/PendingAnalysis/evidence/ghidra/functions.csv) · [Dependencias](../../reversing/PendingAnalysis/evidence/ghidra/dependencies.csv).

## Tipos desconocidos

Se investigaron los 585 tipos originales. Se recuperaron seis callbacks de metadatos de excepciones MSVC pertenecientes a cuatro tipos; se añadieron a sus headers como direcciones estáticas, sin llamar ni reconstruir. Ahora quedan **581 desconocidos**: 13 de game y 568 de rage. [Análisis reproducible](../../reversing/UnknownTypesAnalysis/README.md).

578 tipos figuran como bases y siete solo tenían descriptores. El escaneo no encontró tablas virtuales propias omitidas. Una relación de herencia no permite adjudicar a la base métodos de una clase derivada. Para seguir hacen falta referencias de constructores/destructores y usos concretos de objetos, no direcciones inventadas.

## Manejador fatal

RVA `0x00001210` llama al helper `0x005A8CB0`. La evidencia muestra `MessageBoxW` y una escritura en dirección cero, seguida de una posible salida. Se utiliza para tratar un error irrecuperable; invocarlo deliberadamente puede terminar el proceso. Sus referencias permanecen excluidas. [Cuerpo](../../reversing/NMutils/evidence/00401210.txt) · [Helper](../../reversing/NMutils/evidence/005a8cb0.txt).

## Qué sigue sin resolver

Las funciones complejas requieren delimitar sus cuerpos, recuperar firmas y layouts, revisar sus llamadas y establecer cuándo existen objetos válidos. Las lecturas de punteros, globals/TLS, constructores, destructores y saltos indirectos no se probaron con objetos inventados. Las exclusiones fatales se conservan; ninguna prueba habilita automáticamente un hook.

Regenerar esta ficha y el CSV con `python reversing/PendingAnalysis/summarize.py`, después de los headers y del catálogo. Los bancos se repiten con `reversing/PendingAnalysis/game/run.ps1` y `reversing/PendingAnalysis/rage-art/run.ps1`.

## Reanálisis nuevo de Ghidra

El nuevo análisis REA/Ghidra del mismo EXE reconoce 8,354 de las 8.377 direcciones pendientes iniciales como entradas. Se guardaron 8,354 resultados de decompilación con evidencia. Esto mejora el proyecto histórico, pero el pseudocódigo no es una firma aprobada, una reconstrucción ni una llamada probada. Los 23 destinos iniciales restantes requieren revisar referencias o límites. Los seis callbacks EH recuperados después están fuera del banco inicial. [Entradas nuevas](../../reversing/PendingAnalysis/evidence/fresh-ghidra-procedures.csv) · [Evidencia](../../reversing/PendingAnalysis/evidence/fresh-ghidra-evidence.json) · [Pseudocódigo por lotes](../../reversing/PendingAnalysis/evidence/decompilation).

## Compilación e instalación

Pasaron Release/Win32 y la comprobación sintáctica de los 4.016 headers. Se instaló el ASI final en la copia del juego con respaldo, consola automática y sin marcadores de prueba activos. [Registro de instalación](../../reversing/PendingAnalysis/evidence/installation.json).
