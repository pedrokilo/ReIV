# CEntity — ficha de direcciones

GTA IV **1.0.7.0**, x86. Base preferida `0x00400000`. Direcciones estáticas del EXE canónico; en ejecución, usar `base real + RVA`.

## Identidad y RTTI

| Elemento | VA estática | RVA |
| --- | --- | --- |
| TypeDescriptor `.?AVCEntity@@` | `0x0108F4EC` | `0x00C8F4EC` |
| CompleteObjectLocator | `0x00EC5B00` | `0x00AC5B00` |
| Tabla virtual | `0x00D83BAC` | `0x00983BAC` |

La jerarquía RTTI registra `CVirtualBase`. El locator indica desplazamiento de subobjeto `0`. Esto describe metadatos del binario; no define una estructura C++ propia ni la dirección de una instancia.

## Métodos virtuales

Se comprobaron los 51 punteros siguientes directamente en el EXE y su pertenencia a secciones ejecutables. El número de slots es un límite estimado por continuidad de punteros a código; todavía no demuestra el límite semántico exacto de la tabla.

Los nombres de tres slots proceden de los wrappers de IV-SDK. Son propuestas documentadas, con firma y comportamiento pendientes de validar. `FUN_*` es una etiqueta automática de Ghidra; no identifica el método. Un destino puede ser heredado, compartido o un thunk.

| Slot (desde 0) | VA del destino | RVA del destino | Nombre propuesto | Evidencia del nombre |
| ---: | --- | --- | --- | --- |
| 0 | `0x009EB060` | `0x005EB060` | Desconocido | Sin identificar |
| 1 | `0x009EAF60` | `0x005EAF60` | `Teleport(CMatrix*, bool, bool)` | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L41) |
| 2 | `0x0089E930` | `0x0049E930` | `Teleport(CVector*, bool, bool)` | [SDK, línea 46](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L46) |
| 3 | `0x0089BC10` | `0x0049BC10` | Desconocido | Sin identificar |
| 4 | `0x009E6D80` | `0x005E6D80` | Desconocido | Sin identificar |
| 5 | `0x009E9E10` | `0x005E9E10` | Desconocido | Sin identificar |
| 6 | `0x009EA680` | `0x005EA680` | Desconocido | Sin identificar |
| 7 | `0x009E8680` | `0x005E8680` | Desconocido | Sin identificar |
| 8 | `0x009E86C0` | `0x005E86C0` | Desconocido | Sin identificar |
| 9 | `0x005FDCD0` | `0x001FDCD0` | Desconocido | Sin identificar |
| 10 | `0x005FDCD0` | `0x001FDCD0` | Desconocido | Sin identificar |
| 11 | `0x005FDCD0` | `0x001FDCD0` | Desconocido | Sin identificar |
| 12 | `0x0089BBF0` | `0x0049BBF0` | Desconocido | Sin identificar |
| 13 | `0x00CFAEE0` | `0x008FAEE0` | Desconocido | Sin identificar |
| 14 | `0x009E7C20` | `0x005E7C20` | Desconocido | Sin identificar |
| 15 | `0x009E69E0` | `0x005E69E0` | Desconocido | Sin identificar |
| 16 | `0x009E7CF0` | `0x005E7CF0` | Desconocido | Sin identificar |
| 17 | `0x009E6A80` | `0x005E6A80` | Desconocido | Sin identificar |
| 18 | `0x009E6A10` | `0x005E6A10` | Desconocido | Sin identificar |
| 19 | `0x009E6A40` | `0x005E6A40` | Desconocido | Sin identificar |
| 20 | `0x009E8390` | `0x005E8390` | Desconocido | Sin identificar |
| 21 | `0x009E8280` | `0x005E8280` | Desconocido | Sin identificar |
| 22 | `0x009E6AE0` | `0x005E6AE0` | Desconocido | Sin identificar |
| 23 | `0x009E8490` | `0x005E8490` | Desconocido | Sin identificar |
| 24 | `0x009E6AF0` | `0x005E6AF0` | Desconocido | Sin identificar |
| 25 | `0x009E6B00` | `0x005E6B00` | Desconocido | Sin identificar |
| 26 | `0x009E7EC0` | `0x005E7EC0` | Desconocido | Sin identificar |
| 27 | `0x009E9590` | `0x005E9590` | Desconocido | Sin identificar |
| 28 | `0x004D7030` | `0x000D7030` | Desconocido | Sin identificar |
| 29 | `0x004D7030` | `0x000D7030` | Desconocido | Sin identificar |
| 30 | `0x00447970` | `0x00047970` | Desconocido | Sin identificar |
| 31 | `0x00491800` | `0x00091800` | Desconocido | Sin identificar |
| 32 | `0x00C28820` | `0x00828820` | Desconocido | Sin identificar |
| 33 | `0x009E9BA0` | `0x005E9BA0` | Desconocido | Sin identificar |
| 34 | `0x00C28820` | `0x00828820` | Desconocido | Sin identificar |
| 35 | `0x009EA540` | `0x005EA540` | `PreRender(int, int, char, int)` | [SDK, línea 51](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L51) |
| 36 | `0x005FDCD0` | `0x001FDCD0` | Desconocido | Sin identificar |
| 37 | `0x00550FF0` | `0x00150FF0` | Desconocido | Sin identificar |
| 38 | `0x00C28820` | `0x00828820` | Desconocido | Sin identificar |
| 39 | `0x008B8FE0` | `0x004B8FE0` | Desconocido | Sin identificar |
| 40 | `0x008E05A0` | `0x004E05A0` | Desconocido | Sin identificar |
| 41 | `0x007BDC00` | `0x003BDC00` | Desconocido | Sin identificar |
| 42 | `0x009EAB70` | `0x005EAB70` | Desconocido | Sin identificar |
| 43 | `0x009E8710` | `0x005E8710` | Desconocido | Sin identificar |
| 44 | `0x009E7110` | `0x005E7110` | Desconocido | Sin identificar |
| 45 | `0x009EAC60` | `0x005EAC60` | Desconocido | Sin identificar |
| 46 | `0x009E7140` | `0x005E7140` | Desconocido | Sin identificar |
| 47 | `0x009C80B0` | `0x005C80B0` | Desconocido | Sin identificar |
| 48 | `0x009C80C0` | `0x005C80C0` | Desconocido | Sin identificar |
| 49 | `0x00549100` | `0x00149100` | Desconocido | Sin identificar |
| 50 | `0x00549100` | `0x00149100` | Desconocido | Sin identificar |

## Tamaño y campos de referencia

IV-SDK declara tamaño `0x70` (112 bytes) y las siguientes comprobaciones de offsets. Son referencias de su layout, pendientes de corroborar para este binario; un offset de campo no es una dirección absoluta.

| Campo | Offset dentro del objeto |
| --- | --- |
| `m_pMatrix` | `0x20` |
| `m_nEntityFlags` | `0x24` |
| `m_pInstGta` | `0x38` |
| `m_fDrawDistance` | `0x50` |

## Pendiente

- Identificar los otros 48 slots y revisar los límites de la tabla.
- Localizar constructor, destructor y métodos no virtuales mediante referencias estáticas.
- Corroborar layout y ABI antes de crear una declaración propia en `source/game`.
- Asociar globales únicamente cuando haya evidencia de su relación con esta clase.

## Evidencia

- EXE: SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- Header IV-SDK consultado: SHA-256 `7ff4440e4682d8d1161c61e0e6e39716ca78da3fc41f62f71d1b5b5b703ee5e3`.
- [Ficha estructurada](CEntity.json): slots, etiquetas originales de Ghidra y procedencia de los nombres.
- [Inventario RTTI](../classes.csv), [tablas](../vtables.csv) y [slots originales](../virtual_slots.csv).
- [Header de IV-SDK](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h).

Esta ficha no añade implementaciones, hooks ni validaciones de comportamiento. El catálogo de reconstrucción permanece separado.
