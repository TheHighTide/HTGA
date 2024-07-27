namespace HTGA.Modules
{
    internal class HTConsoleMenuMan
    {
        public static void PrintMenuHeader(string titleText, int menuWidth, string menuSideCharacter = "|")
        {
            int spaces = (menuWidth - titleText.Length - 2) / 2; // The amount of space to have on the left and right of the text
            string line = menuSideCharacter + new string(' ', spaces) + titleText + new string(' ', spaces) + menuSideCharacter;
            Console.WriteLine("╔" + new string('═', menuWidth - 2) + "╗");
            Console.WriteLine(line);
        }
    }
}
