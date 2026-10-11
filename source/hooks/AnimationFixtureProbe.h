#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include <cstring>
// Exact assembly-derived ABI tests on isolated storage; no hooks are installed.
namespace animationfixtures {
inline bool enabled=false,done=false;
inline unsigned calls[7]{},failures[7]{},exceptions=0;
#include "AnimationFixtureBindings.h"
int Check(unsigned index,unsigned sample);
void Report(const char* phase);
void Initialize();
void Tick();
}
