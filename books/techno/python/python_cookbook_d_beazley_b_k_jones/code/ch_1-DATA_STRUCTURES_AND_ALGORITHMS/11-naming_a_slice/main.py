def example_1():
    ######    0123456789012345678901234567890123456789012345678901234567890
    record = '                    100                 513.25               '
    cost = int(record[20:32]) * float(record[40:48])
    print(cost)

    SHARES = slice(20, 32)
    PRICE = slice(40, 48)
    cost = int(record[SHARES]) * float(record[PRICE])
    print(cost)


def example_2():
    items = [0, 1, 2, 3, 4, 5, 6]
    a = slice(2, 4)
    print(items[2:4], items[a])

    items[a] = [10, 11]
    print(items)

    del items[a]
    print(items)

    a = slice(10, 50, 2)
    print(a.start)
    print(a.stop)
    print(a.step)


def example_3():
    s = 'HelloWorld'
    a = slice(0, 10, 2)
    print(a.indices(len(s)))

    for i in range(*a.indices(len(s))):
        print(s[i])


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
