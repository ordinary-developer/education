using System;

class Test
{
    static void Example1_NumericLiterals()
    {
        int x = 127;
        long y = 0x7F;
        double d = 1.5;
        double million = 1e06;
    }

    static void Example2_NumericLiteralTypeInference()
    {
        Console.WriteLine(1.0.GetType());
        Console.WriteLine(1e06.GetType());
        Console.WriteLine(1.GetType());
        Console.WriteLine(0xf0000000.GetType());
        Console.WriteLine(0x100000000.GetType());
    }

    static void Example3_NumericSuffixes()
    {
        long i = 5;
        double x = 4.0;
        float f = 4.5F;
        decimal d = -1.23M;
    }

    static void Example4_NumericConversions()
    {
        int x = 12345;
        long y = x;
        short z = (short)x;

        int i = 1;
        float f = i;
        int i2 = (int)f;

        int i01 = 100000001;
        float f0 = i01;
        int i02 = (int)f0;
    }
    
    static void Example5_ArithmeticOperators()
    {
        int x = 0, y = 0;
        Console.WriteLine(x++);
        Console.WriteLine(++y);

        int a = 2 / 3;
        int b = 0;
        try
        {
            int c = 5 / b;
        }
        catch (Exception) { Console.WriteLine("Division by zero has been ocurred"); }

        a = int.MinValue;
        a--;
        Console.WriteLine(a == int.MaxValue);

        a = 10000000;
        b = 10000000;
        try
        {
            int c = checked(a * b);
        }
        catch (OverflowException) { Console.WriteLine("Overflow exception was caught"); }

        try
        {
            checked
            {
                int c = a * b;
            }
        }
        catch (OverflowException) { Console.WriteLine("Overflow exception was caught"); }

        x = int.MaxValue;
        y = unchecked (x + 1);
        unchecked { int z = x + 1; }

        // compile time error
        // int x = int.MaxValue + 1;
        y = unchecked(int.MaxValue + 1);
    }

    static void Example6_8BitAnd16BitIntegrals()
    {
        short x = 1, y = 1;
        // compile time error
        //short z = x + y;
        short z = (short)(x + y); 
    }

    static void Example7_SpecialFloatAndDoubleValues()
    {
        Console.WriteLine(double.NegativeInfinity);
        Console.WriteLine(1.0 / 0.0);
        Console.WriteLine(-1.0 / 0.0);
        Console.WriteLine(1.0 / -0.0);
        Console.WriteLine(-1.0 / -0.0);

        Console.WriteLine(0.0 / 0.0);
        Console.WriteLine((1.0 / 0.0) - (1.0 / 0.0));

        Console.WriteLine(0.0 / 0.0 == double.NaN);

        Console.WriteLine(double.IsNaN(0.0 / 0.0));
        Console.WriteLine(double.IsNaN(0.0F / 0.0F));
        Console.WriteLine(float.IsNaN(0.0F / 0.0F));

        Console.WriteLine(object.Equals(0.0 / 0.0, double.NaN));
    }

    static void Example8_RealNumberRoundingErrors()
    {
        float tenth = 0.1f;
        float one = 1f;
        Console.WriteLine(one - tenth * 10f);

        decimal m = 1M / 6M;
        double d = 1.0 / 6.0;
        Console.WriteLine(m);
        Console.WriteLine(d);

        decimal notQuiteWholeM = m + m  + m + m + m + m;
        double notQuiteWholeD = d + d + d + d + d + d;
        Console.WriteLine(notQuiteWholeM);
        Console.WriteLine(notQuiteWholeD);
        Console.WriteLine(notQuiteWholeM == 1M);
        Console.WriteLine(notQuiteWholeD < 1.0);
    }


    static void Main()
    {
        Example1_NumericLiterals();
        Example2_NumericLiteralTypeInference();
        Example3_NumericSuffixes();
        Example4_NumericConversions();
        Example5_ArithmeticOperators();
        Example6_8BitAnd16BitIntegrals();
        Example7_SpecialFloatAndDoubleValues();
        Example8_RealNumberRoundingErrors();
    }
}
