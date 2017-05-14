def example_1():
    a = { 'x': 1, 'z': 3 }
    b = { 'y': 2, 'z': 4 }

    from collections import ChainMap
    c = ChainMap(a, b)
    print(c['x'])
    print(c['y'])
    print(c['z'])

    print(len(c))
    print(list(c.keys()))
    print(list(c.values()))

    c['z'] = 10
    c['w'] = 40
    del c['x']
    print(a)

    try:
        del c['y']
    except KeyError:
        print('an error is here')


def example_2():
    from collections import ChainMap

    values = ChainMap()
    values['x'] = 1
    print(values)

    values = values.new_child()
    values['x'] = 2
    print(values)

    values = values.new_child()
    values['x'] = 3
    print(values)
    print(values['x'])

    values = values.parents
    print(values)
    print(values['x'])

    values = values.parents
    print(values)
    print(values['x'])


def example_3():
    a = { 'x': 1, 'z': 3 }
    b = { 'y': 2, 'z': 4 }
    merged = dict(b)
    merged.update(a)
    print(merged)
    print(a)
    print(b)


def example_4():
    a = { 'x': 1, 'z': 3 }
    b = { 'y': 2, 'z': 4 }

    from collections import ChainMap
    merged = ChainMap(a, b)
    print(merged['x'])
    a['x'] = 42
    print(merged['x'])


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
