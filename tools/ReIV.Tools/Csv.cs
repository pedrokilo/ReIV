using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ReIV.Tools
{
    /// <summary>Lector y escritor de CSV (RFC 4180) con cabecera.</summary>
    public static class Csv
    {
        public static List<Dictionary<string, string>> Read(string path)
        {
            var rows = new List<Dictionary<string, string>>();
            if (!File.Exists(path)) return rows;
            var text = File.ReadAllText(path, Encoding.UTF8);
            var records = Parse(text);
            if (records.Count == 0) return rows;
            var header = records[0];
            for (int i = 1; i < records.Count; i++)
            {
                var record = records[i];
                if (record.Count == 1 && record[0].Length == 0) continue;
                var row = new Dictionary<string, string>(header.Count);
                for (int c = 0; c < header.Count; c++) row[header[c]] = c < record.Count ? record[c] : "";
                rows.Add(row);
            }
            return rows;
        }

        static List<List<string>> Parse(string text)
        {
            var records = new List<List<string>>();
            var record = new List<string>();
            var field = new StringBuilder();
            bool quoted = false;
            for (int i = 0; i < text.Length; i++)
            {
                char c = text[i];
                if (quoted)
                {
                    if (c == '"')
                    {
                        if (i + 1 < text.Length && text[i + 1] == '"') { field.Append('"'); i++; }
                        else quoted = false;
                    }
                    else field.Append(c);
                }
                else if (c == '"') quoted = true;
                else if (c == ',') { record.Add(field.ToString()); field.Clear(); }
                else if (c == '\n' || c == '\r')
                {
                    if (c == '\r' && i + 1 < text.Length && text[i + 1] == '\n') i++;
                    record.Add(field.ToString()); field.Clear();
                    records.Add(record); record = new List<string>();
                }
                else field.Append(c);
            }
            if (field.Length > 0 || record.Count > 0) { record.Add(field.ToString()); records.Add(record); }
            return records;
        }

        public static void Write(string path, IList<string> columns, IEnumerable<IList<string>> rows)
        {
            using (var writer = new StreamWriter(path, false, new UTF8Encoding(false)))
            {
                writer.NewLine = "\n";
                writer.WriteLine(Join(columns));
                foreach (var row in rows) writer.WriteLine(Join(row));
            }
        }

        static string Join(IEnumerable<string> values)
        {
            var parts = new List<string>();
            foreach (var value in values)
            {
                var v = value ?? "";
                parts.Add(v.IndexOfAny(new[] { ',', '"', '\n', '\r' }) >= 0 ? "\"" + v.Replace("\"", "\"\"") + "\"" : v);
            }
            return string.Join(",", parts);
        }

        public static string Get(this Dictionary<string, string> row, string key)
        {
            string value;
            return row.TryGetValue(key, out value) ? value : "";
        }

        public static long Hex(string value)
        {
            if (string.IsNullOrEmpty(value)) return -1;
            value = value.Trim();
            if (value.StartsWith("0x", StringComparison.OrdinalIgnoreCase)) value = value.Substring(2);
            long result;
            return long.TryParse(value, System.Globalization.NumberStyles.HexNumber, null, out result) ? result : -1;
        }
    }
}
