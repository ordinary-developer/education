def example1():
    def echo(message):
        print(message)

    echo('Direct call')

    x = echo
    x('Indirect call')


def example2():
    def echo(message):
        print(message)

    def indirect(func, arg):
        func(arg)

    indirect(echo, 'Argument call!')


def example3():
    def echo(message):
        print(message)

    schedule = [ (echo, 'Spam!'), (echo, 'Ham!') ]
    for (func, arg) in schedule:
        func(arg)


def example4():
    def make(label):
        def echo(message):
            print(label + ':' + message)
        return echo

    F = make('Spam')
    F('Ham!')
    F('Eggs!')


def example5():
    def func(a):
        b = 'spam'
        return b * a

    print(func(8))


def example6():
    def func(a):
        b = 'spam'
        return b * a

    print(func.__name__)
    print(dir(func))
    print(func.__code__)
    print(dir(func.__code__))


def example7():
    def func():
        pass

    func.count = 0
    func.count += 1
    print(func.count)

    func.handles = 'Button-Press'
    func.handles
    print(dir(func))


def example8():
    def func(): pass

    print(dir(func))
    print(len(dir(func)))
    print([x for x in dir(func) if not x.startswith('__')])


def example9():
    def func(a: 'spam', b: (1, 10), c: float) -> int:
        return a + b + c

    print(func(1, 2, 3))

    print(func.__annotations__)

    for arg in func.__annotations__:
        print(arg, '=>', func.__annotations__[arg])
    

def example10():
    def func(a: 'spam' = 4, b: (1, 10) = 5, c: float = 6) -> int:
        return a + b + c

    print(func(1, 2, 3))
    print(func()
    print(func(1, c = 10))
    print(func.__annotations__)


if __name__ == '__main__':
    funcs = [ example1, example2, example3, example4, example5,
              example6, example7, example8, example9, example10 ]
    for func in funcs:
        func()
