# Proceso para vincular direcciones y probar métodos

El primer caso fue `CDynamicEntity::GetBoneMatrix`. Se partió del CSV RTTI y del SDK, se comprobó la dirección en el EXE y se construyó una llamada al original. Esta guía sirve para repetir el proceso con más archivos.

1. **Elegir un método pequeño.** Empezar por funciones con firma y fuente conocidas. Los 4.016 headers contienen metadatos RTTI; eso no identifica automáticamente métodos, layouts ni límites de vtables.
2. **Fijar identidad y versión.** GTA IV PC 1.0.7.0 x86, SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`. Comprobar de nuevo si cambia el EXE.
3. **Distinguir direcciones.** El SDK suma la base del módulo a sus constantes: son RVA. Para GetBoneMatrix, RVA `0x005C7710`, VA preferida `0x009C7710`. En ejecución usar `base real + RVA`, sin fijar la base `0x00400000`.
   Contraste las referencias antes de fijar la dirección: IV-SDK, plugin_IV (patrones de bytes) e IV-SDK.Net (`1070.ini`). La columna `reference_names` de [hooks.csv](hooks.csv) y los CSV de [MemoryMap](MemoryMap/README.md) muestran qué referencias nombran una dirección. Es una pista; el desensamblado y las pruebas deciden.
4. **Contrastar bytes y firma.** Mapear RVA a sección/offset PE, exigir código ejecutable y guardar bytes de entrada. Desensamblar el cuerpo acotado: en este caso `this` llega en ECX, hay un argumento de 32 bits y ambas salidas usan `ret 4`. Los nombres semánticos del SDK siguen siendo referencias hasta corroborarlos.
5. **Añadir el wrapper.** Declaración propia en `reversing/MemoryMap/declarations`, método en el `.cpp` de su clase y compilación en `cmake/ReIV.vcxproj`. Usar `core/OriginalCall`: identidad del anfitrión, rango, protección y bytes. Dar una firma explícita y rechazar una vinculación no disponible. No inventar campos; el primer puente recibe una entidad real del SDK.
6. **Comprobar localmente.** Compilar Win32 y ejercitar convenciones de llamada, rechazo de anfitrión incorrecto y entradas nulas/no vinculadas. Que compile no demuestra que la llamada funcione en el juego.
7. **Probar en una copia del juego.** Activar un banco mediante marcador, respaldar archivos, aislar saves/settings, borrar informes previos y ejecutar directamente GTAIV.exe. Esperar una entidad real; conservar contadores, direcciones, hashes, resultado y código de salida. Restaurar los archivos en `finally` y verificar su contenido.
8. **Registrar el alcance exacto.** GetBoneMatrix pasó 64 llamadas al hueso raíz del jugador durante carga de escena: mismo puntero que el SDK, matriz finita, sin fallback de identidad ni excepciones y cierre normal. El primer intento no hizo llamadas porque esperaba el evento de inicio de partida. El segundo comprobó la entidad tras gameLoadEvent. Falta cubrir gameplay completo, otros huesos y otras entidades. Comparar dos rutas al mismo original comprueba el wrapper, no una implementación independiente.
9. **Actualizar el catálogo.** Añadir evidencia y entrada en `reversing/HookRegistry/catalog.json`; ejecutar `python reversing/HookRegistry/generate.py` (genera `docs/hooks.csv`, `docs/hooks_notiv.csv` y `source/core/HooksCatalog.h`) y después `bin/tools/ReIV.Tools.exe` (C#, compilado con `tools/ReIV.Tools/ReIV.Tools.csproj`), que genera `docs/ReversedClasses.md` con el orden completamente revertidas, parcialmente revertidas, sin revertir y desconocido, junto con la [clasificación de funciones](MemoryMap/FunctionClassification.md) y la [procedencia de dependencias](MemoryMap/DependencyProvenance.md). Separar dirección comprobada, llamada original probada, reconstrucción, hook instalado y validación de reconstrucción. No copiar las direcciones de ReSA o GTA V a GTA IV.
10. **Reconstruir después.** Sustituir el wrapper por código propio, comparar con el original y conservar un trampoline si se instala un hook. Llamar al destino enganchado desde el propio hook puede producir recursión. No marcar independencia hasta auditar también las llamadas transitivas.

## Siguiente trabajo

El siguiente candidato es `CDynamicEntity::GetBoneMatrix2`: el SDK documenta RVA `0x000D9100`, pero todavía necesita su propia comprobación de bytes, firma y prueba. Después conviene añadir métodos pequeños de entidades/físicas y validar llamadas virtuales sin perder el despacho de la instancia. No generar wrappers masivos solo porque existan destinos en `virtual_slots.csv`.

## Consola de depuración

`reiv::debug::Initialize`, en `core/DebugLog`, abre la consola al inicializar ReIV, sin marcador ni variable de entorno. La consola muestra nivel, hora con milisegundos, archivo/línea, vinculación de direcciones, instalación de hooks y resultados del banco. Los mensajes también se guardan en `ReIV.log`. El registro runtime se exporta a `ReIV-runtime-hooks.csv`; describe solo entradas de ReIV, no todos los hooks internos del SDK.

La consola no debe cerrarse con la X durante una partida: Windows puede cerrar también el proceso al que pertenece. Su apertura no activa el banco de llamadas ni el cierre automático de pruebas. El banco de llamadas originales usa el marcador independiente `ReIV.original-calls-test`; el cierre de validación usa `ReIV.validation-test`. Los destinos de `PendingHook` con firma o ABI desconocidas permanecen deshabilitados y no se ejecutan para comprobarlos. Ver una dirección en consola no equivale a haber probado su función.

## Evidencia del primer caso

- [Wrapper y verificación estática](../reversing/OriginalCalls/README.md).
- [Resultado en juego](../reversing/OriginalCalls/evidence/runtime-summary.json).
- [Desensamblado](../reversing/OriginalCalls/evidence/GetBoneMatrix.asm.txt).
- [Función reconstruida atStringHash](../reversing/AtStringHash/README.md).

## Prueba de la integración debug

La prueba posterior con consola automática pasó el 9 de octubre de 2026. Windows confirmó `visible=true` y `writable=true` mediante sus APIs; no se tomó una captura visual. atStringHash pasó 8.320 comparaciones del banco y 4.096 durante ejecución, sin fallos; GetBoneMatrix pasó 64 llamadas sin fallos ni excepciones. El juego terminó con código 0. Se instaló el mismo ASI probado en `D:\GTA IV\Grand Theft Auto IV - copia`, sin el marcador que activa el banco y su cierre automático. Las 45.558 referencias pendientes siguen deshabilitadas. [Resumen y hashes](../reversing/HookRegistry/evidence/always-console-runtime-summary.json), [estado de consola](../reversing/HookRegistry/evidence/always-console.json), [log](../reversing/HookRegistry/evidence/always-console-runtime.log) y [CSV runtime](../reversing/HookRegistry/evidence/always-console-runtime-hooks.csv).

La compilación con logger y catálogo pasó otra ejecución el 9 de octubre de 2026: 64 llamadas, cero fallos/excepciones y salida 0. El [log](../reversing/HookRegistry/evidence/debug-runtime.log) contiene nivel, hora, archivo y línea. El [CSV de esa ejecución](../reversing/HookRegistry/evidence/runtime-hooks.csv) registró base `0x00510000`, atStringHash en `0x006C1C30` y GetBoneMatrix en `0x00AD7710`, con el hook de la primera instalado y el segundo como vinculación original. Las direcciones runtime son de esa ejecución y pueden cambiar. [Resumen y hashes](../reversing/HookRegistry/evidence/debug-runtime-summary.json). El banco solicitó la consola mediante marcador; no se conserva captura visual de la ventana.
