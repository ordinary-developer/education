using System;
using System.Linq;


namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            ForLoopExample();
            ForEachLoopExample();
            LinqQueryOverInts();
            WhileLoopExample();
            DoWhileLoopExample();
            
            Console.ReadLine();            
        }
        
        private static void ForLoopExample()
        {
            Console.WriteLine("=> ForLoopExample():");
            
            for (int i = 0; i < 4; i++)
                Console.WriteLine("Number is: {0} ", i);
            
            Console.WriteLine();
        }
        
        private static void ForEachLoopExample()
        {
            Console.WriteLine("=> ForEachLoopExample():");
            
            string[] carTypes = { "Ford", "BMW", "Yugo", "Honda" };
            foreach (string c in carTypes)
                Console.WriteLine(c);
            
            int[] myInts = { 10, 20, 30, 40 };
            foreach (int i in myInts)
                Console.WriteLine(i);

            Console.WriteLine();
        }
        
        private static void LinqQueryOverInts()
        {
            Console.WriteLine("=> LinqQueryOverInts():");
            
            int[] numbers = { 10, 20, 30, 40, 1, 2, 3, 8 };
            var subset = from i in numbers where i < 10 select i;            
            Console.WriteLine("Values in subset: ");
            foreach (var i in subset)
                Console.WriteLine("{0} ", i);
            
            Console.WriteLine();
        }
        
        private static void WhileLoopExample()
        {
            Console.WriteLine("=> WhileLoopExample():");
                
            string userIsDone = "";
            while (userIsDone.ToLower() != "yes")
            {
                Console.WriteLine("In while loop");
                Console.WriteLine("Are you done? [yes][no]: ");
                userIsDone = Console.ReadLine();
            }
            
            Console.WriteLine();
        }
        
        private static void DoWhileLoopExample()
        {
            Console.WriteLine("=> DoWhileLoopExample():");
            
            string userIsDone = "";
            do
            {
                Console.WriteLine("In do/while loop");
                Console.WriteLine("Are you done? [yes][no]: ");
                userIsDone = Console.ReadLine();
            } while (userIsDone.ToLower() != "yes");
            
            Console.WriteLine();
        }
    }
}