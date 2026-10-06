// Export the canonical PC 1.0.7.0 function with Ghidra headless.
// @category ReIV
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.data.UnsignedIntegerDataType;
import ghidra.program.model.data.CharDataType;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.listing.ParameterImpl;
import java.io.PrintWriter;

public class ExportAtStringHash extends GhidraScript {
    public void run() throws Exception {
        Address start = currentProgram.getImageBase().add(0x1b1c30);
        disassemble(start);
        Function function = getFunctionAt(start);
        if (function == null) function = createFunction(start, "ReIV_atStringHash");
        if (function == null) throw new Exception("Function creation failed");
        function.setName("ReIV_atStringHash", SourceType.USER_DEFINED);
        function.setCallingConvention("__cdecl");
        function.setReturnType(UnsignedIntegerDataType.dataType, SourceType.USER_DEFINED);
        function.replaceParameters(Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,
            true, SourceType.USER_DEFINED,
            new ParameterImpl("text", new PointerDataType(CharDataType.dataType), currentProgram),
            new ParameterImpl("seed", UnsignedIntegerDataType.dataType, currentProgram));
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        DecompileResults result = decompiler.decompileFunction(function, 60, monitor);
        try (PrintWriter out = new PrintWriter(getScriptArgs()[0], "UTF-8")) {
            out.println("Program: " + currentProgram.getName());
            out.println("Language: " + currentProgram.getLanguageID());
            out.println("Image base: " + currentProgram.getImageBase());
            out.println("Function: " + start);
            Instruction ins = getInstructionAt(start);
            while (ins != null && function.getBody().contains(ins.getAddress())) {
                out.println(ins.getAddress() + "  " + ins.toString());
                ins = ins.getNext();
            }
            if (!result.decompileCompleted()) throw new Exception(result.getErrorMessage());
            out.println("\nDECOMPILATION (analysis aid, not reconstructed source):");
            out.println(result.getDecompiledFunction().getC());
        } finally { decompiler.dispose(); }
    }
}
