using System;

namespace Project
{
    class Employee
    {
        private string empName;
        private int empID;
        private float currPay;
		private int empAge;
		
		public string Name
		{
			get { return empName; }
			set 
			{
				if (value.Length > 15)
					Console.WriteLine("Error! Name length exceeds 15 characters!");
				else
					empName = value;
			}
		}
				
		public int Age
		{
			get { return empAge; }
			set { empAge = value; }
		}
		
		public int ID 
		{
			get { return empID; }
			set { empID = value; }
		}
		
		public float Pay
		{
			get { return currPay; }
			set { currPay = value; }
		}
        
        public Employee() { }
		public Employee(string name, int id, float pay)
			: this(name, 0, id, pay) { }
        public Employee(string name, int age, int id, float pay)
        {
            Name = name;
			Age = age;
            ID = id;			
            Pay = pay;
        }
        
        public void GiveBonus(float amount)
		{
			Pay += amount;
		}
		
		public void DisplayStats()
		{
			Console.WriteLine("Name: {0}", Name);
			Console.WriteLine("Age: {0}", Age);
			Console.WriteLine("ID: {0}", ID);
			Console.WriteLine("Pay: {0}", Pay);
		}		
    }
	
	class SavingsAccount
	{
		public double currentBalance;	
		
		public static double InterestRate
		{
			get { return currentInterestRate; }
			set { currentInterestRate = value; }
		}
		
		private static double currentInterestRate = 0.04;
	}
        
    class Program
    {
        public static void Main(string[] args)
        {
			UsePropertiesWithInstances();
			UsePropertiesWithStaticClasses();
			
			Console.ReadLine();
        }
		
		private static void UsePropertiesWithInstances()
		{
			Console.WriteLine("=> UsePropertiesWithInstances:");
			
			Employee joe = new Employee();
			joe.Age++;			
			joe.DisplayStats();
			
			Console.WriteLine();
		}
		
		private static void UsePropertiesWithStaticClasses()
		{
			Console.WriteLine("=> UsePropertiesWithStaticClasses:");
			
			Console.WriteLine("InterestRate is: {0}", SavingsAccount.InterestRate);
			
			Console.WriteLine();
		}
		
    }
}