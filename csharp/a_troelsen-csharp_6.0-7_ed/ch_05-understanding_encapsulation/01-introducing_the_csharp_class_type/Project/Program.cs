using System;

namespace Project
{
    class Car
    {
        public string petName;
        public int currSpeed;
        
        public Car()
        {
            petName = "Chuck";
            currSpeed = 10;
        }
        
        public Car(string pn)
        {
            petName = pn;
        }
        
        public Car(string pn, int cs)
        {
            petName = pn;
            currSpeed = cs;
        }
        
        public void PrintState()
        {
            Console.WriteLine("{0} is going {1} MPH.", petName, currSpeed);
        }
        
        public void SpeedUp(int delta)
        {
            currSpeed += delta;
        }
    }
    
    class Motorcycle
    {
        public int driverIntensity;
        
        public void PopAWheely()
        {
            for (int i = 0; i <= driverIntensity; i++)
                Console.WriteLine("Yeeeee Haaaaaaawww!");
        }
        
        public Motorcycle() { }
        
        public Motorcycle(int intensity)
        {
            driverIntensity = intensity;
        }
    }
    
    class Program
    {
        public static void Main(string[] args)
        {
            SimpleObjectUsingExample();
            AClassWithCtorsUsingExample();
            DefaultCtorUsingExample();
            
            Console.ReadLine();
        }
        
        private static void SimpleObjectUsingExample()
        {
            Console.WriteLine("=> SimpleObjectUsingExample");
            
            Car myCar = new Car();
            myCar.petName = "Henry";
            myCar.currSpeed = 10;
            
            for (int i = 0; i <= 10; i++)
            {
                myCar.SpeedUp(5);
                myCar.PrintState();
            }
            
            Console.WriteLine();
        }
        
        private static void AClassWithCtorsUsingExample()
        {
            Console.WriteLine("=> AClassWithCtorsUsingExample");
            
            Car chuck = new Car();
            chuck.PrintState();
            
            Car mary = new Car("Mary");
            mary.PrintState();
            
            Car daisy = new Car("Daisy", 75);
            daisy.PrintState();
            
            Console.WriteLine();
        }
        
        private static void DefaultCtorUsingExample()
        {
            Console.WriteLine("=> DefaultCtorUsingExample");
            
            Motorcycle mc = new Motorcycle();
            mc.PopAWheely();
            
            Console.WriteLine();
        }
    }
}