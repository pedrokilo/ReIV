using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ReIV.Tools
{
    /// <summary>
    /// Mueve a un .cpp los cuerpos de las funciones libres `inline` de un header, dejando en el .h solo la declaracion.
    /// Variables inline, estructuras, plantillas y funciones dentro de clases permanecen en el header.
    /// Uso: ReIV.Tools split &lt;header&gt; [--include &lt;ruta&gt;]... [--keep &lt;nombre&gt;]...
    /// </summary>
    public static class SplitHeader
    {
        sealed class Block { public string Kind; public string Name; public int Open; }

        sealed class Found
        {
            public int DeclStart, BraceOpen, BraceClose;
            public string Signature = "", Body = "", Name = "";
            public List<string> Namespaces = new List<string>();
        }

        public static int Run(string[] args)
        {
            if (args.Length < 2) { Console.Error.WriteLine("Uso: split <header> [--include <ruta>]... [--keep <nombre>]..."); return 2; }
            var header = Path.GetFullPath(args[1]);
            var includes = new List<string>(); var keep = new HashSet<string>(StringComparer.Ordinal);
            for (int i = 2; i + 1 < args.Length; i += 2)
            {
                if (args[i] == "--include") includes.Add(args[i + 1]);
                else if (args[i] == "--keep") keep.Add(args[i + 1]);
            }
            var raw = File.ReadAllText(header, Encoding.UTF8);
            var eol = raw.Contains("\r\n") ? "\r\n" : "\n";
            var text = raw.Replace("\r\n", "\n");
            var found = Scan(text).Where(f => !keep.Contains(f.Name)).ToList();
            if (found.Count == 0) { Console.WriteLine(Path.GetFileName(header) + ": sin funciones libres que mover"); return 0; }

            // Cabecera: sustituye cada definicion por su declaracion.
            var sb = new StringBuilder(); int cursor = 0;
            foreach (var f in found)
            {
                sb.Append(text, cursor, f.DeclStart - cursor);
                sb.Append(Declaration(f.Signature)).Append(';');
                cursor = f.BraceClose + 1;
            }
            sb.Append(text, cursor, text.Length - cursor);
            var newHeader = sb.ToString();

            // Fuente.
            var cpp = new StringBuilder();
            cpp.Append("#include \"").Append(Path.GetFileName(header)).Append("\"\n");
            foreach (var inc in includes) cpp.Append("#include ").Append(inc.StartsWith("<") ? inc : "\"" + inc + "\"").Append('\n');
            cpp.Append('\n');
            List<string> current = null;
            foreach (var f in found)
            {
                if (current == null || !current.SequenceEqual(f.Namespaces))
                {
                    if (current != null) CloseNamespaces(cpp, current);
                    OpenNamespaces(cpp, f.Namespaces);
                    current = f.Namespaces;
                }
                cpp.Append(Definition(f.Signature)).Append(' ').Append(f.Body).Append("\n\n");
            }
            if (current != null) CloseNamespaces(cpp, current);

            File.WriteAllText(header, newHeader.Replace("\n", eol), new UTF8Encoding(false));
            File.WriteAllText(Path.ChangeExtension(header, ".cpp"), cpp.ToString().TrimEnd('\n').Replace("\n", eol) + eol, new UTF8Encoding(false));
            Console.WriteLine(Path.GetFileName(header) + ": " + found.Count + " funciones movidas a " + Path.GetFileName(Path.ChangeExtension(header, ".cpp")));
            return 0;
        }

        static void OpenNamespaces(StringBuilder sb, List<string> names)
        {
            foreach (var n in names) sb.Append("namespace ").Append(n).Append(" {\n");
        }

        static void CloseNamespaces(StringBuilder sb, List<string> names)
        {
            for (int i = names.Count - 1; i >= 0; i--) sb.Append("} // namespace ").Append(names[i]).Append('\n');
            sb.Append('\n');
        }

        // ---- firmas ----
        static readonly Regex LeadingKeywords = new Regex(@"^\s*(?:__declspec\s*\(\s*naked\s*\)\s*)?(?:inline\s+)", RegexOptions.Compiled);

        static string Declaration(string signature)
        {
            return LeadingKeywords.Replace(signature, "").Trim();
        }

        static string Definition(string signature)
        {
            var naked = Regex.Match(signature, @"^\s*__declspec\s*\(\s*naked\s*\)").Success ? "__declspec(naked) " : "";
            var sig = LeadingKeywords.Replace(signature, "").Trim();
            return naked + StripDefaults(sig);
        }

        /// <summary>Quita los valores por defecto de los parametros (solo valen en la declaracion).</summary>
        static string StripDefaults(string signature)
        {
            int open = signature.IndexOf('(');
            int close = signature.LastIndexOf(')');
            if (open < 0 || close < open) return signature;
            var args = signature.Substring(open + 1, close - open - 1);
            if (!args.Contains("=")) return signature;
            var parts = new List<string>(); int depth = 0; var cur = new StringBuilder();
            foreach (char c in args)
            {
                if (c == '(' || c == '<' || c == '{' || c == '[') depth++;
                if (c == ')' || c == '>' || c == '}' || c == ']') depth--;
                if (c == ',' && depth == 0) { parts.Add(cur.ToString()); cur.Clear(); } else cur.Append(c);
            }
            parts.Add(cur.ToString());
            var cleaned = parts.Select(p => { int eq = p.IndexOf('='); return eq >= 0 ? p.Substring(0, eq).TrimEnd() : p; });
            return signature.Substring(0, open + 1) + string.Join(", ", cleaned) + signature.Substring(close);
        }

        // ---- escaner de bloques ----
        static List<Found> Scan(string text)
        {
            var result = new List<Found>();
            var stack = new List<Block>();
            var clean = Mask(text);
            for (int i = 0; i < clean.Length; i++)
            {
                char c = clean[i];
                if (c == '{')
                {
                    var before = clean.Substring(Math.Max(0, i - 400), Math.Min(i, 400));
                    var block = new Block { Open = i };
                    var ns = Regex.Match(before, @"\bnamespace\s+([\w:]+)\s*$");
                    var nsAnon = Regex.Match(before, @"\bnamespace\s*$");
                    if (ns.Success) { block.Kind = "ns"; block.Name = ns.Groups[1].Value; }
                    else if (nsAnon.Success) { block.Kind = "ns"; block.Name = ""; }
                    else if (Regex.IsMatch(before, @"\)\s*(?:const\s*)?(?:noexcept\s*)?(?:->\s*[\w:<>\*&\s]+)?\s*$")) block.Kind = "fn";
                    else block.Kind = "other";
                    stack.Add(block);
                }
                else if (c == '}')
                {
                    if (stack.Count == 0) continue;
                    var block = stack[stack.Count - 1]; stack.RemoveAt(stack.Count - 1);
                    if (block.Kind == "fn" && stack.All(b => b.Kind == "ns"))
                    {
                        var f = Build(text, clean, block.Open, i, stack);
                        if (f != null) result.Add(f);
                    }
                }
            }
            return result.OrderBy(f => f.DeclStart).ToList();
        }

        static Found Build(string text, string clean, int open, int close, List<Block> stack)
        {
            // Inicio de la declaracion: tras el ultimo ';', '}' o '{' previo y saltando preprocesador y comentarios.
            int boundary = -1;
            for (int j = open - 1; j >= 0; j--) if (clean[j] == ';' || clean[j] == '}' || clean[j] == '{') { boundary = j; break; }
            int start = boundary + 1;
            while (true)
            {
                while (start < open && char.IsWhiteSpace(clean[start])) start++;
                if (start < open && clean[start] == '#') { start = clean.IndexOf('\n', start) + 1; continue; }
                break;
            }
            // `Mask` sustituye comentarios por espacios, de modo que `start` ya cae en el primer token real.
            var signature = text.Substring(start, open - start).Trim();
            if (!Regex.IsMatch(signature, @"^(?:__declspec\s*\(\s*naked\s*\)\s*)?inline\b")) return null;
            if (Regex.IsMatch(signature, @"^(?:__declspec\s*\(\s*naked\s*\)\s*)?inline\s+(?:constexpr\s+)?auto\b")) return null;
            if (signature.Contains("constexpr") || signature.Contains("template") || signature.Contains("operator")) return null;
            int paren = signature.IndexOf('(');
            if (paren < 0) return null;
            if (signature.Substring(0, paren).Contains("=")) return null; // inicializador, no funcion
            // Nombre de la funcion (ultimo identificador antes del primer '(').
            var nameMatch = Regex.Match(signature.Substring(0, paren), @"(~?\w+)\s*$");
            if (!nameMatch.Success) return null;
            // Plantilla justo antes de la declaracion.
            var lead = clean.Substring(Math.Max(0, start - 60), start - Math.Max(0, start - 60)).TrimEnd();
            if (lead.EndsWith(">") && Regex.IsMatch(lead, @"template\s*<[^;{}]*>$")) return null;

            return new Found
            {
                DeclStart = start, BraceOpen = open, BraceClose = close,
                Signature = signature, Body = text.Substring(open, close - open + 1), Name = nameMatch.Groups[1].Value,
                Namespaces = stack.Where(b => b.Kind == "ns" && b.Name.Length > 0).SelectMany(b => b.Name.Split(new[] { "::" }, StringSplitOptions.RemoveEmptyEntries)).ToList()
            };
        }

        /// <summary>Sustituye comentarios, cadenas y caracteres por espacios para analizar llaves y tokens.</summary>
        static string Mask(string text)
        {
            var sb = new StringBuilder(text);
            int i = 0;
            while (i < text.Length)
            {
                if (text[i] == '/' && i + 1 < text.Length && text[i + 1] == '/')
                {
                    while (i < text.Length && text[i] != '\n') sb[i++] = ' ';
                }
                else if (text[i] == '/' && i + 1 < text.Length && text[i + 1] == '*')
                {
                    int end = text.IndexOf("*/", i + 2, StringComparison.Ordinal);
                    end = end < 0 ? text.Length : end + 2;
                    for (; i < end; i++) if (text[i] != '\n') sb[i] = ' ';
                }
                else if (text[i] == '"' || text[i] == '\'')
                {
                    char q = text[i]; bool raw = i > 0 && text[i - 1] == 'R' && q == '"';
                    if (raw)
                    {
                        int paren = text.IndexOf('(', i); var delim = text.Substring(i + 1, paren - i - 1);
                        int end = text.IndexOf(")" + delim + "\"", paren, StringComparison.Ordinal);
                        end = end < 0 ? text.Length : end + delim.Length + 2;
                        for (; i < end; i++) if (text[i] != '\n') sb[i] = ' ';
                        continue;
                    }
                    sb[i++] = ' ';
                    while (i < text.Length && text[i] != q && text[i] != '\n')
                    {
                        if (text[i] == '\\' && i + 1 < text.Length) { sb[i++] = ' '; }
                        sb[i++] = ' ';
                    }
                    if (i < text.Length && text[i] == q) sb[i++] = ' ';
                }
                else if (text[i] == '#' && (i == 0 || text[i - 1] == '\n'))
                {
                    // Lineas de preprocesador (con continuaciones): se conservan los '#include' pero no sus llaves.
                    int lineEnd = i;
                    while (lineEnd < text.Length)
                    {
                        int nl = text.IndexOf('\n', lineEnd);
                        if (nl < 0) { lineEnd = text.Length; break; }
                        lineEnd = nl;
                        if (nl > 0 && text[nl - 1] == '\\') { lineEnd = nl + 1; continue; }
                        break;
                    }
                    for (int k = i + 1; k < lineEnd; k++) if (text[k] != '\n') sb[k] = ' ';
                    i = lineEnd;
                }
                else i++;
            }
            return sb.ToString();
        }
    }
}
