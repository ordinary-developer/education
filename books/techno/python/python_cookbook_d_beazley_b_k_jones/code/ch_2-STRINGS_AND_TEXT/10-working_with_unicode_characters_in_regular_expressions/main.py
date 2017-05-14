def example_1():
    import re
    num = re.compile('\d+')
    print(num.match('123'))
    print(num.match('\u0661\u0662\u0663'))


def example_2():
    import re
    pattern = re.compile('stra\u00dfe', re.IGNORECASE)
    s = 'stra\u00dfe'
    print(pattern.match(s))
    print(pattern.match(s.upper()))
    print(s.upper())


if __name__ == '__main__':
    example_1()
    example_2()
