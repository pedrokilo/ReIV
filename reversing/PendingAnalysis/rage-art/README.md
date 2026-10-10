# Pending rage and ART static analysis

Every pending destination in these roots is represented in `evidence/inventory.json` and `inventory.csv`. Entry disassembly is bounded to 512 bytes / 128 instructions; a detected RET with no branches or calls establishes only a complete linear body. Other slices do not establish the complete control-flow graph. Direct call/jump operands are dependencies, not validated signatures.

`fixture-scope.json` recognizes exact finite scalar bodies and bit copies confined to 4096-byte isolated objects or synthetic stack arguments. Globals, TLS, pointer chasing, unknown registers, branches and calls are excluded. LEA outside the object computes an address only, never dereferences it. Pure bodies are called with synthetic x86 aliases matching exact RET stack cleanup. Only defined EAX return bits (or FLDZ) and complete object mutations are checked; EDX returns and original class ABI are not established. All classes remain unreconstructed and disabled.

Run prepare.py, compile the probe, then run.ps1. Static candidates are not runtime validation. The runner preserves marker/report state and uses the protected game baseline runner. Only passed summaries can support registration.
