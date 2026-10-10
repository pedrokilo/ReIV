# Native binding of compiled reconstructed player bodies

This design does not install hooks. The separate loader and banks now execute relocated compiled-source clones in isolated Win32 fixtures; live validation remains pending. The extraction tool reads **compiled reconstructed source**, not GTAIV function bytes. `evidence/native-binding-design.json` contains the complete section bytes, source/object hashes, relocation operands and two synthetic address-patching checks per body.

| Body | Compiled COMDAT bytes | DIR32 operands |
|---|---:|---:|
| Update | 2084 | 97 |
| Adjust | 341 | 13 |
| Select | 1789 | 61 |

MSVC gives each naked inline function a separate code COMDAT section, starting at symbol offset zero. COFF section bounds avoid the invalid technique of stopping at the first `RET`: these bodies have multiple exits. Every relocation is `IMAGE_REL_I386_DIR32`, points at a decoded four-byte displacement/immediate, and names a recognized source global, source callback cell, source table, or local label. There are no unexplained relocation symbols in these three compiled bodies. The code contains no relative external calls requiring a second relocation scheme; local relative branches retain their displacement when the whole section moves.

## Address resolution

Validate the exact supported executable and obtain its loaded image base before resolving any address. Original VAs in symbol names use preferred base `0x00400000`; resolve each with `loadedGameBase + originalVA - 0x00400000`. Require checked 32-bit arithmetic and validate the relevant image mapping before publication.

* `gXXXXXXXX` and `objectXXXXXXXX`: patch the absolute operand directly to game storage, preserving byte/DWORD/SSE widths from each original instruction. Do not take snapshots into fixture variables or write fixture snapshots back to the game.
* `callXXXXXXXX`: patch the operand to a private four-byte callback cell. The **contents** of that cell are the relocated executable function address; the instruction still performs `CALL DWORD PTR [cell]`. Patching the operand directly to callee code would incorrectly dereference its first four bytes.
* local label: patch to `allocatedCodeBase + COFF symbolValue + addend`.
* table symbol: patch to a private 16-byte table plus COFF addend. Never map these source tables to game tables: they contain addresses into the reconstructed code copy.

Callback cells preserve the original ABI without C++ intermediary wrappers. Keep ECX receivers, stack arguments, caller/callee cleanup, AL-only returns, ST0 float returns and flags exactly as emitted. Update's two indirect virtual calls remain indirect and must continue to load the object's real vtable. Calling originals for unresolved dependencies is an external dependency, not reconstruction of those callees.

## Input tables and concurrency

Select contains eight `LEA/MOV` pairs that initialize its two local-label tables. Executing this prefix on every invocation introduces mutable shared storage and prevents read-only publication. During binding, derive the eight destinations from the verified local-label relocations, initialize the private tables once, and publish an entry at the original prologue **88 bytes into the compiled section**. Require verification of this offset against each newly compiled object; never reuse it blindly. All table destinations are beyond the prefix. Do not publish entry zero after making the tables read-only.

Allocate code separately from private callback cells/tables. Patch while unpublished and writable, initialize all cells and tables, then seal code executable/read-only and cells/tables read-only, flush the instruction cache, and publish the entry only after complete initialization. This removes the source fixture globals and mutable table prefix from invocation state. No thread-local fixture rebinding, global callback swapping, per-call code patching, or coarse locking is required. Game storage remains shared with the same accesses as the original body; this does not prove the original algorithm itself is thread-safe. Unpublishing/freeing a binding requires callers to be quiescent.

## Remaining verification before use

Static patch arithmetic has passed at two synthetic game/code bases. `CoffClone.h` and `native-clone/run.ps1` additionally test **compiled-source clones**, with private callback cells/tables and simulated global storage, against original-byte fixtures and reconstructed source. Each body uses two independently allocated clones. Banks preserve full buffers, ordered callback ABI trace, FP state and all eight jump destinations. Code remains RX, binding data RO and byte-identical after invocation. Fourteen loader-contract checks cover rejected sizes, unresolved callbacks, overlapping/out-of-bound operands, unknown kinds, invalid local labels/table addends, unrecognized table initialization and unpublished entry after rejection. These tests do not establish concurrent invocation correctness; original game globals and dependency algorithms remain shared.

Update: 139,920 cases; Adjust: 2,457,600; Select: 74,448. Each case runs original, source and two clones, totaling 5,343,936 clone executions. Adjust and Update exercise 48 masked FP configurations; Select uses default FP state and sampled control paths. Update's existing stack-pointer trace normalization remains a coverage limitation. Refer to `evidence/native-clone-validation.json` for hashes and actual run output.

The opt-in `run-native.ps1` now tests Update through natural vtable calls on the selected player: it observes at least 32 original calls, enables the reconstructed caller for at least 64 calls, then restores the slot and its original protection. The detached bridge preserves the original entry registers, flags, ESP and FP state; the resolver checks the exact executable, complete target bodies, callee entries and recognized data mappings. A diagnostic run confirmed the live ImageBase equals the actual loaded module base; that observed case and the canonical preferred base are accepted after the exact file hash check. Relocation arithmetic still uses preferred base 0x400000.

This is a gameplay smoke test with original external callees, not a duplicate stateful comparison or complete class certification. Results and attempts are in `evidence/native-runtime-*.json`. Adjust/Select native replacements and concurrent invocation remain untested. The native hook is enabled only by the test marker and restored during the test.
