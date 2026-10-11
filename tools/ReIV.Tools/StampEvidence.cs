using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Web.Script.Serialization;

namespace ReIV.Tools
{
    /// <summary>
    /// Vincula la evidencia de pruebas con los hashes de los .h y .cpp de cada fuente del catalogo.
    /// Debe ejecutarse justo despues de repetir las pruebas dentro del juego: solo sella una evidencia cuyo
    /// `implementation_sha256` coincide con el .h actual (es decir, que no quedo obsoleta). No toca las que ya
    /// tienen `additional_source_sha256`.
    /// </summary>
    public static class StampEvidence
    {
        static string Sha(string path)
        {
            using (var sha = SHA256.Create())
                return string.Concat(sha.ComputeHash(File.ReadAllBytes(path)).Select(b => b.ToString("x2")));
        }

        public static int Run(string root)
        {
            var catalog = new JavaScriptSerializer { MaxJsonLength = int.MaxValue }
                .Deserialize<object[]>(File.ReadAllText(Path.Combine(root, "reversing", "HookRegistry", "catalog.json"), Encoding.UTF8));
            var sourcesByEvidence = new Dictionary<string, SortedSet<string>>(StringComparer.Ordinal);
            foreach (Dictionary<string, object> row in catalog.Cast<Dictionary<string, object>>())
            {
                var source = (string)row["source"]; var evidence = (string)row["evidence"];
                if (!source.EndsWith(".h", StringComparison.Ordinal) || source.EndsWith("CPlayerPed.h", StringComparison.Ordinal)) continue;
                var cpp = Path.ChangeExtension(Path.Combine(root, source), ".cpp");
                if (!File.Exists(cpp)) continue;
                SortedSet<string> set;
                if (!sourcesByEvidence.TryGetValue(evidence, out set)) sourcesByEvidence[evidence] = set = new SortedSet<string>(StringComparer.Ordinal);
                set.Add(source);
            }

            int stamped = 0, stale = 0, already = 0, unsupported = 0;
            foreach (var pair in sourcesByEvidence.OrderBy(p => p.Key, StringComparer.Ordinal))
            {
                var path = Path.Combine(root, pair.Key);
                if (!File.Exists(path)) { Console.WriteLine("SIN ARCHIVO " + pair.Key); unsupported++; continue; }
                var text = File.ReadAllText(path, Encoding.UTF8);
                if (text.Contains("\"additional_source_sha256\"")) { already++; continue; }
                var recorded = new HashSet<string>(Regex.Matches(text, "\"(?:implementation_sha256|wrapper_sha256|scalar_implementation_sha256)\"\\s*:\\s*\"([0-9a-f]{64})\"")
                    .Cast<Match>().Select(m => m.Groups[1].Value));
                var hashesBlock = Regex.Match(text, "\"(?:hashes|source_sha256)\"\\s*:\\s*\\{(.*?)\\}", RegexOptions.Singleline);
                foreach (Match m in Regex.Matches(hashesBlock.Success ? hashesBlock.Groups[1].Value : "", "\"([0-9a-f]{64})\"")) recorded.Add(m.Groups[1].Value);
                if (recorded.Count == 0) { Console.WriteLine("SIN HASH " + pair.Key); unsupported++; continue; }
                // Todas las fuentes del catalogo ligadas a esta evidencia deben coincidir con un hash registrado.
                if (pair.Value.Any(s => !recorded.Contains(Sha(Path.Combine(root, s)))))
                {
                    Console.WriteLine("OBSOLETA " + pair.Key + " (" + string.Join(", ", pair.Value.Where(s => !recorded.Contains(Sha(Path.Combine(root, s))))) + ")");
                    stale++; continue;
                }
                var entries = new List<string>();
                foreach (var s in pair.Value)
                {
                    var cpp = Path.ChangeExtension(s, ".cpp");
                    entries.Add("    \"" + s + "\":  \"" + Sha(Path.Combine(root, s)) + "\"");
                    entries.Add("    \"" + cpp + "\":  \"" + Sha(Path.Combine(root, cpp)) + "\"");
                }
                var eol = text.Contains("\r\n") ? "\r\n" : "\n";
                int last = text.LastIndexOf('}');
                var head = text.Substring(0, last).TrimEnd();
                var block = "  \"additional_source_sha256\":  {" + eol + string.Join("," + eol, entries) + eol + "  }";
                text = head + "," + eol + block + eol + "}" + text.Substring(last + 1);
                File.WriteAllText(path, text, new UTF8Encoding(false));
                stamped++;
            }
            Console.WriteLine("Evidencias selladas: " + stamped + "; obsoletas (repetir la prueba): " + stale + "; ya selladas: " + already + "; sin soporte: " + unsupported);
            return stale > 0 ? 1 : 0;
        }
    }
}
