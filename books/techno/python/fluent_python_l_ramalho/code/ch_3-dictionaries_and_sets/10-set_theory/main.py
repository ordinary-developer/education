def example_1():
    l = ['spam', 'spam', 'eggs', 'spam']
    print(set(l))
    print(list(set(l)))


def example_2():
    needles = set([1, 2, 3])
    haystack = set([i for i in range(100)])

    found1 = 0
    for n in needles:
        if n in haystack:
            found1 += 1
    print(found1)

    found2 = len(needles & haystack)
    print(found2)

    found3 = len(set(needles) & set(haystack))
    print(found3)

    found4 = len(set(needles).intersection(haystack))
    print(found4)


def example_3():
    s = {1}
    print(type(s))
    print(s)
    print(s.pop())
    print(s)


def example_4():
    from dis import dis
    print(dis('{1}'))
    print(dis('set([1])'))


def example_5():
    print(frozenset(range(10)))


def example_6():
    from unicodedata import name
    s = {chr(i) for i in range(32, 256) if 'SIGN' in name(chr(i),'')}
    print(s)


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
    example_4()
    example_5()
    example_6()
