// @category ReIV
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.io.PrintWriter;
public class ExportAnimation extends GhidraScript {
 public void run() throws Exception {
  DecompInterface d = new DecompInterface(); d.openProgram(currentProgram);
  long[] addresses={0x00443c20L,0x00443c50L,0x00447970L,0x00491800L,0x004c88c0L,0x004d7030L,0x0050b6e0L,0x0050b6f0L,0x0050b8c0L,0x0050c080L,0x0050c0b0L,0x0050f4d0L,0x00549100L,0x00550ff0L,0x0055a850L,0x0059bc50L,0x005fdcd0L,0x007bdc00L,0x0089bbf0L,0x0089bc10L,0x0089e930L,0x008b8fe0L,0x008da400L,0x008e05a0L,0x00918420L,0x0092f320L,0x0092fb30L,0x00931120L,0x009c80b0L,0x009c80c0L,0x009dfe70L,0x009e0490L,0x009e04d0L,0x009e05c0L,0x009e0610L,0x009e0660L,0x009e0690L,0x009e06c0L,0x009e0bd0L,0x009e1480L,0x009e15b0L,0x009e15d0L,0x009e18a0L,0x009e1b70L,0x009e69e0L,0x009e6a40L,0x009e7110L,0x009e7140L,0x009e7c20L,0x009e8710L,0x009e9e10L,0x009eab70L,0x009eac60L,0x009eaf60L,0x009eb0e0L,0x009eb110L,0x009eb120L,0x009eb260L,0x009ebb70L,0x009ed810L,0x009ed8d0L,0x009ed8f0L,0x009ee4c0L,0x009ee5a0L,0x009ee620L,0x009ee680L,0x009ee6b0L,0x009ee750L,0x009eea90L,0x009eebd0L,0x009eecb0L,0x009eecf0L,0x00a4c3b0L,0x00a4d670L,0x00a4dc50L,0x00a4dc70L,0x00b59b30L,0x00c28820L,0x00c79550L,0x00c79560L,0x00c79570L,0x00c79580L,0x00c79610L,0x00c79690L,0x00cfaee0L};
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

