using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using Microsoft.Office.Interop.Excel;


class Product
{
    public string Name { get; private set; }
    public decimal? Price { get; private set; }    

    public Product(string name, decimal price)
    {
        Name = name;
        Price = price;
    }

    Product() { }

    public static List<Product> GetSampleProducts()
    {
        return new List<Product>
        {
            new Product { Name = "West Side Story", Price = 9.99m },
            new Product { Name = "Assassins", Price = 14.99m },
            new Product { Name = "Frogs", Price = 13.99m },
            new Product { Name = "Sweeney Todd", Price = 10.99m },
            new Product { Name = "Unknown Item", Price = null }
        };
    }

    public override string ToString()
    {
        return string.Format("{0}: {1}", Name, Price);
    }
}

class Test
{
    static void Main()
    {		
		var app = new Application() { Visible = false };
		Workbook workbook = app.Workbooks.Add();
		Worksheet worksheet = (Worksheet)app.ActiveSheet;
		int row = 1;	
		foreach (var product in Product.GetSampleProducts()
									   .Where(p => null != p.Price))
		{
			((Range)worksheet.Cells[row, 1]).Value = product.Name;
			((Range)worksheet.Cells[row, 2]).Value = product.Price;
			row++;
		}			
		workbook.SaveAs(Filename: "demo.xls",
		                FileFormat: XlFileFormat.xlWorkbookNormal);
		app.Application.Quit();	
    }
}
