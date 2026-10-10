#pragma once
#include <cstdint>

namespace reiv::memory_map {
// Inventory only. No callable signature, patch or automatic installation.
enum class AddressOrigin { VirtualSlot, SdkFunctionReference };
struct PendingHook {
    std::uint32_t va;
    std::uint32_t rva;
    std::uint32_t vtableVa; // Zero for non-virtual SDK references.
    int slot;               // -1 for non-virtual SDK references.
    const char* label;
    const char* nameCandidates;
    const char* evidence;
    AddressOrigin origin;
    bool runtimeReferenceTested;
    bool enabled = false;
    bool reconstructed = false;
};
}
