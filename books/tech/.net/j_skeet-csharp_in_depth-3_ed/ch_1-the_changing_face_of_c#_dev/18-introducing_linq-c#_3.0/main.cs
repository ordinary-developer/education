using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Product
{
    public string Name { get; private set; }
    public decimal Price { get; private set; }
    public int SupplierID { get; private set; }

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
            new Product { Name = "West Side Story", Price = 9.99m, SupplierID = 1 },
            new Product { Name = "Assassins", Price = 14.99m, SupplierID = 2 },
            new Product { Name = "Frogs", Price = 13.99m, SupplierID = 1 },
            new Product { Name = "Sweeney Todd", Price = 10.99m, SupplierID = 3 }
        };
    }

    public override string ToString()
    {
        return string.Format("{0}: {1}", Name, Price);
    }
}

class Supplier 
{
    public string Name { get; private set; }
    public int SupplierID { get; private set; }

    Supplier() { }

    public static List<Supplier> GetSampleSuppliers()
    {
        return new List<Supplier>
        {
            new Supplier { Name = "Solely Sondheim", SupplierID = 1 },
            new Supplier { Name = "CD-by-CD-by-Sondheim", SupplierID = 2 },
            new Supplier { Name = "Barbershop CDs", SupplierID = 3 }
        };
    }
}

class Test 
{
    public static void Main()
    {
        List<Product> products = Product.GetSampleProducts();
        List<Supplier> suppliers = Supplier.GetSampleSuppliers();

        var filtered = from p in products
                       join s in suppliers
                              on p.SupplierID equals s.SupplierID
                       where p.Price > 10
                       orderby s.Name, p.Name
                       select new { SupplierName = s.Name, ProductName = p.Name };

        foreach (var v in filtered)
            Console.WriteLine("Supplier = {0}; Product = {1}",
                              v.SupplierName, v.ProductName);
    }
}

