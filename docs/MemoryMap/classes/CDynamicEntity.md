# CDynamicEntity — ficha de direcciones

GTA IV **1.0.7.0**, x86. Base preferida `0x00400000`; VA en ejecución = base real + RVA.

## Identidad y jerarquía

| Elemento | VA estática | RVA |
| --- | --- | --- |
| TypeDescriptor `.?AVCDynamicEntity@@` | `0x0108F504` | `0x00C8F504` |
| CompleteObjectLocator | `0x00EC5A54` | `0x00AC5A54` |
| Tabla virtual | `0x00D82E14` | `0x00982E14` |

RTTI registra `CEntity` y `CVirtualBase`; el locator tiene desplazamiento de subobjeto `0`. IV-SDK declara `CDynamicEntity : CEntity`. Las bases RTTI pueden incluir tipos transitivos.

## Comparación con CEntity

Entre los 51 slots inventariados de [CEntity](CEntity.md), **33 conservan el mismo destino** y **18 tienen otro destino**. Otros **4 slots** quedan fuera del inventario de CEntity.

Se comparan índices y punteros del EXE. Un cambio de destino puede corresponder a una implementación diferente o un thunk; no determina por sí solo el propietario del cuerpo. Los límites de las tablas son estimados por continuidad de punteros a código.

## Métodos virtuales

Los 55 punteros siguientes se contrastaron directamente con el EXE y apuntan a bytes de secciones ejecutables. Los tres nombres proceden de wrappers de clases base y necesitan confirmar su correspondencia en CDynamicEntity. Todos los nombres, firmas y comportamientos quedan pendientes de validación semántica.

| Slot | VA del destino | RVA | Nombre propuesto | Frente a CEntity | Evidencia del nombre |
| ---: | --- | --- | --- | --- | --- |
| 0 | `0x009e2300` | `0x005e2300` | Desconocido | Destino diferente | Sin identificar |
| 1 | `0x009eaf60` | `0x005eaf60` | `Teleport(CMatrix*, bool, bool)` | Mismo destino | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L41) |
| 2 | `0x0089e930` | `0x0049e930` | `Teleport(CVector*, bool, bool)` | Mismo destino | [SDK, línea 46](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L46) |
| 3 | `0x0089bc10` | `0x0049bc10` | Desconocido | Mismo destino | Sin identificar |
| 4 | `0x009e1960` | `0x005e1960` | Desconocido | Destino diferente | Sin identificar |
| 5 | `0x009e9e10` | `0x005e9e10` | Desconocido | Mismo destino | Sin identificar |
| 6 | `0x009e1ed0` | `0x005e1ed0` | Desconocido | Destino diferente | Sin identificar |
| 7 | `0x009e0410` | `0x005e0410` | Desconocido | Destino diferente | Sin identificar |
| 8 | `0x009e0440` | `0x005e0440` | Desconocido | Destino diferente | Sin identificar |
| 9 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 10 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 11 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 12 | `0x0089bbf0` | `0x0049bbf0` | Desconocido | Mismo destino | Sin identificar |
| 13 | `0x00cfaee0` | `0x008faee0` | Desconocido | Mismo destino | Sin identificar |
| 14 | `0x009e7c20` | `0x005e7c20` | Desconocido | Mismo destino | Sin identificar |
| 15 | `0x009e69e0` | `0x005e69e0` | Desconocido | Mismo destino | Sin identificar |
| 16 | `0x009e7cf0` | `0x005e7cf0` | Desconocido | Mismo destino | Sin identificar |
| 17 | `0x009e22a0` | `0x005e22a0` | Desconocido | Destino diferente | Sin identificar |
| 18 | `0x009e18a0` | `0x005e18a0` | Desconocido | Destino diferente | Sin identificar |
| 19 | `0x009e6a40` | `0x005e6a40` | Desconocido | Mismo destino | Sin identificar |
| 20 | `0x009e05c0` | `0x005e05c0` | Desconocido | Destino diferente | Sin identificar |
| 21 | `0x009e04d0` | `0x005e04d0` | Desconocido | Destino diferente | Sin identificar |
| 22 | `0x009e0490` | `0x005e0490` | Desconocido | Destino diferente | Sin identificar |
| 23 | `0x009e0610` | `0x005e0610` | Desconocido | Destino diferente | Sin identificar |
| 24 | `0x009e0660` | `0x005e0660` | Desconocido | Destino diferente | Sin identificar |
| 25 | `0x009e0690` | `0x005e0690` | Desconocido | Destino diferente | Sin identificar |
| 26 | `0x009e06c0` | `0x005e06c0` | Desconocido | Destino diferente | Sin identificar |
| 27 | `0x009e0bd0` | `0x005e0bd0` | Desconocido | Destino diferente | Sin identificar |
| 28 | `0x004d7030` | `0x000d7030` | Desconocido | Mismo destino | Sin identificar |
| 29 | `0x004d7030` | `0x000d7030` | Desconocido | Mismo destino | Sin identificar |
| 30 | `0x00447970` | `0x00047970` | Desconocido | Mismo destino | Sin identificar |
| 31 | `0x00491800` | `0x00091800` | Desconocido | Mismo destino | Sin identificar |
| 32 | `0x00c28820` | `0x00828820` | Desconocido | Mismo destino | Sin identificar |
| 33 | `0x009e1480` | `0x005e1480` | Desconocido | Destino diferente | Sin identificar |
| 34 | `0x009e1b70` | `0x005e1b70` | Desconocido | Destino diferente | Sin identificar |
| 35 | `0x009e15d0` | `0x005e15d0` | `PreRender(int, int, char, int)` | Destino diferente | [SDK, línea 51](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L51) |
| 36 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 37 | `0x00550ff0` | `0x00150ff0` | Desconocido | Mismo destino | Sin identificar |
| 38 | `0x00c28820` | `0x00828820` | Desconocido | Mismo destino | Sin identificar |
| 39 | `0x008b8fe0` | `0x004b8fe0` | Desconocido | Mismo destino | Sin identificar |
| 40 | `0x008e05a0` | `0x004e05a0` | Desconocido | Mismo destino | Sin identificar |
| 41 | `0x007bdc00` | `0x003bdc00` | Desconocido | Mismo destino | Sin identificar |
| 42 | `0x009eab70` | `0x005eab70` | Desconocido | Mismo destino | Sin identificar |
| 43 | `0x009e8710` | `0x005e8710` | Desconocido | Mismo destino | Sin identificar |
| 44 | `0x009e7110` | `0x005e7110` | Desconocido | Mismo destino | Sin identificar |
| 45 | `0x009eac60` | `0x005eac60` | Desconocido | Mismo destino | Sin identificar |
| 46 | `0x009e7140` | `0x005e7140` | Desconocido | Mismo destino | Sin identificar |
| 47 | `0x009c80b0` | `0x005c80b0` | Desconocido | Mismo destino | Sin identificar |
| 48 | `0x009c80c0` | `0x005c80c0` | Desconocido | Mismo destino | Sin identificar |
| 49 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 50 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 51 | `0x009e15b0` | `0x005e15b0` | Desconocido | Fuera del inventario base | Sin identificar |
| 52 | `0x007bdc00` | `0x003bdc00` | Desconocido | Fuera del inventario base | Sin identificar |
| 53 | `0x007bdc00` | `0x003bdc00` | Desconocido | Fuera del inventario base | Sin identificar |
| 54 | `0x009dfe70` | `0x005dfe70` | Desconocido | Fuera del inventario base | Sin identificar |

## Referencias de funciones del SDK

El primer argumento de AddressSetter corresponde a 1.0.7.0. Se comprobó que las ubicaciones contienen bytes de código; un wrapper de dirección fija no demuestra que el método sea no virtual. Nombres y ABI pendientes de corroborar.

| Referencia | VA estática | RVA | Fuente |
| --- | --- | --- | --- |
| `CDynamicEntity::GetBoneMatrix` | `0x009c7710` | `0x005c7710` | [SDK, línea 11](../../../contrib/IV%20SDK/IV-SDK-main/include/CDynamicEntity.h#L11) |
| `CDynamicEntity::GetBoneMatrix2` | `0x004d9100` | `0x000d9100` | [SDK, línea 17](../../../contrib/IV%20SDK/IV-SDK-main/include/CDynamicEntity.h#L17) |

## Tamaño y campos de referencia

IV-SDK declara tamaño `0x110` (272 bytes). Los offsets siguientes proceden de las macros VALIDATE_OFFSET de CDynamicEntity y no se presentan como layout verificado en este EXE. Los campos de clases y estructuras auxiliares del mismo header quedan fuera de esta ficha.

| Campo | Offset dentro de CDynamicEntity | Línea del SDK |
| --- | --- | ---: |
| `m_pAnim` | `0x78` | 22 |

## Pendiente

- Identificar slots desconocidos y confirmar los límites de tabla.
- Localizar constructor y destructor mediante referencias estáticas.
- Corroborar layout, firmas y ABI antes de declarar la clase en source/game.
- Revisar qué cambios de CPhysical ya aparecen en CDynamicEntity.

## Evidencia

- EXE: SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- [Ficha estructurada](CDynamicEntity.json): etiquetas originales, destinos de la base por slot, referencias, offsets y hashes de headers.
- [Inventario RTTI](../classes.csv), [tablas](../vtables.csv) y [slots originales](../virtual_slots.csv).
- [CDynamicEntity del SDK](../../../contrib/IV%20SDK/IV-SDK-main/include/CDynamicEntity.h).

Esta ficha registra direcciones y referencias. No añade reconstrucciones, hooks ni validaciones de comportamiento.
