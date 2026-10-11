#pragma once
#include <cstdint>

namespace reiv {
// PC 1.0.7.0: RVA 0x1b1c30. The second argument is a seed VALUE.
std::uint32_t AtStringHash(const char* text, std::uint32_t seed);
}
