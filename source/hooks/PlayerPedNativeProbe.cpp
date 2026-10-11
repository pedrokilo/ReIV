#include "PlayerPedNativeProbe.h"
// Se compila dentro de core/ReIV.cpp (despues de IVSDK.cpp): el IV-SDK solo admite una unidad de compilacion.

namespace playernativeprobe {
unsigned Resolve(reiv::player_clone::Kind kind,unsigned va) {return resolver.Resolve(kind,va);}

void Report() {
 FILE* file=nullptr;if(fopen_s(&file,hashprobe::GameFile("ReIV-CPlayerPed-native.json").c_str(),"w")||!file)return;
 const LONG calls=InterlockedCompareExchange(&bridge::targetCalls,0,0),selected=InterlockedCompareExchange(&bridge::selected,0,0);
 fprintf(file,"{\"passed\":%s,\"phase\":\"%s\",\"original_calls\":%ld,\"clone_calls\":%ld,\"exceptions\":%ld,\"restored\":%s,\"natural_calls_only\":true,\"external_callees\":\"original game\",\"scope\":\"Update slot29 only; no duplicate stateful comparison\"}",finished&&!failed&&restored&&selected>=64?"true":"false",phase,calls-selected,selected,InterlockedCompareExchange(&bridge::exceptions,0,0),restored?"true":"false");
 fclose(file);
}

bool Restore() {
 bridge::Disable();if(!installed)return restored;
 DWORD old=0;if(!VirtualProtect(const_cast<LONG*>(slot),4,PAGE_READWRITE,&old))return false;
 const LONG expected=reinterpret_cast<LONG>(&bridge::Thunk);
 const LONG previous=InterlockedCompareExchange(slot,reinterpret_cast<LONG>(bridge::originalEntry),expected);
 DWORD ignored=0;const bool protection=slotProtection&&VirtualProtect(const_cast<LONG*>(slot),4,slotProtection,&ignored)!=FALSE;
 restored=previous==expected&&protection;installed=!restored;return restored;
}

bool Install(void* player) {
 std::string error;if(!reiv::player_native::ValidateCurrentGame(resolver,error)){REIV_INFO("Player native resolver rejected: %s",error.c_str());return false;}
 const auto expectedVtable=resolver.Relocated(0xD819C4);
 if(*reinterpret_cast<unsigned*>(player)!=expectedVtable)return false;
 clone=new reiv::player_clone::CoffClone;
 clone->Create(reiv::player_clone::UpdateBody,&Resolve);
 bridge::originalEntry=reinterpret_cast<void*>(resolver.Relocated(0x9C0B00));
 bridge::cloneEntry=clone->Entry();
 bridge::cloneBegin=reinterpret_cast<std::uintptr_t>(bridge::cloneEntry);
 bridge::cloneEnd=bridge::cloneBegin+reiv::player_clone::UpdateBody.size;
 InterlockedExchange(&bridge::targetPlayer,reinterpret_cast<LONG>(player));
 if(!AddVectoredExceptionHandler(1,&bridge::NotifyException))return false;
 slot=reinterpret_cast<volatile LONG*>(expectedVtable+29*4);
 DWORD old=0;if(!VirtualProtect(const_cast<LONG*>(slot),4,PAGE_READWRITE,&old))return false;
 slotProtection=old;
 const LONG previous=InterlockedCompareExchange(slot,reinterpret_cast<LONG>(&bridge::Thunk),reinterpret_cast<LONG>(bridge::originalEntry));
 DWORD ignored=0;const bool protection=VirtualProtect(const_cast<LONG*>(slot),4,old,&ignored)!=FALSE;
 installed=previous==reinterpret_cast<LONG>(bridge::originalEntry);
 if(!installed||!protection){if(installed)Restore();return false;}
 phase="observing_original";return true;
}

void Initialize() {
 enabled=GetFileAttributesA(hashprobe::GameFile("ReIV.player-native-test").c_str())!=INVALID_FILE_ATTRIBUTES;
 if(enabled){Report();REIV_INFO("Native player Update test enabled; waiting for natural calls");}
}

void Tick() {
 if(!enabled||finished||!hashprobe::gameLoaded)return;
 if(!installed){
  auto player=FindPlayerPed();if(!player)return;
  try{if(!Install(player)){failed=finished=true;phase="binding_rejected";Report();return;}}
  catch(const std::exception& e){failed=finished=true;phase="binding_failed";REIV_INFO("Player binding failed: %s",e.what());Restore();Report();return;}
  REIV_INFO("Player Update observer installed on slot29");Report();return;
 }
 const LONG count=InterlockedCompareExchange(&bridge::targetCalls,0,0),selected=InterlockedCompareExchange(&bridge::selected,0,0);
 if(InterlockedCompareExchange(&bridge::exceptions,0,0)){failed=finished=true;phase="exception";Restore();Report();return;}
 if(selected>=64){
  failed=!Restore();finished=true;phase=failed?"restore_failed":"passed";Report();
  REIV_INFO("Native player Update %s: original=%ld reconstructed=%ld restored=%s",failed?"FAILED":"PASSED",count-selected,selected,restored?"yes":"no");return;
 }
 if(count>=32&&!InterlockedCompareExchange(&bridge::enabled,0,0)){
  InterlockedExchange(&bridge::enabled,1);phase="running_reconstruction";REIV_INFO("Player Update reconstruction enabled after %ld natural original calls",count);
 }
 Report();
}

} // namespace playernativeprobe
