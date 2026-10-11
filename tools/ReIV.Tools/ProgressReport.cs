using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace ReIV.Tools
{
    /// <summary>
    /// Genera docs/ReversedClasses.md con la estructura de ReSA: dimensiones con barras, siguientes mediciones,
    /// vista general y secciones en este orden: completamente revertidas, parcialmente revertidas, sin revertir, desconocido.
    /// </summary>
    public static class ProgressReport
    {
        sealed class ClassInfo
        {
            public string Name = "", Kind = "", File = "";
            public HashSet<long> Known = new HashSet<long>();
            public HashSet<long> Reconstructed = new HashSet<long>();
            public HashSet<long> Validated = new HashSet<long>();
            public int Locked, Entries;
            public SortedSet<string> References = new SortedSet<string>(StringComparer.Ordinal);
            public int Total { get { return Known.Union(Reconstructed).Count(); } }
            public int Pending { get { return Total - Reconstructed.Count; } }
        }

        static string Bar(int value, int total, int width = 20)
        {
            int filled = total == 0 ? 0 : (int)Math.Round((double)width * value / total);
            return new string('█', filled) + new string('░', width - filled);
        }

        static string Pct(int value, int total)
        {
            return (total == 0 ? 0 : 100.0 * value / total).ToString("0.00", CultureInfo.InvariantCulture) + "%";
        }

        static string N(int value) { return value.ToString("N0", new CultureInfo("en-US")); }

        static string Label(string name)
        {
            return name.Replace("|", "&#124;").Replace("[", "&#91;").Replace("]", "&#93;").Replace("<", "&lt;").Replace(">", "&gt;");
        }

        public static void Write(string root)
        {
            var memory = Path.Combine(root, "docs", "MemoryMap");
            var classes = new Dictionary<string, ClassInfo>(StringComparer.Ordinal);
            foreach (var r in Csv.Read(Path.Combine(root, "source", "class-files.csv")))
                classes[r.Get("name")] = new ClassInfo { Name = r.Get("name"), Kind = r.Get("kind"), File = r.Get("file") };

            foreach (var r in Csv.Read(Path.Combine(memory, "pending_hooks.csv")))
            {
                ClassInfo c;
                if (classes.TryGetValue(r.Get("owner"), out c)) c.Known.Add(Csv.Hex(r.Get("rva")));
            }

            // Referencias de nombres (IV-SDK, plugin_IV, IV-SDK.Net) por clase.
            Action<string, string> reference = (owner, source) =>
            {
                ClassInfo c;
                if (!string.IsNullOrEmpty(owner) && classes.TryGetValue(owner, out c)) c.References.Add(source);
            };
            foreach (var r in Csv.Read(Path.Combine(memory, "sdk_addresses.csv"))) reference(r.Get("owner"), "IV-SDK");
            foreach (var r in Csv.Read(Path.Combine(memory, "plugin_iv_patterns.csv"))) reference(r.Get("owner"), "plugin_IV");
            foreach (var r in Csv.Read(Path.Combine(memory, "sdknet_addresses.csv")))
                if (r.Get("kind") != "byte_pattern") reference(r.Get("owner"), "IV-SDK.Net");

            var hooks = Csv.Read(Path.Combine(root, "docs", "hooks.csv"));
            var outside = new List<Dictionary<string, string>>();
            foreach (var r in hooks)
            {
                ClassInfo c;
                if (!classes.TryGetValue(r.Get("class"), out c))
                {
                    if (r.Get("reversed") == "1") outside.Add(r);
                    continue;
                }
                c.Entries++;
                var rva = Csv.Hex(r.Get("rva"));
                if (r.Get("locked") == "1") c.Locked++;
                if (r.Get("reversed") == "1")
                {
                    c.Reconstructed.Add(rva);
                    if (r.Get("reconstruction_validated") == "1") c.Validated.Add(rva);
                }
            }

            // Una clase solo es "completamente revertida" si figura con inventario exhaustivo y todo lo conocido esta reconstruido.
            var exhaustive = new HashSet<string>(StringComparer.Ordinal);
            var exhaustivePath = Path.Combine(root, "reversing", "HookRegistry", "exhaustive-classes.txt");
            if (File.Exists(exhaustivePath))
                foreach (var entry in File.ReadAllLines(exhaustivePath, Encoding.UTF8))
                    if (entry.Trim().Length > 0 && !entry.StartsWith("#")) exhaustive.Add(entry.Trim());

            var complete = new List<ClassInfo>(); var partial = new List<ClassInfo>();
            var unreversed = new List<ClassInfo>(); var unknown = new List<ClassInfo>();
            foreach (var c in classes.Values.OrderBy(c => c.Name, StringComparer.OrdinalIgnoreCase))
            {
                if (c.Reconstructed.Count > 0)
                {
                    bool done = exhaustive.Contains(c.Name) && c.Known.All(k => c.Reconstructed.Contains(k));
                    (done ? complete : partial).Add(c);
                }
                else if (c.Known.Count > 0) unreversed.Add(c);
                else unknown.Add(c);
            }

            int totalClasses = classes.Count;
            int entries = hooks.Count;
            int reversedEntries = hooks.Count(r => r.Get("reversed") == "1");
            int validatedEntries = hooks.Count(r => r.Get("reversed") == "1" && r.Get("reconstruction_validated") == "1");
            int matching = hooks.Count(r => r.Get("source_matches_evidence") == "1");
            int uniqueTargets = hooks.Select(r => Csv.Hex(r.Get("rva"))).Distinct().Count();

            // Resultados de la clasificacion por procedencia (si ya se generaron).
            int unidentified = 0, classifiedFunctions = 0;
            foreach (var r in Csv.Read(Path.Combine(memory, "function_classification.csv")))
            {
                classifiedFunctions++;
                if (r.Get("status") == "Desconocido") unidentified++;
            }
            int dependencyCount = Csv.Read(Path.Combine(memory, "dependency_provenance.csv")).Count;

            var sb = new StringBuilder();
            Action<string> line = s => sb.Append(s).Append('\n');
            line("# Progreso del reversing");
            line("");
            line("[Inicio](../README.md) · [Clases y hooks](MemoryMap/ClassesAndHooks.md) · [Clasificación de funciones](MemoryMap/FunctionClassification.md) · [Procedencia de dependencias](MemoryMap/DependencyProvenance.md) · [Proceso y evidencia](AddressBindingProcess.md)");
            line("");
            line("> **Fuente:** [hooks.csv](hooks.csv) · [Inventario de clases](../source/class-files.csv) · **Generado:** " + DateTime.UtcNow.ToString("yyyy-MM-dd HH:mm", CultureInfo.InvariantCulture) + " UTC por `tools/ReIV.Tools`");
            line("");
            line("## Objetivo y dimensiones de progreso");
            line("");
            line("Reconstruir las funciones de GTA IV y comprobar su comportamiento. Registrar una dirección o llamar al original acredita ese alcance de prueba; no cuenta como código revertido.");
            line("");
            line("| Dimensión | Progreso | Medición |");
            line("| --- | --- | --- |");
            line("| Clases completamente revertidas | `" + Bar(complete.Count, totalClasses) + "` | " + N(complete.Count) + "/" + N(totalClasses) + " · " + Pct(complete.Count, totalClasses) + " |");
            line("| Clases parcialmente revertidas | `" + Bar(partial.Count, totalClasses) + "` | " + N(partial.Count) + "/" + N(totalClasses) + " · " + Pct(partial.Count, totalClasses) + " |");
            line("| Funciones reconstruidas | `" + Bar(reversedEntries, entries) + "` | " + N(reversedEntries) + "/" + N(entries) + " · " + Pct(reversedEntries, entries) + " |");
            line("| Funciones reconstruidas con prueba aprobada (de las reconstruidas) | `" + Bar(validatedEntries, reversedEntries) + "` | " + N(validatedEntries) + "/" + N(reversedEntries) + " · " + Pct(validatedEntries, reversedEntries) + " |");
            line("| Entradas cuya fuente coincide con su evidencia | `" + Bar(matching, entries) + "` | " + N(matching) + "/" + N(entries) + " · " + Pct(matching, entries) + " |");
            line("");
            line("Hay " + N(entries) + " entradas por propietario y RVA, correspondientes a " + N(uniqueTargets) + " destinos únicos con pruebas acotadas. Este catálogo no es un inventario exhaustivo del EXE. Los auxiliares [NOTIV](hooks_notiv.csv) quedan fuera del progreso de clases.");
            line("");
            line("### Siguientes mediciones");
            line("");
            line("| Dimensión | Estado actual | Qué hay que hacer |");
            line("| --- | --- | --- |");
            line("| Clasificación de funciones por procedencia | " + N(classifiedFunctions) + " entradas de código clasificadas; " + N(unidentified) + " sin procedencia identificada | Separar CRT, código generado y helpers dentro de las entradas sin procedencia (exige desensamblado). [Detalle](MemoryMap/FunctionClassification.md) |");
            line("| Dependencias de funciones originales eliminadas | " + N(dependencyCount) + " direcciones externas en los cuerpos de CPlayerPed; ninguna eliminada | Reconstruir o sustituir cada dependencia y volver a medir. [Procedencia](MemoryMap/DependencyProvenance.md) |");
            line("| Inventario exhaustivo de métodos | " + N(exhaustive.Count) + " clases con inventario exhaustivo acreditado | Sin él, ninguna clase puede declararse completamente revertida. |");
            line("");
            line("## Vista general");
            line("");
            line("| Completamente revertidas | Parcialmente revertidas | Sin revertir | Desconocido |");
            line("| :---: | :---: | :---: | :---: |");
            line("| **" + N(complete.Count) + "** | **" + N(partial.Count) + "** | **" + N(unreversed.Count) + "** | **" + N(unknown.Count) + "** |");
            line("| " + Pct(complete.Count, totalClasses) + " | " + Pct(partial.Count, totalClasses) + " | " + Pct(unreversed.Count, totalClasses) + " | " + Pct(unknown.Count, totalClasses) + " |");
            line("");
            line("Reconstrucción por clases: " + N(complete.Count) + " completamente revertidas, " + N(partial.Count) + " parcialmente revertidas, " + N(unreversed.Count) + " sin revertir y " + N(unknown.Count) + " de procedencia desconocida, de " + N(totalClasses) + ".");
            line("");
            line("**Ir a:** [Completamente revertidas](#completas) · [Parcialmente revertidas](#parciales) · [Sin revertir](#sin-revertir) · [Desconocido](#desconocido) · [Cómo leer y actualizar](#metodo)");
            line("");
            line("> [!NOTE]");
            line("> Una llamada comprobada al original, un retorno simple probado y una dirección virtual coincidente no convierten una clase en parcialmente revertida. No se declara completa ninguna clase sin un inventario exhaustivo de sus métodos.");
            line("");

            Catalog(sb, "completas", "🟢", "Completamente revertidas", complete,
                "Todos los métodos de un inventario exhaustivo están reconstruidos. Orden alfabético por columna. Entre paréntesis: destinos conocidos; R: reconstruidos; ✅: con prueba aprobada.");
            Table(sb, "parciales", "🟡", "Parcialmente revertidas", partial);
            Catalog(sb, "sin-revertir", "🔴", "Sin revertir", unreversed,
                "Ninguna función registrada como reconstruida; puede tener direcciones y llamadas al original comprobadas. Orden alfabético por columna. Entre paréntesis: destinos conocidos distintos.");
            int gameUnknown = unknown.Count(c => c.File.StartsWith("source/game/", StringComparison.Ordinal));
            int rageUnknown = unknown.Count(c => c.File.StartsWith("source/rage/", StringComparison.Ordinal));
            Catalog(sb, "desconocido", "⚪", "Desconocido", unknown,
                "Estos headers provienen de los nombres y descriptores RTTI registrados en [classes.csv](MemoryMap/classes.csv). Se conoce la identidad del tipo y la dirección de su descriptor; no hay destinos de métodos asociados en el inventario actual. No implica que el tipo carezca de métodos. Este grupo incluye " + N(gameUnknown) + " headers de game y " + N(rageUnknown) + " de rage sin referencias conocidas. [Análisis de tipos sin métodos](../reversing/UnknownTypesAnalysis/README.md).");

            line("## Funciones fuera del inventario de clases");
            line("");
            if (outside.Count == 0) line("Ninguna.");
            else
            {
                line("Los siguientes propietarios son espacios de nombres, no clases RTTI; por eso no se clasifica todo el motor como parcialmente revertido.");
                line("");
                line("| Función | Implementación | Evidencia |");
                line("| --- | --- | --- |");
                foreach (var r in outside)
                    line("| `" + r.Get("class") + "::" + r.Get("fn_name") + "` | [" + r.Get("source") + "](../" + r.Get("source") + ") | [" + Path.GetFileName(r.Get("evidence")) + "](../" + r.Get("evidence") + ") |");
            }
            line("");
            line("<a id=\"metodo\"></a>");
            line("## Cómo leer y actualizar");
            line("");
            line("- **Completamente revertida:** todos los métodos de un inventario exhaustivo (`reversing/HookRegistry/exhaustive-classes.txt`) están reconstruidos. El inventario actual no permite acreditar esta categoría.");
            line("- **Parcialmente revertida:** tiene al menos una función reconstruida y todavía no se acredita la reconstrucción completa de la clase.");
            line("- **Sin revertir:** ninguna función registrada como reconstruida. Puede tener direcciones y llamadas al original comprobadas.");
            line("- **Desconocido:** tipo identificado por RTTI, sin direcciones de métodos asociadas. La reconstrucción todavía no puede medirse.");
            line("- `reversed=1` mide reconstrucción; `reconstruction_validated=1` acredita la prueba de esa reconstrucción. `validated=1` también puede acreditar solo una llamada al original. Los porcentajes no miden estabilidad del juego ni vigencia completa del ASI.");
            line("- 📚 marca las clases con referencias de nombres en [IV-SDK](../contrib/IV%20SDK/IV-SDK-main), plugin_IV e IV-SDK.Net ([cruce de offsets](MemoryMap/SdkCrossReference.md)). Son pistas no validadas; el EXE canónico decide.");
            line("");
            line("Actualizar el catálogo `hooks.csv` con `python reversing/HookRegistry/generate.py` y regenerar este documento y la clasificación de procedencia con las herramientas en C#:");
            line("");
            line("```powershell");
            line("& \"$(& \"${env:ProgramFiles(x86)}\\Microsoft Visual Studio\\Installer\\vswhere.exe\" -latest -products '*' -property installationPath)\\MSBuild\\Current\\Bin\\MSBuild.exe\" tools/ReIV.Tools/ReIV.Tools.csproj /p:Configuration=Release /v:minimal");
            line("bin\\tools\\ReIV.Tools.exe");
            line("```");
            line("");
            line("El detalle de direcciones, fuentes, pruebas y alcance permanece en [hooks.csv](hooks.csv) y [Clases y hooks](MemoryMap/ClassesAndHooks.md).");

            Repo.WriteText(Path.Combine(root, "docs", "ReversedClasses.md"), sb.ToString());
            Console.WriteLine("ReversedClasses: completas " + complete.Count + ", parciales " + partial.Count + ", sin revertir " + unreversed.Count + ", desconocido " + unknown.Count + " de " + totalClasses);
        }

        static string Cell(ClassInfo c)
        {
            var s = "[" + Label(c.Name) + "](../" + c.File + ") (" + c.Known.Count + ")";
            if (c.Reconstructed.Count > 0) s += " · R " + c.Reconstructed.Count;
            if (c.Validated.Count > 0) s += " · ✅ " + c.Validated.Count;
            if (c.References.Count > 0) s += " · 📚 " + string.Join(", ", c.References);
            return s;
        }

        static void Catalog(StringBuilder sb, string anchor, string icon, string title, List<ClassInfo> rows, string intro)
        {
            sb.Append("<a id=\"" + anchor + "\"></a>\n");
            sb.Append("## " + icon + " " + title + " · " + N(rows.Count) + " clases\n\n");
            if (rows.Count == 0) { sb.Append("Ninguna clase en esta categoría.\n\n"); return; }
            sb.Append(intro + "\n\n");
            sb.Append("<details>\n<summary>Mostrar catálogo de clases " + title.ToLowerInvariant() + "</summary>\n\n");
            sb.Append("| Clase (destinos) | Clase (destinos) | Clase (destinos) |\n| --- | --- | --- |\n");
            int height = (rows.Count + 2) / 3;
            for (int i = 0; i < height; i++)
            {
                var cells = new List<string>();
                for (int col = 0; col < 3; col++)
                {
                    int position = i + col * height;
                    cells.Add(position < rows.Count ? Cell(rows[position]) : "");
                }
                sb.Append("| " + string.Join(" | ", cells) + " |\n");
            }
            sb.Append("\n</details>\n\n");
        }

        static void Table(StringBuilder sb, string anchor, string icon, string title, List<ClassInfo> rows)
        {
            sb.Append("<a id=\"" + anchor + "\"></a>\n");
            sb.Append("## " + icon + " " + title + " · " + N(rows.Count) + " clases\n\n");
            if (rows.Count == 0) { sb.Append("Ninguna clase en esta categoría.\n\n"); return; }
            sb.Append("Orden alfabético para localizar clases. Revertidas / total cuenta destinos distintos (conocidos más reconstruidos); el inventario no es exhaustivo.\n\n");
            sb.Append("| Clase | Revertidas / total | Pendientes | Avance | Validated | Locked | Referencias |\n| --- | ---: | ---: | --- | ---: | ---: | --- |\n");
            foreach (var c in rows)
                sb.Append("| [" + Label(c.Name) + "](../" + c.File + ") | " + c.Reconstructed.Count + " / " + c.Total + " | " + c.Pending + " | `" + Bar(c.Reconstructed.Count, c.Total, 10) + "` " +
                    Pct(c.Reconstructed.Count, c.Total) + " | " + c.Validated.Count + " | " + c.Locked + " | " + (c.References.Count > 0 ? "📚 " + string.Join(", ", c.References) : "") + " |\n");
            sb.Append("\n");
        }
    }
}
