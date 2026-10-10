# Player storage and pool stride

`source/game/Peds/PlayerPedLayout.h` provides a flat, standard-layout x86 storage
view with individually asserted observed offsets. Addresses remain 32-bit words
on any parsing host. Floating fields are represented as bits to avoid implicit
NaN conversions. Unknown bytes remain explicit padding. Semantic names are
correlations with local IV SDK headers, rather than independently proved names.

The observed storage prefix ends at 0xEF8: the canonical constructor writes the
DWORD at +0xEF4. This is a lower bound from observed access, not the class size.
The separately named pool-slot structure has 0xF00 bytes, including eight final
unknown bytes.

## Canonical allocation chain

All bytes and instruction locations are saved in `pool-stride-evidence.json`,
bound to canonical EXE SHA-256
`ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.

1. At VA 0x00439E20, initialization obtains 0x1C bytes for pool metadata. It keeps
   that allocation in ESI, calls 0x0043A9E0, and stores the returned pool pointer
   into VA 0x018A82AC at 0x00439E44.
2. At 0x0043A9E0, the helper explicitly writes `DWORD[ESI+0xC] = 0xF00`.
   It allocates 0x70800 bytes for objects, 0x78 bytes for slot flags, and writes
   count 0x78 at pool +8. `0x78 * 0xF00 == 0x70800`.
3. Factory 0x0096D870 loads ECX from the same global VA 0x018A82AC, calls
   allocator 0x0096D520, and tail-jumps to CPlayerPed constructor 0x009C1910.
4. The allocator obtains `DWORD[pool+0xC]` at 0x0096D580, multiplies it by the
   selected slot index at 0x0096D587, and adds `DWORD[pool+0]` at 0x0096D58A.

This proves a **0xF00 pool stride** for storage used by the player factory. It
does not prove the exact C++ class size, all padding semantics, original alignment
requirements, or a separate CPed base boundary.

## SDK correlation

Local `contrib/IV SDK/IV-SDK-main/include/CPools.h` uses AddressSetter offset
0x014A82AC; adding preferred module base 0x00400000 gives the canonical global
VA 0x018A82AC. Its `CPool.h` describes fields +0/+4/+8/+C/+10/+14 and entry-size
arithmetic consistent with the observed allocator.

`CEntity.h`, `CPhysical.h` and `CPed.h` correlate observed inherited field labels
at +0x20, +0x63, +0x6C, +0x118, +0x210 through +0x228, +0x260, +0x26C, +0x2DC,
+0xA94 and +0xB40. CPed.h also includes player-specific regions near +0xE80
through +0xF00. Its `VALIDATE_SIZE(CPed, 0xF00)` therefore must not be used to
infer a proven native CPed/CPlayerPed inheritance boundary. Plugin-SDK's empty
CPlayerPed declaration and 0xF00 assertion are corroborating community metadata,
not an independent native class-size proof.

The initializer at player +0xE80 and protected-handle helper at +0xEAC are
observed constructor receivers. The first embedded object's full type and extent
are not established by this storage view.

MSVC x86 syntax verification passed, including all offset/size assertions.
