# FLOSS: herramienta local de cadenas

Disponible desde el 9 de octubre de 2026: **FLOSS 3.1.1**, ejecutable `C:\Users\pedro\Tools\FLOSS\floss.exe`. Instalado en el PATH del usuario `pedro`, no para todos los usuarios. Codex y Claude pueden usarlo mediante su terminal local; usar la ruta completa si su sesión no ha recogido el PATH nuevo.

Se verificaron `--version` y `--help`. No se ha ejecutado todavía sobre GTA IV ni se atribuyen nuevos hallazgos o validaciones a esta instalación.

Desde la raíz de ReIV:

```powershell
& 'C:\Users\pedro\Tools\FLOSS\floss.exe' --version
New-Item -ItemType Directory -Force 'build/floss' | Out-Null
& 'C:\Users\pedro\Tools\FLOSS\floss.exe' -j --only static -- 'C:\Users\pedro\Tools\ReIV-analysis\targets\GTAIV.exe' > 'build/floss/static.json'
# Pasada complementaria de todos los tipos admitidos:
& 'C:\Users\pedro\Tools\FLOSS\floss.exe' -j -- 'C:\Users\pedro\Tools\ReIV-analysis\targets\GTAIV.exe' > 'build/floss/all.json'
```

Comprobar que la entrada conserva el SHA-256 canónico del [README](../README.md). Registrar hash, versión de FLOSS, comando, código de salida, resultados y limitaciones. Los ejemplos no ejecutan el juego ni instalan hooks.

FLOSS extrae cadenas estáticas, construidas en pila y decodificadas. Sus hallazgos sirven para buscar referencias en Ghidra; no reconstruyen funciones, no demuestran equivalencia y no recuperan automáticamente nombres originales a partir de hashes. Priorizar la pasada estática y valorar la utilidad adicional de la decodificación.

[Proyecto oficial](https://github.com/mandiant/flare-floss) · [Release descargada v3.1.1](https://github.com/mandiant/flare-floss/releases/tag/v3.1.1). SHA-256 local del ZIP Windows: `6c71089b8c629c69424b042769f1565f71adc6cd24b2f8d3713c96fa7fdac2fb`; no es una suma publicada por el autor.
