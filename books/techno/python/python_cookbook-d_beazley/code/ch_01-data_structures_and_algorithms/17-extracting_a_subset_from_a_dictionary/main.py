def example_1():
    prices = {
        'ACME': 45.23,
        'AAPL': 612.78,
        'IBM': 205.55,
        'HPQ': 37.20,
        'FB': 10.75
    }
    tech_names = { 'AAPL', 'IMB', 'HPQ', 'MSFT' }

    p1 = { key:value for key, value in prices.items() if value > 200 }
    print(p1)

    p2 = { key:value for key, value in prices.items() if key in tech_names }
    print(p2)


def example_2():
    prices = {
        'ACME': 45.23,
        'AAPL': 612.78,
        'IBM': 205.55,
        'HPQ': 37.20,
        'FB': 10.75
    }
    tech_names = { 'AAPL', 'IMB', 'HPQ', 'MSFT' }

    p1 = dict((key, value) for key, value in prices.items() if value > 200)
    print(p1)

    p2 = { key:prices[key] for key in prices.keys() & tech_names }
    print(p2)


if __name__ == '__main__':
    example_1()
    example_2()
