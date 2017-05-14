
using System;

namespace Project
{
    struct Point
    {
        public Point(int xPos, int yPos) { X = xPos; Y = yPos; }
            
        public int X;
        public int Y;
        
        public void Increment() { X++; Y++; }
        public void Decrement() { X--; Y--; }
        public void Display() { Console.WriteLine("X = {0}, Y = {1}", X, Y); }
    }
    
    class PointRef
    {
        public PointRef(int xPos, int yPos) { X = xPos; Y = yPos; }
        
        public int X;
        public int Y;
        
        public void Display() { Console.WriteLine("X = {0}, Y = {1}", X, Y); }
    }
    
    class ShapeInfo
    {
        public ShapeInfo(string info) { infoString = info; }
        public string infoString;
    }
    
    struct Rectangle
    {
        public Rectangle(string info, int top, int left, int bottom, int right)
        {
            rectInfo = new ShapeInfo(info);
            rectTop = top; rectBottom = bottom;
            rectLeft = left; rectRight = right;
        }
        
        public void Display()
        {
            Console.WriteLine("String = {0}, Top = {1}, Bottom = {2}, Left = {3}, Right = {4}",
                              rectInfo.infoString, 
                              rectTop, 
                              rectBottom, 
                              rectLeft, 
                              rectRight);
        }
        
        public ShapeInfo rectInfo;
        public int rectTop, rectLeft, rectBottom, rectRight;
    }
    
    class Person
    {
        public Person(string name, int age)
        {
            personName = name;
            personAge = age;
        }
        
        public Person() { }
        
        public void Display() 
        {
            Console.WriteLine("Name: {0}, Age: {1}", personName, personAge);
        }
        
        public string personName;
        public int personAge;
    }
    
    class Program
    {
        public static void Main(string[] args)
        {
            ValueTypeAssignmentExample();
            ReferenceTypeAssignmentExample();
            ValueTypeContainingRefTypeExample();
            SendRefTypeByValueExample();
            SendRefTypeByRefExample();
            
            Console.ReadLine();
        }
        
        private static void ValueTypeAssignmentExample()
        {
            Console.WriteLine("=> ValueTypeAssignmentExample");
            
            Point p1 = new Point(10, 10);
            Point p2 = p1;
            
            p1.Display();
            p2.Display();
            
            p1.X = 100;
            Console.WriteLine("\n-> Changed p1.X\n");
            p1.Display();
            p2.Display();            
            
            Console.WriteLine();
        }
        
        private static void ReferenceTypeAssignmentExample()
        {
            Console.WriteLine("=> ReferenceTypeAssignmentExample");
            
            PointRef p1 = new PointRef(10, 10);
            PointRef p2 = p1;
            
            p1.Display();
            p2.Display();
            
            p1.X = 100;
            Console.WriteLine("\n-> Changed p1.X\n");
            p1.Display();
            p2.Display();
            
            Console.WriteLine();
        }
        
        private static void ValueTypeContainingRefTypeExample()
        {
            Console.WriteLine("=> ValueTypeContainingRefTypeExample");
            
            Console.WriteLine("-> Creating r1");
            Rectangle r1 = new Rectangle("First rect", 10, 10, 50, 50);
            
            Console.WriteLine("-> Assigning r2 to r1");
            Rectangle r2 = r1;
            
            Console.WriteLine("-> Chaning values of r2");
            r2.rectInfo.infoString = "This is new info!";
            r2.rectBottom = 4444;
            
            r1.Display();
            r2.Display();
            
            Console.WriteLine();
        }
        
        private static void SendRefTypeByValueExample()
        {
            Console.WriteLine("=> SendRefTypeByValueExample");
            
            Person fred = new Person("Fred", 12);
            Console.WriteLine("\nBefore by value call, Person is:");
            fred.Display();
            SendAPersonByValue(fred);
            Console.WriteLine("\nAfter value call, Person is:");
            fred.Display();
            
            Console.WriteLine();
        }
        private static void SendAPersonByValue(Person p)
        {
            p.personAge = 99;
            p = new Person("Nikki", 9);
        }
        
        private static void SendRefTypeByRefExample()
        {
            Console.WriteLine("=> SendRefTypeByRefExample");
            
            Person mel = new Person("Mel", 23);
            Console.WriteLine("Before by ref call, Person is:");
            mel.Display();
            SendAPersonByReference(ref mel);
            Console.WriteLine("After ref call, Person is:");
            mel.Display();            
            
            Console.WriteLine();
        }
        private static void SendAPersonByReference(ref Person p)
        {
            p.personAge = 555;
            p = new Person("Nikki", 9999);
        }
    }
}