def example_1():
    text = 'Hello World'
    print(text.ljust(20))
    print(text.rjust(20))
    print(text.center(20))

    print(text.rjust(20, '='))
    print(text.center(20, '*'))


def example_2():
    text = 'Hello World'
    print(format(text, '>20'))
    print(format(text, '<20'))
    print(format(text, '^20'))
    print(format(text, '=>20s'))
    print(format(text, '*^20s'))


def example_3():
    print('{:>10s} {:>10s}'.format('Hello', 'World'))


def example_4():
    x = 1.2345
    print(format(x, '>10'))
    print(format(x, '^10.2f'))


def example_5():
    text = 'Hello World'
    print('%-20s' % text)
    print('%20s' % text)


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
    
