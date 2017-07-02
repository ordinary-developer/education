using System;

class Test
{
    class Dude
    {
        public string Name;
        public Dude (string n) { Name = n; }
    }

    static void Example1_EqualityAndComparisonOperators()
    {
        int x = 1;
        int y = 2;
        int z = 1;
        Console.WriteLine(x == y);
        Console.WriteLine(x == z);

        Dude d1 = new Dude("John");
        Dude d2 = new Dude("John");
        Console.WriteLine(d1 == d2);
        Dude d3 = d1;
        Console.WriteLine(d1 == d3);
    }

    static bool UseUmbrella1(bool rainy, bool sunny, bool windy)
    {
        return !windy && (rainy || sunny);
    }

    static bool UseUmbrella2(bool rainy, bool sunny, bool windy)
    {
        return !windy & (rainy | sunny);
    }

    static void Example2_ConditionalOperators()
    {
        bool toTakeUmbrella = UseUmbrella1(true, false, false);
        Console.WriteLine(toTakeUmbrella);

        toTakeUmbrella = UseUmbrella2(true, false, false);
        Console.WriteLine(toTakeUmbrella);
    }

    static int Max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    static void Example3_TernaryOperator()
    {
        Console.WriteLine(Max(3, 5));
    }

    static void Main()
    {
        Example1_EqualityAndComparisonOperators();
        Example2_ConditionalOperators();
        Example3_TernaryOperator();
    }
}
