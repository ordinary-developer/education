using System;
using System.Collections;
using System.Collections.Generic;

class Product
{
    string name;
    public string Name 
    {
        get { return name; }
        private set { name = value; }
    }

    decimal? price;
    public decimal? Price
    {
        get { return price; }
        private set { price = value; }
    }

    public Product(string name, decimal? price)
    {
        Name = name;
        Price = price;
    }

    public static List<Product> GetSampleProducts()
    {
        List<Product> list = new List<Product>();
        list.Add(new Product("West Side Story", 9.99m));
        list.Add(new Product("Assassins", 14.99m));
        list.Add(new Product("Frogs", 13.99m));
        list.Add(new Product("Sweeny Todd", 10.99m));
        list.Add(new Product("Unknown item", null));
        return list;
    }

    public override string ToString()
    {
        return string.Format("{0}: {1}", name, price);
    }
}

class Test 
{
    public static void Main()
    {
        List<Product> products = Product.GetSampleProducts();
        products.FindAll(delegate(Product p) { return null == p.Price; })
                .ForEach(Console.WriteLine);
    }
}
