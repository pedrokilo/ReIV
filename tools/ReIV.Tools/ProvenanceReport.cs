using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ReIV.Tools
{
    /// <summary>
    /// Clasificacion de funciones binarias (Binary Function Classification) y analisis de procedencia de
    /// dependencias (Dependency Provenance Analysis) sobre el EXE canonico 1.0.7.0.
    /// Solo usa evidencia ya inventariada (RTTI/vtables, referencias de SDK, catalogo); no desensambla.
    /// </summary>
    public static class ProvenanceReport
    {
        public const string Unknown = "Sin procedencia identificada";
        public const string Shared = "Compartida entre varios origenes";
        static readonly string[] StatusOrder =
        {
            "Completamente revertidas", "Parcialmente revertidas", "Sin revertir", "Desconocido"
        };

        public sealed class Entry
        {
            public long Va;
            public string Section = "", Kind = "codigo", Provenance = Unknown, Basis = "ninguna", Status = "Desconocido";
            public int BodyBytes;
            public List<string> Owners = new List<string>();
            public List<string> Names = new List<string>();
        }

        /// <summary>Procedencia segun el espacio de nombres del propietario.</summary>
        public static string GroupOf(string owner)
        {
            if (owner == "rage" || owner.StartsWith("rage::", StringComparison.Ordinal)) return "RAGE (motor)";
            if (owner.StartsWith("ART::", StringComparison.Ordinal)) return "ART (NaturalMotion)";
            if (owner.StartsWith("NMutils::", StringComparison.Ordinal)) return "NMutils";
            return "GTA IV (juego)";
        }

        public static void Write(string root)
        {
            var memory = Path.Combine(root, "docs", "MemoryMap");
            var sections = Repo.LoadSections(root);

            // Propietarios por direccion (slots virtuales y referencias de SDK/patrones).
            var owners = new Dictionary<long, SortedSet<string>>();
            foreach (var r in Csv.Read(Path.Combine(memory, "pending_hooks.csv")))
            {
                var va = Csv.Hex(r.Get("va"));
                if (va < 0) continue;
                SortedSet<string> set;
                if (!owners.TryGetValue(va, out set)) owners[va] = set = new SortedSet<string>(StringComparer.Ordinal);
                set.Add(r.Get("owner"));
            }

            // El catalogo de reconstruccion tambien atribuye cada direccion a su clase.
            foreach (var r in Csv.Read(Path.Combine(root, "docs", "hooks.csv")))
            {
                var va = Csv.Hex(r.Get("address"));
                if (va < 0 || r.Get("class").Length == 0) continue;
                SortedSet<string> set;
                if (!owners.TryGetValue(va, out set)) owners[va] = set = new SortedSet<string>(StringComparer.Ordinal);
                set.Add(r.Get("class"));
            }

            // Nombres de referencia por direccion (IV-SDK, IV-SDK.Net, plugin_IV).
            var names = new Dictionary<long, SortedSet<string>>();
            Action<long, string> addName = (va, n) =>
            {
                if (va < 0 || string.IsNullOrEmpty(n)) return;
                SortedSet<string> set;
                if (!names.TryGetValue(va, out set)) names[va] = set = new SortedSet<string>(StringComparer.Ordinal);
                set.Add(n);
            };
            foreach (var r in Csv.Read(Path.Combine(memory, "sdk_addresses.csv")))
                addName(Csv.Hex(r.Get("va")), "IV-SDK:" + r.Get("name"));
            foreach (var r in Csv.Read(Path.Combine(memory, "sdknet_addresses.csv")))
                if (r.Get("kind") != "byte_pattern") addName(Csv.Hex(r.Get("va")), "IV-SDK.Net:" + r.Get("owner") + "::" + r.Get("name"));
            foreach (var r in Csv.Read(Path.Combine(memory, "plugin_iv_patterns.csv")))
                addName(Csv.Hex(r.Get("target_va")), "plugin_IV:" + r.Get("owner") + "::" + r.Get("name"));

            // Estado de reversion por RVA (catalogo hooks.csv).
            var reconstructed = new Dictionary<long, bool>(); // rva -> validada
            foreach (var r in Csv.Read(Path.Combine(root, "docs", "hooks.csv")))
            {
                if (r.Get("reversed") != "1") continue;
                var rva = Csv.Hex(r.Get("rva"));
                bool validated = r.Get("reconstruction_validated") == "1";
                bool previous;
                reconstructed[rva] = reconstructed.TryGetValue(rva, out previous) ? (previous || validated) : validated;
            }

            var entries = new Dictionary<long, Entry>();
            foreach (var r in Csv.Read(Path.Combine(memory, "code_addresses.csv")))
            {
                var e = Classify(Csv.Hex(r.Get("va")), owners, names, reconstructed, sections);
                e.Section = r.Get("section");
                e.Kind = r.Get("thunk") == "true" ? "thunk" : "codigo";
                int bytes; int.TryParse(r.Get("body_bytes"), out bytes); e.BodyBytes = bytes;
                entries[e.Va] = e;
            }

            WriteFunctionClassification(root, entries);
            WriteDependencyProvenance(root, sections, owners, names, reconstructed, entries);
        }

        static Entry Classify(long va, Dictionary<long, SortedSet<string>> owners, Dictionary<long, SortedSet<string>> names,
                              Dictionary<long, bool> reconstructed, List<Section> sections)
        {
            var e = new Entry { Va = va };
            SortedSet<string> o;
            if (owners.TryGetValue(va, out o)) e.Owners.AddRange(o);
            SortedSet<string> n;
            if (names.TryGetValue(va, out n)) e.Names.AddRange(n);

            var groups = new SortedSet<string>(e.Owners.Select(GroupOf), StringComparer.Ordinal);
            if (groups.Count > 0) e.Basis = "RTTI/vtable, referencia o catalogo con propietario";
            else if (e.Names.Count > 0)
            {
                foreach (var name in e.Names)
                {
                    var q = name.Substring(name.IndexOf(':') + 1);
                    var ownerPart = q.Contains("::") ? q.Substring(0, q.LastIndexOf("::", StringComparison.Ordinal)) : "";
                    groups.Add(ownerPart.Length > 0 ? GroupOf(ownerPart) : "GTA IV (juego)");
                }
                e.Basis = "solo nombre de referencia (SDK)";
            }
            e.Provenance = groups.Count == 0 ? Unknown : groups.Count == 1 ? groups.First() : Shared;

            bool validated;
            long rva = va - Repo.ImageBase;
            if (reconstructed.TryGetValue(rva, out validated)) e.Status = validated ? "Completamente revertidas" : "Parcialmente revertidas";
            else e.Status = e.Provenance == Unknown ? "Desconocido" : "Sin revertir";
            return e;
        }

        static string Cap(IList<string> items, int max)
        {
            if (items.Count <= max) return string.Join(";", items);
            return string.Join(";", items.Take(max)) + ";(+" + (items.Count - max) + ")";
        }

        static string Bar(int value, int total)
        {
            int filled = total == 0 ? 0 : (int)Math.Round(20.0 * value / total);
            return new string('█', filled) + new string('░', 20 - filled);
        }

        static void WriteFunctionClassification(string root, Dictionary<long, Entry> entries)
        {
            var memory = Path.Combine(root, "docs", "MemoryMap");
            var ordered = entries.Values.OrderBy(e => e.Va).ToList();
            Csv.Write(Path.Combine(memory, "function_classification.csv"),
                new[] { "va", "rva", "section", "kind", "body_bytes", "provenance", "basis", "status", "owners", "reference_names" },
                ordered.Select(e => (IList<string>)new[]
                {
                    "0x" + e.Va.ToString("x8"), "0x" + (e.Va - Repo.ImageBase).ToString("x8"), e.Section, e.Kind, e.BodyBytes.ToString(),
                    e.Provenance, e.Basis, e.Status, Cap(e.Owners, 8), Cap(e.Names, 6)
                }));

            var provenances = new[] { "GTA IV (juego)", "RAGE (motor)", "ART (NaturalMotion)", "NMutils", Shared, Unknown };
            var sb = new StringBuilder();
            sb.AppendLine("# Clasificación de funciones binarias");
            sb.AppendLine();
            sb.AppendLine("[Inicio](../../README.md) · [Mapa de memoria](README.md) · [Procedencia de dependencias](DependencyProvenance.md) · [Progreso del reversing](../ReversedClasses.md)");
            sb.AppendLine();
            sb.AppendLine("> Generado por `tools/ReIV.Tools` (C#) a partir de los CSV de este directorio y de `docs/hooks.csv`. Sobre el EXE canónico `ab21c0d90d2ca1c697785aca9dcf44635e1f8d48aa0df1d737e9190bddf0cb4c`.");
            sb.AppendLine();
            sb.AppendLine("Este documento es una **clasificación de funciones binarias** (*Binary Function Classification*, parte del análisis estático de binarios): cada entrada de código del EXE recibe una **procedencia** y un **estado de reversión**. No desensambla ni valida comportamiento; solo cruza la evidencia ya inventariada.");
            sb.AppendLine();
            sb.AppendLine("## Criterios");
            sb.AppendLine();
            sb.AppendLine("- **Procedencia** (por el propietario RTTI del destino o, si solo hay nombre de referencia, por el espacio de nombres del nombre): GTA IV (juego), RAGE (motor), ART (NaturalMotion), NMutils, compartida entre varios orígenes o sin procedencia identificada. **No** distingue CRT, RenderWare-equivalente ni código generado: eso exige desensamblado y queda como *sin procedencia identificada*.");
            sb.AppendLine("- **Estado de reversión**, en este orden: **Completamente revertidas** (reconstruida y con prueba aprobada), **Parcialmente revertidas** (reconstruida sin prueba aprobada), **Sin revertir** (procedencia identificada, sin reconstrucción) y **Desconocido** (sin procedencia).");
            sb.AppendLine("- Una entrada de código no es una función demostrada; los límites son los detectados por Ghidra y los destinos de vtables.");
            sb.AppendLine();
            sb.AppendLine("## Resumen");
            sb.AppendLine();
            sb.AppendLine("| Dimensión | Progreso | Medición |");
            sb.AppendLine("| --- | --- | --- |");
            int total = ordered.Count;
            foreach (var status in StatusOrder)
            {
                int c = ordered.Count(e => e.Status == status);
                sb.AppendLine("| " + status + " | `" + Bar(c, total) + "` | " + c.ToString("N0") + "/" + total.ToString("N0") + " · " + (total == 0 ? 0 : 100.0 * c / total).ToString("0.00") + "% |");
            }
            sb.AppendLine();
            sb.AppendLine("## Procedencia por estado");
            sb.AppendLine();
            sb.AppendLine("| Procedencia | " + string.Join(" | ", StatusOrder) + " | Total |");
            sb.AppendLine("| --- | " + string.Join(" | ", StatusOrder.Select(s => "---:")) + " | ---: |");
            foreach (var p in provenances)
            {
                var group = ordered.Where(e => e.Provenance == p).ToList();
                sb.AppendLine("| " + p + " | " + string.Join(" | ", StatusOrder.Select(s => group.Count(e => e.Status == s).ToString("N0"))) + " | " + group.Count.ToString("N0") + " |");
            }
            sb.AppendLine("| **Total** | " + string.Join(" | ", StatusOrder.Select(s => ordered.Count(e => e.Status == s).ToString("N0"))) + " | " + total.ToString("N0") + " |");
            sb.AppendLine();
            sb.AppendLine("## Base de la clasificación");
            sb.AppendLine();
            sb.AppendLine("| Base | Entradas |");
            sb.AppendLine("| --- | ---: |");
            foreach (var g in ordered.GroupBy(e => e.Basis).OrderByDescending(g => g.Count()))
                sb.AppendLine("| " + g.Key + " | " + g.Count().ToString("N0") + " |");
            sb.AppendLine();
            sb.AppendLine("## Secciones por estado");
            sb.AppendLine();
            foreach (var status in StatusOrder)
            {
                var group = ordered.Where(e => e.Status == status).ToList();
                sb.AppendLine("### " + status + " · " + group.Count.ToString("N0") + " entradas");
                sb.AppendLine();
                if (group.Count == 0) { sb.AppendLine("Ninguna entrada en esta categoría."); sb.AppendLine(); continue; }
                sb.AppendLine("| Sección del PE | Entradas |");
                sb.AppendLine("| --- | ---: |");
                foreach (var s in group.GroupBy(e => e.Section).OrderByDescending(s => s.Count()))
                    sb.AppendLine("| `" + s.Key + "` | " + s.Count().ToString("N0") + " |");
                sb.AppendLine();
            }
            sb.AppendLine("Detalle por dirección en [function_classification.csv](function_classification.csv).");
            sb.AppendLine();
            Repo.WriteText(Path.Combine(memory, "FunctionClassification.md"), sb.ToString());
            Console.WriteLine("FunctionClassification: " + total.ToString("N0") + " entradas; " +
                string.Join("; ", StatusOrder.Select(s => s + " " + ordered.Count(e => e.Status == s))));
        }

        // ---- dependencias de los cuerpos reconstruidos ----
        sealed class Dependency
        {
            public long Va; public string Identifier = "", Kind = "", Section = "";
            public int Uses; public SortedSet<string> Modules = new SortedSet<string>(StringComparer.Ordinal);
        }

        static void WriteDependencyProvenance(string root, List<Section> sections, Dictionary<long, SortedSet<string>> owners,
            Dictionary<long, SortedSet<string>> names, Dictionary<long, bool> reconstructed, Dictionary<long, Entry> entries)
        {
            var headerPath = Path.Combine(root, "source", "game", "Peds", "CPlayerPed.h");
            var text = File.ReadAllText(headerPath, Encoding.UTF8).Replace("\r\n", "\n");
            var banners = Regex.Matches(text, @"^// =+\n// (\w+)\n// =+$", RegexOptions.Multiline)
                .Cast<Match>().Select(m => new KeyValuePair<int, string>(m.Index, m.Groups[1].Value)).ToList();
            Func<int, string> moduleAt = pos =>
            {
                string name = "CPlayerPed";
                foreach (var b in banners) { if (b.Key <= pos) name = b.Value; else break; }
                return name;
            };

            var deps = new Dictionary<long, Dependency>();
            var rx = new Regex(@"\b(call|query|resolve|state|ticks|before|threshold|modelAt|load|g|object|table)([0-9A-Fa-f]{6,8})\b");
            foreach (Match m in rx.Matches(text))
            {
                // Comentarios de linea no cuentan como uso.
                int lineStart = text.LastIndexOf('\n', m.Index) + 1;
                var prefix = text.Substring(lineStart, m.Index - lineStart);
                if (prefix.Contains("//")) continue;
                long va = Csv.Hex(m.Groups[2].Value);
                if (va < Repo.ImageBase) continue;
                Dependency d;
                if (!deps.TryGetValue(va, out d))
                {
                    var section = Repo.SectionOf(sections, va);
                    deps[va] = d = new Dependency
                    {
                        Va = va, Identifier = m.Value,
                        Section = section == null ? "(fuera de la imagen)" : section.Name,
                        Kind = section == null ? "desconocido" : section.Executable ? "funcion" : "dato"
                    };
                }
                d.Uses++;
                d.Modules.Add(moduleAt(m.Index));
            }

            var rows = new List<string[]>();
            var functions = deps.Values.Where(d => d.Kind == "funcion").OrderBy(d => d.Va).ToList();
            var data = deps.Values.Where(d => d.Kind != "funcion").OrderBy(d => d.Va).ToList();
            var functionEntries = new List<KeyValuePair<Dependency, Entry>>();
            foreach (var d in functions)
            {
                Entry e;
                if (!entries.TryGetValue(d.Va, out e)) e = Classify(d.Va, owners, names, reconstructed, sections);
                functionEntries.Add(new KeyValuePair<Dependency, Entry>(d, e));
            }

            Csv.Write(Path.Combine(root, "docs", "MemoryMap", "dependency_provenance.csv"),
                new[] { "va", "rva", "kind", "section", "provenance", "basis", "status", "owners", "reference_names", "uses", "modules" },
                functionEntries.Select(p => (IList<string>)new[]
                {
                    "0x" + p.Key.Va.ToString("x8"), "0x" + (p.Key.Va - Repo.ImageBase).ToString("x8"), "funcion", p.Key.Section,
                    p.Value.Provenance, p.Value.Basis, p.Value.Status, Cap(p.Value.Owners, 6), Cap(p.Value.Names, 4),
                    p.Key.Uses.ToString(), string.Join(";", p.Key.Modules)
                }).Concat(data.Select(d =>
                {
                    SortedSet<string> n;
                    var nm = names.TryGetValue(d.Va, out n) ? n.ToList() : new List<string>();
                    return (IList<string>)new[]
                    {
                        "0x" + d.Va.ToString("x8"), "0x" + (d.Va - Repo.ImageBase).ToString("x8"), d.Kind, d.Section,
                        nm.Count > 0 ? "Dato con nombre de referencia" : "Dato global sin nombre", nm.Count > 0 ? "nombre de referencia (SDK)" : "ninguna",
                        "n/a", "", Cap(nm, 4), d.Uses.ToString(), string.Join(";", d.Modules)
                    };
                })));

            var sb = new StringBuilder();
            sb.AppendLine("# Procedencia de dependencias");
            sb.AppendLine();
            sb.AppendLine("[Inicio](../../README.md) · [Mapa de memoria](README.md) · [Clasificación de funciones](FunctionClassification.md) · [Progreso del reversing](../ReversedClasses.md)");
            sb.AppendLine();
            sb.AppendLine("> Generado por `tools/ReIV.Tools` (C#) a partir de [CPlayerPed.h](../../source/game/Peds/CPlayerPed.h) y de los CSV de este directorio.");
            sb.AppendLine();
            sb.AppendLine("Este documento es un **análisis de procedencia de dependencias** (*Dependency Provenance Analysis*): para los cuerpos de CPlayerPed ya reconstruidos, cada dirección externa que invocan o leen (`call…`, `g…`, `object…`, `table…` y las funciones de sus estructuras de dependencias) se clasifica por su **procedencia**. Los cuerpos siguen dependiendo del EXE para todo lo listado aquí; reconstruirlo es trabajo pendiente.");
            sb.AppendLine();
            sb.AppendLine("## Resumen");
            sb.AppendLine();
            sb.AppendLine("| Medida | Cantidad |");
            sb.AppendLine("| --- | ---: |");
            sb.AppendLine("| Direcciones externas distintas | " + deps.Count + " |");
            sb.AppendLine("| Funciones (sección ejecutable) | " + functions.Count + " |");
            sb.AppendLine("| Datos globales | " + data.Count + " |");
            sb.AppendLine("| Usos en el código | " + deps.Values.Sum(d => d.Uses) + " |");
            sb.AppendLine();
            sb.AppendLine("### Funciones por procedencia y estado");
            sb.AppendLine();
            sb.AppendLine("| Procedencia | " + string.Join(" | ", StatusOrder) + " | Total |");
            sb.AppendLine("| --- | " + string.Join(" | ", StatusOrder.Select(s => "---:")) + " | ---: |");
            foreach (var p in new[] { "GTA IV (juego)", "RAGE (motor)", "ART (NaturalMotion)", "NMutils", Shared, Unknown })
            {
                var group = functionEntries.Where(x => x.Value.Provenance == p).ToList();
                sb.AppendLine("| " + p + " | " + string.Join(" | ", StatusOrder.Select(s => group.Count(x => x.Value.Status == s).ToString())) + " | " + group.Count + " |");
            }
            sb.AppendLine();
            sb.AppendLine("Las funciones sin procedencia identificada no se atribuyen a CRT, RenderWare-equivalente ni código generado: esa separación exige desensamblar cada destino y queda pendiente.");
            sb.AppendLine();
            sb.AppendLine("## Funciones externas");
            sb.AppendLine();
            sb.AppendLine("| Dirección | Procedencia | Propietarios | Nombres de referencia | Estado | Usos | Módulos |");
            sb.AppendLine("| --- | --- | --- | --- | --- | ---: | --- |");
            foreach (var p in functionEntries.OrderBy(x => ProvenanceRank(x.Value.Provenance)).ThenBy(x => x.Key.Va))
                sb.AppendLine("| `0x" + p.Key.Va.ToString("x8") + "` | " + p.Value.Provenance + " | " + Escape(Cap(p.Value.Owners, 3)) + " | " + Escape(Cap(p.Value.Names, 3)) +
                    " | " + p.Value.Status + " | " + p.Key.Uses + " | " + string.Join(", ", p.Key.Modules) + " |");
            sb.AppendLine();
            sb.AppendLine("## Datos globales");
            sb.AppendLine();
            sb.AppendLine("| Dirección | Sección | Nombre de referencia | Usos | Módulos |");
            sb.AppendLine("| --- | --- | --- | ---: | --- |");
            foreach (var d in data)
            {
                SortedSet<string> n;
                var nm = names.TryGetValue(d.Va, out n) ? n.ToList() : new List<string>();
                sb.AppendLine("| `0x" + d.Va.ToString("x8") + "` | `" + d.Section + "` | " + (nm.Count > 0 ? Escape(Cap(nm, 3)) : "—") + " | " + d.Uses + " | " + string.Join(", ", d.Modules) + " |");
            }
            sb.AppendLine();
            sb.AppendLine("Detalle completo en [dependency_provenance.csv](dependency_provenance.csv).");
            sb.AppendLine();
            Repo.WriteText(Path.Combine(root, "docs", "MemoryMap", "DependencyProvenance.md"), sb.ToString());
            Console.WriteLine("DependencyProvenance: " + deps.Count + " direcciones (" + functions.Count + " funciones, " + data.Count + " datos)");
        }

        static int ProvenanceRank(string p)
        {
            return p == "GTA IV (juego)" ? 0 : p == "RAGE (motor)" ? 1 : p == "ART (NaturalMotion)" ? 2 : p == "NMutils" ? 3 : p == Shared ? 4 : 5;
        }

        static string Escape(string s)
        {
            return string.IsNullOrEmpty(s) ? "—" : s.Replace("|", "\\|").Replace("<", "&lt;").Replace(">", "&gt;");
        }
    }
}
