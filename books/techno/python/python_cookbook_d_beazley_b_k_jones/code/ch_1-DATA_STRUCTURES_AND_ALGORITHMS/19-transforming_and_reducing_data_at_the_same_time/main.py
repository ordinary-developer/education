def example_1():
    nums = [1, 2, 3, 4, 5]
    s = sum(x * x for x in nums)
    print(s)


def example_2():
    import os
    files = os.listdir('./')
    if any(name.endswith('.py') for name in files):
        print('Ther be python!')
    else:
        print('Sorry, no python.')


def example_3():
    s = ('ACME', 50, 123.45)
    print(','.join(str(x) for x in s))


def example_4():
    portfolio = [
        { 'name': 'GOOG', 'shares': 50 },
        { 'name': 'YHOO', 'shares': 75 },
        { 'name': 'AOL', 'shares': 20 },
        { 'name': 'SCOX', 'shares': 65 }
    ]

    min_shares = min(s['shares'] for s in portfolio)
    print(min_shares)

    min_shares2 = min(portfolio, key = lambda d: d['shares'])
    print(min_shares2)


def example_5():
    nums = [1, 2, 3, 4, 5]

    s1 = sum((x * x for x in nums))
    s2 = sum(x * x for x in nums)
    s3 = sum([x * x for x in nums])
    print(s1)
    print(s2)
    print(s3)


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()

