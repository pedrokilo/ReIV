// @category ReIV
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

public class ExportPendingFunctions extends GhidraScript {
    private String q(String value) { return "\"" + value.replace("\"", "\"\"").replace("\n", " ").replace("\r", " ") + "\""; }
    public void run() throws Exception {
        File output = new File(getScriptArgs()[1]); output.mkdirs();
        long base = currentProgram.getImageBase().getOffset();
        try (PrintWriter rows = new PrintWriter(new File(output,"functions.csv"),"UTF-8");
             PrintWriter calls = new PrintWriter(new File(output,"dependencies.csv"),"UTF-8")) {
            rows.println("rva,status,entry_name,containing_entry,body_ranges,body_bytes,instructions,direct_calls,indirect_calls,signature,signature_source,thunk");
            calls.println("owner_rva,instruction_va,flow_type,target_va,target_name");
            for (String line:Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
                monitor.checkCancelled(); if(line.trim().isEmpty())continue;
                long rva=Long.decode(line.trim()); Address entry=toAddr(base+rva);
                Function f=currentProgram.getFunctionManager().getFunctionAt(entry);
                if(f==null) {
                    Function containing=currentProgram.getFunctionManager().getFunctionContaining(entry);
                    rows.printf("0x%08x,%s,%s,%s,%s,0,0,0,0,%s,%s,false%n",rva,containing==null?"no_function_boundary":"inside_other_function",q(""),q(containing==null?"":containing.getEntryPoint().toString()),q(""),q(""),q(""));
                    continue;
                }
                StringBuilder ranges=new StringBuilder(); AddressRangeIterator iterator=f.getBody().getAddressRanges();
                while(iterator.hasNext()) { AddressRange range=iterator.next(); if(ranges.length()>0)ranges.append(';');ranges.append(range.getMinAddress()).append('-').append(range.getMaxAddress()); }
                int instructions=0,direct=0,indirect=0;
                InstructionIterator listing=currentProgram.getListing().getInstructions(f.getBody(),true);
                while(listing.hasNext()) {
                    Instruction ins=listing.next(); instructions++;
                    if(!ins.getFlowType().isCall())continue;
                    if(ins.getFlowType().isComputed())indirect++;else direct++;
                    Address[] flows=ins.getFlows();
                    if(flows.length==0)calls.printf("0x%08x,%s,%s,%s,%s%n",rva,ins.getAddress(),q(ins.getFlowType().toString()),q(""),q("unresolved"));
                    for(Address dest:flows) { Function callee=currentProgram.getFunctionManager().getFunctionAt(dest);calls.printf("0x%08x,%s,%s,%s,%s%n",rva,ins.getAddress(),q(ins.getFlowType().toString()),q(dest.toString()),q(callee==null?"":callee.getName(true))); }
                }
                rows.printf("0x%08x,function_boundary,%s,%s,%s,%d,%d,%d,%d,%s,%s,%s%n",rva,q(f.getName(true)),q(f.getEntryPoint().toString()),q(ranges.toString()),f.getBody().getNumAddresses(),instructions,direct,indirect,q(f.getSignature().toString()),q(f.getSignatureSource().toString()),f.isThunk());
            }
        }
        println("Exported existing Ghidra function boundaries and dependencies; inferred signatures are not runtime verified.");
    }
}
