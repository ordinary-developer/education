def simple():
    spam = 'ni'
    def action():
        print(spam)
    return action


def normal():
    def action():
        return spam
    spam = 'ni'
    return action


def weird():
    spam = 42
    return (lambda: spam * 2)


def weird_2():
    tmp = (lambda: spam * 2)
    spam = 42
    return tmp


def weird_3():
    spam = 42
    handler = (lambda: spam * 2)
    spam = 50
    print(handler())
    spam = 60
    print(handler())


def odd():
    funcs = []
    for c in 'abcdefg':
        funcs.append((lambda: c))
    return funcs


def odd_2():
    funcs = []
    for c in 'abcdefg':
        funcs.append((lambda c = c: c))
    return funcs


if __name__ == '__main__':
    act = simple()
    act()

    act = normal()
    print(act())

    act = weird()
    print(act())

    act = weird_2()
    print(act())

    weird_3()

    for func in odd():
        print(func(), end = ' ')
    print()

    for func in odd_2():
        print(func(), end = ' ')
    print()

    funcs = []
    for c in 'abcdefg':
        funcs.append((lambda: c))
    for func in funcs:
        print(func(), end = ' ')
    print()

    funcs = []
    for c in 'abcdefg':
        funcs.append((lambda c = c: c))
    for func in funcs:
        print(func(), end = ' ')
    print()
