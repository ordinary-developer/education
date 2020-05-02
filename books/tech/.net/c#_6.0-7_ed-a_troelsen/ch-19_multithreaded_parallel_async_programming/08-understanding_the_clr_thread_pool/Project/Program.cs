using System;
using System.Threading;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            
            Example1_ThreadPoolUsing();
            
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }

        #region example 1
        private static void Example1_ThreadPoolUsing()
        {
            Console.WriteLine("*** Using the CLR Thread Pool ***\n");

            Console.WriteLine("Main thread started. ThreadID = {0}",
                              Thread.CurrentThread.ManagedThreadId);

            Printer printer = new Printer();
            WaitCallback workItem = new WaitCallback(PrintTheNumbers);
            for (int i = 0; i < 10; i++)
                ThreadPool.QueueUserWorkItem(workItem, printer);
            Console.WriteLine("All tasks queued");
        }

        private static void PrintTheNumbers(object state)
        {
            ((Printer)state).PrintNumbers();
        }

        private class Printer
        {
            private object threadLock = new object();
            public void PrintNumbers()
            {
                lock (threadLock)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        Thread.Sleep(1000 * new Random().Next(5));
                        Console.Write("{0}, ", i);
                    }
                    Console.WriteLine();
                }
            }
        }

        #endregion example 2

    }
}
