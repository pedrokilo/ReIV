#pragma once
#include <cstdint>
#include <cstring>
#include <initializer_list>

namespace reiv { namespace game {
// Reconstructed control flow, not the implementation of its external callees.
// Callbacks make every dependency explicit and allow isolated trace comparisons.
struct PlayerPedDestructionDependencies {
    void* context;
    std::uint32_t playerVtable; // relocated VA 0x00D819C4
    void (*call8DD270)(void*, void*); // thiscall, no stack arguments
    void (*call8DD8B0)(void*, void*); // thiscall, no stack arguments
    void (*call5B1C10)(void*, void*); // cdecl allocation release
    void* (*load1548F88)(void*); // load at each original call site
    std::uint32_t (*call92F4D0)(void*, void*, std::uint32_t); // thiscall, RET 4
    std::uint32_t (*call8631E0)(void*, std::uint32_t); // cdecl
    void (*call9C0A70)(void*, std::uint32_t); // cdecl
    void (*call920CD0)(void*, void*, std::uint32_t); // thiscall, RET 4
    void (*call4475F0)(void*, void*); // thiscall, embedded member
    void (*call8AC1E0)(void*, void*); // tail call to CPed destructor
    void* (*load18A82AC)(void*);
    void (*call448300)(void*, void*, void*); // thiscall allocator, RET 4
};

class PlayerPedDestruction {    static std::uint32_t Read(const void* p, std::uint32_t offset);    static void Write(void* p, std::uint32_t offset, std::uint32_t value);    static void* Pointer(std::uint32_t value);    static void* Member228(void* object);public:

    // VA 0x009C1E60, complete body ending in JMP 0x008AC1E0.
    // Requires readable [member228 + 0x3E4/0x3E8], as does the original.
    // The EA8 pointer and member228 are deliberately re-read after callbacks.
    static void Destroy(void* object, const PlayerPedDestructionDependencies& d);
    // VA 0x009C2260, scalar deleting-destructor wrapper, RET 4.
    // Return is the original pointer, even when the allocator has released it.
    static void* DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& d);

};
} }
