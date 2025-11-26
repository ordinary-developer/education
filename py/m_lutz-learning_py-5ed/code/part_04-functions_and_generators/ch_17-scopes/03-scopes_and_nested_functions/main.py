X = 99

def example_1():
    def f1():
        X = 88
        def f2():
            print(X)
        f2()
    f1()


def example_2():
    def f1():
        X = 88
        def f2():
            print(X)
        return f2

    action = f1()
    action()


def example_3():
    def maker(N):
        def action(X):
            return X ** N
        return action
    
    f = maker(2)
    print(f)

    print(f(3))
    print(f(4))

    g = maker(3)
    print(g(4))
    print(f(4))


def example_4():
    def maker(N):
        return lambda X: X ** N

    h = maker(3)
    print(h(4))


def example_5():
    def f1():
        x = 88
        def f2(x = x):
            print(x)
        f2()

    f1()


def example_6():
    def f1():
        x = 88
        f2(x)

    def f2(x):
        print(x)

    f1()


def example_7():
    def func():
        x = 4
        action = (lambda n: x ** n)
        return action

    x = func()
    print(x(2))


def example_8():
    def func():
        x = 4
        action = (lambda n, x = x: x ** n)
        return action

    x = func()
    print(x(2))


def example_9():
    def makeActions():
        acts = []
        for i in range(5):
            acts.append(lambda x: i ** x)
        return acts

    acts = makeActions()
    print(acts[0])
    print(acts[0](2))
    print(acts[1](2))
    print(acts[2](2))
    print(acts[3](2))
    print(acts[4](2))


def example_10():
    def makeActions():
        acts = []
        for i in range(5):
            acts.append(lambda x, i = i: i ** x)
        return acts

    acts = makeActions()
    print(acts[0](2))
    print(acts[1](2))
    print(acts[2](2))
    print(acts[4](2))


def example_11():
    def f1():
        x = 99
        def f2():
            def f3():
                print(x)
            f3()
        f2()    

    f1()


if __name__ == '__main__':
    for func in [example_1, example_2, example_3, example_4, example_5, 
                 example_6, example_7, example_8, example_9, example_10,
                 example_11]:
        func()
        print(40 * '-')

