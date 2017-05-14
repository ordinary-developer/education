using System;

namespace Project
{
	class MyMathClass
	{
		public const double PI = 3.14;
	}
	
    class Program
    {
        public static void Main(string[] args)
        {
            Example1();
            Example2();
            
            Console.ReadLine();
        }
		
		private static void Example1()
		{
			Console.WriteLine("=> example1");
			
			Console.WriteLine("The value of PI is: {0}", MyMathClass.PI);
			
			Console.WriteLine();
		}
		
		private static void Example2()
		{
		    Console.WriteLine("=> example2");
		    
			const string fixedStr = "Fixed string Data";
			Console.WriteLine(fixedStr);
			
			Console.WriteLine();
		}
    }
}