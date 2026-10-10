#pragma once
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <vector>
#include <stdexcept>

namespace reiv::player_clone {
enum class Kind : unsigned { Global, Object, Call, Table, Label };
struct Relocation { unsigned offset; Kind kind; unsigned va, value, addend; };
struct Body { const unsigned char* bytes; unsigned size; const Relocation* relocations; unsigned count, entry; };
using Resolver = unsigned (*)(Kind,unsigned);

// Loader for compiled-source COFF templates; never reads an original game body.
// Resolver returns global/object addresses or raw callback entry addresses.
// Each clone owns immutable callback cells and local jump tables.
class CoffClone {
    unsigned char* code_ = nullptr;
    unsigned char* data_ = nullptr;
    unsigned entry_ = 0;
    bool ready_ = false;
    std::vector<unsigned> calls_, tables_;
    static unsigned Address(const void* p) { return static_cast<unsigned>(reinterpret_cast<std::uintptr_t>(p)); }
    static void Put(unsigned char* p,unsigned x) { std::memcpy(p,&x,4); }
    static unsigned Index(std::vector<unsigned>& keys,unsigned key) {
        for(unsigned i=0;i<keys.size();++i)if(keys[i]==key)return i;
        keys.push_back(key);return static_cast<unsigned>(keys.size()-1);
    }
public:
    CoffClone() = default;
    CoffClone(const CoffClone&) = delete;
    CoffClone& operator=(const CoffClone&) = delete;
    ~CoffClone(){if(code_)VirtualFree(code_,0,MEM_RELEASE);if(data_)VirtualFree(data_,0,MEM_RELEASE);}
    void Create(const Body& body,Resolver resolve) {
        if(sizeof(void*)!=4||code_||!resolve||!body.bytes||!body.relocations||body.size<4||body.size>4096||body.entry>=body.size)
            throw std::runtime_error("Invalid clone contract");
        std::vector<bool> covered(body.size,false);
        for(unsigned i=0;i<body.count;++i){
            const auto& r=body.relocations[i];
            if(r.offset>body.size-4)throw std::runtime_error("Relocation outside code");
            for(unsigned j=0;j<4;++j){if(covered[r.offset+j])throw std::runtime_error("Overlapping relocation");covered[r.offset+j]=true;}
            if(r.kind==Kind::Call)Index(calls_,r.va);
            else if(r.kind==Kind::Table){Index(tables_,r.va);if(r.addend>12||r.addend%4)throw std::runtime_error("Invalid table addend");}
            else if(r.kind==Kind::Label){if(r.value>=body.size||r.value<body.entry||r.addend)throw std::runtime_error("Invalid local label");}
            else if(r.kind!=Kind::Global&&r.kind!=Kind::Object)throw std::runtime_error("Unknown relocation kind");
        }
        if(calls_.size()*4+tables_.size()*16>4096)throw std::runtime_error("Binding storage overflow");
        code_=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
        data_=static_cast<unsigned char*>(VirtualAlloc(nullptr,4096,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
        if(!code_||!data_)throw std::runtime_error("Allocation failed");
        std::memcpy(code_,body.bytes,body.size);entry_=body.entry;
        for(unsigned i=0;i<calls_.size();++i){unsigned target=resolve(Kind::Call,calls_[i]);if(!target)throw std::runtime_error("Unresolved callback");Put(data_+i*4,target);}
        const auto tableAddress=[&](const Relocation& r){return data_+calls_.size()*4+Index(tables_,r.va)*16+r.addend;};
        for(unsigned i=0;i<body.count;++i){
            const auto& r=body.relocations[i];unsigned target=0;
            if(r.kind==Kind::Call)target=Address(data_+Index(calls_,r.va)*4);
            else if(r.kind==Kind::Table)target=Address(tableAddress(r))-r.addend;
            else if(r.kind==Kind::Label){
                target=Address(code_)+r.value;
                // Verified Select prefix consists of LEA label / MOV table pairs.
                if(r.offset<body.entry){
                    if(i+1>=body.count||body.relocations[i+1].kind!=Kind::Table||body.relocations[i+1].offset>=body.entry)
                        throw std::runtime_error("Unrecognized jump-table initialization");
                    Put(tableAddress(body.relocations[i+1]),target);
                }
            }else target=resolve(r.kind,r.va);
            if(!target||target>UINT32_MAX-r.addend)throw std::runtime_error("Unresolved or overflowing address");
            Put(code_+r.offset,target+r.addend);
        }
        DWORD old;
        if(!VirtualProtect(code_,4096,PAGE_EXECUTE_READ,&old)||!VirtualProtect(data_,4096,PAGE_READONLY,&old)||!FlushInstructionCache(GetCurrentProcess(),code_,4096))
            throw std::runtime_error("Protection/publication failed");
        ready_=true;
    }
    void* Entry() const { if(!ready_)throw std::runtime_error("Clone not published");return code_+entry_; }
    bool Immutable() const {
        MEMORY_BASIC_INFORMATION c{},d{};
        return VirtualQuery(code_,&c,sizeof c)&&VirtualQuery(data_,&d,sizeof d)&&c.Protect==PAGE_EXECUTE_READ&&d.Protect==PAGE_READONLY;
    }
    std::vector<unsigned char> BindingSnapshot() const { return std::vector<unsigned char>(data_,data_+4096); }
};
}
