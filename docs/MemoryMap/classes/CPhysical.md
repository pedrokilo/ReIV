# CPhysical — ficha de direcciones

GTA IV **1.0.7.0**, x86. Base preferida `0x00400000`; VA en ejecución = base real + RVA.

## Identidad y jerarquía

| Elemento | VA estática | RVA |
| --- | --- | --- |
| TypeDescriptor `.?AVCPhysical@@` | `0x0108F524` | `0x00C8F524` |
| CompleteObjectLocator | `0x00EC7CAC` | `0x00AC7CAC` |
| Tabla virtual | `0x00D89F2C` | `0x00989F2C` |

RTTI registra `CDynamicEntity`, `CEntity` y `CVirtualBase`; el locator tiene desplazamiento de subobjeto `0`. IV-SDK declara la cadena `CPhysical : CDynamicEntity : CEntity`. Las bases RTTI pueden ser transitivas.

## Comparación con CEntity

Entre los 51 slots inventariados de [CEntity](CEntity.md), **25 conservan el mismo destino** y **26 tienen otro destino**. Otros **21 slots** quedan fuera del inventario de CEntity.

La comparación usa el mismo índice y los punteros del EXE. Un destino distinto no demuestra por sí solo una implementación propia de CPhysical: puede proceder de CDynamicEntity o ser un thunk. Un destino igual puede ser compartido por varias funciones. Los límites de ambas tablas siguen siendo estimados.

## Métodos virtuales

Los 72 punteros se contrastaron directamente con el EXE y apuntan a bytes de secciones ejecutables. Los nombres de los slots 59, 63 y 71 proceden de wrappers de CPhysical en el SDK; 1, 2 y 35 usan la referencia de slot de CEntity y requieren confirmar su correspondencia en la derivada. Firmas y comportamientos pendientes de validar.

| Slot | VA del destino | RVA | Nombre propuesto | Frente a CEntity | Evidencia del nombre |
| ---: | --- | --- | --- | --- | --- |
| 0 | `0x00a48610` | `0x00648610` | Desconocido | Destino diferente | Sin identificar |
| 1 | `0x00a48eb0` | `0x00648eb0` | `Teleport(CMatrix*, bool, bool)` | Destino diferente | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L41) |
| 2 | `0x00a48e40` | `0x00648e40` | `Teleport(CVector*, bool, bool)` | Destino diferente | [SDK, línea 46](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L46) |
| 3 | `0x00a47a40` | `0x00647a40` | Desconocido | Destino diferente | Sin identificar |
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
| 29 | `0x00cfaee0` | `0x008faee0` | Desconocido | Destino diferente | Sin identificar |
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
| 42 | `0x00c28820` | `0x00828820` | Desconocido | Destino diferente | Sin identificar |
| 43 | `0x00a48630` | `0x00648630` | Desconocido | Destino diferente | Sin identificar |
| 44 | `0x00a486e0` | `0x006486e0` | Desconocido | Destino diferente | Sin identificar |
| 45 | `0x00a48770` | `0x00648770` | Desconocido | Destino diferente | Sin identificar |
| 46 | `0x009e7140` | `0x005e7140` | Desconocido | Mismo destino | Sin identificar |
| 47 | `0x009c80b0` | `0x005c80b0` | Desconocido | Mismo destino | Sin identificar |
| 48 | `0x009c80c0` | `0x005c80c0` | Desconocido | Mismo destino | Sin identificar |
| 49 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 50 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 51 | `0x009e15b0` | `0x005e15b0` | Desconocido | Fuera del inventario base | Sin identificar |
| 52 | `0x007bdc00` | `0x003bdc00` | Desconocido | Fuera del inventario base | Sin identificar |
| 53 | `0x007bdc00` | `0x003bdc00` | Desconocido | Fuera del inventario base | Sin identificar |
| 54 | `0x009dfe70` | `0x005dfe70` | Desconocido | Fuera del inventario base | Sin identificar |
| 55 | `0x00a476b0` | `0x006476b0` | Desconocido | Fuera del inventario base | Sin identificar |
| 56 | `0x00447b20` | `0x00047b20` | Desconocido | Fuera del inventario base | Sin identificar |
| 57 | `0x00a48a40` | `0x00648a40` | Desconocido | Fuera del inventario base | Sin identificar |
| 58 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 59 | `0x00a477f0` | `0x006477f0` | `GetVelocity(CVector*)` | Fuera del inventario base | [SDK, línea 44](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L44) |
| 60 | `0x00a47930` | `0x00647930` | Desconocido | Fuera del inventario base | Sin identificar |
| 61 | `0x00a47950` | `0x00647950` | Desconocido | Fuera del inventario base | Sin identificar |
| 62 | `0x00a47970` | `0x00647970` | Desconocido | Fuera del inventario base | Sin identificar |
| 63 | `0x00447b30` | `0x00047b30` | `GetHealth()` | Fuera del inventario base | [SDK, línea 61](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L61) |
| 64 | `0x00a49650` | `0x00649650` | Desconocido | Fuera del inventario base | Sin identificar |
| 65 | `0x00948fd0` | `0x00548fd0` | Desconocido | Fuera del inventario base | Sin identificar |
| 66 | `0x00447b40` | `0x00047b40` | Desconocido | Fuera del inventario base | Sin identificar |
| 67 | `0x00447b50` | `0x00047b50` | Desconocido | Fuera del inventario base | Sin identificar |
| 68 | `0x00a48550` | `0x00648550` | Desconocido | Fuera del inventario base | Sin identificar |
| 69 | `0x00a4a320` | `0x0064a320` | Desconocido | Fuera del inventario base | Sin identificar |
| 70 | `0x00a4a890` | `0x0064a890` | Desconocido | Fuera del inventario base | Sin identificar |
| 71 | `0x00a4af20` | `0x0064af20` | `ProcessWater()` | Fuera del inventario base | [SDK, línea 50](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L50) |

## Referencias de funciones del SDK

No se identifican como métodos no virtuales sólo por tener un wrapper de dirección fija. Las ubicaciones están mapeadas a código, pero los nombres y ABI no están validados.

| Referencia | VA estática | RVA | Fuente |
| --- | --- | --- | --- |
| `CPhysical::GetConstrainedCollider` | `0x009e7080` | `0x005e7080` | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L41) |
| `CPhysical::_ProcessWater` | `0x00a4af20` | `0x0064af20` | [SDK, línea 52](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L52) |

El slot 71 apunta a `0x00a4af20`. Comparar con la referencia fija de `_ProcessWater` sólo establece si coinciden las direcciones; no demuestra el comportamiento del método.

## Tamaño y campos de referencia

IV-SDK declara tamaño `0x210` (528 bytes). Estos offsets proceden de sus macros `VALIDATE_OFFSET`; su layout queda pendiente de corroborar en el binario.

| Campo | Offset dentro del objeto |
| --- | --- |
| `m_pLastDamageEntity` | `0x1E4` |
| `m_nLastDamageWeapon` | `0x1EC` |
| `m_fHealth` | `0x1F0` |
| `m_nPhysicalFlags` | `0x118` |
| `m_pAttachedToEntity` | `0x1BC` |
| `m_vAttachOffset` | `0x1C0` |
| `m_qAttachOffset` | `0x1D0` |
| `m_pEntityIgnoredCollision` | `0x1F8` |
| `m_fPercentSubmerged` | `0x120` |
| `m_nSubmergedState` | `0x144` |

## Pendiente

- Revisar CDynamicEntity para atribuir los cambios de slots entre niveles de la jerarquía.
- Identificar slots desconocidos, constructor y destructor con evidencia estática.
- Confirmar límites de tabla, layout y ABI antes de declarar la clase en source/game.
- Fichar CPed y CVehicle y comparar sus destinos con CPhysical.

## Evidencia

- EXE: SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- [Ficha estructurada](CPhysical.json): etiquetas originales, comparación por slot, fuentes y hashes de los headers.
- [Inventario RTTI](../classes.csv), [tablas](../vtables.csv) y [slots originales](../virtual_slots.csv).
- [CPhysical del SDK](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h) y [CDynamicEntity](../../../contrib/IV%20SDK/IV-SDK-main/include/CDynamicEntity.h).

Esta ficha registra direcciones y referencias. No añade reconstrucciones, hooks ni validaciones de comportamiento.
