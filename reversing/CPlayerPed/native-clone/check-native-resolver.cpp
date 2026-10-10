#include "native-validation.h"
#include <cstdio>
namespace N=reiv::player_native;
int main(){
 unsigned checks=0;std::string hash;
 if(!N::SupportedLiveImageBase(0x400000,0xC20000)||!N::SupportedLiveImageBase(0xC20000,0xC20000)||N::SupportedLiveImageBase(0x500000,0xC20000)||N::SupportedLiveImageBase(0x400000,0))return 6;checks+=4;
 if(!N::SupportedLiveImageBase(0x400000,0x400000)||N::SupportedLiveImageBase(0,0xC20000)||N::SupportedLiveImageBase(0x400000,0x100000000ull))return 7;checks+=3;
 if(!N::FileSha256(L"D:\\GTA IV\\Grand Theft Auto IV\\GTAIV.exe",hash)||hash!=N::SupportedSha256)return 1;++checks;
 if(N::FileSha256(L"D:\\GTA IV\\ReIV\\build\\privateNativeBinding\\not-present.exe",hash))return 2;++checks;
 N::ValidatedResolver r;std::string error;
 if(r.Ready()||r.Resolve(reiv::player_clone::Kind::Call,0x9C0B00)||r.Mapped(0x9C0B00,16,true))return 3;++checks;
 if(N::ValidateCurrentGame(r,error)||r.Ready()||error!="Unsupported executable SHA256")return 4;++checks;
 for(unsigned va:{0u,0x3FFFFFu,0xFFFFFFFFu}){if(r.Relocated(va)||r.Resolve(reiv::player_clone::Kind::Global,va))return 5;++checks;}
 std::printf("PASS native_resolver_checks=%u exact_file_sha_verified=1 non_game_process_rejected=1 game_runtime_validated=0\n",checks);
}
