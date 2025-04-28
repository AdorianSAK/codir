using System;
using System.IO;

class codir
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        // Creates Random Function and related needed variable 'int' and "splash" message 'string'.
        Random dice = new Random();
        int roll;
        string message = null;

        // Repeats "roll" until a valid random message is selected.
        do
        {
            roll = dice.Next(1, 101);

            using (StreamReader reader = new StreamReader(@"/home/hunish/Desktop/coding/CustomCommands/SysDepen/codir_splash_phrase.txt"))
            {
                int lineNumber = 1;
                while (!reader.EndOfStream)
                {
                    string line = reader.ReadLine();
                    if (lineNumber == roll)
                    {
                        message = line;
                        break; // Found the desired line, exit the loop.
                    }
                    lineNumber++;
                }
            }
        } while (message == null);

        Console.ForegroundColor = ConsoleColor.DarkGreen;
        Console.WriteLine(File.ReadAllText(@"/home/hunish/Desktop/coding/CustomCommands/SysDepen/codir_splash_5.txt"));

        Console.WriteLine("");
        Console.ForegroundColor = ConsoleColor.Blue;
        Console.Write(string.Format("{0, 70}", "Welcome to your coding directory Hunish! n.n"));
        Console.ForegroundColor = ConsoleColor.Red;
        Console.Write(" ~ ♥\n\n");
        Console.ForegroundColor = ConsoleColor.Magenta;
        Console.Write(string.Format("{0, 60}", $"{message}\n\n"));

        Console.ResetColor();
    }
}
