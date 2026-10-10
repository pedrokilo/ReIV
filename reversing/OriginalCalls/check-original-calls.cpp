#include "../../source/core/OriginalCall.h"
#include "../../source/game/scene/CDynamicEntity.h"
#include <cstdio>
#include <cstring>

namespace {
int __cdecl CdeclProbe(int a, int b) { return a + b; }
int __stdcall StdcallProbe(int a, int b) { return a * b; }
struct Instance {
    int value = 37;
    __declspec(noinline) int Method(int increment) { return value + increment; }
};
}

int main() {
    reiv::original::Cdecl<int, int, int> cdeclFunction = &CdeclProbe;
    reiv::original::Stdcall<int, int, int> stdcallFunction = &StdcallProbe;
    if (cdeclFunction(7, 5) != 12 || stdcallFunction(7, 5) != 35) return 1;
    auto member = &Instance::Method;
    reiv::original::Thiscall<int, Instance, int> thiscallFunction = nullptr;
    static_assert(sizeof(member) == sizeof(thiscallFunction));
    std::memcpy(&thiscallFunction, &member, sizeof(member));
    Instance instance;
    for (int i = 0; i < 10000; ++i) {
        if (thiscallFunction(&instance, i) != 37 + i) return 2;
        if (cdeclFunction(i, 5) != i + 5 || stdcallFunction(i, 5) != i * 5) return 3;
    }
    // This test host is not GTAIV.exe; no game RVA may resolve in it.
    if (reiv::original::Initialize()) return 4;
    unsigned char byte = 0;
    const reiv::original::FunctionAddress probe = {
        "must_reject", 0x005c7710u, &byte, 1,
        reiv::original::BindingState::StaticVerified
    };
    if (reiv::original::ResolveAddress(probe) != 0) return 5;
    if (reiv::game::CDynamicEntity::OriginalAvailable()) return 6;
    if (reiv::game::CDynamicEntity::GetBoneMatrix(nullptr, 0) != nullptr) return 7;
    // Non-null opaque object must also be rejected before any original call.
    if (reiv::game::CDynamicEntity::GetBoneMatrix(
        reinterpret_cast<::CDynamicEntity*>(&instance), 0) != nullptr) return 8;
    std::printf("PASS: x86 cdecl/stdcall/thiscall, repeated calls, wrong-host rejection, null/unbound wrapper\n");
    return 0;
}
