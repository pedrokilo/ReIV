#include "AtStringHashProbe.h"
// Se compila dentro de core/ReIV.cpp (despues de IVSDK.cpp): el IV-SDK solo admite una unidad de compilacion.

namespace hashprobe {
std::string GameFile(const char* name) {
    char executable[MAX_PATH]{};
    GetModuleFileNameA(nullptr, executable, MAX_PATH);
    std::string path(executable);
    path.resize(path.find_last_of("\\/") + 1);
    return path + name;
}

void Report(const char* phase) {
    FILE* file = nullptr;
    if (fopen_s(&file, GameFile("ReIV-atStringHash.json").c_str(), "w") != 0 || !file) return;
    fprintf(file, "{\n  \"phase\": \"%s\",\n  \"rva\": \"0x1b1c30\",\n"
        "  \"bank_pairs\": %u,\n  \"bank_failures\": %u,\n"
        "  \"hooked\": %s,\n  \"hook_calls\": %ld,\n"
        "  \"runtime_pairs\": %ld,\n  \"runtime_failures\": %ld,\n"
        "  \"game_loaded\": %s,\n  \"ingame_started\": %s,\n  \"script_ticks\": %u\n}\n",
        phase, bankPairs, bankFailures, hooked ? "true" : "false", calls,
        runtimePairs, runtimeFailures, gameLoaded ? "true" : "false",
        ingameStarted ? "true" : "false", scriptTicks);
    fclose(file);
}

void Compare(const std::string& text, std::uint32_t seed) {
    // Includes embedded NULs; both implementations must stop at the same boundary.
    const std::string before = text;
    const auto expected = original(text.c_str(), seed);
    const auto actual = reiv::AtStringHash(text.c_str(), seed);
    ++bankPairs;
    if (expected != actual || text != before) ++bankFailures;
}

std::uint32_t __cdecl Replacement(const char* text, std::uint32_t seed) {
    const LONG number = InterlockedIncrement(&calls);
    const auto actual = reiv::AtStringHash(text, seed);
    if (number <= 4096) {
        const auto expected = original(text, seed);
        InterlockedIncrement(&runtimePairs);
        if (actual != expected) InterlockedIncrement(&runtimeFailures);
    }
    return actual;
}

bool Install() {
    if (plugin::gameVer != plugin::VERSION_1070) return false;
    const auto address = AddressSetter::Get(0x1b1c30, 0);
    if (memcmp(reinterpret_cast<void*>(address), kHashOriginalBytes, sizeof(kHashOriginalBytes)) != 0) return false;
    original = reinterpret_cast<HashFunction>(address);
    const std::uint32_t seeds[] = {0, 1, 0xffffffffu, 0x80000000u, 0x12345678u, 0xdeadbeefu, 0x7fffffffu, 1025};
    const std::vector<std::string> cases = {
        "", "A", "a", "Z", "z", "AZaz09", "\\", "/", "common:\\data\\gta.dat",
        "COMMON:/DATA/GTA.DAT", "\"", "\"ROMAN\"ignored", "\"A\\B\"C",
        "not\"quoted", "\"unclosed", " \t\r\n", std::string("A\0B", 3), std::string(4096, 'Z')
    };
    for (auto seed : seeds) {
        for (const auto& text : cases) Compare(text, seed);
        for (unsigned byte = 1; byte <= 255; ++byte) {
            Compare(std::string(1, static_cast<char>(byte)), seed);
            Compare("\"" + std::string(1, static_cast<char>(byte)) + "\"suffix", seed);
        }
    }
    std::uint32_t rng = 0x52454956;
    for (unsigned test = 0; test < 4096; ++test) {
        std::string text;
        const unsigned length = test % 257;
        for (unsigned i = 0; i < length; ++i) {
            rng = rng * 1664525u + 1013904223u;
            text.push_back(static_cast<char>(rng >> 24));
        }
        rng = rng * 1664525u + 1013904223u;
        Compare(text, rng);
    }
    if (bankFailures != 0) { Report("bank_failed"); return false; }
    // First instructions are MOV ECX,[ESP+8] (4 bytes), PUSH ESI (1 byte).
    // No relative operands occur in these five bytes.
    auto trampoline = static_cast<unsigned char*>(VirtualAlloc(nullptr, 10, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE));
    if (!trampoline) return false;
    memcpy(trampoline, reinterpret_cast<void*>(address), 5);
    trampoline[5] = 0xe9;
    const auto jumpBack = static_cast<std::int32_t>((address + 5) - (reinterpret_cast<std::uintptr_t>(trampoline) + 10));
    memcpy(trampoline + 6, &jumpBack, 4);
    DWORD oldProtection;
    if (!VirtualProtect(trampoline, 10, PAGE_EXECUTE_READ, &oldProtection)) return false;
    FlushInstructionCache(GetCurrentProcess(), trampoline, 10);
    original = reinterpret_cast<HashFunction>(trampoline);
    injector::MakeJMP(address, Replacement, true);
    FlushInstructionCache(GetCurrentProcess(), reinterpret_cast<void*>(address), 5);
    hooked = true;
    // Call the patched entry itself, verify routing and the saved original.
    auto entry = reinterpret_cast<HashFunction>(address);
    const auto beforeCalls = calls;
    const auto result = entry("ReIV\\FIRST_CASE", 0x12345678u);
    if (calls != beforeCalls + 1 || result != original("ReIV\\FIRST_CASE", 0x12345678u)) ++bankFailures;
    Report("hook_installed");
    return bankFailures == 0;
}

void Tick() {
    ++scriptTicks;
    if (!firstTickTime) firstTickTime = GetTickCount64();
    if (scriptTicks == 1 || scriptTicks % 300 == 0) Report("script_tick");
    // Test-only orderly close request; absent marker means normal gameplay.
    if (!closeRequested && GetTickCount64() - firstTickTime >= 20000 &&
        GetFileAttributesA(GameFile("ReIV.validation-test").c_str()) != INVALID_FILE_ATTRIBUTES) {
        closeRequested = true;
        Report("close_requested");
        PostMessageA(rage::g_pHWND, WM_CLOSE, 0, 0);
    }
}

} // namespace hashprobe
