def example_1():
    parts = [ 'Is', 'Chicago', 'Not', 'Chicago?' ]
    print(' '.join(parts))
    print(','.join(parts))
    print(''.join(parts))


def example_2():
    a = 'Is Chicago'
    b = 'Not Chicago?'
    print(a + ' ' + b)


def example_3():
    a = 'Is Chicago'
    b = 'Not Chicago'
    print('{} {}'.format(a, b))
    print(a + ' ' + b)


def example_4():
    a = 'Hello' 'World'
    print(a)


def example_5():
    data = ['ACME', 50, 91.1]
    print(','.join(str(d) for d in data))


def example_6():
    a, b, c = 'A', 'B', 'C'
    print(':'.join([a, b, c]))
    print(a, b, c, sep = ':')


def example_7():
    def sample():
        yield 'Is'
        yield 'Chicago'
        yield 'Not'
        yield 'Chicago?'

    print(' '.join(sample()))
    
    for part in sample():
        print(part)


def example_8():
    def sample():
        yield 'Is'
        yield 'Chicago'
        yield 'Not'
        yield 'Chicago?'

    def combine(source, maxsize):
        parts = []
        size = 0
        for part in source:
            parts.append(part)
            size += len(part)
            if size > maxsize:
                yield ''.join(parts)
                parts = []
                size = 0
        yield ''.join(parts)

    for part in combine(sample(), 32768):
        print(part)


if __name__ == '__main__':
    example_1()
    print('-' * 75)

    example_2()
    print('-' * 75)

    example_3()
    print('-' * 75)

    example_4()
    print('-' * 75)

    example_5()
    print('-' * 75)

    example_6()
    print('-' * 75)

    example_7()
    print('-' * 75)

    example_8()
