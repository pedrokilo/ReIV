#pragma once
#include "ProbeCommon.h"
#include "../rage/AtStringHash.h"
#include "AtStringHashSignature.h"
#include <cstring>
#include <vector>

namespace hashprobe {
using HashFunction = std::uint32_t(__cdecl*)(const char*, std::uint32_t);
inline HashFunction original = nullptr;
inline LONG calls = 0, runtimePairs = 0, runtimeFailures = 0;
inline unsigned bankPairs = 0, bankFailures = 0;
inline unsigned scriptTicks = 0;
inline bool hooked = false, gameLoaded = false, ingameStarted = false;
inline bool closeRequested = false;
inline ULONGLONG firstTickTime = 0;

std::string GameFile(const char* name);
void Report(const char* phase);
void Compare(const std::string& text, std::uint32_t seed);
std::uint32_t __cdecl Replacement(const char* text, std::uint32_t seed);
bool Install();
void Tick();
}
