using System;

namespace Project
{
    class Motorcycle
    {
        public int driverIntensity;
        public string driverName;
        
        public Motorcycle() 
        {
            Console.WriteLine("In default ctor");
        }
        public Motorcycle(int intensity)
            : this(intensity, "")
        {
            Console.WriteLine("In ctor taking an int");
        }
        public Motorcycle(string name)
            : this(0, name)
        {
            Console.WriteLine("In ctor taking a string");
        }
            
        public Motorcycle(int intensity, string name)
        {
            Console.WriteLine("In master ctor ");
            if (intensity > 10)
                intensity = 10;
            driverIntensity = intensity;
            driverName = name;
        }
        
        public void PopAWheely()
        {
            for (int i = 0; i <= driverIntensity; i++)
                Console.WriteLine("Yeeeee Haaaaeewww!");
        }
        
    }
    
    class MotorcycleWithDefaultParams
    {
        public int driverIntensity;
        public string driverName;
        
        public MotorcycleWithDefaultParams(int intensity = 0, string name = "")
        {
             if (intensity > 10)
                intensity = 10;
            driverIntensity = intensity;
            driverName = name;
        }
       
        public void PopAWheely()
        {
            for (int i = 0; i <= driverIntensity; i++)
                Console.WriteLine("Yeeeee Haaaaeewww!");
        }
        
    }
    class Program
    {
        public static void Main(string[] args)
        {
            KeywordThisUsingExample();
            DefaultCtorArgsUsingExample();
            
            Console.ReadLine();
        }
        
        private static void KeywordThisUsingExample()
        {
            Console.WriteLine("=> KeywordThisUsingExample");
            
            Motorcycle c = new Motorcycle(5);
            c.PopAWheely();
            
            Console.WriteLine();
        }
        
        private static void DefaultCtorArgsUsingExample()
        {
            Console.WriteLine("=> DefaultCtorArgsUsingExample");
            
            MotorcycleWithDefaultParams m1 = new MotorcycleWithDefaultParams();
            Console.WriteLine("Name = {0}, Intensity = {1}",
                              m1.driverName, m1.driverIntensity);
                              
            MotorcycleWithDefaultParams m2 = new MotorcycleWithDefaultParams(name:"Tiny");
            Console.WriteLine("Name = {0}, Intensity = {1}",
                              m2.driverName, m2.driverIntensity);     
                              
            MotorcycleWithDefaultParams m3 = new MotorcycleWithDefaultParams(intensity:7);
            Console.WriteLine("Name = {0}, Intensity = {1}",
                              m3.driverName, m3.driverIntensity);    
            
            Console.WriteLine();
        }
    }
}