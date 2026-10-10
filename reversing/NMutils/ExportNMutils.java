// @category ReIV
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.PrintWriter;
public class ExportNMutils extends GhidraScript {
 public void run() throws Exception {
  DecompInterface d = new DecompInterface(); d.openProgram(currentProgram);
  long[] addresses={0x005d4f40L,0x005d67f0L,0x00401210L,0x005d67a0L,0x005e1600L,0x005e1820L,0x005e1700L,0x005a8cb0L,0x00d11d73L,0x00d11c9fL};
  for(long va:addresses){
   Address a=toAddr(va); disassemble(a); Function f=getFunctionAt(a); if(f==null) f=createFunction(a,null);
   try(PrintWriter out=new PrintWriter(getScriptArgs()[0]+"/"+String.format("%08x",va)+".txt","UTF-8")){
    out.println("Canonical GTAIV.exe preferred VA "+a);
    if(f==null){out.println("No function");continue;}
    Instruction i=getInstructionAt(a); while(i!=null&&f.getBody().contains(i.getAddress())) {out.println(i.getAddress()+" "+i);i=i.getNext();}
    DecompileResults r=d.decompileFunction(f,30,monitor); out.println(r.decompileCompleted()?r.getDecompiledFunction().getC():r.getErrorMessage());
   }
  }
  d.dispose();
 }
}
