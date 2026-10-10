#include <cstdio>
#include "DebugLog.h"
#define DllMain SdkDllMain
#include "../../contrib/IV SDK/IV-SDK-main/include/IVSDK.cpp"
#undef DllMain
#include "../hooks/AtStringHashProbe.h"
#include "OriginalCall.h"
#include "../game/scene/CDynamicEntity.h"
#include "../hooks/GetBoneMatrixProbe.h"
#include "../hooks/NMutilsProbe.h"
#include "../hooks/GameStubsProbe.h"
#include "../hooks/AudioFixtureProbe.h"
#include "../hooks/AnimationFixtureProbe.h"
#include "../hooks/ExtraStubsProbe.h"
#include "../hooks/RageStubsProbe.h"
#include "../hooks/RageFixtureProbe.h"
#include "../hooks/RageWriteProbe.h"
#include "../hooks/ARTStubsProbe.h"
#include "../hooks/ARTFixtureProbe.h"
#include "../hooks/ARTExtraProbe.h"

namespace {
#define Log(message) REIV_INFO("%s", message)
void OnGameLoad() {
    Log("SDK gameLoadEvent received");
    hashprobe::gameLoaded = true;
    hashprobe::Report("game_loaded");
}
void OnIngameStartup() {
    Log("SDK ingameStartupEvent received");
    hashprobe::ingameStarted = true;
    hashprobe::Report("ingame_started");
}
}

void plugin::gameStartupEvent() {
    reiv::debug::Initialize();
    Log(gameVer == VERSION_1070 ? "ReIV bootstrap loaded | GTA IV 1.0.7.0 | x86"
                               : "ReIV bootstrap loaded | GTA IV 1.0.8.0 | x86");
    if (!reiv::original::Initialize()) {
        Log(reiv::original::LastError());
    } else {
        const bool available = reiv::game::CDynamicEntity::OriginalAvailable();
        reiv::debug::Observe("GetBoneMatrix", available, false);
        Log(available
            ? "CDynamicEntity::GetBoneMatrix original binding available | RVA 0x005C7710 | root-bone historical test passed"
            : "CDynamicEntity::GetBoneMatrix original binding rejected: entry bytes or executable memory differ");
    }
    gameLoadEvent::Add(OnGameLoad);
    ingameStartupEvent::Add(OnIngameStartup);
    processScriptsEvent::Add(hashprobe::Tick);
    boneprobe::Initialize();
    processScriptsEvent::Add(boneprobe::Tick);
    nmprobe::Initialize();
    processScriptsEvent::Add(nmprobe::Tick);
    gamestubs::Initialize();
    processScriptsEvent::Add(gamestubs::Tick);
    audiofixtures::Initialize();
    processScriptsEvent::Add(audiofixtures::Tick);
    animationfixtures::Initialize();
    processScriptsEvent::Add(animationfixtures::Tick);
    extrastubs::Initialize();
    processScriptsEvent::Add(extrastubs::Tick);
    ragestubs::Initialize();
    processScriptsEvent::Add(ragestubs::Tick);
    ragefixtures::Initialize();
    processScriptsEvent::Add(ragefixtures::Tick);
    ragewrites::Initialize();
    processScriptsEvent::Add(ragewrites::Tick);
    artstubs::Initialize();
    processScriptsEvent::Add(artstubs::Tick);
    artfixtures::Initialize();
    processScriptsEvent::Add(artfixtures::Tick);
    artextras::Initialize();
    processScriptsEvent::Add(artextras::Tick);
    Log(hashprobe::Install() ? "atStringHash bank passed; replacement installed"
                            : "atStringHash validation or signature failed; inspect report");
    reiv::debug::Observe("atStringHash", hashprobe::original != nullptr, hashprobe::hooked);
    REIV_DEBUG("Runtime catalog exported to ReIV-runtime-hooks.csv");
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_DETACH) {
        hashprobe::Report("process_detach");
        Log("ReIV process detach");
    }
    return SdkDllMain(module, reason, reserved);
}
