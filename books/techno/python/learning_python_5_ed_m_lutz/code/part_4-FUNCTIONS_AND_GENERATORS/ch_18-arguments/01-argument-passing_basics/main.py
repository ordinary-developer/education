def example_1():
    def f(a):
        a = 99

    b = 88
    f(b)
    print(b)


def example_2():
    def changer(a, b):
        a = 2
        b[0] = 'spam'

    X = 1
    L = [1, 2]
    changer(X, L)
    print(X, L)


def example_3():
    X = 1
    a = X
    a = 2
    print(X)

    L = [1, 2]
    b = L
    b[0] = 'spam'
    print(L)


def example_4():
    def changer(a, b):
        a = 2
        b[0] = 'spam'

    X = 1
    L = [1, 2]
    changer(X, L[:])
    print(L)


def example_5():
    def changer(a, b):
        b = b[:]
        a = 2
        b[0] = 'spam'

    X = 1
    L = [1, 2]
    changer(X, L)
    print(L)


def example_6():
    def changer(a, b):
        try:
            b[0] = 'spam'
        except TypeError:
            print("typeerror was")

    X = 1
    L = [1, 2]
    changer(X, tuple(L))


def example_7():
    def multiple(x, y):
        x = 2
        y = [3, 4]
        return x, y

    X = 1
    L = [1, 2]
    X, L = multiple(X, L)
    print(X, L)

    


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
    example_7()
