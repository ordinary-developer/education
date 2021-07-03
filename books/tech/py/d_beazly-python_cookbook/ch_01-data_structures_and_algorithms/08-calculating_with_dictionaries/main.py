def example_1():
    prices = {
        'ACME': 45.23,
        'AAPL': 612.78,
        'IBM': 205.55,
        'HPQ': 37.20,
        'FB': 10.75
    }

    min_price = min(zip(prices.values(), prices.keys()))
    max_price = max(zip(prices.values(), prices.keys()))
    print(min_price, max_price)

    sorted_prices = sorted(zip(prices.values(), prices.keys()))
    print(sorted_prices)

    prices_and_names = zip(prices.values(), prices.keys())
    print(min(prices_and_names))
    try:
        print(max(prices_and_names))
    except ValueError:
        print('here is ValueError')


def example_2():
    prices = {
        'ACME': 45.23,
        'AAPL': 612.78,
        'IBM': 205.55,
        'HPQ': 37.20,
        'FB': 10.75
    }

    print(min(prices))
    print(max(prices))
    print(min(prices.values()))
    print(max(prices.values()))

    print(min(prices, key = lambda k: prices[k]))
    print(max(prices, key = lambda k: prices[k]))

    print(prices[min(prices, key = lambda k: prices[k])])
    print(prices[max(prices, key = lambda k: prices[k])])


def example_3():
    prices = { 'AAA': 45.23, 'ZZZ': 45.23 }
    print(min(zip(prices.values(), prices.keys())))
    print(max(zip(prices.values(), prices.keys())))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()


