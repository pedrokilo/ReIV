#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
#include "../../reversing/CPlayerPed/native-clone/native-validation.h"
#include "../../reversing/CPlayerPed/native-clone/templates.h"
#include "../../reversing/CPlayerPed/NativeObserverBridge.h"

namespace playernativeprobe {
namespace bridge = reiv::player_observer;
inline reiv::player_native::ValidatedResolver resolver;
// Keep published code alive until process exit, including possible in-flight calls.
inline reiv::player_clone::CoffClone* clone = nullptr;
inline volatile LONG* slot = nullptr;
inline DWORD slotProtection=0;
inline bool enabled=false,installed=false,restored=false,finished=false,failed=false;
inline const char* phase="waiting_for_player";
unsigned Resolve(reiv::player_clone::Kind kind,unsigned va);
void Report();
bool Restore();
bool Install(void* player);
void Initialize();
void Tick();
}
