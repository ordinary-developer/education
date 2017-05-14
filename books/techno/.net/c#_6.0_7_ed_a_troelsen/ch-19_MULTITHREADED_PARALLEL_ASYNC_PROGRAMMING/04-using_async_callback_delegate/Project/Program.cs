using System;
using System.Threading;
using System.Runtime.Remoting.Messaging;

namespace Project
{
    public delegate int BinaryOperation(int x, int y);

    class Program
    {
        private static bool isDone = false;

        public static void Main(string[] args)
        {
            Console.WriteLine("Synch Delegate Review");
	    
            Console.WriteLine("Main() invoked on thread {0}",
                              Thread.CurrentThread.ManagedThreadId);    
            BinaryOperation binaryOperation = new BinaryOperation(Add);
            IAsyncResult asyncResult = 
                binaryOperation.BeginInvoke(10, 
                                            10,
                                            new AsyncCallback(AddComplete), 
                                            "Main() thanks you for adding numbers.");
            while (!isDone) 
            {
                Thread.Sleep(1000);
                Console.WriteLine("Working...");
            }
            
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

        static void AddComplete(IAsyncResult asyncResult)
        {
            Console.WriteLine("AddComplete() invoked on thread {0}.",
                              Thread.CurrentThread.ManagedThreadId);
            Console.WriteLine("Your addition is complete");
            AsyncResult concreteAsyncResult = (AsyncResult)asyncResult;
            BinaryOperation operation = 
               (BinaryOperation)concreteAsyncResult.AsyncDelegate;
            Console.WriteLine("10 + 10 is {0}.", operation.EndInvoke(asyncResult));
            string msg = (string)asyncResult.AsyncState;
            Console.WriteLine(msg);
            isDone = true;
        }
    }
}
