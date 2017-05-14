def example_1():
    d = {
        'a': [1, 2, 3],
        'b': [4, 5]
    }
    print(d)

    e = {
        'a': {1, 2, 3},
        'b': {4, 5}
    }
    print(e)


def example_2():
    from collections import defaultdict

    d = defaultdict(list)
    d['a'].append(1)
    d['a'].append(2)
    d['b'].append(4)
    print(d)

    d = defaultdict(set)
    d['a'].add(1)
    d['a'].add(2)
    d['b'].add(4)
    print(d)


def example_3():
    d = {}
    d.setdefault('a', []).append(1)
    d.setdefault('a', []).append(2)
    d.setdefault('b', []).append(4)
    print(d)


def example_4():
    pairs = [ (1, 1), (2, 2), (3, 4), (1, 10)]

    d = {}
    for key, value in pairs:
        if key not in d:
            d[key] = []
        d[key].append(value)
    print(d)

    from collections import defaultdict
    d = defaultdict(list)
    for key, value in pairs:
        d[key].append(value)
    print(d)


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()

