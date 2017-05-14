using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            ProcessCommandLineArgs1(args);
            ProcessCommandLineArgs2(args);
            ProcessCommandLineArgs3();
            ProcessCommandLineArgs4();
            
            Console.ReadLine();            
        }
        
        private static void ProcessCommandLineArgs1(string[] args)
        {
            for (int i = 0; i < args.Length; i++)
                Console.WriteLine("Arg: {0}", args[i]);
        }
        
        private static void ProcessCommandLineArgs2(string[] args)
        {
            foreach (string arg in args)        
                Console.WriteLine("Arg: {0}", arg);       
        }
        
        private static void ProcessCommandLineArgs3()
        {
            string[] theArgs = Environment.GetCommandLineArgs();
            foreach (string arg in theArgs)
                Console.WriteLine("Arg: {0}", arg);
        }
        
        private static void ProcessCommandLineArgs4()
        {
            foreach (string arg in Environment.GetCommandLineArgs())
                Console.WriteLine("Arg: {0}", arg);
        }
    }
}