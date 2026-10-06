#include <cstdio>
#include "../contrib/IV SDK/IV-SDK-main/include/IVSDK.cpp"

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
void OnGameLoad() { Log("SDK gameLoadEvent received"); }
void OnIngameStartup() { Log("SDK ingameStartupEvent received"); }
}

void plugin::gameStartupEvent() {
    Log(gameVer == VERSION_1070 ? "ReIV bootstrap loaded | GTA IV 1.0.7.0 | x86"
                               : "ReIV bootstrap loaded | GTA IV 1.0.8.0 | x86");
    gameLoadEvent::Add(OnGameLoad);
    ingameStartupEvent::Add(OnIngameStartup);
}
