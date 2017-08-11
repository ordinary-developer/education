def example1():
    import sys
    def print3(*args, **kargs):
        sep = kargs.get('sep', ' ')
        end = kargs.get('end', '\n')
        file = kargs.get('file', sys.stdout)
        output = ''
        first = True
        for arg in args:
            output += ('' if first else sep) + str(arg)
            first = False
        file.write(output + end)

    print3(1, 2, 3)
    print3(1, 2, 3, sep = '')
    print3(1, 2, 3, sep = '...')
    print3(1, [2], (3,), sep = '...')

    print3(4, 5, 6, sep = '', end = '')
    print3(7, 8, 9)
    print3()

    import sys
    print3(1, 2, 3, sep = '??', end='.\n', file = sys.stderr)


def example2():
    import sys
    def print3(*args, sep = ' ', end = '\n', file = sys.stdout):
        output = ''
        first = True
        for arg in args:
            output += ('' if first else sep) + str(arg)
            first = False
        file.write(output + end)

    print3(1, 2, 3)
    print3(1, 2, 3, sep = '')
    print3(1, 2, 3, sep = '...')
    print3(1, [2], (3,), sep = '...')

    print3(4, 5, 6, sep = '', end = '')
    print3(7, 8, 9)
    print3()

    import sys
    print3(1, 2, 3, sep = '??', end='.\n', file = sys.stderr)

    try:
        print3(99, name = 'bob')
    except Exception as e:
        print(e)


def example3():
    import sys
    def print3(*args, **kargs):
        sep = kargs.pop('sep', ' ')
        end = kargs.pop('end', '\n')
        file = kargs.pop('file', sys.stdout)
        if kargs:
            raise TypeError('extra keywords: %s' % kargs)
        output = ''
        first = True
        for arg in args:
            output += ('' if first else sep) + str(arg)
            first = False
        file.write(output + end)

    print3(1, 2, 3)
    print3(1, 2, 3, sep = '')
    print3(1, 2, 3, sep = '...')
    print3(1, [2], (3,), sep = '...')

    print3(4, 5, 6, sep = '', end = '')
    print3(7, 8, 9)
    print3()

    import sys
    print3(1, 2, 3, sep = '??', end='.\n', file = sys.stderr)

    try:
        print3(99, name = 'bob')
    except Exception as e:
        print(e)


if __name__ == '__main__':
    example1()
    example2() 
    example3()
