using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            IfElseExample();
            SwitchExample();
            SwitchOnStringExample();
            SwitchOnEnumExample();

            Console.ReadLine();
        }
        
        private static void IfElseExample()
        {
            Console.WriteLine("=> IfElseExample():");
            
            string stringData = "My textual data";
            if (stringData.Length > 0)
                Console.WriteLine("string is greater than 0 characters");
            
            Console.WriteLine();
        }
        
        private static void SwitchExample()
        {
            Console.WriteLine("=> SwitchExample():");
            
            Console.WriteLine("1 [C#], 2 [VB]");
            Console.Write("Please pick your language preference: ");
            string langChoice = Console.ReadLine();
            int n = int.Parse(langChoice);
            switch (n)
            {
                case 1:
                    Console.WriteLine("Good choice, C# is a fine language");
                    break;
                case 2:
                    Console.WriteLine("VB: OOP, multithreading, and more");
                    break;
                default:
                    Console.WriteLine("Well... good luck with that");
                    break;
            }
            
            Console.WriteLine();
        }
        
        private static void SwitchOnStringExample()
        {
            Console.WriteLine("=> SwitchOnStringExample():");
            
            Console.WriteLine("C# or VB");
            Console.WriteLine("Please pick your language preference: ");
            string langChoice = Console.ReadLine();
            switch (langChoice)
            {
                case "C#":
                    Console.WriteLine("Good choice, C# is fine language.");
                    break;
                case "VB":
                    Console.WriteLine("VB: OOP, multithreading and more!");
                    break;
                default:
                    Console.WriteLine("Well... good luck with that!");
                    break;
            }
            
            Console.WriteLine();
        }
        
        private static void SwitchOnEnumExample()
        {
            Console.WriteLine("=> SwtichOnEnumExampel():");
            
            Console.WriteLine("Enter your favorite day of the week: ");
            DayOfWeek favoriteDay;
            
            try
            {
                favoriteDay = (DayOfWeek)Enum.Parse(typeof(DayOfWeek), Console.ReadLine());
            }
            catch (Exception)
            {
                Console.WriteLine("Bad input!");
                return;
            }
            
            switch (favoriteDay)
            {
                case DayOfWeek.Friday:
                    Console.WriteLine("Yes, Friday rules!");
                    break;
                case DayOfWeek.Monday:
                    Console.WriteLine("Another day, another dollar");
                    break;
                case DayOfWeek.Saturday:
                    Console.WriteLine("Great day indeed.");
                    break;
                case DayOfWeek.Sunday:
                    Console.WriteLine("Football!!!");
                    break;
                case DayOfWeek.Thursday:
                    Console.WriteLine("Almost Friday...");
                    break;
                case DayOfWeek.Tuesday:
                    Console.WriteLine("At least it is not Monday");
                    break;
                case DayOfWeek.Wednesday:
                    Console.WriteLine("A fine day.");
                    break;                    
            }
            
            Console.WriteLine();
        }
    }
}