# Clasificación de funciones binarias

[Inicio](../../README.md) · [Mapa de memoria](README.md) · [Procedencia de dependencias](DependencyProvenance.md) · [Progreso del reversing](../ReversedClasses.md)

> Generado por `tools/ReIV.Tools` (C#) a partir de los CSV de este directorio y de `docs/hooks.csv`. Sobre el EXE canónico `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

Este documento es una **clasificación de funciones binarias** (*Binary Function Classification*, parte del análisis estático de binarios): cada entrada de código del EXE recibe una **procedencia** y un **estado de reversión**. No desensambla ni valida comportamiento; solo cruza la evidencia ya inventariada.

## Criterios

- **Procedencia** (por el propietario RTTI del destino o, si solo hay nombre de referencia, por el espacio de nombres del nombre): GTA IV (juego), RAGE (motor), ART (NaturalMotion), NMutils, compartida entre varios orígenes o sin procedencia identificada. **No** distingue CRT, RenderWare-equivalente ni código generado: eso exige desensamblado y queda como *sin procedencia identificada*.
- **Estado de reversión**, en este orden: **Completamente revertidas** (reconstruida y con prueba aprobada), **Parcialmente revertidas** (reconstruida sin prueba aprobada), **Sin revertir** (procedencia identificada, sin reconstrucción) y **Desconocido** (sin procedencia).
- Una entrada de código no es una función demostrada; los límites son los detectados por Ghidra y los destinos de vtables.

## Resumen

| Dimensión | Progreso | Medición |
| --- | --- | --- |
| Completamente revertidas | `░░░░░░░░░░░░░░░░░░░░` | 43/34,141 · 0.13% |
| Parcialmente revertidas | `░░░░░░░░░░░░░░░░░░░░` | 0/34,141 · 0.00% |
| Sin revertir | `██████░░░░░░░░░░░░░░` | 10,131/34,141 · 29.67% |
| Desconocido | `██████████████░░░░░░` | 23,967/34,141 · 70.20% |

## Procedencia por estado

| Procedencia | Completamente revertidas | Parcialmente revertidas | Sin revertir | Desconocido | Total |
| --- | ---: | ---: | ---: | ---: | ---: |
| GTA IV (juego) | 40 | 0 | 5,493 | 0 | 5,533 |
| RAGE (motor) | 1 | 0 | 4,032 | 0 | 4,033 |
| ART (NaturalMotion) | 0 | 0 | 187 | 0 | 187 |
| NMutils | 0 | 0 | 3 | 0 | 3 |
| Compartida entre varios origenes | 2 | 0 | 416 | 0 | 418 |
| Sin procedencia identificada | 0 | 0 | 0 | 23,967 | 23,967 |
| **Total** | 43 | 0 | 10,131 | 23,967 | 34,141 |

## Base de la clasificación

| Base | Entradas |
| --- | ---: |
| ninguna | 23,967 |
| RTTI/vtable, referencia o catalogo con propietario | 9,986 |
| solo nombre de referencia (SDK) | 188 |

## Secciones por estado

### Completamente revertidas · 43 entradas

| Sección del PE | Entradas |
| --- | ---: |
| `.text` | 43 |

### Parcialmente revertidas · 0 entradas

Ninguna entrada en esta categoría.

### Sin revertir · 10,131 entradas

| Sección del PE | Entradas |
| --- | ---: |
| `.text` | 10,131 |

### Desconocido · 23,967 entradas

| Sección del PE | Entradas |
| --- | ---: |
| `.text` | 23,967 |

Detalle por dirección en [function_classification.csv](function_classification.csv).

