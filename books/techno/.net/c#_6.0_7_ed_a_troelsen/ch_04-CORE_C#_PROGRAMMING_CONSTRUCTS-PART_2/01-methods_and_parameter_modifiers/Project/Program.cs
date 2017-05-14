using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            CopyByValueExample();
            OutModifierExample();
            OutModifierAuxExample();
            RefModifierExample();
            ParamModifierExample();
            OptionalParameterExample();
            NamedParameterExample();
            NamedParameterAuxExample();
            MethodOverloadingExample();
            
            Console.ReadLine();
        }
        
        private static void CopyByValueExample()
        {
            Console.WriteLine("=> CopyByValue():");
            
            int x = 9, y = 10;
            Console.WriteLine("Before call: X: {0}, Y: {1}", x, y);
            Console.WriteLine("Answer is: {0}", Add(x, y));
            Console.WriteLine("After call: X: {0}, Y: {1}", x, y);
            
            Console.WriteLine();
        }        
        private static int Add(int x, int y)
        {
            int ans = x + y;
            x = 10000;
            y = 88888;
            return ans;
        }
        
        private static void OutModifierExample()
        {
            Console.WriteLine("=> OutModifierExample():");
            
            int answer;
            Add(90, 90, out answer);
            Console.WriteLine("90 + 90 = {0}", answer);
            
            Console.WriteLine();
        }        
        private static void Add(int x, int y, out int answer) { answer = x + y; }
        
        private static void OutModifierAuxExample()
        {
            Console.WriteLine("=> OutModifierAuxExample():");
            
            int i; string str; bool b;
            FillAllValues(out i, out str, out b);            
            
            Console.WriteLine("Int is: {0}", i);
            Console.WriteLine("String is: {0}", str);
            Console.WriteLine("Boolean is: {0}", b);
            
            Console.WriteLine();
        }
        private static void FillAllValues(out int a, out string b, out bool c)
        {
            a = 9;
            b = "Enjoy your string";
            c = true;
        }
        
        private static void RefModifierExample()
        {
            Console.WriteLine("=> RefModifierExample():");
            
            string str1 = "Flip";
            string str2 = "Flop";
            Console.WriteLine("Before: {0}, {1}", str1, str2);
            SwapStrings(ref str1, ref str2);
            Console.WriteLine("After: {0}, {1}", str1, str2);
            
            Console.WriteLine();
                              
        }        
        private static void SwapStrings(ref string s1, ref string s2)
        {
            string tempStr = s1;
            s1 = s2;
            s2 = tempStr;
        }
        
        private static void ParamModifierExample()
        {
            Console.WriteLine("=> ParamModifierExample():");
            
            double average;
            average = CalculateAverage(4.0, 3.2, 5.7, 64.22, 87.2);
            Console.WriteLine("Average of data is: {0}", average);
            
            double[] data = { 4.0, 3.2, 5.7 };
            average = CalculateAverage(data);
            Console.WriteLine("Average of data is: {0}", average);
            
            Console.WriteLine("Average of data is: {0}", CalculateAverage());
            
            Console.WriteLine();
        }
        private static double CalculateAverage(params double[] values)
        {
            Console.WriteLine("You sent me {0} doubles.", values.Length);
            
            double sum = 0;
            if (values.Length == 0)
                return sum;
            for (int i = 0; i < values.Length; i++)
                sum += values[i];
            return (sum / values.Length);
        }
        
        private static void OptionalParameterExample()
        {
            Console.WriteLine("=> OptionalParameterExample():");
            
            EnterLogData("Oh no! Grid can't find data");
            EnterLogData("Oh no! I can't find the payroll data", "CFO");
            
            Console.WriteLine();
        }
        private static void EnterLogData(string message, string owner = "Programmer")
        {
            Console.Beep();
            Console.WriteLine("Error: {0}", message);
            Console.WriteLine("Owner of Error: {0}", owner);
        }
        
        private static void NamedParameterExample()
        {
            Console.WriteLine("=> NamedParameterExample():");
            
            DisplayFancyMessage(message: "Wow! Very Fancy indeed!",
                                textColor: ConsoleColor.DarkRed,
                                backgroundColor: ConsoleColor.White);
            
            DisplayFancyMessage(backgroundColor: ConsoleColor.Green,
                                message: "Testing...",
                                textColor: ConsoleColor.DarkBlue);
            
            DisplayFancyMessage(ConsoleColor.Blue,
                                message: "Testing...",
                                backgroundColor: ConsoleColor.White);
            
            Console.WriteLine();
        }
        private static void DisplayFancyMessage(ConsoleColor textColor,
                                                ConsoleColor backgroundColor,
                                                string message)
        {
            ConsoleColor oldTextColor = Console.ForegroundColor;
            ConsoleColor oldBackgroundColor = Console.BackgroundColor;
            
            Console.ForegroundColor = textColor;
            Console.BackgroundColor = backgroundColor;
            Console.WriteLine(message);
            
            Console.ForegroundColor = oldTextColor;
            Console.BackgroundColor = oldBackgroundColor;
        }
        
        private static void NamedParameterAuxExample()
        {
            Console.WriteLine("=> NamedParameterAuxExample():");
            
            AuxDisplayFancyMessage(message: "Hello!");
            AuxDisplayFancyMessage(backgroundColor: ConsoleColor.Green);
            
            Console.WriteLine();
        }
        private static void AuxDisplayFancyMessage(ConsoleColor textColor = ConsoleColor.Blue,
                                                   ConsoleColor backgroundColor = ConsoleColor.White,
                                                   string message = "Test Message")
        {
            ConsoleColor oldTextColor = Console.ForegroundColor;
            ConsoleColor oldBackgroundColor = Console.BackgroundColor;
            
            Console.ForegroundColor = textColor;
            Console.BackgroundColor = backgroundColor;
            Console.WriteLine(message);
            
            Console.ForegroundColor = oldTextColor;
            Console.BackgroundColor = oldBackgroundColor;
        }
        
        private static void MethodOverloadingExample()
        {
            Console.WriteLine("=> MethodOverloadingExample():");
            
            Console.WriteLine(OverloadedAdd(10, 10));
            Console.WriteLine(OverloadedAdd(90000000000000, 90000000000000));
            Console.WriteLine(OverloadedAdd(4.3, 4.4));
            
            Console.WriteLine();
        }
        private static int OverloadedAdd(int x, int y) 
        {
            Console.WriteLine("int OverloadedAdd(int, int)");
            return x + y; 
        }
        private static double OverloadedAdd(double x, double y) 
        {
            Console.WriteLine("double OverloadedAdd(double, double)");
            return x + y; 
        }
        private static long OverloadedAdd(long x, long y) 
        {
            Console.WriteLine("long OverloadedAdd(long, long)");
            return x + y; 
        }
    }
}