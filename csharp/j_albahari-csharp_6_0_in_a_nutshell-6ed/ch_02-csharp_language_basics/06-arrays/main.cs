using System;

public struct PointStruct { public int X, Y; }
public class PointClass { public int X, Y; }

class Test
{
    static void Example1_Arrays()
    {
        char[] vowels = new char[5];
        vowels[0] = 'a';
        vowels[1] = 'e';
        vowels[2] = 'i';
        vowels[3] = 'o';
        vowels[4] = 'u';
        Console.WriteLine(vowels[1]);

        for (int i = 0; i < vowels.Length; i++)
            Console.Write(vowels[i]);

        char[] vowels2 = new char[] { 'a', 'e', 'i', 'o', 'u' };
        char[] vowels3 = { 'a', 'e', 'i', 'o', 'u' };
    }

    static void Example2_DefaultElementInitialization()
    {
        int[] a = new int[1000];
        Console.WriteLine(a[123]);
    }

    static void Example3_ValueTypeVsReferenceTypes()
    {
        PointStruct[] a1 = new PointStruct[1000];
        int x1 = a1[500].X;

        PointClass[] a2 = new PointClass[1000];
        try 
        {
            int x2 = a2[500].X;
        }
        catch (Exception) { Console.WriteLine("exception"); }

        PointClass[] a3 = new PointClass[1000];
        for (int i = 0; i < a3.Length; i++)
            a3[i] = new PointClass();

        int[] a4 = null;
    }

    static void Example4_RectangularArrays()
    {
        int[,] matrix = new int[3,3];
        for (int i = 0; i < matrix.GetLength(0); i++)
            for (int j = 0; j < matrix.GetLength(1); j++)
                matrix[i, j] = i * 3 + j;

        int[,] matrix2 = new int[,]
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}
        };
    }

    static void Example5_JaggedArrays()
    {
        int[][] matrix = new int[3][];
        for (int i = 0; i < matrix.Length; i++)
        {
            matrix[i] = new int[3];
            for (int j = 0; j < matrix[i].Length; j++)
                matrix[i][j] = i * 3 + j;
        }

        int[][] matrix2 = new int[][]
        {
            new int[] { 0, 1, 2 },
            new int[] { 3, 4, 5 },
            new int[] { 6, 7, 8, 9 }
        };
    }
    
    static void Example6_SimplifiedArrayInitializationExpressions()
    {
        char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
        int[,] rectangularMatrix = 
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}
        };

        int[][] jaggedMatrix = 
        {
            new int[] {0, 1, 2},
            new int[] {3, 4, 5},
            new int[] {6, 7, 8}
        };

        var i = 3;
        var s = "sausage";

        var rectMatrix = new int[,]
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8}
        };

        var jaggedMat = new int[][]
        {
            new int[] {0, 1, 2},
            new int[] {3, 4, 5},
            new int[] {6, 7, 8}
        };

        var charVowels = new[] { 'a', 'e', 'i', 'o', 'u' };
        var x = new[] { 1, 1000000000000 };
    }

    static void Example7_BoundsChecking()
    {
        int[] arr = new int[3];
        try
        {
            arr[3] = 1;
        }
        catch (IndexOutOfRangeException) { Console.WriteLine("IndexOutOfRangeException"); }
    }

    static void Main()
    {
        Example1_Arrays();
        Example2_DefaultElementInitialization();
        Example3_ValueTypeVsReferenceTypes();
        Example4_RectangularArrays();
        Example5_JaggedArrays();
        Example6_SimplifiedArrayInitializationExpressions();
        Example7_BoundsChecking();
    }
}
