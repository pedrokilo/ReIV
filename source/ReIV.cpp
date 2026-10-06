#include <cstdio>
#define DllMain SdkDllMain
#include "../contrib/IV SDK/IV-SDK-main/include/IVSDK.cpp"
#undef DllMain
#include "AtStringHashProbe.h"

namespace {
void Log(const char* message) {
    char executable[MAX_PATH]{};
    GetModuleFileNameA(nullptr, executable, MAX_PATH);
    std::string path(executable);
    path.resize(path.find_last_of("\\/") + 1);
    path += "ReIV.log";
    FILE* file = nullptr;
    if (fopen_s(&file, path.c_str(), "a") == 0 && file) {
        SYSTEMTIME now{};
        GetLocalTime(&now);
        fprintf(file, "%04u-%02u-%02u %02u:%02u:%02u | %s\n",
            now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond, message);
        fclose(file);
    }
}
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
    Log(gameVer == VERSION_1070 ? "ReIV bootstrap loaded | GTA IV 1.0.7.0 | x86"
                               : "ReIV bootstrap loaded | GTA IV 1.0.8.0 | x86");
    gameLoadEvent::Add(OnGameLoad);
    ingameStartupEvent::Add(OnIngameStartup);
    processScriptsEvent::Add(hashprobe::Tick);
    Log(hashprobe::Install() ? "atStringHash bank passed; replacement installed"
                            : "atStringHash validation or signature failed; inspect report");
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_DETACH) {
        hashprobe::Report("process_detach");
        Log("ReIV process detach");
    }
    return SdkDllMain(module, reason, reserved);
}
