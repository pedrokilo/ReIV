"""Read-only PE/RTTI/SDK inventory. No reconstruction, hooks or game launch."""
from __future__ import annotations
import argparse, base64, csv, gzip, hashlib, json, re, struct
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CANONICAL = 'ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c'
def hx(n): return f'0x{n:08x}'
def write_csv(path, rows, fields):
    with path.open('w', encoding='utf-8', newline='') as file:
        out = csv.DictWriter(file, fieldnames=fields, extrasaction='ignore')
        out.writeheader(); out.writerows(rows)

class PE:
    def __init__(self, path):
        self.data = path.read_bytes()
        if hashlib.sha256(self.data).hexdigest() != CANONICAL: raise ValueError('EXE no canónico')
        pe = struct.unpack_from('<I', self.data, 60)[0]
        if self.data[:2] != b'MZ' or self.data[pe:pe+4] != b'PE\0\0': raise ValueError('PE inválido')
        machine, count = struct.unpack_from('<HH', self.data, pe+4)
        opt_size = struct.unpack_from('<H', self.data, pe+20)[0]
        if machine != 0x14c: raise ValueError('No es x86')
        self.base = struct.unpack_from('<I', self.data, pe+52)[0]
        self.sections = []
        for i in range(count):
            pos = pe+24+opt_size+i*40
            name = self.data[pos:pos+8].split(b'\0')[0].decode('ascii', 'replace')
            vs, rva, raw_size, raw = struct.unpack_from('<IIII', self.data, pos+8)
            flags = struct.unpack_from('<I', self.data, pos+36)[0]
            self.sections.append(dict(name=name, rva=rva, va=self.base+rva, virtual_size=vs,
                raw_size=raw_size, raw_offset=raw, executable=bool(flags & 0x20000000),
                writable=bool(flags & 0x80000000), readable=bool(flags & 0x40000000)))
    def section(self, va):
        return next((s for s in self.sections if s['va'] <= va < s['va']+max(s['virtual_size'],s['raw_size'])), None)
    def offset(self, va, length=1):
        s = self.section(va)
        if s and va-s['va']+length <= s['raw_size']: return s['raw_offset']+va-s['va']
        return None
    def file_va(self, pos):
        s = next((s for s in self.sections if s['raw_offset'] <= pos < s['raw_offset']+s['raw_size']), None)
        return s['va']+pos-s['raw_offset'] if s else None
    def words(self, va, count):
        pos = self.offset(va, count*4)
        return struct.unpack_from('<'+'I'*count, self.data, pos) if pos is not None else None
    def code(self, va):
        s = self.section(va)
        return bool(s and s['executable'] and self.offset(va) is not None)
    def pointers(self):
        for s in self.sections:
            if s['executable']: continue
            data = self.data[s['raw_offset']:s['raw_offset']+s['raw_size']//4*4]
            for i, (value,) in enumerate(struct.iter_unpack('<I', data)):
                yield s['va']+i*4, value

def read_ghidra(pe, directory):
    functions = []
    with (directory/'ghidra_functions.csv').open(encoding='utf-8-sig', newline='') as file:
        for row in csv.DictReader(file):
            va = int(row['va'],16)
            if not pe.code(va): continue
            row.update(rva=hx(va-pe.base), section=pe.section(va)['name'], status='ghidra_candidate')
            functions.append(row)
    symbols = {}
    with (directory/'ghidra_symbols.csv').open(encoding='utf-8-sig', newline='') as file:
        for row in csv.DictReader(file):
            va = int(row['va'],16)
            if pe.section(va) and row['source'] != 'DEFAULT': symbols[va] = row['name']
    return functions, symbols

def rtti_map(pe, symbols):
    classes = {}
    for match in re.finditer(rb'\.\?A[UV][^\x00\r\n]{1,500}@@\x00',pe.data):
        va = pe.file_va(match.start()-8)
        if va is None or va % 4: continue
        words = pe.words(va,2)
        if not words or words[1] != 0 or not pe.section(words[0]): continue
        mangled = match.group()[:-1].decode('ascii','replace')
        label = symbols.get(va,'')
        if label.endswith('::RTTI_Type_Descriptor'): name = label[:-len('::RTTI_Type_Descriptor')]
        elif '?$' not in mangled: name = '::'.join(reversed(mangled[4:-2].split('@')))
        else: name = mangled
        classes[va] = dict(name=name,mangled=mangled,kind='class' if mangled[3]=='V' else 'struct',
            type_descriptor_va=hx(va),type_descriptor_rva=hx(va-pe.base),
            status='exe_rtti_type',section=pe.section(va)['name'], locators=[],vtables=[],bases=[])
    locators = {}
    for reference, value in pe.pointers():
        if value not in classes: continue
        col = reference-12
        words = pe.words(col,5)
        if not words: continue
        signature, displacement, constructor_disp, td, chd = words
        if signature != 0 or displacement > 0x100000 or constructor_disp > 0x100000: continue
        hierarchy = pe.words(chd,4)
        if not hierarchy: continue
        hs, attributes, count, base_array = hierarchy
        if hs != 0 or attributes > 0xff or not 1 <= count <= 4096: continue
        base_pointers = pe.words(base_array,count)
        if not base_pointers: continue
        base_entries = []
        for bcd in base_pointers:
            entry = pe.words(bcd,6)
            if not entry or entry[0] not in classes: break
            base_entries.append(classes[entry[0]]['name'])
        else:
            if base_entries[0] != classes[td]['name']: continue
            locators[col] = (td, displacement)
            classes[td]['locators'].append(hx(col))
            classes[td]['bases'] = list(dict.fromkeys(base_entries[1:]))
    tables = []; slots = []; seen = set()
    for reference, value in pe.pointers():
        if value not in locators: continue
        table_va = reference+4
        if table_va in seen: continue
        entries = []
        for slot in range(512):
            word = pe.words(table_va+slot*4,1)
            if not word or not pe.code(word[0]): break
            entries.append(word[0])
        if not entries: continue
        seen.add(table_va)
        td, displacement = locators[value]
        owner = classes[td]['name']
        classes[td]['vtables'].append(hx(table_va))
        classes[td]['status'] = 'exe_rtti_with_vtable'
        tables.append(dict(owner=owner,va=hx(table_va),rva=hx(table_va-pe.base),
            locator_va=hx(value),object_offset=displacement,slots=len(entries),
            status='rtti_structural',truncated=len(entries)==512))
        for index, function in enumerate(entries): slots.append(dict(owner=owner,vtable_va=hx(table_va),
            slot=index,function_va=hx(function),function_rva=hx(function-pe.base),status='rtti_slot'))
    return list(classes.values()), tables, slots

def sdk_map(pe):
    classes, addresses = [], []
    token_re = re.compile(r'\bnamespace\s+([A-Za-z_]\w*(?:::\w+)*)\s*\{|\b(class|struct)\s+([A-Za-z_]\w*)[^;{}]*\{|[{}]')
    call_re = re.compile(r'AddressSetter::(GetRef(?:<[^\n;]*?>)?|Get)\s*\(\s*(0x[\da-fA-F]+|\d+)\s*,\s*(0x[\da-fA-F]+|\d+)')
    for path in sorted((ROOT/'contrib/IV SDK/IV-SDK-main/include').glob('*.h')):
        text = path.read_text(encoding='utf-8-sig',errors='replace')
        clean = re.sub(r'//[^\n]*|/\*.*?\*/',lambda m: ''.join('\n' if c=='\n' else ' ' for c in m.group()),text,flags=re.S)
        events = [(m.start(), 'scope',m) for m in token_re.finditer(clean)]
        events += [(m.start(),'address',m) for m in call_re.finditer(clean)]
        stack = []
        for pos, kind, match in sorted(events,key=lambda e:e[0]):
            names = [s[1] for s in stack if s[0] in ('namespace','class')]
            if kind == 'scope':
                if match.group() == '}':
                    if stack: stack.pop()
                elif match.group(1): stack.append(('namespace',match.group(1)))
                elif match.group(3):
                    name = '::'.join(names+[match.group(3)])
                    classes.append(dict(name=name,kind=match.group(2),file=path.relative_to(ROOT).as_posix(),
                        line=clean.count('\n',0,pos)+1,status='sdk_declaration'))
                    stack.append(('class',match.group(3)))
                else:
                    prefix = clean[max(0,pos-500):pos]
                    method = re.search(r'\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*(?:const\s*)?$',prefix)
                    stack.append(('method',method.group(1)) if method and method.group(1) not in ('if','while','for','switch') else ('block',''))
                continue
            rva = int(match.group(2),0)
            va = pe.base+rva
            line = clean.count('\n',0,pos)+1
            source_line = text.splitlines()[line-1].strip()
            methods = [s[1] for s in stack if s[0]=='method']
            variable = re.search(r'([A-Za-z_]\w*)\s*=\s*AddressSetter',source_line)
            name = '::'.join(names + ([methods[-1]] if methods else [variable.group(1) if variable else f'address_line_{line}']))
            section = pe.section(va)
            category = 'global_reference' if match.group(1).startswith('GetRef') else 'function_reference' if methods else 'address_reference'
            if 'm_pVFTable' in source_line: category = 'vtable_reference'
            addresses.append(dict(name=name,owner='::'.join(names),kind=category,rva=hx(rva),va=hx(va),
                section=section['name'] if section else '',file=path.relative_to(ROOT).as_posix(),line=line,
                mapped=bool(section),executable=pe.code(va),status='sdk_reference_not_validated'))
    return classes, addresses

def historical_map(pe,path):
    text = path.read_text(encoding='utf-8-sig')
    rows = []; heading = ''
    for lineno,line in enumerate(text.splitlines(),1):
        if line.startswith('#'): heading=line.lstrip('# ').strip()
        spans = []
        for match in re.finditer(r'GTAIV\.exe\s*\+\s*(?:0x)?([\da-fA-F]{5,8})',line,re.I):
            spans.append((match.start(),match.end(),int(match.group(1),16),'rva'))
        for match in re.finditer(r'0x[\da-fA-F]{5,8}\b',line):
            if any(a <= match.start() < b for a,b,_,_ in spans): continue
            value=int(match.group(),16)
            if value>=pe.base: spans.append((match.start(),match.end(),value,'va_candidate'))
        versions=';'.join(dict.fromkeys(re.findall(r'\b[1]\.[01]\.[0-9]+\.[0-9]+\b',line)))
        for _,_,value,notation in spans:
            va=pe.base+value if notation=='rva' else value
            section=pe.section(va)
            rows.append(dict(line=lineno,heading=heading,literal=hx(value),notation=notation,
                version_explicit=versions or 'unspecified',candidate_va=hx(va),candidate_rva=hx(va-pe.base),
                mapped=bool(section),section=section['name'] if section else '',
                status='historical_unverified',context=line.strip()[:240]))
    return rows, hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--exe',type=Path,default=ROOT.parent/'Grand Theft Auto IV - copia/GTAIV.exe')
    parser.add_argument('--reference',type=Path,default=Path('C:/Users/pedro/Downloads/gta4_memory_addresses_completo_es.md'))
    parser.add_argument('--ghidra-export',type=Path,default=ROOT/'build/memory-map')
    args=parser.parse_args()
    pe=PE(args.exe); functions,symbols=read_ghidra(pe,args.ghidra_export)
    classes,tables,slots=rtti_map(pe,symbols)
    sdk_classes,sdk_addresses=sdk_map(pe)
    historical,reference_hash=historical_map(pe,args.reference)
    names_by_va={r['va']:r['name'] for r in functions}
    for slot in slots: slot['function_name']=names_by_va.get(slot['function_va'],'unknown_entry')
    declarations={r['name'] for r in sdk_classes}
    for cls in classes: cls['in_sdk']=cls['name'] in declarations
    sdk_index=defaultdict(list)
    for address in sdk_addresses: sdk_index[address['va']].append(address['name'])
    for f in functions: f['sdk_names']=';'.join(dict.fromkeys(sdk_index[f['va']]))
    virtual_owners=defaultdict(set)
    for slot in slots: virtual_owners[slot['function_va']].add(slot['owner'])
    known_entries={f['va'] for f in functions}
    additional=[]
    for va,owners in sorted(virtual_owners.items()):
        if va in known_entries: continue
        address=int(va,16)
        additional.append(dict(va=va,rva=hx(address-pe.base),name='virtual_entry_'+va[2:],
            sdk_names=';'.join(dict.fromkeys(sdk_index[va])),body_bytes='',section=pe.section(address)['name'],
            thunk='unknown',calling_convention='unknown',source='RTTI_vtable',status='vtable_target_candidate'))
    all_code=sorted(functions+additional,key=lambda f:int(f['va'],16))
    rtti_by_name=defaultdict(list)
    for cls in classes: rtti_by_name[cls['name']].append(cls)
    for declaration in sdk_classes:
        matches=rtti_by_name[declaration['name']]
        declaration['rtti_va']=';'.join(c['type_descriptor_va'] for c in matches)
        declaration['vtables']=';'.join(t for c in matches for t in c['vtables'])
        declaration['address_references']=sum(a['owner']==declaration['name'] for a in sdk_addresses)
    output=ROOT/'docs/MemoryMap'; output.mkdir(parents=True,exist_ok=True)
    summary=dict(exe_sha256=CANONICAL,image_base=hx(pe.base),ghidra_global_analysis_complete=False,
        rtti_type_records=len(classes),rtti_unique_names=len({c['mangled'] for c in classes}),
        rtti_classes_with_vtables=sum(bool(c['vtables']) for c in classes),
        vtables=len(tables),virtual_slots=len(slots),ghidra_function_entries=len(functions),
        unique_virtual_targets=len(virtual_owners),additional_virtual_targets=len(additional),
        code_address_entries=len(all_code),sdk_classes_matching_rtti=sum(bool(d['rtti_va']) for d in sdk_classes),
        sdk_declarations=len(sdk_classes),sdk_unique_declarations=len(declarations),sdk_address_references=len(sdk_addresses),
        historical_address_mentions=len(historical),historical_reference_sha256=reference_hash,
        total_game_classes='unknown',total_game_functions='unknown')
    class_rows=[dict(c,bases=';'.join(c['bases']),vtables=';'.join(c['vtables']),locators=';'.join(c['locators'])) for c in classes]
    write_csv(output/'classes.csv',class_rows,['name','mangled','kind','type_descriptor_rva','type_descriptor_va','section','status','in_sdk','locators','vtables','bases'])
    write_csv(output/'vtables.csv',tables,['owner','rva','va','locator_va','object_offset','slots','status','truncated'])
    write_csv(output/'virtual_slots.csv',slots,['owner','vtable_va','slot','function_rva','function_va','function_name','status'])
    write_csv(output/'function_entries.csv',functions,['rva','va','name','sdk_names','body_bytes','section','thunk','calling_convention','source','status'])
    write_csv(output/'code_addresses.csv',all_code,['rva','va','name','sdk_names','body_bytes','section','thunk','calling_convention','source','status'])
    write_csv(output/'sdk_classes.csv',sdk_classes,['name','kind','rtti_va','vtables','address_references','file','line','status'])
    write_csv(output/'sdk_addresses.csv',sdk_addresses,['name','owner','kind','rva','va','section','file','line','mapped','executable','status'])
    write_csv(output/'historical_references.csv',historical,['line','heading','literal','notation','version_explicit','candidate_va','candidate_rva','mapped','section','status','context'])
    (output/'summary.json').write_text(json.dumps(summary,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
    (output/'sections.json').write_text(json.dumps(pe.sections,indent=2)+'\n',encoding='utf-8')
    dataset=dict(summary=summary,sections=pe.sections,classes=classes,vtables=tables,slots=slots,
        functions=all_code,sdk_classes=sdk_classes,sdk=sdk_addresses,historical=historical)
    template=(ROOT/'reversing/MemoryMap/viewer.template.html').read_text(encoding='utf-8')
    packed=base64.b64encode(gzip.compress(json.dumps(dataset,ensure_ascii=False,separators=(',',':')).encode('utf-8'),mtime=0)).decode('ascii')
    (output/'index.html').write_text(template.replace('__DATA__',packed),encoding='utf-8')
    print(json.dumps(summary,indent=2,ensure_ascii=False))

if __name__=='__main__': main()
