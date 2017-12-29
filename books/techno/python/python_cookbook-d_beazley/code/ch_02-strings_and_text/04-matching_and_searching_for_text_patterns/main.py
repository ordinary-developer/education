def example_1():
    text = 'yeah, but no, but yeah, but no, but yeah'

    print(text == 'yeah')

    print(text.startswith('yeah'))
    print(text.endswith('no'))

    print(text.find('no'))


def example_2():
    import re
    print(re.findall(r'(\d+)/(\d+)/(\d+)', text))

def example_2():
    text1 = '11/27/2012'
    text2 = 'Nov 27, 2012'

    import re
    if re.match(r'\d+/\d+/\d+', text1):
        print('yes')
    else:
        print('no')

    if re.match(r'\d+/\d+/\d+', text2):
        print('yes')
    else:
        print('no')


def example_3():
    text1 = '11/27/2012'
    text2 = 'Nov 27, 2012'

    import re
    date_pattern = re.compile(r'\d+/\d+/\d+')
    if date_pattern.match(text1):
        print('yes')
    else:
        print('no')

    if date_pattern.match(text2):
        print('yes')
    else:
        print('no')


def example_4():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'
    
    import re
    date_pattern = re.compile(r'\d+/\d+/\d+')
    print(date_pattern.findall(text))


def example_5():
    import re

    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)')
    m = date_pattern.match('11/27/2012')
    print(m)

    print(m.group(0))
    print(m.group(1))
    print(m.group(2))
    print(m.group(3))
    print(m.groups())

    month, day, year = m.groups()
    print("month=", month)
    print("day=", day)
    print("year=", year)


def example_6():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'

    import re
    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)')
    print(date_pattern.findall(text))

    for month, day, year in date_pattern.findall(text):
        print('{}-{}-{}'.format(month, day, year))

    for m in date_pattern.finditer(text):
        print(m.groups())


def example_7():
    import re
    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)')

    m = date_pattern.match('11/27/2012abcdefg')
    print(m)
    print(m.group())


def example_8():
    import re
    date_pattern = re.compile(r'(\d+)/(\d+)/(\d+)$')
    print(date_pattern.match('11/27/2012abcdef'))
    print(date_pattern.match('11/27/2012'))


def example_9():
    text = 'Today is 11/27/2012. PyCon starts 3/13/2013'

    import re
    print(re.findall(r'(\d+)/(\d+)/(\d+)', text))


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

    example_6()
    print(75 * '-')

    example_7()
    print(75 * '-')

    example_8()
    print(75 * '-')

    example_9()
    print(75 * '-')

