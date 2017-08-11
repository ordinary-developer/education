def example1():
    counters = [1, 2, 3, 4]
    updated = []
    for x in counters:
        updated.append(x + 10)

    print(updated)             

    def inc(x):
        return x + 10
    print(list(map(inc, counters)))

    print(list(map((lambda x: x + 3), counters)))

    
def example2():
    def inc(x):
        return x + 10

    def mymap(func, seq):
        res = []
        for x in seq: res.append(func(x))
        return res

    print(list(map(inc, [1, 2, 3])))
    print(mymap(inc, [1, 2, 3]))


def example3():
    print(pow(3, 4))
    print(list(map(pow, [1, 2, 3], [2, 3, 4])))


def example4():
    def inc(x):
        return x + 10
    print(list(map(inc, [1, 2, 3, 4])))
    print([inc(x) for x in [1, 2, 3, 4]])


def example5():
    print(list(range(-5, 5)))
    print(list(filter((lambda x: x > 0), range(-5, 5))))


def example6():
    res = []
    for x in range(-5, 5):
        if x > 0:
            res.append(x)

    print(res)


def example7():
    print([x for x in range(-5, 5) if x > 0])


def example8():
    from functools import reduce
    print(reduce((lambda x, y: x + y), [1, 2, 3, 4]))
    print(reduce((lambda x, y: x * y), [1, 2, 3, 4]))


def example9():
    L = [1, 2, 3, 4]
    res = L[0]
    for x in L[1:]:
        res = res + x

    print(res)


def example10():
    def myreduce(function, sequence):
        tally = sequence[0]
        for next in sequence[1:]:
            tally = function(tally, next)
        return tally

    print(myreduce((lambda x, y: x + y), [1, 2, 3, 4, 5]))
    print(myreduce((lambda x, y: x * y), [1, 2, 3, 4, 5]))


def example11():
    import operator, functools
    print(functools.reduce(operator.add, [2, 4, 6]))
    print(functools.reduce((lambda x, y: x + y), [2, 4, 6]))


if __name__ == '__main__':
    example1()
    example2()
    example3()
    example4()
    example5()
    example6()
    example7()
    example8()
    example9()
    example10()
    example11()
