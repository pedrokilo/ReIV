# CPed — ficha de direcciones

GTA IV **1.0.7.0**, x86. Base preferida `0x00400000`; VA en ejecución = base real + RVA.

## Identidad y jerarquía

| Elemento | VA estática | RVA |
| --- | --- | --- |
| TypeDescriptor `.?AVCPed@@` | `0x0108F53C` | `0x00C8F53C` |
| CompleteObjectLocator | `0x00EC17A0` | `0x00AC17A0` |
| Tabla virtual | `0x00D69844` | `0x00969844` |

RTTI registra `CPhysical`, `CDynamicEntity`, `CEntity` y `CVirtualBase`; el locator tiene desplazamiento de subobjeto `0`. IV-SDK declara `CPed : CPhysical`. Las bases RTTI pueden incluir tipos transitivos.

## Comparación con CPhysical

Entre los 72 slots inventariados de [CPhysical](CPhysical.md), **33 conservan el mismo destino** y **39 tienen otro destino**. Otros **9 slots** quedan fuera del inventario de CPhysical.

Se comparan índices y punteros del EXE. Un cambio de destino puede corresponder a una implementación diferente o un thunk; no determina por sí solo el propietario del cuerpo. Los límites de las tablas son estimados por continuidad de punteros a código.

## Métodos virtuales

Los 81 punteros siguientes se contrastaron directamente con el EXE y apuntan a bytes de secciones ejecutables. IV-SDK documenta `SetHealth` en el slot 61 y `AddHealth` en el 62. Los otros seis nombres proceden de wrappers de clases base y necesitan confirmar su correspondencia en CPed. Todos los nombres, firmas y comportamientos quedan pendientes de validación semántica.

| Slot | VA del destino | RVA | Nombre propuesto | Frente a CPhysical | Evidencia del nombre |
| ---: | --- | --- | --- | --- | --- |
| 0 | `0x008acac0` | `0x004acac0` | Desconocido | Destino diferente | Sin identificar |
| 1 | `0x00a48eb0` | `0x00648eb0` | `Teleport(CMatrix*, bool, bool)` | Mismo destino | [SDK, línea 41](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L41) |
| 2 | `0x00a48e40` | `0x00648e40` | `Teleport(CVector*, bool, bool)` | Mismo destino | [SDK, línea 46](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L46) |
| 3 | `0x0089ed00` | `0x0049ed00` | Desconocido | Destino diferente | Sin identificar |
| 4 | `0x009e1960` | `0x005e1960` | Desconocido | Mismo destino | Sin identificar |
| 5 | `0x009e9e10` | `0x005e9e10` | Desconocido | Mismo destino | Sin identificar |
| 6 | `0x009e1ed0` | `0x005e1ed0` | Desconocido | Mismo destino | Sin identificar |
| 7 | `0x009e0410` | `0x005e0410` | Desconocido | Mismo destino | Sin identificar |
| 8 | `0x009e0440` | `0x005e0440` | Desconocido | Mismo destino | Sin identificar |
| 9 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 10 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 11 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 12 | `0x0089e4b0` | `0x0049e4b0` | Desconocido | Destino diferente | Sin identificar |
| 13 | `0x00447ba0` | `0x00047ba0` | Desconocido | Destino diferente | Sin identificar |
| 14 | `0x008ac500` | `0x004ac500` | Desconocido | Destino diferente | Sin identificar |
| 15 | `0x009e69e0` | `0x005e69e0` | Desconocido | Mismo destino | Sin identificar |
| 16 | `0x0089c520` | `0x0049c520` | Desconocido | Destino diferente | Sin identificar |
| 17 | `0x0089c5a0` | `0x0049c5a0` | Desconocido | Destino diferente | Sin identificar |
| 18 | `0x009e18a0` | `0x005e18a0` | Desconocido | Mismo destino | Sin identificar |
| 19 | `0x0089c560` | `0x0049c560` | Desconocido | Destino diferente | Sin identificar |
| 20 | `0x009e05c0` | `0x005e05c0` | Desconocido | Mismo destino | Sin identificar |
| 21 | `0x009e04d0` | `0x005e04d0` | Desconocido | Mismo destino | Sin identificar |
| 22 | `0x009e0490` | `0x005e0490` | Desconocido | Mismo destino | Sin identificar |
| 23 | `0x009e0610` | `0x005e0610` | Desconocido | Mismo destino | Sin identificar |
| 24 | `0x009e0660` | `0x005e0660` | Desconocido | Mismo destino | Sin identificar |
| 25 | `0x009e0690` | `0x005e0690` | Desconocido | Mismo destino | Sin identificar |
| 26 | `0x009e06c0` | `0x005e06c0` | Desconocido | Mismo destino | Sin identificar |
| 27 | `0x009e0bd0` | `0x005e0bd0` | Desconocido | Mismo destino | Sin identificar |
| 28 | `0x00707920` | `0x00307920` | Desconocido | Destino diferente | Sin identificar |
| 29 | `0x008aadc0` | `0x004aadc0` | Desconocido | Destino diferente | Sin identificar |
| 30 | `0x00447970` | `0x00047970` | Desconocido | Mismo destino | Sin identificar |
| 31 | `0x008a8cc0` | `0x004a8cc0` | Desconocido | Destino diferente | Sin identificar |
| 32 | `0x0089d360` | `0x0049d360` | Desconocido | Destino diferente | Sin identificar |
| 33 | `0x008a3850` | `0x004a3850` | Desconocido | Destino diferente | Sin identificar |
| 34 | `0x009e1b70` | `0x005e1b70` | Desconocido | Mismo destino | Sin identificar |
| 35 | `0x008a3b30` | `0x004a3b30` | `PreRender(int, int, char, int)` | Destino diferente | [SDK, línea 51](../../../contrib/IV%20SDK/IV-SDK-main/include/CEntity.h#L51) |
| 36 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Mismo destino | Sin identificar |
| 37 | `0x00550ff0` | `0x00150ff0` | Desconocido | Mismo destino | Sin identificar |
| 38 | `0x008a3ec0` | `0x004a3ec0` | Desconocido | Destino diferente | Sin identificar |
| 39 | `0x008a5060` | `0x004a5060` | Desconocido | Destino diferente | Sin identificar |
| 40 | `0x00447c10` | `0x00047c10` | Desconocido | Destino diferente | Sin identificar |
| 41 | `0x00447c00` | `0x00047c00` | Desconocido | Destino diferente | Sin identificar |
| 42 | `0x008a6780` | `0x004a6780` | Desconocido | Destino diferente | Sin identificar |
| 43 | `0x0089c100` | `0x0049c100` | Desconocido | Destino diferente | Sin identificar |
| 44 | `0x008aac30` | `0x004aac30` | Desconocido | Destino diferente | Sin identificar |
| 45 | `0x0089f050` | `0x0049f050` | Desconocido | Destino diferente | Sin identificar |
| 46 | `0x0089c200` | `0x0049c200` | Desconocido | Destino diferente | Sin identificar |
| 47 | `0x00447bb0` | `0x00047bb0` | Desconocido | Destino diferente | Sin identificar |
| 48 | `0x0074beb0` | `0x0034beb0` | Desconocido | Destino diferente | Sin identificar |
| 49 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 50 | `0x00549100` | `0x00149100` | Desconocido | Mismo destino | Sin identificar |
| 51 | `0x008a8340` | `0x004a8340` | Desconocido | Destino diferente | Sin identificar |
| 52 | `0x00447b90` | `0x00047b90` | Desconocido | Destino diferente | Sin identificar |
| 53 | `0x00447b90` | `0x00047b90` | Desconocido | Destino diferente | Sin identificar |
| 54 | `0x008a3250` | `0x004a3250` | Desconocido | Destino diferente | Sin identificar |
| 55 | `0x008ac520` | `0x004ac520` | Desconocido | Destino diferente | Sin identificar |
| 56 | `0x00447b20` | `0x00047b20` | Desconocido | Mismo destino | Sin identificar |
| 57 | `0x0089efe0` | `0x0049efe0` | Desconocido | Destino diferente | Sin identificar |
| 58 | `0x008a15e0` | `0x004a15e0` | Desconocido | Destino diferente | Sin identificar |
| 59 | `0x00a477f0` | `0x006477f0` | `GetVelocity(CVector*)` | Mismo destino | [SDK, línea 44](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L44) |
| 60 | `0x008ac150` | `0x004ac150` | Desconocido | Destino diferente | Sin identificar |
| 61 | `0x008ac180` | `0x004ac180` | `SetHealth(float, int)` | Destino diferente | [SDK, línea 174](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L174) |
| 62 | `0x008ac1b0` | `0x004ac1b0` | `AddHealth(float)` | Destino diferente | [SDK, línea 178](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L178) |
| 63 | `0x00447b30` | `0x00047b30` | `GetHealth()` | Mismo destino | [SDK, línea 61](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L61) |
| 64 | `0x00a49650` | `0x00649650` | Desconocido | Mismo destino | Sin identificar |
| 65 | `0x008a7d70` | `0x004a7d70` | Desconocido | Destino diferente | Sin identificar |
| 66 | `0x00447b40` | `0x00047b40` | Desconocido | Mismo destino | Sin identificar |
| 67 | `0x00447b50` | `0x00047b50` | Desconocido | Mismo destino | Sin identificar |
| 68 | `0x00a48550` | `0x00648550` | Desconocido | Mismo destino | Sin identificar |
| 69 | `0x008a9070` | `0x004a9070` | Desconocido | Destino diferente | Sin identificar |
| 70 | `0x008ac540` | `0x004ac540` | Desconocido | Destino diferente | Sin identificar |
| 71 | `0x0089dce0` | `0x0049dce0` | `ProcessWater()` | Destino diferente | [SDK, línea 56](../../../contrib/IV%20SDK/IV-SDK-main/include/CPhysical.h#L56) |
| 72 | `0x009be780` | `0x005be780` | Desconocido | Fuera del inventario base | Sin identificar |
| 73 | `0x008a3990` | `0x004a3990` | Desconocido | Fuera del inventario base | Sin identificar |
| 74 | `0x005fdcd0` | `0x001fdcd0` | Desconocido | Fuera del inventario base | Sin identificar |
| 75 | `0x00447c20` | `0x00047c20` | Desconocido | Fuera del inventario base | Sin identificar |
| 76 | `0x00447c30` | `0x00047c30` | Desconocido | Fuera del inventario base | Sin identificar |
| 77 | `0x00447c40` | `0x00047c40` | Desconocido | Fuera del inventario base | Sin identificar |
| 78 | `0x00550ff0` | `0x00150ff0` | Desconocido | Fuera del inventario base | Sin identificar |
| 79 | `0x00550ff0` | `0x00150ff0` | Desconocido | Fuera del inventario base | Sin identificar |
| 80 | `0x00550ff0` | `0x00150ff0` | Desconocido | Fuera del inventario base | Sin identificar |

## Referencias de funciones del SDK

El primer argumento de AddressSetter corresponde a 1.0.7.0. Se comprobó que las ubicaciones contienen bytes de código; un wrapper de dirección fija no demuestra que el método sea no virtual. Nombres y ABI pendientes de corroborar.

| Referencia | VA estática | RVA | Fuente |
| --- | --- | --- | --- |
| `CPed::ProcessWeaponSwitch` | `0x009be7d0` | `0x005be7d0` | [SDK, línea 164](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L164) |
| `CPed::GetPadFromPlayer` | `0x009be5d0` | `0x005be5d0` | [SDK, línea 168](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L168) |
| `CPed::GetVehicle` | `0x00426ab0` | `0x00026ab0` | [SDK, línea 172](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L172) |
| `CPed::ProcessHeading` | `0x008a28b0` | `0x004a28b0` | [SDK, línea 184](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h#L184) |

## Tamaño y campos de referencia

IV-SDK declara tamaño `0xF00` (3.840 bytes). Los offsets siguientes proceden de las macros VALIDATE_OFFSET de CPed y no se presentan como layout verificado en este EXE. Los campos de clases y estructuras auxiliares del mismo header quedan fuera de esta ficha.

| Campo | Offset dentro de CPed | Línea del SDK |
| --- | --- | ---: |
| `m_pCollider` | `0x7BC` | 189 |
| `m_fClimbAnimRate` | `0x278` | 190 |
| `m_nDeathState` | `0xA84` | 191 |
| `m_nCreatedBy` | `0xA70` | 192 |
| `m_nPlayerIndex` | `0x218` | 193 |
| `m_nRagdollStatus` | `0x7C8` | 194 |
| `m_nWeaponObjectVisible` | `0x7F1` | 195 |
| `m_fMaxHealth` | `0xA94` | 196 |
| `m_fCurrentHeading` | `0xAB0` | 197 |
| `m_fDesiredHeading` | `0xAB4` | 198 |
| `m_pVehicle` | `0xB40` | 199 |
| `m_pDrawableInfo` | `0x21C` | 200 |
| `m_nShootRate` | `0x388` | 201 |
| `m_nAccuracy` | `0x389` | 202 |
| `m_pPedMoveBlendOnFoot` | `0xA90` | 203 |
| `m_pComponentModels` | `0xEA8` | 204 |
| `m_nVoiceHash` | `0x61C` | 205 |
| `m_pStandingOnEntity` | `0x484` | 206 |
| `m_pWeaponData` | `0x2B0` | 207 |
| `m_nUnkPlayerSettingsRelated` | `0xE80` | 208 |

## Pendiente

- Identificar slots desconocidos y confirmar los límites de tabla.
- Localizar constructor y destructor mediante referencias estáticas.
- Corroborar layout, firmas y ABI antes de declarar la clase en source/game.
- Fichar CVehicle para comparar ambas clases derivadas de CPhysical.

## Evidencia

- EXE: SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.
- [Ficha estructurada](CPed.json): etiquetas originales, destinos de la base por slot, referencias, offsets y hashes de headers.
- [Inventario RTTI](../classes.csv), [tablas](../vtables.csv) y [slots originales](../virtual_slots.csv).
- [CPed del SDK](../../../contrib/IV%20SDK/IV-SDK-main/include/CPed.h).

Esta ficha registra direcciones y referencias. No añade reconstrucciones, hooks ni validaciones de comportamiento.
