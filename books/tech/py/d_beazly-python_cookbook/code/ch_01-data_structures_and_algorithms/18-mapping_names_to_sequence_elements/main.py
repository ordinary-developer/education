def example_1():
    from collections import namedtuple
    Subscriber = namedtuple('Subscriber', ['addr', 'joined'])
    sub = Subscriber('mail@mail.ru', '2012-10-19')
    print(sub)
    print(sub.addr, sub.joined)

    print(len(sub))
    addr, joined = sub
    print(addr, joined)


def example_2():
    def compute_cost(records):
        total = 0.0
        for record in records:
            total += record[1] * record[2]
        return total

    records = [
        ('APPLE', 25, 7.34),
        ('FB', 75, 8.93),
        ('HP', 34, 10.34)
    ]
    print(compute_cost(records))


def example_3():
    records = [
        ('APPLE', 25, 7.34),
        ('FB', 75, 8.93),
        ('HP', 34, 10.34)
    ]

    from collections import namedtuple
    Stock = namedtuple('Stock', ['name', 'shares', 'price'])

    def compute_cost(records):
        total = 0.0
        for record in records:
            stock = Stock(*record)
            total += stock.shares * stock.price
        return total

    print(compute_cost(records))


def example_4():
    from collections import namedtuple
    Stock = namedtuple('Stock', ['name', 'shares', 'price'])
    stock = Stock('ACME', 100, 123.45)
    stock = stock._replace(shares = 75, price = 125.55)
    print(stock)


def example_5():
    a = { 'name': 'ACME', 'shares': 100, 'price': 123.45 }
    b = { 'name': 'ACME', 'shares': 100, 'price': 123.45, 'date': '12/17/2012' }

    from collections import namedtuple
    Stock = namedtuple('Stock', ['name', 'shares', 'price', 'data', 'time'])
    stock_prototype = Stock('', 0, 0.0, None, None)

    def dict_to_stock(d):
        return stock_prototype._replace(**d)

    print(dict_to_stock(a))
    print(dict_to_stock(b))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
