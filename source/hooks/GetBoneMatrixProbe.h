#pragma once
#include "ProbeCommon.h"
class CPed; // IV-SDK; esta sonda se compila dentro de core/ReIV.cpp, la unica unidad que incluye el SDK.
#include "AtStringHashProbe.h"
#include "../game/scene/CDynamicEntity.h"
#include <cmath>

namespace boneprobe {
inline unsigned ticks = 0, calls = 0, failures = 0, exceptions = 0;
inline bool enabled = false, closeRequested = false;
inline ULONGLONG started = 0, completed = 0;
inline std::uintptr_t lastEntity = 0, lastMatrix = 0;
inline float lastPosition[3]{};

void Report(const char* phase);

// Keep SEH separate from code with destructible C++ objects.
int Check(CPed* ped);

void Initialize();

void Tick();
}
