from pathlib import Path
p=Path(__file__).parent
s=(p/'extra_asm.py').read_text().replace('remaining-update-methods.json','actions-static.json')
a=s.index('for va,file,ns,name,args,ret in '); e=s.index(':\n s=next',a)
s=s[:a]+"for va,file,ns,name,args,ret in [(0x9C1F90,'CPlayerPed.h','player_action_range','Act','void* object, void*, std::uint32_t flag','std::uint8_t'),(0x9C2180,'CPlayerPed.h','player_action_request','Act','void* object, void*, std::uint32_t flag, std::uint32_t argument','std::uint8_t')]"+s[e:]
s=s.replace("prefix='Value' if va==0x9BFD80 else 'Input'","prefix='Range' if va==0x9C1F90 else 'Request'")
(p/'actions_asm.py').write_text(s)
a=s.index('for va,file,ns,name,args,ret in ');e=s.index(':\n s=next',a)
s=s[:a]+"for va,file,ns,name,args,ret in [(0x9C1300,'CPlayerPed.h','player_action_selection','Select','void* embeddedReceiver, void*, std::uint32_t flags, std::uint32_t rangeBits, std::uint32_t argument, float* output, std::uint32_t last','std::uint32_t')]"+s[e:]
s=s.replace("prefix='Range' if va==0x9C1F90 else 'Request'","prefix='Selection'")
s=s.replace("if m=='call' and op.startswith('0x'):op=", "if m=='call' and op=='0x9c1300':op='Select'\n  elif m=='call' and op.startswith('0x'):op=")
s=s.replace("lines.append('  '+m+' '+op)","if 'fs:[g0000002C]' in op:op=op.replace('fs:[g0000002C]','[g0000002C]')\n  lines.append('  '+m+' '+op)")
(p/'selection_asm.py').write_text(s)
