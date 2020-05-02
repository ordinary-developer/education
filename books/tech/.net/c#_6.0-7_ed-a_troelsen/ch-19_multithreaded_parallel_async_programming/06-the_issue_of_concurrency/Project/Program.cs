using System;
using System.Threading;

namespace Project
{
    class Program
    {
        delegate void WorkingMethod();
        public static void Main(string[] args)
        {
            var methodsToRun = new WorkingMethod[] { LockUsingExample };
            foreach (var methodToRun in methodsToRun) 
            {
                var threadToRun = new Thread(new ThreadStart(methodToRun));
                threadToRun.Start();
                threadToRun.Join();
            }

            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }

        #region example 1
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
        private static void LockUsingExample()
        {
            Console.WriteLine("*** LockUsingExample ***");

            Printer printer = new Printer();
            var threads = new Thread[10];
            for (int i = 0; i < 10; i++)
            {
                threads[i] = 
                    new Thread(new ThreadStart(printer.PrintNumbers));
                threads[i].Name = string.Format("Worker thread #{0}", i);
            }
            foreach (Thread thread in threads)
                thread.Start();

            foreach (Thread thread in threads)
                thread.Join();

            Console.WriteLine();
        }
        #endregion example 1
    }
}
