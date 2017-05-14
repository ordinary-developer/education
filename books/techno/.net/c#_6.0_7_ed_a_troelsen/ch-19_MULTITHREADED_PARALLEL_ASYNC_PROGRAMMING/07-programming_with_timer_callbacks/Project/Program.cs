using System;
using System.Threading;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("*** Working with Timer type ***\n");

            TimerCallback timerCallback = new TimerCallback(PrintTime);
            Timer timer = new Timer(timerCallback,
                                    null,
                                    0,
                                    1000);
            
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }

        private static void PrintTime(object state)
        {
            Console.WriteLine("Time is: {0}",
                              DateTime.Now.ToLongTimeString());
        }
    }
}
