using System;

namespace Project
{
    struct Point
    {
        public int X;
        public int Y;
        
        public void Increment() { X++; Y++; }
        public void Decrement() { X--; Y--; }
        public void Display() { Console.WriteLine("X = {0}, Y = {1}", X, Y); }
    }
    
    struct AnotherPoint
    {
        public int X;
        public int Y;
        
        public AnotherPoint(int xPos, int yPos)
        {
            X = xPos;
            Y = yPos;
        }
        
        public void Increment() { X++; Y++; }
        public void Decrement() { X--; Y--; }
        public void Display() { Console.WriteLine("X = {0}, Y = {1}", X, Y); }
    }
    
    class Program
    {
        public static void Main(string[] args)
        {
            SimpleStructUsingExample();
            
            Console.ReadLine();
        }
        
        private static void SimpleStructUsingExample()
        {
            Console.WriteLine("=> SimpleStructUsingExample");
            
            Point myPoint1;
            myPoint1.X = 349;
            myPoint1.Y = 76;
            myPoint1.Display();
            myPoint1.Increment();
            myPoint1.Display();
            
            Point myPoint2 = new Point();
            myPoint2.Display();
            
            AnotherPoint anotherPoint = new AnotherPoint(50, 60);
            anotherPoint.Display();
            
            Console.WriteLine();
        }
    }
}