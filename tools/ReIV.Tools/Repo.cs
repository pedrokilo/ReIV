using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Web.Script.Serialization;

namespace ReIV.Tools
{
    public sealed class Section
    {
        public string Name; public long Va; public long Size; public bool Executable;
    }

    /// <summary>Raiz del repositorio y datos comunes (secciones del PE, texto en UTF-8 sin BOM).</summary>
    public static class Repo
    {
        public const long ImageBase = 0x400000;

        public static string FindRoot(string start)
        {
            var dir = new DirectoryInfo(start);
            while (dir != null)
            {
                if (File.Exists(Path.Combine(dir.FullName, "README.md")) && Directory.Exists(Path.Combine(dir.FullName, "docs", "MemoryMap")))
                    return dir.FullName;
                dir = dir.Parent;
            }
            throw new InvalidOperationException("No se encontro la raiz de ReIV (README.md y docs/MemoryMap).");
        }

        public static List<Section> LoadSections(string root)
        {
            var json = File.ReadAllText(Path.Combine(root, "docs", "MemoryMap", "sections.json"), Encoding.UTF8);
            var list = new List<Section>();
            foreach (var item in new JavaScriptSerializer().Deserialize<object[]>(json))
            {
                var d = (Dictionary<string, object>)item;
                list.Add(new Section
                {
                    Name = (string)d["name"],
                    Va = Convert.ToInt64(d["va"]),
                    Size = Math.Max(Convert.ToInt64(d["virtual_size"]), Convert.ToInt64(d["raw_size"])),
                    Executable = (bool)d["executable"]
                });
            }
            return list;
        }

        public static Section SectionOf(List<Section> sections, long va)
        {
            foreach (var s in sections) if (va >= s.Va && va < s.Va + s.Size) return s;
            return null;
        }

        public static void WriteText(string path, string text)
        {
            File.WriteAllText(path, text.Replace("\r\n", "\n"), new UTF8Encoding(false));
        }

        public static string Rel(string root, string path)
        {
            return path.Substring(root.Length).TrimStart('\\', '/').Replace('\\', '/');
        }
    }
}
