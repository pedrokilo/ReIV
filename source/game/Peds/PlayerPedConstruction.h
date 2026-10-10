#pragma once
#include <cstdint>
#include <cstring>

namespace reiv { namespace game {
// Original RVA 0x005C1910. Algorithm with explicit dependency contracts.
// These callbacks describe used arguments, not complete native subsystem ABIs.
// No live constructor replacement is installed and no sizeof is declared.
// Global/address callbacks are pure memory/address access: they must not alter
// other memory, FP state, or call subsystems. Callee callbacks may mutate state.
struct PlayerPedConstructionDependencies {
    std::uint32_t (*readGlobal32)(std::uint32_t va);
    void (*writeGlobal32)(std::uint32_t va, std::uint32_t value);
    void (*writeGlobal8)(std::uint32_t va, std::uint8_t value);
    std::uint32_t (*address)(std::uint32_t canonicalVa);
    void (*base8ABF10)(void*, std::uint32_t, std::uint32_t);
    void (*embeddedC68B50)(void*);
    void (*embedded4475C0)(void*);
    void (*blockB2A8F0)(void*, std::uint32_t);
    void (*blockB29E50)(void*);
    void* (*resolve817F20)(std::uint32_t);
    void (*link920CD0)(void*, void*);
    void (*link921050)(void*);
    void (*initialize9BE4C0)(void*);
    std::uint32_t (*randomD0D21A)();
    std::uint32_t (*hash8631E0)(std::uint32_t);
    void (*value447610)(void*, std::uint32_t);
    void (*flags89E5A0)(void*, std::uint32_t);
    void (*reset9720E0)(void*);
    std::uint32_t (*index797D70)();
    void (*sendMessageA)(std::uint32_t, std::uint32_t, std::uint32_t, std::uint32_t);
    void* (*allocate4011D0)(std::uint32_t);
    void* (*create8DA9A0)(void*);
    std::uint8_t (*flag878A00)(void*);
};

class PlayerPedConstruction {    static std::uint32_t R(const void* p, std::uint32_t off);    static void W(void* p, std::uint32_t off, std::uint32_t value);    static void B(void* p, std::uint32_t off, std::uint8_t value);    static std::uint8_t Byte(const void* p, std::uint32_t off);    static std::uint32_t Bits(const void* p);    static void* P(std::uint32_t bits);    static void* Add(void* p, std::uint32_t off);    static void* LinkReceiver(void* player);
    // FLD/FSTP keeps original single-precision conversion behavior for NaNs.
    static std::uint32_t LoadStoreX87(std::uint32_t bits);public:

    // Exactly the original x87 arithmetic and saved-control-word sequence.
    // Isolated for independent FPU-state comparison; MSVC x86 only.
    static std::uint32_t RandomOffset(std::uint32_t random, std::uint32_t scaleBits, std::uint32_t rangeBits);    static void* Construct(void* player, std::uint32_t a1, std::uint32_t a2, std::uint32_t a3,
                           const PlayerPedConstructionDependencies& d);

};
} }
