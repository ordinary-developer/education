def example_1():
    def f(a, b, c):
        print(a, b, c)

    f(1, 2, 3)
    f(c = 3, b = 2, a = 1)
    f(1, c = 3, b = 2)


def example_2():
    def f(a, b = 2, c = 3):
        print(a, b, c)

    f(1)
    f(a = 1)
    f(1, 4)
    f(1, 4, 5)
    f(1, c = 6)


def example_3():
    def func(spam, eggs, toast = 0, ham = 0):
        print((spam, eggs, toast, ham))

    func(1, 2)
    func(1, ham = 1, eggs = 0)
    func(spam = 1, eggs = 0)
    func(toast = 1, eggs = 2, spam = 3)
    func(1, 2, 3, 4)


def example_4():
    def f(*args):
        print(args)

    f()
    f(1)
    f(1, 2, 3, 4)


def example_5():
    def f(**args):
        print(args)

    f()
    f(a = 1, b = 2)


def example_6():
    def f(a, *pargs, **kargs):
        print(a, pargs, kargs)

    f(1, 2, 3, x = 1, y = 2)


def example_7():
    def func(a, b, c, d):
        print(a, b, c, d)

    args = (1, 2)
    args += (3, 4)
    func(*args)

    args = {'a': 1, 'b': 2, 'c': 3}
    args['d'] = 4
    func(**args)

    func(*(1, 2), **{'d': 4, 'c': 3})
    func(1, *(2, 3), **{'d': 4})
    func(1, c = 3, *(2,), **{'d': 4})
    func(1, *(2, 3), d = 4)
    func(1, *(2, ), c = 3, **{'d': 4})


def example_8():
    def func(*args):
        print(args)

    args = (2, 3)
    args += (4,) 
    func(*args)


def example_9():
    def tracer(func, *pargs, **kargs):
        print('calling:', func.__name__)
        return func(*pargs, **kargs)

    def func(a, b, c, d):
        return a + b + c + d

    print(tracer(func, 1, 2, c = 3, d = 4))


def example_10():
    def echo(*args, **kwargs):
        print(args, kwargs)

    echo(1, 2, a = 3, b = 4)

    pargs = (1, 2)
    kargs = {'a':3, 'b':4}
    echo(*pargs, **kargs)
    echo(0, c = 5, *pargs, **kargs)


def example_11():
    print(pow(*(2, 100)))


def example_12():
    def kwonly(a, *b, c):
        print(a, b, c)
    
    kwonly(1, 2, c = 3)
    kwonly(a = 1, c = 3)


def example_13():
    def kwonly(a, *, b, c):
        print(a, b, c)

    kwonly(1, c = 3, b = 2)
    kwonly(c = 3, b = 2, a = 1)


def example_14():
    def kwonly(a, *, b = 'spam', c = 'ham'):
        print(a, b, c)

    kwonly(1)
    kwonly(1, c = 3)
    kwonly(a = 1)
    kwonly(c = 3, b = 2, a = 1)


def example_15():
    def kwonly(a, *, b, c = 'spam'):
        print(a, b, c)

    kwonly(1, b = 'eggs')


def example_16():
    def kwonly(a, *, b = 1, c, d = 2):
        print(a, b, c, d)

    kwonly(3, c = 4)
    kwonly(3, c = 4, b = 5)


def example_17():
    def f(a, *b, c = 6, **d):
        print(a, b, c, d)

    f(1, 2, 3, x = 4, y = 5)
    f(1, 2, 3, x = 4, y = 5, c = 7)
    f(1, 2, 3, c = 7, x = 4, y = 5)


def example_18():
    def f(a, c = 6, *b, **d):
        print(a, b, c, d)

    f(1, 2, 3, x = 4)
    

def example_19():
    def f(a, *b, c = 6, **d):
        print(a, b, c, d)

    f(1, *(2, 3), **dict(x = 4, y = 5))
    f(1, *(2, 3), c = 7, **dict(x = 4, y = 5))
    f(1, c = 7, *(2, 3), **dict(x = 4, y = 5))
    f(1, *(2, 3), **dict(x = 4, y = 5, c = 7))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
    example_7()
    example_8()
    example_9()
    example_10()
    example_11()
    example_12()
    example_13()
    example_14()
    example_15()
    example_16()
    example_17()
    example_18()
    example_19()
