#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <wincrypt.h>
#include <cstring>
#include <mutex>
#include "OriginalCall.h"

namespace reiv::original {
namespace {
std::once_flag initializeOnce;
std::uintptr_t moduleBase = 0;
std::uint32_t imageSize = 0;
const char* initializationError = "Original calls have not been initialized";
constexpr unsigned char canonicalHash[] = {
    0xab,0x21,0xc0,0xd9,0x0d,0x2c,0xa1,0xc6,0x97,0x78,0x5a,0xca,0x9d,0xcf,0x44,0x63,
    0x5e,0x1f,0x8d,0x48,0xaa,0x0d,0xf1,0xd7,0x37,0xe9,0x19,0x0b,0xdd,0xf0,0xcb,0x4c
};

bool CanonicalExecutable() {
    wchar_t path[32768]{};
    const DWORD length = GetModuleFileNameW(nullptr, path, 32768);
    if (!length || length >= 32768) return false;
    HANDLE file = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, nullptr,
                             OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) return false;
    HCRYPTPROV provider = 0;
    HCRYPTHASH hash = 0;
    bool valid = CryptAcquireContextW(&provider, nullptr, nullptr, PROV_RSA_AES,
                                     CRYPT_VERIFYCONTEXT) != FALSE;
    if (valid) valid = CryptCreateHash(provider, CALG_SHA_256, 0, 0, &hash) != FALSE;
    unsigned char buffer[65536];
    DWORD count = 0;
    while (valid) {
        if (!ReadFile(file, buffer, sizeof(buffer), &count, nullptr)) { valid = false; break; }
        if (!count) break;
        valid = CryptHashData(hash, buffer, count, 0) != FALSE;
    }
    unsigned char digest[32]{};
    DWORD digestSize = sizeof(digest);
    if (valid) valid = CryptGetHashParam(hash, HP_HASHVAL, digest, &digestSize, 0) != FALSE;
    valid = valid && digestSize == sizeof(canonicalHash) &&
            std::memcmp(digest, canonicalHash, sizeof(digest)) == 0;
    if (hash) CryptDestroyHash(hash);
    if (provider) CryptReleaseContext(provider, 0);
    CloseHandle(file);
    return valid;
}
}

bool Initialize() {
    std::call_once(initializeOnce, [] {
        if (!CanonicalExecutable()) {
            initializationError = "Original calls disabled: host EXE does not match the canonical GTA IV 1.0.7.0 SHA-256";
            return;
        }
        const auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr));
        const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
        if (dos->e_magic != IMAGE_DOS_SIGNATURE) { initializationError = "Invalid DOS header"; return; }
        const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS32*>(base + dos->e_lfanew);
        if (nt->Signature != IMAGE_NT_SIGNATURE || nt->FileHeader.Machine != IMAGE_FILE_MACHINE_I386 ||
            nt->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
            initializationError = "Original calls require a PE32 x86 executable";
            return;
        }
        imageSize = nt->OptionalHeader.SizeOfImage;
        moduleBase = base;
        initializationError = "none";
    });
    return moduleBase != 0;
}

const char* LastError() { return initializationError; }

std::uintptr_t ResolveAddress(const FunctionAddress& function) {
    if (!Initialize() || function.state == BindingState::Unbound ||
        !function.expectedBytes || !function.expectedSize ||
        function.rva >= imageSize || function.expectedSize > imageSize - function.rva) return 0;
    const auto address = moduleBase + function.rva;
    MEMORY_BASIC_INFORMATION info{};
    if (!VirtualQuery(reinterpret_cast<const void*>(address), &info, sizeof(info)) ||
        info.State != MEM_COMMIT || info.AllocationBase != reinterpret_cast<void*>(moduleBase) ||
        (info.Protect & (PAGE_GUARD | PAGE_NOACCESS))) return 0;
    const DWORD protection = info.Protect & 0xff;
    // PAGE_EXECUTE alone does not grant readable memory for the byte check.
    if (protection != PAGE_EXECUTE_READ && protection != PAGE_EXECUTE_READWRITE &&
        protection != PAGE_EXECUTE_WRITECOPY) return 0;
    const auto regionEnd = reinterpret_cast<std::uintptr_t>(info.BaseAddress) + info.RegionSize;
    if (function.expectedSize > regionEnd - address ||
        std::memcmp(reinterpret_cast<const void*>(address), function.expectedBytes, function.expectedSize)) return 0;
    return address;
}
}
