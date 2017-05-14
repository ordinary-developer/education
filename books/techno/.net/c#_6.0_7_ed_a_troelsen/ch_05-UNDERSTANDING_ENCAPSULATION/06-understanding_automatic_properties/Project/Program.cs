using System;

namespace Project
{
	class Car
	{
		public string PetName { get; set; }
		public int Speed { get; set; }
		public string Color { get; set; }
		
		public void DisplayStats()
		{
			Console.WriteLine("Car Name: {0}", PetName);
			Console.WriteLine("Speed: {0}", Speed);
			Console.WriteLine("Color: {0}", Color);
		}
	}
	
	class Garage
	{
	    public int NumberOfCars { get; set; } = 1;
		public Car MyAuto { get; set; } = new Car();
		
		public Garage() { }
		public Garage(Car car, int number)
		{
			MyAuto = car;
			NumberOfCars = number;
		}
	}
	
    class Program
    {
        public static void Main(string[] args)
        {
			InteractWithAutomaticProps();
            Console.ReadLine();
        }
		
		private static void InteractWithAutomaticProps()
		{
			Console.WriteLine("=> InteractWithAutomaticProps:");
			
			Car car = new Car();
			car.PetName = "Frank";
			car.Speed = 25;
			car.Color = "Red";
			car.DisplayStats();
			
			Garage garage = new Garage();
			garage.MyAuto = car;
			Console.WriteLine("Number of Cars in garage: {0}", garage.NumberOfCars);
			Console.WriteLine("Your car is named: {0}", garage.MyAuto.PetName);
			
			Console.WriteLine();
		}
		
    }
}