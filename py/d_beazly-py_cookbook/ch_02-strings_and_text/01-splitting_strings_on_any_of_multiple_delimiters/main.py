def example_1():
    line = 'asdf fjdk; afed, fjek,asdf,     foo'
    import re
    print(re.split(r'[;,\s]\s*', line))


def example_2():
    line = 'asdf fjdk; afed, fjek,asdf,     foo'

    import re
    fields = re.split(r'(;|,|\s)\s*', line)
    values = fields[::2]
    delimiters = fields[1::2] + ['']
    print(values)
    print(delimiters)
    print(''.join(v + d for v, d in zip(values, delimiters)))


def example_3():
    line = 'asdf fjdk; afed, fjek,asdf,     foo'

    import re
    print(re.split(r'(?:,|;|\s)\s*', line))


if __name__ == '__main__':
    example_1()
    example_2()
    example_3()
