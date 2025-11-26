def example01():
    def func(x, y, z):
        return x + y + z
    print(func(2, 3, 4))

    f = lambda x, y, z: x + y + z
    print(f(2, 3, 4))


def example02():
    x = (lambda a = "fee", b = "fie", c = "foe": a + b + c)
    print(x("wee"))


def example03():
    def knights():
        title = 'Sir'
        action = (lambda x: title + ' ' + x)
        return action

    act = knights()
    msg = act('robin')
    print(msg)
    print(act)


def example04():
    L = [ lambda x: x ** 2,
          lambda x: x ** 3,
          lambda x: x ** 4 ]

    for f in L:
        print(f(2))

    print(L[0](3))


def example05():
    key = 'got'
    statuses = { 'already': (lambda: 2 + 2),
                 'got':     (lambda: 2 * 4),
                 'one':     (lambda: 2 ** 6) }
    print(statuses[key]())


def example06():
    lower = (lambda x, y: x if x < y else y)
    print(lower('bb', 'aa'))
    print(lower('aa', 'bb'))


def example07():
    import sys
    showall = lambda x: list(map(sys.stdout.write, x))
    t = showall(['spam\n', 'toast\n', 'eggs\n'])

    showall = lambda x: [sys.stdout.write(line) for line in x]
    t = showall(('bright\n', 'side\n', 'of\n', 'life\n'))

    showall = lambda x: [print(line, end = '') for line in x]
    t = showall([1, 2, 3, 4, 5])

    t = showall([1, 2, 3, 4, 5])
    showall = lambda x: print(*x, sep = '', end = '')


def example08():
    def action(x):
        return (lambda y: x + y)

    act = action(99)
    print(act)
    print(act(2))

        
def example09():
    action = (lambda x: (lambda y: x + y))
    act = action(99)
    print(act(3))
    print((lambda x: (lambda y: x + y))(99)(4))


if __name__ == '__main__':
    example01()
    example02()
    example03()
    example04()
    example05()
    example06()
    example07()
    example08()
    example09()
