class WebServiceResult(object): pass
# Imagine these are loaded dynamically...
product1 = WebServiceResult()
product1.ProductName = "West Wide Story"
product1.Price = 9.99

product2 = WebServiceResult()
product2.ProductName = "Assassins"
product2.Price = 14.99

products = [product1, product2]
