
using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            NewingDataTypes();
            
            Console.ReadLine();
        }
        
        private static void NewingDataTypes()
        {
            Console.WriteLine("=> Using new to create variables:");
            
            bool b = new bool();
            int i = new int();
            double d = new double();
            DateTime dt = new DateTime();
            Console.WriteLine("{0}, {1}, {2}, {3}", b, i, d, dt);
            
            Console.WriteLine();
        }
    }
}