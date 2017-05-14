using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("***** Fun with type conversions *****");
            UseTypeConversions();
            NarrowingAttempt();
            ProcessBytes();
            CheckedProcessBytes();
            UncheckedProcessBytes();
            
            Console.ReadLine();
        }
        
        private static int Add(int x, int y) { return x + y; }
        
        private static void UseTypeConversions()
        {
            Console.WriteLine("=> Using type convertions:");
            
            short number1 = 30000, number2 = 30000;
            try
            {
                short answer = (short)Add(number1, number2);
                Console.WriteLine("{0} + {1} = {2}",
                                  number1, number2, answer);
            } catch (Exception) { }
            
            NarrowingAttempt();
            
            Console.WriteLine();
        }
        
        private static void NarrowingAttempt()
        {
            Console.WriteLine("=> NarrowingAttemp: ");
            
            byte myByte = 0;
            int myInt = 200;
            myByte = (byte)myInt;
            Console.WriteLine("Value of myByte: {0}", myByte);
        }
        
        private static void ProcessBytes()
        {
            Console.WriteLine("=> ProcessBytes:");
            
            byte b1 = 100;
            byte b2 = 250;
            try
            {
                byte sum = (byte)Add(b1, b2);
                Console.WriteLine("sum = {0}", sum);
            }
            catch (OverflowException ex)
            {
                Console.WriteLine(ex.Message);
            }
            
            Console.WriteLine();
        }
        
        private static void CheckedProcessBytes()
        {
            Console.WriteLine("=> CheckedProcessBytes:");
            
            byte b1 = 100;
            byte b2 = 250;
            try
            {
                checked
                {
                    byte sum = (byte)Add(b1, b2);
                    Console.WriteLine("sum = {0}", sum);
                }
            }
            catch (OverflowException ex)
            {
                Console.WriteLine(ex.Message);
            }
            
            Console.WriteLine();
        }
        
        private static void UncheckedProcessBytes()
        {
            Console.WriteLine("=> UncheckedProcessBytes:");
            
            byte b1 = 100;
            byte b2 = 250;
            
            unchecked
            {
                byte sum = (byte)(b1 + b2);
                Console.WriteLine("sum = {0} ", sum);
            }
        }
    }
}