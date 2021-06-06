X_global = 88
def example_1():
    def func():
        global X_global
        X_global = 99

    func()
    print(X_global)


def example_2():
    import first
    print(first.X)
    first.X = 88
    print(first.X)


def example_3():
    import first
    print(first.X)
    first.setX(88)
    print(first.X)

def example_4():
    import thismod
    thismod.test()
    print(thismod.var)


if __name__ == '__main__':
    example_1()    
    example_2()
    example_3()
    example_4()
