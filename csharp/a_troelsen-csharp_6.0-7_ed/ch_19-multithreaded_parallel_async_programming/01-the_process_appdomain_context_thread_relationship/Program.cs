using System;
using System.Threading;
using System.Runtime.Remoting.Contexts;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("=> Main()");
			
			Thread currentThread = Thread.CurrentThread;
			Console.WriteLine(string.Format("Current thread name: [{0}]", currentThread.Name));
			
			AppDomain appDomain = Thread.GetDomain();
			Console.WriteLine(string.Format("Current AppDomain is {0}", appDomain.ToString()));
			
			Context context = Thread.CurrentContext;
			Console.WriteLine(string.Format("Current Thread context is {0}", context.ToString()));
			
			Console.ReadLine();
        }
    }
}