# Animation controlled validation

Scope: every pending reference in all 14 headers recursively below `source/game/animation`: 108 slot references, 85 distinct preferred virtual addresses. Inventory and per-reference dispositions are in `evidence/inventory.csv` and `evidence/static-targets.csv`.

`ExportAnimation.java` exports disassembly and pseudocode of each distinct target from the existing canonical Ghidra project with `-noanalysis -readOnly`. The original analysis database is not modified. `entry-bytes.json` comes directly from canonical PE file section mappings. Assembly establishes the tested machine-level calling conventions; descriptive names are not recovered original symbols.

The generic pure-stub bank covers constant-return and no-op bodies. `source/hooks/AnimationFixtureProbe.h` separately covers seven nontrivial destinations with 64 calls each. Every call validates the canonical host and 16 entry bytes first and uses synthetic stack storage. Failures stop that target immediately; no replacement hook is installed.

| Preferred VA | Exact controlled behavior | ABI |
|---|---|---|
| 0x0050B6E0 | Increment unsigned field at +4 | ECX object, no stack arguments, void |
| 0x0050B6F0 | Decrement field at +4 and return the remaining value | ECX object, no stack arguments, EAX result |
| 0x0059BC50 | Read field at +8 | ECX object, no stack arguments, EAX result |
| 0x0089BBF0 | Set bit 0x20 at +0x24 according to low input byte; preserve all other bits | ECX object, one stack argument, RET 4 |
| 0x008E05A0 | Return +0x38 when bit 0x04000000 at +0x24 is set, otherwise zero | ECX object, no stack arguments, EAX result |
| 0x008B8FE0 | Copy four floats from local +0x10 or parent +0x30 into supplied output | ECX object, output pointer, RET 4 |
| 0x009EB110 | Write 128 to supplied output and return field +8 | ECX object, output pointer, RET 4, EAX result |

The decrement fixture deliberately keeps the count nonzero: its zero branch dispatches a deleting destructor and remains untested. Vector reader tests both pointer and local branches. Flag writer checks preservation of other bits with varying initial values. These tests prove controlled machine behavior, not complete object layouts, original class method names, lifetime correctness, or safe replacement hooks.

Complex destinations remain disabled until object construction, state requirements, and full signatures are established. `static-targets.csv` records static dispositions only; runtime reports must be checked separately before marking any call validated.
