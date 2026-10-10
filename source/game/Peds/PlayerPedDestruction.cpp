#include "game/Peds/PlayerPedDestruction.h"
#include <cstdint>
#include <cstring>
#include <initializer_list>

namespace reiv { namespace game {
std::uint32_t PlayerPedDestruction::Read(const void* p, std::uint32_t offset) {
        std::uint32_t value;
        std::memcpy(&value, reinterpret_cast<const void*>(reinterpret_cast<std::uintptr_t>(p) + offset), 4);
        return value;
    }

void PlayerPedDestruction::Write(void* p, std::uint32_t offset, std::uint32_t value) {
        std::memcpy(reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(p) + offset), &value, 4);
    }

void* PlayerPedDestruction::Pointer(std::uint32_t value) { return reinterpret_cast<void*>(static_cast<std::uintptr_t>(value)); }

void* PlayerPedDestruction::Member228(void* object) {
        const auto value = Read(object, 0x228);
        return value ? Pointer(value + 0x60u) : nullptr;
    }

    // VA 0x009C1E60, complete body ending in JMP 0x008AC1E0.
    // Requires readable [member228 + 0x3E4/0x3E8], as does the original.
    // The EA8 pointer and member228 are deliberately re-read after callbacks.
void PlayerPedDestruction::Destroy(void* object, const PlayerPedDestructionDependencies& d) {
        auto owned = Read(object, 0xEA8);
        Write(object, 0, d.playerVtable);
        if (owned) {
            d.call8DD270(d.context, Pointer(owned));
            owned = Read(object, 0xEA8);
            if (owned) {
                d.call8DD8B0(d.context, Pointer(owned));
                d.call5B1C10(d.context, Pointer(owned));
            }
            Write(object, 0xEA8, 0);
        }
        for (const std::uint32_t offset : {0x3E4u, 0x3E8u}) {
            const auto handle = Read(Member228(object), offset);
            if (handle) {
                const auto first = d.call92F4D0(d.context, d.load1548F88(d.context), handle);
                const auto second = d.call8631E0(d.context, first);
                d.call9C0A70(d.context, second);
                Write(Member228(object), offset, 0);
            }
        }
        d.call920CD0(d.context, Member228(object), 0);
        d.call4475F0(d.context, reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(object) + 0xEAC));
        d.call8AC1E0(d.context, object);
    }

    // VA 0x009C2260, scalar deleting-destructor wrapper, RET 4.
    // Return is the original pointer, even when the allocator has released it.
void* PlayerPedDestruction::DestroyDeleting(void* object, std::uint32_t flags, const PlayerPedDestructionDependencies& d) {
        Destroy(object, d);
        if (flags & 1u) d.call448300(d.context, d.load18A82AC(d.context), object);
        return object;
    }
} }
