# Patrones de plugin_IV resueltos en el EXE

Generado por `contrib/plugin-iv-patterns.py` contra `GTAIV.exe` canónico (SHA-256 `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`).

plugin_IV localiza sus funciones y globales con patrones de bytes (`gpattern`). Cada patrón se buscó en las secciones ejecutables. Solo una coincidencia única da una dirección candidata; el nombre y la firma siguen sin validar.

- Patrones: 361 (230 de función, 131 de datos).
- Sin ninguna coincidencia: 283; con varias: 11. Muchos patrones de plugin_IV parecen apuntar a otra compilación del juego, por lo que **la ausencia de coincidencia no dice nada sobre la función** en 1.0.7.0.
- Con coincidencia única: 67; sin coincidencia única: 294.

## Funciones con dirección candidata por clase

| Clase | Candidatas | Total |
| --- | ---: | ---: |
| (libre) | 0 | 18 |
| CAreaName | 0 | 1 |
| CBaseDC | 0 | 3 |
| CCam | 1 | 7 |
| CCamIdle | 0 | 1 |
| CCamScriptInstruction | 1 | 2 |
| CCamScriptInstruction_CamProcess | 0 | 1 |
| CCamScriptInstruction_DestroyAllCams | 1 | 1 |
| CCamScriptInstruction_EnableDebugCam | 1 | 1 |
| CCamScriptInstruction_SetCamBehindPed | 1 | 1 |
| CCamScriptInstruction_SetCamInFrontPed | 1 | 1 |
| CCamScriptInstruction_SetPosTargetEntity | 0 | 1 |
| CCamera | 0 | 1 |
| CCheat | 3 | 10 |
| CControl | 1 | 1 |
| CControllerState | 0 | 1 |
| CCutsceneMgr | 2 | 3 |
| CDrawRadarCircleDC | 0 | 2 |
| CEntity | 2 | 3 |
| CFileTypeMgr | 0 | 1 |
| CFont | 3 | 20 |
| CGeneral | 0 | 7 |
| CHudColours | 0 | 2 |
| CHudComponent | 1 | 1 |
| CKeyboard | 0 | 4 |
| CMenuManager | 2 | 6 |
| CModelInfo | 0 | 1 |
| CPad | 3 | 12 |
| CPed | 5 | 12 |
| CPedIntelligence | 1 | 3 |
| CPhysical | 0 | 5 |
| CPlayerData | 1 | 1 |
| CPlayerInfo | 0 | 4 |
| CRadar | 0 | 2 |
| CSimpleTransform | 0 | 1 |
| CSprite2d | 3 | 13 |
| CStreaming | 0 | 6 |
| CStreetName | 1 | 1 |
| CTaskComplexAimAndThrowProjectile | 0 | 1 |
| CTaskManager | 0 | 1 |
| CTaskSimpleAimGun | 0 | 1 |
| CText | 2 | 3 |
| CTheScripts | 0 | 4 |
| CTimer | 0 | 1 |
| CTxdStore | 0 | 9 |
| CVehicle | 0 | 2 |
| CVehicleName | 0 | 1 |
| CViewport | 0 | 2 |
| CWanted | 1 | 1 |
| CWeaponData | 1 | 5 |
| CWeaponInfo | 2 | 2 |
| CWorld | 1 | 5 |
| C_PcSave | 0 | 2 |
| T_CB_Generic_NoArgs | 0 | 1 |
| audFrontendAudioEntity | 2 | 4 |
| audGtaAudioEntity | 0 | 1 |
| audRadioAudioEntity | 2 | 10 |
| audRadioStation | 0 | 5 |
| cHandlingDataMgr | 0 | 2 |
| rage | 3 | 6 |

Detalle completo en [plugin_iv_patterns.csv](plugin_iv_patterns.csv).
