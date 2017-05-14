import collections

def example_1():
    import collections
    my_dict = {}
    print(isinstance(my_dict, collections.Mapping))

def example_2():
    t1 = (10, 20, (30, 40))
    print(hash(t1))
    t2 = (10, 20, frozenset([30, 40]))
    print(hash(t2))

def example_3():
    a = dict(one = 1, two = 2, three = 3)
    print(a)

    b = {'one': 1, 'three': 3, 'two': 2}
    print(b)

    c = dict({'two': 2, 'one': 1, 'three': 3})
    print(c)

    d = dict([('two', 2), ('three', 3), ('one', 1)])
    print(d)

    e = dict(zip(['three', 'one', 'two'], [3, 1, 2]))
    print(e)

    f = dict(zip(['three', 'two', 'one'], [3, 2, 1]))
    print(f)

    print(a == b == c == d == e == f)



if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
