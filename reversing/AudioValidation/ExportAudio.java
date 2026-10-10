// @category ReIV
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.PrintWriter;
import java.nio.file.*;
public class ExportAudio extends GhidraScript {
 public void run() throws Exception {
  DecompInterface d=new DecompInterface(); d.openProgram(currentProgram);
  String dir=getScriptArgs()[0];
  for(String line:Files.readAllLines(Paths.get(dir,"targets.txt"))) {
   long va=Long.decode(line.trim()); Address a=toAddr(va); disassemble(a);
   Function f=getFunctionAt(a); if(f==null) f=createFunction(a,null);
   try(PrintWriter out=new PrintWriter(dir+"/"+String.format("%08x",va)+".txt","UTF-8")) {
    out.println("Canonical GTAIV.exe preferred VA "+a);
    byte[] bytes=new byte[24]; currentProgram.getMemory().getBytes(a,bytes);
    out.print("Entry bytes: "); for(byte b:bytes)out.printf("%02x ",b&255);out.println();
    if(f==null){out.println("No function");continue;}
    out.println("Body size: "+f.getBody().getNumAddresses());
    Instruction i=getInstructionAt(a);while(i!=null&&f.getBody().contains(i.getAddress())){out.println(i.getAddress()+" "+i);i=i.getNext();}
    DecompileResults r=d.decompileFunction(f,20,monitor);out.println(r.decompileCompleted()?r.getDecompiledFunction().getC():r.getErrorMessage());
   }
  }d.dispose();
 }
}
