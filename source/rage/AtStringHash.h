#pragma once
#include <cstdint>

namespace reiv {
// PC 1.0.7.0: RVA 0x1b1c30. The second argument is a seed VALUE.
inline std::uint32_t AtStringHash(const char* text, std::uint32_t seed) {
    const bool quoted = *text == '"';
    if (quoted) ++text;
    while (*text != '\0') {
        unsigned char byte = static_cast<unsigned char>(*text++);
        if (quoted && byte == '"') break;
        if (byte >= 'A' && byte <= 'Z') byte += 'a' - 'A';
        else if (byte == '\\') byte = '/';
        // MOVSX in the original: bytes >= 0x80 are sign-extended.
        const auto value = byte < 128 ? static_cast<std::int32_t>(byte)
                                    : static_cast<std::int32_t>(byte) - 256;
        seed = (seed + static_cast<std::uint32_t>(value)) * 1025u;
        seed ^= seed >> 6;
    }
    seed *= 9u;
    seed ^= seed >> 11;
    return seed * 32769u;
}
}
