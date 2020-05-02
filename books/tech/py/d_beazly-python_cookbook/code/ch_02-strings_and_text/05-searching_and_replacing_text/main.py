def example_1():
    text = 'yeah, but no, but yeah, but no, but yeah'

    print(text.replace('yeah', 'yep'))


def example_2():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'

    import re
    print(re.sub(r'(\d+)/(\d+)/(\d+)', r'\3-\1-\2', text))


def example_3():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'

    import re
    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)')
    print(date_pattern.sub(r'\3-\1-\2', text))


def example_4():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'

    import re
    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)')
    newtext, n = date_pattern.subn(r'\3-\1-\2', text)
    print(newtext)
    print(n)


if __name__ == '__main__':
    example_1()
    print(75 * '-') 

    example_2()
    print(75 * '-')

    example_3()
    print(75 * '-')

    example_4()
    print(75 * '-')
