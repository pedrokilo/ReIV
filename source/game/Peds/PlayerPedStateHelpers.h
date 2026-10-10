#pragma once
#include <cstdint>
#include <cstring>
#if !defined(_MSC_VER) || !defined(_M_IX86)
#error Player state helpers require MSVC x86.
#endif
namespace reiv::game::player_detail {
using StateQueryCallback = float(__cdecl*)(std::uint32_t selector);
struct StateHelperDependencies {
    const volatile std::uint32_t* sourceD50398;
    volatile std::uint32_t* destinationF1D9D8;
    StateQueryCallback query962B20;
};
// Bodies have proved player receivers at original callsites; the original
// defining C++ class is not inferred from proximity. No live hooks are installed.
// Null player-info paths retain original low-memory fault behavior.
// VA 0x009BF070. MOVSS copies the global as bits before the state write.
void ClearState3D8(void* player, const StateHelperDependencies& d);

// VA 0x009BF2D0. Preserve callback output in ST0 and the destination captured
// before the callback. A C++ float temporary can add an unwanted rounding store.
void __fastcall StoreQuery7(void* player, const StateHelperDependencies* dependencies);
// VA 0x009BF310. The FSTP destination is latched; the flag destination is
// reloaded from player+228 after the callback, allowing dependency mutations.
void __fastcall StoreQuery8AndClearFlag(void* player, const StateHelperDependencies* dependencies);
}
