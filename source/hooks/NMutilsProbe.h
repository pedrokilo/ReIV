#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
#include <cwchar>

// Controlled synthetic-object tests only; never hook or destroy game-owned objects.
namespace nmprobe {
inline bool enabled = false, done = false;
inline unsigned calls[6]{}, failures[6]{}, exceptions = 0;
inline unsigned callbackCalls = 0, callbackLevel = 0;
inline wchar_t callbackText[128]{};
void __fastcall Capture(void*, void*, unsigned level, const wchar_t* text);
void Report(const char* phase);
// Defined in NMutilsBindings.h from canonical executable bytes.
#include "NMutilsBindings.h"
int Check(unsigned i);
void Tick();
void Initialize();
}
