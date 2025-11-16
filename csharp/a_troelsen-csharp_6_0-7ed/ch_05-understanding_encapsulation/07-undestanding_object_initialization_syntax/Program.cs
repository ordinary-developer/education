using System;

class Point 
{
	public int X { get; set; }
	public int Y { get; set; }
	
	public Point() { }
	
	public Point(int xValue, int yValue) 
	{
		X = xValue;
		Y = yValue;
	}
	
	public void DisplayStats()
	{
		Console.WriteLine("[{0}, {1}]", X, Y);
	}
	
}

enum PointColor { LightBlue, BloodRed, Gold };
class AnotherPoint
{
	public int X { get; set; }
	public int Y { get; set; }
	public PointColor Color { get; set; }
	
	public AnotherPoint(int xValue, int yValue)
	{
		X = xValue;
		Y = yValue;
		Color = PointColor.Gold;
	}
	
	public AnotherPoint(PointColor pointColor)
	{
		Color = pointColor;
	}
	
	public AnotherPoint()
		: this(PointColor.BloodRed) { }
		
	public void DisplayStats()
	{
		Console.WriteLine("[{0}, {1}]", X, Y);
		Console.WriteLine("Point is {0}", Color);
	}
}

class Rectangle 
{
	private AnotherPoint topLeft = new AnotherPoint();
	private AnotherPoint bottomRight = new AnotherPoint();
	
	public AnotherPoint TopLeft
	{
		get { return topLeft; }
		set { topLeft = value; }
	}
	
	public AnotherPoint BottomRight
	{
		get { return bottomRight; }
		set { bottomRight = value; }
	}
	
	public void DisplayStats()
	{
		Console.WriteLine("[TopLeft: {0}, {1}, {2} BottomRight: {3}, {4}, {5}]",
						  topLeft.X,
						  topLeft.Y,
						  topLeft.Color,
						  bottomRight.X,
						  bottomRight.Y,
						  bottomRight.Color);
	}
}

namespace Project
{
    class Program
    {
        public static void Main(string[] args)
        {
			Example1();
			Example2();
			Example3();
            Console.ReadLine();
        }
		
		private static void Example1()
		{
			Console.WriteLine("=> Example1");
			
			Point firstPoint = new Point();
			firstPoint.X = 10;
			firstPoint.Y = 10;
			firstPoint.DisplayStats();
			
			Point anotherPoint = new Point(20, 20);
			anotherPoint.DisplayStats();
			
			Point finalPoint = new Point { X = 30, Y = 30 };
			finalPoint.DisplayStats();
			
			Console.WriteLine();
		}
		
		private static void Example2()
		{
			Console.WriteLine("=> Example2");
			
			AnotherPoint goldPoint = new AnotherPoint(PointColor.Gold) { X = 90, Y = 20 };
			goldPoint.DisplayStats();
			
			Console.WriteLine();			
		}
		
		private static void Example3()
		{
			Console.WriteLine("=> Example3");
			
			Rectangle myRect = new Rectangle
			{
				TopLeft = new AnotherPoint { X = 10, Y = 10 },
				BottomRight = new AnotherPoint { X = 200, Y = 200 }
			};
			myRect.DisplayStats();
			
			Console.WriteLine();			
		}
    }
}