using System;

namespace Project
{
    class DatabaseReader
    {
        public int? numericValue = null;
        public bool? boolValue = true;
        
        public int? GetIntFromDatabase() { return numericValue; }
        public bool? GetBoolFromDatabase() { return boolValue; }
    }
        
    class Program
    {
        public static void Main(string[] args)
        {
            LocalNullableVariablesExample();
            LocalNullableVariablesExampleUsingNullable();
            MoreRealNulltypeTypeExample();
            UsingNullCoalescingOperatorNull();
            UsingTheNullConditionalOperatorExample();
            
            Console.ReadLine();
        }
        
        private static void LocalNullableVariablesExample()
        {
            Console.WriteLine("=>LocalNullableVariablesExample");
            
            int? nullableInt = 10;
            double? nullableDouble = 3.14;
            bool? nullableBool = null;
            char? nullableChar = 'a';
            int?[] arrayOfNullableInts = new int?[10];
            
            Console.WriteLine();
        }
        
        private static void LocalNullableVariablesExampleUsingNullable()
        {
            Console.WriteLine("=>LocalNullableVariablesExampleUsingNullable");
            
            Nullable<int> nullableInt = 10;
            Nullable<double> nullableDouble = 3.14;
            Nullable<bool> nullableBool = null;
            Nullable<char> nullableChar = 'a';
            Nullable<int>[] arrayOfNullableInts = new Nullable<int>[10];
            
            Console.WriteLine();
        }
        
        private static void MoreRealNulltypeTypeExample()
        {
            Console.WriteLine("=>MoreRealNulltypeTypeExample");
            
            DatabaseReader dr = new DatabaseReader();
            
            int? i = dr.GetIntFromDatabase();
            if (i.HasValue)
                Console.WriteLine("Value of 'i' is: {0}", i.Value);
            else
                Console.WriteLine("Value of 'i' is undefined.");
            
            bool? b = dr.GetBoolFromDatabase();
            if (b != null)
                Console.WriteLine("Value of 'b' is: {0}", b.Value);
            else
                Console.WriteLine("Value of 'b' is underfined.");
            
            Console.WriteLine();
        }
        
        private static void UsingNullCoalescingOperatorNull()
        {
            Console.WriteLine("=>UsingNullCoalescingOperatorNull");
            
            DatabaseReader dr = new DatabaseReader();
            int myData = dr.GetIntFromDatabase() ?? 100;
            Console.WriteLine("Value of myData: {0}", myData);
            
            Console.WriteLine();
        }
        
        private static void UsingTheNullConditionalOperatorExample()
        {
            Console.WriteLine("=>UsingTheNullConditionalOperatorExample");
            
            TesterMethod(null);
            
            Console.WriteLine();
        }
        private static void TesterMethod(string[] args)
        {
            if (null != args)
                Console.WriteLine("You sent me {0} arguments", args.Length);
        }
    }
}