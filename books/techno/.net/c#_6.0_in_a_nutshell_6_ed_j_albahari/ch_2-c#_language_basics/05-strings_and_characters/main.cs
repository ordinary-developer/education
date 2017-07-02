using System;

class Test
{
    static void Example1_StringsAndCharacter()
    {
        char c = 'A';
        Console.WriteLine(c);

        char newLine = '\n';
        char backSlash = '\\';
        Console.WriteLine(newLine);
        Console.WriteLine(backSlash);

        char copyrightSymbol = '\u00A9';
        char omegaSymbol = '\u03A9';
        char newLineChar = '\u000A';
        Console.WriteLine(copyrightSymbol);
        Console.WriteLine(omegaSymbol);
        Console.WriteLine(newLineChar);
    }

    static void Example2_StringType()
    {
        string a1 = "Heat";
        Console.WriteLine(a1);

        string a2 = "test";
        string b2 = "test";
        Console.WriteLine(a2 == b2);

        string a3 = "Here's a tab:\t";
        Console.WriteLine(a3);

        string a4 = "\\\\server\\fileshare\\helloword.cs";
        Console.WriteLine(a4);
        string a5 = @"\\server\fileshare\helloword.cs";
        Console.WriteLine(a5);

        string escaped = "Frist Line\nSecond Line";
        string verbatim = @"First Line
Second Line";
        Console.WriteLine(escaped == verbatim);

        string xml = @"<customer id=""123""></customer>";
        Console.WriteLine(xml);
        
        string s1 = "a" + "b";
        string s2 = "a" + 5;
        Console.WriteLine(s1);
        Console.WriteLine(s2);
    }

    static void Main()
    {
        Example1_StringsAndCharacter();
        Example2_StringType();
    }
}
