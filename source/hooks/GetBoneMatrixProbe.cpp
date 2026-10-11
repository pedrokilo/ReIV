#include "GetBoneMatrixProbe.h"
// Se compila dentro de core/ReIV.cpp (despues de IVSDK.cpp): el IV-SDK solo admite una unidad de compilacion.

namespace boneprobe {
void Report(const char* phase) {
    FILE* file = nullptr;
    if (fopen_s(&file, hashprobe::GameFile("ReIV-GetBoneMatrix.json").c_str(), "w") || !file) return;
    fprintf(file, "{\n  \"phase\": \"%s\",\n  \"rva\": \"0x005c7710\",\n"
        "  \"bone_index\": 0,\n  \"calls\": %u,\n  \"failures\": %u,\n"
        "  \"exceptions\": %u,\n  \"ticks\": %u,\n  \"entity\": \"0x%08X\",\n"
        "  \"matrix\": \"0x%08X\",\n  \"position\": [%.9g, %.9g, %.9g],\n"
        "  \"game_loaded\": %s,\n  \"ingame_started\": %s\n}\n",
        phase, calls, failures, exceptions, ticks, static_cast<unsigned>(lastEntity),
        static_cast<unsigned>(lastMatrix), lastPosition[0], lastPosition[1], lastPosition[2],
        hashprobe::gameLoaded ? "true" : "false", hashprobe::ingameStarted ? "true" : "false");
    fclose(file);
}

int Check(CPed* ped) {
    __try {
        auto entity = static_cast<::CDynamicEntity*>(ped);
        auto matrix = reiv::game::CDynamicEntity::GetBoneMatrix(entity, 0);
        auto sdkMatrix = entity->GetBoneMatrix(0);
        lastEntity = reinterpret_cast<std::uintptr_t>(entity);
        lastMatrix = reinterpret_cast<std::uintptr_t>(matrix);
        if (!matrix || matrix != sdkMatrix ||
            lastMatrix == reinterpret_cast<std::uintptr_t>(GetModuleHandleW(nullptr)) + 0x01239460u) return 1;
        const CVector_pad* rows[] = {&matrix->right, &matrix->up, &matrix->at, &matrix->pos};
        for (auto row : rows) {
            if (!std::isfinite(row->x) || !std::isfinite(row->y) || !std::isfinite(row->z)) return 2;
        }
        lastPosition[0] = matrix->pos.x;
        lastPosition[1] = matrix->pos.y;
        lastPosition[2] = matrix->pos.z;
        if (std::fabs(matrix->pos.x) + std::fabs(matrix->pos.y) + std::fabs(matrix->pos.z) < 0.001f) return 3;
        return 0;
    } __except(EXCEPTION_EXECUTE_HANDLER) { return 4; }
}

void Initialize() {
    enabled = GetFileAttributesA(hashprobe::GameFile("ReIV.original-calls-test").c_str()) != INVALID_FILE_ATTRIBUTES;
    if (enabled) { started = GetTickCount64(); Report("waiting_for_player"); REIV_DEBUG("GetBoneMatrix test enabled: waiting for a live player"); }
}

void Tick() {
    if (!enabled || closeRequested) return;
    ++ticks;
    if (!completed && calls < 64 && hashprobe::gameLoaded && ticks % 3 == 0) {
        auto ped = FindPlayerPed();
        if (ped && reiv::game::CDynamicEntity::OriginalAvailable()) {
            ++calls;
            const int result = Check(ped);
            if (result) ++failures;
            if (result == 4) ++exceptions;
            Report("sampling");
            if (failures || calls == 64) { completed = GetTickCount64(); Report(failures ? "failed" : "passed"); REIV_INFO("GetBoneMatrix %s | calls=%u failures=%u exceptions=%u | entity=0x%08X matrix=0x%08X", failures ? "FAILED" : "PASSED", calls, failures, exceptions, static_cast<unsigned>(lastEntity), static_cast<unsigned>(lastMatrix)); }
        }
    }
    if (ticks % 300 == 0 && !completed) Report("waiting_for_player");
    if ((completed && GetTickCount64() - completed > 2000) || GetTickCount64() - started > 180000) {
        closeRequested = true;
        Report(calls == 64 && !failures ? "passed" : "failed");
        PostMessageA(rage::g_pHWND, WM_CLOSE, 0, 0);
    }
}

} // namespace boneprobe
