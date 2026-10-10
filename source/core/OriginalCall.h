#pragma once
#include <cstddef>
#include <cstdint>
#include <type_traits>

#if !defined(_M_IX86)
#error Original game calls require MSVC x86.
#endif

namespace reiv::original {
enum class BindingState { Unbound, StaticVerified, RuntimeVerified, Reconstructed };

struct FunctionAddress {
    const char* name;
    std::uint32_t rva;
    const unsigned char* expectedBytes;
    std::size_t expectedSize;
    BindingState state;
};

// Validates the host EXE's canonical SHA-256 before exposing any addresses.
bool Initialize();
const char* LastError();
std::uintptr_t ResolveAddress(const FunctionAddress& function);

template<typename Return, typename... Args>
using Cdecl = Return(__cdecl*)(Args...);
template<typename Return, typename... Args>
using Stdcall = Return(__stdcall*)(Args...);
template<typename Return, typename Object, typename... Args>
using Thiscall = Return(__thiscall*)(Object*, Args...);

template<typename Function>
Function Resolve(const FunctionAddress& function) {
    static_assert(std::is_pointer_v<Function> &&
                  std::is_function_v<std::remove_pointer_t<Function>>,
                  "Use a function pointer with an explicit calling convention.");
    return reinterpret_cast<Function>(ResolveAddress(function));
}
}
