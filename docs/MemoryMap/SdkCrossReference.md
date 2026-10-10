# Cruce de SDKs: IV-SDK, plugin_IV e IV-SDK.Net

Generado por `contrib/crossref-sdks.py`. Compara los `VALIDATE_OFFSET` de CEntity, CDynamicEntity, CPhysical y CPed. Una coincidencia entre SDKs es una pista; **el ejecutable decide**. `PlayerPedLayout.h` aporta los offsets observados en cuerpos del EXE.

## Cobertura

| SDK | Offsets nombrados (4 clases) |
| --- | ---: |
| IV-SDK | 35 |
| plugin_IV | 125 |
| IV-SDK.Net | 15 |

## Offsets que solo nombra plugin_IV

Candidatos para nombrar campos aún sin etiqueta. Si el offset aparece en el layout observado se marca.

| Clase | Offset | Nombre plugin_IV | En layout observado |
| --- | ---: | --- | --- |
| CDynamicEntity | 0x70 | `pad6` |  |
| CDynamicEntity | 0x7C | `pad7` |  |
| CEntity | 0x4 | `m_nCurrentWeaponSlot` |  |
| CEntity | 0x8 | `field_1` |  |
| CEntity | 0x10 | `m_Transform` |  |
| CEntity | 0x2C | `field_2C` |  |
| CEntity | 0x2E | `m_nModelIndex` |  |
| CEntity | 0x30 | `m_pReference` |  |
| CEntity | 0x34 | `field_34` |  |
| CEntity | 0x3C | `field_3C` |  |
| CEntity | 0x40 | `field_40` |  |
| CEntity | 0x41 | `field_41` |  |
| CEntity | 0x42 | `field_42` |  |
| CEntity | 0x44 | `field_44` |  |
| CEntity | 0x46 | `field_46` |  |
| CEntity | 0x48 | `m_hInterior` |  |
| CEntity | 0x4C | `field_4C` |  |
| CEntity | 0x54 | `field_54` |  |
| CEntity | 0x58 | `field_58` |  |
| CEntity | 0x5C | `field_5C` |  |
| CEntity | 0x5E | `field_5E` |  |
| CEntity | 0x60 | `field_60` |  |
| CEntity | 0x61 | `field_61` |  |
| CEntity | 0x62 | `field_62` |  |
| CEntity | 0x63 | `m_nAlpha` | `alpha_63` |
| CEntity | 0x64 | `field_64` |  |
| CEntity | 0x68 | `field_68` | `field_68` |
| CEntity | 0x6C | `field_6C` | `network_object_address` |
| CPed | 0x210 | `m_bDead` | `dead_flag_210` |
| CPed | 0x211 | `m_bInjured` | `injured_flag_211` |
| CPed | 0x212 | `m_bFatallyInjured` | `fatal_injury_flag_212` |
| CPed | 0x213 | `field_4` |  |
| CPed | 0x214 | `m_fHealth` | `health_bits_214` |
| CPed | 0x219 | `m_bIsPlayer` | `is_player_219` |
| CPed | 0x21A | `field_10` |  |
| CPed | 0x220 | `field_16` |  |
| CPed | 0x224 | `m_pPedIntelligence` | `intelligence_address` |
| CPed | 0x228 | `m_pPlayerInfo` | `player_info_address` |
| CPed | 0x22C | `field_18` |  |
| CPed | 0x275 | `field_77` |  |
| CPed | 0x27C | `field_32` |  |
| CPed | 0x2A0 | `field_38` |  |
| CPed | 0x2A4 | `field_42` |  |
| CPed | 0x2A8 | `field_46` |  |
| CPed | 0x2AC | `field_50` |  |
| CPed | 0x3B0 | `field_56` |  |
| CPed | 0x3E7 | `field_156` |  |
| CPed | 0x488 | `field_204` |  |
| CPed | 0x620 | `field_208` |  |
| CPed | 0x770 | `m_bIsDrunk` |  |
| CPed | 0x771 | `field_210` |  |
| CPed | 0x7B8 | `m_nRagdollState` |  |
| CPed | 0x7C0 | `field_216` |  |
| CPed | 0x7D0 | `field_233` |  |
| CPed | 0x7F2 | `field_332` |  |
| CPed | 0xA60 | `m_nPedType` |  |
| CPed | 0xA64 | `field_338` |  |
| CPed | 0xA6E | `m_bHasBeenArrested` |  |
| CPed | 0xA74 | `m_nDeathState` |  |
| CPed | 0xA78 | `m_nLastDamageBone` |  |
| CPed | 0xA7C | `field_360` |  |
| CPed | 0xA88 | `field_370` |  |
| CPed | 0xAA0 | `m_fCurrentHeading` |  |
| CPed | 0xAA4 | `m_fDesiredHeading` |  |
| CPed | 0xAA8 | `field_388` |  |
| CPed | 0xAB6 | `field_394` |  |
| CPed | 0xB28 | `m_fMaxTimeInWater` |  |
| CPed | 0xB2C | `m_fMaxTimeUnderwater` |  |
| CPed | 0xB30 | `m_pVehicle` |  |
| CPed | 0xB34 | `field_402` |  |
| CPed | 0xB44 | `field_404` |  |
| CPed | 0xB84 | `m_fArmour` |  |
| CPed | 0xB88 | `m_nMoney` |  |
| CPed | 0xB8C | `field_414` |  |
| CPed | 0xBE0 | `m_nLegIK` |  |
| CPed | 0xBE4 | `field_422` |  |
| CPed | 0xD2C | `m_nCellphoneRingTime` |  |
| CPed | 0xD30 | `m_nCellphoneState` |  |
| CPed | 0xD31 | `field_450` |  |
| CPed | 0xD48 | `m_fHeadingLimitForAttachedPed` |  |
| CPed | 0xD4C | `m_fHeadingLimitForAttachedPed2` |  |
| CPed | 0xD50 | `field_788` |  |
| CPed | 0xE0C | `m_fWindyClothingScale` |  |
| CPed | 0xE10 | `field_800` |  |
| CPed | 0xE84 | `field_819` |  |
| CPed | 0xE97 | `m_bIsCop` |  |
| CPed | 0xE98 | `field_832` |  |
| CPed | 0xEAC | `field_840` | `protected_handle_eac` |
| CPhysical | 0x110 | `m_nBodyPart` |  |
| CPhysical | 0x11C | `m_nRelationshipGroup` |  |
| CPhysical | 0x11E | `field_24` |  |
| CPhysical | 0x124 | `field_32` |  |
| CPhysical | 0x148 | `field_40` |  |
| CPhysical | 0x1CC | `field_116` |  |
| CPhysical | 0x1E0 | `field_124` |  |
| CPhysical | 0x1E8 | `field_132` |  |
| CPhysical | 0x1ED | `field_138` |  |
| CPhysical | 0x1F4 | `field_152` |  |
| CPhysical | 0x1FC | `field_158` |  |

## Offsets nombrados distinto entre SDKs

| Clase | Offset | IV-SDK | plugin_IV | IV-SDK.Net |
| --- | ---: | --- | --- | --- |
| CEntity | 0x38 | `m_pInstGta` | `m_pColModel` | `m_pInstGta` |
| CEntity | 0x50 | `m_fDrawDistance` | `field_50` | `m_fDrawDistance` |
| CPed | 0x2B0 | `m_pWeaponData` | `m_WeaponData` |  |
| CPed | 0x7BC | `m_pCollider` | `m_nRagdollTime` |  |
| CPed | 0xA70 | `m_nCreatedBy` | `field_350` |  |
| CPed | 0xA84 | `m_nDeathState` | `m_fMaxHealth` |  |
| CPed | 0xA94 | `m_fMaxHealth` | `field_378` |  |
| CPhysical | 0x1F0 | `m_fHealth` | `m_fLife` | `m_fHealth` |

## Layout observado de CPlayerPed con nombre en algún SDK

19 offsets de `PlayerPedLayout.h` tienen nombre en al menos un SDK.

| Offset | Layout observado | IV-SDK | plugin_IV | IV-SDK.Net |
| ---: | --- | --- | --- | --- |
| 0x20 | `matrix_address` | `CEntity::m_pMatrix` | `CEntity::m_pMatrix` | `CEntity::m_pMatrix` |
| 0x63 | `alpha_63` |  | `CEntity::m_nAlpha` |  |
| 0x68 | `field_68` |  | `CEntity::field_68` |  |
| 0x6C | `network_object_address` |  | `CEntity::field_6C` |  |
| 0x118 | `physical_flags_118` | `CPhysical::m_nPhysicalFlags` |  | `CPhysical::m_nPhysicalFlags` |
| 0x210 | `dead_flag_210` |  | `CPed::m_bDead` |  |
| 0x211 | `injured_flag_211` |  | `CPed::m_bInjured` |  |
| 0x212 | `fatal_injury_flag_212` |  | `CPed::m_bFatallyInjured` |  |
| 0x214 | `health_bits_214` |  | `CPed::m_fHealth` |  |
| 0x218 | `player_index_218` | `CPed::m_nPlayerIndex` | `CPed::m_nPlayerIndex` |  |
| 0x219 | `is_player_219` |  | `CPed::m_bIsPlayer` |  |
| 0x21C | `drawable_info_address` | `CPed::m_pDrawableInfo` | `CPed::m_pDrawableInfo` |  |
| 0x224 | `intelligence_address` |  | `CPed::m_pPedIntelligence` |  |
| 0x228 | `player_info_address` |  | `CPed::m_pPlayerInfo` |  |
| 0xA84 | `field_a84` | `CPed::m_nDeathState` | `CPed::m_fMaxHealth` |  |
| 0xA94 | `max_health_bits_a94` | `CPed::m_fMaxHealth` | `CPed::field_378` |  |
| 0xB40 | `vehicle_address` | `CPed::m_pVehicle` |  |  |
| 0xEA8 | `component_models_address` | `CPed::m_pComponentModels` | `CPed::m_pComponentModels` |  |
| 0xEAC | `protected_handle_eac` |  | `CPed::field_840` |  |

## Notas

- plugin_IV `CPlayerPed.h` está vacío: solo hereda de CPed y valida tamaño `0xF00`. IV-SDK e IV-SDK.Net no declaran CPlayerPed.
- IV-SDK.Net replica en gran parte los headers de IV-SDK; su aporte es independiente solo donde difiere.
