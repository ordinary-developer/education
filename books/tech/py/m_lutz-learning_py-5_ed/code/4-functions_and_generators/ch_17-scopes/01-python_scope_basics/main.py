def example_1():
    X = 99

    def func():
        X = 88
        print(X)

    print(X)
    func()
    print(X)


def example_2():
    X = 99

    def func(Y):
        Z = X + Y
        return Z

    print(func(1))


def example_3():
    import builtins
    print(dir(builtins))


def example_4():
    print(zip)

    import builtins
    print(builtins.zip)

    print(zip is builtins.zip)


def example_5():
    import builtins
    print(len(dir(builtins)))
    print(len([x for x in dir(builtins) if not x.startswith('__')]))


if __name__ == '__main__':
    example_1()    
    example_2()
    example_3()
    example_4()
    example_5()
