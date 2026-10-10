# Validación de NMutils

Las tres clases del inventario presentan seis destinos virtuales únicos: cuatro en `NMutils::BasicLogger`, uno en `NMutils::MemoryStream` y uno en `NMutils::MemoryStreamReader`. Las direcciones pertenecen al ejecutable PC 1.0.7.0 con SHA256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

La exportación estática incluye cuerpos completos y dependencias relevantes. Los nombres descriptivos son inferencias del código máquina; no se recuperaron símbolos originales.

| Clase | VA preferida | RVA | Comportamiento inferido | Prueba preparada |
|---|---|---|---|---|
| BasicLogger | 0x005D4F40 | 0x001D4F40 | Destructor con indicador de liberación | Objeto sintético, indicador cero, retorno y vtable |
| BasicLogger | 0x005D67F0 | 0x001D67F0 | Convierte texto estrecho a ancho y llama slot 2 | Capturar texto y nivel con callback sintético |
| BasicLogger | 0x00401210 | 0x00001210 | Manejador fatal compartido | Excluido: muestra MessageBoxW, escribe dirección cero y puede terminar el proceso |
| BasicLogger | 0x005D67A0 | 0x001D67A0 | Formatea texto ancho mediante argumentos variables y llama slot 2 | Formato ancho con entero y captura de texto/nivel |
| MemoryStream | 0x005E1600 | 0x001E1600 | Destructor con indicador de liberación | Objeto sintético vacío, indicador cero, retorno y vtable |
| MemoryStreamReader | 0x005E1820 | 0x001E1820 | Destructor que desvincula lector de su stream | Lector y padre sintéticos, indicador cero, retorno, vtable y limpieza de padre+0x34 |

Los destructores usan `__thiscall` y consumen un argumento de cuatro bytes. La conversión estrecho→ancho consume dos argumentos. El formateador variádico usa `__cdecl`, con objeto como primer argumento explícito. El callback virtual recibe texto `wchar_t`, confirmado porque la dependencia 0x00D11C9F duplica la longitud de caracteres y escribe un terminador de dos bytes.

El banco `source/hooks/NMutilsProbe.h` está condicionado al marcador `ReIV.nmutils-test`. Solo usa objetos temporales del banco, nunca objetos del juego, y deja excluido el destino fatal. Las comprobaciones de comportamiento abarcan únicamente objetos vacíos, ramas sin liberación y mensajes de prueba. No validan constructores, propiedad de memoria, destructores con liberación ni el diseño completo de estas clases. Son llamadas al código original, no reconstrucciones ni sustituciones instaladas.

El banco pasó dentro del juego el 9 de octubre de 2026: 64 llamadas por cada una de las cinco entradas admitidas, 320 en total, sin fallos ni excepciones. La entrada fatal tuvo cero llamadas. Se comprobaron los efectos descritos en la tabla; el juego cerró normalmente con código 0. atStringHash y GetBoneMatrix también pasaron sus bancos durante la misma ejecución. La consola estuvo visible y disponible para escritura. Ningún hook de sustitución NMutils se instaló.

Las cinco referencias ahora incluyen la evidencia histórica de la prueba en sus headers y en `pending_hooks.csv`, conservando `enabled=false` y `reconstructed=false`. [hooks.csv](../hooks.csv) y [ClassesAndHooks.md](ClassesAndHooks.md) incluyen las llamadas originales probadas; los nombres son descriptivos inferidos.

Evidencia: [resumen runtime y hashes](../../reversing/NMutils/evidence/runtime-summary.json), [contadores por entrada](../../reversing/NMutils/evidence/runtime-report.json), [log](../../reversing/NMutils/evidence/runtime.log), [CSV de las seis referencias](../../reversing/NMutils/evidence/static-targets.csv), [ABI estático](../../reversing/NMutils/evidence/static-abi.md), [bytes de entrada](../../reversing/NMutils/evidence/entry-bytes.json), [secciones PE](../../reversing/NMutils/evidence/pe-sections.json).
