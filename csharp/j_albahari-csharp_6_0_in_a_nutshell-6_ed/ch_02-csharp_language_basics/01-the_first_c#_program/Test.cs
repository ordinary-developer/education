using System;

class Test 
{
    static void Main()
    {
	Console.WriteLine(FeetToInches(30));
	Console.WriteLine(FeetToInches(100));
    }

    static int FeetToInches(int feet)
    {
	int inches = feet * 12;
	return inches;
    }
}
