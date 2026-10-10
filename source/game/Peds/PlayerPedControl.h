#pragma once
#include <cstdint>
#include <cstring>
namespace reiv { namespace game {
struct PlayerPedControlDependencies {
    void* context;
    const void* (*modelAt15F73B0)(void*, std::uint32_t);
    std::uint32_t (*call8AC500)(void*, void*, std::uint32_t); // thiscall, RET 4
    void (*call8DB2B0)(void*, std::uint32_t); // cdecl
    void (*call9BF660)(void*, void*, std::uint8_t); // thiscall, bool low byte, RET 4
    std::uint32_t (*call8DD530)(void*, void*, std::uint32_t); // cdecl
    void* (*load18A839C)(void*);
    void* (*call439CB0)(void*, void*); // thiscall, no explicit arguments
    void* (*call4F4D20)(void*, void*, void*, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t); // thiscall, RET 24
    void (*call49F330)(void*, void*, std::uint32_t); // thiscall, RET 4
};
class PlayerPedControl {    static std::uint32_t Read(const void* p, unsigned offset);    static void Write(void* p,unsigned offset,std::uint32_t value);public:

    // VA 0x009C0AA0, slot 14. Raw EAX result; its gameplay meaning is unknown.
    static std::uint32_t ApplyModel(void* object,std::uint32_t model,const PlayerPedControlDependencies& d);
    // VA 0x009C1E10, slot 47, five stack arguments, RET 20.
    static void* CreateControl(void* object,std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t e,std::uint32_t count,const PlayerPedControlDependencies& d);

};
} }
