using System;

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
            SimpleArrayExample();
            ArrayInitializationExample();
            ImplicitArrayExample();
            ArrayOfObjects();
            RectMultidimensionalArrayExample();
            JaggedMultidimensionalArrayExample();
            PassAndReceiveArrays();
            SystemArrayFunctionalityExample();
            
            Console.ReadLine();
        }
        
        private static void SimpleArrayExample()
        {
            Console.WriteLine("=> SimpleArrayExample()");
            
            int[] myInts = new int[3];
            myInts[0] = 100;
            myInts[1] = 200;
            myInts[2] = 300;
            foreach (int i in myInts)
                Console.WriteLine(i);
            
            string[] booksOnDotNet = new string[100];
            
            Console.WriteLine();
        }
        
        private static void ArrayInitializationExample()
        {
            Console.WriteLine("=> ArrayInitialization()");
            
            string[] stringArray = new string[] { "one", "two", "three" };
            Console.WriteLine("stringArray has {0} elements", stringArray.Length);
            
            bool[] boolArray = { false, false, true };
            Console.WriteLine("boolArray has {0} elements", boolArray.Length);
            
            int[] intArray = new int[4] { 20, 22, 23, 0 };
            Console.WriteLine("intArray has {0} elements", intArray.Length);
            
            Console.WriteLine();
        }
        
        private static void ImplicitArrayExample()
        {
            Console.WriteLine("=> ImplicitArrayExample");
            
            var a = new[] { 1, 10, 100, 1000 };
            Console.WriteLine("a is a: {0}", a.ToString());
            
            var b = new[] { 1, 1.5, 2, 2.5 };
            Console.WriteLine("b is a: {0}", b.ToString());
            
            var c = new[] { "hello", "null", "world" };
            Console.WriteLine("c is a: {0}", c.ToString());
            
            Console.WriteLine();
        }
        
        private static void ArrayOfObjects()
        {
            Console.WriteLine("=> Array of Objects.");
            
            object[] myObjects = new object[4];
            myObjects[0] = 10;
            myObjects[1] = false;
            myObjects[2] = new DateTime(1969, 3, 24);
            myObjects[3] = "Form & Void";
            foreach (object obj in myObjects)
                Console.WriteLine("Type: {0}, Value: {1}", obj.GetType(), obj);
            
            Console.WriteLine();
        }
        
        private static void RectMultidimensionalArrayExample()
        {
            Console.WriteLine("=> Rectangular multidimensional array.");
            
            int[,] myMatrix;
            myMatrix = new int[3, 4];
            
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 4; j++)
                    myMatrix[i, j] = i * j;
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                    Console.Write(myMatrix[i, j] + "\t");
                Console.WriteLine();
            }
            
            Console.WriteLine();
        }
        
        private static void JaggedMultidimensionalArrayExample()
        {
            Console.WriteLine("=> Jagged Multidimensional array");
            
            int[][] myJaggedArray = new int[5][];
            for (int i = 0; i < myJaggedArray.Length; i++)
                myJaggedArray[i] = new int[i + 7];
            
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < myJaggedArray[i].Length; j++)
                    Console.Write(myJaggedArray[i][j] + " ");
                Console.WriteLine();
            }
            
            Console.WriteLine();
        }
        
        private static void PassAndReceiveArrays()
        {
            Console.WriteLine("=> Arrays as params and return values.");
            
            int[] ages = { 20, 22, 23, 0 };
            PrintArray(ages);
            
            string[] strs = GetStringArray();
            foreach (string s in strs)
                Console.WriteLine(s);
            
            Console.WriteLine();
        }
        private static void PrintArray(int[] myInts)
        {
            for (int i = 0; i < myInts.Length; i++)
                Console.WriteLine("Item {0} is {1}", i, myInts[i]);
        }        
        private static string[] GetStringArray()
        {            
            return new string[] { "Hello", "from", "GetStringArray" };
        }
        
        private static void SystemArrayFunctionalityExample()
        {
            Console.WriteLine("=> Working with System.Array");
            
            string[] gothicBands = { "Tones on Tail", "Bauhaus", "Sisters of Mercy" };
            
            Console.WriteLine("Here is the array:");
            for (int i = 0; i < gothicBands.Length; i++)
                Console.Write(gothicBands[i] + ", ");
            Console.WriteLine("\n");
            
            Array.Reverse(gothicBands);
            Console.WriteLine("The reversed array");
            for (int i = 0; i < gothicBands.Length; i++)
                Console.Write(gothicBands[i] + ", ");
            Console.WriteLine("\n");
            
            Console.WriteLine("Cleared out all but one...");
            Array.Clear(gothicBands, 1, 2);
            for (int i = 0; i < gothicBands.Length; i++)
                Console.Write(gothicBands[i] + ", ");
            Console.WriteLine();
            
            Console.WriteLine();
        }
    }
}