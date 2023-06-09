using System;
using System.Linq;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            DeclareExplicitVars();
            DeclareImplicitVars();
            DeclareImplicitVarsAux();
            LinqQueryOverInts();
            
            Console.ReadLine();
        }
        
        private static void DeclareExplicitVars()
        {
            Console.WriteLine("=> DeclareExplicitVars():");
            
            int myInt = 0;
            bool myBool = true;
            string myString = "Time, marches on...";
            
            Console.WriteLine();
        }
        
        private static void DeclareImplicitVars()
        {
            Console.WriteLine("=> DeclareImplicitVars():");
                
            var myInt = 0;
            var myBool = true;
            var myString = "Time, marches on ...";
            
            Console.WriteLine("myInt is a: {0}", myInt.GetType().Name);
            Console.WriteLine("myBool is a: {0}", myBool.GetType().Name);
            Console.WriteLine("myString is a: {0}", myString.GetType().Name);
            
            Console.WriteLine();
        }
        
        private static void DeclareImplicitVarsAux()
        {
            Console.WriteLine("=> DeclareImplicitVarsAux():");
            
            var myInt = 0;
            var anotherInt = myInt;
            
            string myString = "Wake up!";
            var myData = myString;
            
            var aValue = GetAnInt();
            
            Console.WriteLine();
        }
        
        static int GetAnInt() 
        {
            var retVal = 9;
            return retVal;
        }
        
        static void LinqQueryOverInts()
        {
            Console.WriteLine("=> LinqQueryOverInts()");
            
            int[] numbers = { 10, 20, 30, 40, 1, 2, 3, 8 };
            
            var subset = from i in numbers where i < 10 select i;
            Console.WriteLine("Values in subset: ");
            foreach (var i in subset)
                Console.WriteLine("{0} ", i);
            
            Console.WriteLine();
            Console.WriteLine("subset is a: {0}", subset.GetType().Name);
            Console.WriteLine("subset is defined in: {0}", subset.GetType().Namespace);
            
            Console.WriteLine();
        }   
    }
}