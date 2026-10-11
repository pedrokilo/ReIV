using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ReIV.Tools
{
    /// <summary>
    /// Auditoria de source/: pares .h/.cpp por carpeta (como en ReSA) y uso de ensamblador en linea.
    /// Solo lee archivos; no modifica nada de source/.
    /// </summary>
    public static class AuditReport
    {
        sealed class Item
        {
            public string Path = "", Folder = "", Kind = "", Stem = "";
            public bool HasPair; public int AsmBlocks, NakedFunctions, Lines, InlineBodies;
        }

        static readonly Regex Asm = new Regex(@"\b__asm\b|\b_asm\b", RegexOptions.Compiled);
        static readonly Regex Naked = new Regex(@"__declspec\s*\(\s*naked\s*\)", RegexOptions.Compiled);
        // Definiciones de funcion con cuerpo (firma que termina en ') {' o ') const {') fuera de comentarios.
        static readonly Regex Body = new Regex(@"^[ \t]*[\w:<>~\*&\s,\[\]]+\([^;{}]*\)\s*(const\s*)?(noexcept\s*)?\{", RegexOptions.Multiline | RegexOptions.Compiled);

        public static void Write(string root)
        {
            var source = Path.Combine(root, "source");
            var files = Directory.GetFiles(source, "*.*", SearchOption.AllDirectories)
                .Where(f => f.EndsWith(".h", StringComparison.Ordinal) || f.EndsWith(".cpp", StringComparison.Ordinal)).ToList();
            var set = new HashSet<string>(files.Select(f => f.ToLowerInvariant()));
            var items = new List<Item>();
            foreach (var f in files)
            {
                var rel = Repo.Rel(root, f);
                var text = File.ReadAllText(f, Encoding.UTF8);
                bool header = f.EndsWith(".h", StringComparison.Ordinal);
                var pair = Path.ChangeExtension(f, header ? ".cpp" : ".h").ToLowerInvariant();
                var item = new Item
                {
                    Path = rel, Stem = Path.GetFileNameWithoutExtension(f), Lines = text.Count(c => c == '\n'),
                    Folder = FolderOf(rel), HasPair = set.Contains(pair),
                    AsmBlocks = Asm.Matches(text).Count, NakedFunctions = Naked.Matches(text).Count
                };
                bool generated = text.Contains("// BEGIN GENERATED PENDING HOOK ADDRESSES");
                item.Kind = header ? (generated ? "h-rtti" : "h-manual") : "cpp";
                if (header && !generated) item.InlineBodies = Body.Matches(StripComments(text)).Count;
                items.Add(item);
            }

            var headers = items.Where(i => i.Kind.StartsWith("h-", StringComparison.Ordinal)).ToList();
            var cpps = items.Where(i => i.Kind == "cpp").ToList();
            var rtti = headers.Where(i => i.Kind == "h-rtti").ToList();
            var manual = headers.Where(i => i.Kind == "h-manual").ToList();
            var asm = items.Where(i => i.AsmBlocks > 0 || i.NakedFunctions > 0).OrderBy(i => i.Path, StringComparer.Ordinal).ToList();

            Csv.Write(Path.Combine(root, "docs", "source_audit.csv"),
                new[] { "path", "kind", "folder", "lines", "has_pair", "asm_blocks", "naked_functions", "inline_bodies" },
                items.OrderBy(i => i.Path, StringComparer.Ordinal).Select(i => (IList<string>)new[]
                {
                    i.Path, i.Kind, i.Folder, i.Lines.ToString(), i.HasPair ? "1" : "0", i.AsmBlocks.ToString(), i.NakedFunctions.ToString(), i.InlineBodies.ToString()
                }));

            var sb = new StringBuilder();
            Action<string> line = s => sb.Append(s).Append('\n');
            line("# Auditoría de `source/`");
            line("");
            line("[Inicio](../README.md) · [Progreso del reversing](ReversedClasses.md) · [Organización de source](../source/README.md)");
            line("");
            line("> Generado por `tools/ReIV.Tools audit` (C#). Solo lee `source/`; detalle por archivo en [source_audit.csv](source_audit.csv).");
            line("");
            line("Se revisan dos reglas, como en ReSA: **cada clase tiene su `.h` y su `.cpp`** (con sus subcarpetas) y **todo está escrito en C++, no en ensamblador**.");
            line("");
            line("## Resumen");
            line("");
            line("| Medida | Cantidad |");
            line("| --- | ---: |");
            line("| Headers | " + headers.Count.ToString("N0") + " |");
            line("| — de tipos RTTI generados (identidad y tabla de direcciones, sin código) | " + rtti.Count.ToString("N0") + " |");
            line("| — escritos a mano | " + manual.Count.ToString("N0") + " |");
            line("| Archivos `.cpp` | " + cpps.Count.ToString("N0") + " |");
            line("| Headers con su `.cpp` | " + headers.Count(h => h.HasPair).ToString("N0") + " |");
            line("| Headers sin `.cpp` | " + headers.Count(h => !h.HasPair).ToString("N0") + " |");
            line("| `.cpp` sin `.h` | " + cpps.Count(c => !c.HasPair).ToString("N0") + " |");
            line("| Archivos con ensamblador (`__asm` o `naked`) | " + asm.Count + " |");
            line("| Bloques `__asm` | " + asm.Sum(a => a.AsmBlocks).ToString("N0") + " |");
            line("| Funciones `naked` | " + asm.Sum(a => a.NakedFunctions).ToString("N0") + " |");
            line("");
            line("## Headers sin `.cpp` por carpeta");
            line("");
            line("| Carpeta | Headers | De tipos RTTI | A mano | Con `.cpp` | Sin `.cpp` | Con ensamblador |");
            line("| --- | ---: | ---: | ---: | ---: | ---: | ---: |");
            foreach (var g in headers.GroupBy(h => h.Folder).OrderBy(g => g.Key, StringComparer.Ordinal))
                line("| `" + g.Key + "` | " + g.Count() + " | " + g.Count(h => h.Kind == "h-rtti") + " | " + g.Count(h => h.Kind == "h-manual") + " | " +
                     g.Count(h => h.HasPair) + " | " + g.Count(h => !h.HasPair) + " | " + g.Count(h => h.AsmBlocks > 0 || h.NakedFunctions > 0) + " |");
            line("");
            line("## Headers escritos a mano");
            line("");
            line("Los que tienen cuerpos de función dentro del header deberían tener su `.cpp`, como en ReSA. «Cuerpos» es una cuenta aproximada de definiciones con llaves.");
            line("");
            line("| Header | Líneas | Cuerpos en el header | `.cpp` | Ensamblador |");
            line("| --- | ---: | ---: | :---: | :---: |");
            foreach (var h in manual.OrderBy(h => h.Path, StringComparer.Ordinal))
                line("| [" + h.Path + "](../" + h.Path + ") | " + h.Lines + " | " + h.InlineBodies + " | " + (h.HasPair ? "sí" : "no") + " | " +
                     (h.AsmBlocks > 0 || h.NakedFunctions > 0 ? "sí" : "no") + " |");
            line("");
            line("## Ensamblador en línea");
            line("");
            if (asm.Count == 0) line("Ninguno.");
            else
            {
                line("| Archivo | Bloques `__asm` | Funciones `naked` |");
                line("| --- | ---: | ---: |");
                foreach (var a in asm) line("| [" + a.Path + "](../" + a.Path + ") | " + a.AsmBlocks + " | " + a.NakedFunctions + " |");
            }
            line("");
            line("## `.cpp` sin `.h`");
            line("");
            var orphans = cpps.Where(c => !c.HasPair).OrderBy(c => c.Path, StringComparer.Ordinal).ToList();
            if (orphans.Count == 0) line("Ninguno.");
            else foreach (var o in orphans) line("- [" + o.Path + "](../" + o.Path + ")");
            line("");
            Repo.WriteText(Path.Combine(root, "docs", "SourceAudit.md"), sb.ToString());
            Console.WriteLine("SourceAudit: " + headers.Count + " headers (" + rtti.Count + " RTTI, " + manual.Count + " a mano), " + cpps.Count +
                " cpp, " + headers.Count(h => !h.HasPair) + " headers sin cpp, " + asm.Count + " archivos con ensamblador");
        }

        static string FolderOf(string rel)
        {
            var parts = rel.Split('/').Skip(1).ToArray(); // sin el prefijo source/
            if (parts.Length <= 1) return "(raiz)";
            if ((parts[0] == "game" || parts[0] == "rage") && parts.Length > 2) return parts[0] + "/" + parts[1];
            return parts[0];
        }

        static string StripComments(string text)
        {
            text = Regex.Replace(text, @"/\*.*?\*/", "", RegexOptions.Singleline);
            return Regex.Replace(text, @"//[^\n]*", "");
        }
    }
}
