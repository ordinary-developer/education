using System;

namespace Project
{
    class Employee
    {
        private string empName;
        private int empID;
        private float currPay;
		
		public string GetName()
		{
			return empName;
		}
		
		public void SetName(string name)
		{
			if (name.Length > 15)
				Console.WriteLine("Error! Name length exceeds 15 characters!");
			else
				empName = name;
		}
        
        public Employee() { }
        public Employee(string name, int id, float pay)
        {
            empName = name;
            empID = id;
            currPay = pay;
        }
        
        public void GiveBonus(float amount)
		{
			currPay += amount;
		}
		
		public void DisplayStats()
		{
			Console.WriteLine("Name: {0}", empName);
			Console.WriteLine("ID: {0}", empID);
			Console.WriteLine("Pay: {0}", currPay);
		}		
    }
        
    class Program
    {
        public static void Main(string[] args)
        {
			Employee emp = new Employee("Marvin", 456, 30000);
			emp.GiveBonus(1000);
			emp.DisplayStats();
			emp.SetName("Marv");
			Console.WriteLine("Employee is named: {0}", emp.GetName());
			
			Employee emp2 = new Employee();
			emp2.SetName("Xena the warrior princess");
			
			Console.ReadLine();
        }
    }
}