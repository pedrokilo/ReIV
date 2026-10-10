# CPlayerPed protected value operations

`source/game/Peds/CPlayerPed.h` reconstructs four player bodies and
three helper bodies with MSVC x86 assembly. The public operations take the real
object pointer and an explicit `ProtectedCallbacks` dependency. Neither XLive
ordinal is implemented or resolved by this header.

| Original VA | Operation |
| --- | --- |
| 0x009C1CF0 | SetProtectedAndFlags, virtual slot 60 |
| 0x009C1D20 | SetProtectedAndFlagsWithUnused, slot 61; discarded second DWORD |
| 0x009C1D50 | AddProtectedAndFlags, slot 62 |
| 0x009C1CE0 | GetPlayerProtected, slot 63 |
| 0x00447610 | WriteProtected helper |
| 0x00447640 | ReadProtected helper |
| 0x0089E5A0 | UpdateValueFlags helper |

The protected handle is the DWORD at object + 0xEAC. Original XLive ordinal 5021
receives `(handle, 0, value_bits)` and ordinal 5020 receives
`(handle, 0, &zero_initialized_output_bits)`. Their return DWORDs are ignored.
The getter returns callback output via x87. Ghidra's saved decompilation of
0x00447640 incorrectly returns the handle; the machine instructions load the
output local instead.

Flag updates preserve COMISS comparison behavior at 50, 100 and zero, including
unordered NaNs and MXCSR DAZ. Bytes +0x212/+0x211/+0x210 and DWORD +0x214 are
updated in original order. Player setters perform their original x87 load/store
conversions. The additive body retains both single-precision stores before
updating flags. These field names describe behavior; full layout and semantic
names remain separate work.

## Verification

Run `run.ps1`. Preparation checks the canonical executable SHA-256, extracts
seven complete bodies and verifies both threshold constants. The native Win32
comparison copies those bodies into executable test storage and patches only
dependency destinations and constant addresses. XLive callbacks are isolated
mocks, including a getter that leaves its zero-initialized output untouched.

The recorded run passed 325,248 comparisons: 46,464 per body. It includes 22 float
patterns, four rounding modes, three x87 precision modes, four DAZ/FTZ settings
and two getter modes. It compares all 4,096 object bytes, callback argument/event
logs, protected bits, return values, x87 status and MXCSR. Exceptions were masked.

This evidence establishes the tested bodies with controlled dependencies. It
does not establish XLive behavior, exception handling with unmasked floating
exceptions, in-game calls, installed replacement hooks, or complete CPlayerPed
reconstruction. Exact original stack cleanup (slot 61 RET 8) is accounted for by
the original comparison call type; reconstructed internal helpers use a distinct
explicit-dependency fastcall interface rather than pretending to be hook targets.
