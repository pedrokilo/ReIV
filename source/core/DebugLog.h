#pragma once
namespace reiv::debug {
enum class Level { Info, Debug, Warning, Error };
void Initialize();
void Write(Level level, const char* file, int line, const char* format, ...);
void Observe(const char* function, bool addressChecked, bool installed);
}
#define REIV_INFO(...) reiv::debug::Write(reiv::debug::Level::Info, __FILE__, __LINE__, __VA_ARGS__)
#define REIV_DEBUG(...) reiv::debug::Write(reiv::debug::Level::Debug, __FILE__, __LINE__, __VA_ARGS__)
