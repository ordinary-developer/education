using System;

namespace Project
{
    class SavingsAccount
    {
        public double currBalance;
        
        public static double currInterestRate;
        
        public SavingsAccount(double balance)
        {
            currBalance = balance;
        }
        
        static SavingsAccount()
        {
            Console.WriteLine("In static ctor!");
            currInterestRate = 0.04;
        }
        
        public static void SetInterestRate(double newRate)
        {
            currInterestRate = newRate;
        }
        
        public static double GetInterestRate()
        {
            return currInterestRate;
        }
    }
    
    static class TimeUtilClass
    {
        public static void PrintTime()
        {
            Console.WriteLine(DateTime.Now.ToShortTimeString());
        }
        
        public static void PrintDate()
        {
            Console.WriteLine(DateTime.Today.ToShortDateString());
        }
    }
    
    class Program
    {
        public static void Main(string[] args)
        {
            SimpleUsingOfSavingsAccount();
            SimpleUseOfStaticMethods();
            
            Console.ReadLine();
        }
        
        private static void SimpleUsingOfSavingsAccount()
        {
            Console.WriteLine("=> SimpleUsingOfSavingsAccount");
            
            SavingsAccount s1 = new SavingsAccount(50);
            SavingsAccount s2 = new SavingsAccount(100);
            SavingsAccount s3 = new SavingsAccount(10000.75);
            
            Console.WriteLine();
        }
        
        private static void SimpleUseOfStaticMethods()
        {
            Console.WriteLine("=> SimpleUseOfStaticMethods");
            
            SavingsAccount s1 = new SavingsAccount(50);
            SavingsAccount s2 = new SavingsAccount(100);
            
            Console.WriteLine("Interest Rate is: {0}", SavingsAccount.GetInterestRate());
            
            SavingsAccount s3 = new SavingsAccount(10000.75);
            Console.WriteLine("Interest Rate is: {0}", SavingsAccount.GetInterestRate());
            
            Console.WriteLine();
        }
        
        private static void UsingStaticClass()
        {
            Console.WriteLine("=> UsingStaticClass");
            
            TimeUtilClass.PrintDate();
            TimeUtilClass.PrintTime();
            
            
            
            Console.WriteLine();
        }
    }
}