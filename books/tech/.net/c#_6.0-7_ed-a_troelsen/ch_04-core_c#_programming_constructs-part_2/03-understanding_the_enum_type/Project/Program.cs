using System;

namespace Project
{
    enum EmployeeType
    {
        Manager,
        Grunt,
        Contractor,
        VicePresident
    }
    
    class Program
    {
        public static void Main(string[] args)
        {
            SimpleUseOfEnumExample();
            EvaluateEnumExample();
            
            Console.ReadLine();
        }
        
        private static void SimpleUseOfEnumExample()
        {
            Console.WriteLine("=> SimpleUseOfEnumExample:");
            
            EmployeeType employee = EmployeeType.Contractor;
            AskForBonus(employee);
            
            Console.WriteLine("EmployeeType uses a {0} for storage",
                              Enum.GetUnderlyingType(employee.GetType()));
            Console.WriteLine("EmployeType uses a {0} for storage",
                              Enum.GetUnderlyingType(typeof(EmployeeType)));
            
            Console.WriteLine("employee is a {0}", employee.ToString());
            
            Console.WriteLine("{0} = {1}", employee.ToString(), (byte)employee);
                              
            Console.WriteLine();
        }
        private static void AskForBonus(EmployeeType employee)
        {
            switch(employee)
            {
                case EmployeeType.Manager:
                    Console.WriteLine("How about stock options instead?");
                    break;
                case EmployeeType.Grunt:
                    Console.WriteLine("You have got to be kidding...");
                    break;
                case EmployeeType.Contractor:
                    Console.WriteLine("You already get enough cash...");
                    break;
                case EmployeeType.VicePresident:
                    Console.WriteLine("VERY GOOD, Sir!");
                    break;
            }
        }
        private static void EvaluateEnumExample()
        {
            Console.WriteLine("=> EvaluateEnumExample:");
            
            EmployeeType e = EmployeeType.Contractor;
            DayOfWeek day = DayOfWeek.Monday;
            ConsoleColor cc = ConsoleColor.Gray;
            
            EvaluateEnum(e);
            EvaluateEnum(day);
            EvaluateEnum(cc);
            
            Console.WriteLine();
        }
        private static void EvaluateEnum(System.Enum e)
        {
            Console.WriteLine("Underlying storage type: {0}", 
                              Enum.GetUnderlyingType(e.GetType()));
            
            Array enumData = Enum.GetValues(e.GetType());
            Console.WriteLine("This enum has {0} members.", enumData.Length);            
            for (int i = 0; i < enumData.Length; i++)
                Console.WriteLine("Name: {0}, Value: {0:D}",
                                  enumData.GetValue(i));
        }
    }
}