def example_1():
    s = 'pýtĥöñ\fis\tawesome\r\n'
    print(s)

    remap = {
        ord('\t'): ' ',
        ord('\f'): ' ',
        ord('\r'): None
    }
    a = s.translate(remap)
    print(a)


def example_2():
    s = 'pýtĥöñ is awesome\n'

    import unicodedata
    import sys
    combining_chars = dict.fromkeys(
        c for c in range(sys.maxunicode) 
        if unicodedata.combining(chr(c)))
    b = unicodedata.normalize('NFD', s)
    print(b)
    print(b.translate(combining_chars))


def example_3():
    import unicodedata
    import sys

    digitmap = { c: ord('0') + unicodedata.digit(chr(c))
                 for c in range(sys.maxunicode)
                 if unicodedata.category(chr(c)) == 'Nd' } 
    print(len(digitmap))
    x = '\u0661\u0662\u0663'
    print(x.translate(digitmap))


def example_4():
    a = 'pýtĥöñ is awesome\n'

    import unicodedata
    b = unicodedata.normalize('NFD', a)
    print(b.encode('ascii', 'ignore'))
    print(b.encode('ascii', 'ignore').decode('ascii'))


def example_5():
    def clean_spaces(s):
        s = s.replace('\r', '')
        s = s.replace('\t', ' ')
        s = s.replace('\f', ' ')
        return s

    print(clean_spaces("hello\tworld\r\n"))


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

