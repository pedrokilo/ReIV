# Banco NMutils

Inventario objetivo: `source/external/NMutils/BasicLogger.h`, `MemoryStream.h` y `MemoryStreamReader.h`.

`ExportNMutils.java` exporta seis destinos y cuatro dependencias desde el proyecto canónico existente con Ghidra headless, sin análisis global ni cambios persistidos. Los cuerpos están en `evidence/*.txt`. `evidence/static-abi.md` documenta firmas inferidas, efectos y límites. `evidence/entry-bytes.json` contiene las primeras 16 posiciones de cada entrada; la correspondencia RVA→offset de archivo se confirma en `evidence/pe-sections.json`.

El banco dentro del juego se define en `source/hooks/NMutilsProbe.h` y se activa mediante `ReIV.nmutils-test`. Prepara objetos temporales, suministra callbacks propios y comprueba resultados. El destino 0x00401210 permanece excluido por su comportamiento fatal demostrado en 0x005A8CB0. Ninguna prueba destruye objetos del juego ni usa el indicador de liberación del destructor.

La documentación de las seis referencias está en `docs/MemoryMap/NMutilsValidation.md`. Las pruebas confirman solo ramas controladas; las referencias originales del inventario no se convierten automáticamente en hooks instalables.
