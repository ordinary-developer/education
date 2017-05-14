using System;

namespace Project
{
	public class MyMathClass
	{
		public readonly double PI;
		public static readonly double PI2;
			
		public MyMathClass() { PI = 3.14; }
		static MyMathClass() { PI2 = 3.1415; }
	}
	
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine(new MyMathClass().PI);
			Console.WriteLine(MyMathClass.PI2);
            Console.ReadLine();
        }
    }
}