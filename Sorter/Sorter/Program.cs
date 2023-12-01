namespace Sorter
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<string> lines = new List<string>();
        newline:
            string input = Console.ReadLine();
            do
            {
                lines.Add(input);
                goto newline;
            } while (!string.IsNullOrEmpty(input));

            lines = lines.Where(x => x.Contains(':')).OrderBy(x => Convert.ToInt32(x.Split(": ")[1].Replace("0x", string.Empty), 16)).ToList();

            Console.WriteLine("gaaaaa");
            foreach (string line in lines)
                Console.WriteLine(line);
        }
    }
}
