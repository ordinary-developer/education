using System;

public class UnitConverter
{
    int ratio;
    public UnitConverter(int unitRatio) { ratio = unitRatio; }
    public int Convert (int unit) { return unit * ratio; }
}

public class Panda
{
    public string Name;
    public static int Population;

    public Panda(string n)
    {
        Name = n;
        Population = Population + 1;
    }
}

public struct PointValue { public int X, Y; }
public class PointClass { public int X, Y; }

class Test
{
    static void Example1_PredefinedTypeExamples() 
    {
        string message = "Hello world";
        string upperMessage = message.ToUpper();
        Console.WriteLine(upperMessage);

        int x = 2015;
        message = message + x.ToString();
        Console.WriteLine(message);
    }

    static void Example2_PredefinedTypeExamples()
    {
        bool simpleVar = false;
        if (simpleVar)
            Console.WriteLine("This will not print");

        int x = 5000;
        bool lessThanAMile = x < 5280;
        if (lessThanAMile)
            Console.WriteLine("This will print");
    }

    static void Example3_CustomTypeExamples()
    {
        UnitConverter feetToInchesConverter = new UnitConverter(12);
        UnitConverter milesToFeetConverter = new UnitConverter(5280);

        Console.WriteLine(feetToInchesConverter.Convert(30));
        Console.WriteLine(feetToInchesConverter.Convert(100));
        Console.WriteLine(feetToInchesConverter.Convert(
                            milesToFeetConverter.Convert(1)));
    }

    static void Example4_InstanceVersusStaticMembers()
    {
        Panda p1 = new Panda("Pan Dee");
        Panda p2 = new Panda("Pan Dah");

        Console.WriteLine(p1.Name);
        Console.WriteLine(p2.Name);

        Console.WriteLine(Panda.Population);
    }

    static void Example5_Conversions()
    {
        int x = 12345;
        long y = x;
        short z = (short)x;
    }

    static void Example6_ValueTypes()
    {
        PointValue p1 = new PointValue();
        p1.X = 7;

        PointValue p2 = p1;
        Console.WriteLine(p1.X);
        Console.WriteLine(p2.X);

        p1.X = 9;
        Console.WriteLine(p1.X);
        Console.WriteLine(p2.X);
    }

    static void Example7_ReferenceTypes()
    {
        PointClass p1 = new PointClass();
        p1.X = 7;

        PointClass p2 = p1;
        Console.WriteLine(p1.X);
        Console.WriteLine(p2.X);

        p1.X  = 9;
        Console.WriteLine(p1.X);
        Console.WriteLine(p2.X);
    }

    static void Example8_Null()
    {
        PointClass p1 = null;
        Console.WriteLine(null == p1);

        try 
        {
            Console.WriteLine(p1.X);
        }
        catch (NullReferenceException) { Console.WriteLine("Exception was caught"); }

        // will not compile
        // PointValue p2 = null;
        // int x = null;
    }

    static void Example9_PredefinedTypeTaxonomy()
    {
        int i = 5;
        System.Int32 i = 5;
        bool b = true;
        char c = 'A';
        float f = 0.5f;
    }

    static void Example10_NumericLiterals()
    {
        int x = 127;
        long y = 0x7F;
        double d = 1.5;
        double million = 1e06;
    }

    static void Example11_NumericLiteralTypeInference()
    {
        Console.WriteLine(1.0.GetType());
        Console.WriteLine(1e06.GetType());
        Console.WriteLine(1.GetType());
        Console.WriteLine(0xf0000000.GetType());
        Console.WriteLine(0x100000000.GetType());
    }

    static void Main()
    {
        Example1_PredefinedTypeExamples();
        Example2_PredefinedTypeExamples();
        Example3_CustomTypeExamples();
        Example4_InstanceVersusStaticMembers();
        Example5_Conversions();
        Example6_ValueTypes();
        Example7_ReferenceTypes();
        Example8_Null();
        Example9_PredefinedTypeTaxonomy();
        Example10_NumericLiterals();
        Example11_NumericLiteralTypeInference();
    }
}
