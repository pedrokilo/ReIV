# CPlayerPed: inventory scope, 2026-10-10

The complete class is still pending. Vtable enumeration is exact within the canonical artifact: 82 slots and 77 unique targets, including 64 slots shared with CPed. It does not enumerate every nonvirtual method.

## Concrete remaining work

- `9BF250`: confirmed player receiver from `B91D70 CALL817F40; MOV ECX,EAX; JMP9BF250`. Full body is 114 bytes. Body reconstruction and validation remain pending in this snapshot.
- `9BEE90`: four-argument auxiliary; do not assign player membership from nearby code.
- `9BF360`: explicit entity parameter, RET4, no preserved incoming ECX. Auxiliary stdcall helper.
- `9C0A70`: explicit pool/reference index, global13D9A38, RET0. Auxiliary cdecl helper.
- `88F660`: receives embedded player+E7C from A606F3 and9B431A. This is a component dependency, not a player receiver. Callee body/contracts remain pending.

The five newly adjudicated neighbor receivers are `9BE5F0`, `9BE790`, `9BEEF0`, `9BEF20`, `9BEF70`; their reconstruction is handled separately. The three StateHelpers neighbors already have source. The initial 18-candidate ledger has15 source bodies and3 excluded child attributions (`9C2680`, `9C2960`, `9C3090`, inherited CPed callers). Historical reconstructed:false entries are not a current absence-of-source claim.

## Outside-range search

A canonical executable-section scan found397 candidate memory operands E7C..EF4 outside9BE000..9C4000. Exact instruction matches from old candidate entries retain316 hits across119 candidatefunctions;81 unaligned or stale-boundary hits remain excluded. This is a bounded candidate search, not an exhaustive class scan.

Fresh provider boundaries distinguish player consumers from members. Script wrappers `B92A00` and `B92B90` resolve817F20(index), read PlayerInfo+58C, and write EA7/EF4. `9C56E0` reads playerEF4 from getter817F40 while its explicit argument accesses another object's295C..296E. None preserves an incoming player thiscall receiver, so none is attributed as a new CPlayerPed member.

No new outside-range own player method is confirmed by this search. Additional offset matches require complete caller/receiver analysis; the absence of confirmation does not prove that no such methods exist.

## What blocks complete native ABI

The CPed base constructor8ABF10 and destructor8AC1E0 remain dependency contracts; their complete bodies and transitive lifetimes are required. Native callbacks must prove argument cleanup, AL/EAX returns, x87 ST0, preserved registers, globals and live ownership. Pool strideF00 and observedminimumEF8 are storage facts; they do not recover the original base extent or complete C++ inheritance layout. Embedded E80 extent and protected/playerlink/component lifetimes remain unresolved.

Original readable method/field names are optional for equivalent behavior: offset or VA labels can remain. Actual calling conventions, access widths, lifetime/ownership, exact layout boundaries and dependency behavior are required. A semantic name alone cannot close an ABI gap.

Evidence: `evidence/neighbor-receiver-adjudication.json`, `evidence/outside-range-adjudication.json`, `evidence/native-abi-completion-gaps.json`, and fresh provider records `rea-outside-instructions.json` / `rea-seven-player-callers.json`. No hooks, common sources or runtime probe were edited.
