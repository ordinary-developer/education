def example_1():
    def tester(start):
        state = start
        def nested(label):
            print(label, state)
        return nested

    F = tester(0)
    F('spam')
    F('ham')


def example_2():
    def tester(start):
        state = start
        def nested(label):
            nonlocal state
            print(label, state)
            state += 1
        return nested

    F = tester(0)
    F('spam')
    F('ham')
    F('eggs')

    G = tester(42)
    G('spam')
    G('eggs')

    F('bacon')


def example_3():
    def tester(start):
        def nested(label):
            global state
            state = 0
            print(label, state)
        return nested

    F = tester(0)
    F('abc')
    print(state)


def example_4():
    def tester(start):
        global state
        state = start
        def nested(label):
            global state
            print(label, state)
            state += 1
        return nested

    F = tester(0)
    F('spam')
    F('eggs')

    G = tester(42)
    G('toast')
    G('bacon')
    F('ham')


def example_5():
    class tester:
        def __init__(self, start):
            self.state = start
        def nested(self, label):
            print(label, self.state)
            self.state += 1

    F = tester(0)
    F.nested('spam')
    F.nested('ham')

    G = tester(42)
    G.nested('toast')
    G.nested('bacon')
    F.nested('eggs')
    print(F.state)


def example_6():
    class tester:
        def __init__(self, start):
            self.state = start
        def __call__(self, label):
            print(label, self.state)
            self.state += 1

    H = tester(99)
    H('juice')
    H('pancakes')


def example_7():
    def tester(start):
        def nested(label):
            print(label, nested.state)
            nested.state += 1
        nested.state = start
        return nested

    F = tester(0)
    F('spam')
    F('ham')
    print(F.state)

    G = tester(42)
    G('eggs')
    F('ham')
    print(F.state)
    print(G.state)
    print(F is G)


def example_8():
    def tester(start):
        def nested(label):
            print(label, state[0])
            state[0] += 1
        state = [start]
        return nested


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
    example_7()
    example_8()
