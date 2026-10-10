# Player receiver state helpers

Three complete bodies were reconstructed without attributing ownership merely
from neighboring addresses:

| VA | Implementation | Complete bytes |
| --- | --- | --- |
| 0x009BF070 | ClearState3D8 | 84 |
| 0x009BF2D0 | StoreQuery7 | 52 |
| 0x009BF310 | StoreQuery8AndClearFlag | 73 |

Original callsites establish player-receiver usage. Calls to 0x009BF310 follow
an explicit nonnull ECX check and nonzero byte `[ECX+0x219]` at 0x00BFE975,
0x00BFE99D and 0x00C05E86. The 0x009BF070 call at 0x008792FF loads ECX from
the surrounding object's +0x58C, correlated with local IV SDK CPlayerInfo's
`m_pPlayerPed`. Calls at 0x007B7C7B and 0x007B7C82 pass the same ESI receiver
to ClearState3D8 and StoreQuery7. Exact instruction windows are preserved in
`static-bodies.json`. This establishes observed receiver usage; the original
defining C++ class and complete nonvirtual method set remain unconfirmed.

The static parameter-only helpers 0x009BF360 and 0x009C0A70 were excluded.
Other neighboring candidates remain unadjudicated and are not included solely
on the basis of proximity.

The source preserves:

- The global raw bit copy from 0x00D50398 to 0x00F1D9D8 after clearing +0x3D8.
- x87 callback output and single FSTP destination stores for selectors 7 and 8.
- The member destination latched before a callback.
- The player-info pointer reloaded after selector 8 before clearing bit 0x80.
- Original null-dependent low-memory fault paths; they are not executed in the
  valid-object fixture bank.

The two query bodies use assembly to preserve ST0 without inserting a C++
temporary store. The callback for 0x00962B20 remains an external dependency.
No live hook is installed or global binding supplied by this module.

Run `run.ps1` to verify the canonical EXE, compile MSVC Win32 and repeat tests.
The recorded bank passed **73,728 comparisons**, 24,576 per body, with zero
differences. It compares three full 4,096-byte buffers, globals, callback events,
x87 status and MXCSR. Coverage includes 16 float patterns, three x87 precision
modes, four rounding modes, four DAZ/FTZ combinations, all four clear-state gates
and callback mutations that switch the player-info pointer and flags.

The bank uses copied complete original bodies with controlled dependencies.
It does not validate the original query implementation, unmasked floating
exceptions, live gameplay effects, or complete CPlayerPed reconstruction.
