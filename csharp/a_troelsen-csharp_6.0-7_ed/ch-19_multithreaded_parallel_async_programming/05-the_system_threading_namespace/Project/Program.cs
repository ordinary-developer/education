using System;
using System.Threading;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            Thread primaryThread = Thread.CurrentThread;
            primaryThread.Name = "The Primary Thread";

            ObtainThreadStats(); 
            UseThreadStartDelegate();
            UseParameterizedThreadStartDelegate();
            
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }

        #region	Example 1
        private static void ObtainThreadStats()
        {
            Console.WriteLine("*** Obtaining thread stats ***\n");

            Thread primaryThread = Thread.CurrentThread;
            Console.WriteLine("Name of current AppDomain: {0}",
                              Thread.GetDomain().FriendlyName);
            Console.WriteLine("ID of current Context: {0}",
                              Thread.CurrentContext.ContextID);
            Console.WriteLine("Thread Name: {0}", primaryThread.Name);
            Console.WriteLine("Has thread started?: {0}", primaryThread.IsAlive);
            Console.WriteLine("Priority level: {0}", primaryThread.Priority);
            Console.WriteLine("Thread State: {0}", primaryThread.ThreadState);
        }
        #endregion

        #region Example 2
        private class Printer 
        {
            public void PrintNumbers()
            {
                Console.WriteLine("-> {0} is executing PrintNumbers()",
                                  Thread.CurrentThread.Name);

                Console.Write("Your numbers: ");
                for (int i = 0; i < 10; i++)
                {
                    Console.WriteLine("{0}, ", i);
                    Thread.Sleep(2000);
                }
                Console.WriteLine();
            }
        }
        private static void UseThreadStartDelegate()
        {
            Console.WriteLine("*** UseThreadStartDelegate ***");

            Thread primaryThread = Thread.CurrentThread;
            Console.WriteLine("-> {0} is executing Main()",
                              primaryThread.Name);

            Printer printer = new Printer();
            int threadCount = new Random().Next(1, 3);
            if (2 == threadCount) 
            {
                Thread backgroundThread = 
                    new Thread(new ThreadStart(printer.PrintNumbers));
                backgroundThread.Name = "Secondary";
                backgroundThread.Start();
            }
            else // threadCount is 1
                printer.PrintNumbers();
        }
        #endregion Example 2

        #region Example 3
        private static AutoResetEvent waitHandle = new AutoResetEvent(false);
        private class AddParams 
        {
            public int a, b;

            public AddParams(int number1, int number2)
            {
                a = number1;
                b = number2;
            }
        }
        private static void Add(object data)
        {
            if (data is AddParams)
            {
                Console.WriteLine("ID of thread in Add(): {0}",
                                  Thread.CurrentThread.ManagedThreadId);
                AddParams parameters = (AddParams)data;
                Console.WriteLine("{0} + {1} is {2}",
                                  parameters.a,
                                  parameters.b,
                                  parameters.a + parameters.b);

                waitHandle.Set();
            }
        }
        private static void UseParameterizedThreadStartDelegate()
        {
            Console.WriteLine("*** UseParameterizedThreadStartDelegate ***");

            Console.WriteLine("ID of thread in Main(): {0}",
                              Thread.CurrentThread.ManagedThreadId);
            AddParams parameters = new AddParams(10, 10);
            Thread thread = new Thread(new ParameterizedThreadStart(Add));
            thread.Start(parameters);
            waitHandle.WaitOne();
            Console.WriteLine("Other thread is done!");
        }
        #endregion Example 3

    }
}
