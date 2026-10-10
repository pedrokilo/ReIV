#pragma once
#include "CoffClone.h"
#include <wincrypt.h>
#include <string>
#include <array>
#include <limits>
#include <cstdio>
#include <cstddef>
#pragma comment(lib,"advapi32.lib")
namespace reiv::player_native {
inline constexpr char SupportedSha256[]="ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c";
// The supported disk image has preferred base 0x400000. The observed loader
// rewrites the mapped header ImageBase to the actual module base under ASLR.
// Invoke only after the exact canonical disk SHA has been established.
inline bool SupportedLiveImageBase(std::uint32_t imageBase,std::uint64_t loadedBase){
 return loadedBase!=0&&loadedBase<=UINT32_MAX&&(imageBase==0x400000||imageBase==loadedBase);
}
inline bool FileSha256(const wchar_t* path,std::string& hex){
 HCRYPTPROV provider=0;HCRYPTHASH hash=0;HANDLE file=INVALID_HANDLE_VALUE;bool ok=false;
 do{
  if(!CryptAcquireContextW(&provider,nullptr,nullptr,PROV_RSA_AES,CRYPT_VERIFYCONTEXT))break;
  if(!CryptCreateHash(provider,CALG_SHA_256,0,0,&hash))break;
  file=CreateFileW(path,GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_DELETE,nullptr,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,nullptr);
  if(file==INVALID_HANDLE_VALUE)break;
  unsigned char block[65536];DWORD read=0;bool readOK=true;
  while(true){if(!ReadFile(file,block,sizeof block,&read,nullptr)){readOK=false;break;}if(!read)break;if(!CryptHashData(hash,block,read,0)){readOK=false;break;}}
  if(!readOK)break;
  unsigned char bytes[32];DWORD length=sizeof bytes;
  if(!CryptGetHashParam(hash,HP_HASHVAL,bytes,&length,0)||length!=32)break;
  constexpr char digits[]="0123456789abcdef";hex.clear();for(auto b:bytes){hex+=digits[b>>4];hex+=digits[b&15];}ok=true;
 }while(false);
 if(file!=INVALID_HANDLE_VALUE)CloseHandle(file);if(hash)CryptDestroyHash(hash);if(provider)CryptReleaseContext(provider,0);return ok;
}
struct Operand { unsigned offset,va; };
struct ExpectedBody { unsigned va;const unsigned char* bytes;unsigned length;const Operand* absolute;unsigned absoluteCount; };
using ExpectedEntry = ExpectedBody;
struct AllowedReference { player_clone::Kind kind;unsigned va,width; };

class ValidatedResolver {
 std::uintptr_t base_=0;unsigned size_=0;bool ready_=false;
 std::vector<unsigned> calls_;
 std::vector<AllowedReference> data_;
public:
 // Validate the current game's exact on-disk executable plus mapped bodies and
 // callee entries. Expected arrays are canonical validation data only.
 bool Open(const ExpectedBody* bodies,unsigned bodyCount,const ExpectedEntry* entries,unsigned entryCount,const AllowedReference* references,unsigned referenceCount,std::string& error){
  if(ready_){error="Resolver already published";return false;}
  auto module=GetModuleHandleW(nullptr);wchar_t path[32768];auto length=GetModuleFileNameW(module,path,32768);
  std::string hash;if(!length||length>=32768||!FileSha256(path,hash)||hash!=SupportedSha256){error="Unsupported executable SHA256";return false;}
  base_=reinterpret_cast<std::uintptr_t>(module);
  auto dos=reinterpret_cast<const IMAGE_DOS_HEADER*>(base_);
  if(dos->e_magic!=IMAGE_DOS_SIGNATURE||dos->e_lfanew<=0||dos->e_lfanew>4096){error="Invalid image header";return false;}
  auto nt=reinterpret_cast<const IMAGE_NT_HEADERS32*>(base_+dos->e_lfanew);
  if(nt->Signature!=IMAGE_NT_SIGNATURE||nt->FileHeader.Machine!=IMAGE_FILE_MACHINE_I386||nt->OptionalHeader.Magic!=IMAGE_NT_OPTIONAL_HDR32_MAGIC||!SupportedLiveImageBase(nt->OptionalHeader.ImageBase,base_)){
   unsigned rawSignature=0,rawImageBase=0;unsigned short rawMachine=0,rawMagic=0,rawOptionalSize=0;
   const auto raw=reinterpret_cast<const unsigned char*>(nt);
   std::memcpy(&rawSignature,raw,4);std::memcpy(&rawMachine,raw+4,2);std::memcpy(&rawOptionalSize,raw+20,2);std::memcpy(&rawMagic,raw+24,2);std::memcpy(&rawImageBase,raw+52,4);
   char diagnostic[512];std::snprintf(diagnostic,sizeof diagnostic,"Unsupported image format: loadedBase=%08X e_lfanew=%X signature=%08X machine=%04X magic=%04X ImageBase=%08X sizeofNT=%u fileHeaderOffset=%u optionalOffset=%u optionalSize=%u rawSignature=%08X rawMachine=%04X rawMagic=%04X rawImageBase=%08X rawOptionalSize=%u",static_cast<unsigned>(base_),static_cast<unsigned>(dos->e_lfanew),nt->Signature,nt->FileHeader.Machine,nt->OptionalHeader.Magic,nt->OptionalHeader.ImageBase,static_cast<unsigned>(sizeof(IMAGE_NT_HEADERS32)),static_cast<unsigned>(offsetof(IMAGE_NT_HEADERS32,FileHeader)),static_cast<unsigned>(offsetof(IMAGE_NT_HEADERS32,OptionalHeader)),nt->FileHeader.SizeOfOptionalHeader,rawSignature,rawMachine,rawMagic,rawImageBase,rawOptionalSize);
   error=diagnostic;return false;
  }
  size_=nt->OptionalHeader.SizeOfImage;
  if(!bodies||!bodyCount||!entries||!entryCount||!references||!referenceCount){error="Missing validation manifest";return false;}
  for(unsigned i=0;i<bodyCount;++i){const auto& b=bodies[i];auto address=Mapped(b.va,b.length,true);if(!address||!b.bytes||!b.length){error="Invalid body mapping";return false;}
   std::vector<unsigned char> expected(b.bytes,b.bytes+b.length);
   for(unsigned j=0;j<b.absoluteCount;++j){const auto& p=b.absolute[j];if(b.length<4||p.offset>b.length-4){error="Invalid body operand";return false;}unsigned relocated=Relocated(p.va);if(!relocated){error="Invalid operand address";return false;}std::memcpy(expected.data()+p.offset,&relocated,4);}
   if(std::memcmp(reinterpret_cast<void*>(address),expected.data(),b.length)){error="Mapped reconstructed-target body differs";return false;}
  }
  for(unsigned i=0;i<entryCount;++i){const auto& e=entries[i];auto address=Mapped(e.va,e.length,true);if(!address||!e.bytes||!e.length){error="Invalid external callee mapping";return false;}
   std::vector<unsigned char> expected(e.bytes,e.bytes+e.length);
   for(unsigned j=0;j<e.absoluteCount;++j){const auto& p=e.absolute[j];if(e.length<4||p.offset>e.length-4){error="Invalid callee operand";return false;}unsigned relocated=Relocated(p.va);if(!relocated){error="Invalid callee operand address";return false;}std::memcpy(expected.data()+p.offset,&relocated,4);}
   if(std::memcmp(reinterpret_cast<void*>(address),expected.data(),e.length)){error="Mapped external callee differs";return false;}
  }
  auto slot=Mapped(0xD819C4+29*4,4,false);unsigned expected=Relocated(0x9C0B00);
  if(!slot||!expected||*reinterpret_cast<const unsigned*>(slot)!=expected){error="Player vtable slot29 differs";return false;}
  std::vector<AllowedReference> verifiedData;
  for(unsigned i=0;i<referenceCount;++i){const auto& r=references[i];if((r.kind!=player_clone::Kind::Global&&r.kind!=player_clone::Kind::Object)||!r.width||!Mapped(r.va,r.width,false)){error="Invalid data reference manifest";return false;}verifiedData.push_back(r);}
  std::vector<unsigned> verifiedCalls;for(unsigned i=0;i<entryCount;++i)verifiedCalls.push_back(entries[i].va);
  calls_=std::move(verifiedCalls);data_=std::move(verifiedData);
  ready_=true;return true;
 }
 unsigned Relocated(unsigned va) const {if(va<0x400000||va-0x400000>=size_||base_>UINT32_MAX-(va-0x400000))return 0;return static_cast<unsigned>(base_+va-0x400000);}
 unsigned Mapped(unsigned va,unsigned length,bool executable) const {
  unsigned address=Relocated(va);if(!address||!length||length>size_-(va-0x400000))return 0;
  std::uintptr_t cursor=address,end=cursor+length;
  while(cursor<end){MEMORY_BASIC_INFORMATION m{};if(!VirtualQuery(reinterpret_cast<void*>(cursor),&m,sizeof m)||m.State!=MEM_COMMIT||m.Type!=MEM_IMAGE||reinterpret_cast<std::uintptr_t>(m.AllocationBase)!=base_||m.Protect&(PAGE_GUARD|PAGE_NOACCESS))return 0;
   const auto protection=m.Protect&0xFF;
   if(executable&&protection!=PAGE_EXECUTE_READ&&protection!=PAGE_EXECUTE_READWRITE&&protection!=PAGE_EXECUTE_WRITECOPY)return 0;
   if(!executable&&protection!=PAGE_READONLY&&protection!=PAGE_READWRITE&&protection!=PAGE_WRITECOPY&&protection!=PAGE_EXECUTE_READ&&protection!=PAGE_EXECUTE_READWRITE&&protection!=PAGE_EXECUTE_WRITECOPY)return 0;
   auto next=reinterpret_cast<std::uintptr_t>(m.BaseAddress)+m.RegionSize;if(next<=cursor)return 0;cursor=next;
  }
  return address;
 }
 unsigned Resolve(player_clone::Kind kind,unsigned va) const {
  if(!ready_)return 0;
  if(kind==player_clone::Kind::Call){for(auto allowed:calls_)if(allowed==va)return Mapped(va,16,true);return 0;}
  for(auto allowed:data_)if(allowed.kind==kind&&allowed.va==va)return Mapped(va,allowed.width,false);
  return 0;
 }
 bool Ready() const{return ready_;}
};
}
