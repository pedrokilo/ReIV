#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <mutex>
#include <string>
#include "DebugLog.h"
#include "HooksCatalog.h"

namespace reiv::debug {
namespace {
std::mutex outputMutex;
HANDLE console = INVALID_HANDLE_VALUE;
bool checked[sizeof(catalog) / sizeof(catalog[0])]{};
bool installed[sizeof(catalog) / sizeof(catalog[0])]{};
std::string GameFile(const char* name) {
    char path[MAX_PATH]{};
    GetModuleFileNameA(nullptr, path, MAX_PATH);
    std::string file(path);
    file.resize(file.find_last_of("\\/") + 1);
    return file + name;
}
void Export() {
    FILE* file = nullptr;
    if (fopen_s(&file, GameFile("ReIV-runtime-hooks.csv").c_str(), "w") || !file) return;
    fprintf(file, "class,fn_name,preferred_va,rva,module_base,runtime_va,reversed,historical_validated,entry_kind,address_checked_this_run,hook_installed_this_run,evidence\n");
    const auto base = reinterpret_cast<unsigned>(GetModuleHandleW(nullptr));
    for (unsigned i = 0; i < sizeof(catalog) / sizeof(catalog[0]); ++i) {
        const auto& e = catalog[i];
        fprintf(file, "%s,%s,0x%08X,0x%08X,0x%08X,0x%08X,%d,%d,%s,%d,%d,%s\n",
            e.owner, e.function, 0x400000u + e.rva, e.rva, base, checked[i] ? base + e.rva : 0,
            e.reversed, e.validated, e.kind, checked[i], installed[i], e.evidence);
    }
    fclose(file);
}
}
void Initialize() {
    if (GetConsoleWindow() || AllocConsole()) {
        SetConsoleTitleW(L"ReIV | GTA IV 1.0.7.0 | Debug");
        // Open the console explicitly; inherited stdout can be redirected.
        console = CreateFileW(L"CONOUT$", GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
        if (const auto window = GetConsoleWindow()) ShowWindow(window, SW_SHOWNORMAL);
    }
    Export();
    const auto window = GetConsoleWindow();
    DWORD mode = 0;
    const bool writable = console != INVALID_HANDLE_VALUE && console && GetConsoleMode(console, &mode);
    const bool visible = window && IsWindowVisible(window);
    FILE* report = nullptr;
    if (!fopen_s(&report, GameFile("ReIV-debug-console.json").c_str(), "w") && report) {
        fprintf(report, "{\"console_window\":\"0x%08X\",\"visible\":%s,\"writable\":%s,\"always_enabled\":true}\n",
            reinterpret_cast<unsigned>(window), visible ? "true" : "false", writable ? "true" : "false");
        fclose(report);
    }
    Write(writable && visible ? Level::Info : Level::Error, __FILE__, __LINE__,
        "Debug console always enabled | visible=%s writable=%s hwnd=0x%08X",
        visible ? "true" : "false", writable ? "true" : "false", reinterpret_cast<unsigned>(window));
}
void Write(Level level, const char* file, int line, const char* format, ...) {
    char message[2048]{};
    va_list arguments;
    va_start(arguments, format);
    vsnprintf_s(message, sizeof(message), _TRUNCATE, format, arguments);
    va_end(arguments);
    const char* name = file;
    for (const char* p = file; *p; ++p) if (*p == '\\' || *p == '/') name = p + 1;
    const char* names[] = {"info", "debug", "warning", "error"};
    const WORD colors[] = {FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
        FOREGROUND_RED | FOREGROUND_INTENSITY};
    SYSTEMTIME time{};
    GetLocalTime(&time);
    char output[2400]{};
    sprintf_s(output, "[%s][%02u:%02u:%02u.%03u][%s:%d]: %s\r\n", names[static_cast<unsigned>(level)],
        time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, name, line, message);
    std::lock_guard<std::mutex> lock(outputMutex);
    FILE* log = nullptr;
    if (!fopen_s(&log, GameFile("ReIV.log").c_str(), "ab") && log) { fputs(output, log); fclose(log); }
    if (console && console != INVALID_HANDLE_VALUE) {
        SetConsoleTextAttribute(console, colors[static_cast<unsigned>(level)]);
        DWORD written = 0;
        WriteConsoleA(console, output, static_cast<DWORD>(std::strlen(output)), &written, nullptr);
    }
    OutputDebugStringA(output);
}
void Observe(const char* function, bool addressChecked, bool hooked) {
    std::lock_guard<std::mutex> lock(outputMutex);
    for (unsigned i = 0; i < sizeof(catalog) / sizeof(catalog[0]); ++i) {
        if (!std::strcmp(catalog[i].function, function)) { checked[i] = addressChecked; installed[i] = hooked; }
    }
    Export();
}
}
