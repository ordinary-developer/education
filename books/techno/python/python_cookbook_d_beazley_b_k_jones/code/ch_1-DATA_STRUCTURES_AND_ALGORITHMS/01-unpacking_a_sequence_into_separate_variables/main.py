def example_1():
    p = (4, 5)
    x, y = p
    print(x, y)


def example_2():
    data = [ 'ACME', 50, 91.1, (2012, 12, 21) ]
    name, shares, price, date = data
    print(name, shares, price, date)


def example_3():
    data = [ 'ACME', 50, 91.1, (2012, 12, 21) ]
    name, shares, price, (year, mon, day) = data
    print(name, shares, price)
    print(year, mon, day)


def example_4():
    try:
        p = (4, 5)
        x, y, z = p
    except ValueError:
        print("An error was occurred")


def example_5():
    s = 'Hello'
    a, b, c, d, e = s
    print(a, c, e)


def example_6():
    data = [ 'ACME', 50, 91.1, (2012, 12, 21) ]
    _, shares, price, _ = data
    print(shares, price)


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
    
