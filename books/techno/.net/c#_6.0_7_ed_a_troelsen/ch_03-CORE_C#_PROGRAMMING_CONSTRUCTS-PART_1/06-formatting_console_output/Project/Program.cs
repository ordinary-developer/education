using System;
using System.Windows;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            // Formatting console output
            Console.WriteLine("{0}, Number {0}, Number {0}", 9);
            Console.WriteLine("{1}, {0}, {2}", 10, 20, 30);
            
            // Formatting numeric data 
            Console.WriteLine("The value 99999 in various formats: ");
            Console.WriteLine("c format: {0:c}", 9999);
            Console.WriteLine("d9 format: {0:d9}", 9999);
            Console.WriteLine("f3 format: {0:f3}", 9999);
            Console.WriteLine("n format: {0:n}", 9999);
            Console.WriteLine("E format: {0:E}", 9999);
            Console.WriteLine("e format: {0:e}", 9999);
            Console.WriteLine("X format: {0:X}", 9999);
            Console.WriteLine("x format: {0:x}", 9999);            
            
            // Displaying messages via a message box
            System.Windows.MessageBox.Show(String.Format("10000 in hex is {0:x}", 100000));
            
            Console.ReadLine();            
        }
    }
}