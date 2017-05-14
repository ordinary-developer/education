def example_1():
    filename = 'spam.txt'
    print(filename.endswith('.txt'))
    print(filename.startswith('file:'))

    url = 'http://www.python.org'
    print(url.startswith('http:'))


def example_2():
    filenames = [ 'Makefile', 'foo.c', 'bar.py', 'spam.c', 'spam.h' ]

    print([name for name in filenames if name.endswith(('.c', '.h'))])
    print(any(name.endswith('.py') for name in filenames))


def example_3():
    choices = ['http:', 'ftp:']
    url = 'http://www.python.org'
    print(url.startswith(tuple(choices)))


def example_4():
    filename = 'spam.txt'
    url = 'http://www.python.org'
    print(filename[-4:] == '.txt')
    print(url[:5] == 'http:' or url[:6] == 'https:' or url[:4] == 'ftp:')


def example_5():
    url = 'http://www.python.org'
    import re
    print(not(re.match('http:|https:|ftp:', url) is None))
    

if __name__ == '__main__':
    example_1()
    print(75 * '-')

    example_2()
    print(75 * '-')

    example_3()
    print(75 * '-')

    example_4()
    print(75 * '-')

    example_5()
    print(75 * '-')
