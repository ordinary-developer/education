using System;
using System.Threading;

namespace Project
{
    public delegate int BinaryOperation(int x, int y);

    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Synch Delegate Review");
	    
            Console.WriteLine("Main() invoked on thread {0}",
                              Thread.CurrentThread.ManagedThreadId);    
            BinaryOperation binaryOperation = new BinaryOperation(Add);
            IAsyncResult asyncResult = binaryOperation.BeginInvoke(10, 10, null, null);
            while (!asyncResult.AsyncWaitHandle.WaitOne(1000, true))
            {
                Console.WriteLine("Doing more work in Main()!");
                Thread.Sleep(1000);
            }
            int answer = binaryOperation.EndInvoke(asyncResult);
            Console.WriteLine("10 + 10 is {0}.", answer);
            
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }

        static int Add(int x, int y) 
        {
            Console.WriteLine("Add() invoked on thread {0}.",
                              Thread.CurrentThread.ManagedThreadId);
            Thread.Sleep(5000);
            return x + y;
        }
    }
}
