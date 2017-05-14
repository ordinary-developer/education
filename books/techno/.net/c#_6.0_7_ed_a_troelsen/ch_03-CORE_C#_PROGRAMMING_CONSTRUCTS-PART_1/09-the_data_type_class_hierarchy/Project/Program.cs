using System;
using System.Numerics;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            ObjectFunctionality();   
            DataTypeFunctionality();
            BooleanTypeFunctionality();
            CharFunctionality();
            ParseFromStrings();        
            UseDatesAndTimes();
            UseBigInteger();
            
            Console.ReadLine();
        }
        
        private static void ObjectFunctionality()
        {
            Console.WriteLine("=> System.Object Functionality");
            
            Console.WriteLine("12.GetHashCode() = {0}", 12.GetHashCode());
            Console.WriteLine("12.Equals(23) = {0}", 12.Equals(23));
            Console.WriteLine("12.ToString() = {0}", 12.ToString());
            Console.WriteLine("12.GetType() = {0}", 12.GetType());
            
            Console.WriteLine();
        }
        
        private static void DataTypeFunctionality()
        {
            Console.WriteLine("=> Data type Functionality:");
            
            Console.WriteLine("Max of int: {0}", int.MaxValue);
            Console.WriteLine("Min of int: {0}", int.MinValue);
            Console.WriteLine("Max of double: {0}", double.MaxValue);
            Console.WriteLine("Min of double: {0}", double.MinValue);
            Console.WriteLine("double.Epsilon: {0}", double.Epsilon);
            Console.WriteLine("double.PositiveInfinity: {0}",
                              double.PositiveInfinity);
            Console.WriteLine("double.NegativeInfinity: {0}",
                              double.NegativeInfinity);
            
            Console.WriteLine();
        }
        
        private static void BooleanTypeFunctionality()
        {
            Console.WriteLine("=> Boolean type functionality:");
            
            Console.WriteLine("bool.FalseString: {0}", bool.FalseString);
            Console.WriteLine("bool.TrueString: {0}", bool.TrueString);
            
            Console.WriteLine();
        }
        
        private static void CharFunctionality()
        {
            Console.WriteLine("=> Char type functionality:");
            
            char myChar = 'a';
            Console.WriteLine("char.IsDigit('a'): {0}", char.IsDigit(myChar));
            Console.WriteLine("char.IsLetter('a'): {0}", char.IsLetter(myChar));
            Console.WriteLine("char.IsWhiteSpace('Hello There', 5): {0}",
                              char.IsWhiteSpace("Hello There", 5));
            Console.WriteLine("char.IsWhiteSpace('Hello There', 6): {0}",
                              char.IsWhiteSpace("Hello There", 6));
            Console.WriteLine("char.IsPunctuation('?'): {0}",
                              char.IsPunctuation('?'));
            
            Console.WriteLine();
        }
        
        private static void ParseFromStrings()
        {
            Console.WriteLine("=> Data type parsing: ");
            
            bool b = bool.Parse("True");
            Console.WriteLine("Value of b: {0}", b);
            double d = double.Parse("99,84");
            Console.WriteLine("Value of d: {0}", d);            
            int i = int.Parse("8");
            Console.WriteLine("Value of i: {0}", i);
            char c= Char.Parse("w");
            Console.WriteLine("Value of c: {0}", c);
            
            Console.WriteLine();
        }
        
        private static void UseDatesAndTimes()
        {
            Console.WriteLine("=> Dates and Times:");
            
            DateTime dt = new DateTime(2015, 10, 17);
            Console.WriteLine("The day of {0} is {1}", dt.Date, dt.DayOfWeek);
            
            dt = dt.AddMonths(2);
            Console.WriteLine("Daylight savings: {0}", dt.IsDaylightSavingTime());
            
            TimeSpan ts = new TimeSpan(4, 30, 0);
            Console.WriteLine(ts);            
            Console.WriteLine(ts.Subtract(new TimeSpan(0, 15, 0)));
                              
            Console.WriteLine();
        }
        
        private static void UseBigInteger()
        {
            Console.WriteLine("=> Use BigInteger:");
            
            BigInteger biggy = 
                BigInteger.Parse("9999999999999999999999999999999999999999999999999999999");
            Console.WriteLine("Value of biggy is {0}", biggy);
            Console.WriteLine("Is biggy an even value?: {0}", biggy.IsEven);
            Console.WriteLine("Is biggy a power of two?: {0}", biggy.IsPowerOfTwo);
            BigInteger reallyBig = BigInteger.Multiply(biggy,
                BigInteger.Parse("88888888888888888888888888888888888888888888888888888888"));
            Console.WriteLine("Value of reallyBig is {0}" , reallyBig);
            BigInteger reallyBig2 = biggy * reallyBig;
            Console.WriteLine("Value of reallyBig2 is {0}", reallyBig2);
                                    
            Console.WriteLine();
        }
    }
}