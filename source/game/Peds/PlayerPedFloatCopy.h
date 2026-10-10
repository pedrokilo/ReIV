#pragma once

#if !defined(_MSC_VER) || !defined(_M_IX86)
#error CPlayerPed float-copy operations require MSVC x86 inline assembly.
#endif

namespace reiv::game::player_detail {
// VA 0x009C1D90 / slot 79 and VA 0x009C1DD0 / slot 80.
// The original uses x87 loads/stores for components 0 and 3, MOVSS for 1/2.
// Keep that distinction and the late load of component 3: memcpy, or loading
// all four components first, changes signalling NaNs and overlapping inputs.
// Assembly-specific reconstruction; the complete object layout is not inferred.
void CopyBlockEC0(void* object, const void* input);

void CopyBlockED0(void* object, const void* input);
}
