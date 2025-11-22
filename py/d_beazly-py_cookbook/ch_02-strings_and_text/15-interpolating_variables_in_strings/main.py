def example_1():
    s = '{name} has {n} messages.'
    print(s.format(name = 'Guido', n = 37))


def example_2():
    name = 'Guido'
    n = 37
    s = '{name} has {n} messages.'
    print(s.format_map(vars()))


def example_3():
    class Info:
        def __init__(self, name, n):
            self.name = name
            self.n = n

    a = Info('Guido', 37)
    s = '{name} has {n} messages.'
    print(s.format_map(vars(a)))


def example_4():
    class safesub(dict):
        def __missing__(self, key):
            return '{' + key + '}'

    s = '{name} has {n} messages'
    name = 'Guido'
    print(s.format_map(safesub(vars())))


def example_5():
    class safesub(dict):
        def __missing__(self, key):
            return '{' + key + '}'

    import sys
    def sub(text):
        return text.format_map(safesub(sys._getframe(1).f_locals))

    name = 'Guido'
    n = 37
    print(sub('Hello {name}'))
    print(sub('You have {n} messages.'))
    print(sub('Your favorite color is {color}'))


def example_6():
    name = 'Guido'
    n = 37
    import string
    s = string.Template('$name has $n messages.')
    print(s.substitute(vars()))


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
