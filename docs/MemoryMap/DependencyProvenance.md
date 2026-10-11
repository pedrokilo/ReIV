# Procedencia de dependencias

[Inicio](../../README.md) · [Mapa de memoria](README.md) · [Clasificación de funciones](FunctionClassification.md) · [Progreso del reversing](../ReversedClasses.md)

> Generado por `tools/ReIV.Tools` (C#) a partir de [CPlayerPed.h](../../source/game/Peds/CPlayerPed.h) y de los CSV de este directorio.

Este documento es un **análisis de procedencia de dependencias** (*Dependency Provenance Analysis*): para los cuerpos de CPlayerPed ya reconstruidos, cada dirección externa que invocan o leen (`call…`, `g…`, `object…`, `table…` y las funciones de sus estructuras de dependencias) se clasifica por su **procedencia**. Los cuerpos siguen dependiendo del EXE para todo lo listado aquí; reconstruirlo es trabajo pendiente.

## Resumen

| Medida | Cantidad |
| --- | ---: |
| Direcciones externas distintas | 154 |
| Funciones (sección ejecutable) | 91 |
| Datos globales | 63 |
| Usos en el código | 347 |

### Funciones por procedencia y estado

| Procedencia | Completamente revertidas | Parcialmente revertidas | Sin revertir | Desconocido | Total |
| --- | ---: | ---: | ---: | ---: | ---: |
| GTA IV (juego) | 6 | 0 | 12 | 0 | 18 |
| RAGE (motor) | 0 | 0 | 0 | 0 | 0 |
| ART (NaturalMotion) | 0 | 0 | 0 | 0 | 0 |
| NMutils | 0 | 0 | 0 | 0 | 0 |
| Compartida entre varios origenes | 0 | 0 | 1 | 0 | 1 |
| Sin procedencia identificada | 0 | 0 | 0 | 72 | 72 |

Las funciones sin procedencia identificada no se atribuyen a CRT, RenderWare-equivalente ni código generado: esa separación exige desensamblar cada destino y queda pendiente.

## Funciones externas

| Dirección | Procedencia | Propietarios | Nombres de referencia | Estado | Usos | Módulos |
| --- | --- | --- | --- | --- | ---: | --- |
| `0x00439cb0` | GTA IV (juego) | — | IV-SDK.Net:CPool::New;IV-SDK:CPool::New | Sin revertir | 1 | Control |
| `0x00462f90` | GTA IV (juego) | — | IV-SDK.Net:CNetwork::IsNetworkGameRunning;IV-SDK:CNetwork::IsNetworkGameRunning | Sin revertir | 9 | ActionRange, ActionRequest, ActionSelection, InputSelection, Update, ValueAdjustment |
| `0x007c3900` | GTA IV (juego) | — | IV-SDK.Net:CPad::GetPad;IV-SDK:CPad::GetPad | Sin revertir | 1 | Nonvirtual |
| `0x00817f20` | GTA IV (juego) | — | IV-SDK.Net:CPlayerInfo::GetPlayerInfo;IV-SDK:CPlayerInfo::GetPlayerInfo | Sin revertir | 1 | Construction |
| `0x008a3990` | GTA IV (juego) | CPed | — | Sin revertir | 1 | Counter |
| `0x008a70c0` | GTA IV (juego) | CPed | plugin_IV:CPed::SetDuck | Sin revertir | 1 | ModelReset |
| `0x008aadc0` | GTA IV (juego) | CPed | — | Sin revertir | 3 | Update |
| `0x008ac500` | GTA IV (juego) | CPed | — | Sin revertir | 1 | Control |
| `0x008ff470` | GTA IV (juego) | — | IV-SDK.Net:CGarages::CameraShouldBeOutside;IV-SDK:CGarages::CameraShouldBeOutside | Sin revertir | 2 | InputSelection |
| `0x00924e80` | GTA IV (juego) | — | IV-SDK.Net:CWeaponInfo::GetWeaponInfo;IV-SDK:CWeaponInfo::GetWeaponInfo;plugin_IV:CWeaponInfo::GetWeaponInfo | Sin revertir | 8 | ActionRange, ActionRequest, InputSelection, ReceiverHelpers, Update |
| `0x009be5d0` | GTA IV (juego) | CPed;CPlayerPed | IV-SDK.Net:CPed::GetPadFromPlayer;IV-SDK:CPed::GetPadFromPlayer | Completamente revertidas | 5 | Counter, InputSelection, Update |
| `0x009be7d0` | GTA IV (juego) | CPed;CPlayerPed | IV-SDK.Net:CPed::ProcessWeaponSwitch;IV-SDK:CPed::ProcessWeaponSwitch | Completamente revertidas | 2 | Update |
| `0x009bee70` | GTA IV (juego) | CPlayerPed | — | Completamente revertidas | 2 | Update |
| `0x009beed0` | GTA IV (juego) | CPlayerPed | — | Completamente revertidas | 2 | Update |
| `0x009bf660` | GTA IV (juego) | CPlayerPed | — | Completamente revertidas | 1 | Control |
| `0x009bfd80` | GTA IV (juego) | CPlayerPed | — | Completamente revertidas | 2 | Update |
| `0x009c5d60` | GTA IV (juego) | CVehicle | IV-SDK.Net:CVehicle::IsDriver;IV-SDK:CVehicle::IsDriver | Sin revertir | 2 | InputSelection |
| `0x00afea00` | GTA IV (juego) | CCamScriptInstruction | plugin_IV:CCamScriptInstruction::SetInstruction | Sin revertir | 2 | Update |
| `0x00c28820` | Compartida entre varios origenes | CAddModelInfoReferenceDC;CAddTxdReferenceDC;CAlterWantedLevelEvent;(+173) | — | Sin revertir | 2 | ActionRange, ActionSelection |
| `0x00401950` | Sin procedencia identificada | — | — | Desconocido | 5 | Update |
| `0x004255a0` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x00426780` | Sin procedencia identificada | — | — | Desconocido | 21 | InputSelection |
| `0x00426910` | Sin procedencia identificada | — | — | Desconocido | 4 | Counter, InputSelection |
| `0x004269b0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x004389d0` | Sin procedencia identificada | — | — | Desconocido | 9 | Update, ValueAdjustment |
| `0x00441f20` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x004475f0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x00448300` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x00448330` | Sin procedencia identificada | — | — | Desconocido | 1 | Counter |
| `0x0049f330` | Sin procedencia identificada | — | — | Desconocido | 1 | Control |
| `0x004f4d20` | Sin procedencia identificada | — | — | Desconocido | 1 | Control |
| `0x005b1c10` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x00785eb0` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x008631e0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x008793f0` | Sin procedencia identificada | — | — | Desconocido | 1 | ModelReset |
| `0x0088f5d0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x0089c8b0` | Sin procedencia identificada | — | — | Desconocido | 1 | ModelReset |
| `0x0089dfb0` | Sin procedencia identificada | — | — | Desconocido | 1 | ReceiverHelpers |
| `0x0089e300` | Sin procedencia identificada | — | — | Desconocido | 3 | InputSelection |
| `0x0089ea80` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x008a07e0` | Sin procedencia identificada | — | — | Desconocido | 1 | ModelReset |
| `0x008a3390` | Sin procedencia identificada | — | — | Desconocido | 1 | ReceiverHelpers |
| `0x008a92c0` | Sin procedencia identificada | — | — | Desconocido | 1 | ModelReset |
| `0x008ac1e0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x008ae670` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x008db2b0` | Sin procedencia identificada | — | — | Desconocido | 1 | Control |
| `0x008dd270` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x008dd530` | Sin procedencia identificada | — | — | Desconocido | 1 | Control |
| `0x008dd8b0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x0091a050` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x0091a0a0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00920cd0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x00921320` | Sin procedencia identificada | — | — | Desconocido | 1 | ReceiverHelpers |
| `0x00921e00` | Sin procedencia identificada | — | — | Desconocido | 1 | ReceiverHelpers |
| `0x00922020` | Sin procedencia identificada | — | — | Desconocido | 1 | ReceiverHelpers |
| `0x00922850` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x009252d0` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x0092f4d0` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x00962b20` | Sin procedencia identificada | — | — | Desconocido | 3 | StateHelpers, ValueAdjustment |
| `0x00976e90` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x0097d7c0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00987730` | Sin procedencia identificada | — | — | Desconocido | 5 | InputSelection, Update |
| `0x0099c5e0` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009a9cf0` | Sin procedencia identificada | — | — | Desconocido | 8 | ActionRequest, InputSelection, Update |
| `0x009a9ef0` | Sin procedencia identificada | — | — | Desconocido | 3 | ActionRange, ActionRequest, Nonvirtual |
| `0x009aa330` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009ac110` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009adb90` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009b3b00` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009be4a0` | Sin procedencia identificada | — | — | Desconocido | 2 | InputSelection |
| `0x009bee44` | Sin procedencia identificada | — | — | Desconocido | 6 | InputSelection |
| `0x009bee54` | Sin procedencia identificada | — | — | Desconocido | 6 | InputSelection |
| `0x009bf0d0` | Sin procedencia identificada | — | — | Desconocido | 1 | ModelReset |
| `0x009bf360` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009bf390` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009bf420` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009c03e0` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009c0660` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009c07a0` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009c0a70` | Sin procedencia identificada | — | — | Desconocido | 1 | Destruction |
| `0x009c1300` | Sin procedencia identificada | — | — | Desconocido | 3 | ActionRange, ActionRequest, ActionSelection |
| `0x009c2720` | Sin procedencia identificada | — | — | Desconocido | 1 | Counter |
| `0x009e6580` | Sin procedencia identificada | — | — | Desconocido | 1 | ReferenceClear |
| `0x009e6630` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x009e9090` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x009e9340` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |
| `0x00aa80d0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00aa83f0` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00ab3b60` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00afe160` | Sin procedencia identificada | — | — | Desconocido | 2 | Update |
| `0x00d0c8e4` | Sin procedencia identificada | — | — | Desconocido | 1 | ActionSelection |

## Datos globales

| Dirección | Sección | Nombre de referencia | Usos | Módulos |
| --- | --- | --- | ---: | --- |
| `0x00d50398` | `.rdata` | — | 3 | ActionSelection, Update |
| `0x00d582a0` | `.rdata` | — | 2 | Update |
| `0x00d5a154` | `.rdata` | — | 2 | ValueAdjustment |
| `0x00d796e4` | `.rdata` | — | 2 | Update |
| `0x00d81944` | `.rdata` | — | 2 | Update |
| `0x00d81958` | `.rdata` | — | 3 | ActionSelection, Update |
| `0x00d819b4` | `.rdata` | — | 3 | ValueAdjustment |
| `0x00d819b8` | `.rdata` | — | 2 | Update |
| `0x00d8f340` | `.rdata` | — | 2 | Update |
| `0x00dc9290` | `.rdata` | — | 4 | ActionSelection, Update |
| `0x00dcb2a8` | `.rdata` | — | 1 | ActionSelection |
| `0x00dcb2ac` | `.rdata` | — | 4 | Update |
| `0x00dce03c` | `.rdata` | — | 1 | ActionSelection |
| `0x00dcea38` | `.rdata` | — | 2 | ValueAdjustment |
| `0x00decd60` | `.rdata` | — | 3 | ActionSelection, ValueAdjustment |
| `0x00e3447c` | `.rdata` | — | 2 | Update |
| `0x00ebded4` | `.rdata` | — | 2 | Update |
| `0x00ebdee4` | `.rdata` | — | 1 | ActionSelection |
| `0x00ebe128` | `.rdata` | — | 1 | ActionSelection |
| `0x00ebe294` | `.rdata` | — | 1 | ActionSelection |
| `0x00f0e4a0` | `.data` | — | 2 | Update |
| `0x00f21a70` | `.data` | IV-SDK.Net:CCamera::g_pFinalCam;IV-SDK:CCamera::g_pFinalCam | 2 | Update |
| `0x00f2f067` | `.data` | — | 1 | Counter |
| `0x00f2f869` | `.data` | — | 1 | ActionSelection |
| `0x00f2f86a` | `.data` | — | 1 | ActionSelection |
| `0x00f317a8` | `.data` | — | 1 | ActionSelection |
| `0x00f317ac` | `.data` | — | 1 | ActionSelection |
| `0x00f317b0` | `.data` | — | 1 | ActionSelection |
| `0x00f317b4` | `.data` | — | 1 | ActionSelection |
| `0x00f317b8` | `.data` | — | 2 | Update |
| `0x00fc7eff` | `.data` | — | 1 | ActionRange |
| `0x010c7a08` | `.data` | — | 1 | ActionRange |
| `0x010d0170` | `.data` | IV-SDK.Net:CGarages::bCamShouldBeOutside;IV-SDK.Net:CReplay::Mode;IV-SDK:CGarages::bCamShouldBeOutside;(+1) | 2 | Update |
| `0x010e1984` | `.data` | — | 2 | Update |
| `0x010f8044` | `.data` | IV-SDK.Net:CGame::m_nCurrentEpisode;IV-SDK:CGame::m_nCurrentEpisode | 4 | ActionRange, ActionRequest, InputSelection |
| `0x011dc4c0` | `.data` | — | 1 | ActionSelection |
| `0x011dc4c4` | `.data` | — | 1 | ActionSelection |
| `0x011dc4c8` | `.data` | — | 1 | ActionSelection |
| `0x011dc4e0` | `.data` | — | 1 | ActionSelection |
| `0x011dc4e4` | `.data` | — | 1 | ActionSelection |
| `0x011dc4e8` | `.data` | — | 1 | ActionSelection |
| `0x011dde74` | `.data` | IV-SDK.Net:CTimer::m_snTimeInMilliseconds;IV-SDK:CTimer::m_snTimeInMilliseconds | 10 | Update |
| `0x011dde7c` | `.data` | IV-SDK.Net:CTimer::ms_fTimeStep;IV-SDK:CTimer::ms_fTimeStep | 8 | Update, ValueAdjustment |
| `0x011ddf38` | `.data` | IV-SDK.Net:CTimer::m_FrameCounter;IV-SDK:CTimer::m_FrameCounter | 4 | InputSelection, Update |
| `0x01548f88` | `.data` | — | 1 | Destruction |
| `0x015f73b0` | `.data` | IV-SDK.Net:CModelInfo::ms_modelInfoPtrs;IV-SDK:CModelInfo::address_line_174;plugin_IV:CModelInfo::ms_modelInfoPtrs | 1 | Control |
| `0x01618020` | `.data` | IV-SDK.Net:CPools::ms_pCameraPool;IV-SDK:CPools::ms_pCameraPool | 2 | Update |
| `0x016180e8` | `.data` | — | 6 | Update |
| `0x016180ec` | `.data` | — | 6 | Update |
| `0x016180f0` | `.data` | — | 4 | Update |
| `0x016180f4` | `.data` | — | 3 | Update |
| `0x016180f8` | `.data` | — | 3 | Update |
| `0x01618101` | `.data` | — | 1 | ActionSelection |
| `0x01618104` | `.data` | — | 2 | ValueAdjustment |
| `0x01618106` | `.data` | — | 1 | ActionSelection |
| `0x0161810c` | `.data` | — | 4 | Update |
| `0x01618110` | `.data` | — | 3 | Update |
| `0x01662170` | `.data` | — | 1 | Nonvirtual |
| `0x0168f910` | `.data` | — | 3 | Update |
| `0x017237b0` | `.data` | — | 1 | ActionSelection |
| `0x01724286` | `.data` | — | 2 | Update |
| `0x018a82ac` | `.data` | IV-SDK.Net:CPools::ms_pPedPool;IV-SDK:CPools::ms_pPedPool | 1 | Destruction |
| `0x018a839c` | `.data` | — | 1 | Control |

Detalle completo en [dependency_provenance.csv](dependency_provenance.csv).

