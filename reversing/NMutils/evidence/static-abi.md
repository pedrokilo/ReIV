# NMutils static ABI observations

Canonical GTA IV PC 1.0.7.0 SHA256: `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

Exported with Ghidra 12.1.4 against the existing canonical project, `-noanalysis -readOnly`. Assembly governs ABI conclusions; generated pseudocode is an analysis aid. Function names below are descriptions of behavior, not verified original symbols.

| Preferred VA | ABI | Behavior and controlled fixture |
|---|---|---|
| 0x005D4F40 | thiscall object, unsigned flags; pointer return; RET 4 | BasicLogger deleting destructor. With flags zero only overwrites object vptr with 0x00EBA548. Four writable bytes suffice. Flag one invokes game TLS allocator and must not be used for a synthetic object. |
| 0x005D67F0 | thiscall object, unsigned level, const char* text; RET 8 | Converts narrow text to wchar_t on stack then calls object's virtual slot 2 with level and wide text. Controlled logger fixture supplies a thiscall-compatible callback. |
| 0x00401210 | no incoming arguments used; RET | Shared fatal/error thunk. Calls 0x005A8CB0 with message address 0x00E9E378 and two zeroes. Helper invokes MessageBoxW, writes address zero, and can terminate. Never test-call this slot. |
| 0x005D67A0 | cdecl logger pointer, unsigned level, const wchar_t* format, variadic arguments; caller cleanup | Formatter passes buffer, count 0x3FF, format, va_list to 0x00D11D73. Helper 0x00D11C9F doubles count and writes two-byte terminator, proving wide format. Calls logger virtual slot 2 with wide output. |
| 0x005E1600 | thiscall object, unsigned flags; pointer return; RET 4 | MemoryStream deleting destructor calls 0x005E1700. Synthetic object >=0x3C zero-initialized with flags zero avoids allocator/logger callbacks. Internal destructor sets vptr 0x00EBA6D0, accesses offsets 0x0C,0x1C,0x20,0x2D,0x30,0x34,0x38 on optional branches. |
| 0x005E1820 | thiscall object, unsigned flags; pointer return; RET 4 | MemoryStreamReader deleting destructor sets vptr 0x00EBA6C8. Object offset4 is parent pointer; clears parent offset0x34 only when equal to this. Controlled writable parent and flags zero avoid allocator. |

Non-deleting controlled calls establish only the exercised branches. They do not establish constructors, complete original layouts, allocation ownership, or flag-one behavior. The original game objects must never be destructed by the probe.

`entry-bytes.json` provides first 16 canonical bytes at each entry. `pe-sections.json` confirms file offsets equal RVAs for the executable section used here. Absolute immediates embedded in these bytes can require relocation adjustment if image base changes.
