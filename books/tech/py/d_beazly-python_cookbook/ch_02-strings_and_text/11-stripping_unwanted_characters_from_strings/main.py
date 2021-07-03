def example_1():
    s = '   hello word   \n'
    print(s.strip())
    print(s.lstrip())
    print(s.rstrip())

    t = '----=hello======='
    print(t.lstrip('-'))
    print(t.strip('-='))


def example_2():
    s = '   hello    world    \n'
    print(s.strip())


def example_3():
    s = 'hello    world'

    print(s.replace(' ',''))
    
    import re
    print(re.sub('\s+', ' ', s))


if __name__ == '__main__':
    example_1()
    print('-' * 75)

    example_2()
    print('-' * 75)

    example_3()
