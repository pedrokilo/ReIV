using System;
using System.IO;

namespace ReIV.Tools
{
    /// <summary>
    /// Herramientas de ReIV en C#:
    ///   progress    genera docs/ReversedClasses.md (completamente revertidas, parcialmente revertidas, sin revertir, desconocido)
    ///   provenance  clasifica funciones y dependencias por procedencia (docs/MemoryMap/FunctionClassification.md y DependencyProvenance.md)
    ///   audit       audita source/: pares .h/.cpp y ensamblador en linea (docs/SourceAudit.md)
    ///   all         ejecuta provenance y progress (por defecto)
    /// </summary>
    public static class Program
    {
        public static int Main(string[] args)
        {
            try
            {
                var root = Repo.FindRoot(Directory.GetCurrentDirectory());
                var command = args.Length > 0 ? args[0].ToLowerInvariant() : "all";
                switch (command)
                {
                    case "provenance": ProvenanceReport.Write(root); break;
                    case "progress": ProgressReport.Write(root); break;
                    case "audit": AuditReport.Write(root); break;
                    case "all":
                        ProvenanceReport.Write(root);
                        ProgressReport.Write(root);
                        break;
                    default:
                        Console.Error.WriteLine("Uso: ReIV.Tools [all|progress|provenance|audit]");
                        return 2;
                }
                return 0;
            }
            catch (Exception ex)
            {
                Console.Error.WriteLine("ERROR: " + ex.Message);
                return 1;
            }
        }
    }
}
