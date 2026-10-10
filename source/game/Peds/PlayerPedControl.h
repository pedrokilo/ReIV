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
class PlayerPedControl {
    static std::uint32_t Read(const void* p, unsigned offset) {
        std::uint32_t value;std::memcpy(&value,static_cast<const unsigned char*>(p)+offset,4);return value;
    }
    static void Write(void* p,unsigned offset,std::uint32_t value){std::memcpy(static_cast<unsigned char*>(p)+offset,&value,4);}
public:
    // VA 0x009C0AA0, slot 14. Raw EAX result; its gameplay meaning is unknown.
    static std::uint32_t ApplyModel(void* object,std::uint32_t model,const PlayerPedControlDependencies& d){
        const auto descriptor=d.modelAt15F73B0(d.context,model);
        std::uint8_t flag;std::memcpy(&flag,static_cast<const unsigned char*>(descriptor)+0x8C,1);
        if(!flag)return d.call8AC500(d.context,object,model);
        d.call8DB2B0(d.context,model);
        d.call8AC500(d.context,object,model);
        // The original SETNE CL leaves high bits of ECX unspecified; 9BF660
        // reads only its argument's low byte (CMP BYTE [ESP+8],0).
        d.call9BF660(d.context,object,static_cast<std::uint8_t>(Read(object,0x68)!=0xFFFFFFFFu));
        return d.call8DD530(d.context,object,Read(object,0x21C));
    }
    // VA 0x009C1E10, slot 47, five stack arguments, RET 20.
    static void* CreateControl(void* object,std::uint32_t a,std::uint32_t b,std::uint32_t c,std::uint32_t e,std::uint32_t count,const PlayerPedControlDependencies& d){
        auto allocated=d.call439CB0(d.context,d.load18A839C(d.context));
        auto created=allocated?d.call4F4D20(d.context,allocated,object,0,a,b,c,e):nullptr;
        Write(object,0x6C,static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created)));
        // Deliberately invoked even for null, matching the original caller.
        d.call49F330(d.context,created,count);
        return reinterpret_cast<void*>(static_cast<std::uintptr_t>(Read(object,0x6C)));
    }
};
} }
