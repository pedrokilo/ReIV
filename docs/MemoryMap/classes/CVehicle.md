# CVehicle — ficha de direcciones

GTA IV **1.0.7.0**, x86. Base preferida `0x00400000`; VA en ejecución = base real + RVA.

## Identidad y jerarquía

| Elemento | VA estática | RVA |
| --- | --- | --- |
| TypeDescriptor `.?AVCVehicle@@` | `0x00F22240` | `0x00B22240` |
| CompleteObjectLocator | `0x00EC59F4` | `0x00AC59F4` |
| Tabla virtual | `0x00D82164` | `0x00982164` |

RTTI registra `CPhysical`, `CDynamicEntity`, `CEntity` y `CVirtualBase`; el locator tiene desplazamiento de subobjeto `0`. IV-SDK declara `CVehicle : CPhysical`. Las bases RTTI pueden incluir tipos transitivos.

## Comparación con CPhysical

Entre los 72 slots inventariados de [CPhysical](CPhysical.md), **60 conservan el mismo destino** y **12 tienen otro destino**. Otros **39 slots** quedan fuera del inventario de CPhysical.

Se comparan índices y punteros del EXE. Un cambio de destino puede corresponder a una implementación diferente o un thunk; no determina por sí solo el propietario del cuerpo. Los límites de las tablas son estimados por continuidad de punteros a código.

## Métodos virtuales

Los 111 punteros siguientes se contrastaron directamente con el EXE y apuntan a bytes de secciones ejecutables. IV-SDK documenta `Fix` en el slot 101. Los otros seis nombres proceden de wrappers de clases base y necesitan confirmar su correspondencia en CVehicle. Todos los nombres, firmas y comportamientos quedan pendientes de validación semántica.

| Slot | VA del destino | RVA | Nombre propuesto | Frente a CPhysical | Evidencia del nombre |
| ---: | --- | --- | --- | --- | --- |
| 0 | `0x009d5ed0` | `0x005d5ed0` | Desconocido | Destino diferente | Sin identificar |
| 1 | `0x00a48eb0` | `0x00648eb0` | `Teleport(CMatrix*, bool, bool)` | Mismo destino | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L41) |
| 2 | `0x00a48e40` | `0x00648e40` | `Teleport(CVector*, bool, bool)` | Mismo destino | [SDK, línea 46](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L46) |
| 3 | `0x00a47a40` | `0x00647a40` | Desconocido | Mismo destino | Sin identificar |
| 4 | `0x009e1960` | `0x005e1960` | Desconocido | Mismo destino | Sin identificar |
| 5 | `0x009e9e10` | `0x005e9e10` | Desconocido | Mismo destino | Sin identificar |
| 6 | `0x009e1ed0` | `0x005e1ed0` | Desconocido | Mismo destino | Sin identificar |
| 7 | `0x009e0410` | `0x005e0410` | Desconocido | Mismo destino | Sin identificar |
| 8 | `0x009e0440` | `0x005e0440` | Desconocido | Mismo destino | Sin identificar |
| 9 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 10 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 11 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 12 | `0x0089bbf0` | `0x0049bbf0` | Desconocido | Mismo destino | Sin identificar |
| 13 | `0x008b86d0` | `0x004b86d0` | Desconocido | Destino diferente | Sin identificar |
| 14 | `0x009d45e0` | `0x005d45e0` | Desconocido | Destino diferente | Sin identificar |
| 15 | `0x009e69e0` | `0x005e69e0` | Desconocido | Mismo destino | Sin identificar |
| 16 | `0x009e7cf0` | `0x005e7cf0` | Desconocido | Mismo destino | Sin identificar |
| 17 | `0x009e22a0` | `0x005e22a0` | Desconocido | Mismo destino | Sin identificar |
| 18 | `0x009e18a0` | `0x005e18a0` | Desconocido | Mismo destino | Sin identificar |
| 19 | `0x009e6a40` | `0x005e6a40` | Desconocido | Mismo destino | Sin identificar |
| 20 | `0x009e05c0` | `0x005e05c0` | Desconocido | Mismo destino | Sin identificar |
| 21 | `0x009e04d0` | `0x005e04d0` | Desconocido | Mismo destino | Sin identificar |
| 22 | `0x009e0490` | `0x005e0490` | Desconocido | Mismo destino | Sin identificar |
| 23 | `0x009e0610` | `0x005e0610` | Desconocido | Mismo destino | Sin identificar |
| 24 | `0x009e0660` | `0x005e0660` | Desconocido | Mismo destino | Sin identificar |
| 25 | `0x009e0690` | `0x005e0690` | Desconocido | Mismo destino | Sin identificar |
| 26 | `0x009e06c0` | `0x005e06c0` | Desconocido | Mismo destino | Sin identificar |
| 27 | `0x009e0bd0` | `0x005e0bd0` | Desconocido | Mismo destino | Sin identificar |
| 28 | `0x00cfaee0` | `0x008faee0` | Desconocido | Destino diferente | Sin identificar |
| 29 | `0x00cfaee0` | `0x008faee0` | Desconocido | Mismo destino | Sin identificar |
| 30 | `0x00447970` | `0x00047970` | Desconocido | Mismo destino | Sin identificar |
| 31 | `0x009d6170` | `0x005d6170` | Desconocido | Destino diferente | Sin identificar |
| 32 | `0x00c28820` | `0x00828820` | Desconocido | Mismo destino | Sin identificar |
| 33 | `0x009c80d0` | `0x005c80d0` | Desconocido | Destino diferente | Sin identificar |
| 34 | `0x009e1b70` | `0x005e1b70` | Desconocido | Mismo destino | Sin identificar |
| 35 | `0x009c83a0` | `0x005c83a0` | `PreRender(int, int, char, int)` | Destino diferente | [SDK, línea 51](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L51) |
| 36 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 37 | `0x00550ff0` | `0x00150ff0` | Desconocido | Mismo destino | Sin identificar |
| 38 | `0x009c91a0` | `0x005c91a0` | Desconocido | Destino diferente | Sin identificar |
| 39 | `0x008b8fe0` | `0x004b8fe0` | Desconocido | Mismo destino | Sin identificar |
| 40 | `0x008b86c0` | `0x004b86c0` | Desconocido | Destino diferente | Sin identificar |
| 41 | `0x007bdc00` | `0x003bdc00` | Desconocido | Mismo destino | Sin identificar |
| 42 | `0x009d5f00` | `0x005d5f00` | Desconocido | Destino diferente | Sin identificar |
| 43 | `0x00a48630` | `0x00648630` | Desconocido | Mismo destino | Sin identificar |
| 44 | `0x00a486e0` | `0x006486e0` | Desconocido | Mismo destino | Sin identificar |
| 45 | `0x00a48770` | `0x00648770` | Desconocido | Mismo destino | Sin identificar |
| 46 | `0x009c93b0` | `0x005c93b0` | Desconocido | Destino diferente | Sin identificar |
| 47 | `0x009c80b0` | `0x005c80b0` | Desconocido | Mismo destino | Sin identificar |
| 48 | `0x009c80c0` | `0x005c80c0` | Desconocido | Mismo destino | Sin identificar |
| 49 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 50 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 51 | `0x009e15b0` | `0x005e15b0` | Desconocido | Mismo destino | Sin identificar |
| 52 | `0x007bdc00` | `0x003bdc00` | Desconocido | Mismo destino | Sin identificar |
| 53 | `0x007bdc00` | `0x003bdc00` | Desconocido | Mismo destino | Sin identificar |
| 54 | `0x009dfe70` | `0x005dfe70` | Desconocido | Mismo destino | Sin identificar |
| 55 | `0x00a476b0` | `0x006476b0` | Desconocido | Mismo destino | Sin identificar |
| 56 | `0x008b86f0` | `0x004b86f0` | Desconocido | Destino diferente | Sin identificar |
| 57 | `0x00a48a40` | `0x00648a40` | Desconocido | Mismo destino | Sin identificar |
| 58 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Mismo destino | Sin identificar |
| 59 | `0x00a477f0` | `0x006477f0` | `GetVelocity(CVector*)` | Mismo destino | [SDK, línea 44](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L44) |
| 60 | `0x00a47930` | `0x00647930` | Desconocido | Mismo destino | Sin identificar |
| 61 | `0x00a47950` | `0x00647950` | Desconocido | Mismo destino | Sin identificar |
| 62 | `0x00a47970` | `0x00647970` | Desconocido | Mismo destino | Sin identificar |
| 63 | `0x00447b30` | `0x00047b30` | `GetHealth()` | Mismo destino | [SDK, línea 61](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L61) |
| 64 | `0x00a49650` | `0x00649650` | Desconocido | Mismo destino | Sin identificar |
| 65 | `0x00948fd0` | `0x00548fd0` | Desconocido | Mismo destino | Sin identificar |
| 66 | `0x00447b40` | `0x00047b40` | Desconocido | Mismo destino | Sin identificar |
| 67 | `0x00447b50` | `0x00047b50` | Desconocido | Mismo destino | Sin identificar |
| 68 | `0x00a48550` | `0x00648550` | Desconocido | Mismo destino | Sin identificar |
| 69 | `0x00a4a320` | `0x0064a320` | Desconocido | Mismo destino | Sin identificar |
| 70 | `0x00a4a890` | `0x0064a890` | Desconocido | Mismo destino | Sin identificar |
| 71 | `0x00a4af20` | `0x0064af20` | `ProcessWater()` | Mismo destino | [SDK, línea 56](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L56) |
| 72 | `0x009c8a70` | `0x005c8a70` | Desconocido | Fuera del inventario base | Sin identificar |
| 73 | `0x009c52c0` | `0x005c52c0` | Desconocido | Fuera del inventario base | Sin identificar |
| 74 | `0x009c5360` | `0x005c5360` | Desconocido | Fuera del inventario base | Sin identificar |
| 75 | `0x009c8d80` | `0x005c8d80` | Desconocido | Fuera del inventario base | Sin identificar |
| 76 | `0x009c5370` | `0x005c5370` | Desconocido | Fuera del inventario base | Sin identificar |
| 77 | `0x009c8dc0` | `0x005c8dc0` | Desconocido | Fuera del inventario base | Sin identificar |
| 78 | `0x009c53c0` | `0x005c53c0` | Desconocido | Fuera del inventario base | Sin identificar |
| 79 | `0x009c8f30` | `0x005c8f30` | Desconocido | Fuera del inventario base | Sin identificar |
| 80 | `0x009d4a50` | `0x005d4a50` | Desconocido | Fuera del inventario base | Sin identificar |
| 81 | `0x009c5430` | `0x005c5430` | Desconocido | Fuera del inventario base | Sin identificar |
| 82 | `0x009c9020` | `0x005c9020` | Desconocido | Fuera del inventario base | Sin identificar |
| 83 | `0x009c9210` | `0x005c9210` | Desconocido | Fuera del inventario base | Sin identificar |
| 84 | `0x009c9450` | `0x005c9450` | Desconocido | Fuera del inventario base | Sin identificar |
| 85 | `0x00949b70` | `0x00549b70` | Desconocido | Fuera del inventario base | Sin identificar |
| 86 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 87 | `0x00c28820` | `0x00828820` | Desconocido | Fuera del inventario base | Sin identificar |
| 88 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 89 | `0x004d7030` | `0x000d7030` | Desconocido | Fuera del inventario base | Sin identificar |
| 90 | `0x00c28820` | `0x00828820` | Desconocido | Fuera del inventario base | Sin identificar |
| 91 | `0x009d25d0` | `0x005d25d0` | Desconocido | Fuera del inventario base | Sin identificar |
| 92 | `0x004d7030` | `0x000d7030` | Desconocido | Fuera del inventario base | Sin identificar |
| 93 | `0x004d7030` | `0x000d7030` | Desconocido | Fuera del inventario base | Sin identificar |
| 94 | `0x004d7030` | `0x000d7030` | Desconocido | Fuera del inventario base | Sin identificar |
| 95 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 96 | `0x00c4c720` | `0x0084c720` | Desconocido | Fuera del inventario base | Sin identificar |
| 97 | `0x00c71460` | `0x00871460` | Desconocido | Fuera del inventario base | Sin identificar |
| 98 | `0x009cc990` | `0x005cc990` | Desconocido | Fuera del inventario base | Sin identificar |
| 99 | `0x007bdc00` | `0x003bdc00` | Desconocido | Fuera del inventario base | Sin identificar |
| 100 | `0x00c28820` | `0x00828820` | Desconocido | Fuera del inventario base | Sin identificar |
| 101 | `0x009d5fc0` | `0x005d5fc0` | `Fix()` | Fuera del inventario base | [SDK, línea 568](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L568) |
| 102 | `0x00c28820` | `0x00828820` | Desconocido | Fuera del inventario base | Sin identificar |
| 103 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 104 | `0x00c28820` | `0x00828820` | Desconocido | Fuera del inventario base | Sin identificar |
| 105 | `0x00948fe0` | `0x00548fe0` | Desconocido | Fuera del inventario base | Sin identificar |
| 106 | `0x00aaaf20` | `0x006aaf20` | Desconocido | Fuera del inventario base | Sin identificar |
| 107 | `0x009c7380` | `0x005c7380` | Desconocido | Fuera del inventario base | Sin identificar |
| 108 | `0x009ca710` | `0x005ca710` | Desconocido | Fuera del inventario base | Sin identificar |
| 109 | `0x009ca8e0` | `0x005ca8e0` | Desconocido | Fuera del inventario base | Sin identificar |
| 110 | `0x004ee420` | `0x000ee420` | Desconocido | Fuera del inventario base | Sin identificar |

## Referencias de funciones del SDK

El primer argumento de AddressSetter corresponde a 1.0.7.0. Se comprobó que las ubicaciones contienen bytes de código; un wrapper de dirección fija no demuestra que el método sea no virtual. Nombres y ABI pendientes de corroborar.

| Referencia | VA estática | RVA | Fuente |
| --- | --- | --- | --- |
| `CVehicle::SetRemap` | `0x009c7580` | `0x005c7580` | [SDK, línea 575](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L575) |
| `CVehicle::GetRemapIndex` | `0x009c7560` | `0x005c7560` | [SDK, línea 579](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L579) |
| `CVehicle::MakeDirty` | `0x009d3e90` | `0x005d3e90` | [SDK, línea 583](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L583) |
| `CVehicle::GetVehicleLightsStatus` | `0x009c63d0` | `0x005c63d0` | [SDK, línea 587](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L587) |
| `CVehicle::GetSeatPartId` | `0x009c6ef0` | `0x005c6ef0` | [SDK, línea 592](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L592) |
| `CVehicle::GetCameraType` | `0x009d68f0` | `0x005d68f0` | [SDK, línea 597](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L597) |
| `CVehicle::ProcessRespot` | `0x009d3a10` | `0x005d3a10` | [SDK, línea 601](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L601) |
| `CVehicle::ProcessAirControl` | `0x00bfd450` | `0x007fd450` | [SDK, línea 605](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L605) |
| `CVehicle::IsDriver` | `0x009c5d60` | `0x005c5d60` | [SDK, línea 609](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L609) |
| `CVehicle::HeightAboveCeiling` | `0x009c6100` | `0x005c6100` | [SDK, línea 614](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L614) |
| `CVehicle::UsesSiren` | `0x009c5f50` | `0x005c5f50` | [SDK, línea 618](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h#L618) |

## Tamaño y campos de referencia

IV-SDK declara tamaño `0x20D0` (8.400 bytes). Los offsets siguientes proceden de las macros VALIDATE_OFFSET de CVehicle y no se presentan como layout verificado en este EXE. Los campos de clases y estructuras auxiliares del mismo header quedan fuera de esta ficha.

| Campo | Offset dentro de CVehicle | Línea del SDK |
| --- | --- | ---: |
| `m_fEngineRPM` | `0x688` | 622 |
| `m_nDoorLock` | `0x1320` | 623 |
| `m_nVehicleType` | `0x1354` | 624 |
| `m_fLightMult` | `0x1330` | 625 |
| `m_nHornCounter` | `0x133C` | 626 |
| `m_nVehicleFlags` | `0xF64` | 627 |
| `m_nVehicleFlags2` | `0xF68` | 628 |
| `m_nVehicleFlags3` | `0xF6C` | 629 |
| `m_nVehicleFlags4` | `0xF70` | 630 |
| `m_nCreatedBy` | `0x1108` | 631 |
| `m_pVehicleFragInst` | `0xE14` | 632 |
| `m_nRespotTimer` | `0x1114` | 633 |
| `m_fDirtLevel` | `0x1118` | 634 |
| `m_fDeformationMult` | `0x132C` | 635 |
| `m_pDriver` | `0xFA0` | 636 |
| `m_nPrimaryColor` | `0xFE4` | 637 |
| `m_nMaxPassengers` | `0x10C0` | 638 |
| `m_fGasPedal` | `0x10C8` | 639 |
| `m_nCurrentGear` | `0x10E0` | 640 |
| `m_fEngineHealth` | `0x10FC` | 641 |
| `m_fPetrolTankHealth` | `0x1128` | 642 |
| `m_pHandling` | `0xE18` | 643 |
| `m_pDoors` | `0xFD8` | 644 |
| `m_fEngineRevs` | `0x10E4` | 645 |
| `m_nLights` | `0x11E0` | 646 |
| `m_nSirens` | `0x11F0` | 647 |
| `m_fPlaneTurn` | `0x1F00` | 648 |
| `m_fPlaneUpDown` | `0x1F04` | 649 |
| `m_fPlaneRotate` | `0x1F08` | 650 |
| `m_fPlaneThrust` | `0x1F0C` | 651 |
| `m_fPlanePropSpeed` | `0x1F3C` | 652 |
| `m_nAbsFlags` | `0xFE0` | 653 |

## Pendiente

- Identificar slots desconocidos y confirmar los límites de tabla.
- Localizar constructor y destructor mediante referencias estáticas.
- Corroborar layout, firmas y ABI antes de declarar la clase en source/game.
- Comparar CPed y CVehicle como clases derivadas de CPhysical, sin asumir que sus slots adicionales tengan el mismo significado.

## Evidencia

- EXE: SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- [Ficha estructurada](CVehicle.json): etiquetas originales, destinos de la base por slot, referencias, offsets y hashes de headers.
- [Inventario RTTI](../classes.csv), [tablas](../vtables.csv) y [slots originales](../virtual_slots.csv).
- [CVehicle del SDK](../../../contrib/IV%20SDK/IV-SDK-main/include/CVehicle.h).

Esta ficha registra direcciones y referencias. No añade reconstrucciones, hooks ni validaciones de comportamiento.
