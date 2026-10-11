#pragma once
#include "ProbeCommon.h"
#include "AtStringHashProbe.h"
// Pure, complete instruction bodies only. No inferred class ABI is exercised.
namespace artstubs {
struct Candidate { unsigned rva; const unsigned char* bytes; unsigned size; unsigned mask; unsigned expected; bool relocated; unsigned stackPop; bool floatReturn; };
#include "ARTStubBindings.h"
struct Slot { unsigned vtableRva; unsigned slot; unsigned targetRva; };
#include "ARTSlotBindings.h"
inline unsigned slotsChecked=0, slotsFailed=0;
int CheckSlot(const Slot& s, std::uintptr_t& actual);
void AuditSlots();
inline unsigned calls[sizeof(candidates)/sizeof(candidates[0])]{}, failures[sizeof(candidates)/sizeof(candidates[0])]{};
inline unsigned exceptions=0;
inline bool enabled=false,done=false;
int Check(unsigned i);
void Report(const char* phase);
void Initialize();
void Tick();
}
